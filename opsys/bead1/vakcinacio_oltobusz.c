//Author: Koller David Daniel
//Neptun Code: IDJJQ2

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "vakcinacio_lib.h"
#include <unistd.h> //fork
#include <sys/types.h> //fork-hoz
#include <fcntl.h> //lock
#include <sys/wait.h> //waitpid
#include <signal.h>
#include <sys/stat.h>
#include <time.h>



//const char* busPipeNameIn = ["/tmp/firstBusPipeIn", "/tmp/secondBusPipeIn"];
//const char* busPipeNameOut = ["/tmp/firstBusPipeOut", "/tmp/secondBusPipeOut"];

const char* busPipeNameIn = "/tmp/firstBusPipeIn";
const char* busPipeNameOut = "/tmp/firstBusPipeOut";


FILE* busPipeFileIn;
FILE* busPipeFileOut;

pid_t secondBus = 1;
pid_t firstBus = 1;

struct sigaction firstBusSigact;
struct sigaction secondBusSigact;

bool firstBusStart = false;
bool secondBusStart = false;

//0 booting up   1: waiting for input  2: input sent by host process 3: waiting for output to be received 4: output received
int firstBusStatus = 0;
int secondBusStatus = 0;


struct record* records;
int recordCount;
int recordIndex = 0;
const int maxRecordSize = 100;

struct record* readRecords(int* size)
{
    recordIndex = 0;
    struct record* records = malloc(maxRecordSize * sizeof(struct record));
    int index = 0;
    FILE* fp = openFile();
    struct record input;
    while(fread(&input, sizeof(struct record), 1, fp))
    {
        if (input.vaccinated == false)
        {
           records[index] = input;
           index = index +1;
        }

    }
    fclose(fp);
    *size = index;
    return records;
};


void waitForAllProcesses()
{
    int status;
    if (firstBusStart)  waitpid(firstBus,&status,0);
    if (secondBusStart) waitpid(secondBus,&status,0);
}

void signalHandler(int signumber)
{
    printf("0 SignalHander START: %d %d %d\n",signumber, firstBusStatus, secondBusStatus);
    if (signumber == 10)  firstBusStatus = firstBusStatus+1;
    if (signumber == 12)  secondBusStatus = secondBusStatus+1;
    printf("0 SignalHander END: %d %d %d\n",signumber, firstBusStatus, secondBusStatus);
}



void busProcess(int busNumber)
{
        printf("%d Process START\n", busNumber);
        srand ( time(NULL) );
        pid_t parentId = getppid();
        sleep(1);

        printf("%d Signalling for reading \n", busNumber);

        if (busNumber == 1)
        {
            kill(parentId,SIGUSR1);    //HARCRA FEL!
        }
        else
        {
            kill(parentId,SIGUSR2);    //HARCRA FEL!
        }

        busPipeFileIn = fopen(busPipeNameIn, "rb");
        printf("1 %s opened in rb mode\n", busPipeNameIn);
        printf("1 Reading the input\n");
        struct record inRecords[5];
        struct record input;
        printf("1 Received following people: ");
        for(int i=0; i<5; i++)
        {
            fread(&input, sizeof(struct record), 1, busPipeFileIn);
            inRecords[i] = input;
            printf("%d ", inRecords[i].id);

        }
        printf("\n");
        fclose(busPipeFileIn);
        printf("0 %s closed\n", busPipeNameIn);

        printf("1 Starting Vaccination...\n");
        sleep(1);
        printf("1 Vaccination Results:");
        for(int i=0; i<5; i++)
        {

            if ((rand() % 100) > 10)
            {
                printf(" (%d:Success)", inRecords[i].id);
                inRecords[i].vaccinated = true;
                //fwrite(&(inRecords[i].id), sizeof(int), 1, busPipeFileOut);
            }
            else
            {
                printf(" %d: Failed", inRecords[i].id);
            }
        }
        printf("\n");
        printf("1 Signalling for writing time \n");
        kill(parentId,SIGUSR1);    //HARCRA FEL!
        busPipeFileOut = fopen(busPipeNameIn, "wb");
        printf("1 %s opened in wb mode\n", busPipeNameIn);
        printf("1 following people were successfully vaccinated: ");
        for(int i=0; i<5; i++)
        {
            if (inRecords[i].vaccinated == true)
            {
                fwrite(&(inRecords[i].id), sizeof(int), 1, busPipeFileOut);
            }
        }
        printf("\n");
        fclose(busPipeFileOut);
        printf("0 %s closed\n", busPipeNameIn);

        sleep(3);



    printf("1 First bus END \n");


}

void secondBusProcess()
{
    printf("2 Second bus START \n");
    printf("2 Second bus END \n");
}

void calcRecordCount()
{
    recordCount = countRecord();
    printf("0 Currently there are %d people waiting to get vaccinated.\n", recordCount);
    if (recordCount > 4)
    {
        firstBusStart = true;
        if (recordCount > 9)
        {
            secondBusStart = true;
        }
    }
}


void hqBeforeFork()
{
    mkfifo(busPipeNameIn, S_IRUSR|S_IWUSR ); // creating named pipe file
    mkfifo(busPipeNameIn, S_IRUSR|S_IWUSR ); // creating named pipe file
    printf("0 MKFIFO executed\n");

//    mkfifo(busPipeNameIn, S_IRUSR|S_IWUSR ); // creating named pipe file
//    mkfifo(secondBusPipeName, S_IRUSR|S_IWUSR ); // creating named pipe file
//
//
    calcRecordCount();

}


void hqSignalHandlerMethod()
{
    if (firstBusStatus == 1 )
    {
        firstBusStatus = 2;
        printf("0 Setting up list for first bus...\n");

        busPipeFileIn = fopen(busPipeNameIn, "wb");
        printf("0 %s opened in wb mode\n", busPipeNameIn);

        int recordStart = recordIndex;
        printf("0 Following people are queued for vaccination on the FIRST bus: ");
        for(; (recordIndex < recordCount && recordIndex - recordStart < 5); recordIndex++)
        {
            fwrite(&records[recordIndex], sizeof(struct record), 1, busPipeFileIn);
            printf("%d ", records[recordIndex].id);
        }
        printf("\n");

        fclose(busPipeFileIn);
        printf("0 %s closed\n", busPipeNameIn);

    }

    if (firstBusStatus == 3)
    {
        firstBusStatus = 4;
        busPipeFileOut = fopen(busPipeNameIn, "rb");
        printf("0 %s opened in rb mode\n", busPipeNameIn);

        printf("0 Following people were vaccinated: ");

        unsigned int successIds[5];

        int count = 0;
        int id;
        while((fread(&id, sizeof(int), 1, busPipeFileOut)))
        {

            printf("%d, ", id);
            successIds[count] = id;
            count = count +1;
        }



        printf("\n");

        fclose(busPipeFileOut);
        printf("0 %s closed\n", busPipeNameIn);

        writeVaccinationSuccess(successIds, count);
        calcRecordCount();
    }
}

void hqProcess()
{
    printf("0 HQ START\n");

    firstBusSigact.sa_handler=signalHandler;
    sigemptyset(&firstBusSigact.sa_mask);
    firstBusSigact.sa_flags=0;
    sigaction(SIGUSR1,&firstBusSigact,NULL);
//
//    secondBusSigact.sa_handler=secondBusHandler;
//    sigemptyset(&secondBusSigact.sa_mask);
//    secondBusSigact.sa_flags=0;
    sigaction(SIGUSR2,&firstBusSigact,NULL);

    records = readRecords(&recordCount);

    printf("0 Read the following records from db to memory: ");
    for (int i=0; i<recordCount; i++)
    {
        printf("%d ", records[i].id);
    }
    printf("\n");


    while ((firstBusStart && firstBusStatus != 4) && (secondBusStart && secondBusStatus != 4))
    {
        pause();
        hqSignalHandlerMethod();
    }

    waitForAllProcesses();

    free(records);
    printf("0 HQ END\n");
}


int main()
{
    hqBeforeFork();


    if (firstBusStart == 1)
    {
        firstBus = fork();
        if (firstBus<0)
        {
            //Error
            perror("Error on firstBus");
            exit(1);
        }

        if (firstBus==0)
        {
            busProcess(1);
        }
    }

//    if (secondBusStart == 1 && (firstBusStart == 1 && firstBus > 0))
//    {
//        secondBus = fork();
//        if (secondBus<0)
//        {
//            //Error
//            perror("Error on secondBus");
//            exit(1);
//        }
//
//        if (secondBus==0)
//        {
//            secondBusProcess();
//        }
//    }

    if (firstBusStart == 1 && firstBus > 0)
    {
        hqProcess();
//        if (secondBusStart == 1)
//        {
//            if (secondBus > 0)
//            {
//                hqProcess();
//            }
//        }
//        else
//        {
//            hqProcess();
//        }
    }
}


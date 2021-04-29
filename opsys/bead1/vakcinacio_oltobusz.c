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

const char* firstBusPipeNameIn = "/tmp/firstBusPipeIn";
const char* firstBusPipeNameOut = "/tmp/firstBusPipeOut";
FILE* firstBusPipeFileIn;
FILE* firstBusPipeFileOut;

FILE* firstBusPipeFileIn_child;
FILE* firstBusPipeFileOut_child;

const char* secondBusPipeName = "/tmp/secondBusPipe";

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

int firstBusPipeId;
int secondBusPipeId;

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
    if (firstBusStart)
    {
        printf("0 Waiting for the FirstBus process to end...\n");

        waitpid(firstBus,&status,0);
    }
    printf("0 FirstBus process ended!\n");
    if (secondBusStart) {waitpid(secondBus,&status,0);}
}

void firstBusHandler(int signumber){
    printf("0 FirstBusHandler START: signumber: %i firstbusstatus: %d\n",signumber, firstBusStatus);
    firstBusStatus = firstBusStatus+1;

    printf("0 FirstBusHandler END: signumber: %i firstbusstatus: %d\n",signumber, firstBusStatus);

    //waitForAllProcesses();


}

void secondBusHandler(int signumber){
    printf("0 Signal with number %i from Second Bus has arrived\n",signumber);
    printf("0 Signal handler ends \n");
}

void firstBusProcess(int busNumber)
{

        printf("%d First bus START\n", busNumber);
        srand ( time(NULL) );
        pid_t parentId = getppid();
        sleep(1);

        printf("1 Signalling for reading \n");
        kill(parentId,SIGUSR1);    //HARCRA FEL!
        firstBusPipeFileIn = fopen(firstBusPipeNameIn, "rb");
        printf("1 %s opened in rb mode\n", firstBusPipeNameIn);
        printf("1 Reading the input\n");
        struct record inRecords[5];
        struct record input;
        printf("1 Received following people: ");
        for(int i=0; i<5; i++)
        {
            fread(&input, sizeof(struct record), 1, firstBusPipeFileIn);
            inRecords[i] = input;
            printf("%d ", inRecords[i].id);

        }
        printf("\n");
        fclose(firstBusPipeFileIn);
        printf("0 %s closed\n", firstBusPipeNameIn);

        printf("1 Starting Vaccination...\n");
        sleep(1);
        printf("1 Vaccination Results:");
        for(int i=0; i<5; i++)
        {

            if ((rand() % 100) > 10)
            {
                printf(" (%d:Success)", inRecords[i].id);
                inRecords[i].vaccinated = true;
                //fwrite(&(inRecords[i].id), sizeof(int), 1, firstBusPipeFileOut);
            }
            else
            {
                printf(" %d: Failed", inRecords[i].id);
            }
        }
        printf("\n");
        printf("1 Signalling for writing time \n");
        kill(parentId,SIGUSR1);    //HARCRA FEL!
        firstBusPipeFileOut = fopen(firstBusPipeNameOut, "wb");
        printf("1 %s opened in wb mode\n", firstBusPipeNameOut);
        printf("1 following people were successfully vaccinated: ");
        for(int i=0; i<5; i++)
        {
            if (inRecords[i].vaccinated == true)
            {
                fwrite(&(inRecords[i].id), sizeof(int), 1, firstBusPipeFileOut);
            }
        }
        printf("\n");
        fclose(firstBusPipeFileOut);
        printf("0 %s closed\n", firstBusPipeNameOut);

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
    mkfifo(firstBusPipeNameIn, S_IRUSR|S_IWUSR ); // creating named pipe file
    mkfifo(firstBusPipeNameOut, S_IRUSR|S_IWUSR ); // creating named pipe file
    printf("0 MKFIFO executed\n");

//    mkfifo(firstBusPipeNameIn, S_IRUSR|S_IWUSR ); // creating named pipe file
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

        firstBusPipeFileIn = fopen(firstBusPipeNameIn, "wb");
        printf("0 %s opened in wb mode\n", firstBusPipeNameIn);

        int recordStart = recordIndex;
        printf("0 Following people are queued for vaccination on the FIRST bus: ");
        for(; (recordIndex < recordCount && recordIndex - recordStart < 5); recordIndex++)
        {
            fwrite(&records[recordIndex], sizeof(struct record), 1, firstBusPipeFileIn);
            printf("%d ", records[recordIndex].id);
        }
        printf("\n");

        fclose(firstBusPipeFileIn);
        printf("0 %s closed\n", firstBusPipeNameIn);

    }

    if (firstBusStatus == 3)
    {
        firstBusStatus = 4;
        firstBusPipeFileOut = fopen(firstBusPipeNameOut, "rb");
        printf("0 %s opened in rb mode\n", firstBusPipeNameOut);

        printf("0 Following people were vaccinated: ");

        unsigned int successIds[5];

        int count = 0;
        int id;
        while((fread(&id, sizeof(int), 1, firstBusPipeFileOut)))
        {

            printf("%d, ", id);
            successIds[count] = id;
            count = count +1;
        }



        printf("\n");

        fclose(firstBusPipeFileOut);
        printf("0 %s closed\n", firstBusPipeNameOut);

        writeVaccinationSuccess(successIds, count);
        calcRecordCount();
    }
}

void hqProcess()
{
    printf("0 HQ START\n");



    firstBusSigact.sa_handler=firstBusHandler;
    sigemptyset(&firstBusSigact.sa_mask);
    firstBusSigact.sa_flags=0;
    sigaction(SIGUSR1,&firstBusSigact,NULL);

    secondBusSigact.sa_handler=secondBusHandler;
    sigemptyset(&secondBusSigact.sa_mask);
    secondBusSigact.sa_flags=0;
    sigaction(SIGUSR2,&secondBusSigact,NULL);

    records = readRecords(&recordCount);

    printf("0 Read the following records from db to memory: ");
    for (int i=0; i<recordCount; i++)
    {
        printf("%d ", records[i].id);
    }
    printf("\n");

    if (firstBusStart)
    {

    }

    while (firstBusStatus != 4 && secondBusStatus != 4)
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
            firstBusProcess(1);
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


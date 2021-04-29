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
#include <string.h>
#include <errno.h>

const char* busPipeNameIn[2] = {"/tmp/firstBusPipeIn", "/tmp/secondBusPipeIn"};
const char* busPipeNameOut[2] = {"/tmp/firstBusPipeOut", "/tmp/secondBusPipeOut"};



pid_t secondBus = 1;
pid_t firstBus = 1;

struct sigaction firstBusSigact;
struct sigaction secondBusSigact;

bool firstBusStart = false;
bool secondBusStart = false;

//status values 0 booting up, waiting for input   1: data received, vaccinating 2: vaccinated, result sent, process ending
//array 0 index is for first bus process, 1 is for the second one
int busStatus[2] = {0,0};

bool firstSignal = false;
bool secondSignal = false;


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
    printf("0 Signal Received: %d\n",signumber);
    if (signumber == 10)
    {
        firstSignal = true;
    }
    else if (signumber == 12)
    {
        secondSignal = true;
    }

}



void busProcess(int busNumber)
{
    printf("%d Process START\n", busNumber);

    sleep(busNumber);
    srand ( time(NULL) );
    pid_t parentId = getppid();


    printf("%d Signalling for reading \n", busNumber);

    if (busNumber == 1)
    {
        kill(parentId,SIGUSR1);    //HARCRA FEL!

    }
    else
    {
        kill(parentId,SIGUSR2);    //HARCRA FEL!
    }

    sleep(1);

    FILE* busPipeFileIn = fopen(busPipeNameIn[busNumber-1], "rb");
    printf("%d %s opened in rb mode\n", busNumber, busPipeNameIn[busNumber-1]);
    printf("%d Reading the input\n", busNumber);
    struct record inRecords[5];
    struct record input;
    printf("%d Received following people: ", busNumber);
    int inputCount = 0;

    while(fread(&input, sizeof(struct record), 1, busPipeFileIn))
    {
        //fread(&input, sizeof(struct record), 1, busPipeFileIn);
        inRecords[inputCount] = input;
        printf("%d ", inRecords[inputCount].id);
        inputCount++;

    }
    printf("\n");
    fclose(busPipeFileIn);
    printf("%d %s closed\n", busNumber, busPipeNameIn[busNumber-1]);

    printf("%d Starting Vaccination...\n", busNumber);
    sleep(1);
    printf("%d Vaccination Results:", busNumber);
    for(int i=0; i<inputCount; i++)
    {

        if ((rand() % 100) > 10)
        {
            printf(" (%d:Success)", inRecords[i].id);
            inRecords[i].vaccinated = true;
            //fwrite(&(inRecords[i].id), sizeof(int), 1, busPipeFileOut);
        }
        else
        {
            printf(" (%d:Failed)", inRecords[i].id);
        }
    }
    printf("\n");
    printf("%d Signalling for writing \n", busNumber);

    if (busNumber == 1)
    {
        kill(parentId,SIGUSR1);    //HARCRA FEL!
    }
    else
    {
        kill(parentId,SIGUSR2);    //HARCRA FEL!
    }

    printf("%d Writing to output pipe \n", busNumber);
    FILE * busPipeFileOut = fopen(busPipeNameOut[busNumber-1], "wb");
    if (!busPipeFileOut)
    {
        printf("0 ERROR when opening %s in wb mode\n", busPipeNameOut[busNumber-1]);
        exit(1);
    }

    printf("%d %s opened in wb mode\n", busNumber, busPipeNameOut[busNumber-1]);
    for(int i=0; i<inputCount; i++)
    {
        if (inRecords[i].vaccinated == true)
        {
            fwrite(&(inRecords[i].id), sizeof(int), 1, busPipeFileOut);
        }
    }
    fclose(busPipeFileOut);
    printf("%d %s closed\n", busNumber, busPipeNameOut[busNumber-1]);
    printf("%d Process END \n", busNumber);
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
    unlink(busPipeNameIn[0]);
    unlink(busPipeNameIn[1]);
    unlink(busPipeNameOut[0]);
    unlink(busPipeNameOut[1]);

    mkfifo(busPipeNameIn[0], S_IRUSR|S_IWUSR ); // creating named pipe file
    mkfifo(busPipeNameOut[0], S_IRUSR|S_IWUSR ); // creating named pipe file
    mkfifo(busPipeNameIn[1], S_IRUSR|S_IWUSR ); // creating named pipe file
    mkfifo(busPipeNameOut[1], S_IRUSR|S_IWUSR ); // creating named pipe file
    printf("0 MKFIFO executed\n");

    calcRecordCount();

}


void hqSignalHandlerMethod()
{
    printf("0 hqSignalHandlerMethod Status: firstStart: %d status: %d signal: %d secondStart: %d status: %d signal: %d \n", firstBusStart, busStatus[0], firstSignal, secondBusStart, busStatus[1], secondSignal);


    int busProcess = -1;

    if (firstSignal)
    {
        firstSignal = false;
        busProcess = 1;
    }

    else if (secondSignal)
    {
        secondSignal = false;
        busProcess = 2;
    }

    if (busProcess == -1)
    {
        printf("0 nothing to do here\n");
        return;
    }

    printf("0 handling the signal from process #%d status: %d\n", busProcess, busStatus[busProcess-1]);

    if (busStatus[busProcess-1] == 0 )
    {
        printf("0 Process#%d is standing by to receive data from HQ\n", busProcess);
        busStatus[busProcess-1] = 1;
        printf("0 Setting up list for Bus #%d...\n", busProcess);

        FILE* busPipeFileIn = fopen(busPipeNameIn[busProcess-1], "wb");

        if (!busPipeFileIn)
        {
            printf("0 ERROR when opening %s in wb mode. %d %s\n", busPipeNameIn[busProcess-1], errno, strerror(errno));
            exit(1);
        }

        printf("0 %s opened in wb mode\n", busPipeNameIn[busProcess-1]);

        printf("0 Following people are queued for vaccination on the #%d bus: ", busProcess);

        int count = 0;
        for(int i = recordIndex; (i < recordCount && count < 5); i++)
        {
            count++;
            fwrite(&records[i], sizeof(struct record), 1, busPipeFileIn);
            printf("%d ", records[i].id);
        }
        recordIndex = recordIndex + count;
        printf("\n");

        fclose(busPipeFileIn);
        printf("0 %s closed\n", busPipeNameIn[busProcess-1]);
        return;
    }

    if (busStatus[busProcess-1] == 1)
    {
        printf("0 Process#%d sent data to HQ\n", busProcess);
        busStatus[busProcess-1] = 2;
        FILE* busPipeFileOut = fopen(busPipeNameOut[busProcess-1], "rb");

        if (!busPipeFileOut)
        {
            printf("0 ERROR when opening %s in rb mode\n", busPipeNameOut[busProcess-1]);
            exit(1);
        }

        printf("0 %s opened in rb mode\n", busPipeNameOut[busProcess-1]);

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
        printf("0 %s closed\n", busPipeNameOut[busProcess-1]);

        writeVaccinationSuccess(successIds, count);
        calcRecordCount();
        return;
    }
}

void hqProcess()
{
    printf("0 HQ START\n");

    firstBusSigact.sa_handler=signalHandler;
    sigemptyset(&firstBusSigact.sa_mask);
    firstBusSigact.sa_flags=0;
    sigaction(SIGUSR1,&firstBusSigact,NULL);

    secondBusSigact.sa_handler=signalHandler;
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


    while ((firstBusStart && busStatus[0] != 2) || (secondBusStart && busStatus[1] != 2))
    {
        //pause();
        sleep(1);
        printf("0 Status: firstStart: %d status: %d signal: %d secondStart: %d status: %d signal: %d \n", firstBusStart, busStatus[0], firstSignal, secondBusStart, busStatus[1], secondSignal);

        hqSignalHandlerMethod();
    }

    printf("0 LOOP END Status: firstStart: %d status: %d signal: %d secondStart: %d status: %d signal: %d \n", firstBusStart, busStatus[0], firstSignal, secondBusStart, busStatus[1], secondSignal);


    waitForAllProcesses();

    free(records);
    sleep(3);
    unlink(busPipeNameIn[0]);
    unlink(busPipeNameIn[1]);
    unlink(busPipeNameOut[0]);
    unlink(busPipeNameOut[1]);

    printf("0 HQ END\n");
}


int main()
{
    hqBeforeFork();


    if (firstBusStart)
    {
        printf("0 Going to fork to create first process!\n");
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
            return 0;
        }
    }

    if (secondBusStart && firstBus > 0)
    {
        printf("0 Going to fork to create second process!\n");
        secondBus = fork();
        if (secondBus<0)
        {
            //Error
            perror("Error on secondBus");
            exit(1);
        }

        if (secondBus==0)
        {
            busProcess(2);
            return 0;
        }
    }

    hqProcess();
}


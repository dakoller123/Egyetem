#include <unistd.h> //fork
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h> //waitpid
#include <signal.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <errno.h>

bool verbose = true;
pid_t firstProcessId = 1;
pid_t secondProcessId = 1;

bool SIGUSR1_received = false;
bool SIGUSR2_received = false;

bool SIGUSR1_processed = false;
bool SIGUSR2_processed = false;

bool endLoop = false;

struct sigaction sigact;

const char* pipeNameIn[2] = {"/tmp/firstProcessPipeIn", "/tmp/secondProcessPipeIn"};
const char* pipeNameOut[2] = {"/tmp/firstProcessPipeOut", "/tmp/secondProcessPipeOut"};

void mainProcessBeforeFork()
{

    unlink(pipeNameIn[0]);
    unlink(pipeNameIn[1]);
    unlink(pipeNameOut[0]);
    unlink(pipeNameOut[1]);

    mkfifo(pipeNameIn[0], S_IRUSR|S_IWUSR ); // creating named pipe file
    mkfifo(pipeNameOut[0], S_IRUSR|S_IWUSR ); // creating named pipe file
    mkfifo(pipeNameIn[1], S_IRUSR|S_IWUSR ); // creating named pipe file
    mkfifo(pipeNameOut[1], S_IRUSR|S_IWUSR ); // creating named pipe file
}



void signalHandler(int signumber)
{
    if (verbose) printf("0 Signal Received: %d\n",signumber);
    if (signumber == 10)
    {
        SIGUSR1_received = true;
    }
    else if (signumber == 12)
    {
        SIGUSR2_received = true;
    }

}

void loopMethod()
{
    int processNumber = -1;

    if (SIGUSR1_received)
    {
        SIGUSR1_received = false;
        if (verbose) printf("0 SIGUSR1_received\n");
        processNumber = 1;

    }
    else if (SIGUSR2_received)
    {
        SIGUSR2_received = false;
        if (verbose) printf("0 SIGUSR2_received\n");
        processNumber = 2;
    }


    if (processNumber == -1)
    {
        if (verbose) printf("0 nothing to do here\n");
        return;
    }

    FILE* pipeFileIn = fopen(pipeNameIn[processNumber-1], "w");
    while (!pipeFileIn)
    {
        printf("0!!! ERROR when opening %s in w mode. %d %s\n", pipeNameIn[processNumber-1], errno, strerror(errno));
        pipeFileIn = fopen(pipeNameIn[processNumber-1], "w");
    }
    int number = 5;
    fwrite(&number, sizeof(int), 1, pipeFileIn);
    fclose(pipeFileIn);


    if (processNumber == 1)
    {
        SIGUSR1_processed = true;
    }
    else if (processNumber == 2)
    {
        SIGUSR2_processed = true;
    }

    if (SIGUSR1_processed && SIGUSR2_processed)
    {
        endLoop = true;
    }

}

void mainProcessAfterFork()
{
    if (verbose) printf("0 Main after fork START\n");



    sigact.sa_handler=signalHandler;
    sigemptyset(&sigact.sa_mask);
    sigact.sa_flags=0;
    sigaction(SIGUSR1,&sigact,NULL);
    sigaction(SIGUSR2,&sigact,NULL);

    while (!endLoop)
    {
        pause();
        loopMethod();
        loopMethod();


    }

    int status;
    waitpid(firstProcessId,&status,0);
    waitpid(secondProcessId,&status,0);
    if (verbose) printf("0 Main after fork END\n");
}

void childProcess(int processNumber)
{
    if (verbose) printf("%d Child Process START\n", processNumber);
    sleep(getpid() % 2);
    srand ( time(NULL) );
    pid_t parentId = getppid();
    sleep(1);

    if (processNumber == 1)
    {
        kill(parentId,SIGUSR1);
    }
    else
    {
        kill(parentId,SIGUSR2);
    }

    FILE* pipeFileIn = fopen(pipeNameIn[processNumber-1], "r");
    int number;
    fread(&number, sizeof(int), 1, pipeFileIn);

    fclose(pipeFileIn);

    printf("%d Number received: %d END\n", processNumber, number);

    if (verbose) printf("%d Child Process END\n", processNumber);
}

int main()
{
    mainProcessBeforeFork();


    if (verbose) printf("0 Going to fork to create first process!\n");
    firstProcessId = fork();
    if (firstProcessId<0)
    {
        //Error
        perror("Error on first fork");
        exit(1);
    }

    if (firstProcessId==0)
    {
        childProcess(1);
        return 0;
    }

    if (verbose) printf("0 Going to fork to create second process!\n");
    firstProcessId = fork();
    if (firstProcessId<0)
    {
        //Error
        perror("Error on second fork");
        exit(1);
    }

    if (firstProcessId==0)
    {
        childProcess(2);
        return 0;
    }

    mainProcessAfterFork();
}


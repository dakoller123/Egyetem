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

int firstBusPipefd[2]; // unnamed pipe file descriptor array
int secondBusPipefd[2]; // unnamed pipe file descriptor array
char sz1[100];  // char array for reading from pipe
char sz2[100];  // char array for reading from pipe
pid_t secondBus = 1;
pid_t firstBus = 1;
struct sigaction firstBusSigact;
struct sigaction secondBusSigact;
int firstBusStart = 0;
int secondBusStart = 0;

void waitForAllProcesses()
{
    int status;
    if (firstBusStart == 1) {waitpid(firstBus,&status,0);}
    if (secondBusStart == 1) {waitpid(secondBus,&status,0);}
}

void firstBusHandler(int signumber){
    printf("0 Signal with number %i from First Bus has arrived\n",signumber);
    write(firstBusPipefd[1], "First Bus!",10);
    close(firstBusPipefd[1]); // Closing write descriptor
    printf("0 Szulo beirta az adatokat a csobe!\n");
    printf("0 Signal handler ends \n");
}

void secondBusHandler(int signumber){
    printf("0 Signal with number %i from Second Bus has arrived\n",signumber);
    write(secondBusPipefd[1], "Second Bus!",11);
    close(secondBusPipefd[1]); // Closing write descriptor
    printf("0 Szulo beirta az adatokat a csobe!\n");
    printf("0 Signal handler ends \n");
}

void firstBusProcess()
{
    printf("1 First bus START \n");
    close(firstBusPipefd[1]);  //Usually we close the unused write end
    sleep(3);
    kill(getppid(),SIGUSR1);    //HARCRA FEL!
    sleep(3);

    printf("1 Gyerek elkezdi olvasni a csobol az adatokat!\n");
    read(firstBusPipefd[0],sz1,sizeof(sz1)); // reading max 100 chars
    printf("1 Gyerek olvasta uzenet: %s",sz1);
    printf("\n");
    close(firstBusPipefd[0]); // finally we close the used read end
    printf("1 First bus END \n");
}

void secondBusProcess()
{
    printf("2 Second bus START \n");
    close(secondBusPipefd[1]);  //Usually we close the unused write end
    sleep(3);
    kill(getppid(),SIGUSR2);    //HARCRA FEL!
    sleep(3);

    printf("2 Gyerek elkezdi olvasni a csobol az adatokat!\n");
    read(secondBusPipefd[0],sz2,sizeof(sz2)); // reading max 100 chars
    printf("2 Gyerek olvasta uzenet: %s",sz2);
    printf("\n");
    close(secondBusPipefd[0]); // finally we close the used read end
    printf("2 Second bus END \n");
}

void hqProcess()
{
    close(firstBusPipefd[0]); //Usually we close unused read end
    close(secondBusPipefd[0]); //Usually we close unused read end
    printf("0 HQ START\n");
    waitForAllProcesses();
    printf("0 HQ END\n");
}

void calcRecordCount()
{
    int recordCount = countRecord();
    printf("0 Currently there are %d people waiting to get vaccinated.\n", recordCount);
    if (recordCount > 4)
    {
        firstBusStart = 1;
        if (recordCount > 9)
        {
            secondBusStart = 1;
        }
    }
}

int main()
{

    firstBusSigact.sa_handler=firstBusHandler;
    sigemptyset(&firstBusSigact.sa_mask);
    firstBusSigact.sa_flags=0;
    sigaction(SIGUSR1,&firstBusSigact,NULL);

    secondBusSigact.sa_handler=secondBusHandler;
    sigemptyset(&secondBusSigact.sa_mask);
    secondBusSigact.sa_flags=0;
    sigaction(SIGUSR2,&secondBusSigact,NULL);

    calcRecordCount();

    if (pipe(firstBusPipefd) == -1 || pipe(secondBusPipefd) == -1)
	{
        perror("0 Hiba a pipe nyitaskor!");
        exit(EXIT_FAILURE);
    }

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
            firstBusProcess();
        }
    }

    if (secondBusStart == 1 && (firstBusStart == 1 && firstBus > 0))
    {
        secondBus = fork();
        if (secondBus<0)
        {
            //Error
            perror("Error on secondBus");
            exit(1);
        }

        if (secondBus==0)
        {
            secondBusProcess();
        }
    }

    if ((secondBusStart == 1 && secondBus>0) && (firstBusStart == 1 && firstBus > 0))
    {
        hqProcess();
    }
}


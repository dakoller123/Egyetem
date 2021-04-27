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

int pipefd[2]; // unnamed pipe file descriptor array
char sz[100];  // char array for reading from pipe


void handler(int signumber){
    printf("Signal with number %i has arrived\n",signumber);

    close(pipefd[0]); //Usually we close unused read end
    write(pipefd[1], "Hajra Fradi!",13);
    close(pipefd[1]); // Closing write descriptor
    printf("Szulo beirta az adatokat a csobe!\n");
    printf("Signal handler ends \n");


}

int main()
{
    struct sigaction sigact;
    sigact.sa_handler=handler;
    sigemptyset(&sigact.sa_mask); //during execution of handler these signals will be blocked plus the signal
  //now only the arriving signal, SIGTERM will be blocked
    sigact.sa_flags=0;
    sigaction(SIGUSR1,&sigact,NULL);


    if (pipe(pipefd) == -1)
	{
        perror("Hiba a pipe nyitaskor!");
        exit(EXIT_FAILURE);
    }

    int recordCount = countRecord();

    printf("Currently there are %d people waiting to get vaccinated.\n", recordCount);
    if (recordCount > 4)
    {
        pid_t firstBus = fork();
        if (firstBus<0)
        {
            //Error
            perror("Error on firstBus");
            exit(1);
        }

        if (firstBus>0)
        {
            //Parent process
            pid_t secondBus = 1;
            if (recordCount > 9)
            {
                secondBus = fork();
                if (secondBus<0)
                {
                    perror("Error on secondBus\n");
                    exit(1);
                }

                if (secondBus>0)
                {
                    //Parent process
                    int status;
                    waitpid(secondBus,&status,0);
                    printf("The end of parent process of SecondBus\n");
                }
                else
                {
                    //Second Bus process
                    printf("Second bus process start\n");
                    kill(getppid(),SIGUSR1);    //HARCRA FEL!

                    sleep(3);	// sleeping a few seconds, not necessary
                    close(pipefd[1]);  //Usually we close the unused write end
                    printf("Gyerek elkezdi olvasni a csobol az adatokat!\n");
                    read(pipefd[0],sz,sizeof(sz)); // reading max 100 chars
                    printf("Gyerek olvasta uzenet: %s",sz);
                    printf("\n");
                    close(pipefd[0]); // finally we close the used read end
                }
            }

            if (secondBus > 0)
            {
                int status;
                waitpid(firstBus,&status,0);
                printf("The end of parent process of FirstBus\n");
            }

        }
        else
        {
            //First Bus process
            printf("First bus START \n");
            sleep(3);
            printf("First bus END \n");
        }


    }


}


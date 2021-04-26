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




int main()
{
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

            if (recordCount > 9)
            {
                pid_t secondBus = fork();
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
                    printf("The end of parent process\n");
                }
                else
                {
                    printf("Second bus is leaving\n");
                    //Second Bus process
                }
            }

            int status;
            waitpid(firstBus,&status,0);
            printf("The end of parent process\n");
        }
        else
        {
            //First Buss process
            printf("First bus is leaving \n");
        }


    }


}


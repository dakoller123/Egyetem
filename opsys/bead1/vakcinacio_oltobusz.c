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

void setVaccinationStatus(unsigned int id, bool vaccinated)
{
    FILE* oldDB = fopen(DB_FILENAME, "rb");
    FILE* tmpDB = fopen(DB_BACKUP_FILENAME, "wb");
    bool found = false;
    struct record tmp;
    while((fread(&tmp, sizeof(struct record), 1, oldDB)))
    {
        if (tmp.id == id)
        {
            found = true;
        }

        fwrite(&tmp, sizeof(struct record), 1, tmpDB);
    }
    fclose(tmpDB);
    fclose(oldDB);

    if (found)
    {
        printf("Entry found, editing...\n");
        tmpDB = fopen(DB_BACKUP_FILENAME, "rb");
        FILE* newDB = fopen(DB_FILENAME, "wb");
        struct record tmp2;
        while((fread(&tmp2, sizeof(struct record), 1, tmpDB)))
        {
            if (tmp2.id == id)
            {
                tmp2.vaccinated = vaccinated;
            }
            fwrite(&tmp2, sizeof(struct record), 1, newDB);
        }

        fclose(newDB);
        fclose(tmpDB);
    }
}

int countRecord()
{
    FILE* fp = openFile();
    struct record input;
    int result = 0;
    while(fread(&input, sizeof(struct record), 1, fp))
    {
        result = result +1;

    }
    fclose(fp);
    return result;
}

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
            perror("Error on firstBus"); exit(1);
        }

        if (firstBus>0)
        {

            //Parent process

            if (recordCount > 9)
            {
                pid_t secondBus = fork();
                if (secondBus<0)
                {
                    //Error
                    perror("Error on secondBus"); exit(1);
                }

                if (secondBus>0)
                {
                    //Parent process
                }
                else
                {
                    printf("Second bus is leaving \n");
                    //Second Bus process
                }
            }
        }
        else
        {
            //First Buss process
            printf("First bus is leaving \n");
        }


    }


}


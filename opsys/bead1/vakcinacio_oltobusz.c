//Author: Koller David Daniel
//Neptun Code: IDJJQ2

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "vakcinacio_lib.h"

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




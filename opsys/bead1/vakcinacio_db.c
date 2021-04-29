//Author: Koller David Daniel
//Neptun Code: IDJJQ2

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "vakcinacio_lib.h"



void readRecord(FILE *restrict fp, unsigned int id)
{
    bool found = false;
    struct record input;
    while((!found) && (fread(&input, sizeof(struct record), 1, fp)))
    {
        if (input.id == id)
        {
            found = true;
        }
    }

    if (found)
    {
        printf("%i | %s %s | %d | %s",
                   input.id, input.firstName, input.lastName, input.birthYear, input.phoneNumber);

        if (input.paid)
        {
            printf(" | X |\n");
        }
        else
        {
            printf(" |  | \n");
        }
    }
    else
    {
        printf("Couldn't find the entry in the db!\n");
    }
}



void deleteRecord(unsigned int id)
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
        printf("Entry found, deleting...\n");
        tmpDB = fopen(DB_BACKUP_FILENAME, "rb");
        FILE* newDB = fopen(DB_FILENAME, "wb");
        struct record tmp2;
        while((fread(&tmp2, sizeof(struct record), 1, tmpDB)))
        {
            if (tmp2.id != id)
            {
                fwrite(&tmp2, sizeof(struct record), 1, newDB);
            }
        }
        fclose(newDB);
        fclose(tmpDB);
    }
}

unsigned int listRecords(FILE* restrict fp, bool print)
{
    if (print)
    {
        printf("%s\n", "listing all records...");
        printf("%s\n", "| ID | NAME | BirthYear | PhoneNumber | Private Healthcare | Vaccinated | ");
    }

    struct record input;
    unsigned int firstFreeId = 1;

    while(fread(&input, sizeof(struct record), 1, fp))
    {
        if (firstFreeId == input.id)
        {
            firstFreeId = firstFreeId + 1;
        }

        if (print)
        {
            printf("| %i | %s %s | %d | %s | %d | %d |\n",
                   input.id, input.firstName, input.lastName, input.birthYear, input.phoneNumber, input.paid, input.vaccinated);

        }
    }

    return firstFreeId;
}

void createRecord(FILE *restrict fp, char* firstName, char* lastName, int birthYear, char* phoneNumber, bool paid)
{
    unsigned int freeId = listRecords(fp, false);
    printf("%s %d\n", "free id: ", freeId);
    struct record newRecord;
    newRecord.id = freeId;
    strcpy(newRecord.firstName, firstName);
    strcpy(newRecord.lastName, lastName);
    newRecord.birthYear = birthYear;
    strcpy(newRecord.phoneNumber, phoneNumber);
    newRecord.paid = paid;
    newRecord.vaccinated = false;
    fwrite(&newRecord, sizeof(struct record), 1, fp);
}

void updateRecord(unsigned int id, char* firstName, char* lastName, int birthYear, char* phoneNumber, bool paid, bool vaccinated)
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
                tmp2.birthYear = birthYear;
                strcpy(tmp2.firstName, firstName);
                strcpy(tmp2.lastName, lastName);
                strcpy(tmp2.phoneNumber, phoneNumber);
                tmp2.paid = paid;
                tmp2.vaccinated = vaccinated;
            }
            fwrite(&tmp2, sizeof(struct record), 1, newDB);
        }

        fclose(newDB);
        fclose(tmpDB);
    }
}


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




void invalidArguments()
{
    printf("%s \n", "Invalid Arguments, try './vakcinacio H' to see the manual  ");
}

int main(int argc, char *argv[]) {
    if (argc < 2 || strlen(argv[1]) != 1)
    {
        invalidArguments();
        return -1;
    }

    char operation;

    operation = argv[1][0];

    bool validArgs = false;

    if ((argc == 2) && (operation == 'H'))
    {
        validArgs = true;
        printf("%s\n", "Usage: specify the type of operation: (C)create, (R)ead, (U)pdate, (D)elete, (L)ist then additional parameters");
        printf("%s\n", "Additional parameters: First Name, Last Name, Year of Birth, PhoneNumber, True/False for the Premium option");
        printf("%s\n", "Example #1: ./vakcinacio  C Gipsz Jakab 1945 0036202536099 True");
        printf("%s\n", "Example #2: ./vakcinacio  U Gipsz Jakab 1945 0036202536099 False");
        printf("%s\n", "Example #3: ./vakcinacio R 15");
        printf("%s\n", "Example #4: ./vakcinacio D 4");
        printf("%s\n", "Example #5: ./vakcinacio L");
    }

    if ((argc == 2) && (operation == 'L'))
    {
        validArgs = true;
        FILE* fp = openFile();
        listRecords(fp, true);
        fclose(fp);
    }

    if ((argc == 2) && (operation == 'l'))
    {
        validArgs = true;
        int count = countRecord();
        printf("%d\n", count  );
    }

    if ((argc == 7  ) && (operation == 'C'))
    {


        char* arg_fName = argv[2];
        char* arg_lName = argv[3];
        char* arg_birthYear = argv[4];
        char* arg_phone = argv[5];
        char* arg_paid = argv[6];

        int birthYear = atoi(arg_birthYear);

        if (birthYear < 1900 && birthYear > 2050)
        {
            printf("%s\n", "invalid birthYear given");
        }
        else
        {
            if ((strlen(arg_phone) > 13) || (strlen(arg_fName) > 13) || (strlen(arg_lName) > 13))
            {
                printf("Strings can't be longer than 12 characters!\n");
            }
            else
            {
                bool paid = false;

                if ((strcmp(arg_paid, "true") == 0) || (strcmp(arg_paid, "True") == 0))
                {
                    paid = true;
                }

                validArgs = true;

                FILE* fp = openFile();
                createRecord(fp, arg_fName, arg_lName, birthYear, arg_phone, paid);
                fclose(fp);
            }
        }
    }

    if ((argc == 3) && ((operation == 'R') || (operation == 'D') || (operation == 'V') || (operation == 'W')))
    {
        char* arg_id = argv[2];
        unsigned int id = atoi(arg_id);
        if (id < 1)
        {
            printf("%s\n", "invalid Id given");
        }
        else
        {
            validArgs = true;

            if (operation == 'R')
            {
                FILE* fp = fopen(DB_FILENAME, "rb");
                readRecord(fp, id);
                fclose(fp);
            }
            else
            {
                if (operation == 'V')
                {
                    setVaccinationStatus(id, true);
                }
                else
                {
                    if (operation == 'W')
                    {
                        setVaccinationStatus(id, false);
                    }
                    else
                    {
                        if (operation == 'D')
                        {
                            deleteRecord(id);
                        }
                    }
                }
            }
        }
    }

    if ((argc == 8) && operation == 'U')
    {
        char* arg_id = argv[2];
        char* arg_fName = argv[3];
        char* arg_lName = argv[4];
        char* arg_birthYear = argv[5];
        char* arg_phone = argv[6];
        char* arg_paid = argv[7];

        int birthYear = atoi(arg_birthYear);

        unsigned int id = atoi(arg_id);
        if (id < 1)
        {
            printf("%s\n", "invalid Id given");
        }
        else
        {
            if (birthYear < 1900 && birthYear > 2050)
            {
                printf("%s\n", "invalid birthYear given");
            }
            else
            {
                if ((strlen(arg_phone) > 13) || (strlen(arg_fName) > 13) || (strlen(arg_lName) > 13))
                {
                    printf("Strings can't be longer than 12 characters!\n");
                }
                else
                {
                    bool paid = false;

                    if ((strcmp(arg_paid, "true") == 0) || (strcmp(arg_paid, "True") == 0))
                    {
                        paid = true;
                    }
                    validArgs = true;
                    updateRecord(id, arg_fName, arg_lName, birthYear, arg_phone, paid, false);
                }
            }
        }
    }

    if (!validArgs)
    {
        invalidArguments();
        return -1;
    }

}



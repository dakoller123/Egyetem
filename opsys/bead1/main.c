#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

static const char DB_FILENAME[] = "./database";

struct record
{
    unsigned long id;
    //char firstName[20];
    //char lastName[20];
    int birthYear;
    //char phoneNumber[14];
    //bool paid;
};



void readRecord(FILE *restrict fp)
{

}

void updateRecord(FILE *restrict fp, unsigned long id, char* firstName, char* lastName, int birthYear, char* phoneNumber, bool paid)
{

}

void deleteRecord()
{

}

int listRecords(FILE* restrict fp, bool print)
{
    if (print)
    {
        printf("%s\n", "listing all records...");
        printf("%s\n", "ID | NAME | BirthYear | PhoneNumber | Paid/Free version");
    }


    struct record input;
    printf("A");
    //input.id = 0;
    while(fread(&input, sizeof(struct record), 1, fp))
    {
        printf("B");
        if (print)
        {
            //printf("id = %lu name = %s %s birthYear = %d phoneNumber = %s paid = %d \n",
             //       input.id, input.firstName, input.lastName, input.birthYear, input.phoneNumber, input.paid);
            printf("id = %lu \n", input.id);
        }
    }

    //return input.id;
    return 0;
}

void createRecord(FILE *restrict fp, char* firstName, char* lastName, int birthYear, char* phoneNumber, bool paid)
{

    int lastId = listRecords(fp, false);
    printf("%s %d\n", "last id used was: ", lastId);
    struct record newRecord;
    newRecord.id = lastId + 1;
    //strcpy(newRecord.firstName, firstName);
    //strcpy(newRecord.lastName, lastName);
    newRecord.birthYear = birthYear;
    //strcpy(newRecord.phoneNumber, phoneNumber);
    //newRecord.paid = paid;

    fwrite(&newRecord, sizeof(struct record), 1, fp);
}


FILE* openFile()
{
    FILE* fp = fopen(DB_FILENAME, "a+");
    if (fp == 0)
    {
        printf("%s\n", "DB file was not found, creating one...");
        fp = fopen(DB_FILENAME, "w+");
    }
    else
    {
        printf("%s\n", "DB file was opened successfully");
    }
    return fp;
}

void invalidArguments()
{
    printf("%s \n", "Invalid Arguments, try '.\vakcinacio H' to see the help");
}

int main(int argc, char *argv[]) {


    FILE* fp;
    fp = openFile();

    bool validArgs = false;

    if ((argc == 2) && ((strcmp(argv[1], "H")) == 0))
    {
        validArgs = true;
        printf("%s\n", "Usage: specify the db filename as the first parameter, then either C,R,U,D,L for the options.");
        printf("%s\n", "Example: ./vakcinacio ./db.txt C GipszJakab 1945 0036202536099 True");
        printf("%s\n", "Example2: ./vakcinacio ./db.txt R 15");
        printf("%s\n", "For additional help: Type H and either C,R,U,D,L to get the help for those commands.");
        printf("%s\n", "Example: ./vakcinacio H C");
    }

    if ((argc == 2) && (strcmp(argv[1], "L")) == 0)
    {
        validArgs = true;
        listRecords(fp, true);
    }



    if ((argc == 7) && (strcmp(argv[1], "C")) == 0)
    {
        //"bin C FirstName LastName BirthYear Phone Paid"
        validArgs = true;

        int birthYear = atoi(argv[5]);

        if (birthYear < 1900 && birthYear > 2050)
        {
            printf("%s\n", "invalid birthYear given");
        }
        else
        {
            bool paid = false;

            if ((strcmp(argv[6], "true")) || (strcmp(argv[6], "True")))
            {
                paid = true;
            }

            createRecord(fp, argv[2], argv[3], birthYear, argv[5], paid);
        }

    }

    if ((argc == 3) && (strcmp(argv[1], "R")) == 0)
    {
        //"bin R Id"
        validArgs = true;
        readRecord(fp);
    }

    if ((argc == 9) && (strcmp(argv[1], "U")) == 0)
    {
        //"bin U Id C Name BirthYear Phone Paid"
        validArgs = true;

        char *ptr;
        unsigned long id = strtoul(argv[3], &ptr, 10);

        if (id < 1)
        {
            printf("%s\n", "invalid Id given");
        }
        else
        {

            int birthYear = atoi(argv[5]);

            if (birthYear < 1900 && birthYear > 2050)
            {
                printf("%s\n", "invalid birthYear given");
            }
            else
            {
                bool paid = false;

                if ((strcmp(argv[7], "true")) || (strcmp(argv[7], "True")))
                {
                    paid = true;
                }

                updateRecord(fp, id, argv[3], argv[4], birthYear, argv[6], paid);
            }
        }
    }

    if ((argc == 4) && (strcmp(argv[1], "D")) == 0)
    {
        //"bin D Id"
        validArgs = true;
        deleteRecord();
    }






    if (!validArgs)
    {
        invalidArguments();
    }

    fclose(fp);

}



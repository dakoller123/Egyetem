#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

static const char DB_FILENAME[] = "./database";
static const char DB_ID[] = "./id";

struct record
{

//(Például: Vakci Áci, 1953, 36301234567, igen )
    unsigned long id;
    char firstName[20];
    char lastName[20];
    int birthYear;
    char phoneNumber[14];
    bool paid;
};



void createRecord(FILE *restrict fp, char* firstName, char* lastName, int birthYear, char* phoneNumber, bool paid)
{
    struct record newRecord;
    newRecord.id = 0;
    strcpy(newRecord.firstName, firstName);
    strcpy(newRecord.lastName, lastName);
    newRecord.birthYear = birthYear;
    strcpy(newRecord.phoneNumber, phoneNumber);
    newRecord.paid = paid;

    fwrite(&newRecord, sizeof(struct record), 1, fp);

    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");
}

void readRecord(FILE *restrict fp)
{

}

void updateRecord(FILE *restrict fp, unsigned long id, char* firstName, char* lastName, int birthYear, char* phoneNumber, bool paid)
{

}

void deleteRecord()
{

}

void listRecords(FILE *restrict fp)
{
    printf("%s\n", "listing all records...");
    printf("%s\n", "ID | NAME | BirthYear | PhoneNumber | Paid/Free version");

    struct record input;
    while(fread(&input, sizeof(struct record), 1, fp))
    {
        printf ("id = %d name = %s %s birthYear = %d phoneNumber = %d paid = %d \n", input.id,
        input.firstName, input.lastName, input.birthYear, input.phoneNumber, input.paid);
        //printf ("id = %d name = %s %s birthYear = %d phoneNumber = \n", input.id,
        //input.firstName, input.lastName);
    }
}

void invalidArguments()
{
    printf("%s \n", "Invalid Arguments, try '.\vakcinacio H' to see the help");
}

int main(int argc, char *argv[]) {
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

    if (argc > 2)
    {
        char* fileName = argv[2];
        FILE *fp;

        if ((argc == 8) && (strcmp(argv[1], "C")) == 0)
        {
            //"bin fileName C FirstName LastName BirthYear Phone Paid"
            validArgs = true;
            fp = fopen(fileName, "a");

            int birthYear = atoi(argv[5]);

            if (birthYear < 1900 && birthYear > 2050)
            {
                printf("%s\n", "invalid birthYear given");
            }
            else
            {
                bool paid = false;

                if (argv[7] == "true" || argv[7] == "True")
                {
                    paid = true;
                }

                createRecord(fp, argv[3], argv[4], birthYear, argv[6], paid);
            }

        }

        if ((argc == 4) && (strcmp(argv[1], "R")) == 0)
        {
            //"bin fileName R Id"
            validArgs = true;
            readRecord(fp);
        }

        if ((argc == 9) && (strcmp(argv[1], "U")) == 0)
        {
            //"bin fileName U Id C Name BirthYear Phone Paid"
            validArgs = true;
            fp = fopen(fileName, "w");

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

                    if (argv[7] == "true" || argv[7] == "True")
                    {
                        paid = true;
                    }

                    updateRecord(fp, id, argv[3], argv[4], birthYear, argv[6], paid);
                }
            }
        }

        if ((argc == 4) && (strcmp(argv[1], "D")) == 0)
        {
            //"bin fileName D Id"
            validArgs = true;
            deleteRecord();
        }

        if ((argc == 3) && (strcmp(argv[1], "L")) == 0)
        {
            validArgs = true;
            fp = fopen(fileName, "r");
            listRecords(fp);
        }

        fclose(fp);
    }

    if (!validArgs)
    {
        invalidArguments();
    }



}



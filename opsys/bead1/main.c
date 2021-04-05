#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
static const char DB_FILENAME[] = "./database";
static const char DB_BACKUP_FILENAME[] = "./database.bak";
struct record
{
    unsigned int id;
    char firstName[18];
    char lastName[18];
    int birthYear;
    char phoneNumber[14];
    bool paid;
};



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
        printf("%i | %s %s | %d | %s | %d \n",
                   input.id, input.firstName, input.lastName, input.birthYear, input.phoneNumber, input.paid);
    }
    else
    {
        printf("Couldn't find the entry in the db!\n");
    }
}

void updateRecord(unsigned int id, char* firstName, char* lastName, int birthYear, char* phoneNumber, bool paid)
{
    FILE* oldDB = fopen(DB_FILENAME, "r");
    FILE* tmpDB = fopen(DB_BACKUP_FILENAME, "w");
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
        tmpDB = fopen(DB_BACKUP_FILENAME, "r");
        FILE* newDB = fopen(DB_FILENAME, "w");
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
            }
            fwrite(&tmp2, sizeof(struct record), 1, newDB);
        }

        fclose(newDB);
        fclose(tmpDB);
    }
}

void deleteRecord(unsigned int id)
{
    FILE* oldDB = fopen(DB_FILENAME, "r");
    FILE* tmpDB = fopen(DB_BACKUP_FILENAME, "w");
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
        tmpDB = fopen(DB_BACKUP_FILENAME, "r");
        FILE* newDB = fopen(DB_FILENAME, "w");
        struct record tmp2;
        while((fread(&tmp2, sizeof(struct record), 1, tmpDB)))
        {
            if (tmp.id != id)
            {
                fwrite(&tmp2, sizeof(struct record), 1, newDB);
            }
        }
        fclose(newDB);
        fclose(tmpDB);
    }
}

int listRecords(FILE* restrict fp, bool print)
{
    if (print)
    {
        printf("%s\n", "listing all records...");
        printf("%s\n", "ID | NAME | BirthYear | PhoneNumber | Paid/Free version");
    }

    struct record input;
    input.id = 0;
    while(fread(&input, sizeof(struct record), 1, fp))
    {
        if (print)
        {
            printf("%i | %s %s | %d | %s | %d \n",
                   input.id, input.firstName, input.lastName, input.birthYear, input.phoneNumber, input.paid);
        }
    }

    return input.id;
}

void createRecord(FILE *restrict fp, char* firstName, char* lastName, int birthYear, char* phoneNumber, bool paid)
{
    int lastId = listRecords(fp, false);
    printf("%s %d\n", "last id used was: ", lastId);
    struct record newRecord;
    newRecord.id = lastId + 1;
    strcpy(newRecord.firstName, firstName);
    strcpy(newRecord.lastName, lastName);
    newRecord.birthYear = birthYear;
    strcpy(newRecord.phoneNumber, phoneNumber);
    newRecord.paid = paid;

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
        printf("%s\n", "Usage: specify the type of operation: C,R,U,D,L then additional parameters");
        printf("%s\n", "Example: ./vakcinacio  C GipszJakab 1945 0036202536099 True");
        printf("%s\n", "Example2: ./vakcinacio . R 15");
        printf("%s\n", "For additional help: Type H and either C,R,U,D,L to get the help for those commands.");
        printf("%s\n", "Example: ./vakcinacio H C");
    }

    if ((argc == 2) && (operation == 'L'))
    {
        validArgs = true;
        FILE* fp = openFile();
        listRecords(fp, true);
        fclose(fp);
    }



    if ((argc == 7  ) && (operation == 'C'))
    {
        validArgs = true;

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
            bool paid = false;

            if ((strcmp(arg_paid, "true")) || (strcmp(arg_paid, "True")))
            {
                paid = true;
            }
            validArgs = true;

            FILE* fp = openFile();
            createRecord(fp, arg_fName, arg_lName, birthYear, arg_phone, paid);
            fclose(fp);
        }

    }


    if ((argc == 3) && ((operation == 'R') || (operation == 'D')))
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
                FILE* fp = fopen(DB_FILENAME, "r");
                readRecord(fp, id);
                fclose(fp);
            }
            else
            {
                deleteRecord(id);
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
                bool paid = false;

                if ((strcmp(arg_paid, "true")) || (strcmp(arg_paid, "True")))
                {
                    paid = true;
                }
                validArgs = true;
                updateRecord(id, arg_fName, arg_lName, birthYear, arg_phone, paid);
            }
        }
    }

    if (!validArgs)
    {
        invalidArguments();
        return -1;
    }

}



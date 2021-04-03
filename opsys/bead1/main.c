#include <stdio.h>
#include <string.h>
 #include <stdbool.h>
const int LINE_MAX = 999;

struct Record
{

//(Például: Vakci Áci, 1953, 36301234567, igen )
    int Id;
    char* Name;
    int BirthYear;
    long PhoneNumber;
    bool Paid;
};

void createRecord()
{

}

void readRecord()
{

}

void updateRecord()
{

}

void deleteRecord()
{

}

void listRecords(char* fileName)
{

    FILE *fp;
    fp = fopen(fileName, "r");
    printf("%s\n", "ID | NAME | BirthYear | PhoneNumber | Paid/Free version");

    char line[LINE_MAX];
    while (fgets(line, LINE_MAX, fp) != NULL)
    {
        printf("%s\n", line);
    }
    fclose(fp);
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

        if ((argc == 7) && (strcmp(argv[1], "C")) == 0)
        {
            //"bin fileName C Name BirthYear Phone Paid"
            validArgs = true;
            createRecord();
        }

        if ((argc == 4) && (strcmp(argv[1], "R")) == 0)
        {
            //"bin fileName R Id"
            validArgs = true;
            readRecord();
        }

        if ((argc == 9) && (strcmp(argv[1], "U")) == 0)
        {
            //"bin fileName U Id C Name BirthYear Phone Paid"
            validArgs = true;
            updateRecord();
        }

        if ((argc == 4) && (strcmp(argv[1], "D")) == 0)
        {
            //"bin fileName D Id"
            validArgs = true;
            deleteRecord();
        }

        if ((argc == 3) && (strcmp(argv[1], "L")) == 0)
        {
            printf("%s\n", "listing...");
            validArgs = true;
            listRecords(fileName);
        }
    }

    if (!validArgs)
    {
        invalidArguments();
    }



}



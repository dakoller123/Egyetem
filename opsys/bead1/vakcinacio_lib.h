
static const char DB_FILENAME[] = "./database";
static const char DB_BACKUP_FILENAME[] = "./database.bak";

struct record
{
    unsigned int id;
    char firstName[14];
    char lastName[14];
    int birthYear;
    char phoneNumber[14];
    bool paid;
    bool vaccinated;
};

FILE* openFile()
{
    FILE* fp = fopen(DB_FILENAME, "a+b");
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



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



int countRecord()
{
    FILE* fp = openFile();
    struct record input;
    int result = 0;
    while(fread(&input, sizeof(struct record), 1, fp))
    {
        if (input.vaccinated == false)
        {
            result = result +1;
        }
    }
    fclose(fp);
    return result;
}



void writeVaccinationSuccess(unsigned int* ids, int idCount)
{
    printf("AAAA" );
    for (int i=0; i<idCount; i++)
    {
        printf(" %d ", ids[i]);
    }
    printf("\n");


    FILE* oldDB = fopen(DB_FILENAME, "rb");
    FILE* tmpDB = fopen(DB_BACKUP_FILENAME, "wb");

    struct record tmp;
    while((fread(&tmp, sizeof(struct record), 1, oldDB)))
    {
        for (int i=0; i<idCount; i++)
        {
            if (tmp.id == ids[i])
            {
                printf("Going to set vaccination status for id: %d \n", ids[i]);
                tmp.vaccinated = true;
            }
        }
        fwrite(&tmp, sizeof(struct record), 1, tmpDB);
    }
    fclose(tmpDB);
    fclose(oldDB);

    tmpDB = fopen(DB_BACKUP_FILENAME, "rb");
    FILE* newDB = fopen(DB_FILENAME, "wb");
    struct record tmp2;
    while((fread(&tmp2, sizeof(struct record), 1, tmpDB)))
    {
        fwrite(&tmp2, sizeof(struct record), 1, newDB);
    }

    fclose(newDB);
    fclose(tmpDB);


}

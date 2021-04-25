
static const char DB_FILENAME[] = "./database";
static const char DB_BACKUP_FILENAME[] = "./database.bak";
struct flock lock_data;

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


  lock_data.l_whence=SEEK_SET;//the absolute starting position of locking: SEEK_SET - start of file, SEEK_END - end of file, SEEK_CUR - actual place of
  lock_data.l_start=0; // relative position of locking to l_whence
  lock_data.l_len=0; //how long is the locked part of the file, 0 - if it depends on the whole file
  int rc=0; //result of lock
  f=open("data.txt",O_RDWR|O_TRUNC|O_CREAT,S_IRUSR|S_IWUSR);

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



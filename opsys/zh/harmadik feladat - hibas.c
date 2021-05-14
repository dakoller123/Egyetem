#include <unistd.h> //fork
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h> //waitpid
#include <signal.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/msg.h>

bool verbose = true;
pid_t firstProcessId = 1; //Vahur
pid_t secondProcessId = 1; //Ficko

bool SIGUSR1_received = false;
bool SIGUSR2_received = false;

bool endLoop = false;

const char* pipeNameIn[2] = {"/tmp/VahurPipeIn", "/tmp/FickoPipeIn"};
const char* pipeNameOut[2] = {"/tmp/VahurPipeOut", "/tmp/FickoPipeOut"};


key_t messageQueueKey;
int messageQueue;



struct mesg_buffer {
    long mesg_type;
    int numberOfFoxes;
    int senderId;
};


void signalHandler(int signumber)
{
    if (verbose) printf("Signal Received: %d\n",signumber);
    if (signumber == 10)
    {
        SIGUSR1_received = true;
    }
    else if (signumber == 12)
    {
        SIGUSR2_received = true;
    }
}



void mainProcessBeforeFork(int argc, char* argv[])
{

    for (int i=0; i<2; i++)
    {
        unlink(pipeNameIn[i]);
        mkfifo(pipeNameIn[i], S_IRUSR|S_IWUSR );
        unlink(pipeNameOut[i]);
        mkfifo(pipeNameOut[i], S_IRUSR|S_IWUSR );
    }

    struct sigaction sigact;
    sigact.sa_handler=signalHandler;
    sigemptyset(&sigact.sa_mask);
    sigact.sa_flags=0;
    sigaction(SIGUSR1,&sigact,NULL);
    sigaction(SIGUSR2,&sigact,NULL);

    if (verbose) printf("%d", argc);
    messageQueueKey = ftok(argv[0],1);
    messageQueue = msgget( messageQueueKey, 0600 | IPC_CREAT );
    if ( messageQueue < 0 ) {
      perror("msgget");
      exit(1);
    }

}


void mainProcessAfterFork()
{
    //VUK
    if (verbose) printf("0 Main process (VUK) after fork START\n");


    sleep(3);
    kill(firstProcessId,SIGUSR1); //FELDERITES Vahurnak
    kill(secondProcessId,SIGUSR1); //FELDERITES Ficurnak

    int foundFoxes[3] = {0, 0};


    for (int i=0; i<2; i++)
    {
        int status;
        struct mesg_buffer message;
        status = msgrcv(messageQueue, &message, sizeof(struct mesg_buffer), 5, 0 );
        if ( status < 0 )
              perror("msgrcv");

        if (message.senderId == 1)
        {
            printf("0 Vuk megkapta a kisrokakat Vahurtol : %d %d \n", message.numberOfFoxes, message.senderId);
            foundFoxes[0] = message.numberOfFoxes;
        }
        else
        {
            printf("0 Vuk megkapta a kisrokakat Fickotol : %d %d \n", message.numberOfFoxes, message.senderId);
            foundFoxes[1] = message.numberOfFoxes;
        }
    }

    for (int i=0; i<2; i++)
    {
        int plannedVaccinations = foundFoxes[i]*8/10;
        FILE* pipe = fopen(pipeNameIn[i], "w");
        if (!pipe) perror("pipe");
        fwrite(&plannedVaccinations, sizeof(int), 1, pipe);
        fclose(pipe);
    }


    for (int i=0; i<2; i++)
    {
        pause();
        if (SIGUSR1_received)
        {
            SIGUSR1_received = false;
            if (verbose) printf("0 VAHUR_CSAPAT Received\n");

        }
        else if (SIGUSR2_received)
        {
            SIGUSR2_received = false;
            if (verbose) printf("0 FICKO_CSAPAT received \n");
        }
    }

    //itt most mindket folyamatot bevartuk meg mielott a pipebol olvasnank
    //nem hatekony mukodes, lehetne javitani. Igy viszont nem interruptolja a csovezest a masik gyerek. lehet itt inkabb messagequeue kellett volna, de nincs idom atirni
    int successfulVaccinations[3] = {0, 0};
    for (int i=0; i<2; i++)
    {
        FILE* pipe = fopen(pipeNameOut[i], "r");
        if (!pipe) perror("pipe");
        fread(&successfulVaccinations[i], sizeof(int), 1, pipe);
        fclose(pipe);
    }

    printf("0 Vahur sikeres oltasai: %d, Fickoe: %d", successfulVaccinations[0], successfulVaccinations[1]);

    int status;
    waitpid(firstProcessId,&status,0);
    waitpid(secondProcessId,&status,0);
    if (verbose) printf("0 Main after fork END\n");
}

void childProcess(int processNumber)
{
    //ProcessNumber == 1 => Vahur
    //ProcessNumber == 2 => Ficko
    if (verbose) printf("%d Child Process START\n", processNumber);

    pid_t parentId = getppid();


    pause();
    if(SIGUSR1_received)
    {
        if (processNumber == 1) sleep(4);
        if (processNumber == 2) sleep(1);
        srand ( time(NULL) );
        int numberOfFoxes = (rand() % 11) + 20;
        if (verbose) printf("%d Talalt oltando kisrokak szama: %d\n", processNumber, numberOfFoxes);
        const struct mesg_buffer message = { 5, numberOfFoxes, processNumber };

        int status;
        status = msgsnd( messageQueue, &message, sizeof(message), 0 );
        if ( status < 0 )  perror("msgsnd");

        int plannedVaccinations = 0;
        FILE* pipeIn = fopen(pipeNameIn[processNumber-1], "r");
        if (!pipeIn) perror("pipeIn");
        fread(&plannedVaccinations, sizeof(int), 1, pipeIn);
        fclose(pipeIn);

        printf("%d Megkaptam Vuktol a tervezett oltasok szamat: %d\n", processNumber, plannedVaccinations);



        if (processNumber == 1)
        {
            kill(parentId,SIGUSR1);    //VAHUR_CSAPAT
        }
        else
        {
            kill(parentId,SIGUSR2);    //FICKO_CSAPAT
        }

        int successfulVaccinations = plannedVaccinations *9/10;
        FILE* pipeOut = fopen(pipeNameOut[processNumber-1], "r");
        if (!pipeOut) perror("pipeOut");
        fwrite(&successfulVaccinations, sizeof(int), 1, pipeOut);
        fclose(pipeOut);



    }
    if (verbose) printf("%d Child Process END\n", processNumber);
}

int main(int argc, char* argv[])
{

    mainProcessBeforeFork(argc, argv);

    if (verbose) printf("0 Going to fork to create first process (Vahur) !\n");
    firstProcessId = fork();
    if (firstProcessId<0)
    {
        //Error
        perror("Error on first fork");
        exit(1);
    }

    if (firstProcessId==0)
    {
        childProcess(1);
        return 0;
    }

    if (verbose) printf("0 Going to fork to create second process (Ficko) !\n");
    secondProcessId = fork();
    if (secondProcessId<0)
    {
        //Error
        perror("Error on second fork");
        exit(1);
    }

    if (secondProcessId==0)
    {
        childProcess(2);
        return 0;
    }

    mainProcessAfterFork();
}


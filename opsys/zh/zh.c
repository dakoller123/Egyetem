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

bool endLoop = false;



const char* pipeNameIn[2] = {"/tmp/firstProcessPipeIn", "/tmp/secondProcessPipeIn"};
const char* pipeNameOut[2] = {"/tmp/firstProcessPipeOut", "/tmp/secondProcessPipeOut"};


key_t messageQueueKey;
int messageQueue;



struct mesg_buffer {
    long mesg_type;
    int numberOfFoxes;
};


void signalHandler(int signumber)
{
    if (verbose) printf("Signal Received: %d\n",signumber);
    if (signumber == 10)
    {
        SIGUSR1_received = true;
    }

}



void mainProcessBeforeFork(int argc, char* argv[])
{

//    unlink(pipeNameIn[0]);
//    unlink(pipeNameIn[1]);
//    unlink(pipeNameOut[0]);
//    unlink(pipeNameOut[1]);
//
//    mkfifo(pipeNameIn[0], S_IRUSR|S_IWUSR );
//    mkfifo(pipeNameOut[0], S_IRUSR|S_IWUSR );
//    mkfifo(pipeNameIn[1], S_IRUSR|S_IWUSR );
//    mkfifo(pipeNameOut[1], S_IRUSR|S_IWUSR );


    struct sigaction sigact;
    sigact.sa_handler=signalHandler;
    sigemptyset(&sigact.sa_mask);
    sigact.sa_flags=0;
    sigaction(SIGUSR1,&sigact,NULL);

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

    int status;

    struct mesg_buffer message;

    pause();
    pause();

    status = msgrcv(messageQueue, &message, sizeof(struct mesg_buffer), 5, 0 );

    if ( status < 0 )
          perror("msgrcv");

    printf("0 Vuk megkapta a kisrokakat Vahurtol : %d \n", message.numberOfFoxes);

    status = msgrcv(messageQueue, &message, sizeof(struct mesg_buffer), 5, 0 );

    if ( status < 0 )
          perror("msgrcv");

    printf("0 Vuk megkapta a kisrokakat Fickotol : %d \n", message.numberOfFoxes);

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
        sleep(getpid() % 2);
        srand ( time(NULL) );
        int numberOfFoxes = (rand() % 11) + 20;
        if (verbose) printf("%d Talalt oltando kisrokak szama: %d\n", processNumber, numberOfFoxes);
        const struct mesg_buffer message = { 5, numberOfFoxes };

        int status;
        status = msgsnd( messageQueue, &message, sizeof(message), 0 );
        if ( status < 0 )  perror("msgsnd");

        kill(parentId,SIGUSR1);

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


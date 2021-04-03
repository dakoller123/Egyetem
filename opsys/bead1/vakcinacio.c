#include <stdio>
int main(int argc, char *argv[]) {
    if (argc > 1)
    {
        for (int i=0; i < argc-1; i++)
        {
            printf("%c \n", argv[i]);
        }
    }

}

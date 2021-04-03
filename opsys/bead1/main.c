#include <stdio.h>
int main(int argc, char *argv[]) {
    if (argc > 1)
    {
        for (int i=0; i < argc-1; i++)
        {
            printf("%s \n", argv[i+1]);
        }
    }

}

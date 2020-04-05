#include 'dicontainer.h'

DIContainer g_DIContainer;

int main()
{

    FileReader fileReader("path_goes_here");
    g_DIContainer.AddFileReader();
    return 0;
}
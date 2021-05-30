#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main()
{
     /* initialize random seed: */
    srand (time(NULL));
    cout << "Hello world!" << endl;
    return 0;
}

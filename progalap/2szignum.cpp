#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    double x, y;
    bool hiba;

//    do {
//        cout << "adj megy egy valos szamot!" << endl;
//        cin >> x;
//        hiba = cin.fail();
//        if (hiba){
//            cin.clear();
//            cin.ignore(1000, '\n');
//        }
//    } while (hiba);

    string s;
    do {
        cout << "adj megy egy valos szamot: " <<endl;
        getline(cin, s);
        x = atof(s.c_str());
        if (x==0 && s!="0"){
            cout << "hiba tortent" << endl;
        }
    } while (x==0 && s!="0");
    cout << "beolvasott szam: " << x << endl;

    if ( x>0){
        y = 1.0;
    }
    else{
        if (x = 0){
            y = 0.0;
        }
        else {
            y = -1.0;
        }
    }

    cout << "signum(" << x <<") = " << y << endl;
}

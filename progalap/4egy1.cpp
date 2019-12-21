#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{

    enum  HanyLehet {egy, vegtelen, nulla};
    HanyLehet hanyMegoldasVan;

    double a,b,x;
    cout << "add meg az a es b kitevok ertekeit" << endl;
    cin >> a;
    cin >> b;

    if (a == 0){
        if (b == 0){
            hanyMegoldasVan = vegtelen;
        }
        else {
            hanyMegoldasVan = nulla;
        }
    }
    else{
        hanyMegoldasVan = egy;
    }

    switch (hanyMegoldasVan){

        case egy : {
            x = b/a;
            cout << "a gyok erteke: " << x << endl;
            break;
        }

        case nulla: {
            cout << "Nincs megoldasa az egyenletnek" << endl;
            break;
        }

        case vegtelen :{
            cout << "Minden valos szam megoldas" << endl;
             break;
        }

        default : {
            cout << "Hiba a switch elagazban" << endl;
            break;
        }

    }

}

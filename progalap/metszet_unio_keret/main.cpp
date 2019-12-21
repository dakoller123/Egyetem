#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 100;

struct eredmeny{
    string EHA;
    int JEGY;
};

void beolvas(string filename, string uzenet, int &DB, eredmeny OSZT[]);
void metszet(int ZHDB, int PZHDB, const eredmeny ZH[], const eredmeny PZH[],
             int &DB, string MINDKET[]);
void unio(int ZHDB, int PZHDB, const eredmeny ZH[], const eredmeny PZH[],
          int &DB, string EGYIK[]);
void kiir_be(int DB, const eredmeny OSZT[]);
void kiir_ki(int DB, const string OSZT[]);

int main() {
    int ZHDB,PZHDB,DBE,DBME;
    eredmeny ZH[MAX],PZH[MAX];
    string MINDKET[MAX],EGYIK[MAX];

    beolvas("zh1.txt","ZH:",ZHDB, ZH);
    beolvas("zh2.txt","PÓT ZH:",PZHDB, PZH);

    metszet(ZHDB,PZHDB,ZH,PZH,DBME,MINDKET);
    unio(ZHDB,PZHDB,ZH,PZH,DBE,EGYIK);

    cout<<"\nMindegyiken probalkoztak:\n";
    kiir_ki(DBME,MINDKET);
    cout<<"\nValamelyiken probalkoztak:\n";
    kiir_ki(DBE,EGYIK);

    return 0;
}


void beolvas(string filename, string uzenet, int &DB, eredmeny OSZT[]){
    ifstream ifs(filename.c_str());
    if (ifs.is_open()) {
        DB = 0;
        while (!ifs.eof()) {

            ifs >> OSZT[DB].EHA;
            ifs >> OSZT[DB].JEGY;
            DB++;
        }
        ifs.close();
        cout<<"\n"<<uzenet<<"\n";
        kiir_be(DB,OSZT);
    } else {cout<<"Hiba a fajllal!";}
}
void metszet(int ZHDB, int PZHDB, const eredmeny ZH[], const eredmeny PZH[],
             int &DB, string MINDKET[]){
   DB=0;

   for(int i=0; i<ZHDB; i++)
   {
        int j=-1;

        do
       {
           j++;
       } while (j<PZHDB-1 && (ZH[i].EHA != PZH[j].EHA ));

        if (j < PZHDB-1)
        {
            MINDKET[DB] = ZH[i].EHA;
            DB++;
        }

    }


}

void unio(int ZHDB, int PZHDB, const eredmeny ZH[], const eredmeny PZH[],
          int &DB, string EGYIK[]){
   DB=ZHDB;

   for(int j=0; j<PZHDB; j++)
    {
        int i=-1;
        do{
            i++;
        } while (i<PZHDB && PZH[i].EHA != ZH[j].EHA);

            if (i < PZHDB){
             EGYIK[DB] = PZH[i].EHA;
            DB++;
    }
    }



}
void kiir_be(int DB, const eredmeny OSZT[]){
    for (int i = 0; i<DB; i++) {
        cout << i+1 << ". hallgato: " << OSZT[i].EHA << " - " << OSZT[i].JEGY << endl;
    }

}

void kiir_ki(int DB, const string OSZT[]){
     for (int i = 0; i<DB; i++) {
        cout << i+1 << ". hallgato: " << OSZT[i] << endl;
    }
}

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <time.h>
#include "adventurer.h"
#include "land.h"

using namespace std;



//Task:     Read data from a file and fill the input vectors
//Input:    string fileName - name of the text file
//          vector<Adventurer*> &adventurers  - vector of the pointers of the adventurers
//          vector<Land*> &lands  - vector of the pointers of the lands
//Output:   vector<Adventurer*> &adventurers  - vector of the pointers of the adventurers
//          vector<Land*> &lands  - vector of the pointers of the lands
//Activity: Based on the text file, it creates the adventurers and puts their addresses into vector adventurers.
//          It fills the vector of lands, too.
void create(const string &fileName, vector<Adventurer*> &adventurers, vector<Land*> &lands)
{
    ifstream f(fileName);
    if(f.fail())
    {
        cout << "Wrong file name!\n";
        exit(1);
    }

    // adventurers
    unsigned int n;
    f >> n;
    adventurers.resize(n);
    for( unsigned int i = 0; i < n; ++i )
    {
        char ch;
        string name;
        int health;
        f >> ch >> name >> health;
        if (health>0)
        {
            switch(ch)
            {
                case 'O' :
                    adventurers[i] = new Confident(name,health);
                    break;
                case 'A' :
                    adventurers[i] = new Cautious(name,health);
                    break;
                case 'B' :
                    adventurers[i] = new Brave(name,health);
                    break;
            }
        }
    }

    // lands
    string lnds;
    f >> lnds;
    unsigned int m = lnds.size();
    lands.resize(m);
    for( unsigned int j = 0; j < m; ++j )
    {
        switch(lnds[j])
        {
            case 'E' :
                lands[j] = Enemy::instance();
                break;
            case 'N' :
                lands[j] = NoMansLand::instance();
                break;
            case 'F' :
                lands[j] = Friend::instance();
                break;
        }
    }
}



//Task:     Set the health of every alive adventurer to maximum
//Input:    vector<Adventurer*> &adventurers  - vector of the pointers of the adventurers
//Output:   vector<Adventurer*> &adventurers  - vector of the pointers of the adventurers
//Activity: It calls method heal() for every adventurer for which health is positive
void healing(vector<Adventurer*> adventurers)
{
    for( unsigned int j = 0; j < adventurers.size(); ++j ) /// start every round with maximal health
    {
        if (adventurers[j]->alive()) adventurers[j]->heal();
    }
}



//Task:     All the active adventurers cross one land
//Input:    bool printToConsole - selector for writing to console or not
//          vector<Adventurer*> &adventurers  - vector of the pointers of the adventurers
//          vector<Adventurer*> &died  - vector of the pointers of the adventurers
//          int active  - number of active adventurers
//Output:   vector<Adventurer*> &adventurers  - vector of the pointers of the adventurers
//          vector<Adventurer*> &died  - vector of the pointers of the adventurers
//          int active  - number of active adventurers
//Activity: Calls method cross() for every adventurer which decides if an adventurer continues after crossing or not
//          If somebody dies, he is added to the vector of died heroes and removed from the vector of alive adventurers.
//          If somebody does not continue for some reason, the number of active adventurers is decreased
int moving(const bool printToConsole,vector<Adventurer*> &adventurers, vector<Adventurer*> &died, Land* land,int active)
{
    int counter = active;
    for( unsigned int j = 0; j < adventurers.size(); ++j )
    {
        if ( adventurers[j]->in() && !adventurers[j]->cross(land, active) )
        {
            --counter; /// if active and does not continue
            if (adventurers[j]->alive())
            {
                if (printToConsole) cout << *adventurers[j] << " is out.\n";
            }
            else
            {
                if (printToConsole) cout << *adventurers[j] << " is dead.\n";
                died.push_back(adventurers[j]);
                adventurers[j] = adventurers.back();
                adventurers.pop_back();
                --j;
            }
        }
        else if (adventurers[j]->in())
        {
            if (printToConsole) cout << *adventurers[j] << endl;
        }
    }
    return counter;
}



//Task:     One attempt to clear all the lands
//Input:    bool printToConsole - selector for writing to console or not
//          vector<Adventurer*> &adventurers  - vector of the pointers of the adventurers
//          vector<Adventurer*> &died  - vector of the pointers of the adventurers
//          vector<Land*> &lands  - vector of the pointers of the lands
//Output:   vector<Adventurer*> &adventurers  - vector of the pointers of the adventurers
//          vector<Adventurer*> &died  - vector of the pointers of the adventurers
//          vector<Land*> &lands  - vector of the pointers of the lands
//          int active  - number of active adventurers
//Activity: Calls method moving() for every land which gives back the number of active adventurers at the end of every crossing
//          If the number of active adventurers decrease to zero, the round finishes unsuccessfully
//          If the adventurers cross a land, the land is improved
int attempt(const bool printToConsole,vector<Adventurer*> &adventurers,vector<Adventurer*> &died, vector<Land*> &lands)
{
    healing(adventurers);
    int active = adventurers.size(); /// number of active adventurers
    for( unsigned int i = 0; i < lands.size(); ++i )
    {
        if (printToConsole) cout << endl << *lands[i] << endl;
        active = moving(printToConsole,adventurers,died,lands[i],active);
        if (active == 0) break; /// if nobody remains active, the round finishes
        lands[i] = lands[i]->improve(); ///otherwise, the land is improved
    }
    return active;
}



//Task:     Mission
//Input:    vector<Adventurer*> &adventurers  - vector of the pointers of the adventurers
//          vector<Land*> &lands  - vector of the pointers of the lands
//Output:   vector<Adventurer*> &adventurers  - vector of the pointers of the adventurers
//          vector<Land*> &lands  - vector of the pointers of the lands
//          vector<Adventurer*> &died         - vector of the pointers of the died adventurers
//Activity: The adventurers cross the lands as long as there is at least one enemy or until all the adventurers die.
//          Te names of the died adventurers are collected.
bool mission(bool printToConsole,vector<Adventurer*> &adventurers,vector<Adventurer*> &died, vector<Land*> &lands)
{
    try
    {
        died.clear();
        for( unsigned int rNo = 1; rNo < 4; ++rNo )
        {
            if (printToConsole)
            {
                cout << endl;
                cout << "|----------------|" << endl;
                cout << "|    "<< rNo <<". round    |" << endl;
                cout << "|----------------|" << endl;
            }
            if (attempt(printToConsole,adventurers,died,lands) > 0) return true; ///if there is active adventurer at the end of one round, then all lands are cleared
            if (adventurers.size() == 0) return false; /// if all the adventurers have died then mission has failed
        }
    }
    catch(exception e)
    {
        cout << e.what() << endl;
    }
    return false;
}



//Task:     Destruction of the adventurers
//Input:    vector<Adventurer*> &vec  - vector of the pointers of the adventurers
//Activity: destroys every dinamically created adventurer
template <typename Item>
void destroy(vector<Item*> &vec)
{
    for(unsigned int i = 0; i < vec.size(); ++i)
        delete vec[i];
}



//Task:     Destruction of the lands
//Activity: destroys every dinamically created land
void destroyLands()
{
    Enemy::destroy();
    NoMansLand::destroy();
    Friend::destroy();
}



// Template for printing a vector of pointers, writing operator is needed
template <typename Item>
void print (const vector<Item*> &vec)
{
    for (Item* ptr : vec)
    {
        cout << *ptr << endl;
    }
}


// Change between manual and test mode
//#define NORMAL_MODE
#ifdef NORMAL_MODE

bool Adventurer::_randomized_ = true; // randomized lifechanges during the mission

//Task:          Field creation for adventurers to clean, collecting the name of the died heroes.
//Input: text file
//Output: Status of every round, names of the died heroes.
//Activity: Creating the adventurers and the lands, then simulation and writing the results
int main()
{
    // Random initializer
    srand(time(NULL));

    // print to console
    bool consolePrint = true;


    // Main variables
    vector<Adventurer*> adventurers;
    vector<Adventurer*> died;
    vector<Land*> lands;

    // Reading data from the file
    create("input.txt", adventurers, lands );

    // Initial data
    cout << "Adventurers:\n";
    print(adventurers);
    cout << "\nLands of the kingdom:\n";
    print(lands);

    // The mission
    cout << "\n--- Mission starts ---\n\n";
    if (mission(consolePrint,adventurers, died, lands)) cout << "\nMission accomplished.\n";
    else cout << "\nMission failed.\n";

    if (died.size() > 0)
    {
        cout << "\n--- In honor of our died heroes ---\n";
        print(died);
    }

    // Destruction of objects
    destroy(adventurers);
    destroy(died);
    destroyLands();
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

bool Adventurer::_randomized_ = false; // not randomized mission for testing

TEST_CASE("no lands", "inp10.txt")
{
    vector<Adventurer*> adventurers;
    vector<Land*> lands;
    vector<Adventurer*> died;

    create("inp10.txt", adventurers, lands);
    CHECK(mission(false,adventurers, died, lands));
    CHECK(died.size() == 0);

    destroy(adventurers);
    destroy(died);
}
TEST_CASE("no adventurers", "inp11.txt")
{
    vector<Adventurer*> adventurers;
    vector<Land*> lands;
    vector<Adventurer*> died;

    create("inp11.txt", adventurers, lands);
    CHECK_FALSE(mission(false,adventurers, died, lands));
    CHECK(died.size() == 0);

    destroy(adventurers);
    destroy(died);
}
TEST_CASE("1 adventurer, 1 land", "inp12-20.txt")
{
    vector<Adventurer*> adventurers;
    vector<Land*> lands;
    vector<Adventurer*> died;

    SECTION("Enemy's land")
    {
        create("inp12.txt", adventurers, lands );
        CHECK_FALSE(mission(false,adventurers, died, lands));
        CHECK(died.size() == 1);
        CHECK(adventurers.size() == 0);
        CHECK(lands[0]->type() == "Enemy");
        destroy(adventurers);
        destroy(died);

        create("inp13.txt", adventurers, lands );
        CHECK_FALSE(mission(false,adventurers, died, lands));
        CHECK(died.size() == 1);
        CHECK(adventurers.size() == 0);
        CHECK(lands[0]->type() == "Enemy");
        destroy(adventurers);
        destroy(died);

        create("inp14.txt", adventurers, lands );
        CHECK_FALSE(mission(false,adventurers, died, lands));
        CHECK(died.size() == 1);
        CHECK(adventurers.size() == 0);
        CHECK(lands[0]->type() == "Enemy");
        destroy(adventurers);
        destroy(died);
    }

    SECTION("No man's land")
    {
        create("inp15.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 1);
        CHECK(adventurers[0]->health() == 100);
        CHECK(lands[0]->type() == "Friend");
        destroy(adventurers);
        destroy(died);

        create("inp16.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 1);
        CHECK(adventurers[0]->health() == 100);
        CHECK(lands[0]->type() == "Friend");
        destroy(adventurers);
        destroy(died);

        create("inp17.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 1);
        CHECK(adventurers[0]->health() == 100);
        CHECK(lands[0]->type() == "Friend");
        destroy(adventurers);
        destroy(died);
    }

    SECTION("Friend's land")
    {
        create("inp18.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 1);
        CHECK(adventurers[0]->health() == 100);
        CHECK(lands[0]->type() == "Friend");
        destroy(adventurers);
        destroy(died);

        create("inp19.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 1);
        CHECK(adventurers[0]->health() == 100);
        CHECK(lands[0]->type() == "Friend");
        destroy(adventurers);
        destroy(died);

        create("inp20.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 1);
        CHECK(adventurers[0]->health() == 100);
        CHECK(lands[0]->type() == "Friend");
        destroy(adventurers);
        destroy(died);
    }
}

TEST_CASE("2 adventurers, 1 land", "inp21-29.txt")
{
    vector<Adventurer*> adventurers;
    vector<Adventurer*> died;
    vector<Land*> lands;

    SECTION("Enemy's land")
    {
        create("inp21.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 2);
        CHECK(adventurers[0]->health() == 50);
        CHECK(adventurers[1]->health() == 50);
        CHECK(lands[0]->type() == "No man");
        destroy(adventurers);
        destroy(died);

        create("inp22.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 2);
        CHECK(adventurers[0]->health() == 50);
        CHECK(adventurers[1]->health() == 50);
        CHECK(lands[0]->type() == "No man");
        destroy(adventurers);
        destroy(died);

        create("inp23.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 2);
        CHECK(adventurers[0]->health() == 50);
        CHECK(adventurers[1]->health() == 50);
        CHECK(lands[0]->type() == "No man");
        destroy(adventurers);
        destroy(died);
    }

    SECTION("Friend's land")
    {
        create("inp24.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 2);
        CHECK(adventurers[0]->health() == 100);
        CHECK(adventurers[1]->health() == 100);
        CHECK(lands[0]->type() == "Friend");
        destroy(adventurers);
        destroy(died);

        create("inp25.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 2);
        CHECK(adventurers[0]->health() == 100);
        CHECK(adventurers[1]->health() == 100);
        CHECK(lands[0]->type() == "Friend");
        destroy(adventurers);
        destroy(died);

        create("inp26.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 2);
        CHECK(adventurers[0]->health() == 100);
        CHECK(adventurers[1]->health() == 100);
        CHECK(lands[0]->type() == "Friend");
        destroy(adventurers);
        destroy(died);
    }

    SECTION("No man's land")
    {
        create("inp27.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 2);
        CHECK(adventurers[0]->health() == 100);
        CHECK(adventurers[1]->health() == 100);
        CHECK(lands[0]->type() == "Friend");
        destroy(adventurers);
        destroy(died);

        create("inp28.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 2);
        CHECK(adventurers[0]->health() == 100);
        CHECK(adventurers[1]->health() == 100);
        CHECK(lands[0]->type() == "Friend");
        destroy(adventurers);
        destroy(died);

        create("inp29.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 2);
        CHECK(adventurers[0]->health() == 100);
        CHECK(adventurers[1]->health() == 100);
        CHECK(lands[0]->type() == "Friend");
        destroy(adventurers);
        destroy(died);
    }
}

TEST_CASE("4 adventurers", "inp31-33.txt")
{
    vector<Adventurer*> adventurers;
    vector<Land*> lands;
    vector<Adventurer*> died;

    SECTION("3 enemy's land, 1st and last dies")
    {
        create("inp31.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 2);
        CHECK(died[0]->name() == "Bravy");
        CHECK(died[1]->name() == "Confy");
        CHECK(adventurers.size() == 2);
        CHECK(adventurers[0]->name() == "Cauty2");
        CHECK(adventurers[1]->name() == "Cauty");
        CHECK(adventurers[0]->health() == 50);
        CHECK(adventurers[1]->health() == 50);
        destroy(adventurers);
        destroy(died);
    }

    SECTION("3 enemy's land and one friend, 2 cautiouses are out")
    {
        create("inp32.txt", adventurers, lands );
        CHECK(mission(false,adventurers, died, lands));
        CHECK(died.size() == 0);
        CHECK(adventurers.size() == 4);
        CHECK(adventurers[0]->health() == 75);
        CHECK(adventurers[1]->health() == 25);
        CHECK(adventurers[2]->health() == 25);
        CHECK(adventurers[3]->health() == 75);
        destroy(adventurers);
        destroy(died);
    }

    SECTION("5 enemy's land and 1 no man's land - everybody dies")
    {
        create("inp33.txt", adventurers, lands );
        CHECK_FALSE(mission(false,adventurers, died, lands));
        CHECK(died.size() == 4);
        CHECK(adventurers.size() == 0);
        destroy(adventurers);
        destroy(died);
        destroyLands();
    }
}


#endif // NORMAL_MODE

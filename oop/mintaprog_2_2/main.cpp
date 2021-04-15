//Author:   Gregorics Tibor
//Date:     2021.04.08.
//Title:    Hunters
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "infile.h"
#include "enor.h"

using namespace std;

//First task
//Activity: present the hunter and his hunting where he shot the most of the bears,
//          in addition the total weight of bears killed by him on that day
bool first(const string &fname, string &hunter, string &date, double &sum)
{
    Infile x(fname);
    Status sx;
    Hunting dx, elem;

    if(!x.read(sx,elem)) return false;

    while(x.read(sx,dx)){
        if(dx.bears_no > elem.bears_no){
            elem = dx;
        }
    }
    hunter = elem.name;
    date = elem.date;
    sum = elem.bears_we;
    return true;
}

//Second task
//Activity:  List the hunters who has shot reindeer, and
//           present the hunter who has shot most of the bears among the hunters who have also shot reindeer
bool second(const string &fname, ostream &y, string &hunter)
{
    Enor t(fname);
    bool l = false;
    int max;
    for(t.first(); !t.end(); t.next()){
        if( t.current().reindeer) {
            y << t.current().name;
            if(l) {
                if(t.current().bears_no > max){
                    max = t.current().bears_no;
                    hunter = t.current().name;
                }
            } else {
                l = true;
                max = t.current().bears_no;
                hunter = t.current().name;
            }
        }
    }
    return l;
}

//#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{

    string filename;
    cout<<"Enter the name of the input file, please:"; cin>>filename;

    //First task
    cout<<"First  task\n";
    try{
        string hunter, date;
        double sum;
        if(first(filename, hunter, date, sum))
            cout << hunter << " has shot the most bears on " << date << ", their total weight: " << sum << endl;
        else cout << "Empty file!\n";
    }catch(Infile::Errors err){
        cerr<<"Can't find the input file\n";
    }

    //Second task
    cout<<"Second task\n";

    try{
        ofstream y("out.txt");
        string hunter;
        if(second(filename, y, hunter)) cout << hunter << " has shot most of the bears among the hunters who have also shot reindeer.\n";
        else cout << "Nobody has shot reindeer.\n";
    }catch(Enor::Errors err){
        cerr<<"Can't find the input file\n";
    }

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//linear search first task

TEST_CASE("first task empty file", "t1.txt") {
    string h;
    string d;
    double s;
    CHECK_FALSE(first("t1.txt", h, d, s));
    CHECK_FALSE(second("t1.txt", cout, h));
}

TEST_CASE("1 hunter, no reindeer, first hunting is the best", "t2.txt") {
    string h;
    string d;
    double s;
    CHECK_FALSE(!first("t2.txt", h, d, s));
    CHECK(h=="KARCSI");
    CHECK(d=="2021.04.07.");
    CHECK(s==780.0);
    CHECK_FALSE(second("t2.txt", cout, h));
}

TEST_CASE("1 hunter, no reindeer, last hunting is the best", "t3.txt") {
    string h;
    string d;
    double s;
    CHECK_FALSE(!first("t3.txt", h, d, s));
    CHECK(h=="KARCSI");
    CHECK(d=="2021.04.09.");
    CHECK(s==630.0);
    CHECK_FALSE(second("t3.txt", cout, h));
}

TEST_CASE("1 hunter, reindeer, medium hunting is the best", "t4.txt") {
    string h;
    string d;
    double s;
    CHECK_FALSE(!first("t4.txt", h, d, s));
    CHECK(h=="KARCSI");
    CHECK(d=="2021.04.08.");
    CHECK(s==630.0);
    CHECK_FALSE(!second("t4.txt", cout, h));
    CHECK(h=="KARCSI");
}

TEST_CASE("more hunters, one reindeer, medium hunting is the best", "t5.txt") {
    string h;
    string d;
    double s;
    CHECK_FALSE(!first("t5.txt", h, d, s));
    CHECK(h=="KARCSI");
    CHECK(d=="2021.04.08.");
    CHECK(s==630.0);
    CHECK_FALSE(second("t5.txt", cout, h));
}

TEST_CASE("more hunters, 1 reindeer, medium hunting is the best", "t6.txt") {
    string h;
    string d;
    double s;
    CHECK_FALSE(!first("t6.txt", h, d, s));
    CHECK(h=="KARCSI");
    CHECK(d=="2021.04.08.");
    CHECK(s==630.0);
    CHECK_FALSE(!second("t6.txt", cout, h));
    CHECK(h=="ZSOLTI");
}

TEST_CASE("more hunters, all reindeer, medium hunting is the best", "t7.txt") {
    string h;
    string d;
    double s;
    CHECK_FALSE(!first("t7.txt", h, d, s));
    CHECK(h=="KARCSI");
    CHECK(d=="2021.04.07.");
    CHECK(s==200.0);
    CHECK_FALSE(!second("t7.txt", cout, h));
    CHECK(h=="KARCSI");
}
#endif

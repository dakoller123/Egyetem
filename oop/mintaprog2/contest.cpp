//Author:   Gregorics Tibor
//Date:     2018.09.23.
//Title:    Anglers

#include "contest.h"

using namespace std;

//Task: 	C:\!DATA\Programozás_UJ\2019\HF2\Atdolgozott\hf2minta\t6.txtConstructor
//Input:    string str  - the test file's name
//Activity: tries to open the given file, if its falis, throws a "FileError" exception
ContestEnor::ContestEnor(const std::string &str) throw (FileError)
{
    _f.open(str);
    if(_f.fail())throw MissingInputFile;
}

//Task: 	Reading the next row of the inputfile
//Input:    ifstream _f  - the test file
//Output:   Contest _cur - the next contest
//          bool _end    - the end of the enumeration
//Activity:
void ContestEnor::next()
{
    string line;
    getline(_f , line);
    if( !(_end = _f.fail()) ){
        istringstream is(line);
        is >> _cur.angler >> _cur.contest;
        _cur.counter = 0;
        string fish;
        int size;
        for( is >> fish >> size ; !is.fail(); is >> fish >> size ){
            if(fish == "catfish") ++_cur.counter;
        }
    }
}

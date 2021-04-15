#include "infile.h"
#include <sstream>

using namespace std;

Infile::Infile(const std::string &fname)
{
    f.open(fname);
    if(f.fail()) throw FILEERROR;
}

bool Infile::read(Status &sx, Hunting &dx)
{
    string line;
    getline(f, line);
    sx = f.fail() ? abnorm : norm;
    if (norm==sx) {
        istringstream in(line);
        in >> dx.name >> dx.date;
        dx.bears_no = 0;
        dx.bears_we = 0.0;
        string species;
        double weight;
        while( in>>species>>weight ){
            if("medve"==species) {
                ++dx.bears_no;
                dx.bears_we += weight;
            }
        }
    }

    return norm==sx;
}

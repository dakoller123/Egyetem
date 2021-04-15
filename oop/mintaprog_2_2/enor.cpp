#include "enor.h"
#include <sstream>

using namespace std;

Enor::Enor(const std::string &fname)
{
    f.open(fname);
    if(f.fail()) throw FILEERROR;
}

void Enor::next()
{
    _end = abnorm==sx;
    if (!_end) {
        _cur.name = dx.name;
        _cur.reindeer = false;
        _cur.bears_no = 0;
        while(norm==sx && dx.name==_cur.name ){
            _cur.bears_no += dx.bears_no;
            _cur.reindeer = _cur.reindeer || dx.reindeer;
            read();
        }
    }
}

bool Enor::read()
{
    string line;
    getline(f, line);
    sx = f.fail() ? abnorm : norm;
    if (norm==sx) {
        istringstream in(line);
        in >> dx.name >> dx.date;
        dx.bears_no = 0;
        dx.bears_we = 0.0;
        dx.reindeer = false;
        string species;
        double weight;
        while( in>>species>>weight ){
            dx.reindeer = dx.reindeer || "reindeer"==species;
            if("medve"==species) {
                ++dx.bears_no;
            }
        }
    }
    return norm==sx;
}

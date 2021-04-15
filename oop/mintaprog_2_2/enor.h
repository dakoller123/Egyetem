#ifndef ENOR_H
#define ENOR_H

#include <string>
#include <fstream>
#include "type.h"

class Enor
{
    public:
        enum Errors { FILEERROR };

        Enor(const std::string &fname);

        void first() { read(); next(); }
        void next();
        Hunter current() const { return _cur; }
        bool end() const { return _end; }

    private:
        std::ifstream f;
        Hunting dx;
        Status sx;
        Hunter _cur;
        bool _end;

        bool read();
};

#endif // ENOR_H

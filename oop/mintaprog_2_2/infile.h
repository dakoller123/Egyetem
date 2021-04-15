#ifndef INFILE_H
#define INFILE_H

#include <fstream>
#include "type.h"

class Infile
{
    public:
        enum Errors { FILEERROR };

        Infile(const std::string &fname);
        bool read(Status &sx, Hunting &dx);
    private:
        std::ifstream f;
};

#endif // INFILE_H

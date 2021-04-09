#pragma once
#include <fstream>
#include <string>

#include "adoptionEnor.h"

struct adoptionDay
{
    std::string date;
    AdoptionEnor* adoptions;
};


class AdoptionDayEnor
{
    private:
        std::ifstream _f;
        struct adoptionDay _current;
        Status _status;

    public:
        enum FileError { MissingInputFile };
        AdoptionDayEnor(const std::string &str) throw (FileError);
        void first();
        void next();
        struct adoptionDay current() const;
        bool end() const;
};

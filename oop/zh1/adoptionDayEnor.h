#pragma once

#include <fstream>
#include <string>


struct AdoptionDay
{
    std::string date;
    AdoptionEnor* adoptionEnor
};


enum Status
{
    Abnormal, Normal
};

class AdoptionEnor
{
    private:
        std::ifstream _f;
        struct record _current;
        Status _status;

    public:
        enum FileError { MissingInputFile };
        AdoptionEnor(const std::string &str) throw (FileError);
        void first();
        void next();
        struct record current() const;
        bool end() const;
};

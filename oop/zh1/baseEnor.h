#pragma once

#include <fstream>
#include <string>

struct record
{
    int randomAttribute;
};

enum Status
{
    Abnormal, Normal
};

class BaseEnor
{
    private:
        std::ifstream _f;
        struct record _current;
        Status _status;

    public:
        enum FileError { MissingInputFile };
        BaseEnor(const std::string &str) throw (FileError);
        void first();
        void next();
        struct record current() const;
        bool end() const;
};

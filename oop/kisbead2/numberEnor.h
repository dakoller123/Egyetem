#pragma once

#include <fstream>
#include <string>

enum Status
{
    Abnormal, Normal
};

class NumberEnor
{
    private:
        std::ifstream _f;
        int _current;
        Status _status;

    public:
        enum FileError { MissingInputFile };
        NumberEnor(const std::string &str) throw (FileError);

        void first();
        void next();
        int current() const;
        bool end() const;
};

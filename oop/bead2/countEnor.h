#pragma once

#include <fstream>
#include <string>
#include "numberEnor.h"

struct ValueCountPair
{
    int Value;
    int Count;
};

class CountEnor
{
    private:
        NumberEnor _numberEnor;
        ValueCountPair _current;

    public:
        CountEnor(const std::string &str): _numberEnor(str){};

        void first();
        void next();
        ValueCountPair current() const;
        bool end() const;
};

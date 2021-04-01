#pragma once

#include <fstream>
#include <string>
#include "numberEnor.h"

class CountEnor
{
    private:
        NumberEnor _numberEnor;
        int _currentCount;
        int _currentValue;

    public:
        CountEnor(const std::string &str): _numberEnor(str){};

        void first();
        void next();
        int current() const;
        bool end() const;
};

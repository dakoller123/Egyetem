#pragma once
#include "baseEnor.h"
#include <fstream>
#include <string>

class SecondEnor
{
    private:
        BaseEnor _baseEnor;
        int _current;
        Status _status;

    public:
        SecondEnor(const std::string &str) : _baseEnor(str) {}
        void first();
        void next();
        int current() const;
        bool end() const;
};

#include "entry.h"
#pragma once
class File: public Entry
{
    private:
        int _size();
    public:
        int getSize() override
        {
            return _size();
        }
};

#pragma once

#include <fstream>
#include <string>

struct entry
{
    std::string date;
    unsigned float weight;
};

struct record
{
    std::string name;
    std::string classId;
};

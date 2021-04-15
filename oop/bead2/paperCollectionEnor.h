#pragma once

#include <fstream>
#include <string>

struct paperCollection
{
    std::string date;
    float weight;
};

enum Status
{
    Abnormal, Normal
};

class PaperCollectionEnor
{
    private:
        std::ifstream _f;
        struct student _current;
        Status _status;

    public:
        PaperCollectionEnor(const std::string &str) throw (FileError);
        void first();
        void next();
        struct student current() const;
        bool end() const;
};

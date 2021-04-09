#pragma once

#include <fstream>
#include <string>

struct student
{
    std::string name;
    std::string classId;
    float sumWeight;
};

enum Status
{
    Abnormal, Normal
};

class StudentEnor
{
    private:
        std::ifstream _f;
        struct student _current;
        Status _status;

    public:
        enum FileError { MissingInputFile };
        StudentEnor(const std::string &str) throw (FileError);
        void first();
        void next();
        struct student current() const;
        bool end() const;
};

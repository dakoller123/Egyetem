#pragma once
#include <fstream>
#include <string>
#include "studentEnor.h"

struct classResult
{
    std::string classId;
    float sumWeight;
};

class ClassEnor
{
    private:
        StudentEnor& _studentEnor;
        struct classResult _current;
        Status _status;

    public:
        ClassEnor(StudentEnor& studentEnor) : _studentEnor(studentEnor) {}
        void first();
        void next();
        struct classResult current() const;
        bool end() const;
};

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
        bool _isEmpty;

    public:
        ClassEnor(StudentEnor& studentEnor) : _studentEnor(studentEnor), _isEmpty(true) {}
        void first();
        void next();
        struct classResult current() const;
        bool end() const;
        bool isEmpty() const;
};

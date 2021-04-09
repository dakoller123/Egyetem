#pragma once

#include <fstream>
#include <string>

enum Status
{
    Abnormal, Normal
};

struct adoption
{
    std::string firstName;
    std::string lastName;
    std::string dogType;
    std::string dogName;
    unsigned int dogAge;
};

class AdoptionEnor
{
    private:
        std::stringstream* _stream;
        struct adoption _current;
        Status _status;

    public:
        //AdoptionEnor(std::stringstream& stream) : _stream(stream) {};
        AdoptionEnor(std::stringstream* stream) {_stream = stream;};
        void first();
        void next();
        struct adoption current() const;
        bool end() const;
};

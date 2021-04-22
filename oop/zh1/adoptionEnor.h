#pragma once

#include <fstream>
#include <string>
#include <sstream>

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
        std::stringstream _stream;
        struct adoption _current;
        Status _status;

    public:
        //AdoptionEnor(std::stringstream& stream) : _stream(stream) {};
        //AdoptionEnor(const std::string &str) : _stream(std::stringstream(str)) {};
        AdoptionEnor(const std::string str)
        {
            _stream = std::stringstream(str);
        };
        void first();
        void next();
        struct adoption current() const;
        bool end() const;
};

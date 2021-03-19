#pragma once

#include <fstream>
#include <string>

enum Status
{
    Abnormal, Normal
};

class TemperatureEnor
{
    private:
        std::ifstream _f;
        float _current;
        Status _status;

    public:
        enum FileError { MissingInputFile };
        TemperatureEnor(const std::string &str) throw (FileError);

        void first();
        void next();
        float current() const;
        bool end() const;
};

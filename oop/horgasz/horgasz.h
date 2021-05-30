#pragma once
#include <vector>
#include "fogas.h"
#include "verseny.h"
class Verseny;

class Horgasz{
private:
    std::string _name;
    std::vector<Fogas*> _eredmenyek;
public:
    Horgasz(const std::string& name) : _name(name), _eredmenyek(){}
    void resztvesz(Verseny* v);
    int getHarcsaCount(const Verseny* v) const;
    ~Horgasz();
};


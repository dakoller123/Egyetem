#pragma once
#include <vector>
#include "fogas.h"
#include <string>
#include "horgasz.h"

class Horgasz;
class Verseny{
private:
    std::string _id;
    std::string _loc;
    std::vector<Fogas*> _versenyFogas;
    std::vector<Horgasz*> _resztvevok;
    Fogas* generateFogas();
public:
    std::vector<Fogas*> versenyeztet(Horgasz* h);
    bool isMindenkiFogottHarcsat() const;
    int calculateEredmeny() const;
    ~Verseny();
    std::string getId() const
    {
        //todo: copy
        return _id;
    }
};

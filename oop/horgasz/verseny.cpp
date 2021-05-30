#include <vector>
#include "verseny.h"
#include "horgasz.h"

Fogas* Verseny::generateFogas()
{
    int weight = rand() % 100 + 1;
    int type = rand() % 3 + 1;
    switch(type) {
      case 1:
        _versenyFogas.push_back(new Harcsa(weight, _id));
        return (new Harcsa(weight, _id));
      case 2:
        _versenyFogas.push_back(new Keszeg(weight, _id));
        return (new Keszeg(weight, _id));
      case 3:
        _versenyFogas.push_back(new Ponty(weight, _id));
        return (new Ponty(weight, _id));
      default:
        //TODO: error handling
        _versenyFogas.push_back(new Ponty(weight, _id));
        return (new Ponty(weight, _id));
    }
}

std::vector<Fogas*> Verseny::versenyeztet(Horgasz* h)
{
    int fishCount = rand()%10;
    std::vector<Fogas*> result(fishCount);
    for (int i = 0; i<fishCount; i++)
    {
        Fogas* ujfogas = generateFogas();
        result.push_back(ujfogas);
    }
    _resztvevok.push_back(h);
    return result;
}

bool Verseny::isMindenkiFogottHarcsat() const
{
    bool result = true;
    for (Horgasz* resztvevo : _resztvevok)
    {
        result = result && (resztvevo->getHarcsaCount(this) > 0);
    }
    return result;
}

int Verseny::calculateEredmeny() const
{
    int sum = 0;
    for (Fogas* fogas : _versenyFogas)
    {
        sum += fogas->getValue();
    }
    return sum;
}

Verseny::~Verseny()
{
    for (Fogas* fogas : _versenyFogas)
    {
        delete fogas;
    }
}


#include <vector>
#include "horgasz.h"

void Horgasz::resztvesz(Verseny* v)
{
    std::vector<Fogas*> eredmeny = v->versenyeztet(this);
    _eredmenyek.insert( _eredmenyek.end(), eredmeny.begin(), eredmeny.end() );
}

int Horgasz::getHarcsaCount(const Verseny* v) const
{
    int sum = 0;
    for (Fogas* fogas : _eredmenyek)
    {
        if (fogas->getVersenyId() == v->getId())
        {
            sum += fogas->getValue();
        }
    }
    return sum;
}

Horgasz::~Horgasz()
{
    for (Fogas* fogas : _eredmenyek)
    {
       delete fogas;
    }
}

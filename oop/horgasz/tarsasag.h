#pragma once
#include <vector>
#include "verseny.h"

class Verseny;

struct MaybeVerseny{
    bool exists;
    Verseny* verseny;
};

class HorgaszTarsasag{
private:
    std::vector<Verseny*> _versenyek;
    std::vector<Horgasz*> _horgaszok;
public:
    struct MaybeVerseny legEredmenyesebbHarcsaContest();
    HorgaszTarsasag();
};

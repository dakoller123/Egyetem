#include <vector>
#include "verseny.h"
#include "tarsasag.h"

struct MaybeVerseny HorgaszTarsasag::legEredmenyesebbHarcsaContest()
{
    bool found = false;
    Verseny* maxV = 0;
    for (Verseny* verseny: _versenyek)
    {
        if (verseny->isMindenkiFogottHarcsat())
        {
            if (found)
            {
                if (maxV->calculateEredmeny() < verseny->calculateEredmeny())
                {
                    maxV = verseny;
                }
            }
            else
            {
                found = true;
                maxV = verseny;
            }
        }
    }

    struct MaybeVerseny result;
    result.exists = found;
    result.verseny = maxV;
    return result;
}

HorgaszTarsasag::HorgaszTarsasag()
{
    //Todo: ctor with rand
}

//Author:    Koller Dávid Dániel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#include "indextransformer.h"

Coord IndexTransformer::getNextCoord(int width, Coord source)
{
    Coord next;
    if (source.j == width-1)
    {
        next.i = source.i + 1;
        next.j = 0;
    }
    else
    {
        next.i = source.i;
        next.j = source.j + 1;
    }

    return next;
}
bool IndexTransformer::isNullElement(int i, int j)
{
    if ((i+j) % 2 == 0)
    {
        return false;
    }

    return true;
}

int IndexTransformer::matrixToVector(int height, int width, int i, int j)




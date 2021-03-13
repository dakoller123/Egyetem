//Author:    Koller Dávid Dániel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#pragma once
#include <iostream>
#include <vector>
struct Coord
{
    int i;
    int j;

};
class IndexTransformer
{
    public:

        static bool isNullElement(int i, int j)
        {
            if ((i+j) % 2 == 0)
            {
                return false;
            }

            return true;
        }

        static int matrixToVector(int width, int height, int i, int j)
        {
           return ((i * height) + j) / 2 ;
        }

        static Coord vectorToMatrix(int width, int height, int vi)
        {
            Coord c;
            c.i = (2 * vi) / height;
            c.j = (2* vi ) % height;

            return c;
        }





};


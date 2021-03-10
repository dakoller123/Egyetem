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

        static int matrixToVector(int m, int n, int i, int j)
        {
           return ((i * n) + j) / 2 ;
        }

        static Coord vectorToMatrix(int m, int n, int vi)
        {
            //vi = ((i * n) + j) / 2 ;
            //2vi = ((i * n) + j)
            Coord c;
            c.i = (2 * vi) / n;
            c.j = (2* vi ) % n;

//            if (isNullElement(c.i, c.j))
//            {
//                c.j = c.j + 1;
//            }

            return c;
        }





};


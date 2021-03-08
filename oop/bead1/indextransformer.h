//Author:    Koller Dávid Dániel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#pragma once
#include <iostream>
#include <vector>

class IndexTransformer
{
    public:

        static bool isNullElement(int i, int j)
        {
            if (i % 2 == 0)
            {
                if (j %2 == 0)
                {
                    return true;
                }
                return false;
            }

            if (j % 2 == 0)
            {
                return false;
            }
            return true;
        }

        static int matrixToVector(int m, int n, int i, int j)
        {
           return ((i * n) + j) / 2 ;
        }

        static void vectorToMatrix(int m, int n, int vi, int& i, int& j)
        {
            i = (2 * vi) / n;
            j = (2* vi ) % n;

            if (isNullElement(i, j))
            {
                j = j + 1;
            }
        }



};


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
        static std::string InvalidArgumentException(){return "InvalidArgumentException";}
        static Coord getNextCoord(int width, Coord source)
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

        static bool isNullElement(int i, int j)
        {
            if ((i+j) % 2 == 0)
            {
                return false;
            }

            return true;
        }
        static int matrixToVector(int height, int width, int i, int j)
        {
            if (j >= width)
            {
                throw InvalidArgumentException();
            }

            if (i >= height)
            {
                throw InvalidArgumentException();
            }


            if (i == 0 && j == 0)
            {
                return 0;
            }

            int result = 0;
            Coord current;
            current.i=0;
            current.j=0;
            do
            {
                current = getNextCoord(width, current);
                if (!isNullElement(current.i, current.j))
                {
                    result++;
                }

            } while (!(current.i == i && current.j == j));

            return result;
        }
};


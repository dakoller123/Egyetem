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
                std::cout <<  std::endl;
            std::cout << "START" << std::endl;
            std::cout << "width: " << width <<" height: " << height << " i: " << i << "j: " << j << std::endl;
                throw 123131;
            }

            if (i >= height)
            {
                std::cout <<  std::endl;
            std::cout << "START" << std::endl;
            std::cout << "width: " << width <<" height: " << height << " i: " << i << "j: " << j << std::endl;
                throw 99999;
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
                //std::cout << "currenti: " << current.i << " currentj: " << current.j << std::endl;
                current = getNextCoord(width, current);
                if (!isNullElement(current.i, current.j))
                {
                    result++;
                    //std::cout << "result : " << result;
                }

            } while (!(current.i == i && current.j == j));

            //std::cout << "resultat end : " << result;
            return result;
            //std::cout << std::endl;
        }

        static Coord vectorToMatrix(int height, int width, int vi)
        {
            Coord result;
            result.i = 0;
            result.j = 0;

            if (vi == 0)
            {
                return result;
            }

            int currentvi = 0;
            do
            {
                result = getNextCoord(width, result);
                if (!(isNullElement(result.i, result.j)))
                {
                    currentvi++;
                }

            } while (currentvi != vi);

            return result;
        }





};


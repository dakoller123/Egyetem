//Author:    Koller Dávid Dániel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#include <iostream>
#include "checkerboardmatrix.h"
#include "read.hpp"
#include "menu.h"

bool check(int n) { return 0<=n && n<=6; }
bool leftOrRight(std::string s) {return (s == "left" || s == "right");};
void Menu::run()
{
    int n = 0;
    do {
        menuWrite();

        n = read <int> ( "\n>>>>", "integer between 0 and 6 is needed\n", check );
        switch(n)
        {
            case 1:
                resizeMatrix();
                break;
            case 2:
                getElement();
                break;
            case 3:
                setElement();
                break;
            case 4:
                writeMatrix();
                break;
            case 5:
                sum();
                break;
            case 6:
                mul();
                break;
        }
    } while(n!=0);
}

void Menu::menuWrite()
{
    std::cout << std::endl << std::endl;
    std::cout << " 0. - Quit" << std::endl;
    std::cout << " 1. - Reset Matrix && set width and height" << std::endl;
    std::cout << " 2. - Get an element of the matrix" << std::endl;
    std::cout << " 3. - Overwrite an element of the matrix" << std::endl;
    std::cout << " 4. - Write matrices" << std::endl;
    std::cout << " 5. - Add matrices" << std::endl;
    std::cout << " 6. - Multiply matrices" << std::endl;

}

void Menu::getElement() const
{
    std::string side = read <std::string> ( "Which matrix should be used? left or right\n", "\n>>>>", leftOrRight);
    int i,j;
    std::cout << "Give the index of the row: ";
    std::cin >> i;
    std::cout << "Give the index of the column: ";
    std::cin >> j;
    try
    {
        if (side == "left")
        {
            std::cout << "a[" << i << "," << j << "]= " << a.getElement(i-1, j-1) << std::endl;
        }
        else
        {
            std::cout << "b[" << i << "," << j << "]= " << b.getElement(i-1, j-1) << std::endl;
        }

    }
    catch(std::string ex)
    {
        if(ex == CheckerboardMatrix::OverIndexedException())
            std::cout << "Overindexing!" << std::endl;
        else
            std::cout << "Unhandled ecxeption!" << std::endl;
    }
}

void Menu::resizeMatrix()
{
    std::string side = read <std::string> ( "Which matrix should be used? left or right\n", "\n>>>>", leftOrRight);
    int height, width;
    std::cout << "Give the new height";
    std::cin >> height;
    std::cout << "Give the new width";
    std::cin >> width;

    try
    {
        if (side == "left")
        {
            a = CheckerboardMatrix(height, width);
        }
        else
        {
            b = CheckerboardMatrix(height, width);
        }
    }
    catch(std::string  ex)
    {
        if(ex == CheckerboardMatrix::InvalidMatrixDimensionException())
            std::cout << "Invalid Matrix dimension" << std::endl;
    }
}

void Menu::setElement()
{
    std::string side = read <std::string> ( "Which matrix should be used? left or right\n", "\n>>>>", leftOrRight);

    int i,j,e;
    std::cout << "Give the index of the row: ";
    std::cin >> i;
    std::cout << "Give the index of the column: ";
    std::cin >> j;
    std::cout << "Give the value: ";
    std::cin >> e;

    try
    {
        if (side == "left")
        {
            a.setElement(i-1, j-1, e);
        }
        else
        {
            b.setElement(i-1, j-1, e);
        }
    }
    catch(std::string  ex)
    {
        if(ex == CheckerboardMatrix::OverIndexedException())
            std::cout << "Overindexing!" << std::endl;
        if (ex == CheckerboardMatrix::NullElementException())
            std::cout << "These indexes do not point to the diagonal!" << std::endl;
    }
}

void Menu::writeMatrix()
{
    std::cout << "Matrix A:" << std::endl << a << std::endl;
    std::cout << "Matrix B:" << std::endl << b << std::endl;
}

void Menu::sum()
{
    try
    {
        CheckerboardMatrix c = a + b;

        std::cout << "Sum of the matrices: " << std::endl;
        std::cout << c << std::endl;
    }
    catch(std::string  ex)
    {
        if(ex == CheckerboardMatrix::IncompatibleMatrixException())
            std::cout << "Different sizes!" << std::endl;
    }
}

void Menu::mul()
{
    try
    {
        CheckerboardMatrix c = a * b;
        std::cout << "Multiplication of the matrices: " << std::endl;
        std::cout << c << std::endl;
    }
    catch(std::string ex)
    {
        if(ex == CheckerboardMatrix::IncompatibleMatrixException())
            std::cout << "Invalid matrix sizes!" << std::endl;
    }
}

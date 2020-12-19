// A vectors_predicate_view osztály
// template, megkap egy T típusparamétert és egy predikátumot template
// paraméterként, két T-ket tároló std::vector-t pedig konstruktor
// paraméterként. Az a feladat, hogy amíg a nézet rajta van a két vector-on,
// addig a vektorok elemei legyenek a predikátum szerint szétválogatva. Ahol
// igaz a predikátum, az a konstruktor első vektorába, a többi a másodikba
// kerül, megőrizve az eredeti sorrendet. Ha a nézet lekerül, visszaállnak az
// eredeti állapotukba. Van két művelete az osztálynak: size() visszaadja,
// hogy összesen hány elem van a nézetben, a negate() pedig negálja a
// predikátumot. Ha nincs megadva a predikátum template paraméter, akkor
// "semmit kell csinálni", nem kell szétválogatni az elemeket, mert nincs mi
// szerint.

#include <iostream>
#include "vecspred.h"
#include <algorithm>
#include <string>
#include <numeric>
#include <functional>
#include <vector>

struct is_even: std::unary_function<int, bool>
{
  bool operator()( int i ) const
  {
    return 0 == i % 2;
  }
};

struct is_good_language: std::unary_function<std::string, bool>
{
  bool operator()( const std::string& s ) const
  {
    return s == "C++" || s == "C";
  }
};
void print (int i) 
{  
    std::cout << ' ' << i;
}

void check()
{
    std::vector<int> a{ 10, 20, 21, 49, 30 };
    std::vector<int> b{ 5, 6, 9, 0, 1 };
  
    std::cout << "A start :";
    for_each (a.begin(), a.end(), print);
    std::cout << std::endl;
  
    std::cout << "B start :";
    for_each (b.begin(), b.end(), print);
    std::cout << std::endl;
  
    if (true)
    {
        const vectors_predicate_view<int, is_even> va( a, b );
        
        std::cout << "A middle :";
        for_each (a.begin(), a.end(), print);
        std::cout << std::endl;
        
        std::cout << "B middle :";
        for_each (b.begin(), b.end(), print);
        std::cout << std::endl;
    }

    std::cout << "A after :";
    for_each (a.begin(), a.end(), print);
    std::cout << std::endl;
    
    std::cout << "B after :";
    for_each (b.begin(), b.end(), print);
    std::cout << std::endl;
  
}

int main()
{
  check();
}
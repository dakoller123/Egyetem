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



bool check()
{
  std::vector<int> a{ 10, 20, 30 };;

  const vectors_predicate_view va( a);
  
  return true;
}

int main()
{
  check();
}
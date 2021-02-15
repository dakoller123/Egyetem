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
#include "vecspred.h"

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

const int max = 1024;

bool check()
{
  bool c = false;
  std::vector<int> a;
  std::vector<int> b;

  for( int i = 0; i < max; ++i )
  {
    if ( i < max / 2 )
    {
      a.push_back( i );
    }
    else
    {
      b.push_back( i );
    }
  }

  std::vector<std::string> x;
  x.push_back( "Cobol" );
  x.push_back( "Ada" );

  std::vector<std::string> y;
  y.push_back( "Javascript" );
  y.push_back( "C++" );
  y.push_back( "ABAP" );

  if ( !c )
  {
    vectors_predicate_view<int, is_even> va( a, b );
    vectors_predicate_view<std::string, is_good_language> vb( x, y );

    c = ( 1 == x.size() && 1 == b[ 0 ] && 2 == a[ 1 ] && "Cobol" == y[ 0 ] );
  }
  if ( !c || "Ada" != x[ 1 ] || "ABAP" != y[ 2 ] || max / 2 != b[ 0 ] )
  {
    return false;
  }

  if ( c )
  {
    const vectors_predicate_view<int, is_even> va( a, b );
    vectors_predicate_view<std::string, is_good_language> vb( x, y );

    vb.negate();

    if ( va.size() != max || 4 != x.size() )
    {
      return false;
    }
  }

  if ( c )
  {
    vectors_predicate_view<int> va( a, b );
    vectors_predicate_view<std::string> vb( x, y );

    return ( 2 == x.size() && "C++" == y[ 1 ] && 5 == vb.size() &&
         max / 2 == b[ 0 ] && max == va.size() );
  }
  return false;
}

int main()
{
  std::cout
    << "Your solution is " << (check() ? "" : "not ")
    << "ready for submission.\n";
}
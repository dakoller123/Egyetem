#include "bag.cpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("empty sequence", "")
{
    Bag b = Bag();
	int testValueThatsNotAddedYet = 1;
	REQUIRE(b.GetCount(testValueThatsNotAddedYet) == 0);
	REQUIRE(b.IsEmpty() == true);
	REQUIRE(b.ToString() == "");
}

TEST_CASE("single element sequence", "getCount, isEmpty")
{
    Bag b = Bag();
	int testValueToBeAdded = 2132;
	REQUIRE(b.GetCount(testValueToBeAdded) == 0);
    b.Add(testValueToBeAdded);
	REQUIRE(b.GetCount(testValueToBeAdded) == 1);
	REQUIRE(b.IsEmpty() == false);
	//REQUIRE(b.ToString() == "");
}

TEST_CASE("single element sequence multiple items in it", "getCount")
{
    Bag b = Bag();
	int testValueToBeAdded = 2132;
	REQUIRE(b.GetCount(testValueToBeAdded) == 0);
	int timesToBeAdded = 91;	
	for (int i=0; i<timesToBeAdded; i++)
	{
		b.Add(testValueToBeAdded);		
	}

	REQUIRE(b.GetCount(testValueToBeAdded) == timesToBeAdded);
}

TEST_CASE("", "getCount")
{
    Bag b = Bag();
	int testValueToBeAdded = 2132;
	REQUIRE(b.GetCount(testValueToBeAdded) == 0);
	int timesToBeAdded = 91;	
	for (int i=0; i<timesToBeAdded; i++)
	{
		b.Add(testValueToBeAdded);		
	}

	REQUIRE(b.GetCount(testValueToBeAdded) == timesToBeAdded);
}
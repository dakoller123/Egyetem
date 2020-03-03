#include "integerBag.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("empty sequence", "[GetCount, IsEmpty, ToString]")
{
    IntegerBag b = IntegerBag();
	int testValueThatsNotAddedYet = 1;
	REQUIRE(b.GetCount(testValueThatsNotAddedYet) == 0);
	REQUIRE(b.IsEmpty() == true);
	REQUIRE(b.ToString() == "{ }");
}

TEST_CASE("single element sequence", "[GetCount, IsEmpty]")
{
    IntegerBag b = IntegerBag();
	int testValueToBeAdded = 2132;
	REQUIRE(b.GetCount(testValueToBeAdded) == 0);
    b.Add(testValueToBeAdded);
	REQUIRE(b.GetCount(testValueToBeAdded) == 1);
	REQUIRE(b.IsEmpty() == false);
}

TEST_CASE("single element sequence multiple items in it", "[GetCount, IsEmpty]")
{
    IntegerBag b = IntegerBag();
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
    IntegerBag b = IntegerBag();
	int testValueToBeAdded = 2132;
	REQUIRE(b.GetCount(testValueToBeAdded) == 0);
	int timesToBeAdded = 91;	
	for (int i=0; i<timesToBeAdded; i++)
	{
		b.Add(testValueToBeAdded);		
	}

	REQUIRE(b.GetCount(testValueToBeAdded) == timesToBeAdded);
}

SCENARIO("elements can be added to IntegerBags and removed", "[IntegerBag]")
{
	GIVEN("An empty IntegerBag")
	{
		IntegerBag b = IntegerBag();
		
		REQUIRE(b.IsEmpty());
		REQUIRE(b.GetCount(0) == 0);
		REQUIRE(b.GetCount(1) == 0);
		REQUIRE(b.ToString() == "{ }");
		
		WHEN("we add a new element")
		{
			int x = 5;
			int y = 10;
			b.Add(x);
			
			THEN("the IntegerBag ain't empty no more");
			{
				REQUIRE(b.IsEmpty() == false);
				REQUIRE(b.GetCount(x) == 1);
				REQUIRE(b.BiggestNumber() == x);
				REQUIRE(b.ToString() == "{ (5,1) }");
			}
			
			WHEN("we add some more");
			{
				b.Add(x);
				b.Add(y);
				b.Add(y);
				b.Add(y);
				
				THEN("the IntegerBag's biggest stored number changes")
				{
					REQUIRE(b.IsEmpty() == false);
					REQUIRE(b.ToString() == "{ (5,2) (10,3) }");
					REQUIRE(b.BiggestNumber() == y);
					REQUIRE(b.GetCount(x) == 2);	
					REQUIRE(b.GetCount(y) == 3);
					
					WHEN("we remove a number")
					{
						b.Remove(x);
						
						THEN("only that number's count changes")
						{
							REQUIRE(b.IsEmpty() == false);	
							REQUIRE(b.GetCount(x) == 1);	
							REQUIRE(b.GetCount(y) == 3);
							REQUIRE(b.BiggestNumber() == y);
							
							WHEN("we remove a single piece of the biggest number from the IntegerBag")
							{
								b.Remove(y);
								
								THEN("its count changes but it's still the biggest number in the IntegerBag")
								{
									REQUIRE(b.GetCount(x) == 1);	
									REQUIRE(b.GetCount(y) == 2);
									REQUIRE(b.BiggestNumber() == y);
								}
								
								WHEN ("we remove every piece of the biggest number from the IntegerBag")
								{
									b.Remove(y);
									b.Remove(y);
									
									THEN("it ain't the biggest number no more")
									{
										REQUIRE(b.GetCount(x) == 1);	
										REQUIRE(b.GetCount(y) == 0);
										REQUIRE(b.BiggestNumber() == x);	
									}	
								}															
							}
						}
					}						
				}		
			}
		}
	}
}
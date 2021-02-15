#include <string>
#include "ordermanager.h"
#include <stdexcept>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("empty sequence", "[MostProfitableFood]")
{
    OrderManager mgr = OrderManager();
	REQUIRE_THROWS_AS(mgr.MostProfitableFood(), std::domain_error);
}

SCENARIO("elements can be added to IntegerBags and removed", "[IntegerBag]")
{
	GIVEN("An empty OrderManager")
	{
		OrderManager mgr = OrderManager();
		REQUIRE_THROWS_AS(mgr.MostProfitableFood(), std::domain_error);
		WHEN("we add an order")
		{			
			int firstFoodPrice = 10;
			std::string firstFoodName = "foodOne";
			mgr.AddOrder(Order(firstFoodName, 1, firstFoodPrice));
			
			THEN("thats the most profitable food");
			{
				REQUIRE(mgr.MostProfitableFood() == firstFoodName);
			}
			
			WHEN("we add the same food again")
			{
				mgr.AddOrder(Order(firstFoodName, 4, firstFoodPrice));					
				
				THEN("thats still most profitable food");
				{
					REQUIRE(mgr.MostProfitableFood() == firstFoodName);
				}
				
				WHEN("we add a new food's order")
				{
					int secondFoodPrice = 40;
					std::string secondFoodName = "foodTwo";

					mgr.AddOrder(Order(secondFoodName, 1, secondFoodPrice));
					
					THEN("the first is still most profitable food");
					{
						REQUIRE(mgr.MostProfitableFood() == firstFoodName);
					}

					WHEN("but then we add the second one again")
					{
						mgr.AddOrder(Order(secondFoodName, 1, secondFoodPrice));
						
						THEN("now the second is the MVP");
						{
							REQUIRE(mgr.MostProfitableFood() == secondFoodName);
						}	

						WHEN("we add the second one again")
						{
							mgr.AddOrder(Order(secondFoodName, 1, secondFoodPrice));
							
							THEN("the second is the MVP");
							{
								REQUIRE(mgr.MostProfitableFood() == secondFoodName);
							}	

							WHEN("we add the first one again with a BIG order")
							{
								mgr.AddOrder(Order(firstFoodName, 100, firstFoodPrice));
								
								THEN("the first is the MVP");
								{
									REQUIRE(mgr.MostProfitableFood() == firstFoodName);
								}								
							}	
						}	
					}
				}
			}
		}	
	}
}
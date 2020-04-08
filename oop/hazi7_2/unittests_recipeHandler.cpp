#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "recipeHandler.h"

RecipeHandler recipeHandler = RecipeHandler();

TEST_CASE("happy path", "[EveryRecipeContainsSugar]")
{
    REQUIRE(recipeHandler.EveryRecipeContainsSugar("test1.txt", "cukor"));
}

TEST_CASE("one does not", "[EveryRecipeContainsSugar]")
{
    REQUIRE(!recipeHandler.EveryRecipeContainsSugar("test2.txt", "cukor"));
}

TEST_CASE("one line, sugar", "[EveryRecipeContainsSugar]")
{
    REQUIRE(recipeHandler.EveryRecipeContainsSugar("test3.txt", "cukor"));
}

TEST_CASE("one line, not sugar", "[EveryRecipeContainsSugar]")
{
    REQUIRE(!recipeHandler.EveryRecipeContainsSugar("test4.txt", "cukor"));
}
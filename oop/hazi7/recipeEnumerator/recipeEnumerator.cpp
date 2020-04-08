#import "recipeEnumerator.h"

void RecipeEnumerator::First()
{
    _current = new Recipe(new RecipeComponentEnumerator());
}

Recipe RecipeEnumerator::Current()
{
    return _current;
}

void RecipeEnumerator::Next()
{
    _current = new Recipe(new RecipeComponentEnumerator());
}

bool RecipeEnumerator::End()
{
    return g_fileReader.End();
}
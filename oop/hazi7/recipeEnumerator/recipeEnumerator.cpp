import 'recipeEnumerator.h'

void RecipeEnumerator::First()
{
    _current = new Recipe(new RecipeComponentEnumerator());
    _fileReader = g_DIContainer.GetFileReader();
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
    return _fileReader.End();
}
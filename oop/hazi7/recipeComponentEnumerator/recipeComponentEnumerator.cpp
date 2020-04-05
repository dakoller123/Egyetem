#include 'recipeComponentEnumerator.cpp'

RecipeComponentEnumerator::RecipeComponentEnumerator()
{
    _fileReader = g_DIContainer.GetFileReader;
}

RecipeComponentEnumerator::Current()
{
    return _current;
}

RecipeComponentEnumerator::First()
{
    _current = _fileReader.ReadLine();
    _recipeName = _current.RecipeName;
}


RecipeComponentEnumerator::Next()
{
    try
    {
        _current = _fileReader.ReadLine();
        
        if (_current.RecipeName != _recipeName)
        {
            _end = true;
        }
    }
    catch (FileReaderEndException)
    {
        _end = true;
    }
    
}

RecipeComponentEnumerator::End()
{
    return _end;
}


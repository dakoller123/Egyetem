

// RecipeComponentEnumerator::RecipeComponentEnumerator()
// {
//     _fileReader = FileReader();
// }

RecipeComponentEnumerator::Current()
{
    return _current;
}

RecipeComponentEnumerator::First()
{
    _current = g_fileReader.ReadLine();
    _recipeName = _current.RecipeName;
}


RecipeComponentEnumerator::Next()
{
    _current = g_fileReader.ReadLine();
    
    if (_current.RecipeName != _recipeName || g_fileReader.End())
    {
        _end = true;
    }
}

RecipeComponentEnumerator::End()
{
    return _end;
}


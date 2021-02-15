#include <recipe>

Recipe::Recipe(RecipeComponentEnumerator components)
{
    _components = components;

    _containsSugar = false;
    components.First();
    
    while (!components.End())
    {
        _containsSugar = _containsSugar || components.Current().IsSugar();
        components.Next();        
   }
}

bool Recipe::ContainsSugar() const
 {


    return _containsSugar;
 }
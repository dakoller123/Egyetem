#include <vector>
#include <iostream>    
#include <algorithm>  

void print (int i) 
{  
  std::cout << ' ' << i;
}

class vectors_predicate_view
{
    private:
        std::vector<int>& original;
        std::vector<int> original_copy;
        
    public:
        vectors_predicate_view(std::vector<int>& original_): original(original_)
        {
            std::cout << "original vector start :";
            for_each (original.begin(), original.end(), print);
            std::cout << std::endl;
                      
            copy(original.begin(), original.end(), back_inserter(original_copy)); 
            
            original[0]  = 999;
            original.push_back(888);
            
            std::cout << "original vector now :";
            for_each (original.begin(), original.end(), print);
            std::cout << std::endl;
            
            original.assign(original_copy.begin(), original_copy.end()); 
            
            std::cout << "original vector after copy back :";
            for_each (original.begin(), original.end(), print);
            std::cout << std::endl;
        }
};
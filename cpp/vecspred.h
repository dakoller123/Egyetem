#include <vector>
#include <iostream>    
#include <algorithm>  



class vectors_predicate_view
{
    private:
        std::vector<int>& original;
        std::vector<int> original_copy;
        
    public:
        vectors_predicate_view(std::vector<int>& original_): original(original_)
        {
            original_copy.assign(original.begin(), original.end()); 
            
            original[0]  = 999;
            original.push_back(888);           
        }
        
        ~vectors_predicate_view()
        {
            original.assign(original_copy.begin(), original_copy.end()); 
        }
};
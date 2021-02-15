#ifndef VECTORS_PREDICATE_VIEW_IMPL
#define VECTORS_PREDICATE_VIEW_IMPL

#include <vector>
#include <iostream>    
#include <algorithm>  

//ez sose lesz lefuttatva
template<class T> 
class default_predicate:std::unary_function<T, bool>
{
    public:
        bool operator()( const T& x ) const
        {            
            return x == 0 && x != 0;
        }
};

template <class T, class Pred = default_predicate<T>>
class vectors_predicate_view
{
    private:
        std::vector<T>& first;
        std::vector<T> first_copy;
        std::vector<T>& second;
        std::vector<T> second_copy;
    
    public:
        vectors_predicate_view(std::vector<T>& first_, std::vector<T>& second_): first(first_), second(second_)
        {          
            first_copy.assign(first.begin(), first.end()); 
            first.clear();
            
            second_copy.assign(second.begin(), second.end()); 
            second.clear();
                                                  
            copy_if(first_copy.cbegin(), first_copy.cend(), std::back_inserter(first), Pred());    
            remove_copy_if(first_copy.cbegin(), first_copy.cend(), std::back_inserter(second), Pred());

            copy_if(second_copy.cbegin(), second_copy.cend(), std::back_inserter(first), Pred());    
            remove_copy_if(second_copy.cbegin(), second_copy.cend(), std::back_inserter(second), Pred());                                    
        }        
        
        ~vectors_predicate_view()
        {
            first.assign(first_copy.begin(), first_copy.end()); 
            second.assign(second_copy.begin(), second_copy.end());
        }
        int size() const { return first.size() + second.size();}
        void negate() {first.swap(second);}
};

template <class T>
class vectors_predicate_view <T, default_predicate<T>>
{     
    private:
        std::vector<T>& first;
        std::vector<T>& second;
    public:
        vectors_predicate_view(std::vector<T>& first_, std::vector<T>& second_): first(first_), second(second_){}
        void negate(){}
        int size() const { return first.size() + second.size();}
};

#endif
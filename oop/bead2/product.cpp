#include "product.h"
#include <string> 

Product::Product(std::string name, unsigned int price)
{
	Name = name;
	Price = price;
}

bool Product::IsExpensive() const
{
	return Price > 20000;
}
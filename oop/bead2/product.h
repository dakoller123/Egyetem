#pragma once
#include <string> 

class Product
{
	public:
		std::string Name;
		unsigned int Price;
		Product(std::string name, unsigned int price);
		bool IsExpensive() const;
};
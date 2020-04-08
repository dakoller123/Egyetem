#pragma once
#include "product.h"
#include <string>
#include <vector>

class Receipt
{
	public:
		std::vector<std::string> CustomerName;
		std::vector<Product> Products;
		bool OnlyExpensiveProducts() const;
		Receipt(std::vector<std::string> customerName, std::vector<Product> products);
};
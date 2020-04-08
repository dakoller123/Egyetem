#include "receipt.h"

bool Receipt::OnlyExpensiveProducts() const
{
	for (Product p : Products)
	{
		if (!p.IsExpensive())
		{
			return false;
		}
	}
	
	return true;
}

Receipt::Receipt(std::vector<std::string> customerName, std::vector<Product> products)
{
	CustomerName = customerName;
	Products = products;
}
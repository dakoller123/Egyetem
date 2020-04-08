#pragma once
#include "receipt.h"
#include <vector> 

class Turnover
{
	public:
		std::vector<Receipt> Receipts;
		bool AnyExpensiveReceipts() const;
		Turnover(std::vector<Receipt> receipts);
	
};
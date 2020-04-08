#include "turnover.h"

bool Turnover::AnyExpensiveReceipts() const
{
	for (Receipt rec : Receipts)
	{
		if (rec.OnlyExpensiveProducts())
		{
			return true;
		}
	}
	
	return false;
}

Turnover::Turnover(std::vector<Receipt> receipts)
{
	Receipts = receipts;
}
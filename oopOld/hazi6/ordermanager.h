#pragma once
#include <string>
#include "order.h"

class OrderManager
{
	private:
		std::string mostProfitableFoodName;
		std::string lastAddedFoodName;
		int mostProfitableFoodTotalProfit;
		int lastAddedFoodTotalProfit;
		bool isEmpty;
		void setMostToLast();
		void setLast(Order order);
	public:
		OrderManager();
		void AddOrder(Order order);
		std::string MostProfitableFood() const;
};
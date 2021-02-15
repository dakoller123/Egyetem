#include "order.h"
#include "ordermanager.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{	
	OrderManager mgr = OrderManager();
    ifstream f( "input.txt" );
    if(f.fail()){
        cout << "File open error!\n";
        return 1;
    }

	std::string foodName; 
	int tableId; 
	std::string timeOfOrder; 
	int count; 
	int unitPrice;
    
    while(f >> foodName >> tableId >> timeOfOrder >> count >> unitPrice) 
	{ 
		mgr.AddOrder(Order(foodName, count, unitPrice)); 	
	}
	
    cout << "The most profitable food: "<< mgr.MostProfitableFood() << endl;

    return 0;
}

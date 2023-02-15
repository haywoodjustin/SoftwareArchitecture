#pragma once
#include "Order.h"
class OrderManager
{
	Order* order;

public:
	OrderManager(Order* order) : order(order) {}

	void createCustomer(std::string name, std::string address);
	void submitOrder();
	bool checkStock(int itemNumber);
};
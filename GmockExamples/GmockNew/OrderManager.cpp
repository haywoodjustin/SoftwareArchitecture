#include "OrderManager.h"

void OrderManager::createCustomer(std::string name, std::string address)
{
	order->setCustomerName(name);
	order->setCustomerAddress(address);
}

void OrderManager::submitOrder()
{
	if (checkStock(order->getItemNumber()))
	{
		order->setStatus(pending);
	}
	else
	{
		order->setStatus(cancelled);
	}
}

bool OrderManager::checkStock(int itemNumber)
{
	// Pretending item 3000 is the only not in stock item
	if (3000 == itemNumber)
	{
		return false;
	}
	else
	{
		return true;
	}
}
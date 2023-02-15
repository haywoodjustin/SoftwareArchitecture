#pragma once
#include "Order.h"
#include "gmock/gmock.h"
class MockOrder : public Order
{
public:
	MOCK_METHOD(void, setCustomerAddress, (std::string addr));
	MOCK_METHOD(void, setCustomerName, (std::string name));
	MOCK_METHOD(void, setItemNumber, (int item));
	MOCK_METHOD(void, setStatus, (orderStatus status));
	MOCK_METHOD(std::string, getCustomerAddress, ());
	MOCK_METHOD(std::string, getCustomerName, ());
	MOCK_METHOD(int, getItemNumber, ());
	MOCK_METHOD(orderStatus, getOrderStatus, ());
};
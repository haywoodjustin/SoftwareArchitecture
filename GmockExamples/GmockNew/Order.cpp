#include "Order.h"
void Order::setCustomerName(std::string name) { custName = name; };
void Order::setCustomerAddress(std::string addr) { custAddr = addr; };
void Order::setItemNumber(int item) { itemNum = item; };
void Order::setStatus(orderStatus orderstatus) { status = orderstatus; };
std::string Order::getCustomerAddress() { return custAddr; };
std::string Order::getCustomerName() { return custName; };
int Order::getItemNumber() { return itemNum; };
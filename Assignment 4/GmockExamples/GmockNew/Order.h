#pragma once
#include <string>
enum orderStatus
{
	submitted = 1,
	pending = 2,
	shipped = 3,
	complete = 4,
	cancelled = 5
};

class Order 
{
private:
	int itemNum;
	std::string custName, custAddr;
	orderStatus status;
public:
	virtual ~Order() {}
	virtual void setCustomerName(std::string name);
	virtual void setCustomerAddress(std::string addr);
	virtual void setItemNumber(int item);
	virtual void setStatus(orderStatus status);
	virtual std::string getCustomerAddress();
	virtual std::string getCustomerName();
	virtual int getItemNumber();
};
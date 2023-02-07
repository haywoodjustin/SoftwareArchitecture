
#include <BI.h>
#include <Core.h>
#include <string>
#include <iostream>

static BusinessIntelligence* theBusinessIntelligence = nullptr;

BusinessIntelligence::BusinessIntelligence()
{
	fnCore();
}

void BusinessIntelligence::LogSomething(std::string something)
{
	std::cout << "BusinessIntelligence LogSomething " << something <<  std::endl;
}

BusinessIntelligence* GetBusinessIntelligence()
{
	return theBusinessIntelligence;
}




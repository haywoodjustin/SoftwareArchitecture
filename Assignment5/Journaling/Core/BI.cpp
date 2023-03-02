
#include "BI.h"
#include <string>

static BusinessIntelligence* theBusinessIntelligence = nullptr;

	BusinessIntelligence::BusinessIntelligence()
	{

	}

	void BusinessIntelligence::LogSomething(std::string something)
	{

	}

	BusinessIntelligence* GetBusinessIntelligence()
	{
		return theBusinessIntelligence;
	}




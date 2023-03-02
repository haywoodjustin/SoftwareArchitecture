#pragma once

#include "CoreExports.h"
#include <string>

class CORE_API BusinessIntelligence
{
public:
	BusinessIntelligence();

	void LogSomething(std::string something);

	

};

extern CORE_API BusinessIntelligence* GetBusinessIntelligence();
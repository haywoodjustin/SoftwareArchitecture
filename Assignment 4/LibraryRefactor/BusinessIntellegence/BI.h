#pragma once
#include "../BusinessIntellegence/BusinessExports.h"

#include <string>
/// <summary>
/// Utility class for our Business Intelligence module
/// </summary>
class BUSINESSINTELLEGENCE_API BusinessIntelligence
{
public:
	

	void LogSomething(std::string something);

private:

	BusinessIntelligence();
};

extern BUSINESSINTELLEGENCE_API BusinessIntelligence* GetBusinessIntelligence();
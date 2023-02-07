#pragma once
#include "BlobExports.h"

#include <string>
/// <summary>
/// Utility class for our Business Intelligence module
/// </summary>
class BLOBLIBRARY_API BusinessIntelligence
{
public:
	

	void LogSomething(std::string something);

private:

	BusinessIntelligence();
};

extern BLOBLIBRARY_API BusinessIntelligence* GetBusinessIntelligence();
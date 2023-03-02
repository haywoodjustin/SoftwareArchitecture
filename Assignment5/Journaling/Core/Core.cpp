// Core.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "Core.h"
#include <iostream>
#include "CoreSession.h"

static CoreSession* m_coreSession = nullptr;

CORE_API int initializeProduct(void)
{
	std::cout << "Product Core is Initialized" << std::endl;
	CoreSession::GetInstance();
	return 0;
}

CORE_API int shutdownProduct(void)
{
	std::cout << "Product Core is Shutdown" << std::endl;
	CoreSession::GetInstance().ClearObservers();
	return 0;
}


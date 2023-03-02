// AppsCore.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "AppsCore.h"


// This is an example of an exported variable
APPSCORE_API int nAppsCore=0;

// This is an example of an exported function.
APPSCORE_API int fnAppsCore(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CAppsCore::CAppsCore()
{
    return;
}

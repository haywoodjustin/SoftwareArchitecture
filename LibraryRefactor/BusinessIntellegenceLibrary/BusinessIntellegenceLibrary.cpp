// BusinessIntellegenceLibrary.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "BusinessIntellegenceLibrary.h"


// This is an example of an exported variable
BUSINESSINTELLEGENCELIBRARY_API int nBusinessIntellegenceLibrary=0;

// This is an example of an exported function.
BUSINESSINTELLEGENCELIBRARY_API int fnBusinessIntellegenceLibrary(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CBusinessIntellegenceLibrary::CBusinessIntellegenceLibrary()
{
    return;
}

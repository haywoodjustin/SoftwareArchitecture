// UserInterfaceLibrary.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "UserInterfaceLibrary.h"


// This is an example of an exported variable
USERINTERFACELIBRARY_API int nUserInterfaceLibrary=0;

// This is an example of an exported function.
USERINTERFACELIBRARY_API int fnUserInterfaceLibrary(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CUserInterfaceLibrary::CUserInterfaceLibrary()
{
    return;
}

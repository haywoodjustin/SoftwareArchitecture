// UserInterfaceLibrary.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "UserInterfaceLibrary.h"


// This is an example of an exported variable
USERINTERFACE_API int nUserInterface = 0;

// This is an example of an exported function.
USERINTERFACE_API int fnUserInterface(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CUserInterface::CUserInterface()
{
    return;
}
// UiLibrary.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "UiLibrary.h"


// This is an example of an exported variable
UILIBRARY_API int nUiLibrary=0;

// This is an example of an exported function.
UILIBRARY_API int fnUiLibrary(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CUiLibrary::CUiLibrary()
{
    return;
}

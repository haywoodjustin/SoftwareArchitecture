// ApplicationLibrary.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "ApplicationLibrary.h"


// This is an example of an exported variable
APPLICATIONLIBRARY_API int nApplicationLibrary=0;

// This is an example of an exported function.
APPLICATIONLIBRARY_API int fnApplicationLibrary(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CApplicationLibrary::CApplicationLibrary()
{
    return;
}

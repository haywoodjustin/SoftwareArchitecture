// WorkbookManipulation.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "WorkbookManipulation.h"


// This is an example of an exported variable
WORKBOOKMANIPULATION_API int nWorkbookManipulation=0;

// This is an example of an exported function.
WORKBOOKMANIPULATION_API int fnWorkbookManipulation(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CWorkbookManipulation::CWorkbookManipulation()
{
    return;
}

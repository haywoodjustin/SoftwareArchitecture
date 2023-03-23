// Workbook.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "Workbook.h"


// This is an example of an exported variable
WORKBOOK_API int nWorkbook=0;

// This is an example of an exported function.
WORKBOOK_API int fnWorkbook(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CWorkbook::CWorkbook()
{
    return;
}

/// <summary>
/// API for workbook object 
/// </summary>
/// <returns>
/// Workbook object
/// </returns>
CWorkbook CWorkbook::GetWorkbook()
{
    static CWorkbook workbook;
    return workbook; 
}

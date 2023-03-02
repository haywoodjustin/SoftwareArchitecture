// JavaAutomationBinding.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "JavaAutomationBinding.h"


// This is an example of an exported variable
JAVAAUTOMATIONBINDING_API int nJavaAutomationBinding=0;

// This is an example of an exported function.
JAVAAUTOMATIONBINDING_API int fnJavaAutomationBinding(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CJavaAutomationBinding::CJavaAutomationBinding()
{
    return;
}

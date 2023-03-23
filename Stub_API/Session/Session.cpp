// Session.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "Session.h"


// This is an example of an exported variable
SESSION_API int nSession=0;

// This is an example of an exported function.
SESSION_API int fnSession(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CSession::CSession()
{
    return;
}

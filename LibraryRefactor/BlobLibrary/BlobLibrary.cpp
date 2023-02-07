// BlobLibrary.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "BlobLibrary.h"


// This is an example of an exported variable
BLOBLIBRARY_API int nBlobLibrary=0;

// This is an example of an exported function.
BLOBLIBRARY_API int fnBlobLibrary(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CBlobLibrary::CBlobLibrary()
{
    return;
}

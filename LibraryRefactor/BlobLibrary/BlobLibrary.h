
#include "BlobExports.h"

// This class is exported from the dll
class BLOBLIBRARY_API CBlobLibrary {
public:
	CBlobLibrary(void);
	// TODO: add your methods here.
};

extern BLOBLIBRARY_API int nBlobLibrary;

BLOBLIBRARY_API int fnBlobLibrary(void);

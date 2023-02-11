// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the BUSINESSINTELLEGENCELIBRARY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// BUSINESSINTELLEGENCELIBRARY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include "BusinessExports.h"

// This class is exported from the dll
class BUSINESSINTELLEGENCELIBRARY_API CBusinessIntellegenceLibrary {
public:
	CBusinessIntellegenceLibrary(void);
	// TODO: add your methods here.
};

extern BUSINESSINTELLEGENCELIBRARY_API int nBusinessIntellegenceLibrary;

BUSINESSINTELLEGENCELIBRARY_API int fnBusinessIntellegenceLibrary(void);

// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CORE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CORE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#include "CoreExports.h"

// This class is exported from the dll
class CORE_API CCore {
public:
	CCore(void);
	// TODO: add your methods here.
};

extern CORE_API int nCore;

CORE_API int fnCore(void);

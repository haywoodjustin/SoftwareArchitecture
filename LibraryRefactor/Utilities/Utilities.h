// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the UTILITIES_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// UTILITIES_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#include "UtilitiesExports.h"

// This class is exported from the dll
class UTILITIES_API CUtilities {
public:
	CUtilities(void);
	// TODO: add your methods here.
};

extern UTILITIES_API int nUtilities;

UTILITIES_API int fnUtilities(void);

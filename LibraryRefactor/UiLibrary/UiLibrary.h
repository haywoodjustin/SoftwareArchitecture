// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the UILIBRARY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// UILIBRARY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include "UiLibraryExports.h"

// This class is exported from the dll
class UILIBRARY_API CUiLibrary {
public:
	CUiLibrary(void);
	// TODO: add your methods here.
};

extern UILIBRARY_API int nUiLibrary;

UILIBRARY_API int fnUiLibrary(void);

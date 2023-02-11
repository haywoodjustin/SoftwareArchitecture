// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the BUSINESSINTELLEGENCE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// BUSINESSINTELLEGENCE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include "BusinessExports.h"

// This class is exported from the dll
class BUSINESSINTELLEGENCE_API CBusinessIntellegence {
public:
	CBusinessIntellegence(void);
	// TODO: add your methods here.
};

extern BUSINESSINTELLEGENCE_API int nBusinessIntellegence;

BUSINESSINTELLEGENCE_API int fnBusinessIntellegence(void);

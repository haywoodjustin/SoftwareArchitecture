// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the APPSCORE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// APPSCORE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef APPSCORE_EXPORTS
#define APPSCORE_API __declspec(dllexport)
#else
#define APPSCORE_API __declspec(dllimport)
#endif

// This class is exported from the dll
class APPSCORE_API CAppsCore {
public:
	CAppsCore(void);
	// TODO: add your methods here.
};

extern APPSCORE_API int nAppsCore;

APPSCORE_API int fnAppsCore(void);

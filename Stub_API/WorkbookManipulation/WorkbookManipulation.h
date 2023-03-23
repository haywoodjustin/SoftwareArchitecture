// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the WORKBOOKMANIPULATION_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// WORKBOOKMANIPULATION_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef WORKBOOKMANIPULATION_EXPORTS
#define WORKBOOKMANIPULATION_API __declspec(dllexport)
#else
#define WORKBOOKMANIPULATION_API __declspec(dllimport)
#endif

// This class is exported from the dll
class WORKBOOKMANIPULATION_API CWorkbookManipulation {
public:
	CWorkbookManipulation(void);
	// TODO: add your methods here.
};

extern WORKBOOKMANIPULATION_API int nWorkbookManipulation;

WORKBOOKMANIPULATION_API int fnWorkbookManipulation(void);

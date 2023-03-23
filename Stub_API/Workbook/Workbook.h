// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the WORKBOOK_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// WORKBOOK_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef WORKBOOK_EXPORTS
#define WORKBOOK_API __declspec(dllexport)
#else
#define WORKBOOK_API __declspec(dllimport)
#endif

// This class is exported from the dll
class WORKBOOK_API CWorkbook {
public:
	CWorkbook(void);
	CWorkbook GetWorkbook(); 
	// TODO: add your methods here.
};

extern WORKBOOK_API int nWorkbook;

WORKBOOK_API int fnWorkbook(void);

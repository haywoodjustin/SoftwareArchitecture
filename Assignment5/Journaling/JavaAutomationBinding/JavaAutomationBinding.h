// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the JAVAAUTOMATIONBINDING_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// JAVAAUTOMATIONBINDING_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef JAVAAUTOMATIONBINDING_EXPORTS
#define JAVAAUTOMATIONBINDING_API __declspec(dllexport)
#else
#define JAVAAUTOMATIONBINDING_API __declspec(dllimport)
#endif

// This class is exported from the dll
class JAVAAUTOMATIONBINDING_API CJavaAutomationBinding {
public:
	CJavaAutomationBinding(void);
	// TODO: add your methods here.
};

extern JAVAAUTOMATIONBINDING_API int nJavaAutomationBinding;

JAVAAUTOMATIONBINDING_API int fnJavaAutomationBinding(void);

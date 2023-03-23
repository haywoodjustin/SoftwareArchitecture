// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the SESSION_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// SESSION_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SESSION_EXPORTS
#define SESSION_API __declspec(dllexport)
#else
#define SESSION_API __declspec(dllimport)
#endif

// This class is exported from the dll
class SESSION_API CSession {
public:
	CSession(void);
	CSession GetSession(void); 
	// TODO: add your methods here.
};

extern SESSION_API int nSession;

SESSION_API int fnSession(void);

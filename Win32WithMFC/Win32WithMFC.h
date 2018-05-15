// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the WIN32WITHMFC_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// WIN32WITHMFC_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef WIN32WITHMFC_EXPORTS
#define WIN32WITHMFC_API __declspec(dllexport)
#else
#define WIN32WITHMFC_API __declspec(dllimport)
#endif

// This class is exported from the Win32WithMFC.dll
class WIN32WITHMFC_API CWin32WithMFC {
public:
	CWin32WithMFC(void);
	// TODO: add your methods here.
};

extern WIN32WITHMFC_API int nWin32WithMFC;

WIN32WITHMFC_API int fnWin32WithMFC(void);

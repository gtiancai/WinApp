
// MFCApplicationDemo.h : main header file for the MFCApplicationDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCApplicationDemoApp:
// See MFCApplicationDemo.cpp for the implementation of this class
//

class CMFCApplicationDemoApp : public CWinAppEx
{
public:
	CMFCApplicationDemoApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplicationDemoApp theApp;

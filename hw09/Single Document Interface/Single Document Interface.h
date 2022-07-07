
// Single Document Interface.h : main header file for the Single Document Interface application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSingleDocumentInterfaceApp:
// See Single Document Interface.cpp for the implementation of this class
//

class CSingleDocumentInterfaceApp : public CWinApp
{
public:
	CSingleDocumentInterfaceApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSingleDocumentInterfaceApp theApp;

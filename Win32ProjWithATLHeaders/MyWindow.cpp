#include "stdafx.h"
#include <WinUser.h>
#include "MyWindow.h"

LRESULT CMyWindow::onDestroy(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& isHandled)
{
    ::PostQuitMessage(0);

    return 0;
}

LRESULT CMyWindow::onClose(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& isHandled)
{
    // ::DestroyWindow(this->m_hWnd);

    int ret = ::MessageBox(this->m_hWnd, _T("About the dialog"), _T("The Caption"), MB_OKCANCEL);

    if (ret == IDOK)
    {
        ::DestroyWindow(this->m_hWnd);
    }

    return 0;
}

LRESULT CMyWindow::onAbout(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& isHandled)
{
    // ::MessageBox(this->m_hWnd, _T("About the dialog"), _T("The Caption"), MB_OK);
    CMyAboutDialog dialog;
    dialog.DoModal(/*this->m_hWnd*/);

    return 0;
}

LRESULT CMyWindow::onCreate(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& isHandled)
{
    HMENU menu = ::LoadMenu(_AtlBaseModule.GetResourceInstance(), MAKEINTRESOURCE(IDR_MyMENU));
    ::SetMenu(this->m_hWnd, menu);

    return 0;
}

/*
// cannot use CPaintBkgnd as based class for CMyWindow if define the constructor here.
// error:LNK2019	unresolved external symbol "public: __thiscall CPaintBkgnd<class CMyWindow,16711680>::CPaintBkgnd<class CMyWindow,16711680>(void)" (? ? 0 ? $CPaintBkgnd@VCMyWindow@@$0PPAAAA@@@QAE@XZ) referenced in function "public: __thiscall CMyWindow::CMyWindow(void)" (? ? 0CMyWindow@@QAE@XZ)	Win32ProjWithATLHeaders
template<typename T, COLORREF t_crBRUSHCOLOR>
CPaintBkgnd<T, t_crBRUSHCOLOR>::CPaintBkgnd()
{
    m_hbkgnd = CreateSolidBrush(t_crBRUSHCOLOR);
}*/

/*
Severity	Code	Description	Project	File	Line	Suppression State
Error	LNK2019	unresolved external symbol "private: long __thiscall CPaintBkgnd<class CMyWindow,16711680>::onClearBackground(unsigned int,unsigned int,long,int &)" (?onClearBackground@?$CPaintBkgnd@VCMyWindow@@$0PPAAAA@@@AAEJIIJAAH@Z) referenced in function "public: int __thiscall CPaintBkgnd<class CMyWindow,16711680>::ProcessWindowMessage(struct HWND__ *,unsigned int,unsigned int,long,long &,unsigned long)" (?ProcessWindowMessage@?$CPaintBkgnd@VCMyWindow@@$0PPAAAA@@@QAEHPAUHWND__@@IIJAAJK@Z)

template<typename T, COLORREF t_crBRUSHCOLOR>
LRESULT CPaintBkgnd<T, t_crBRUSHCOLOR>::onClearBackground(UINT mgs, WPARAM wParam, LPARAM lParam, BOOL& isHandled)
{
    T* pThis = static_cast<T*>(this);
    HDC hdc = (HDC)wParam;
    RECT rcClient;

    pThis->GetClientRect(&rcClient);
    FillRect(hdc, &rcClient, m_hbkgnd);

    return 1;
}
*/
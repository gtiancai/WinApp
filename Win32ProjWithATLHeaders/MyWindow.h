#pragma once
#include "stdafx.h"
#include <atlwin.h>
#include "Resource.h"

typedef CWinTraits<WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN, WS_EX_APPWINDOW> CMyWindowTraits;

class CMyAboutDialog;

// template<typename, COLORREF> class CPaintBkgnd;


// how to declare a template class? so that we may put the template declaration after the CMyWindow class
template<typename T, COLORREF t_crBRUSHCOLOR>
class CPaintBkgnd
{
public:
    CPaintBkgnd() { m_hbkgnd = CreateSolidBrush(t_crBRUSHCOLOR); }
    ~CPaintBkgnd() { DeleteObject(m_hbkgnd); }

    BEGIN_MSG_MAP(CPaintBkgnd)
        MESSAGE_HANDLER(WM_ERASEBKGND, onClearBackground)
    END_MSG_MAP(CPaintBkgnd)

private:
    LRESULT onClearBackground(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& isHandled)
    {
        T* pThis = static_cast<T*>(this);
        HDC hdc = (HDC)wParam;
        RECT rcClient;

        pThis->GetClientRect(&rcClient);
        FillRect(hdc, &rcClient, m_hbkgnd);

        return 1;
    }
private:
    HBRUSH m_hbkgnd;
};


class CMyAboutDialog : public CDialogImpl<CMyAboutDialog>
{
public:
    enum { IDD = ID_HELP_ABOUT };

    BEGIN_MSG_MAP(CMyAboutDialog)
        MESSAGE_HANDLER(WM_INITDIALOG, onInitDialog)
        MESSAGE_HANDLER(WM_CLOSE, onClose)

        COMMAND_ID_HANDLER(IDOK, onOKCancel)
        COMMAND_ID_HANDLER(IDCANCEL, onOKCancel)
    END_MSG_MAP()

public:
    LRESULT onInitDialog(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& isHandled)
    {
        CenterWindow();

        return 1;
    }

    LRESULT onClose(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& isHandled)
    {
        EndDialog(IDCANCEL);
        return 0;
    }

    LRESULT onOKCancel(WORD wNotificyID, WORD wRD, HWND hWndCtrl, BOOL& isHandled)
    {
        EndDialog(wRD);

        return 0;
    }
};


// 
class CMyWindow : public CWindowImpl<CMyWindow, CWindow, CFrameWinTraits>, public CPaintBkgnd<CMyWindow, RGB(0, 0, 255)>
{
    typedef CPaintBkgnd<CMyWindow, RGB(0, 0, 255)> CPaintBkgndBase;
    // typedef CMyAboutDialog theDialog;
public:
    DECLARE_WND_CLASS(_T("My Window class"))

    BEGIN_MSG_MAP(CMyWindow)
        MESSAGE_HANDLER(WM_CREATE, onCreate);

        MESSAGE_HANDLER(WM_CLOSE, onClose)
        MESSAGE_HANDLER(WM_DESTROY, onDestroy)
        COMMAND_ID_HANDLER(ID_HELP_ABOUT, onAbout) //  COMMAND_ID_HANDLER(IDM_ABOUT, onAbout) // does not work, see .rc file to check which ID the menu item is using
        COMMAND_ID_HANDLER(ID_FILE_EXIT, onExit)
        CHAIN_MSG_MAP(CPaintBkgndBase)
        // CHAIN_MSG_MAP(theDialog)
    END_MSG_MAP()

    LRESULT onClose(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& isHandled);
    LRESULT onDestroy(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& isHandled);
    // LRESULT onAbout(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& isHandled);
    LRESULT onAbout(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& isHandled);
    LRESULT onCreate(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& isHandled);
    LRESULT onExit(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& isHandled)
    {
        // ::DestroyWindow(this->m_hWnd);
        // ::PostMessage(this->m_hWnd, wNotifyCode, wID, 0);
        // ::PostMessage(this->m_hWnd, WM_CLOSE, 0, 0);    // async-message
        ::SendMessage(this->m_hWnd, WM_CLOSE, 0, 0); // which is better? sync-message
        return 0;
    }
};

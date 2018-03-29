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
    ::DestroyWindow(this->m_hWnd);

    return 0;
}

LRESULT CMyWindow::onAbout(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& isHandled)
{
    ::MessageBox(this->m_hWnd, _T("About the dialog"), _T("The Caption"), MB_OK);

    return 0;
}
#pragma once
#include "stdafx.h"
#include <atlwin.h>

typedef CWinTraits<WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN, WS_EX_APPWINDOW> CMyWindowTraits;

// 
class CMyWindow : public CWindowImpl<CMyWindow, CWindow, CFrameWinTraits>
{

public:
    DECLARE_WND_CLASS(_T("My Window class"))

    BEGIN_MSG_MAP(CMyWindow)
        MESSAGE_HANDLER(WM_CLOSE, onClose)
        MESSAGE_HANDLER(WM_DESTROY, onDestroy)
        COMMAND_ID_HANDLER(IDM_ABOUT, onAbout)
    END_MSG_MAP()

    LRESULT onClose(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& isHandled);
    LRESULT onDestroy(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& isHandled);
    LRESULT onAbout(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& isHandled);
};
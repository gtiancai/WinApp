#include "stdAfx.h"
#include <atlwin.h>
#include "MyWindow.h"

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPWSTR cmdLine, int nCmdShow)
{
    //  _Module.Init(NULL);

    CMyWindow myWindow;
    MSG msg;

    if (NULL == myWindow.Create(NULL, CWindow::rcDefault, L"The first ATL Window"))
    {
        return 1;
    }

    myWindow.ShowWindow(nCmdShow);
    myWindow.UpdateWindow();

    while (::GetMessage(&msg, NULL, 0, 0))
    {
        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
    }

    return msg.lParam;
}
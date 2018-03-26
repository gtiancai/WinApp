#pragma once

#include <string>

template <typename theType>
class BaseWinProc
{
public:
    static HRESULT CALLBACK theWinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        theType* pThis = nullptr;

        if (msg == WM_NCCREATE)
        {
            CREATESTRUCT *pCreate = (CREATESTRUCT*)lParam;

            if (pCreate)
            {
                pThis = (theType*)pCreate->lpCreateParams;
                pThis->m_hwnd = hwnd;
                ::SetWindowLongPtr(pThis->m_hwnd, GWLP_USERDATA, (LONG_PTR)pThis);
            }
            else
            {
                pThis = (theType*) ::GetWindowLongPtr(hwnd, GWLP_USERDATA);
            }

            if (pThis)
            {
                pThis->HandleMessage(uMsg, wParam, lParam);
            }
            else
            {
                ::DefWindowProc(hwnd, uMsg, wParam, lParam);
            }
        }

    }
private:
    std::string className;
};


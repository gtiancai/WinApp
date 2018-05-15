
// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "MFCApplicationDemo.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
    // WM_LBUTTONDOWN(OnLButtonDown)
    // WM_LBUTTONUP(OnLButtonUp)
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
    curLine = nullptr;
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying the CREATESTRUCT cs
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CChildFrame message handlers

void CChildFrame::OnLButtonDown(UINT flag, CPoint point)
{
    curLine = new MyLine();
    curLine->SetTopLeftPoint(point);
}

void CChildFrame::OnLButtonUp(UINT flag, CPoint point)
{
    curLine->SetBottomRightPoint(point);

    lines.push_back(std::shared_ptr<MyLine>(curLine));
    curLine = nullptr;
}
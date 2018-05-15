
// MFCApplicationDemoView.cpp : implementation of the CMFCApplicationDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplicationDemo.h"
#endif

#include "MFCApplicationDemoDoc.h"
#include "MFCApplicationDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplicationDemoView

IMPLEMENT_DYNCREATE(CMFCApplicationDemoView, CView)

BEGIN_MESSAGE_MAP(CMFCApplicationDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplicationDemoView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()

    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEMOVE()
    ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFCApplicationDemoView construction/destruction

CMFCApplicationDemoView::CMFCApplicationDemoView() : isBtnDown(false)
{
	// TODO: add construction code here
    prevPoint = 0;
    content = "";
}

CMFCApplicationDemoView::~CMFCApplicationDemoView()
{
}

BOOL CMFCApplicationDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplicationDemoView drawing

void CMFCApplicationDemoView::OnDraw(CDC* /*pDC*/)
{
	CMFCApplicationDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

    CClientDC dc(this);
    dc.TextOutW(0, 0, content);

    TEXTMETRIC txtMetric;
    GetTextMetrics(dc, &txtMetric);

    CreateSolidCaret(txtMetric.tmAveCharWidth / 4, txtMetric.tmHeight);
    /*POINT p;
    CSize size = dc.GetTextExtent(content);
    p.x = size.cx;
    // p.y = size.cy;
    SetCaretPos(p);
    */
    SetCaretPos(caretPos);
    ShowCaret();

	// TODO: add draw code for native data here
}


// CMFCApplicationDemoView printing


void CMFCApplicationDemoView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplicationDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApplicationDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApplicationDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCApplicationDemoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplicationDemoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplicationDemoView diagnostics

#ifdef _DEBUG
void CMFCApplicationDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplicationDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplicationDemoDoc* CMFCApplicationDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationDemoDoc)));
	return (CMFCApplicationDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplicationDemoView message handlers

void CMFCApplicationDemoView::OnLButtonDown(UINT flag, CPoint point)
{
    isBtnDown = true;
    prevPoint = point;

    curLine = new MyLine();
    curLine->SetTopLeftPoint(point);
}

void CMFCApplicationDemoView::OnLButtonUp(UINT flag, CPoint point)
{
    curLine->SetBottomRightPoint(point);

    lines.push_back(std::shared_ptr<MyLine>(curLine));
    // curLine = nullptr;

    /*
    CDC *dc = nullptr;
    dc = this->GetDC();

    curLine->Draw(*dc);

    this->ReleaseDC(dc);
    */

    // CClientDC dc(this);
    // CClientDC dc(GetParent());

    // CWindowDC dc(GetParent());
    CWindowDC dc(this);
    CPen myPen(PS_SOLID, 1, RGB(0, 255, 100));

    CPen* oldPen = dc.SelectObject(&myPen);

    dc.MoveTo(curLine->GetTopLeftPoint());
    dc.LineTo(curLine->GetBottomRight());

    dc.SelectObject(oldPen);

    curLine = nullptr;
    isBtnDown = false;

    caretPos = point;
    SetCaretPos(caretPos);
}



void CMFCApplicationDemoView::OnMouseMove(UINT flags, CPoint point)
{
    if (isBtnDown)
    {
        CClientDC dc(this);

        dc.MoveTo(prevPoint);
        dc.LineTo(point);

        prevPoint = point;
    }
}

void CMFCApplicationDemoView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    content.AppendChar(nChar);

    CClientDC dc(this);
    dc.TextOutW(0, 0, content);

    CSize sz = dc.GetTextExtent(content);
    POINT p = {sz.cx, 0};
    SetCaretPos(p);
}
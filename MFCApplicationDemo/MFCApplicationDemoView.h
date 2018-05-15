
// MFCApplicationDemoView.h : interface of the CMFCApplicationDemoView class
//

#pragma once
#include <memory>
// #include <string>
#include "MyLine.h"

class CMFCApplicationDemoView : public CView
{
protected: // create from serialization only
	CMFCApplicationDemoView();
	DECLARE_DYNCREATE(CMFCApplicationDemoView)

// Attributes
public:
	CMFCApplicationDemoDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

    virtual void OnLButtonDown(UINT flags, CPoint point);
    virtual void OnLButtonUp(UINT flags, CPoint point);
    virtual void OnMouseMove(UINT flags, CPoint piont);
    virtual void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);

// Implementation
public:
	virtual ~CMFCApplicationDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);

    std::vector<std::shared_ptr<MyLine>> lines;
    MyLine* curLine;
    CPoint prevPoint;
    bool isBtnDown;
    // std::string content;
    CString content;
    CPoint caretPos;
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCApplicationDemoView.cpp
inline CMFCApplicationDemoDoc* CMFCApplicationDemoView::GetDocument() const
   { return reinterpret_cast<CMFCApplicationDemoDoc*>(m_pDocument); }
#endif


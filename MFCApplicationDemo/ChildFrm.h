
// ChildFrm.h : interface of the CChildFrame class
//

#pragma once

#include <memory>
#include "MyLine.h"

class CChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

// Attributes
public:

// Operations
public:

// Overrides
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

    virtual void OnLButtonDown(UINT flags, CPoint point);
    virtual void OnLButtonUp(UINT flag, CPoint point);

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

    std::vector<std::shared_ptr<MyLine>> lines;
    MyLine* curLine;
};

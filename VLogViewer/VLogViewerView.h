
// VLogViewerView.h : interface of the CVLogViewerView class
//

#pragma once
#include "LogFile.h"

class CVLogViewerView : public CListView
{
protected: // create from serialization only
	CVLogViewerView();
	DECLARE_DYNCREATE(CVLogViewerView)

// Attributes
public:
	CVLogViewerDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CVLogViewerView();
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
	DECLARE_MESSAGE_MAP()
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
};

#ifndef _DEBUG  // debug version in VLogViewerView.cpp
inline CVLogViewerDoc* CVLogViewerView::GetDocument() const
   { return reinterpret_cast<CVLogViewerDoc*>(m_pDocument); }
#endif


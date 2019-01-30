
// VLogViewerView.cpp : implementation of the CVLogViewerView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "VLogViewer.h"
#endif

#include "VLogViewerDoc.h"
#include "VLogViewerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVLogViewerView

IMPLEMENT_DYNCREATE(CVLogViewerView, CListView)

BEGIN_MESSAGE_MAP(CVLogViewerView, CListView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()		
END_MESSAGE_MAP()

// CVLogViewerView construction/destruction

CVLogViewerView::CVLogViewerView()
{
	// TODO: add construction code here

}

CVLogViewerView::~CVLogViewerView()
{
}

BOOL CVLogViewerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	return CListView::PreCreateWindow(cs);
}

void CVLogViewerView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().	
	ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
	ASSERT(GetStyle() & LVS_REPORT);

	CListCtrl& listCtrl = GetListCtrl();

	// Insert a column. This override is the most convenient.
	listCtrl.InsertColumn(0, _T("Time"), LVCFMT_LEFT);
	listCtrl.InsertColumn(1, _T("Type"), LVCFMT_LEFT);
	listCtrl.InsertColumn(2, _T("Content"), LVCFMT_LEFT);

	listCtrl.SetColumnWidth(0, 200);
	listCtrl.SetColumnWidth(1, 100);
	listCtrl.SetColumnWidth(2, LVSCW_AUTOSIZE_USEHEADER);
}

void CVLogViewerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CVLogViewerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CVLogViewerView diagnostics

#ifdef _DEBUG
void CVLogViewerView::AssertValid() const
{
	CListView::AssertValid();
}

void CVLogViewerView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CVLogViewerDoc* CVLogViewerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVLogViewerDoc)));
	return (CVLogViewerDoc*)m_pDocument;
}
#endif //_DEBUG


// CVLogViewerView message handlers


void CVLogViewerView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	CVLogViewerDoc* pDoc = this->GetDocument();
	CList<CItemInfo, CItemInfo&> &items = pDoc->GetLogFile()->GetItems();
	POSITION pos = items.GetHeadPosition();
	while (pos)
	{
		CItemInfo item = items.GetNext(pos);
		CListCtrl& listCtrl = this->GetListCtrl();
		BOOL bFound = FALSE;
		for (int i = 0; i < listCtrl.GetItemCount(); i++)
		{
			CString strItemText = listCtrl.GetItemText(i, 0);
			if (strItemText == item.GetTime())
			{
				bFound = TRUE;
				break;
			}
		}
		if (!bFound)
		{			
			int nItem = listCtrl.InsertItem(0, item.GetTime());
			listCtrl.SetItemText(nItem, 1, item.GetType());
			listCtrl.SetItemText(nItem, 2, item.GetContent());			
		}
	}

	CListView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}


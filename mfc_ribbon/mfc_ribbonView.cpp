// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// mfc_ribbonView.cpp : implementation of the Cmfc_ribbonView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "mfc_ribbon.h"
#endif

#include "mfc_ribbonDoc.h"
#include "mfc_ribbonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfc_ribbonView

IMPLEMENT_DYNCREATE(Cmfc_ribbonView, CView)

BEGIN_MESSAGE_MAP(Cmfc_ribbonView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cmfc_ribbonView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_MENU0_PLAY, &Cmfc_ribbonView::OnMenu0Play)
	ON_COMMAND(ID_MENU0_SAY, &Cmfc_ribbonView::OnMenu0Say)
	ON_COMMAND(ID_EDIT_CUT, &Cmfc_ribbonView::OnEditCut)
END_MESSAGE_MAP()

// Cmfc_ribbonView construction/destruction

Cmfc_ribbonView::Cmfc_ribbonView()
{
	// TODO: add construction code here

}

Cmfc_ribbonView::~Cmfc_ribbonView()
{
}

BOOL Cmfc_ribbonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cmfc_ribbonView drawing

void Cmfc_ribbonView::OnDraw(CDC* /*pDC*/)
{
	Cmfc_ribbonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cmfc_ribbonView printing


void Cmfc_ribbonView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cmfc_ribbonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cmfc_ribbonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cmfc_ribbonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Cmfc_ribbonView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cmfc_ribbonView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cmfc_ribbonView diagnostics

#ifdef _DEBUG
void Cmfc_ribbonView::AssertValid() const
{
	CView::AssertValid();
}

void Cmfc_ribbonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmfc_ribbonDoc* Cmfc_ribbonView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfc_ribbonDoc)));
	return (Cmfc_ribbonDoc*)m_pDocument;
}
#endif //_DEBUG


// Cmfc_ribbonView message handlers


void Cmfc_ribbonView::OnMenu0Play()
{
	AfxMessageBox(_T("OnMenu0Play"));
}


void Cmfc_ribbonView::OnMenu0Say()
{
	AfxMessageBox(_T("OnMenu0Say"));
}


void Cmfc_ribbonView::OnEditCut()
{
	AfxMessageBox(_T("OnEditCut"));
}

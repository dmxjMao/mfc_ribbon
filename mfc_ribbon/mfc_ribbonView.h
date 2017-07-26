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

// mfc_ribbonView.h : interface of the Cmfc_ribbonView class
//

#pragma once


class Cmfc_ribbonView : public CView
{
protected: // create from serialization only
	Cmfc_ribbonView();
	DECLARE_DYNCREATE(Cmfc_ribbonView)

// Attributes
public:
	Cmfc_ribbonDoc* GetDocument() const;

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

// Implementation
public:
	virtual ~Cmfc_ribbonView();
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
public:
	afx_msg void OnMenu0Play();
	afx_msg void OnMenu0Say();
	afx_msg void OnEditCut();
};

#ifndef _DEBUG  // debug version in mfc_ribbonView.cpp
inline Cmfc_ribbonDoc* Cmfc_ribbonView::GetDocument() const
   { return reinterpret_cast<Cmfc_ribbonDoc*>(m_pDocument); }
#endif


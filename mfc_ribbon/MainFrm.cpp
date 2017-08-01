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

// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "mfc_ribbon.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnApplicationLook)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnUpdateApplicationLook)
	ON_COMMAND(ID_FILE_PRINT, &CMainFrame::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CMainFrame::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMainFrame::OnFilePrintPreview)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_PREVIEW, &CMainFrame::OnUpdateFilePrintPreview)
	ON_COMMAND(ID_BUTTON4, &CMainFrame::OnButton4)
	ON_COMMAND_RANGE(ID_POPUP0_0ITEM0, ID_POPUP0_0ITEM3, &CMainFrame::OnPopup0Item)
	ON_COMMAND(ID_BUTTON5, &CMainFrame::OnButton5)
END_MESSAGE_MAP()

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	theApp.m_nAppLook = theApp.GetInt(_T("ApplicationLook"), ID_VIEW_APPLOOK_WINDOWS_7);
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	BOOL bNameValid;

	m_wndRibbonBar.Create(this);
	m_wndRibbonBar.LoadFromResource(IDR_RIBBON);

	CMFCRibbonCategory* pCate0 = m_wndRibbonBar.AddCategory(_T("我的类别"), IDB_WRITESMALL, IDB_WRITELARGE);

	CMFCRibbonPanel* pPanel0 = pCate0->AddPanel(_T("Standard"));
	pPanel0->Add(new CMFCRibbonGallery(ID_BUTTON4, _T("Embedded"), -1, -1, IDB_WRITELARGE, 32));
	CMFCRibbonGallery* pGBtn0 = new CMFCRibbonGallery(ID_BUTTON4, _T("Button"), 1, 1, IDB_WRITELARGE, 32);
	pGBtn0->SetButtonMode();
	pGBtn0->SetIconsInRow(4);
	//pGBtn0->SetAlwaysLargeImage();
	pGBtn0->EnableMenuResize(TRUE); //多出滚动条
	pPanel0->Add(pGBtn0);

	CMFCRibbonPanel* pPanel1 = pCate0->AddPanel(_T("Extended"));
	CMFCRibbonGallery* pGBtn1 = new CMFCRibbonGallery(ID_BUTTON4, _T("Resize Vertical"), 2, 2, IDB_WRITELARGE, 32);
	pGBtn1->SetButtonMode();
	pGBtn1->SetIconsInRow(3);
	pGBtn1->EnableMenuResize(TRUE); //多出滚动条
	pPanel1->Add(pGBtn1);

	CMFCRibbonGallery* pGBtn2 = new CMFCRibbonGallery(ID_BUTTON4, _T("Groups"), 4, 4);
	pGBtn2->AddGroup(_T("Group1"), IDB_WRITELARGE, 32);
	pGBtn2->AddGroup(_T("Group2"), IDB_WRITELARGE, 32);
	pGBtn2->SetButtonMode();
	pGBtn2->SetIconsInRow(4);
	pGBtn2->EnableMenuResize(TRUE);
	
	//pGBtn2->AddSubItem(new CMFCRibbonButton(ID_BUTTON9, _T("Item 1")));
	//pGBtn2->AddSubItem(new CMFCRibbonButton(ID_BUTTON10, _T("Item 2")));
	//pGBtn2->AddSubItem(new CMFCRibbonButton(ID_BUTTON8, _T("Item 3")));
	pPanel1->Add(pGBtn2);

	CMFCRibbonPanel* pG0Panel3 = pCate0->AddPanel(_T("abc"));
	pG0Panel3->Add(new CMFCRibbonLabel(_T("缩进")));
	CMFCRibbonEdit* pG0P3Spin = new CMFCRibbonEdit(ID_FILE_NEW, 60, _T("左："), 5);
	pG0P3Spin->EnableSpinButtons(0, 99);
	pG0P3Spin->SetEditText(_T("0字符"));
	pG0Panel3->Add(pG0P3Spin);
	

	//我的类别2：工具栏
	CMFCRibbonCategory* pCate2 = m_wndRibbonBar.AddCategory(_T("我的类别2"), IDB_WRITESMALL, IDB_WRITELARGE);
	CMFCRibbonPanel* pC2Panel0 = pCate2->AddPanel(_T("Form Toolbar"));
	pC2Panel0->AddToolBar(IDR_MAINFRAME_256); //工具栏设计时指定了id

	CMFCRibbonPanel* pC2Panel1 = pCate2->AddPanel(_T("Manual Toolbar"));

	CMFCRibbonButtonsGroup* pBtnGroup1 = new CMFCRibbonButtonsGroup;
	pBtnGroup1->AddButton(new CMFCRibbonButton(ID_FILE_NEW, _T(""), 0));
	pBtnGroup1->AddButton(new CMFCRibbonButton(ID_FILE_OPEN, _T(""), 1));
	pBtnGroup1->AddButton(new CMFCRibbonButton(ID_FILE_NEW, _T(""), 2));
	pBtnGroup1->AddButton(new CMFCRibbonButton(ID_FILE_OPEN, _T(""), 3));
	CMFCRibbonEdit* pEdit = new CMFCRibbonEdit(2, 66);
	pBtnGroup1->AddButton(pEdit);
	pC2Panel1->Add(pBtnGroup1);

	CMFCRibbonButtonsGroup* pBtnGroup2 = new CMFCRibbonButtonsGroup;
	pBtnGroup2->AddButton(new CMFCRibbonButton(ID_FILE_NEW, _T(""), 0));
	pBtnGroup2->AddButton(new CMFCRibbonButton(ID_FILE_OPEN, _T(""), 1));
	pBtnGroup2->AddButton(new CMFCRibbonButton(ID_FILE_NEW, _T(""), 2));
	CMenu m;
	m.LoadMenu(IDR_Menu_Popup);
	HMENU hm = m.GetSubMenu(0)->GetSafeHmenu();
	CMFCRibbonButton* pG2Btn4 = new CMFCRibbonButton(ID_FILE_OPEN, _T(""), 3);
	pG2Btn4->SetMenu(hm/*, TRUE是否分为两部分,文本右对齐*/);
	pBtnGroup2->AddButton(pG2Btn4);
	CMFCRibbonButton* pG2Btn5 = new CMFCRibbonButton(ID_FILE_NEW, _T(""), 5);
	pG2Btn5->SetMenu(hm/*, TRUE是否分为两部分,文本右对齐*/);
	pBtnGroup2->AddButton(pG2Btn5);
	pC2Panel1->Add(pBtnGroup2);

	CMFCRibbonPanel* pC2Pane3 = pCate2->AddPanel(_T("Other Control"));
	CMFCRibbonUndoButton* pUndoBtn = new CMFCRibbonUndoButton(ID_FILE_NEW, _T("Undo"), 0);
	for (int i = 0; i < 10; ++i) {
		CString str;
		str.Format(_T("Action %d"), i + 1);
		pUndoBtn->AddUndoAction(str);
	}
	pC2Pane3->Add(pUndoBtn);
	pC2Pane3->Add(new CMFCRibbonSeparator());
	pC2Pane3->Add(new CMFCRibbonLabel(_T("哎呦不错哦！")/*, TRUE 是否多行*/));

	pC2Pane3->Add(new CMFCRibbonLinkCtrl(ID_FILE_NEW, _T("aaa"), _T("mailto:920746980@qq.com")/*提示文本*/));//邮件、网页、启动程序。。

	pC2Pane3->Add(new CMFCRibbonFontComboBox(ID_FILE_NEW));
	CMFCRibbonComboBox* pCombo = new CMFCRibbonComboBox(ID_FILE_NEW, TRUE,40);
	//pCombo->SetDropDownHeight(960);
	pCombo->AddItem(_T("A"));
	//pCombo->AddSubItem(new CMFCRibbonLabel(_T("哎呦不错哦！")/*, TRUE 是否多行*/));
	pCombo->AddItem(_T("b"));
	pCombo->AddItem(_T("c"));
	pCombo->AddItem(_T("d"));
	pCombo->AddItem(_T("e"));
	pCombo->AddItem(_T("f"));
	pCombo->AddItem(_T("g"));
	pCombo->AddItem(_T("h"));
	pCombo->AddItem(_T("i"));
	pCombo->AddItem(_T("j"));
	pCombo->AddItem(_T("k"));
	pCombo->AddItem(_T("l"));

	pC2Pane3->Add(pCombo);

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	CString strTitlePane1;
	CString strTitlePane2;
	bNameValid = strTitlePane1.LoadString(IDS_STATUS_PANE1);
	ASSERT(bNameValid);
	bNameValid = strTitlePane2.LoadString(IDS_STATUS_PANE2);
	ASSERT(bNameValid);
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE1, strTitlePane1, TRUE), strTitlePane1);
	m_wndStatusBar.AddExtendedElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE2, strTitlePane2, TRUE), strTitlePane2);

	// enable Visual Studio 2005 style docking window behavior
	CDockingManager::SetDockingMode(DT_SMART);
	// enable Visual Studio 2005 style docking window auto-hide behavior
	EnableAutoHidePanes(CBRS_ALIGN_ANY);
	// set the visual manager and style based on persisted value
	OnApplicationLook(theApp.m_nAppLook);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

void CMainFrame::OnApplicationLook(UINT id)
{
	CWaitCursor wait;

	theApp.m_nAppLook = id;

	switch (theApp.m_nAppLook)
	{
	case ID_VIEW_APPLOOK_WIN_2000:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManager));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_OFF_XP:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOfficeXP));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_WIN_XP:
		CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_OFF_2003:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2003));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_VS_2005:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_VS_2008:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_WINDOWS_7:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows7));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(TRUE);
		break;

	default:
		switch (theApp.m_nAppLook)
		{
		case ID_VIEW_APPLOOK_OFF_2007_BLUE:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_BLACK:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_SILVER:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_AQUA:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Aqua);
			break;
		}

		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
	}

	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

	theApp.WriteInt(_T("ApplicationLook"), theApp.m_nAppLook);
}

void CMainFrame::OnUpdateApplicationLook(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(theApp.m_nAppLook == pCmdUI->m_nID);
}


void CMainFrame::OnFilePrint()
{
	if (IsPrintPreview())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_PRINT);
	}
}

void CMainFrame::OnFilePrintPreview()
{
	if (IsPrintPreview())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_CLOSE);  // force Print Preview mode closed
	}
}

void CMainFrame::OnUpdateFilePrintPreview(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(IsPrintPreview());
}


void CMainFrame::OnButton4()
{
	AfxMessageBox(_T("OnButton4"));
}

void CMainFrame::OnPopup0Item(UINT nID)
{
	CString str;
	str.Format(_T("Popup0, item %d clicked !"), nID - ID_POPUP0_0ITEM0);
	AfxMessageBox(str);
}

void CMainFrame::OnButton5()
{
	AfxMessageBox(_T("OnButton5"));
}

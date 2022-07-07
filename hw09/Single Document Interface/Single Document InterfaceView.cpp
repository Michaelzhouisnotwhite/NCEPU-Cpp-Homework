
// Single Document InterfaceView.cpp : implementation of the CSingleDocumentInterfaceView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Single Document Interface.h"
#endif

#include "Single Document InterfaceDoc.h"
#include "Single Document InterfaceView.h"
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSingleDocumentInterfaceView

IMPLEMENT_DYNCREATE(CSingleDocumentInterfaceView, CView)

BEGIN_MESSAGE_MAP(CSingleDocumentInterfaceView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FONTDLG_MENU, &CSingleDocumentInterfaceView::OnFontDlgMenu)
	ON_COMMAND(ID_FONTCOLORDLG_MENU, &CSingleDocumentInterfaceView::OnFontcolordlgMenu)
END_MESSAGE_MAP()

// CSingleDocumentInterfaceView construction/destruction

CSingleDocumentInterfaceView::CSingleDocumentInterfaceView() noexcept
{
	// TODO: add construction code here

}

CSingleDocumentInterfaceView::~CSingleDocumentInterfaceView()
{
}

BOOL CSingleDocumentInterfaceView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}
// CSingleDocumentInterfaceView drawing

CFont* CSingleDocumentInterfaceView::ChangePointFontStyle(CDC* pDC, LPSTR font_name, int height)
{
	CFont newFont;
	CString csFontName = CA2CT(font_name);
	//csFontName.Format(_T("%s"), font_name);
	VERIFY(newFont.CreatePointFont(height, csFontName));
	CFont* pOldFont = pDC->SelectObject(&newFont);
	return pOldFont;
}

void CSingleDocumentInterfaceView::ChangeTextColor(CDC* pDC, int r=0, int g=0, int b=0)
{
	pDC->SetTextColor(RGB(r, g, b));
}

void CSingleDocumentInterfaceView::OnDraw(CDC* pDC)
{
	CSingleDocumentInterfaceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: add draw code for native data here
	CFont* oldFont1 = ChangePointFontStyle(pDC, "Castellar", 180);
	ChangeTextColor(pDC, 18, 170, 156);

	CFont* pfntOld = pDC->SelectObject(&m_font);
	pDC->SetTextColor(m_TextColor);

	pDC->TextOutW(50, 10, _T("The course of true love never did run smooth."));

	CFont* oldFont2 = ChangePointFontStyle(pDC, "方正姚体", 180);
	//ChangeTextColor(pDC, 0, 0, 255);

	pDC->TextOutW(50, 60, _T("真诚的爱情之路永不会是平坦的"));

	//pDC->SelectObject(oldFont2);

}


// CSingleDocumentInterfaceView printing

BOOL CSingleDocumentInterfaceView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSingleDocumentInterfaceView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSingleDocumentInterfaceView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSingleDocumentInterfaceView diagnostics

#ifdef _DEBUG
void CSingleDocumentInterfaceView::AssertValid() const
{
	CView::AssertValid();
}

void CSingleDocumentInterfaceView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSingleDocumentInterfaceDoc* CSingleDocumentInterfaceView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingleDocumentInterfaceDoc)));
	return (CSingleDocumentInterfaceDoc*)m_pDocument;
}
#endif //_DEBUG


// CSingleDocumentInterfaceView message handlers


void CSingleDocumentInterfaceView::OnFontDlgMenu()
{
	// TODO: 在此添加命令处理程序代码
}


void CSingleDocumentInterfaceView::OnFontcolordlgMenu()
{
	ChangeColorDlg ccdlg;
	if (ccdlg.DoModal() == IDOK)
	{
		int r = 0, g = 0, b = 0;
		if (ccdlg.r_push)
		{
			r = 255;
		}
		if (ccdlg.g_push)
		{	
			g = 255;
		}
		if (ccdlg.b_push)
		{
			b = 255;
		}
		m_TextColor = RGB(r, g, b);
		RedrawWindow();
	}
}

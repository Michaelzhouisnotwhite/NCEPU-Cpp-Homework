
// Single Document App 10View.cpp: CSingleDocumentApp10View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Single Document App 10.h"
#endif

#include "Single Document App 10Doc.h"
#include "Single Document App 10View.h"

#include "CMyText.h"
#include "CTextDlg.h"
#include "CChangeTextDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSingleDocumentApp10View

IMPLEMENT_DYNCREATE(CSingleDocumentApp10View, CView)

BEGIN_MESSAGE_MAP(CSingleDocumentApp10View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	//ON_COMMAND(ID_32772, &CSingleDocumentApp10View::OnShowTextDlg)
//	ON_WM_LBUTTONDBLCLK()
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
//	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CSingleDocumentApp10View 构造/析构

CSingleDocumentApp10View::CSingleDocumentApp10View() noexcept
{
	// TODO: 在此处添加构造代码

	m_nX = 0;
	m_nY = 0;
	m_strText = _T("");
}

CSingleDocumentApp10View::~CSingleDocumentApp10View()
{
}

BOOL CSingleDocumentApp10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSingleDocumentApp10View 绘图

void CSingleDocumentApp10View::OnDraw(CDC* pDC)
{
	CSingleDocumentApp10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	//pDC->SetTextColor(m_TextColor);
	//pDC->TextOutW(m_nX, m_nY, m_strText);
	POSITION pos = pDoc->m_textList.GetHeadPosition();
	while (pos != nullptr)
	{
		CFont* oldfont = ChangePointFontStyle(pDC, "方正姚体", 160);
		CMyText* pText = (CMyText*)pDoc->m_textList.GetNext(pos);
		CFont font;
		//font.CreateFontIndirectW(&pText->m_textFont);
		//CFont* pfntOld = pDC->SelectObject(&font);
		pDC->SetTextColor(pText->m_textColor);
		pDC->TextOutW(pText->m_textPos.x, pText->m_textPos.y, pText->m_strText);
		pDC->SelectObject(oldfont);

		m_CStorage.PushBack(pText->m_textPos, pText->m_strText, pText->m_textColor);
	}
}



CFont* CSingleDocumentApp10View::ChangePointFontStyle(CDC* pDC, LPSTR font_name, int height)
{
	CFont newFont;
	CString csFontName = CA2CT(font_name);
	VERIFY(newFont.CreatePointFont(height, csFontName));
	CFont* pOldFont = pDC->SelectObject(&newFont);
	
	return pOldFont;
}


// CSingleDocumentApp10View 打印

BOOL CSingleDocumentApp10View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSingleDocumentApp10View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSingleDocumentApp10View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CSingleDocumentApp10View 诊断

#ifdef _DEBUG
void CSingleDocumentApp10View::AssertValid() const
{
	CView::AssertValid();
}

void CSingleDocumentApp10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSingleDocumentApp10Doc* CSingleDocumentApp10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingleDocumentApp10Doc)));
	return (CSingleDocumentApp10Doc*)m_pDocument;
}
#endif //_DEBUG


// CSingleDocumentApp10View 消息处理程序


void CSingleDocumentApp10View::OnShowTextDlg()
{
	// TODO: 在此添加命令处理程序代码
	CTextDlg cdlg;
	//cdlg.DoModal();
	/*CTextDlg cdlg;
	
	if (cdlg.DoModal() == IDOK)
	{
		m_nX = cdlg.m_nX;
		m_nY = cdlg.m_nY;
		m_strText = cdlg.m_strText;
		
		nRgb = cdlg.nRgb;

		COLORREF cref = RGB(0, 0, 0);
		switch (nRgb)
		{
		case 0:
			cref = RGB(255, 0, 0);
			break;
		case 1:
			cref = RGB(0, 255, 0);
			break;
		case 2:
			cref = RGB(0, 0, 255);
			break;
		Default:
			cref = RGB(0, 0, 0);
			break;
		}
		
		
	}
	Invalidate(FALSE);*/
}


//void CSingleDocumentApp10View::OnLButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	//SetCapture();
//	if (m_bCursorFlag)
//	{
//		CChangeTextDlg ctdlg;
//		//ctdlg.m_strText = m_CStorage.m
//		if (IDOK == ctdlg.DoModal());
//	}
//	CView::OnLButtonUp(nFlags, point);
//}


BOOL CSingleDocumentApp10View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_bCursorFlag == TRUE)
	{
		::SetCursor(LoadCursorW(nullptr, IDC_HAND));
		return TRUE;
	}
	
	else
	{
		::SetCursor(LoadCursorW(nullptr, IDC_ARROW));
	}
	//return CView::OnSetCursor(pWnd, nHitTest, message);
	return FALSE;
}


void CSingleDocumentApp10View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if (m_CStorage.SearchStorage(point))
	{
		m_bCursorFlag = TRUE;
	}
	else
	{
		m_bCursorFlag = FALSE;
	}

	auto* pStatus = dynamic_cast<CMFCStatusBar*>(AfxGetApp()->m_pMainWnd->GetDescendantWindow(AFX_IDW_STATUS_BAR));
	if (pStatus)
	{
		CString msg;
		msg.Format(_T("(%4d, %4d)"), point.x, point.y);
		//pStatus->SetPaneText(1, msg);
		GetParent()->GetDescendantWindow(AFX_IDW_STATUS_BAR)->SetWindowText(msg);
	}
	CView::OnMouseMove(nFlags, point);
}


//void CSingleDocumentApp10View::OnLButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	
//}


void CSingleDocumentApp10View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_bCursorFlag)
	{
		auto* gr = m_CStorage.GetRecentInfo();

		if (gr == nullptr)
		{
			return;
		}
		CChangeTextDlg ctdlg;
		ctdlg.GetInit(gr->message, gr->point, gr->nRgb);
		//ctdlg.GetInitAfter();
		if (IDOK == ctdlg.DoModal())
		{
			CSingleDocumentApp10Doc* pDoc = GetDocument();
			ASSERT_VALID(pDoc);
			POSITION pos = pDoc->m_textList.GetHeadPosition();
			while (pos != nullptr)
			{
				auto* pText = dynamic_cast<CMyText*>(pDoc->m_textList.GetNext(pos));
				if (pText->m_textPos == gr->point)
				{
					pText->m_strText = ctdlg.m_strText;
					pText->m_textPos = CPoint(ctdlg.m_nX, ctdlg.m_nY);
					const int nRgb = ctdlg.nRgb;

					COLORREF cref;
					switch (nRgb)
					{
					case 0:
						cref = RGB(255, 0, 0);
						break;
					case 1:
						cref = RGB(0, 255, 0);
						break;
					case 2:
						cref = RGB(0, 0, 255);
						break;
					default:
						cref = RGB(0, 0, 0);
						break;
					}
					pText->m_textColor = cref;
				}
				m_CStorage.ChangeIndex(pText->m_textPos, pText->m_strText, pText->m_textColor);
			}
			RedrawWindow();
		}
	}
	CView::OnLButtonDblClk(nFlags, point);
}

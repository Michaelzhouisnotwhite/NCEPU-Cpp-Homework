// Draw Rectangle AppView.cpp : CDrawRectangleAppView 类的实现
//

// ReSharper disable CppParameterMayBeConst
#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Draw Rectangle App.h"
#endif

#include "Draw Rectangle AppDoc.h"
#include "Draw Rectangle AppView.h"

#ifdef _DEBUG
// ReSharper disable once CppInconsistentNaming
#define new DEBUG_NEW
#endif


#include "CRectAttribute.h"

#include "CRectangle.h"

#include "Line.h"
// CDrawRectangleAppView

IMPLEMENT_DYNCREATE(CDrawRectangleAppView, CView)

BEGIN_MESSAGE_MAP(CDrawRectangleAppView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawRectangleAppView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32772, &CDrawRectangleAppView::OnDrawRectencgle)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_LINE_TYPE, &CDrawRectangleAppView::OnLineType)
END_MESSAGE_MAP()

// CDrawRectangleAppView 构造/析构

// ReSharper disable once CppPossiblyUninitializedMember
CDrawRectangleAppView::CDrawRectangleAppView() // NOLINT(cppcoreguidelines-pro-type-member-init)
{
	// TODO: 在此处添加构造代码
	m_nPenType = 0;
	m_PenColor = RGB(0, 0, 0);
	m_nPenWidth = 1;

	m_nFillPattern = -1;
	m_FillColor = RGB(255, 255, 255);
}

CDrawRectangleAppView::~CDrawRectangleAppView()
{
}

BOOL CDrawRectangleAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawRectangleAppView 绘制

void CDrawRectangleAppView::OnDraw(CDC* pDC)
{
	CDrawRectangleAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	POSITION pos = pDoc->m_FigureList.GetHeadPosition();
	while (pos != nullptr)
	{
		auto pRectangle = new CRectangle(m_StartPos, m_EndPos, m_nPenWidth, m_nPenType, m_PenColor, m_nFillPattern,
		                                 m_FillColor);
		pRectangle->Draw(pDC);
		pDoc->m_FigureList.AddTail(pRectangle);
	}
}


// CDrawRectangleAppView 打印


void CDrawRectangleAppView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawRectangleAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawRectangleAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawRectangleAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDrawRectangleAppView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawRectangleAppView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawRectangleAppView 诊断

#ifdef _DEBUG
void CDrawRectangleAppView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawRectangleAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawRectangleAppDoc* CDrawRectangleAppView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawRectangleAppDoc)));
	return (CDrawRectangleAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawRectangleAppView 消息处理程序


void CDrawRectangleAppView::OnDrawRectencgle()
{
	// TODO: 在此添加命令处理程序代码
	m_nMouseStep = 0;
	m_nDrawOption = 0;
	m_hCursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
}


void CDrawRectangleAppView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (0 == m_nDrawOption)
	{
		CDC* pDc = GetDC();
		m_nDrawMode = pDc->SetROP2(R2_NOT);
		if (!m_bFinished)
		{
			CPoint pr_o(m_EndPos.x, m_StartPos.y);
			CPoint pr_n(point.x, m_StartPos.y);

			CPoint pl_o(m_StartPos.x, m_EndPos.y);
			CPoint pl_n(m_StartPos.x, point.y);

			// CRect rect;
			// GetClientRect(&rect);
			// rect.InflateRect(m_StartPos.x, m_StartPos.y, m_EndPos.x, m_EndPos.y);
			// pDc->Rectangle(rect);
			//
			// rect.InflateRect(m_StartPos.x, m_StartPos.y, point.x, point.y);
			// pDc->Rectangle(rect);
			pDc->MoveTo(m_StartPos);
			pDc->LineTo(pr_o);
			pDc->MoveTo(m_StartPos);
			pDc->LineTo(pr_n);

			pDc->MoveTo(m_StartPos);
			pDc->LineTo(pl_o);
			pDc->MoveTo(m_StartPos);
			pDc->LineTo(pl_n);

			pDc->MoveTo(pr_o);
			pDc->LineTo(m_EndPos);
			pDc->MoveTo(pr_n);
			pDc->LineTo(point);

			pDc->MoveTo(pl_o);
			pDc->LineTo(m_EndPos);
			pDc->MoveTo(pl_n);
			pDc->LineTo(point);
			// pDc->Rectangle(m_StartPos.x, m_StartPos.y, point.x, point.y);
			m_EndPos = point;
			ReleaseDC(pDc);
		}
	}

	CView::OnMouseMove(nFlags, point);
}


void CDrawRectangleAppView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (0 == m_nDrawOption)
	{
		SetCapture();
		::SetCursor(m_hCursor);
		m_StartPos = m_EndPos = point;
		m_bFinished = FALSE;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CDrawRectangleAppView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC* pDc = GetDC();
	CDrawRectangleAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (0 == m_nDrawOption)
	{
		// auto pPen = new CPen(m_nPenType, m_nPenWidth, m_PenColor);
		// auto pOldPen = pDc->SelectObject(pPen);
		// CPoint pr(m_EndPos.x, m_StartPos.y);
		// CPoint pl(m_StartPos.x, m_EndPos.y);
		m_EndPos = point;

		auto pRectangle = new CRectangle(m_StartPos, m_EndPos, m_nPenType, m_nPenType, m_PenColor, m_nFillPattern,
		                                 m_FillColor);
		pRectangle->Draw(pDc);
		pDoc->m_FigureList.AddTail(pRectangle);
		// {
		// 	auto pLine = new CLine(m_StartPos, pr);
		// 	pLine->Draw(pDc);
		// 	pDoc->m_FigureList.AddTail(pLine);
		// }
		//
		// {
		// 	auto pLine = new CLine(pr, m_EndPos);
		// 	pLine->Draw(pDc);
		// 	pDoc->m_FigureList.AddTail(pLine);
		// }
		//
		// {
		// 	auto pLine = new CLine(m_StartPos, pl);
		// 	pLine->Draw(pDc);
		// 	pDoc->m_FigureList.AddTail(pLine);
		// }
		//
		// {
		// 	auto pLine = new CLine(pl, m_EndPos);
		// 	pLine->Draw(pDc);
		// 	pDoc->m_FigureList.AddTail(pLine);
		// }
		m_bFinished = TRUE;

		// pDc->SelectObject(pOldPen);
		// delete pPen;
	}
	ReleaseCapture();
	ReleaseDC(pDc);
	CView::OnLButtonUp(nFlags, point);
}


void CDrawRectangleAppView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_bFinished = TRUE;
	m_nDrawOption = -1;
	CView::OnLButtonDblClk(nFlags, point);
}


void CDrawRectangleAppView::OnLineType()
{
	// TODO: 在此添加命令处理程序代码
	CRectAttribute cadlg;
	if (IDOK == cadlg.DoModal())
	{
		m_nPenType = cadlg.m_nLineType;
		m_nPenWidth = cadlg.m_nLineWith;
		m_PenColor = cadlg.m_lineColor;
		m_nFillPattern = cadlg.m_nFillPattern;
		m_FillColor = cadlg.m_FillColor;
	}
}

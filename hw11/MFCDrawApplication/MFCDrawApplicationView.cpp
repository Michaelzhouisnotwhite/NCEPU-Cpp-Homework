// MFCDrawApplicationView.cpp: CMFCDrawApplicationView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCDrawApplication.h"
#endif

#include "MFCDrawApplicationDoc.h"
#include "MFCDrawApplicationView.h"
#include "Line.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDrawApplicationView

IMPLEMENT_DYNCREATE(CMFCDrawApplicationView, CView)

BEGIN_MESSAGE_MAP(CMFCDrawApplicationView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFCDrawApplicationView::OnLineMenu)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_32772, &CMFCDrawApplicationView::OnRectangleMenu)
END_MESSAGE_MAP()

// CMFCDrawApplicationView 构造/析构

CMFCDrawApplicationView::CMFCDrawApplicationView() noexcept
{
	// TODO: 在此处添加构造代码
	m_nMouseStep = 0;
}

CMFCDrawApplicationView::~CMFCDrawApplicationView()
{
}

BOOL CMFCDrawApplicationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCDrawApplicationView 绘图

void CMFCDrawApplicationView::OnDraw(CDC* pDc)
{
	CMFCDrawApplicationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	POSITION pos = pDoc->m_FigureList.GetHeadPosition();
	while (pos != nullptr)
	{
		auto* pFigure = static_cast<CLine*>(pDoc->m_FigureList.GetNext(pos));
		pFigure->Draw(pDc);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCDrawApplicationView 打印

BOOL CMFCDrawApplicationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCDrawApplicationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCDrawApplicationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCDrawApplicationView 诊断

#ifdef _DEBUG
void CMFCDrawApplicationView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDrawApplicationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDrawApplicationDoc* CMFCDrawApplicationView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDrawApplicationDoc)));
	return dynamic_cast<CMFCDrawApplicationDoc*>(m_pDocument);
}
#endif //_DEBUG


// CMFCDrawApplicationView 消息处理程序


void CMFCDrawApplicationView::OnLineMenu()
{
	// TODO: 在此添加命令处理程序代码
	m_hCursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
	SetCursor(m_hCursor);
	m_nDrawChoose = 0;
}


void CMFCDrawApplicationView::InitDrawChoose()
{
	m_nDrawChoose = -1;
}

void CMFCDrawApplicationView::OnLButtonDown(const UINT nFlags, const CPoint point)
{
	CMFCDrawApplicationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (-1 == m_nDrawChoose)
	{
		return;
	}
	
	SetCapture();
	SetCursor(m_hCursor);
	CDC* pDc = GetDC();
	if (0 == m_nDrawChoose)
	{
		switch (m_nMouseStep)
		{
		case 0:
			m_StartPos = m_EndPos = point;
			m_nMouseStep ++;
			break;
		case 1:
			m_EndPos = point;
			m_nMouseStep = 0;
			// pDc->MoveTo(m_StartPos);
			// pDc->LineTo(m_EndPos);
			auto* pLine = new CLine(m_StartPos, m_EndPos);
			pLine->Draw(pDc);
			pDoc->m_FigureList.AddTail(pLine);
			ReleaseCapture();
			// default: ;
		}
	}
	else if (1 == m_nDrawChoose)
	{
		if (m_nMouseStep == 0)
		{
			m_nInitStartPos = point;
		}
		if (0 == m_nMouseStep)
		{
			m_StartPos = m_EndPos = point;
			m_nMouseStep ++;
		}
		else if (1 <= m_nMouseStep)
		{
			m_EndPos = point;
			m_nMouseStep++;
			auto* pLine = new CLine(m_StartPos, m_EndPos);
			pLine->Draw(pDc);
			pDoc->m_FigureList.AddTail(pLine);

			m_StartPos = m_EndPos;
		}
		if (3 == m_nMouseStep)
		{
			// pDc->MoveTo(m_StartPos);
			// pDc->LineTo(m_nInitStartPos);

			auto* pLine = new CLine(m_StartPos, m_nInitStartPos);
			pLine->Draw(pDc);
			pDoc->m_FigureList.AddTail(pLine);

			m_nMouseStep = 0;
			ReleaseCapture();
		}
	}

	ReleaseDC(pDc);
	CView::OnLButtonDown(nFlags, point);
}


void CMFCDrawApplicationView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC* pDc = GetDC();
	m_nDrawMode = pDc->SetROP2(R2_NOT);
	if (1 <= m_nMouseStep)
	{
		// m_EndPos = point;
		pDc->MoveTo(m_StartPos);
		pDc->LineTo(m_EndPos);
		pDc->MoveTo(m_StartPos);
		pDc->LineTo(point);
		m_EndPos = point;
	}
	CView::OnMouseMove(nFlags, point);
}


void CMFCDrawApplicationView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ReleaseCapture();
	InitDrawChoose();
	m_nMouseStep = 0;
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFCDrawApplicationView::OnRectangleMenu()
{
	// TODO: 在此添加命令处理程序代码
	m_hCursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
	SetCursor(m_hCursor);
	m_nDrawChoose = 1;
}

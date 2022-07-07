
// Draw Rectangle AppView.h : CDrawRectangleAppView 类的接口
//

#pragma once


class CDrawRectangleAppView : public CView
{
protected: // 仅从序列化创建
	CDrawRectangleAppView();
	DECLARE_DYNCREATE(CDrawRectangleAppView)

// 特性
public:
	CDrawRectangleAppDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDrawRectangleAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CPoint m_StartPos, m_EndPos;
	int m_nMouseStep;
	int m_nDrawOption;
	HCURSOR m_hCursor;
	afx_msg void OnDrawRectencgle();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	BOOL m_bFinished;
	int m_nDrawMode;
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);

	afx_msg void OnLineType();

	int m_nPenType;
	int m_nPenWidth;
	COLORREF m_PenColor;

	int m_nFillPattern;
	COLORREF m_FillColor;
};

#ifndef _DEBUG  // Draw Rectangle AppView.cpp 中的调试版本
inline CDrawRectangleAppDoc* CDrawRectangleAppView::GetDocument() const
   { return reinterpret_cast<CDrawRectangleAppDoc*>(m_pDocument); }
#endif



// MFCDrawApplicationView.h: CMFCDrawApplicationView 类的接口
//

#pragma once


class CMFCDrawApplicationView : public CView
{
protected: // 仅从序列化创建
	CMFCDrawApplicationView() noexcept;
	DECLARE_DYNCREATE(CMFCDrawApplicationView)

// 特性
public:
	CMFCDrawApplicationDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDc);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCDrawApplicationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLineMenu();
	int m_nMouseStep;
	CPoint m_StartPos, m_EndPos;
	HCURSOR m_hCursor;

	int m_nDrawChoose = -1;
	void InitDrawChoose();
	int m_nDrawMode;
	CPoint m_nInitStartPos;
	
	
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRectangleMenu();
};

#ifndef _DEBUG  // MFCDrawApplicationView.cpp 中的调试版本
inline CMFCDrawApplicationDoc* CMFCDrawApplicationView::GetDocument() const
   { return reinterpret_cast<CMFCDrawApplicationDoc*>(m_pDocument); }
#endif


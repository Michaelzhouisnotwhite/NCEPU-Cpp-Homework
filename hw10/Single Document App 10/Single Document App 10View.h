
// Single Document App 10View.h: CSingleDocumentApp10View 类的接口
//

#pragma once


class CSingleDocumentApp10View : public CView
{
protected: // 仅从序列化创建
	CSingleDocumentApp10View() noexcept;
	DECLARE_DYNCREATE(CSingleDocumentApp10View)

// 特性
public:
	CSingleDocumentApp10Doc* GetDocument() const;

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
	virtual ~CSingleDocumentApp10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowTextDlg();
	int m_nX;
	int m_nY;
	int nRgb;
	CString m_strText;
	COLORREF m_TextColor;
	CFont* ChangePointFontStyle(CDC* pDC, LPSTR font_name, int height);
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	CPoint m_MousePos;
	BOOL m_bCursorFlag = FALSE;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	CStorageTextInfo m_CStorage;
	
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Single Document App 10View.cpp 中的调试版本
inline CSingleDocumentApp10Doc* CSingleDocumentApp10View::GetDocument() const
   { return reinterpret_cast<CSingleDocumentApp10Doc*>(m_pDocument); }
#endif


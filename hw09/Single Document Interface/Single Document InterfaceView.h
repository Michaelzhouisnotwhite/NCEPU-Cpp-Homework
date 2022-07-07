
// Single Document InterfaceView.h : interface of the CSingleDocumentInterfaceView class
//

#pragma once
#include "ChangeColorDlg.h"

class CSingleDocumentInterfaceView : public CView
{
protected: // create from serialization only
	CSingleDocumentInterfaceView() noexcept;
	DECLARE_DYNCREATE(CSingleDocumentInterfaceView)

// Attributes
public:
	CSingleDocumentInterfaceDoc* GetDocument() const;

// Operations
public:
	CFont* ChangePointFontStyle(CDC *pDC, LPSTR font_name, int height);
	void ChangeTextColor(CDC* pDC, int r, int g, int b);
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
	virtual ~CSingleDocumentInterfaceView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFontDlgMenu();
	afx_msg void OnFontcolordlgMenu();
	COLORREF m_TextColor;
	CFont m_font;
	
};

#ifndef _DEBUG  // debug version in Single Document InterfaceView.cpp
inline CSingleDocumentInterfaceDoc* CSingleDocumentInterfaceView::GetDocument() const
   { return reinterpret_cast<CSingleDocumentInterfaceDoc*>(m_pDocument); }
#endif


#pragma once
#include <afxdialogex.h>
#include <afxwin.h>


// CRectAttribute 对话框

class CDataExchange;

class CRectAttribute : public CDialogEx
{
	DECLARE_DYNAMIC(CRectAttribute);

public:
	CRectAttribute(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CRectAttribute();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = LINE_ATTRIBUTE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP();
public:
//	CComboBox m_LineWith;
//	CComboBox m_lineType;
	int m_nLineType;
	
	COLORREF m_lineColor;
	BOOL OnInitDialog() override;
	afx_msg void OnCbnSelchangeCombxLineType();
	afx_msg void OnBnClickedOk();
	void GetLineType();
	afx_msg void OnBnClickedBtnPencolor();
	void GetLineWith();
	int m_nLineWith;
	afx_msg void OnBnClickedBtnBrushColor();


	COLORREF m_FillColor;
	int m_nFillPattern;
	
	afx_msg void OnLbnSelchangeListPatten();
};

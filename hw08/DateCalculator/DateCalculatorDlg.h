
// DateCalculatorDlg.h: 头文件
//

#pragma once


// CDateCalculatorDlg 对话框
class CDateCalculatorDlg : public CDialogEx
{
// 构造
public:
	CDateCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DATECALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
protected:
	// year
	CComboBox years;
	CComboBox months;
	CComboBox days;
public:
	afx_msg void OnSelchangeCombo1();
protected:
	// 1、能被4整除，但不能被100整除；2、能被400整除；
	bool IfLeapYear(int year);
	int ChangeFebDay();
public:
	afx_msg void OnSelchangeCombo2();
	afx_msg void OnSelchangeCombo3();
protected:
	bool ifLeapYear;
	int ResetDays();
	int ChangeSmallMonth();
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	CEdit output;
protected:
	int getCurSel(CComboBox &);
};

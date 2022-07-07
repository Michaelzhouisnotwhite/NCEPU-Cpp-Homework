
// StandardCalculatorDlg.h : header file
//

#pragma once
//typedef signed __int128 INT128;


// CStandardCalculatorDlg dialog
class CStandardCalculatorDlg : public CDialogEx
{
// Construction
public:
	CStandardCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STANDARDCALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	// Number
	CButton btn_n1;
	CButton btn_n2;
	CButton btn_n3;
	CButton btn_n4;
	CButton btn_n5;
	CButton btn_n6;
	CButton btn_n7;
	CButton btn_n8;
	CButton btn_n9;
	CButton btn_n0;
	CButton btn_n00;
	CButton btn_clear;
	CButton btn_del;
	CButton btn_multiply;
	CButton btn_div;
	CButton btn_minus;
	CButton btn_dot;
	CButton btn_eq;
	afx_msg void OnBnClickedButtonNum0();
	CEdit ouyput_e;
	CString display_value;
	afx_msg void OnBnClickedButtonNum00();
	afx_msg void OnBnClickedButtonNum7();
	afx_msg void OnBnClickedButtonNum8();
	afx_msg void OnBnClickedButtonNum9();
	afx_msg void OnBnClickedButtonNum4();
	afx_msg void OnBnClickedButtonNum5();
	afx_msg void OnBnClickedButtonNum6();
	afx_msg void OnBnClickedButtonNum1();
	afx_msg void OnBnClickedButtonNum2();
	afx_msg void OnBnClickedButtonNum3();
	CFont font;
	CFont font_s;
	afx_msg void OnEnChangeOutputedit();
	int CancelInit();
	CEdit output_s;
	afx_msg void OnBnClickedMultiplyButton();
	CString display_s;
	afx_msg void OnBnClickedDiviceButton();
	afx_msg void OnBnClickedMinusButton();
	afx_msg void OnBnClickedPlusButton();
	afx_msg void OnBnClickedEqualButton();
	afx_msg void OnBnClickedButtonNumdot();
	//__int128 a;
};

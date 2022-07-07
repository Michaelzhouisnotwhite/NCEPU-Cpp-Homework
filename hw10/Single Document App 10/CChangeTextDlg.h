#pragma once


// CChangeTextDlg 对话框
#include <vector>
using namespace std;
class CChangeTextDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeTextDlg)

public:
	CChangeTextDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CChangeTextDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGETEXT_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strText;
	int m_nX;
	int m_nY;
	CButton m_bR;
	CButton m_bG;
	CButton m_bB;

	int nRgb;
	CPoint m_point;

	void GetInit(CString text, CPoint pos, int nRgb);
	afx_msg void OnBnClickedOk();

	void GetInitAfter();
//	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};

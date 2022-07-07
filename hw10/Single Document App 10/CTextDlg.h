#pragma once


// CTextDlg 对话框

class CTextDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTextDlg)

public:
	CTextDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTextDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnAddText();
	afx_msg void OnBnClickedRadio2();
//	CEdit m_strText;
//	CEdit m_nX;
//	CEdit m_nY;
//	CString m_nX;
	int m_nY = 10;
	int m_nX = 10;
	CButton m_R;
	CButton m_G;
	CButton m_B;
	afx_msg void OnBnClickedOk();
	int nRgb;
	CString m_strText;
};

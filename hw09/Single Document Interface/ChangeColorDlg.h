#pragma once


// ChangeColorDlg 对话框

class ChangeColorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChangeColorDlg)

public:
	ChangeColorDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChangeColorDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// blue
//	CButton radio_btn_b;
//	CButton radio_btn_g;
//	CButton radio_btn_r;
	afx_msg void OnBnClickedOk();
	CButton check_btn_r;
	CButton check_btn_g;
	CButton check_btn_b;

	int r_push;
	int g_push;
	int b_push;
};

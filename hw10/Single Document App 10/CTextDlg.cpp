// CTextDlg.cpp: 实现文件
//

#include "pch.h"
#include "Single Document App 10.h"
#include "CTextDlg.h"
#include "afxdialogex.h"


// CTextDlg 对话框

IMPLEMENT_DYNAMIC(CTextDlg, CDialogEx)

CTextDlg::CTextDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_nY(0)
	, m_nX(0)
	, m_strText(_T(""))
{

	nRgb = 0;
}

CTextDlg::~CTextDlg()
{
}

void CTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_strText);
	//  DDX_Control(pDX, IDC_EDIT2, m_nX);
	//  DDX_Control(pDX, IDC_EDIT3, m_nY);
	DDX_Text(pDX, IDC_EDIT2, m_nX);
	DDX_Text(pDX, IDC_EDIT3, m_nY);
	DDX_Control(pDX, IDC_RADIO1, m_R);
	DDX_Control(pDX, IDC_RADIO2, m_G);
	DDX_Control(pDX, IDC_RADIO3, m_B);
	DDX_Text(pDX, IDC_EDIT1, m_strText);
}


BEGIN_MESSAGE_MAP(CTextDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO2, &CTextDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDOK, &CTextDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTextDlg 消息处理程序


//void CTextDlg::OnAddText()
//{
//	// TODO: 在此添加命令处理程序代码
//}


void CTextDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CTextDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_R.GetCheck())
	{
		nRgb = 0;
	}
	if (m_G.GetCheck())
	{
		nRgb = 1;
	}
	if (m_B.GetCheck())
	{
		nRgb = 2;
	}
	CDialogEx::OnOK();
}

// ChangeColorDlg.cpp: 实现文件
//

#include "pch.h"
#include "Single Document Interface.h"
#include "ChangeColorDlg.h"
#include "afxdialogex.h"


// ChangeColorDlg 对话框

IMPLEMENT_DYNAMIC(ChangeColorDlg, CDialogEx)

ChangeColorDlg::ChangeColorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG, pParent)
{

}

ChangeColorDlg::~ChangeColorDlg()
{

}

void ChangeColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, check_btn_r);
	DDX_Control(pDX, IDC_CHECK2, check_btn_g);
	DDX_Control(pDX, IDC_CHECK3, check_btn_b);
}


BEGIN_MESSAGE_MAP(ChangeColorDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &ChangeColorDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ChangeColorDlg 消息处理程序


void ChangeColorDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	r_push = check_btn_r.GetCheck();
	g_push = check_btn_g.GetCheck();
	b_push = check_btn_b.GetCheck();
}

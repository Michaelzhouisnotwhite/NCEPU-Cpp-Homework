// CChangeTextDlg.cpp: 实现文件
//

#include "pch.h"
#include "Single Document App 10.h"
#include "CChangeTextDlg.h"
#include "afxdialogex.h"
#include "CTextDlg.h"
#include <vector>


// CChangeTextDlg 对话框

IMPLEMENT_DYNAMIC(CChangeTextDlg, CDialogEx)

CChangeTextDlg::CChangeTextDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHANGETEXT_DLG, pParent)
	, m_strText(_T(""))
	, m_nX(0)
	, m_nY(0)
{

}

CChangeTextDlg::~CChangeTextDlg()
{
}

void CChangeTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT, m_strText);
	DDX_Text(pDX, IDC_EDIT_X, m_nX);
	DDX_Text(pDX, IDC_EDIT_Y, m_nY);
	DDX_Control(pDX, IDC_RADIO1, m_bR);
	DDX_Control(pDX, IDC_RADIO2, m_bG);
	DDX_Control(pDX, IDC_RADIO3, m_bB);
}

void CChangeTextDlg::GetInit(CString text, CPoint pos, int nRgb)
{
	m_strText = text;
	m_nX = pos.x;
	m_nY = pos.y;

	this->nRgb = nRgb;

	/*switch (this->nRgb)
	{
	case 0:
		m_bR.SetCheck(BST_CHECKED);
		break;
	case 1:
		m_bG.SetCheck(TRUE);
		break;
	case 2:
		m_bR.SetCheck(0);
		if (1);
		m_bG.SetCheck(0);
		if (1);
		m_bB.SetCheck(1);
		break;
	default:
		m_bR.SetCheck(0);
		m_bG.SetCheck(0);
		m_bB.SetCheck(0);
		break;
	}*/
	this->nRgb = nRgb;

	//UpdateData(FALSE);
}

BEGIN_MESSAGE_MAP(CChangeTextDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CChangeTextDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CChangeTextDlg 消息处理程序


void CChangeTextDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_bR.GetCheck())
	{
		nRgb = 0;
	}
	if (m_bG.GetCheck())
	{
		nRgb = 1;
	}
	if (m_bB.GetCheck())
	{
		nRgb = 2;
	}
	CDialogEx::OnOK();
}

void CChangeTextDlg::GetInitAfter()
{
	//((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
	switch (this->nRgb)
	{
	case 0:
		m_bR.SetCheck(TRUE);
		m_bG.SetCheck(FALSE);
		m_bB.SetCheck(FALSE);
		break;
	case 1:
		m_bR.SetCheck(FALSE);
		m_bG.SetCheck(TRUE);
		m_bB.SetCheck(FALSE);
		break;
	case 2:
		m_bR.SetCheck(FALSE);
		m_bG.SetCheck(FALSE);
		m_bB.SetCheck(TRUE);
		break;
	default:
		m_bR.SetCheck(FALSE);
		m_bG.SetCheck(FALSE);
		m_bB.SetCheck(FALSE);
		break;
	}
	UpdateData(FALSE);
}

//void CChangeTextDlg::OnBnClickedButton1()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
//}


BOOL CChangeTextDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetInitAfter();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

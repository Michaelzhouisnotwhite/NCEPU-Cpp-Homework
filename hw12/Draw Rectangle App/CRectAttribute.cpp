// CRectAttribute.cpp: 实现文件
//

// #include "pch.h"
#include "stdafx.h"
#include "Draw Rectangle App.h"
#include "CRectAttribute.h"
#include "afxdialogex.h"

#include <string>

// CRectAttribute 对话框

IMPLEMENT_DYNAMIC(CRectAttribute, CDialogEx)

CRectAttribute::CRectAttribute(CWnd* pParent /*=nullptr*/)
	: CDialogEx(LINE_ATTRIBUTE, pParent)
	  , m_nLineWith(0)
{
}

CRectAttribute::~CRectAttribute()
{
}

void CRectAttribute::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, ID_COMBX_LINE_WIDTH, m_LineWith);
	//  DDX_Control(pDX, ID_COMBX_LINE_TYPE, m_lineType);
	DDX_Text(pDX, IDC_EDIT1, m_nLineWith);
}


BEGIN_MESSAGE_MAP(CRectAttribute, CDialogEx)
	ON_CBN_SELCHANGE(ID_COMBX_LINE_TYPE, &CRectAttribute::OnCbnSelchangeCombxLineType)
	ON_BN_CLICKED(IDOK, &CRectAttribute::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_PENCOLOR, &CRectAttribute::OnBnClickedBtnPencolor)
	ON_BN_CLICKED(IDC_BTN_BRUSH_COLOR, &CRectAttribute::OnBnClickedBtnBrushColor)
	ON_LBN_SELCHANGE(IDC_LIST_PATTEN, &CRectAttribute::OnLbnSelchangeListPatten)
END_MESSAGE_MAP()


// CRectAttribute 消息处理程序


BOOL CRectAttribute::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	auto m_lineType = static_cast<CComboBox*>(GetDlgItem(ID_COMBX_LINE_TYPE));
	auto m_listFill = static_cast<CListBox*>(GetDlgItem(IDC_LIST_PATTEN));
	// TODO:  在此添加额外的初始化
	std::string sLineType[] = {{"实线"}, {"虚线"}, {"点线"}, {"点划线"}, {"双点划线"}};
	for (auto lineType : sLineType)
	{
		CString tmp_str;
		tmp_str = CA2T(lineType.c_str());
		m_lineType->AddString(tmp_str);
	}
	m_lineType->SetCurSel(0);


	std::string sRectPatten[] = {
		{"纯色"}, {"水平阴影线"}, {"垂直阴影线"}, {"45度左上－右下阴影线"}, {"45度左下－右上阴影线"}, {"垂直相交阴影线"}, {"45度叉线"}
	};
	for (auto rectPatten : sRectPatten)
	{
		CString tmp_str;
		tmp_str = CA2T(rectPatten.c_str());
		m_listFill->AddString(tmp_str);
	}
	m_listFill->SetCurSel(0);

	m_FillColor = RGB(255, 255, 255);
	m_nFillPattern = -1;
	m_lineColor = RGB(0, 0, 0);
	UpdateData(FALSE);

	return TRUE; // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRectAttribute::OnCbnSelchangeCombxLineType()
{
	// TODO: 在此添加控件通知处理程序代码
	GetLineType();
}


void CRectAttribute::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CRectAttribute::GetLineType()
{
	// TODO: 在此处添加实现代码.
	auto cbLineType = static_cast<CComboBox*>(GetDlgItem(ID_COMBX_LINE_TYPE));
	int index = cbLineType->GetCurSel();
	switch (index)
	{
	case 0:
		m_nLineType = PS_SOLID;
		break;
	case 1:
		m_nLineType = PS_DASH;
		break;
	case 2:
		m_nLineType = PS_DOT;
		break;
	case 3:
		m_nLineType = PS_DASHDOT;
		break;
	case 4:
		m_nLineType = PS_DASHDOTDOT;
		break;
	default:
		m_lineColor = PS_SOLID;
	}
}


void CRectAttribute::OnBnClickedBtnPencolor()
{
	// TODO: 在此添加控件通知处理程序代码
	CColorDialog colorDlg;
	if (colorDlg.DoModal() == IDOK)
	{
		m_lineColor = colorDlg.GetColor();
	}
}

void CRectAttribute::GetLineWith()
{
}


void CRectAttribute::OnBnClickedBtnBrushColor()
{
	// TODO: 在此添加控件通知处理程序代码
	CColorDialog colorDlg;
	if (IDOK == colorDlg.DoModal())
	{
		m_FillColor = colorDlg.GetColor();
	}
}


void CRectAttribute::OnLbnSelchangeListPatten()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = static_cast<CListBox*>(GetDlgItem(IDC_LIST_PATTEN))->GetCurSel();
	switch (nIndex)
	{
	case 0:
		m_nFillPattern = -1;
		break;
	case 1: m_nFillPattern = HS_HORIZONTAL;
		break; //水平阴影线
	case 2: m_nFillPattern = HS_VERTICAL;
		break; //垂直阴影线
	case 3: m_nFillPattern = HS_FDIAGONAL;
		break;
		//45度左上－右下阴影线   
	case 4: m_nFillPattern = HS_BDIAGONAL;
		break;
		//45度左下－右上阴影线       
	case 5: m_nFillPattern = HS_CROSS;
		break; //水平垂直相交阴影线
	case 6: m_nFillPattern = HS_DIAGCROSS;
		break; //45度叉线      
	default: break;
	}
}

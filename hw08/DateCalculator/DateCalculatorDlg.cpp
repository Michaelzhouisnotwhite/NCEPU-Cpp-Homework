// DateCalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "DateCalculator.h"
#include "DateCalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDateCalculatorDlg 对话框



CDateCalculatorDlg::CDateCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DATECALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDateCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, years);
	DDX_Control(pDX, IDC_COMBO2, months);
	DDX_Control(pDX, IDC_COMBO3, days);
	DDX_Control(pDX, IDC_EDIT1, output);
}



BEGIN_MESSAGE_MAP(CDateCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDateCalculatorDlg::OnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CDateCalculatorDlg::OnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CDateCalculatorDlg::OnSelchangeCombo3)
	ON_EN_CHANGE(IDC_EDIT1, &CDateCalculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CDateCalculatorDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDateCalculatorDlg 消息处理程序

BOOL CDateCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	int year_num = 2000;
	
	for (int i = 0; i < 99; i++) {
		CString tmp;
		tmp.Format(_T("%d"), year_num + i);
		years.AddString(tmp);
	}
	years.SetCurSel(0);
	for (int month = 1; month <= 12; month++) {
		CString tmp;
		tmp.Format(_T("%d"), month);
		months.AddString(tmp);
	}
	months.SetCurSel(0);

	for (int day = 1; day <= 31; day++) {
		CString tmp;
		tmp.Format(_T("%d"), day);
		days.AddString(tmp);
	}
	days.SetCurSel(0);
	//ifLeapYear = true;
	int year_int = getCurSel(years);
	ifLeapYear = IfLeapYear(year_int);
	
	//output.SetSel()

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDateCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDateCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDateCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDateCalculatorDlg::OnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	int year_int = getCurSel(years);
	ifLeapYear = IfLeapYear(year_int);

	int big_month[] = { 1, 3, 5, 7, 8, 10, 12 };
	int small_month[] = { 4, 6, 9, 11 };

	CString month_cstr;

	int month_int = getCurSel(months);
	if (month_int == 2) {
		ResetDays();
		ChangeFebDay();
	}
	for (int m : small_month) {
		if (m == month_int) {
			ResetDays();
			ChangeSmallMonth();
		}
	}
	for (int m : big_month) {
		if (m == month_int) {
			ResetDays();
		}
	}
}

// 1、能被4整除，但不能被100整除；2、能被400整除；
bool CDateCalculatorDlg::IfLeapYear(int year)
{
	// TODO: Add your implementation code here.
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	}
	else
		return false;
}


int CDateCalculatorDlg::ChangeFebDay()
{
	// TODO: Add your implementation code here.


	if (ifLeapYear) {
		CString d[] = { _T("30"), _T("31")};
		for (CString str : d) {
			int nItem = 0;
			while ((nItem = days.FindString(nItem, str)) != CB_ERR)
			{
				days.DeleteString(nItem);
			}
		}
	} else {
		CString d[] = { _T("29"), _T("30"), _T("31") };
		for (CString str : d) {
			int nItem = 0;
			while ((nItem = days.FindString(nItem, str)) != CB_ERR)
			{
				days.DeleteString(nItem);
			}
		}
	}
	return 0;
}



void CDateCalculatorDlg::OnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
	int big_month[] = { 1, 3, 5, 7, 8, 10, 12 };
	int small_month[] = { 4, 6, 9, 11 };

	CString month_cstr;

	int month_int = getCurSel(months);
	if (month_int == 2) {
		ResetDays();
		ChangeFebDay();
	}
	for (int m : small_month) {
		if (m == month_int) {
			ResetDays();
			ChangeSmallMonth();
		}
	}
	for (int m : big_month) {
		if (m == month_int) {
			ResetDays();
		}
	}
}


void CDateCalculatorDlg::OnSelchangeCombo3()
{
	// TODO: Add your control notification handler code here
}


int CDateCalculatorDlg::ResetDays()
{
	// TODO: Add your implementation code here.
	CString d[] = { _T("29"), _T("30"), _T("31") };
	for (CString str : d) {
		int nItem = 0;
		while ((nItem = days.FindString(nItem, str)) == CB_ERR)
		{
			days.AddString(str);
		}
	}
	return 0;
}


int CDateCalculatorDlg::ChangeSmallMonth()
{
	// TODO: Add your implementation code here.
	CString d = _T("31");


	int nItem = 0;
	while ((nItem = days.FindString(nItem, d)) != CB_ERR)
	{
		days.DeleteString(nItem);
	}
	return 0;
}


void CDateCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CDateCalculatorDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	int month_int = getCurSel(months);

	int day_int = getCurSel(days);

	int length = 0;

	int* total_days_per_months = new int[12];
	int big_month[] = { 1, 3, 5, 7, 8, 10, 12 };
	int small_month[] = { 4, 6, 9, 11 };
	for (int i = 1; i < month_int; i++)
	{
		for (int m : big_month) {
			if (m == i) {
				length += 31;
			}
		}
		for (int m : small_month) {
			if (m == i) {
				length += 30;
			}
		}
		if (i == 2) {
			if (ifLeapYear) {
				length += 29;
			}
			else {
				length += 28;
			}
		}
	}
	length += day_int;
	CString length_cstr;
	length_cstr.Format(_T("该天是一年中的第%d天"), length);
	output.SetWindowTextW(length_cstr);
}


int CDateCalculatorDlg::getCurSel(CComboBox &cb)
{
	// TODO: 在此处添加实现代码.
	int index = cb.GetCurSel();
	CString cstr;
	cb.GetLBText(index, cstr);
	int t_int = _ttoi(cstr);
	return t_int;
}

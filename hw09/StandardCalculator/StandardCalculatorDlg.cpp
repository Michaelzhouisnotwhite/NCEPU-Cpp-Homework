
// StandardCalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "StandardCalculator.h"
#include "StandardCalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CStandardCalculatorDlg dialog



CStandardCalculatorDlg::CStandardCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STANDARDCALCULATOR_DIALOG, pParent)
	, display_value('0')
	, display_s(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStandardCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_NUM0, btn_n0);
	DDX_Control(pDX, IDC_BUTTON_NUM00, btn_n00);
	DDX_Control(pDX, IDC_BUTTON_NUM1, btn_n1);
	DDX_Control(pDX, IDC_BUTTON_NUM2, btn_n2);
	DDX_Control(pDX, IDC_BUTTON_NUM3, btn_n3);
	DDX_Control(pDX, IDC_BUTTON_NUM4, btn_n4);
	DDX_Control(pDX, IDC_BUTTON_NUM5, btn_n5);
	DDX_Control(pDX, IDC_BUTTON_NUM6, btn_n6);
	DDX_Control(pDX, IDC_BUTTON_NUM7, btn_n7);
	DDX_Control(pDX, IDC_BUTTON_NUM8, btn_n8);
	DDX_Control(pDX, IDC_BUTTON_NUM9, btn_n9);
	DDX_Control(pDX, IDC_CLEAR_BUTTON, btn_clear);
	DDX_Control(pDX, IDC_DEL_BUTTON, btn_del);
	DDX_Control(pDX, IDC_CLEAR_BUTTON, btn_clear);
	DDX_Control(pDX, IDC_MULTIPLY_BUTTON, btn_multiply);
	DDX_Control(pDX, IDC_DIVICE_BUTTON, btn_div);
	DDX_Control(pDX, IDC_MINUS_BUTTON, btn_minus);
	DDX_Control(pDX, IDC_BUTTON_NUM_dot, btn_dot);
	DDX_Control(pDX, IDC_EQUAL_BUTTON, btn_eq);
	DDX_Control(pDX, OutputEdit, ouyput_e);
	DDX_Text(pDX, OutputEdit, display_value);
	DDX_Control(pDX, OutputEditSymbol, output_s);
	DDX_Text(pDX, OutputEditSymbol, display_s);
}

BEGIN_MESSAGE_MAP(CStandardCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_BUTTON_NUM0, &CStandardCalculatorDlg::OnBnClickedButtonNum0)
	ON_BN_CLICKED(IDC_BUTTON_NUM00, &CStandardCalculatorDlg::OnBnClickedButtonNum00)
	ON_BN_CLICKED(IDC_BUTTON_NUM7, &CStandardCalculatorDlg::OnBnClickedButtonNum7)
	ON_BN_CLICKED(IDC_BUTTON_NUM8, &CStandardCalculatorDlg::OnBnClickedButtonNum8)
	ON_BN_CLICKED(IDC_BUTTON_NUM9, &CStandardCalculatorDlg::OnBnClickedButtonNum9)
	ON_BN_CLICKED(IDC_BUTTON_NUM4, &CStandardCalculatorDlg::OnBnClickedButtonNum4)
	ON_BN_CLICKED(IDC_BUTTON_NUM5, &CStandardCalculatorDlg::OnBnClickedButtonNum5)
	ON_BN_CLICKED(IDC_BUTTON_NUM6, &CStandardCalculatorDlg::OnBnClickedButtonNum6)
	ON_BN_CLICKED(IDC_BUTTON_NUM1, &CStandardCalculatorDlg::OnBnClickedButtonNum1)
	ON_BN_CLICKED(IDC_BUTTON_NUM2, &CStandardCalculatorDlg::OnBnClickedButtonNum2)
	ON_BN_CLICKED(IDC_BUTTON_NUM3, &CStandardCalculatorDlg::OnBnClickedButtonNum3)
	ON_EN_CHANGE(OutputEdit, &CStandardCalculatorDlg::OnEnChangeOutputedit)
	ON_BN_CLICKED(IDC_MULTIPLY_BUTTON, &CStandardCalculatorDlg::OnBnClickedMultiplyButton)
	ON_BN_CLICKED(IDC_DIVICE_BUTTON, &CStandardCalculatorDlg::OnBnClickedDiviceButton)
	ON_BN_CLICKED(IDC_MINUS_BUTTON, &CStandardCalculatorDlg::OnBnClickedMinusButton)
	ON_BN_CLICKED(IDC_PLUS_BUTTON, &CStandardCalculatorDlg::OnBnClickedPlusButton)
	ON_BN_CLICKED(IDC_EQUAL_BUTTON, &CStandardCalculatorDlg::OnBnClickedEqualButton)
	ON_BN_CLICKED(IDC_BUTTON_NUM_dot, &CStandardCalculatorDlg::OnBnClickedButtonNumdot)
END_MESSAGE_MAP()


// CStandardCalculatorDlg message handlers

BOOL CStandardCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//display.SetWindowTextW(_T("0"));
	display_value = '0';

	CEdit* pEdt = (CEdit*)GetDlgItem(OutputEdit);
	font.CreatePointFont(300, _T("黑体"));
	pEdt->SetFont(&font);

	CEdit* pEdt_s = (CEdit*)GetDlgItem(OutputEditSymbol);
	font_s.CreatePointFont(300, _T("黑体"));
	pEdt_s->SetFont(&font_s);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStandardCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStandardCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStandardCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CStandardCalculatorDlg::OnBnClickedButtonNum0()
{
	// TODO: Add your control notification handler code here
	CancelInit();
	display_value = display_value + '0';
	UpdateData(FALSE);
}


void CStandardCalculatorDlg::OnBnClickedButtonNum00()
{
	// TODO: Add your control notification handler code here
	CancelInit();
	display_value = display_value + _T("00");
	UpdateData(FALSE);
}


void CStandardCalculatorDlg::OnBnClickedButtonNum7()
{
	// TODO: Add your control notification handler code here
	CancelInit();
	display_value = display_value + '7';
	UpdateData(FALSE);
}


void CStandardCalculatorDlg::OnBnClickedButtonNum8()
{
	// TODO: Add your control notification handler code here
	CancelInit();
	display_value = display_value + '8';
	UpdateData(FALSE);
}


void CStandardCalculatorDlg::OnBnClickedButtonNum9()
{
	// TODO: Add your control notification handler code here
	CancelInit();
	display_value = display_value + '9';
	UpdateData(FALSE);
}


void CStandardCalculatorDlg::OnBnClickedButtonNum4()
{
	// TODO: Add your control notification handler code here
	CancelInit();
	display_value = display_value + '4';
	UpdateData(FALSE);
}


void CStandardCalculatorDlg::OnBnClickedButtonNum5()
{
	// TODO: Add your control notification handler code here
	CancelInit();
	display_value = display_value + '5';
	UpdateData(FALSE);
}




void CStandardCalculatorDlg::OnBnClickedButtonNum6()
{
	// TODO: Add your control notification handler code here
	CancelInit();
	display_value = display_value + '6';
	UpdateData(FALSE);
}


void CStandardCalculatorDlg::OnBnClickedButtonNum1()
{
	// TODO: Add your control notification handler code here
	CancelInit();
	display_value = display_value + '1';
	UpdateData(FALSE);
}


void CStandardCalculatorDlg::OnBnClickedButtonNum2()
{
	// TODO: Add your control notification handler code here
	CancelInit();
	display_value = display_value + '2';
	UpdateData(FALSE);
}


void CStandardCalculatorDlg::OnBnClickedButtonNum3()
{
	// TODO: Add your control notification handler code here
	CancelInit();
	display_value = display_value + '3';
	UpdateData(FALSE);
}


void CStandardCalculatorDlg::OnEnChangeOutputedit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


int CStandardCalculatorDlg::CancelInit()
{
	// TODO: Add your implementation code here.
	if (display_value == '0') {
		display_value = _T("");
	}
	return 0;
}


void CStandardCalculatorDlg::OnBnClickedMultiplyButton()
{
	// TODO: 在此添加控件通知处理程序代码
	display_s = '*';
	UpdateData(FALSE);
}


void CStandardCalculatorDlg::OnBnClickedDiviceButton()
{
	// TODO: 在此添加控件通知处理程序代码
	display_s = '/';
	UpdateData(FALSE);
}


void CStandardCalculatorDlg::OnBnClickedMinusButton()
{
	// TODO: 在此添加控件通知处理程序代码
	display_s = '-';
	UpdateData(FALSE);
}


void CStandardCalculatorDlg::OnBnClickedPlusButton()
{
	// TODO: 在此添加控件通知处理程序代码
	display_s = '+';
	UpdateData(FALSE);
}


void CStandardCalculatorDlg::OnBnClickedEqualButton()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CStandardCalculatorDlg::OnBnClickedButtonNumdot()
{
	// TODO: 在此添加控件通知处理程序代码
	display_value = display_value + '.';
}




// SetVolumeGUIDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SetVolumeGUI.h"
#include "SetVolumeGUIDlg.h"
#include "afxdialogex.h"
#include "SetVolumeFeature.h"
#include "SetLight.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define ID_VOLUP   0x5000
#define ID_VOLDOWN   0X6000
#define ID_LUP   0X7000
#define ID_LDOWN   0X8000
#define ID_SCROFF   0XA000
#define ID_SHOWWINDOW 0XB000

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CSetVolumeGUIDlg 对话框



CSetVolumeGUIDlg::CSetVolumeGUIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SETVOLUMEGUI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSetVolumeGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSetVolumeGUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_HOTKEY, OnHotKey)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CSetVolumeGUIDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSetVolumeGUIDlg 消息处理程序

BOOL CSetVolumeGUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
	RegisterHotKey(GetSafeHwnd(), ID_VOLUP, MOD_CONTROL | MOD_ALT , VK_RIGHT);
	RegisterHotKey(GetSafeHwnd(), ID_VOLDOWN, MOD_CONTROL | MOD_ALT, VK_LEFT);
	RegisterHotKey(GetSafeHwnd(), ID_LUP, MOD_CONTROL | MOD_ALT, VK_UP);
	RegisterHotKey(GetSafeHwnd(), ID_LDOWN, MOD_CONTROL | MOD_ALT, VK_DOWN);
	RegisterHotKey(GetSafeHwnd(), ID_LDOWN, MOD_CONTROL | MOD_ALT, VK_DOWN);
	RegisterHotKey(GetSafeHwnd(), ID_SCROFF, MOD_CONTROL | MOD_ALT, VK_F2);
	RegisterHotKey(GetSafeHwnd(), ID_SHOWWINDOW, MOD_CONTROL | MOD_ALT, VK_F3);

	if (ERROR_ALREADY_EXISTS == GetLastError())
		return -1;

	int r = Init();
	if (r != 0)
		return -1;
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSetVolumeGUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSetVolumeGUIDlg::OnPaint()
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
HCURSOR CSetVolumeGUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HRESULT CSetVolumeGUIDlg::OnHotKey(WPARAM wParm, LPARAM lParam)
{
	if (wParm == ID_VOLUP)
	{
		CString test; 
		int currentVolume = GetVolumeLevel()*100;
		SetVolumeLevel(currentVolume + 2);
		test.Format(_T("现在音量：%d"), currentVolume);
		CSetVolumeGUIDlg::SetDlgItemTextW(IDC_STATIC, test);
		RECT rctA = { 0, 0, 0, 0 };
		LPRECT prctB = &rctA;
		CSetVolumeGUIDlg::GetWindowRect(prctB);
		SetWindowPos(&wndTopMost, prctB->left, prctB->top, prctB->right-prctB->left, prctB->bottom-prctB->top, SWP_SHOWWINDOW);
		SetTimer(1, 2000, NULL);
		//MessageBox(test);
	}
	if (wParm == ID_VOLDOWN)
	{
		CString test;
		int currentVolume = GetVolumeLevel() * 100;
		SetVolumeLevel(currentVolume - 2);
		test.Format(_T("现在音量：%d"), currentVolume);
		CSetVolumeGUIDlg::SetDlgItemTextW(IDC_STATIC, test);
		RECT rctA = { 0, 0, 0, 0 };
		LPRECT prctB = &rctA;
		CSetVolumeGUIDlg::GetWindowRect(prctB);
		SetWindowPos(&wndTopMost, prctB->left, prctB->top, prctB->right - prctB->left, prctB->bottom - prctB->top, SWP_SHOWWINDOW);
		SetTimer(1, 2000, NULL);
		//MessageBox(test);
	}
	if (wParm == ID_LUP)
	{
		auto m = CreateMutexA(NULL, TRUE, "{CAF16FA1-1E0C-419B-9D45-99B5719ED318}");
		CString test;

		IncreaseBrightness();
		test.Format(_T("现在亮度：%d"), GetBrightness());
		CSetVolumeGUIDlg::SetDlgItemTextW(IDC_STATIC2, test);
		RECT rctA = { 0, 0, 0, 0 };
		LPRECT prctB = &rctA;
		CSetVolumeGUIDlg::GetWindowRect(prctB);
		SetWindowPos(&wndTopMost, prctB->left, prctB->top, prctB->right - prctB->left, prctB->bottom - prctB->top, SWP_SHOWWINDOW);
		SetTimer(1, 2000, NULL);
		//MessageBox(test);
	}
	if (wParm == ID_LDOWN)
	{
		auto m = CreateMutexA(NULL, TRUE, "{CAF16FA1-1E0C-419B-9D45-99B5719ED318}");
		CString test;

		ReduceBrightness();
		test.Format(_T("现在亮度：%d"), GetBrightness());
		CSetVolumeGUIDlg::SetDlgItemTextW(IDC_STATIC2, test);
		RECT rctA = { 0, 0, 0, 0 };
		LPRECT prctB = &rctA;
		CSetVolumeGUIDlg::GetWindowRect(prctB);
		SetWindowPos(&wndTopMost, prctB->left, prctB->top, prctB->right - prctB->left, prctB->bottom - prctB->top, SWP_SHOWWINDOW);
		SetTimer(1, 2000, NULL);
		//MessageBox(test);
	}
	if (wParm == ID_SCROFF) {
		SendMessage(WM_SYSCOMMAND, SC_MONITORPOWER, 2);
		RECT rctA = { 0, 0, 0, 0 };
		LPRECT prctB = &rctA;
		CSetVolumeGUIDlg::GetWindowRect(prctB);
		SetWindowPos(&wndTopMost, prctB->left, prctB->top, prctB->right - prctB->left, prctB->bottom - prctB->top, SWP_SHOWWINDOW);
		SetTimer(1, 2000, NULL);
	}
	if (wParm == ID_SHOWWINDOW) {
		RECT rctA = { 0, 0, 0, 0 };
		LPRECT prctB = &rctA;
		CSetVolumeGUIDlg::GetWindowRect(prctB);
		SetWindowPos(&wndTopMost, prctB->left, prctB->top, prctB->right - prctB->left, prctB->bottom - prctB->top, SWP_SHOWWINDOW);
	}
	return true;
}

BOOL CSetVolumeGUIDlg::DestroyWindow() {
	UnregisterHotKey(GetSafeHwnd(), ID_VOLUP);
	UnregisterHotKey(GetSafeHwnd(), ID_VOLDOWN);
	UnregisterHotKey(GetSafeHwnd(), ID_LUP);
	UnregisterHotKey(GetSafeHwnd(), ID_LDOWN);
	UnregisterHotKey(GetSafeHwnd(), ID_SCROFF);
	return CDialog::DestroyWindow();
}

void CSetVolumeGUIDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent) {
	case 1:
		RECT rctA = { 0, 0, 0, 0 };
		LPRECT prctB = &rctA;
		CSetVolumeGUIDlg::GetWindowRect(prctB);
		SetWindowPos(&wndNoTopMost, prctB->left, prctB->top, prctB->right - prctB->left, prctB->bottom - prctB->top, SWP_HIDEWINDOW);
		KillTimer(1);
	}
}


void CSetVolumeGUIDlg::OnBnClickedButton1()
{
	RECT rctA = { 0, 0, 0, 0 };
	LPRECT prctB = &rctA;
	CSetVolumeGUIDlg::GetWindowRect(prctB);
	SetWindowPos(&wndNoTopMost, prctB->left, prctB->top, prctB->right - prctB->left, prctB->bottom - prctB->top, SWP_HIDEWINDOW);
	// TODO: 在此添加控件通知处理程序代码
}

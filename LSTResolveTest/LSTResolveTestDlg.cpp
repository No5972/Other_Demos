
// LSTResolveTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LSTResolveTest.h"
#include "LSTResolveTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLSTResolveTestDlg �Ի���



CLSTResolveTestDlg::CLSTResolveTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LSTRESOLVETEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLSTResolveTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_filename);
	DDX_Control(pDX, IDC_TREE1, m_files);
}

BEGIN_MESSAGE_MAP(CLSTResolveTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLSTResolveTestDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CLSTResolveTestDlg ��Ϣ�������

BOOL CLSTResolveTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_files.ModifyStyle(m_files.GetStyle(), m_files.GetStyle() | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_HASLINES);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLSTResolveTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLSTResolveTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLSTResolveTestDlg::OnBnClickedButton1()
{
	SetDlgItemText(IDC_EDIT1, CLSTResolveTestApp::opendialog());
	CString pathtmp;
	GetDlgItemText(IDC_EDIT1, pathtmp);

	CFile f; int namelen;
	unsigned char GetStr[256] = {0};
	f.Open(pathtmp, CFile::modeRead);
	f.Seek(56, CFile::begin);
	CString tmp, tmp2;
	/*
	SetDlgItemText(IDC_BUTTON1, size);
	f.Read(GetStr, 7);
	CString tmp; tmp.Format("%s", GetStr); 
	f.Read(GetStr, 12);
	f.Read(GetStr, 32);
	//position = f.Read(GetStr, 32);
	CString tmp2; tmp2.Format(",%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x"
		, GetStr[0], GetStr[1], GetStr[2], GetStr[3], GetStr[4], GetStr[5], GetStr[6], GetStr[7]
		, GetStr[8], GetStr[9], GetStr[10], GetStr[11], GetStr[12], GetStr[13], GetStr[14], GetStr[15]
		, GetStr[16], GetStr[17], GetStr[18], GetStr[19], GetStr[20], GetStr[21], GetStr[22], GetStr[23]
		, GetStr[23], GetStr[25], GetStr[26], GetStr[27], GetStr[28], GetStr[29], GetStr[30], GetStr[31]);
	tmp.Append(tmp2);
	*/
	
	m_files.DeleteAllItems();
	HTREEITEM Files = m_files.InsertItem("Files", NULL, NULL);
	HTREEITEM Sprites = m_files.InsertItem("ImagePacks2", NULL, NULL, Files);
	HTREEITEM Musics = m_files.InsertItem("Music", NULL, NULL, Files);
	HTREEITEM Sounds = m_files.InsertItem("SoundPacks", NULL, NULL, Files);

	f.Seek(48, CFile::begin);
	f.Read(GetStr, 4);
	int thiscount = GetStr[1] * 256 + GetStr[0];
	for (int i = 0; i < thiscount; i++) {
		f.Read(GetStr, 4);
		namelen = GetStr[0];
		f.Read(GetStr, namelen);
		tmp.Format("%s", GetStr);
		f.Read(GetStr, 4); //size compressed
		tmp2.Format(",%d", GetStr[0] + GetStr[1] * 256 + GetStr[2] * 256 * 256 + GetStr[3] * 256 * 256 * 256);
		tmp.Append(tmp2);
		f.Read(GetStr, 4); //size uncompressed
		tmp2.Format(",%d", GetStr[0] + GetStr[1] * 256 + GetStr[2] * 256 * 256 + GetStr[3] * 256 * 256 * 256);
		tmp.Append(tmp2);
		f.Read(GetStr, 4);
		f.Read(GetStr, 32);
		//position = f.Read(GetStr, 32);
		tmp2.Format(",%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x"
			, GetStr[0], GetStr[1], GetStr[2], GetStr[3], GetStr[4], GetStr[5], GetStr[6], GetStr[7]
			, GetStr[8], GetStr[9], GetStr[10], GetStr[11], GetStr[12], GetStr[13], GetStr[14], GetStr[15]
			, GetStr[16], GetStr[17], GetStr[18], GetStr[19], GetStr[20], GetStr[21], GetStr[22], GetStr[23]
			, GetStr[23], GetStr[25], GetStr[26], GetStr[27], GetStr[28], GetStr[29], GetStr[30], GetStr[31]);
		tmp.Append(tmp2);
		m_files.InsertItem(tmp, NULL, NULL, Files);
	}

	//f.Seek(1864, CFile::begin);
	//for (int i = 0; i < 5155; i++) {
	f.Read(GetStr, 38);
	f.Read(GetStr, 4);
	thiscount = GetStr[1] * 256 + GetStr[0];
	for (int i = 0; i < thiscount; i++) {
		f.Read(GetStr, 4);
		namelen = GetStr[0];
		f.Read(GetStr, namelen);
		tmp.Format("%s", GetStr);
		f.Read(GetStr, 4); //size compressed
		tmp2.Format(",%d", GetStr[0] + GetStr[1] * 256 + GetStr[2] * 256 * 256 + GetStr[3] * 256 * 256 * 256);
		tmp.Append(tmp2);
		f.Read(GetStr, 4); //size uncompressed
		tmp2.Format(",%d", GetStr[0] + GetStr[1] * 256 + GetStr[2] * 256 * 256 + GetStr[3] * 256 * 256 * 256);
		tmp.Append(tmp2);
		f.Read(GetStr, 4);
		f.Read(GetStr, 32);
		//position = f.Read(GetStr, 32);
		tmp2.Format(",%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x"
			, GetStr[0], GetStr[1], GetStr[2], GetStr[3], GetStr[4], GetStr[5], GetStr[6], GetStr[7]
			, GetStr[8], GetStr[9], GetStr[10], GetStr[11], GetStr[12], GetStr[13], GetStr[14], GetStr[15]
			, GetStr[16], GetStr[17], GetStr[18], GetStr[19], GetStr[20], GetStr[21], GetStr[22], GetStr[23]
			, GetStr[23], GetStr[25], GetStr[26], GetStr[27], GetStr[28], GetStr[29], GetStr[30], GetStr[31]);
		tmp.Append(tmp2);
		m_files.InsertItem(tmp, NULL, NULL, Sprites);
	}

	f.Read(GetStr, 14);
	f.Read(GetStr, 4);
	thiscount = GetStr[1] * 256 + GetStr[0];
	for (int i = 0; i < thiscount; i++) {
		f.Read(GetStr, 4);
		namelen = GetStr[0];
		f.Read(GetStr, namelen);
		tmp.Format("%s", GetStr);
		f.Read(GetStr, 4); //size compressed
		tmp2.Format(",%d", GetStr[0] + GetStr[1] * 256 + GetStr[2] * 256 * 256 + GetStr[3] * 256 * 256 * 256);
		tmp.Append(tmp2);
		f.Read(GetStr, 4); //size uncompressed
		tmp2.Format(",%d", GetStr[0] + GetStr[1] * 256 + GetStr[2] * 256 * 256 + GetStr[3] * 256 * 256 * 256);
		tmp.Append(tmp2);
		f.Read(GetStr, 4);
		f.Read(GetStr, 32);
		//position = f.Read(GetStr, 32);
		tmp2.Format(",%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x"
			, GetStr[0], GetStr[1], GetStr[2], GetStr[3], GetStr[4], GetStr[5], GetStr[6], GetStr[7]
			, GetStr[8], GetStr[9], GetStr[10], GetStr[11], GetStr[12], GetStr[13], GetStr[14], GetStr[15]
			, GetStr[16], GetStr[17], GetStr[18], GetStr[19], GetStr[20], GetStr[21], GetStr[22], GetStr[23]
			, GetStr[23], GetStr[25], GetStr[26], GetStr[27], GetStr[28], GetStr[29], GetStr[30], GetStr[31]);
		tmp.Append(tmp2);
		m_files.InsertItem(tmp, NULL, NULL, Musics);
	}

	f.Read(GetStr, 42);
	f.Read(GetStr, 4);
	thiscount = GetStr[1] * 256 + GetStr[0];
	for (int i = 0; i < thiscount; i++) {
		f.Read(GetStr, 4);
		namelen = GetStr[0];
		f.Read(GetStr, namelen);
		tmp.Format("%s", GetStr);
		f.Read(GetStr, 12);
		f.Read(GetStr, 32);
		//position = f.Read(GetStr, 32);
		tmp2.Format(",%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x"
			, GetStr[0], GetStr[1], GetStr[2], GetStr[3], GetStr[4], GetStr[5], GetStr[6], GetStr[7]
			, GetStr[8], GetStr[9], GetStr[10], GetStr[11], GetStr[12], GetStr[13], GetStr[14], GetStr[15]
			, GetStr[16], GetStr[17], GetStr[18], GetStr[19], GetStr[20], GetStr[21], GetStr[22], GetStr[23]
			, GetStr[23], GetStr[25], GetStr[26], GetStr[27], GetStr[28], GetStr[29], GetStr[30], GetStr[31]);
		tmp.Append(tmp2);
		m_files.InsertItem(tmp, NULL, NULL, Sounds);
	}

	/*
	f.Seek(518231, CFile::begin);

	for (int i = 0; i < 93; i++) {
		f.Read(GetStr, 4);
		namelen = GetStr[0];
		f.Read(GetStr, namelen);
		tmp.Format("%s", GetStr);
		f.Read(GetStr, 12);
		f.Read(GetStr, 32);
		//position = f.Read(GetStr, 32);
		tmp2.Format(",%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x"
			, GetStr[0], GetStr[1], GetStr[2], GetStr[3], GetStr[4], GetStr[5], GetStr[6], GetStr[7]
			, GetStr[8], GetStr[9], GetStr[10], GetStr[11], GetStr[12], GetStr[13], GetStr[14], GetStr[15]
			, GetStr[16], GetStr[17], GetStr[18], GetStr[19], GetStr[20], GetStr[21], GetStr[22], GetStr[23]
			, GetStr[23], GetStr[25], GetStr[26], GetStr[27], GetStr[28], GetStr[29], GetStr[30], GetStr[31]);
		tmp.Append(tmp2);
		m_files.InsertItem(tmp, NULL, NULL, Sounds);
	}
	*/

	m_files.Expand(Files, TVE_EXPAND);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


// MFCDemoDlg.h : ͷ�ļ�
//

#pragma once
#include "CWMPPlayer4.h"
#include "Cmci.h"



// CMFCDemoDlg �Ի���
class CMFCDemoDlg : public CDialogEx
{
// ����
public:
	CMFCDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	//CCommondialog1 CCDG;
	CWMPPlayer4 m_player;
	Cmci m_mmcontrol;
};

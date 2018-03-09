
// ListBoxTestDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "ColorListBox.h"


// CListBoxTestDlg 对话框
class CListBoxTestDlg : public CDialogEx
{
// 构造
public:
	CListBoxTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTBOXTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CColorListBox m_list;
};


// LSTResolveTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLSTResolveTestApp: 
// �йش����ʵ�֣������ LSTResolveTest.cpp
//

class CLSTResolveTestApp : public CWinApp
{
public:
	CLSTResolveTestApp();
	static TCHAR *opendialog();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLSTResolveTestApp theApp;
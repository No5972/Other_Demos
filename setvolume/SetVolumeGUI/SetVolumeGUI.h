
// SetVolumeGUI.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSetVolumeGUIApp: 
// �йش����ʵ�֣������ SetVolumeGUI.cpp
//

class CSetVolumeGUIApp : public CWinApp
{
public:
	CSetVolumeGUIApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSetVolumeGUIApp theApp;
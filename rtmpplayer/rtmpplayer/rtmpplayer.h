
// rtmpplayer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CrtmpplayerApp:
// �йش����ʵ�֣������ rtmpplayer.cpp
//

class CrtmpplayerApp : public CWinApp
{
public:
	CrtmpplayerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CrtmpplayerApp theApp;
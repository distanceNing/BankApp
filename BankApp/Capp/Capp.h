
// Capp.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "Csocket.h"
#include "DlgClient.h"
// CCappApp: 
// �йش����ʵ�֣������ Capp.cpp
//

class CCappApp : public CWinApp
{
public:
	CCappApp();
	Csocket sock;

	char id[16];
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

size_t CstringtoChar(CString& str, char* dest);

extern CCappApp theApp;
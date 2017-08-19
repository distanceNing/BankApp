
// Capp.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "Capp.h"
#include "CappDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCappApp

BEGIN_MESSAGE_MAP(CCappApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
	
END_MESSAGE_MAP()


// CCappApp 构造

CCappApp::CCappApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CCappApp 对象

CCappApp theApp;


// CCappApp 初始化

BOOL CCappApp::InitInstance()
{
	CWinApp::InitInstance();

	CCappDlg dlg;
	//CDlgClient dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
		TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
	}


	return FALSE;
}

size_t CstringtoChar(CString & str, char * dest)
{
	WCHAR *buffer = str.GetBuffer();
	BOOL defaut = true;
	size_t size = ::WideCharToMultiByte(CP_ACP, 0, (const WCHAR *)buffer, wcslen(buffer), dest, 32, 0, (LPBOOL)&defaut);
	dest[size] = '\0';
	return size;
}

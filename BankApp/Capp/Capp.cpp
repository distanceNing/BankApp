
// Capp.cpp : ����Ӧ�ó��������Ϊ��
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


// CCappApp ����

CCappApp::CCappApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CCappApp ����

CCappApp theApp;


// CCappApp ��ʼ��

BOOL CCappApp::InitInstance()
{
	CWinApp::InitInstance();

	CCappDlg dlg;
	//CDlgClient dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
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

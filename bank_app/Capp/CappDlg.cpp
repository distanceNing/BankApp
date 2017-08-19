
// CappDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Capp.h"
#include "CappDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCappDlg �Ի���



CCappDlg::CCappDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_BANK);
}

void CCappDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCappDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CCappDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCappDlg::OnBnClickedCancel)

END_MESSAGE_MAP()


// CCappDlg ��Ϣ�������

BOOL CCappDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	theApp.sock.CreatSocket();
	int flag = theApp.sock.Connect("192.168.0.110", PORT);//10.100.7.202 
	if (flag == 0)
	{
		MessageBox(L"����������ʧ��", L"��ܰ��ʾ", MB_OK);
		return false;
	}

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCappDlg::OnPaint()
{
	
	CPaintDC   dc(this);
	CRect   rect;
	GetClientRect(&rect);
	CDC   dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP_BANK);
	//IDB_BITMAP�����Լ���ͼ��Ӧ��ID   
	BITMAP   bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap   *pbmpOld = dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCappDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCappDlg::OnBnClickedOk()
{
	char user_type[USER_TYPE_SIZE];
	snprintf(user_type, USER_TYPE_SIZE, "%d", CLIENT);
	theApp.sock.Send(user_type, USER_TYPE_SIZE);
	int ntype = REQ_LOGIN;
	theApp.sock.Send(&ntype, sizeof(int));

	CString testName, testPassword;
	char  temp[32];
	GetDlgItemText(IDC_USERID, testName);
	GetDlgItemText(IDC_PASSWORD, testPassword);

	struct LOGIN_INFO login;

	CstringtoChar(testName, temp);
	strcpy(login.id, temp);

	CstringtoChar(testPassword, temp);
	strcpy(login.pass, temp);

	theApp.sock.Send(&login, sizeof(struct LOGIN_INFO));

	int nRet=0;
	theApp.sock.Receive(&nRet, sizeof(nRet));
	switch (nRet)
	{
	case PASSWD_ERROR:
		{
			MessageBox(L"�˺������벻ƥ��", L"��ܰ��ʾ", MB_OK);
			break;
		}
	case ALREADY_ONLINE:
		{
			MessageBox(L"�˻�������", L"��ܰ��ʾ", MB_OK);
			break;
		}
	case NO_THIS_USER:
		{
			MessageBox(L"���˻�������", L"��ܰ��ʾ", MB_OK);
			break;
		}
	case CHECK_SUCCESS:
		{
			memset(theApp.id, '\0', 16);
			strcpy(theApp.id, login.id);
			EndDialog(0);
			CDlgClient dlg;
			dlg.DoModal();
			break;
		}
	default:
		break;
	}
	
	
}


void CCappDlg::OnBnClickedCancel()
{
	int flag = MessageBox(L"��ȷ��Ҫ�˳���", L"��ܰ��ʾ", MB_OKCANCEL);
	if (flag == 1)
	{
	
		int ntype = REQ_EXIT;
		char type[REQ_SIZE] = { 0 };
		snprintf(type, REQ_SIZE, "%d", ntype);
		theApp.sock.Send(type, REQ_SIZE);
		EndDialog(1);
	}
}




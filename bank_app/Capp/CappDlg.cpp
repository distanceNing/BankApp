
// CappDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Capp.h"
#include "CappDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCappDlg 对话框



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


// CCappDlg 消息处理程序

BOOL CCappDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	theApp.sock.CreatSocket();
	int flag = theApp.sock.Connect("192.168.0.110", PORT);//10.100.7.202 
	if (flag == 0)
	{
		MessageBox(L"服务器连接失败", L"温馨提示", MB_OK);
		return false;
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCappDlg::OnPaint()
{
	
	CPaintDC   dc(this);
	CRect   rect;
	GetClientRect(&rect);
	CDC   dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP_BANK);
	//IDB_BITMAP是你自己的图对应的ID   
	BITMAP   bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap   *pbmpOld = dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
			MessageBox(L"账号与密码不匹配", L"温馨提示", MB_OK);
			break;
		}
	case ALREADY_ONLINE:
		{
			MessageBox(L"账户已在线", L"温馨提示", MB_OK);
			break;
		}
	case NO_THIS_USER:
		{
			MessageBox(L"此账户不存在", L"温馨提示", MB_OK);
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
	int flag = MessageBox(L"您确定要退出吗？", L"温馨提示", MB_OKCANCEL);
	if (flag == 1)
	{
	
		int ntype = REQ_EXIT;
		char type[REQ_SIZE] = { 0 };
		snprintf(type, REQ_SIZE, "%d", ntype);
		theApp.sock.Send(type, REQ_SIZE);
		EndDialog(1);
	}
}




// PageInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "Capp.h"
#include "PageInfo.h"
#include "afxdialogex.h"


// PageInfo 对话框

IMPLEMENT_DYNAMIC(PageInfo, CDialogEx)

PageInfo::PageInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALO_ACCOUNT, pParent)
{

}

PageInfo::~PageInfo()
{
}

void PageInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PageInfo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &PageInfo::OnBnClickedButton1)
END_MESSAGE_MAP()


// PageInfo 消息处理程序


void PageInfo::SetDlgItem(const CLIENT_INFO &client_info)
{
	CString str;
	WCHAR buffer[64];
	int size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)client_info.id, strlen(client_info.id), buffer, 64);
	buffer[size] = '\0';
	SetDlgItemText(IDC_STATIC_ID, buffer);


	size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)client_info.name, strlen(client_info.name), buffer, 64);
	buffer[size] = '\0';
	SetDlgItemText(IDC_STATIC_NAME, buffer);

	if(client_info.status)
		SetDlgItemText(IDC_STATIC_STASTUS, L"正常");
	else
		SetDlgItemText(IDC_STATIC_STASTUS, L"冻结");

	size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)client_info.date, strlen(client_info.date), buffer, 64);
	buffer[size] = '\0';
	SetDlgItemText(IDC_STATIC_TIME, buffer);

	str.Format(L"%s", client_info.credit);
	SetDlgItemText(IDC_STATIC_CREDIT, str);
	

}


BOOL PageInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CLIENT_INFO client_info;

	memset(&client_info, 0, sizeof(CLIENT_INFO));
	int type = REQ_SERACC;

	theApp.sock.Send(&type, sizeof(int));
	theApp.sock.Send(theApp.id,16);
	theApp.sock.Receive(&client_info, sizeof(CLIENT_INFO));
	SetDlgItem(client_info);
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void PageInfo::OnBnClickedButton1()
{
	int flag = MessageBox(L"您确定要注销账户吗？", L"温馨提示", MB_OKCANCEL);
	if (!flag)
	{
		return;
	}
	int type = REQ_DESACC;
	theApp.sock.Send(&type, sizeof(type));
	theApp.sock.Send(theApp.id, 16);
	int ret = 0;
	theApp.sock.Receive(&ret, sizeof(ret));
	if (ret)
		MessageBox(L"销户成功！", L"温馨提示", MB_OK);
	else
		MessageBox(L"销户失败！", L"温馨提示", MB_OK);
}

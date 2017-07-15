// PageModify.cpp : 实现文件
//

#include "stdafx.h"
#include "Capp.h"
#include "PageModify.h"
#include "afxdialogex.h"


// PageModify 对话框

IMPLEMENT_DYNAMIC(PageModify, CDialogEx)

PageModify::PageModify(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_MOD, pParent)
{

}

PageModify::~PageModify()
{
}

void PageModify::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PageModify, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTONOK, &PageModify::OnBnClickedButtonok)
END_MESSAGE_MAP()


// PageModify 消息处理程序


void PageModify::OnBnClickedButtonok()
{
	int type = REQ_MOD;
	theApp.sock.Send(&type, sizeof(int));
	CString str;
	MOD_INFO data;
	memset(&data, 0, sizeof(MOD_INFO));
	theApp.sock.Send(theApp.id, 16);
	char temp[32];
	CString pass_again;
	GetDlgItemText(IDC_EDIT_PASSWD_AGAIN, pass_again);
	GetDlgItemText(IDC_EDIT_PASSWD, str);
	if (str.Compare(pass_again))
	{
		MessageBox(L"您输入的密码不一致！", L"温馨提示", MB_OK);
		return;
	}
	
	CstringtoChar(str, temp);
	strcpy(data.pass, temp);
	theApp.sock.Send(&data, sizeof(struct MOD_INFO));
	int ret=0;
	theApp.sock.Receive(&ret, sizeof(ret));
	if(ret)
		MessageBox(L"修改成功！", L"温馨提示", MB_OK);
	else
		MessageBox(L"修改失败！", L"温馨提示", MB_OK);
}

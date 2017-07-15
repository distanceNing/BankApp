// PageOperate.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Capp.h"
#include "PageOperate.h"
#include "afxdialogex.h"

std::vector<int> PageOperate::operation = {0,0,0};

// PageOperate �Ի���

IMPLEMENT_DYNAMIC(PageOperate, CDialogEx)

PageOperate::PageOperate(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_OPEARTE, pParent)
{
	
}

PageOperate::~PageOperate()
{
}

void PageOperate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PageOperate, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &PageOperate::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO_SAVE, &PageOperate::OnBnClickedRadioSave)
	ON_BN_CLICKED(IDC_RADIO_WHD, &PageOperate::OnBnClickedRadioWhd)
	ON_BN_CLICKED(IDC_RADIO_TRAN, &PageOperate::OnBnClickedRadioTran)
END_MESSAGE_MAP()


// PageOperate ��Ϣ�������


void PageOperate::OnBnClickedButton1()
{
	int flag = -1;
	for (int i = 0;i < 3;i++)
	{
		if (operation[i])
		{
			flag = i;
			break;
		}
	}
	if (-1 == flag)
	{
		MessageBox(L"��ѡ�����Ĳ�����", L"��ܰ��ʾ", MB_OK);
		return;
	}
	switch (flag)
	{
	case 0:
		OnSave();
		break;
	case 1:
		OnWhd();
		break;
	case 2:
		OnTrans();
		break;
	default:
		break;
	}
	
}


void PageOperate::OnBnClickedRadioSave()
{	
	
	operation[0] = 1;
	operation[1] = 0;
	operation[2] = 0;
}


void PageOperate::OnBnClickedRadioWhd()
{
	operation[0] = 0;
	operation[1] = 1;
	operation[2] = 0;
}


void PageOperate::OnBnClickedRadioTran()
{
	operation[0] = 0;
	operation[1] = 0;
	operation[2] = 1;
}


bool PageOperate::OnSave()
{
	int type = REQ_SAVE;
	theApp.sock.Send(&type, sizeof(type));
	SAVE_INFO data;
	memset(&data, 0, sizeof(SAVE_INFO));
	CString str;
	GetDlgItemText(IDC_EDIT_SAVE, str);
	CstringtoChar(str, data.money);

	GetDlgItemText(IDC_EDIT_CARDID, str);
	CstringtoChar(str, data.id);
	theApp.sock.Send(&data, sizeof(SAVE_INFO));
	int ret = -1;
	theApp.sock.Receive(&ret, sizeof(int));
	if(ret==1)
		MessageBox(L"���ɹ���", L"��ܰ��ʾ", MB_OK);
	else
		MessageBox(L"���ʧ�ܣ�", L"��ܰ��ʾ", MB_OK);
	return false;
}


bool PageOperate::OnWhd()
{
	int type = REQ_WHD;
	theApp.sock.Send(&type, sizeof(type));
	SAVE_INFO data;
	memset(&data, 0, sizeof(SAVE_INFO));
	CString str;
	GetDlgItemText(IDC_EDIT_WHD, str);
	CstringtoChar(str, data.money);

	GetDlgItemText(IDC_EDIT_CARDID, str);
	CstringtoChar(str, data.id);
	theApp.sock.Send(&data, sizeof(SAVE_INFO));
	int ret = -1;
	theApp.sock.Receive(&ret, sizeof(int));
	if (ret == 1)
		MessageBox(L"ȡ��ɹ���", L"��ܰ��ʾ", MB_OK);
	else
		MessageBox(L"ȡ��ʧ�ܣ�", L"��ܰ��ʾ", MB_OK);
	return false;
}


bool PageOperate::OnTrans()
{
	int type = REQ_TRANS;
	theApp.sock.Send(&type, sizeof(type));
	TRANS_INFO data;
	memset(&data, 0, sizeof(TRANS_INFO));
	CString str;
	GetDlgItemText(IDC_EDIT_MYID, str);
	CstringtoChar(str, data.money);

	GetDlgItemText(IDC_EDIT_CARDID, str);
	CstringtoChar(str, data.this_card);

	GetDlgItemText(IDC_EDIT_TRANID, str);
	CstringtoChar(str, data.the_other_card);

	theApp.sock.Send(&data, sizeof(TRANS_INFO));
	int ret = -1;
	theApp.sock.Receive(&ret, sizeof(int));
	if (ret == 1)
		MessageBox(L"ת�˳ɹ���", L"��ܰ��ʾ", MB_OK);
	else
		MessageBox(L"ת��ʧ�ܣ�", L"��ܰ��ʾ", MB_OK);
	return false;
}

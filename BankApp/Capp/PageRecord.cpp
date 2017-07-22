// PageRecord.cpp : 实现文件
//

#include "stdafx.h"
#include "Capp.h"
#include "PageRecord.h"
#include "afxdialogex.h"

std::vector<int> PageRecord::operation = { 0,0,0 };
// PageRecord 对话框

IMPLEMENT_DYNAMIC(PageRecord, CDialogEx)

PageRecord::PageRecord(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_RECORD, pParent)
{

}

PageRecord::~PageRecord()
{
}

void PageRecord::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RECORDLIST, recordList);
}


BEGIN_MESSAGE_MAP(PageRecord, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &PageRecord::OnBnClickedRadio1)
	
	ON_BN_CLICKED(IDC_BUTTON1, &PageRecord::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO2, &PageRecord::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &PageRecord::OnBnClickedRadio3)
END_MESSAGE_MAP()


// PageRecord 消息处理程序


BOOL PageRecord::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	recordList.InsertColumn(0, L"卡号", 0, 120);
	recordList.InsertColumn(1, L"操作人", 0, 100);
	//recordList.InsertColumn(2, L"操作地IP", 0, 100);
	recordList.InsertColumn(2, L"金额", 0, 125);
	recordList.InsertColumn(3, L"操作时间", 0, 120);

	return false;
}






void PageRecord::OnBnClickedButton1()
{
	recordList.DeleteAllItems();
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
		MessageBox(L"请选择您的操作！", L"温馨提示", MB_OK);
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


void PageRecord::OnBnClickedRadio1()
{

	operation[0] = 0;
	operation[1] = 1;
	operation[2] = 0;
}

bool PageRecord::OnSave()
{
	int type = REQ_SAVE_RECORD;
	theApp.sock.Send(&type, sizeof(int));
	
	CString id;
	GetDlgItemText(IDC_EDIT_ID, id);


	char Id[16];
	memset(Id, '\0', 16);
	CstringtoChar(id, Id);
	theApp.sock.Send(Id, 16);

	int card_num = 0;
	theApp.sock.Receive(&card_num, sizeof(int));
	if (!card_num)
	{
		MessageBox(L"没有您要查询你的记录", L"温馨提示", MB_OK);
		return false;
	}
	struct TRCODE_INFO card_info;

	CString str;
	WCHAR buffer[64];


	for (int i = 0; i < card_num; i++)
	{
		memset(&card_info, 0, sizeof(TRCODE_INFO));
		theApp.sock.Receive(&card_info, sizeof(TRCODE_INFO));
		int size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.id, strlen(card_info.id), buffer, 64);
		buffer[size] = '\0';
		recordList.InsertItem(i, buffer);


		size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.name, strlen(card_info.name), buffer, 64);
		buffer[size] = '\0';
		recordList.SetItemText(i, 1, buffer);

		size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.money, strlen(card_info.money), buffer, 64);
		buffer[size] = '\0';
		recordList.SetItemText(i, 2, buffer);



		size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.date, strlen(card_info.date), buffer, 64);
		buffer[size] = '\0';
		recordList.SetItemText(i, 3, buffer);



	}

	return false;
}

bool PageRecord::OnWhd()
{
	int type = REQ_WHD_RECORD;
	theApp.sock.Send(&type, sizeof(int));

	CString id;
	GetDlgItemText(IDC_EDIT_ID, id);


	char Id[16];
	memset(Id, '\0', 16);
	CstringtoChar(id, Id);
	theApp.sock.Send(Id, 16);

	int card_num = 0;
	theApp.sock.Receive(&card_num, sizeof(int));
	if (!card_num)
	{
		MessageBox(L"没有您要查询你的记录", L"温馨提示", MB_OK);
		return false;
	}
	struct TRCODE_INFO card_info;

	CString str;
	WCHAR buffer[64];


	for (int i = 0; i < card_num; i++)
	{
		memset(&card_info, 0, sizeof(TRCODE_INFO));
		theApp.sock.Receive(&card_info, sizeof(TRCODE_INFO));
		int size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.id, strlen(card_info.id), buffer, 64);
		buffer[size] = '\0';
		recordList.InsertItem(i, buffer);


		size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.name, strlen(card_info.name), buffer, 64);
		buffer[size] = '\0';
		recordList.SetItemText(i, 1, buffer);

		size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.money, strlen(card_info.money), buffer, 64);
		buffer[size] = '\0';
		recordList.SetItemText(i, 2, buffer);



		size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.date, strlen(card_info.date), buffer, 64);
		buffer[size] = '\0';
		recordList.SetItemText(i, 3, buffer);
	}

	return false;
}

bool PageRecord::OnTrans()
{
	int type = REQ_TRANS_RECORD;
	theApp.sock.Send(&type, sizeof(int));

	CString id;
	GetDlgItemText(IDC_EDIT_ID, id);


	char Id[16];
	memset(Id, '\0', 16);
	CstringtoChar(id, Id);
	theApp.sock.Send(Id, 16);

	int card_num = 0;
	theApp.sock.Receive(&card_num, sizeof(int));
	if (!card_num)
	{
		MessageBox(L"没有您要查询你的记录", L"温馨提示", MB_OK);
		return false;
	}
	struct TRCODE_INFO card_info;

	CString str;
	WCHAR buffer[64];


	for (int i = 0; i < card_num; i++)
	{
		memset(&card_info, 0, sizeof(TRCODE_INFO));
		theApp.sock.Receive(&card_info, sizeof(TRCODE_INFO));
		int size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.id, strlen(card_info.id), buffer, 64);
		buffer[size] = '\0';
		recordList.InsertItem(i, buffer);


		size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.name, strlen(card_info.name), buffer, 64);
		buffer[size] = '\0';
		recordList.SetItemText(i, 1, buffer);

		size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.money, strlen(card_info.money), buffer, 64);
		buffer[size] = '\0';
		recordList.SetItemText(i, 2, buffer);



		size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.date, strlen(card_info.date), buffer, 64);
		buffer[size] = '\0';
		recordList.SetItemText(i, 3, buffer);



	}

	return false;
}

void PageRecord::OnBnClickedRadio2()
{

	operation[0] = 1;
	operation[1] = 0;
	operation[2] = 0;
}

void PageRecord::OnBnClickedRadio3()
{

	operation[0] = 0;
	operation[1] = 0;
	operation[2] = 1;
}

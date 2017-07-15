// PageAccount.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Capp.h"
#include "PageAccount.h"
#include "afxdialogex.h"


// PageAccount �Ի���

IMPLEMENT_DYNAMIC(PageAccount, CDialogEx)

PageAccount::PageAccount(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CARD, pParent)
{

}

PageAccount::~PageAccount()
{
}

void PageAccount::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ACCOUNT, accountList);
}


BEGIN_MESSAGE_MAP(PageAccount, CDialogEx)
END_MESSAGE_MAP()


// PageAccount ��Ϣ�������


BOOL PageAccount::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	accountList.InsertColumn(0, L"����", 0, 120);
	accountList.InsertColumn(1, L"������", 0, 100);
	accountList.InsertColumn(2, L"�������", 0, 125);
	accountList.InsertColumn(3, L"�˻�״̬", 0, 120);
	accountList.InsertColumn(4, L"����ʱ��", 0, 120);
	int type = REQ_SERALLCARD;
	theApp.sock.Send(&type, sizeof(int));
	theApp.sock.Send(theApp.id, 16);

	int card_num = 0;
	theApp.sock.Receive(&card_num, sizeof(int));
	if (!card_num)
		return TRUE;
	CARD_INFO card_info;

	CString str;
	WCHAR buffer[64];
	int size = 0;
	
	for (int i = 0; i < card_num; i++)
	{
		memset(&card_info, 0, sizeof(CARD_INFO));
		
		size=theApp.sock.Receive(&card_info, sizeof(CARD_INFO));
		int size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.id, strlen(card_info.id), buffer, 64);
		buffer[size] = '\0';
		accountList.InsertItem(i,buffer);
		

		size=::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.name, strlen(card_info.name), buffer, 64);
		buffer[size] = '\0';
		accountList.SetItemText(i, 1, buffer);

		size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.money, strlen(card_info.money), buffer, 64);
		buffer[size] = '\0';
		accountList.SetItemText(i, 2, buffer);
		

		if(atoi(card_info.status)== ACCOUNT_STATE_AVAILABLE)
			accountList.SetItemText(i, 3, L"����");
		else
			accountList.SetItemText(i, 3, L"����");

		size = ::MultiByteToWideChar(CP_ACP, 0, (const char *)card_info.date, strlen(card_info.date), buffer, 64);
		buffer[size] = '\0';
		accountList.SetItemText(i, 4, buffer);



	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

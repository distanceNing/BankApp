// DlgClient.cpp : 实现文件
//

#include "stdafx.h"
#include "Capp.h"
#include "DlgClient.h"
#include "afxdialogex.h"


// CDlgClient 对话框

IMPLEMENT_DYNAMIC(CDlgClient, CDialogEx)

CDlgClient::CDlgClient(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CLIENT, pParent)
{

}

CDlgClient::~CDlgClient()
{
}

void CDlgClient::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, clientTAB);
}


BEGIN_MESSAGE_MAP(CDlgClient, CDialogEx)
	ON_WM_PAINT()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CDlgClient::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDCANCEL, &CDlgClient::OnBnClickedCancel)

END_MESSAGE_MAP()


// CDlgClient 消息处理程序


BOOL CDlgClient::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	clientTAB.InsertItem(0, L"您的账户");
	clientTAB.InsertItem(1, L"您的信用卡");
	clientTAB.InsertItem(2, L"用户操作");
	clientTAB.InsertItem(3, L"修改信息");
	clientTAB.InsertItem(4, L"操作记录");



	clientOperate.Create(IDD_DIALOG_OPEARTE, GetDlgItem(IDC_TAB1));
	clientInfo.Create(IDD_DIALO_ACCOUNT, GetDlgItem(IDC_TAB1));
	clientRecord.Create(IDD_DIALOG_RECORD, GetDlgItem(IDC_TAB1));
	clientMod.Create(IDD_DIALOG_MOD, GetDlgItem(IDC_TAB1));
	clientAccount.Create(IDD_DIALOG_CARD, GetDlgItem(IDC_TAB1));
	// 获得IDC_TABTEST客户区大小
	CRect rect;
	clientTAB.GetClientRect(&rect);

	rect.top += 20;
	//rect.bottom -= 60;
	rect.left += 5;
	rect.right -= 5;

	//调整子对话框在父窗口中的位置

	clientOperate.MoveWindow(&rect);
	clientInfo.MoveWindow(&rect);
	clientRecord.MoveWindow(&rect);
	clientMod.MoveWindow(&rect);
	clientAccount.MoveWindow(&rect);

	clientInfo.ShowWindow(true);
	clientTAB.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgClient::OnPaint()
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


void CDlgClient::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int CurSel = clientTAB.GetCurSel();
	switch (CurSel)
	{
	case 0:
		clientInfo.ShowWindow(true);
		clientAccount.ShowWindow(false);
		clientOperate.ShowWindow(false);
		clientMod.ShowWindow(false);
		clientRecord.ShowWindow(false);
		break;

	case 1:
		clientInfo.ShowWindow(false);
		clientAccount.ShowWindow(true);
		clientOperate.ShowWindow(false);
		clientMod.ShowWindow(false);
		clientRecord.ShowWindow(false);
		break;
	case 2:
		clientInfo.ShowWindow(false);
		clientAccount.ShowWindow(false);
		clientOperate.ShowWindow(true);
		clientMod.ShowWindow(false);
		clientRecord.ShowWindow(false);
		break;
	case 3:
		clientInfo.ShowWindow(false);
		clientAccount.ShowWindow(false);
		clientOperate.ShowWindow(false);
		clientMod.ShowWindow(true);
		clientRecord.ShowWindow(false);
		break;
	case 4:
		clientInfo.ShowWindow(false);
		clientAccount.ShowWindow(false);
		clientOperate.ShowWindow(false);
		clientMod.ShowWindow(false);
		clientRecord.ShowWindow(true);
		break;
	default:
		break;
	}
}


void CDlgClient::OnBnClickedCancel()
{
	
	int flag = MessageBox(L"您确定要退出吗？", L"温馨提示", MB_OKCANCEL);
	if (flag == 1)
	{
		int ntype = REQ_EXIT;
		
		theApp.sock.Send(&ntype, sizeof(ntype));
		theApp.sock.Send(theApp.id, 16);
		EndDialog(1);
	}
}


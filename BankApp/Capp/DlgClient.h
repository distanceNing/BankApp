#pragma once
#include "afxcmn.h"
#include "define.h"
#include "PageOperate.h"
#include "PageInfo.h"
#include "PageRecord.h"
#include "PageModify.h"
#include "PageAccount.h"
// CDlgClient 对话框

class CDlgClient : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgClient)

public:
	CDlgClient(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgClient();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CLIENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl clientTAB;
	PageOperate clientOperate;
	PageInfo clientInfo;
	PageRecord clientRecord;
	PageModify clientMod;
	PageAccount clientAccount;


	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCancel();
	
};

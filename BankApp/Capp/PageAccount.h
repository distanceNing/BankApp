#pragma once
#include "afxcmn.h"


// PageAccount 对话框

class PageAccount : public CDialogEx
{
	DECLARE_DYNAMIC(PageAccount)

public:
	PageAccount(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PageAccount();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CARD
	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl accountList;
	virtual BOOL OnInitDialog();
};

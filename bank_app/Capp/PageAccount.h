#pragma once
#include "afxcmn.h"


// PageAccount �Ի���

class PageAccount : public CDialogEx
{
	DECLARE_DYNAMIC(PageAccount)

public:
	PageAccount(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PageAccount();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CARD
	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl accountList;
	virtual BOOL OnInitDialog();
};

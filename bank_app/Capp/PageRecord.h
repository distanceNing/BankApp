#pragma once
#include "afxcmn.h"
#include <vector>

// PageRecord �Ի���

class PageRecord : public CDialogEx
{
	DECLARE_DYNAMIC(PageRecord)

public:
	PageRecord(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PageRecord();
	
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RECORD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl recordList;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadio1();
	bool OnSave();
	bool OnWhd();
	bool OnTrans();
	static std::vector<int> operation;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
};

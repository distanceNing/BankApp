#pragma once

#include <atlconv.h>
// PageModify �Ի���

class PageModify : public CDialogEx
{
	DECLARE_DYNAMIC(PageModify)

public:
	PageModify(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PageModify();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MOD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonok();
};

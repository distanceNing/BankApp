#pragma once


// PageInfo �Ի���

class PageInfo : public CDialogEx
{
	DECLARE_DYNAMIC(PageInfo)

public:
	PageInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PageInfo();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALO_ACCOUNT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	void SetDlgItem(const CLIENT_INFO&client_info);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};

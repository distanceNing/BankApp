#pragma once


// PageInfo 对话框

class PageInfo : public CDialogEx
{
	DECLARE_DYNAMIC(PageInfo)

public:
	PageInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PageInfo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALO_ACCOUNT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void SetDlgItem(const CLIENT_INFO&client_info);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};

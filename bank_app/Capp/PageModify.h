#pragma once

#include <atlconv.h>
// PageModify 对话框

class PageModify : public CDialogEx
{
	DECLARE_DYNAMIC(PageModify)

public:
	PageModify(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PageModify();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MOD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonok();
};

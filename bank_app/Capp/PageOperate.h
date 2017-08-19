#pragma once


// PageOperate 对话框
#include <vector>
class PageOperate : public CDialogEx
{
	DECLARE_DYNAMIC(PageOperate)
	static std::vector<int>operation;
public:
	PageOperate(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PageOperate();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OPEARTE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadioSave();
	afx_msg void OnBnClickedRadioWhd();
	afx_msg void OnBnClickedRadioTran();
	bool OnSave();
	bool OnWhd();
	bool OnTrans();
};

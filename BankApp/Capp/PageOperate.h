#pragma once


// PageOperate �Ի���
#include <vector>
class PageOperate : public CDialogEx
{
	DECLARE_DYNAMIC(PageOperate)
	static std::vector<int>operation;
public:
	PageOperate(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PageOperate();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OPEARTE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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

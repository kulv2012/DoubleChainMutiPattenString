#pragma once
#include "afxwin.h"


// mainStrShowDlg 对话框

class mainStrShowDlg : public CDialog
{
	DECLARE_DYNAMIC(mainStrShowDlg)

public:
	mainStrShowDlg(CWnd* pParent = NULL);   // 标准构造函数
	mainStrShowDlg(CString str );
	virtual ~mainStrShowDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_MAINSTRING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strMainString;
	void setText(CString str);
	afx_msg void OnBnClickedOk();
	CEdit m_editStr;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

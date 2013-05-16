#pragma once


// helping 对话框

class helping : public CDialog
{
	DECLARE_DYNAMIC(helping)

public:
	helping(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~helping();

// 对话框数据
	enum { IDD = IDD_DIALOG_HELP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditStr();
	CEdit m_editStr;
	bool setText(CString str);
	CString m_strStr;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBnClickedOk();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

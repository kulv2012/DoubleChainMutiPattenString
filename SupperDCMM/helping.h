#pragma once


// helping �Ի���

class helping : public CDialog
{
	DECLARE_DYNAMIC(helping)

public:
	helping(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~helping();

// �Ի�������
	enum { IDD = IDD_DIALOG_HELP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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

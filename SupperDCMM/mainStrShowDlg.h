#pragma once
#include "afxwin.h"


// mainStrShowDlg �Ի���

class mainStrShowDlg : public CDialog
{
	DECLARE_DYNAMIC(mainStrShowDlg)

public:
	mainStrShowDlg(CWnd* pParent = NULL);   // ��׼���캯��
	mainStrShowDlg(CString str );
	virtual ~mainStrShowDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_MAINSTRING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strMainString;
	void setText(CString str);
	afx_msg void OnBnClickedOk();
	CEdit m_editStr;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

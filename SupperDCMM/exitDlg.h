#pragma once


// exitDlg �Ի���

class exitDlg : public CDialog
{
	DECLARE_DYNAMIC(exitDlg)

public:
	exitDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~exitDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_EXIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};

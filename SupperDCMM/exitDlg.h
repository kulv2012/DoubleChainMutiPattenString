#pragma once


// exitDlg 对话框

class exitDlg : public CDialog
{
	DECLARE_DYNAMIC(exitDlg)

public:
	exitDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~exitDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_EXIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};

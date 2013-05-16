#pragma once


// ModeChooseDlg 对话框

class ModeChooseDlg : public CDialog
{
	DECLARE_DYNAMIC(ModeChooseDlg)

public:
	ModeChooseDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ModeChooseDlg();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_DIALOG_MODE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnPaint();
	// 系统的保留字，public访问控制。
private:
	CString m_strReserve;
public:
	afx_msg void OnBnClickedCancel();
	wchar_t  reserveChar ;
};

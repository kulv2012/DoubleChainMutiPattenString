#pragma once


// ModeChooseDlg �Ի���

class ModeChooseDlg : public CDialog
{
	DECLARE_DYNAMIC(ModeChooseDlg)

public:
	ModeChooseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ModeChooseDlg();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_DIALOG_MODE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnPaint();
	// ϵͳ�ı����֣�public���ʿ��ơ�
private:
	CString m_strReserve;
public:
	afx_msg void OnBnClickedCancel();
	wchar_t  reserveChar ;
};

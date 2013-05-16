// SupperDCMMDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "resource.h"
#include "algorithm.h"
#include "afxwin.h"
#include "mainStrShowDlg.h"


enum MODE{ STANDARD , EXTEND } ;
// CSupperDCMMDlg �Ի���
class CSupperDCMMDlg : public CDialog
{
// ����
public:
	CSupperDCMMDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SUPPERDCMM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	// ����
	CString m_strMainString;
	// ģʽ��
	CString m_strSubString;
	// ģʽ���б�
	CListCtrl m_listSubString;
	// ƥ�����б�
	CListCtrl m_listResult;
	afx_msg void OnBnClickedButtonInputMainstring();
	// �㷨��
	Algorithm m_Kernel;
	afx_msg void OnBnClickedButtonInit();
	afx_msg void OnBnClickedButtonAddSubstring();
	afx_msg void OnBnClickedButtonBegin();
	afx_msg void OnBnClickedButtonShowTree();
	afx_msg void OnBnClickedButtonStep();
	afx_msg void OnBnClickedButtonDeleteSubstring();
	BOOL m_bIsShowTree;
	int drawTree(CDC * pDC);
	void PreOrderDraw( LPBtree tree , CDC * pDC );
	int m_nRadius;
	// ����ʾ���Ʊ���
	BOOL m_bStepShow;
	BOOL m_bIsStepShow;
	BOOL m_bHaveMainStr;
	afx_msg void OnBnClickedButtonHelping();

	
	// ƥ��ģʽ����
	MODE m_eMode;
	afx_msg void OnBnClickedButtonSetMode();
	afx_msg void OnBnClickedButtonShowNewTree();
	CButton m_ctrlCheck;
private:
	// ϵͳ�����ַ������ܵ���ģʽ���е��ַ�����
	wchar_t  m_cReserveChar;
public:
	afx_msg void OnBnClickedButtonFile();

	mainStrShowDlg mainstrdlg ;
};

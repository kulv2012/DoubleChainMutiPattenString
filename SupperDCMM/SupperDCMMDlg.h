// SupperDCMMDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "resource.h"
#include "algorithm.h"
#include "afxwin.h"
#include "mainStrShowDlg.h"


enum MODE{ STANDARD , EXTEND } ;
// CSupperDCMMDlg 对话框
class CSupperDCMMDlg : public CDialog
{
// 构造
public:
	CSupperDCMMDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SUPPERDCMM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	// 主串
	CString m_strMainString;
	// 模式串
	CString m_strSubString;
	// 模式串列表
	CListCtrl m_listSubString;
	// 匹配结果列表
	CListCtrl m_listResult;
	afx_msg void OnBnClickedButtonInputMainstring();
	// 算法类
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
	// 逐步演示控制变量
	BOOL m_bStepShow;
	BOOL m_bIsStepShow;
	BOOL m_bHaveMainStr;
	afx_msg void OnBnClickedButtonHelping();

	
	// 匹配模式设置
	MODE m_eMode;
	afx_msg void OnBnClickedButtonSetMode();
	afx_msg void OnBnClickedButtonShowNewTree();
	CButton m_ctrlCheck;
private:
	// 系统保留字符，不能当做模式串中的字符输入
	wchar_t  m_cReserveChar;
public:
	afx_msg void OnBnClickedButtonFile();

	mainStrShowDlg mainstrdlg ;
};

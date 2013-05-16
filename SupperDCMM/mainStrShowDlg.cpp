// mainStrShowDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SupperDCMM.h"
#include "mainStrShowDlg.h"


// mainStrShowDlg 对话框

IMPLEMENT_DYNAMIC(mainStrShowDlg, CDialog)

mainStrShowDlg::mainStrShowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(mainStrShowDlg::IDD, pParent)
	, m_strMainString(_T(""))
{
	
}

mainStrShowDlg::mainStrShowDlg( CString str )
{
	m_strMainString = str ;
	//UpdateData(FALSE);
}

mainStrShowDlg::~mainStrShowDlg()
{
}

void mainStrShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_STR, m_strMainString);
	DDX_Control(pDX, IDC_EDIT_STR, m_editStr);
}


BEGIN_MESSAGE_MAP(mainStrShowDlg, CDialog)
	ON_BN_CLICKED(IDOK, &mainStrShowDlg::OnBnClickedOk)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// mainStrShowDlg 消息处理程序

void mainStrShowDlg::setText(CString str)
{
	m_strMainString = str ;
	CFont *lpfont = new CFont ;
	lpfont->CreatePointFont(140,_T("楷体_GB2312"),NULL );
	//m_editStr.SetFont(&font);
	m_editStr.SetFont( lpfont ) ;
	UpdateData(FALSE);
}

void mainStrShowDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}

HBRUSH mainStrShowDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	if( nCtlColor == CTLCOLOR_EDIT )
	{
		pDC->SetBkColor(RGB(181,129,201) ) ;
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

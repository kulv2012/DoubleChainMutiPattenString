// exitDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SupperDCMM.h"
#include "exitDlg.h"


// exitDlg 对话框

IMPLEMENT_DYNAMIC(exitDlg, CDialog)

exitDlg::exitDlg(CWnd* pParent /*=NULL*/)
	: CDialog(exitDlg::IDD, pParent)
{

}

exitDlg::~exitDlg()
{
}

void exitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(exitDlg, CDialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &exitDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &exitDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// exitDlg 消息处理程序

void exitDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	CFont font ;
	dc.SetBkMode(TRANSPARENT);

	font.CreatePointFont(200,_T("楷体_GB2312"),NULL );
	CFont *oldfont = dc.SelectObject( &font );
	dc.SetTextColor( RGB(255,0,0) );
	//cdc.TextOutW(0 ,0 ,_T("------------------------------------"),34),
	CString str( _T("感谢您使用:") ) ;
	dc.TextOutW(190,20,str,str.GetLength() );
	dc.MoveTo(0,48);
	dc.LineTo(550,48);
	str = _T("基于优化双链树的多模式匹配算法演示系统 ！\n请问是否确定退出？") ;
	dc.TextOutW(5,50,str,str.GetLength() );
	dc.MoveTo(0,80);
	dc.LineTo(550,80);

	dc.SetTextColor(RGB(255,0,255) ) ;
	str = _T("请问是否确定退出？") ;
	dc.TextOutW(170,90,str,str.GetLength() );
	// 不为绘图消息调用 CDialog::OnPaint()
}

void exitDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}

void exitDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}

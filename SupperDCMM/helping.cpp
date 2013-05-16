// helping.cpp : 实现文件
//

#include "stdafx.h"
#include "SupperDCMM.h"
#include "helping.h"


// helping 对话框

IMPLEMENT_DYNAMIC(helping, CDialog)

helping::helping(CWnd* pParent /*=NULL*/)
	: CDialog(helping::IDD, pParent)
	, m_strStr(_T(""))
{

}

helping::~helping()
{
}

void helping::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_STR, m_editStr);
	DDX_Text(pDX, IDC_EDIT_STR, m_strStr);
}


BEGIN_MESSAGE_MAP(helping, CDialog)
	ON_EN_CHANGE(IDC_EDIT_STR, &helping::OnEnChangeEditStr)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDOK, &helping::OnBnClickedOk)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// helping 消息处理程序

void helping::OnEnChangeEditStr()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	
	// TODO:  在此添加控件通知处理程序代码
}

bool helping::setText(CString str)
{
	m_strStr = str ;
	//m_editStr.SetDlgItemTextW(IDC_EDIT_STR ,str ) ;
	return true;
}

int helping::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	
	// TODO:  在此添加您专用的创建代码

	return 0;
}

void helping::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}

void helping::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CFont *font = new CFont ;
	font->CreatePointFont(135,_T("楷体_GB2312"),NULL );

	//m_editStr.SetFont(&font);
	m_editStr.SetFont(font) ;
	
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
}

HBRUSH helping::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	if( nCtlColor ==   CTLCOLOR_EDIT  )
	{
		pDC->SetBkColor(RGB(119,210,255) ) ;
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

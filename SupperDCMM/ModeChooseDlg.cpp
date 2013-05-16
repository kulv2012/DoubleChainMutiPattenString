// ModeChooseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SupperDCMM.h"
#include "ModeChooseDlg.h"


// ModeChooseDlg 对话框

IMPLEMENT_DYNAMIC(ModeChooseDlg, CDialog)

ModeChooseDlg::ModeChooseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ModeChooseDlg::IDD, pParent)
	, m_strReserve(_T("@"))
{

	EnableAutomation();

}

ModeChooseDlg::~ModeChooseDlg()
{
}

void ModeChooseDlg::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialog::OnFinalRelease();
}

void ModeChooseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CHAR, m_strReserve);
}


BEGIN_MESSAGE_MAP(ModeChooseDlg, CDialog)
	ON_BN_CLICKED(IDOK, &ModeChooseDlg::OnBnClickedOk)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDCANCEL, &ModeChooseDlg::OnBnClickedCancel)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(ModeChooseDlg, CDialog)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IModeChooseDlg 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {C61F352D-B053-4891-8068-31C2FA61DE0B}
static const IID IID_IModeChooseDlg =
{ 0xC61F352D, 0xB053, 0x4891, { 0x80, 0x68, 0x31, 0xC2, 0xFA, 0x61, 0xDE, 0xB } };

BEGIN_INTERFACE_MAP(ModeChooseDlg, CDialog)
	INTERFACE_PART(ModeChooseDlg, IID_IModeChooseDlg, Dispatch)
END_INTERFACE_MAP()


// ModeChooseDlg 消息处理程序

void ModeChooseDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if( 1 != m_strReserve.GetLength() )
	{
		MessageBox(_T("请输入正确的保留字符！此字符在系统中将不能作为模式串中字符出现"),_T("保留字符输入错误"));
		return ;
	}
	reserveChar = (char)m_strReserve.GetAt(0);
	OnOK();
}

void ModeChooseDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CFont font ;
	dc.SetBkMode(TRANSPARENT);
	font.CreatePointFont(200,_T("楷体_GB2312"),NULL );
	CFont *oldfont = dc.SelectObject( &font );
	dc.SetTextColor( RGB(255,0,0) );
	//cdc.TextOutW(0 ,0 ,_T("------------------------------------"),34),
	CString str( _T("请选择要匹配的模式：") ) ;
		//
	dc.TextOutW(20,20,str,str.GetLength() );
	dc.SelectObject(oldfont);
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
}

void ModeChooseDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if( 1 != m_strReserve.GetLength() )
	{
		MessageBox(_T("请输入正确的保留字符！此字符在系统中将不能作为模式串中字符出现"),_T("保留字符输入错误"));
		return ;
	}
	reserveChar = (char)m_strReserve.GetAt(0);
	OnCancel();
}

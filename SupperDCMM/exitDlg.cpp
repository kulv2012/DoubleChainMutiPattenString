// exitDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SupperDCMM.h"
#include "exitDlg.h"


// exitDlg �Ի���

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


// exitDlg ��Ϣ�������

void exitDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	CFont font ;
	dc.SetBkMode(TRANSPARENT);

	font.CreatePointFont(200,_T("����_GB2312"),NULL );
	CFont *oldfont = dc.SelectObject( &font );
	dc.SetTextColor( RGB(255,0,0) );
	//cdc.TextOutW(0 ,0 ,_T("------------------------------------"),34),
	CString str( _T("��л��ʹ��:") ) ;
	dc.TextOutW(190,20,str,str.GetLength() );
	dc.MoveTo(0,48);
	dc.LineTo(550,48);
	str = _T("�����Ż�˫�����Ķ�ģʽƥ���㷨��ʾϵͳ ��\n�����Ƿ�ȷ���˳���") ;
	dc.TextOutW(5,50,str,str.GetLength() );
	dc.MoveTo(0,80);
	dc.LineTo(550,80);

	dc.SetTextColor(RGB(255,0,255) ) ;
	str = _T("�����Ƿ�ȷ���˳���") ;
	dc.TextOutW(170,90,str,str.GetLength() );
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
}

void exitDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}

void exitDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}

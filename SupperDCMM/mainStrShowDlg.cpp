// mainStrShowDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SupperDCMM.h"
#include "mainStrShowDlg.h"


// mainStrShowDlg �Ի���

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


// mainStrShowDlg ��Ϣ�������

void mainStrShowDlg::setText(CString str)
{
	m_strMainString = str ;
	CFont *lpfont = new CFont ;
	lpfont->CreatePointFont(140,_T("����_GB2312"),NULL );
	//m_editStr.SetFont(&font);
	m_editStr.SetFont( lpfont ) ;
	UpdateData(FALSE);
}

void mainStrShowDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}

HBRUSH mainStrShowDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if( nCtlColor == CTLCOLOR_EDIT )
	{
		pDC->SetBkColor(RGB(181,129,201) ) ;
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}

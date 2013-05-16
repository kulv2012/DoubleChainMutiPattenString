// helping.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SupperDCMM.h"
#include "helping.h"


// helping �Ի���

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


// helping ��Ϣ�������

void helping::OnEnChangeEditStr()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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

	
	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}

void helping::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}

void helping::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CFont *font = new CFont ;
	font->CreatePointFont(135,_T("����_GB2312"),NULL );

	//m_editStr.SetFont(&font);
	m_editStr.SetFont(font) ;
	
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
}

HBRUSH helping::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if( nCtlColor ==   CTLCOLOR_EDIT  )
	{
		pDC->SetBkColor(RGB(119,210,255) ) ;
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}

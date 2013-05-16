// ModeChooseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SupperDCMM.h"
#include "ModeChooseDlg.h"


// ModeChooseDlg �Ի���

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
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

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

// ע��: ������� IID_IModeChooseDlg ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {C61F352D-B053-4891-8068-31C2FA61DE0B}
static const IID IID_IModeChooseDlg =
{ 0xC61F352D, 0xB053, 0x4891, { 0x80, 0x68, 0x31, 0xC2, 0xFA, 0x61, 0xDE, 0xB } };

BEGIN_INTERFACE_MAP(ModeChooseDlg, CDialog)
	INTERFACE_PART(ModeChooseDlg, IID_IModeChooseDlg, Dispatch)
END_INTERFACE_MAP()


// ModeChooseDlg ��Ϣ�������

void ModeChooseDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if( 1 != m_strReserve.GetLength() )
	{
		MessageBox(_T("��������ȷ�ı����ַ������ַ���ϵͳ�н�������Ϊģʽ�����ַ�����"),_T("�����ַ��������"));
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
	font.CreatePointFont(200,_T("����_GB2312"),NULL );
	CFont *oldfont = dc.SelectObject( &font );
	dc.SetTextColor( RGB(255,0,0) );
	//cdc.TextOutW(0 ,0 ,_T("------------------------------------"),34),
	CString str( _T("��ѡ��Ҫƥ���ģʽ��") ) ;
		//
	dc.TextOutW(20,20,str,str.GetLength() );
	dc.SelectObject(oldfont);
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
}

void ModeChooseDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if( 1 != m_strReserve.GetLength() )
	{
		MessageBox(_T("��������ȷ�ı����ַ������ַ���ϵͳ�н�������Ϊģʽ�����ַ�����"),_T("�����ַ��������"));
		return ;
	}
	reserveChar = (char)m_strReserve.GetAt(0);
	OnCancel();
}

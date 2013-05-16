#pragma once

#define MAX_STR 64
#define MAX_STR_LEN 128
struct  node
{//tree node
    struct  node  *child;//point to the left child
    struct  node  *brother;//point to the left child
    wchar_t   data;//store the data.
	CPoint point ;
	int numSon ;
};
typedef struct node *LPBtree;


class CSupperDCMMDlg ;

class Algorithm
{
public:
	Algorithm( CSupperDCMMDlg * wnd );
	~Algorithm(void);
private:
	// �㷨��������������������㡣
	wchar_t  *mainStr;
	int maxLen ;
	int n_totallStr;
	wchar_t  subStr[MAX_STR][MAX_STR_LEN];
public:
	LPBtree root;
public:
	BOOL inputMainString(wchar_t  str[] , int len );
	int addSubString(wchar_t   str[]);

	BOOL StandardBuildTree(bool isIgnoreSame);
	BOOL StandardProcessTree(bool isIgnoreSame);
	BOOL StandardDoubleChainMatcher(const int beginSub);
	BOOL StandardPreorderRecProc(const LPBtree tree, const LPBtree treeHead , int difCount , int sameCount);

	BOOL ExtendBuildTree( void );
	BOOL ExtendProcessTree( void  );
	BOOL ExtendDoubleChainMatcher(const int beginSub);
	BOOL ExtendPreorderRecProc(const LPBtree tree, const LPBtree treeHead , int difCount , int sameCount);


	void PreorderSetPos(LPBtree tree , CPoint ps );
	void setPosition(void);

	BOOL init(void);
	void initTree(void);

	void deleteTree(  LPBtree treeHead );
	BOOL deleteString(wchar_t  * str);

private:
	CSupperDCMMDlg *mainWnd;
	CPoint showRectTop ;
	CPoint showRectBottom ;
	
public:
	// ���õ�ʱ�������ߵľ���
	int m_nDownLen;
	// ���õ�ʱ�����ߵľ��롣
	int m_nRightLen;

	
	void printRecord(int begin, int end);
private:
	// ϵͳ�����ַ�
	wchar_t  m_cReserveChar;
public:
	// ���ñ����ַ�
	void setReserveChar(wchar_t  reserve);
};



/*

int _tmain(int argc, _TCHAR* argv[])
{

    while ( getInput( &n_totallStr , mainStr , subStr ) )
    {
		deleteTree( root->child ) ;
		printInput( n_totallStr , mainStr , subStr ) ;
		if ( -1 == buildTree( n_totallStr , subStr , root ) )
		{
			cout << "\n\t\t\t�Բ���û�б�Ҫ������������ַ��� " << endl ;
			continue ;
		}
		cout << "\n-----------------ģʽ����ģ���˫����Ϊ��ǰ���������:---------------" << endl ;
		Preorder( root->child );
		cout << "\n\n------------------ģʽ���Ľ���ĽṹΪ��ǰ�������:---------------" << endl ;
		if ( false == processTree( root ) )
		{
			cout << "\n\n\t\t�Բ����벻Ҫ�����໥�������ַ�����"<<endl;
			continue ;
		}
		Preorder( root->child );
		cout << "\n--------------------------the matching result is :---------------------------" << endl ;
		if( false == DoubleChainMatcher ( mainStr , root , 0 ) )
		{
			cout << "\t\t\t�Բ���û��ģʽ����! " << endl ;
		}
	}
    return 0;
}*/
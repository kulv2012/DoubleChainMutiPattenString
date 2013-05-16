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
	// 算法程序里的主串，这样方便。
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
	// 设置点时的往下走的距离
	int m_nDownLen;
	// 设置点时网右走的距离。
	int m_nRightLen;

	
	void printRecord(int begin, int end);
private:
	// 系统保留字符
	wchar_t  m_cReserveChar;
public:
	// 设置保留字符
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
			cout << "\n\t\t\t对不起，没有必要输入相包含的字符串 " << endl ;
			continue ;
		}
		cout << "\n-----------------模式串建模后的双链树为（前序遍历）：:---------------" << endl ;
		Preorder( root->child );
		cout << "\n\n------------------模式串改进后的结构为（前序遍历）:---------------" << endl ;
		if ( false == processTree( root ) )
		{
			cout << "\n\n\t\t对不起，请不要输入相互包含的字符串！"<<endl;
			continue ;
		}
		Preorder( root->child );
		cout << "\n--------------------------the matching result is :---------------------------" << endl ;
		if( false == DoubleChainMatcher ( mainStr , root , 0 ) )
		{
			cout << "\t\t\t对不起，没有模式串！! " << endl ;
		}
	}
    return 0;
}*/
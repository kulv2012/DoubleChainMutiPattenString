#include "StdAfx.h"
#include "Algorithm.h"
#include "SupperDCMMDlg.h"


Algorithm::Algorithm( CSupperDCMMDlg * wnd )
: n_totallStr(0)
,showRectTop(50,100)
,showRectBottom(550,500)
, m_nDownLen(0)
, m_nRightLen(0)
, m_cReserveChar(0)
{
	//build a new tree ;
	root = new ( struct  node ) ;//initialize the root .
	root->child = NULL ;
	root->brother = NULL ;
	root->data = m_cReserveChar ;

	n_totallStr = 0 ;
	mainWnd = wnd ;

	mainStr = NULL  ;
	for( int i=0;i< MAX_STR ; i++ )
	{
		subStr[i][0] = '\0' ;
	}
	
}

Algorithm::~Algorithm(void)
{
}

BOOL Algorithm::inputMainString(wchar_t str[] , int len )
{
	if( '\0' == str[0] )
	{
		return FALSE ;
	}
	int i = 0 ;

	maxLen = wcslen(str);
	delete mainStr ;
	mainStr = new wchar_t[maxLen +1] ;

	for( i=0 ; '\0' != str[i] && i < maxLen  ; i++ )
	{
		mainStr[i] = str[i] ;
	}
	mainStr[len] = '\0' ;
	return TRUE ;
}

int Algorithm::addSubString(wchar_t   str[ ])
{
	if( '\0' == str[0] )
	{
		return -1 ;
	}
	int i = wcslen(str) ;
	maxLen = (maxLen> i )? maxLen : i ;

	
	for( i=0 ; '\0' != str[i] && maxLen > i ; i++ )
	{
		subStr[ n_totallStr ][i] = str[i] ;
	}
	subStr[n_totallStr][i] = '\0' ;
	n_totallStr = n_totallStr + 1 ;//add one !!!!
	return n_totallStr-1  ;
}

//function: pre order search the tree ,and print out it in the screen
//parament : the root of a tree;
//return void
void Algorithm::PreorderSetPos( LPBtree tree , CPoint ps )
{
	if ( tree != NULL )
    {
        if( tree->data == m_cReserveChar )
        {//�Ҳ�������
            //cout << "->0->" << tree->brother->data << "\t" ;
            return ;
        }
        //if the tree is not NULL
       //  go to the son ,then the postion is number of son * step
		tree->point = ps ;

		CPoint down( ps.x ,ps.y + m_nDownLen );
		CPoint left( ps.x + tree->numSon*m_nRightLen , ps.y ) ;

        PreorderSetPos( tree->child ,down );//seatch the left child of the tree .
        PreorderSetPos( tree->brother ,left );//search the right child of the tree
    }
}


//function : delete a tree .
//parament : the tree head , contain data .
void Algorithm::deleteTree(  LPBtree treeHead )
{
	if ( treeHead != NULL && m_cReserveChar != treeHead->data )
    {
        //if the tree is not NULL
        deleteTree( treeHead->child );//seatch the left child of the tree .
        deleteTree( treeHead->brother );//search the right child of the tree
        delete treeHead ;
    }
	else if ( treeHead != NULL && m_cReserveChar == treeHead->data  )
	{
		delete treeHead ;
	}
}

BOOL Algorithm::init(void)
{
	deleteTree(root->child);
	root->child = NULL ;
	root->numSon = 0 ;
	n_totallStr = 0;
	maxLen = 0 ;
	mainStr = NULL  ;
	for( int i=0;i< MAX_STR ; i++ )
	{
		subStr[i][0] = '\0' ;
	}

	//mainStr[0] = '\0' ;
	//n_totallStr = 0 ;
	return 0;
}

void Algorithm::setPosition(void)
{
	//get the max length 
	int i = 0;
	int maxlen = wcslen( subStr[0] );
	for( i = 1; i< n_totallStr;i++)
	{
		int tmp = wcslen( subStr[i] ) ;
		maxlen = maxlen< tmp ? tmp :maxlen ;
	}
	m_nDownLen = (showRectBottom.y - showRectTop.x)/(1+maxlen) ;
	if( 0 != root->numSon )
		m_nRightLen = (showRectBottom.x - showRectTop.x)/root->numSon ;
	else
		m_nRightLen = (showRectBottom.x - showRectTop.x) ;

	PreorderSetPos( root->child , showRectTop );
}

void Algorithm::initTree(void)
{
	deleteTree(root->child) ;
	root->child = NULL ;
}

BOOL Algorithm::deleteString(wchar_t  * str)
{
	int i = 0;
	int sign   = 0 ;
	for( i = 0; i < n_totallStr ; i++)
	{
		if( 0 == wcscmp( subStr[i] , str ) )
		{
			sign = 1 ;
		}
		if( 1 == sign )
		{
			 wcscpy_s( subStr[i],subStr[i+1] );
		}
	}
	n_totallStr-- ;
	sign = 0 ;
	return 0;
}


// function : use the strings to build a tree . and find out the especial link
//parament : the root , strings and the totall number
//return : if succeed ,return TRUE ,if has �����Ĵ���return FALSE .
BOOL Algorithm::StandardBuildTree(bool isIgnoreSame)
{
	int i = 0 ;
    int j = 0 ;
    LPBtree lptmp = root ;
	
	if( '\0' == subStr[0][0] || 0 == n_totallStr )
		return TRUE ;
    //append the frist to the root .
    //LPBtree
	root->numSon = 1 ;
	for ( j = 0 ;  subStr[0][j] != '\0' ; j++ )
	{
		lptmp->child = new (struct node ) ;
		lptmp = lptmp->child ;

		lptmp->child = NULL ;
		lptmp->brother = NULL ;
		lptmp->data = subStr[0][j] ;//copy the data
		lptmp->numSon = 1 ;
	}
	bool issame ;
    for( i = 1 ; i < n_totallStr ; i++ )
    {//each loop append one string into the tree
        lptmp = root->child ;
        j = 0 ;
		issame = FALSE ;
        while( lptmp->brother  != NULL || lptmp->data == subStr[i][j] )
        {//if the brother is not null,then should goto brother
            //if the data is equal goto child .
            if( lptmp->data == subStr[i][j] )
            {//if equal the data ,then check the brother
                if( lptmp->child == NULL || subStr[i][j+1] == '\0' )
                {//if child is null ,or the current string is end ,then has inner string .
					if( TRUE == isIgnoreSame )
					{//We should ignore the longer string 
						if( NULL != lptmp->child )
							lptmp->child = NULL ;//ok , i admit now it wasn't a good behavier 
						//j++ ;
						//continue ;
						issame = TRUE ;
						break ;
					}
					else 
						return FALSE ;
                }
				else
				{
					lptmp->numSon ++ ;
					lptmp = lptmp->child ;
					j ++ ;
				}
            }
            else
            {//if not equal the data ,then append after in the song
                lptmp = lptmp->brother ;
            }
        }
		if( FALSE == issame )
		{
			//append the brother wchar_t  .
			lptmp->brother = new ( struct node );
			lptmp = lptmp->brother ;

			lptmp->child = NULL ;
			lptmp->brother = NULL ;
			lptmp->data = subStr[i][j];
			lptmp->numSon = 1 ;

			for( j = j+1 ; subStr[i][j] != '\0' ; j++ )
			{//append the rest chars in the child
				lptmp->child = new (struct node );
				lptmp = lptmp->child ;
				lptmp->child = NULL ;
				lptmp->brother = NULL ;
				lptmp->data = subStr[i][j];
				lptmp->numSon = 1 ;
			}

			root->numSon ++ ;
		}
    }
	return TRUE;
}

//function : process the tree , add some prople aid point to the stree ;
//parament : the root of the stree ;
//return : void
BOOL Algorithm::StandardProcessTree(bool isIgnoreSame)
{
	if( root != NULL )
	{	
		LPBtree lptmp = root->child ;
		while( lptmp != NULL )
		{//loop to process each of the sub string
			if( false == StandardPreorderRecProc( lptmp->child , root->child , 1  , 0 ))//attention the 1 !!!
				if( FALSE == isIgnoreSame )
					return FALSE ;

			lptmp = lptmp->brother ;
		}
	}
	return TRUE ;
}


//function: pre order search the tree ,and print out it in the screen
//parament : the root of sub tree;the biggest root is for bad comparision and pass to left son
//return void
BOOL Algorithm::StandardPreorderRecProc(const LPBtree tree, const LPBtree treeHead , int difCount , int sameCount)
{
	if ( tree != NULL && tree->data != m_cReserveChar )
    {//if the tree is not NULL
        LPBtree lptmp = treeHead ;
		LPBtree lptreeHeadTmp = treeHead ;
		int sign = 0 ;
		bool noneed = FALSE ;//���������һ���ڵ���Ȼ�ȣ��ҶԷ�û���ֵ��ˣ���ô���ǲ���Ҫ�������ڵ�����
        while ( lptmp != NULL )
        {
			//����м�����֮ǰ�����ĸ����ڵ㣬������������Ϊ�������ǲ�������ȵģ���һ��͵��������ġ����ֵܡ�
			//�ޣ����ˣ�����ʧ����ĿҲ�ü���ȥ�ˣ��������簡
			if( m_cReserveChar == lptmp->data )
			{
				sign = sign + (int)(lptmp->child) ;
			}
            else if( tree->data == lptmp->data )
            {//if confered  equal data ,then use the current's
                //rightest son link to the other's leftest son
				if( NULL == lptmp->child )
				{//one string is included in the other
					return FALSE ;
				}
                LPBtree tmp = tree->child ;
				LPBtree special = lptmp->child ;
				
				if( tmp == NULL  )
                {//if there is no child => no need to append . 
                    break ;
                }
				while( tmp->data == special->data )//no need to NULL == lptmp->child 
				{//�����һ���ַ�����ƥ�䣬��ô��ǰ�ڵ�ָ��Է������ֵ�/��ת�ڵ㡣
					if( NULL == special->brother )
					{//����Է�û��brother�ˣ���ô�����üӸ����ӵ�������Ϊ����϶���ƥ���ˡ�
						noneed = TRUE ;
						break ;
					}
					else
					{//�������brother����ô�һ���ȥ������
						if( m_cReserveChar == special->brother->data )
						{//˵���⻹��һ����ת�ڵ㣬��ô����������һ���£���������
							sign  = sign + (int)(special->brother->child) ;
							special = special->brother->brother ;
						}
						else
						{//�������һ��ƽ���Ľڵ㡣��ôָ����
							special = special->brother ;//������ʵ����break����Ϊ������������������ܺ�tmp->data��ȡ�
						}
					}
				}
				if ( TRUE != noneed )
				{
					while(tmp->brother != NULL )
					{//loop to the rightest son
						tmp = tmp->brother ;
					}//new a link //ok ,i find it ! ,and newed a link
					tmp->brother = new (struct node );
					tmp = tmp->brother ;
					tmp->child = ( node *)(difCount+sign) ;//the left child store the part different cout of the two string !!!!!
					tmp->data = m_cReserveChar ;
					tmp->brother = special ;//point to the other's leftest son
				}
                break ;
            }
            lptmp = lptmp->brother ;//go to brother
			if( NULL == lptmp && root->child != lptreeHeadTmp )
			{//attention !!!!! if falid at the rightest brother , but ,
				//we know that there is still possible for current char match with the root's childs
				lptmp = root->child ;//go the the frist of son of the root again .
				lptreeHeadTmp = root->child ;
				//important !1! again turn to the frist ,so the up char are all different count .
				difCount = difCount + sameCount ;
				sameCount = 0 ;
			}
        }
        if( lptmp != NULL )
		{//find the same data ƥ����Ŀ��ȻҲ�ü�1����
            if( false == StandardPreorderRecProc( tree->child , lptmp->child,  difCount  , sameCount+1 ) )//difCount shouldn't add 1 !!!
				return FALSE ;
        }
        else
        {//if not find , goto begain,compare with root->child
			//ע�⣬���һ����ƥ�䣬��ô��ƥ����Ŀ�͵ü����ϴ�ƥ����Ŀ��������Ȼ��ƥ����Ŀ�������Ӧ����0 ����
            if ( false == StandardPreorderRecProc( tree->child , root->child , (difCount + 1 + sameCount) , 0  ) )
				return FALSE ;
        }
        //but ,the brothers all equal , compare with the original layer
        if ( false == StandardPreorderRecProc( tree->brother , treeHead, difCount , sameCount ) )
			return FALSE ;
       // PreorderRecProc( tree->child );//seatch the left child of the tree .
        //PreorderRecProc( tree->brother );//search the right child of the tree
    }
	return TRUE ;
}


//function : search the double chain ,
			//and print the same substrings and the 
			//	subnumber in format: begin---end : substring 
//parament :the root of the tree 
//return : if the root is NULL ,then return false ,else true .
BOOL Algorithm::StandardDoubleChainMatcher(const int beginSub)
{
	if( root == NULL )
	{//no need 
		return FALSE ;
	}
	LPBtree lptmp = root->child ;
	int window = beginSub ;
	int pc = 1 ;
	
	while( lptmp != NULL )
	{//loop ,entil come to the end of the main string , at the last of this loop ,will lptmp = root->child 
		if(  '\0' == mainStr[window+pc-1]  )
		{//if the main string is end . then , return ;
			return TRUE ;
		}
		else if( lptmp->data == mainStr[window+pc-1] )
		{//if the data is the same 
			if( NULL == lptmp->child )
			{//if there is no child ,then we can conclude that we find a substring .print it !!!! o ye !!
//---------------------------------------------------------------------
				wchar_t *strtmp = new wchar_t[pc+1] ;
				//cout << window << "---" << window+pc-1 << ": " ;
				for( int j = window ; j < window + pc ; j++ )
				{//print out the substring !
					strtmp[j-window] = mainStr[ j ] ;
				}
				strtmp[pc] = '\0' ;
				CString str ;
				str.Format(_T("%d--%d"),window , window+pc-1) ;
				mainWnd->m_listResult.InsertItem(0,str);

				//str.Format(_T("%s"),strtmp);
				str = (CString)strtmp ;
				mainWnd->m_listResult.SetItemText(0,1,str );
//---------------------------------------------------------------------
				window = window + pc ;//move 
				pc = 1 ;//initialize  
				lptmp = root->child ;//point to the root's son ,again !
			}
			else //lptmp have child .
			{
				lptmp = lptmp->child ;
				pc++ ;
			}
		}
		else //if not equal .rightword .
		{
			if( NULL == lptmp->brother )
			{//if no brother , ok ,let's search again .
				if( 1 != pc )
				{
					window = window + pc - 1 ;
				}
				else
				{
					window = window + 1 ;
				}
				pc = 1 ;
				lptmp = root->child ;
			}
			else
			{//if have brother ````````
				lptmp = lptmp->brother ;
				if( m_cReserveChar != lptmp->data )
				{//if the right brother is not a aid point .
					;//do nothing 
				}
				else 
				{//lptmp->data is m_cReserveChar , that means ```aid point !!!!!
					//attention : I stored the diffent number of string in the child .
					window = window + (int)(lptmp->child)  ;
					pc = pc - (int)(lptmp->child)  ;
					lptmp = lptmp->brother ;
				}
			}
		}
	}//while end .
	return TRUE ;
}


//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
// function : use the strings to build a tree . and find out the especial link
//parament : the root , strings and the totall number
//return : if succeed ,return TRUE ,if has �����Ĵ���return FALSE .
BOOL Algorithm::ExtendBuildTree( void )
{
	int i = 0 ;
    int j = 0 ;
    LPBtree lptmp = root ;
	
	if( '\0' == subStr[0][0] || 0 == n_totallStr )
		return FALSE ;
    //append the frist to the root .
    //LPBtree
	root->numSon = 1 ;
	for ( j = 0 ;  subStr[0][j] != '\0' ; j++ )
	{
		lptmp->child = new (struct node ) ;
		lptmp = lptmp->child ;

		lptmp->child = NULL ;
		lptmp->brother = NULL ;
		lptmp->data = subStr[0][j] ;//copy the data
		lptmp->numSon = 1 ;
	}

	BOOL isSame ;
    for( i = 1 ; i < n_totallStr ; i++ )
    {//each loop append one string into the tree
        lptmp = root->child ;
        j = 0 ;
		isSame = FALSE ;
        while( lptmp->brother  != NULL || lptmp->data == subStr[i][j] )
        {//if the brother is not null,then should goto brother
            //if the data is equal goto child .
            if( lptmp->data == subStr[i][j] )
            {//if equal the data ,then check the brother
//----------------------------------------------------------------
                if( lptmp->child != NULL && subStr[i][j+1] == '\0' )
                {//if child is not null ,and  the new is in it . append at the rightest brother .
					if( NULL  == lptmp->brother )
					{//if has no brother ,then break to append at the right .
						break ;
					}
					else
					{//if has brother .
						lptmp = lptmp->brother ;
						continue ;
					}
					break ;
                }
				else if( NULL == lptmp->child && '\0' != subStr[i][j+1] )
				{
					if( NULL  == lptmp->brother )
					{//if has no brother ,then break to append at the right .
						break ;
					}
					else
					{//if has brother .
						lptmp = lptmp->brother ;
						continue ;
					}
					break ;
				}
				else if ( NULL == lptmp->child && '\0' == subStr[i][j+1] )
				{//if the two is the same !!!!.
					isSame = TRUE ;
					break ;
				}
//----------------------------------------------------------------
				lptmp->numSon ++ ;
                lptmp = lptmp->child ;
                j ++ ;
            }
            else
            {//if not equal the data ,then append after in the song
                lptmp = lptmp->brother ;
            }
        }

		if( FALSE == isSame )
		{//if is not the same .
			//append the brother char .
			lptmp->brother = new ( struct node );
			lptmp = lptmp->brother ;

			lptmp->child = NULL ;
			lptmp->brother = NULL ;
			lptmp->data = subStr[i][j];
			lptmp->numSon = 1 ;

			for( j = j+1 ; subStr[i][j] != '\0' ; j++ )
			{//append the rest chars in the child
				lptmp->child = new (struct node );
				lptmp = lptmp->child ;
				lptmp->child = NULL ;
				lptmp->brother = NULL ;
				lptmp->data = subStr[i][j];
				lptmp->numSon = 1 ;
			}

			root->numSon ++ ;
		}
    }
	return TRUE;
}

//function : process the tree , add some prople aid point to the stree ;
//parament : the root of the stree ;
//return : void
BOOL Algorithm::ExtendProcessTree( void )
{
	if( root != NULL )
	{	
		LPBtree lptmp = root->child ;
		while( lptmp != NULL )
		{//loop to process each of the sub string
			ExtendPreorderRecProc( lptmp->child , root->child , 1  , 0 ) ;//attention the 1 !!!
			lptmp = lptmp->brother ;
		}
	}
	return TRUE ;
}


//function: pre order search the tree ,and print out it in the screen
//parament : the root of sub tree;the biggest root is for bad comparision and pass to left son
//return void
BOOL Algorithm::ExtendPreorderRecProc(const LPBtree tree, const LPBtree treeHead , int difCount , int sameCount)
{
	if ( tree != NULL && tree->data != m_cReserveChar )
    {//if the tree is not NULL
        LPBtree lptmp = treeHead ;
		LPBtree lptreeHeadTmp = treeHead ;
		int sign = 0 ;
		bool noneed = FALSE ;//���������һ���ڵ���Ȼ�ȣ��ҶԷ�û���ֵ��ˣ���ô���ǲ���Ҫ�������ڵ�����
        while ( lptmp != NULL )
        {
			sign = 0 ;
			//����м�����֮ǰ�����ĸ����ڵ㣬������������Ϊ�������ǲ�������ȵģ���һ��͵��������ġ����ֵܡ�
			//�ޣ����ˣ�����ʧ����ĿҲ�ü���ȥ�ˣ��������簡
			if( m_cReserveChar == lptmp->data )
			{
				sign = sign + (int)(lptmp->child) ;
			}
            else if( tree->data == lptmp->data )
            {//if confered  equal data ,then use the current's
                //rightest son link to the other's leftest son
				if(  NULL == tree->child || NULL == lptmp->child )
				{//one string is included in the other. point to it !!!!
					LPBtree tmp = tree ;
					while( tmp->brother != NULL && m_cReserveChar != tmp->data  )
					{//loop to the rightest son
						tmp = tmp->brother ;
					}//new a link //ok ,i find it ! ,and newed a link
					if( tmp->brother == NULL  )
					{
						tmp->brother = new (struct node );
						tmp = tmp->brother ;
						tmp->child = ( node *)(difCount+sign) ;//the left child store the part different cout of the two string !!!!!
						tmp->data = m_cReserveChar ;
						tmp->brother = lptmp ;//point to the other's leftest son
					}
					else if( m_cReserveChar == tmp->data  )
					{// show that conqued a aid point .!!!!!!!do nothing .?????
						//no !!!!! I want to see who is ahead !!!!
						LPBtree lpahead = lptmp->brother ;
						while( NULL != lpahead && lpahead !=  tmp->brother )
							lpahead = lpahead->brother ;
						
						if( lpahead ==  tmp->brother )
						{//if find that the current is ahead !!! tmp->brother point to the current point !!!
							tmp->brother = lptmp ;
						}
					}
						
				}
				else//all of the two is not null ,, has child !!
				{
					if( treeHead == root->child )
					{//if the treeHead is root's son , so it is special : " abdc , bd , b "
						LPBtree rootChild = root->child ;
						while( NULL != rootChild )
						{
							if( rootChild->data == tree->data && NULL == rootChild->child )
							{//If find a isolate point of the root's son !!
								LPBtree treetmp = tree ;
								while( NULL != treetmp->brother )
								{
									treetmp = treetmp->brother ;
								}
								treetmp->brother = new (struct node );
								treetmp = treetmp->brother ;
								treetmp->child = ( node *)(difCount+sign) ;//the left child store the part different cout of the two string !!!!!
								treetmp->data = m_cReserveChar ;
								treetmp->brother = rootChild ;//point to the other's leftest son
								break ;
							}
							rootChild = rootChild->brother ;
						}
					}
					LPBtree special = lptmp->child ;
					LPBtree tmp = tree->child ;
					
					if( tmp->data == special->data )//no need to NULL == lptmp->child 
					{//�����һ���ַ�����ƥ�䣬��ô��ǰ�ڵ�ָ��Է������ֵ�/��ת�ڵ㡣
						if( NULL == special->brother )
						{//����Է�û��brother�ˣ���ô�����üӸ����ӵ�������Ϊ����϶���ƥ���ˡ�
							noneed = TRUE ;
							break ;
						}
						else //�������������ȣ��ҶԷ����ֵܣ���ô��ָ���£�
						{//�������brother����ô�һ���ȥ������
							;//if( m_cReserveChar == special->brother->data )
							//{//˵���⻹��һ����ת�ڵ㣬��ô����������һ���£���������
							//	sign  = sign + (int)(special->brother->child) ;
							//	special = special->brother->brother ;
							//}
							//else
							//{//�������һ��ƽ���Ľڵ㡣��ôָ����
								//special = special->brother ;//������ʵ����break����Ϊ������������������ܺ�tmp->data��ȡ�
							//}
						}
					}
					if ( TRUE != noneed )
					{
						while( tmp->brother != NULL && m_cReserveChar != tmp->data )
						{//loop to the rightest son
							tmp = tmp->brother ;
						}//new a link //ok ,i find it ! ,and newed a link
						if( NULL == tmp->brother )
						{
							tmp->brother = new (struct node );
							tmp = tmp->brother ;
							tmp->child = ( node *)(difCount+sign) ;//the left child store the part different cout of the two string !!!!!
							tmp->data = m_cReserveChar ;
							tmp->brother = special ;//point to the other's leftest son
						}
					}
					break ;
				}
            }
            lptmp = lptmp->brother ;//go to brother
			if( NULL == lptmp && root->child != lptreeHeadTmp )
			{//attention !!!!! if falid at the rightest brother , but ,
				//we know that there is still possible for current char match with the root's childs
				lptmp = root->child ;//go the the frist of son of the root again .
				lptreeHeadTmp = root->child ;
				//important !1! again turn to the frist ,so the up char are all different count .
				difCount = difCount + sameCount ;
				sameCount = 0 ;
			}
        }

        if( lptmp != NULL )
		{//find the same data ƥ����Ŀ��ȻҲ�ü�1����
            if( false == ExtendPreorderRecProc( tree->child , lptmp->child,  difCount  , sameCount+1 ) )//difCount shouldn't add 1 !!!
				return FALSE ;
        }
        else
        {//if not find , goto begain,compare with root->child
			//ע�⣬���һ����ƥ�䣬��ô��ƥ����Ŀ�͵ü����ϴ�ƥ����Ŀ��������Ȼ��ƥ����Ŀ�������Ӧ����0 ����
            if ( false == ExtendPreorderRecProc( tree->child , root->child , (difCount + 1 + sameCount) , 0  ) )
				return FALSE ;
        }
        //but ,the brothers all equal , compare with the original layer
        if ( false == ExtendPreorderRecProc( tree->brother , treeHead, difCount , sameCount ) )
			return FALSE ;
       // PreorderRecProc( tree->child );//seatch the left child of the tree .
        //PreorderRecProc( tree->brother );//search the right child of the tree
    }
	return TRUE ;
}


//function : search the double chain ,
			//and print the same substrings and the 
			//	subnumber in format: begin---end : substring 
//parament :the root of the tree 
//return : if the root is NULL ,then return false ,else true .
BOOL Algorithm::ExtendDoubleChainMatcher(const int beginSub)
{
	if( root == NULL )
	{//no need 
		return FALSE ;
	}
	LPBtree lptmp = root->child ;
	int window = beginSub ;
	int pc = 1 ;
	
	while( lptmp != NULL )
	{//loop ,entil come to the end of the main string , at the last of this loop ,will lptmp = root->child 
		if(  '\0' == mainStr[window+pc-1]  )
		{//if the main string is end . then , return ;
			return TRUE ;
		}
		else if( lptmp->data == mainStr[window+pc-1] )
		{//if the data is the same 

			if( NULL == lptmp->child )
			{//if there is no child ,then we can conclude that we find a substring .print it !!!! o ye !!
//---------------------------------------------------------------------
				printRecord( window ,window + pc ) ;
//---------------------------------------------------------------------
				if( NULL == lptmp->brother )
				{//if no brother ,then again !!
					window = window + pc ;//move 
					pc = 1 ;//initialize  
					lptmp = root->child ;//point to the root's son ,again !
				}
				else
				{//if have brother .go to brother .
					lptmp = lptmp->brother ;
					if( m_cReserveChar != lptmp->data )
					{//if the right brother is not a aid point .
						;//do nothing 
					}
					else 
					{//lptmp->data is m_cReserveChar , that means ```aid point !!!!!
						//attention : I stored the diffent number of string in the child .
						window = window + (int)(lptmp->child)  ;
						pc = pc - (int)(lptmp->child)  ;
						lptmp = lptmp->brother ;
					}
				}
			}
			else //lptmp have child .
			{
				//�ж��ӣ��϶�Ҫ������ȥ�ˣ��˶��ǻ��ɵģ����û�����ˣ�
				//�⺣�ģ��㱿���㣡�Ǳ�����������ⲻ������ظ���ӡ���𣿣���
				//�������ǡ�˳�㡱�ɣ�˳�㿴һ����û�а������ַ������оʹ�Ӧ�£�

				LPBtree lpbytheway = lptmp ;
				int tmpwindow = window ;
				while ( NULL != lpbytheway->brother )
				{
					lpbytheway = lpbytheway->brother ;
					if( m_cReserveChar == lpbytheway->data )
					{//if find a aid point ! move the tempwindow !
						tmpwindow = tmpwindow + (int)(lpbytheway->child) ;
					}
					else if ( mainStr[window+pc-1] == lpbytheway->data && NULL == lpbytheway->child  )
					{//������ֵ�������ȣ�����û�ж��ӣ����ֶ���Ϊ�أ���ӡ�ɣ���
						
						printRecord( tmpwindow ,window + pc ) ;//the second parement!!! no move !
					}
					//else if (  mainStr[window+pc-1] == lpbytheway->data )
				}
//----------------------------------------------------
				lptmp = lptmp->child ;
				pc++ ;
			}
		}
		else //if not equal .rightword .
		{
			if( NULL == lptmp->brother )
			{//if no brother , ok ,let's search again .
				if( 1 != pc )
				{
					window = window + pc - 1 ;
				}
				else
				{
					window = window + 1 ;
				}
				pc = 1 ;
				lptmp = root->child ;
			}
			else
			{//if have brother ````````
				lptmp = lptmp->brother ;
				if( m_cReserveChar != lptmp->data )
				{//if the right brother is not a aid point .
					;//do nothing 
				}
				else 
				{//lptmp->data is m_cReserveChar , that means ```aid point !!!!!
					//attention : I stored the diffent number of string in the child .
					window = window + (int)(lptmp->child)  ;
					pc = pc - (int)(lptmp->child)  ;
					lptmp = lptmp->brother ;
				}
			}
		}//if end 
	}//while end .
	return TRUE ;
}
void Algorithm::printRecord(int begin, int end)
{
	wchar_t *strtmp = new wchar_t[end-begin+1] ;
	//cout << window << "---" << window+pc-1 << ": " ;
	for( int j = begin ; j < end ; j++ )
	{//print out the substring !
		strtmp[j-begin] = mainStr[ j ] ;
	}
	strtmp[end-begin] = '\0' ;
	CString str ;
	str.Format(_T("%d--%d"),begin , end-1) ;
	mainWnd->m_listResult.InsertItem(0,str);

	//str.Format(_T("%s"),strtmp);
	str = (CString)strtmp ;
	mainWnd->m_listResult.SetItemText(0,1,str );
}

// ���ñ����ַ�
void Algorithm::setReserveChar( wchar_t reserve )
{
	m_cReserveChar = reserve ;
	return ;
}

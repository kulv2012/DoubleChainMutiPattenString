// SupperDCMM.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSupperDCMMApp:
// �йش����ʵ�֣������ SupperDCMM.cpp
//

class CSupperDCMMApp : public CWinApp
{
public:
	CSupperDCMMApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSupperDCMMApp theApp;
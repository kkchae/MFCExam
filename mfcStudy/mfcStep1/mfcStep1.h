
// mfcStep1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CmfcStep1App:
// �� Ŭ������ ������ ���ؼ��� mfcStep1.cpp�� �����Ͻʽÿ�.
//

class CmfcStep1App : public CWinAppEx
{
public:
	CmfcStep1App();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CmfcStep1App theApp;
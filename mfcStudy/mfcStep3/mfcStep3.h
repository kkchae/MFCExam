
// mfcStep3.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CmfcStep3App:
// �� Ŭ������ ������ ���ؼ��� mfcStep3.cpp�� �����Ͻʽÿ�.
//

class CmfcStep3App : public CWinAppEx
{
public:
	CmfcStep3App();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CmfcStep3App theApp;
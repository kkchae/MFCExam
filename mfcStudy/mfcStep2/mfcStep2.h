
// mfcStep2.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CmfcStep2App:
// �� Ŭ������ ������ ���ؼ��� mfcStep2.cpp�� �����Ͻʽÿ�.
//

class CmfcStep2App : public CWinAppEx
{
public:
	CmfcStep2App();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CmfcStep2App theApp;
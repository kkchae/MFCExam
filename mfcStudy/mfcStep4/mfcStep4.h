
// mfcStep4.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CmfcStep4App:
// �� Ŭ������ ������ ���ؼ��� mfcStep4.cpp�� �����Ͻʽÿ�.
//

class CmfcStep4App : public CWinAppEx
{
public:
	CmfcStep4App();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CmfcStep4App theApp;

// mfcStep3Dlg.h : ��� ����
//

#pragma once
#include "afxext.h"


// CmfcStep3Dlg ��ȭ ����
class CmfcStep3Dlg : public CDialog
{
// �����Դϴ�.
public:
	CmfcStep3Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MFCSTEP3_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

private:
	CBitmapButton *m_pButtonOnOff;
	BOOL m_bButtonOn;
	void InitButtons();
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnOnOff();
};

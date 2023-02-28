#pragma once


// CDlgImage

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = NULL);
	virtual ~CDlgImage();

	enum { IDD = IDD_DLG_IMAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnSendToParent();

private:
	CWnd* m_pParentWnd;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};



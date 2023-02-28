#pragma once

#define MAX_COORD_DATA_SIZE 100
#define COLOR_WHITE		RGB(255, 255, 255)
#define COLOR_BLACK		RGB(0, 0, 0)
#define COLOR_RED		RGB(255,0,0)

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

	CImage m_Image;

private:
	CWnd* m_pParentWnd;
	

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	void InitImage(void);
	void DrawData(CDC* pDC);
	int m_nCoordDataSize;
	CPoint m_ptCoordData[MAX_COORD_DATA_SIZE];
};



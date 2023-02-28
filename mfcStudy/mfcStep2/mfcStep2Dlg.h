
// mfcStep2Dlg.h : 헤더 파일
//

#pragma once


// CmfcStep2Dlg 대화 상자
class CmfcStep2Dlg : public CDialog
{
private:
	CImage m_Image;
	CString m_strImageFilename;

// 생성입니다.
public:
	CmfcStep2Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MFCSTEP2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnImage();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnLoad();
	void UpdateDisplay(void);
	void MoveRect(void);
	afx_msg void OnBnClickedBtnAction();

private:
	BOOL ValidImgPos(int nPosX, int nPosY) const;
	void DrawCircle(unsigned char* fm, int nPosX, int nPosY, int nRadius, int nColor = 0);
	BOOL CheckInnerCircle(int nCenterX, int nCenterY, int nRadius, int nTargetX, int nTargetY) const;
};

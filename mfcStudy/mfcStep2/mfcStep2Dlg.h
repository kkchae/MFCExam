
// mfcStep2Dlg.h : ��� ����
//

#pragma once


// CmfcStep2Dlg ��ȭ ����
class CmfcStep2Dlg : public CDialog
{
private:
	CImage m_Image;
	CString m_strImageFilename;

// �����Դϴ�.
public:
	CmfcStep2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MFCSTEP2_DIALOG };

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


// mfcStep2Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "mfcStep2.h"
#include "mfcStep2Dlg.h"

#include <iostream>
#include <cmath>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CmfcStep2Dlg 대화 상자




CmfcStep2Dlg::CmfcStep2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CmfcStep2Dlg::IDD, pParent)
	, m_strImageFilename(_T("./image/save.bmp"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcStep2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcStep2Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_IMAGE, &CmfcStep2Dlg::OnBnClickedBtnImage)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CmfcStep2Dlg::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_LOAD, &CmfcStep2Dlg::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_ACTION, &CmfcStep2Dlg::OnBnClickedBtnAction)
END_MESSAGE_MAP()


// CmfcStep2Dlg 메시지 처리기

BOOL CmfcStep2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmfcStep2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmfcStep2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmfcStep2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/************************************************************************/
/* step 2-1                                                             */
/************************************************************************/
//void CmfcStep2Dlg::OnBnClickedBtnImage()
//{
//	int nWidth = 640;
//	int nHeight = 480;
//	int nBpp = 8;
//
//	m_Image.Create(nWidth, nHeight, nBpp);
//	if (nBpp == 8) {
//		static RGBQUAD rgb[256];
//		for (int i = 0; i < 256; i++ ) {
//			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
//		}
//		m_Image.SetColorTable(0, 256, rgb);
//	}
//
//	unsigned char* fm = (unsigned char*)m_Image.GetBits();
//	int nPitch = m_Image.GetPitch();
//	//cout << _T("nPitch =") <<  nPitch << endl;
//
//	for(int j = 0; j < nHeight; j++ ) {
//		for (int i = 0; i < nWidth; i++ ) {
//			fm[j*nPitch + i] = j % 255;
//		}
//	}
//
//	fm[(nHeight/2 * nPitch) + (nWidth/2)] = 255; // center
//	fm[0 * nPitch + 0] = 255/2; // left-top
//	fm[(0 * nPitch) + (nWidth-1)] = 255/2; // right-top
//	fm[((nHeight-1) * nPitch) + 0] = 255/2; // left-bottom
//	fm[((nHeight-1) * nPitch) + (nWidth-1)] = 255/2; // right-bottom
//
//	int nColor = 200;
//	for(int j = 0; j < nHeight/2; j++ ) {
//		for (int i = 0; i < nWidth/2; i++ ) {
//			fm[j*nPitch + i] = nColor;
//		}
//	}
//
//
//	CClientDC dc(this);
//	//m_Image.Draw(dc, nWidth/2, nHeight/2);
//	m_Image.Draw(dc, 0, 0);
//	m_Image.Save(_T("./image/save.bmp"));
//}


/************************************************************************/
/* step 2-2                                                             */
/************************************************************************/
void CmfcStep2Dlg::OnBnClickedBtnImage()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_Image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++ ) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		}
		m_Image.SetColorTable(0, 256, rgb);
	}

	unsigned char* fm = (unsigned char*)m_Image.GetBits();
	int nPitch = m_Image.GetPitch();
	//cout << _T("nPitch =") <<  nPitch << endl;

	int nColor = 255; // 0~255
	memset(fm, nColor, sizeof(unsigned char)*nWidth*nHeight);

	/*for(int j = 0; j < nHeight; j++ ) {
		for (int i = 0; i < nWidth; i++ ) {
			fm[j*nPitch + i] = j % 255;
		}
	}*/

	//fm[(nHeight/2 * nPitch) + (nWidth/2)] = 255; // center
	//fm[0 * nPitch + 0] = 255/2; // left-top
	//fm[(0 * nPitch) + (nWidth-1)] = 255/2; // right-top
	//fm[((nHeight-1) * nPitch) + 0] = 255/2; // left-bottom
	//fm[((nHeight-1) * nPitch) + (nWidth-1)] = 255/2; // right-bottom


	//for(int j = 0; j < nHeight/2; j++ ) {
	//	for (int i = 0; i < nWidth/2; i++ ) {
	//		fm[j*nPitch + i] = nColor;
	//	}
	//}
	

	UpdateDisplay();
}

void CmfcStep2Dlg::OnBnClickedBtnSave()
{
	if(m_Image) {
		m_Image.Save(m_strImageFilename);
	}
}

void CmfcStep2Dlg::OnBnClickedBtnLoad()
{
	if(m_Image != NULL) {
		m_Image.Destroy();
	}

	m_Image.Load(m_strImageFilename);
	UpdateDisplay();
}

void CmfcStep2Dlg::UpdateDisplay( void )
{
	CClientDC dc(this);
	m_Image.Draw(dc, 0, 0);
}

//void CmfcStep2Dlg::MoveRect( void )
//{
//	if(m_Image == NULL)
//	{
//		AfxMessageBox(_T("Image not created"));
//	}
//	else
//	{
//		static int nStartPosX = 0;
//		static int nStartPosY = 0;
//
//		int nWidth = m_Image.GetWidth();
//		int nHeight = m_Image.GetHeight();
//		unsigned char* fm = (unsigned char*)m_Image.GetBits();
//		int nPitch = m_Image.GetPitch();
//		int nGray = 80;
//		int nColor = 255; // 0~255
//		memset(fm, nColor, sizeof(unsigned char)*nWidth*nHeight);
//
//		for(int j=nStartPosX; j<nStartPosX+48; j++) {
//			for(int i=nStartPosY; i<nStartPosY+64; i++) {
//				if (ValidImgPos(i, j)) {
//					fm[j*nPitch + i] = nGray;
//				} 
//				else
//				{
//				}
//			}
//		}
//		
//		nStartPosX++;
//		nStartPosY++;
//
//		UpdateDisplay();
//	}
//}

void CmfcStep2Dlg::OnBnClickedBtnAction()
{
	for (int i=0; i<480; i++)
	{
		MoveRect();
		Sleep(5);
	}

}

BOOL CmfcStep2Dlg::ValidImgPos( int nPosX, int nPosY ) const
{
	int nWidth = m_Image.GetWidth();
	int nHeight = m_Image.GetHeight();
	CRect rect(0, 0, nWidth, nHeight);
	return rect.PtInRect(CPoint(nPosX, nPosY));
}

/************************************************************************/
/* step 2-3                                                             */
/************************************************************************/
void CmfcStep2Dlg::MoveRect( void )
{
	if(m_Image == NULL)
	{
		AfxMessageBox(_T("Image not created"));
	}
	else
	{
		static int nStartPosX = 0;
		static int nStartPosY = 0;

		int nWidth = m_Image.GetWidth();
		int nHeight = m_Image.GetHeight();
		unsigned char* fm = (unsigned char*)m_Image.GetBits();
		int nPitch = m_Image.GetPitch();
		int nGray = 80;
		int nRadius = 20;
		int nInitColor = 255; // 0~255

		//memset(fm, nInitColor, sizeof(unsigned char) * nWidth * nHeight);

		DrawCircle(fm, nStartPosX++, nStartPosY++, nRadius, nInitColor);
		DrawCircle(fm, nStartPosX, nStartPosY, nRadius, nGray);

		UpdateDisplay();
	}
}

void CmfcStep2Dlg::DrawCircle( unsigned char* fm, int nPosX, int nPosY, int nRadius, int nGary /*= 0*/ )
{
	int nWidth = m_Image.GetWidth();
	int nHeight = m_Image.GetHeight();
	int nPitch = m_Image.GetPitch();

	for (int j = nPosY - nRadius; j < nPosY + nRadius; j++) {
		for (int i = nPosX - nRadius; i < nPosX + nRadius; i++) {
			if ((j >= 0 && i >= 0) && (j < nHeight - nRadius && i < nWidth - nRadius)) {
				if (CheckInnerCircle(nPosX, nPosY, nRadius, i, j)) {
					fm[j*nPitch + i] = nGary;
				}
			}
		}
	}
}

BOOL CmfcStep2Dlg::CheckInnerCircle( int nCenterX, int nCenterY, int nRadius, int nTargetX, int nTargetY ) const
{
	BOOL bRet = FALSE;
	double dX = nTargetX - nCenterX;
	double dY = nTargetY - nCenterY;

	if( (dX*dX + dY*dY) <= nRadius*nRadius )
		bRet = TRUE;

	return bRet;
}

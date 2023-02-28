// DlgImage.cpp : implementation file
//

#include "stdafx.h"
#include "mfcStep4.h"
#include "DlgImage.h"

#include "mfcStep4Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDlgImage

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=NULL*/)
: CDialogEx(CDlgImage::IDD, pParent)
{
	m_pParentWnd = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange( CDataExchange* pDX )
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_SEND_TO_PARENT, &CDlgImage::OnBnClickedBtnSendToParent)
	ON_WM_CREATE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage message handlers



void CDlgImage::OnBnClickedBtnSendToParent()
{
	// TODO: Add your control notification handler code here
	CmfcStep4Dlg* pDlg = (CmfcStep4Dlg*)m_pParentWnd;
	if (pDlg) {
		pDlg->SendMsg(_T("Hello, I'm child dialog"));
	}
}

int CDlgImage::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	//m_pParentWnd = CWnd::FromHandle(lpCreateStruct->hwndParent);

	return 0;
}

BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	MoveWindow(0, 0, 640, 480);
	InitImage();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages

	if (m_Image) {
		m_Image.Draw(dc, 0, 0);
	}
}

void CDlgImage::InitImage( void )
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
}

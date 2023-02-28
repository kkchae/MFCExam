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

// FileDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TicTacToe20160316_1.h"
#include "FileDlg.h"
#include "afxdialogex.h"


// CFileDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFileDlg, CDialogEx)

CFileDlg::CFileDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FileDlg, pParent)
	// m_fileStr(_T(""))
	, m_fileString(_T(""))
{

}

CFileDlg::~CFileDlg()
{
}

void CFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT1, m_fileStr);
	DDX_Text(pDX, IDC_EDIT1, m_fileString);
}


BEGIN_MESSAGE_MAP(CFileDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CFileDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CFileDlg 메시지 처리기입니다.


void CFileDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}

// FileDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TicTacToe20160316_1.h"
#include "FileDlg.h"
#include "afxdialogex.h"


// CFileDlg ��ȭ �����Դϴ�.

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


// CFileDlg �޽��� ó�����Դϴ�.


void CFileDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnOK();
}

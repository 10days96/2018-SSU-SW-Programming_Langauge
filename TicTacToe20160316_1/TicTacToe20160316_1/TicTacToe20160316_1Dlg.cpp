
// TicTacToe20160316_1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "TicTacToe20160316_1.h"
#include "TicTacToe20160316_1Dlg.h"
#include "afxdialogex.h"
#include "FileDlg.h"
//#include <queue>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTicTacToe20160316_1Dlg ��ȭ ����



CTicTacToe20160316_1Dlg::CTicTacToe20160316_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TICTACTOE20160316_1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTicTacToe20160316_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Control(pDX, IDC_UNDO, m_undo);
}

BEGIN_MESSAGE_MAP(CTicTacToe20160316_1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CTicTacToe20160316_1Dlg::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CTicTacToe20160316_1Dlg::OnBnClickedButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CTicTacToe20160316_1Dlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_START, &CTicTacToe20160316_1Dlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_P1, &CTicTacToe20160316_1Dlg::OnBnClickedP1)
	ON_BN_CLICKED(IDC_P2, &CTicTacToe20160316_1Dlg::OnBnClickedP2)
	ON_BN_CLICKED(IDC_P3, &CTicTacToe20160316_1Dlg::OnBnClickedP3)
	ON_BN_CLICKED(IDC_P4, &CTicTacToe20160316_1Dlg::OnBnClickedP4)
	ON_BN_CLICKED(IDC_P5, &CTicTacToe20160316_1Dlg::OnBnClickedP5)
	ON_BN_CLICKED(IDC_P6, &CTicTacToe20160316_1Dlg::OnBnClickedP6)
	ON_BN_CLICKED(IDC_P7, &CTicTacToe20160316_1Dlg::OnBnClickedP7)
	ON_BN_CLICKED(IDC_P8, &CTicTacToe20160316_1Dlg::OnBnClickedP8)
	ON_BN_CLICKED(IDC_P9, &CTicTacToe20160316_1Dlg::OnBnClickedP9)
	ON_BN_CLICKED(IDC_P10, &CTicTacToe20160316_1Dlg::OnBnClickedP10)
	ON_BN_CLICKED(IDC_P11, &CTicTacToe20160316_1Dlg::OnBnClickedP11)
	ON_BN_CLICKED(IDC_P12, &CTicTacToe20160316_1Dlg::OnBnClickedP12)
	ON_BN_CLICKED(IDC_P13, &CTicTacToe20160316_1Dlg::OnBnClickedP13)
	ON_BN_CLICKED(IDC_P14, &CTicTacToe20160316_1Dlg::OnBnClickedP14)
	ON_BN_CLICKED(IDC_P15, &CTicTacToe20160316_1Dlg::OnBnClickedP15)
	ON_BN_CLICKED(IDC_P16, &CTicTacToe20160316_1Dlg::OnBnClickedP16)
	ON_BN_CLICKED(IDC_UNDO, &CTicTacToe20160316_1Dlg::OnBnClickedUndo)
END_MESSAGE_MAP()


// CTicTacToe20160316_1Dlg �޽��� ó����

BOOL CTicTacToe20160316_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

									// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_isLoad = 0;
	m_checkUndo = 0;
	//checkFirstTurn = FALSE;
	SetGame();
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CTicTacToe20160316_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CTicTacToe20160316_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CTicTacToe20160316_1Dlg::SetGame()
{
	m_combo.AddString(_T("Level 3"));
	m_combo.AddString(_T("Level 5"));

	m_combo.SetCurSel(0);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(_T("<���� Ʈ��>"));

	for(int i = 0; i < 16; i++)
		GetDlgItem(IDC_A1 + i) ->EnableWindow(FALSE);
	
	GetDlgItem(IDC_UNDO) ->EnableWindow(FALSE);
	newGame = FALSE;
}


void CTicTacToe20160316_1Dlg::ResetGame()
{
	CString str;
	int count = 0;

	UpdateData(FALSE);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			str.Format(_T("%d"), count + 1);
			SetDlgItemText(1022 + count, str);
			SetDlgItemText(1004 + count, str);
			count++;
			m_board.board[i][j] = ' ';
		}
	}

	GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"<���� Ʈ��>");
	m_board.state = GameBoard::STATE_INIT;

	for (int i = 0; i < 16; i++) {
		GetDlgItem(IDC_A1 + i)->EnableWindow(FALSE);
		GetDlgItem(IDC_P1 + i)->EnableWindow(TRUE);
	}

	GetDlgItem(IDC_UNDO) ->EnableWindow(FALSE);
	m_board.moveCnt = 0;
	newGame = FALSE;
	checkEndGame = FALSE;

}


void CTicTacToe20160316_1Dlg::EndGame()
{
	switch (m_board.state)
	{
	case GameBoard::STATE_WINP:
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"���ӿ� �̰���ϴ�.");
		for (int i = 0; i < 16; i++)
			GetDlgItem(IDC_P1 + i)->EnableWindow(FALSE);
			m_undo.EnableWindow(FALSE);
			checkEndGame = TRUE;
		break;

	case GameBoard::STATE_WINC:
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"���ӿ� �����ϴ�.");
		for (int i = 0; i < 16; i++)
			GetDlgItem(IDC_P1 + i)->EnableWindow(FALSE);
			m_undo.EnableWindow(FALSE);
			checkEndGame = TRUE;
		break;

	case GameBoard::STATE_DRAW:
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"���ӿ� �����ϴ�.");
		for (int i = 0; i < 16; i++)
			GetDlgItem(IDC_P1 + i)->EnableWindow(FALSE);
			m_undo.EnableWindow(FALSE);
			checkEndGame = TRUE;
		break;

	case GameBoard::STATE_INIT:
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"<���� Ʈ��>");
		break;

	case GameBoard::STATE_STOP:
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"������ �ߴ܉���ϴ�.");
		break;
	}
}


int CTicTacToe20160316_1Dlg::CheckReady()
{
	UpdateData(TRUE);

	int level_c = m_combo.GetCurSel();

	if (level_c == -1)
		return -1;
	else if (m_startCom == -1)
		return 0;

	else
	{
		switch (level_c)
		{
		case 0: m_levelC = 3; break;
		case 1: m_levelC = 5; break;
		}
		return 1;
	}
	//return 1;
}

void CTicTacToe20160316_1Dlg::UpdateGame()
{
	int count = 0;
	int comButton = 0;
	CString str;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (m_board.board[i][j] == 'X') {
				SetDlgItemText(IDC_P1 + count, L"X");
				SetDlgItemText(IDC_A1 + count, L"X");
				GetDlgItem(IDC_P1 + count) -> EnableWindow(FALSE);
				GetDlgItem(IDC_A1 + count) -> EnableWindow(FALSE);

			}
			else if (m_board.board[i][j] == 'O') {
				SetDlgItemText(IDC_P1 + count, L"O");
				SetDlgItemText(IDC_A1 + count, L"O");
				GetDlgItem(IDC_P1 + count)->EnableWindow(FALSE);
				GetDlgItem(IDC_A1 + count)->EnableWindow(FALSE);
			}
			else
			{
				str.Format(L"%d", count + 1);
				SetDlgItemText(IDC_P1 + count, str);
				SetDlgItemText(IDC_A1 + count, str);
				GetDlgItem(IDC_P1 + count)->EnableWindow(TRUE);
			}
			count++;
		}
	}

	count = 0;
	if (m_board.state != GameBoard::STATE_PLAY)
	{
		for (int i = 0; i<4; i++)
		{
			for (int j = 0; j<4; j++)
			{
				if (m_board.board[i][j] == 'X')
				{
					SetDlgItemText(IDC_P1 + count, L"X");
					SetDlgItemText(IDC_A1 + count, L"X");
				}
				else if (m_board.board[i][j] == 'O')
				{
					SetDlgItemText(IDC_P1 + count, L"O");
					SetDlgItemText(IDC_A1 + count, L"O");
				}
				else
				{
					str.Format(L"%d", count + 1);
					SetDlgItemText(IDC_P1 + count, str);
					SetDlgItemText(IDC_A1 + count, str);
				}
				count++;
			}
		}
	}
}


void CTicTacToe20160316_1Dlg::LoadGame()
{
	CFileDlg dlg;

	if (m_board.state == GameBoard::STATE_PLAY)	/* �ҷ����� ������ ������������ �˻� */
	{
		MessageBox(L"������ �������Դϴ�! �����ϰ� �õ��ϼ���.", L"�� ��", MB_ICONEXCLAMATION);
		return;
	}

	if (dlg.DoModal() == IDOK)
	{
		FILE *fp;						/* ���� ������ ���� */
		CStringA name(dlg.m_fileString);

		if (!(fp = fopen(name, "r")))
		{
			MessageBox(L"������ �� �� �����ϴ�! ���ϸ��� Ȯ���ϼ���.", L"ERROR", MB_ICONERROR);
			return;
		}
		else		/* ����� ���� �����̶�� */
		{
			int i, j, stoneCount = 0;
			int Acnt = 0, Bcnt = 0;
			char temp[5];

			for (i = 0; i<4; i++)
			{
				fscanf_s(fp, "%s", temp, 5);	/* �ش����Ͽ��� ������ ������ */
				for (j = 0; j<4; j++)				/* ���ڿ� �°� �����ǿ� �Է� */
				{
					if (temp[j] == 'X')
					{
						m_board.board[i][j] = 'X';
						Acnt++;
					}
					else if (temp[j] == 'O')
					{
						m_board.board[i][j] = 'O';
						Bcnt++;
					}
					else
						m_board.board[i][j] = ' ';
				}
			}

			m_startCom = 0;
			UpdateData(FALSE);
			m_isLoad = Acnt + Bcnt;
			UpdateGame();
			GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"<���� Ʈ��>");
			fclose(fp);

		}
	}
	newGame = TRUE;
	StartGame();
}


void CTicTacToe20160316_1Dlg::SaveGame()
{
	FILE *fp;

	fp = fopen("Save.txt", "w");
	char temp[6] = {'\0'};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (m_board.board[i][j] != ' ') {
				temp[j] = m_board.board[i][j];
			}
			else {
				temp[j] = 'B';
			}
		}
			temp[4] = '\n'; temp[5] = '\0';
			fprintf_s(fp, "%s", temp);
	}
	fclose(fp);
}

void CTicTacToe20160316_1Dlg::OnBnClickedButtonStart()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int check;

	if (m_board.state == GameBoard::STATE_PLAY)
	{
		check = MessageBox(L"���� �������Դϴ�.\n������ �ٽ� �Ͻðڽ��ϱ�?", L"�� ����", MB_OKCANCEL);
		if (check == IDOK) {
			//m_board.state = GameBoard::STATE_INIT;
			ResetGame();
		}
	}

	else {
		ResetGame();
		StartGame();
		newGame = TRUE;
	}
}

void CTicTacToe20160316_1Dlg::OnBnClickedButtonLoad()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	LoadGame();
	//m_isLoad = 1;
}


void CTicTacToe20160316_1Dlg::OnBnClickedButtonSave()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SaveGame();
}

void CTicTacToe20160316_1Dlg::OnBnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int conclusion;

	if (m_board.state == GameBoard::STATE_PLAY)
	{
		conclusion = MessageBox(_T("���� �������Դϴ�.\n������ �ߴ� �Ͻðڽ��ϱ�?"), _T("���� �ߴ�"), MB_OKCANCEL);
		if (conclusion == IDOK)
			m_board.state = GameBoard::STATE_STOP;
	}
	else {
		conclusion = MessageBox(_T("������ ���� �Ͻðڽ��ϱ�?"), _T("���� ����"), MB_OKCANCEL);
		if (conclusion == IDOK)
			::SendMessage(this->m_hWnd, WM_CLOSE, NULL, NULL);
	}
}
void CTicTacToe20160316_1Dlg::OnBnClickedP1()
{
	if (newGame) {
		GetDlgItem(IDC_P1)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(0, 0);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CTicTacToe20160316_1Dlg::OnBnClickedP2()
{
	if (newGame) {
		GetDlgItem(IDC_P2)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(0, 1);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");

}


void CTicTacToe20160316_1Dlg::OnBnClickedP3()
{
	if (newGame) {
		GetDlgItem(IDC_P3)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(0, 2);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (newGame) {
		GetDlgItem(IDC_P4)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(0, 3);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (newGame) {
		GetDlgItem(IDC_P5)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(1, 0);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (newGame) {
		GetDlgItem(IDC_P6)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(1, 1);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (newGame) {
		GetDlgItem(IDC_P7)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(1, 2);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (newGame) {
		GetDlgItem(IDC_P8)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(1, 3);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (newGame) {
		GetDlgItem(IDC_P9)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(2, 0);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");

}


void CTicTacToe20160316_1Dlg::OnBnClickedP10()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (newGame) {
		GetDlgItem(IDC_P10)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(2, 1);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");

}


void CTicTacToe20160316_1Dlg::OnBnClickedP11()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (newGame) {
		GetDlgItem(IDC_P11)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(2, 2);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP12()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (newGame) {
		GetDlgItem(IDC_P12)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(2, 3);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP13()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (newGame) {
		GetDlgItem(IDC_P13)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(3, 0);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");

}


void CTicTacToe20160316_1Dlg::OnBnClickedP14()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (newGame) {
		GetDlgItem(IDC_P14)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(3, 1);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP15()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (newGame) {
		GetDlgItem(IDC_P15)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(3, 2);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");

}


void CTicTacToe20160316_1Dlg::OnBnClickedP16()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (newGame) {
		GetDlgItem(IDC_P3)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(3, 3);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"�� ���� ��ư�� ���� �ּ���");


}


void CTicTacToe20160316_1Dlg::OnBnClickedUndo()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int x = m_board.preMoves[m_board.moveCnt-1].x;
	int y = m_board.preMoves[m_board.moveCnt-1].y;

	if (m_board.moveCnt - 2 >= 0) {
		if (x >= 0 && x <= 15 && y >= 0 && y <= 15) {
		m_board.UndoMove();
		m_board.UndoMove();
		UpdateGame();
		}

		else
			MessageBox(L"�� �̻� ���� ���� �����ϴ�.");
		}
	else{
		MessageBox(L"�� �̻� ���� ���� �����ϴ�.");
	}
}

void CTicTacToe20160316_1Dlg::StartGame()
{
	int checkErr, id;
	checkErr = CheckReady();
	m_board.CheckState();

	if (checkErr == 1) {
		if (m_board.state == GameBoard::STATE_PLAY) {
			GameAI* AI = new GameAI(m_board);

			AI->GetBestMove();							/* ������ ��ǥ�� ���� */
			m_board.DoMove(AI->bestX, AI->bestY);		/* �ش� ��ǥ�� ���� �� */

			Node* node = AI->GetRootNode();			/* ������ ��ǥ�� ���ϴµ��� ������ Ʈ�� �� ��Ʈ��� ��ȯ */
			this->PrintTreeNode(node);					/* Ʈ�� ��� */

			UpdateGame();							/* ������ ������Ʈ */

			delete AI;
			delete node;
			m_board.CheckState();			/* ������ ���¸� ���� */
			if (m_board.state != GameBoard::STATE_PLAY)
				EndGame();					/* �÷��� ���� �ƴ� ���¸� ���� ���� */
		}
		else {
			EndGame();
			return;
		}
		if (!checkEndGame)
		UpdateGame();	/* ���� �����ǿ��� ��� */
	}
}


void CTicTacToe20160316_1Dlg::PrintTreeNode(Node* root)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int preDepth = 0;			/* ���� ����� ���� */
	bool preParent = false;		/* �θ� ������ ���� ���� */
	Node *pNode = root;			/* ��Ʈ��带 ���� */
	CString temp, temp2;
	queue <Node* > que;			/* ť ���� */

	que.push(pNode);			/* ť�� ��Ʈ��带 �ְ� */
	while (!que.empty())			/* ť�� ������� �� ���� ��� */
	{
		pNode = que.front();	/* �տ��� ������ */
		que.pop();
		if (pNode != NULL)		/* NULL ���� �ƴϰ� */
		{
			if (preDepth != pNode->depth)	/* ���� ��尪�� ���̰� �ٸ��� */
				temp = temp + (L"\r\n");	/* ���� */

			if (preParent)					/* �θ��尡 ������ */
				temp = temp + (L", ");		/* �̾ ��� */
			else
				temp = temp + (L"(");		/* �ٸ��� '(' �� ���� */

			temp2.Format(L"%d", pNode->eval);
			temp = temp + temp2;

			preParent = true;

			if (pNode->childCnt != 0)		/* �ڽĳ�� ������ 0�� �ƴϸ� */
			{
				que.push(NULL);				/* NULL ������ �θ��� ���� ���ְ� */
				for (int j = 0; j < pNode->childCnt; j++)
					que.push(pNode->next[j]);		/* �ڽĳ�带 ť�� ���� */

			}
			preDepth = pNode->depth;				/* ��� ���̸� ���� */
		}
		else							/* ť���� ������ NULL �� �̶�� */
		{
			temp = temp + (L")");		/* ')' �� �θ��带 ���� */
			preParent = false;
		}
	}
	temp = temp + (L")");

	GetDlgItem(IDC_EDIT1)->SetWindowTextW(temp);

}


void CTicTacToe20160316_1Dlg::FirstClick(){
	if (m_board.state != GameBoard::STATE_PLAY) /* �������� �ƴ϶��*/
	{
		if (m_isLoad != 0)		/* �ҷ��� �����̶��, */
		{						/* �ҷ��� ���� ������ ������ �ʱ�ȭ */
			CheckReady();
			m_board.InitBoard(0, m_isLoad, m_levelC);
		}
		else {
			CheckReady();
			m_board.InitBoard(0, 0, m_levelC);	/* �ƴ϶��, ���ο� ������ �ʱ�ȭ */
		}
	}
		m_isLoad = 0;
		UpdateGame();
		m_board.state = GameBoard::STATE_PLAY;	/* ������ ���¸� �÷��� ������ ���� */
}


// TicTacToe20160316_1Dlg.cpp : 구현 파일
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


// CTicTacToe20160316_1Dlg 대화 상자



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


// CTicTacToe20160316_1Dlg 메시지 처리기

BOOL CTicTacToe20160316_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

									// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_isLoad = 0;
	m_checkUndo = 0;
	//checkFirstTurn = FALSE;
	SetGame();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTicTacToe20160316_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

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
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTicTacToe20160316_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CTicTacToe20160316_1Dlg::SetGame()
{
	m_combo.AddString(_T("Level 3"));
	m_combo.AddString(_T("Level 5"));

	m_combo.SetCurSel(0);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(_T("<게임 트리>"));

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

	GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"<게임 트리>");
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
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"게임에 이겼습니다.");
		for (int i = 0; i < 16; i++)
			GetDlgItem(IDC_P1 + i)->EnableWindow(FALSE);
			m_undo.EnableWindow(FALSE);
			checkEndGame = TRUE;
		break;

	case GameBoard::STATE_WINC:
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"게임에 졌습니다.");
		for (int i = 0; i < 16; i++)
			GetDlgItem(IDC_P1 + i)->EnableWindow(FALSE);
			m_undo.EnableWindow(FALSE);
			checkEndGame = TRUE;
		break;

	case GameBoard::STATE_DRAW:
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"게임에 비겼습니다.");
		for (int i = 0; i < 16; i++)
			GetDlgItem(IDC_P1 + i)->EnableWindow(FALSE);
			m_undo.EnableWindow(FALSE);
			checkEndGame = TRUE;
		break;

	case GameBoard::STATE_INIT:
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"<게임 트리>");
		break;

	case GameBoard::STATE_STOP:
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"게임이 중단됬습니다.");
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

	if (m_board.state == GameBoard::STATE_PLAY)	/* 불러오는 시점이 게임중인지를 검사 */
	{
		MessageBox(L"지금은 게임중입니다! 종료하고 시도하세요.", L"경 고", MB_ICONEXCLAMATION);
		return;
	}

	if (dlg.DoModal() == IDOK)
	{
		FILE *fp;						/* 파일 포인터 선언 */
		CStringA name(dlg.m_fileString);

		if (!(fp = fopen(name, "r")))
		{
			MessageBox(L"파일을 열 수 없습니다! 파일명을 확인하세요.", L"ERROR", MB_ICONERROR);
			return;
		}
		else		/* 제대로 열린 파일이라면 */
		{
			int i, j, stoneCount = 0;
			int Acnt = 0, Bcnt = 0;
			char temp[5];

			for (i = 0; i<4; i++)
			{
				fscanf_s(fp, "%s", temp, 5);	/* 해당파일에서 한줄을 읽은뒤 */
				for (j = 0; j<4; j++)				/* 문자에 맞게 게임판에 입력 */
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
			GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"<게임 트리>");
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int check;

	if (m_board.state == GameBoard::STATE_PLAY)
	{
		check = MessageBox(L"현재 게임중입니다.\n게임을 다시 하시겠습니까?", L"새 게임", MB_OKCANCEL);
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	LoadGame();
	//m_isLoad = 1;
}


void CTicTacToe20160316_1Dlg::OnBnClickedButtonSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SaveGame();
}

void CTicTacToe20160316_1Dlg::OnBnClickedButtonExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int conclusion;

	if (m_board.state == GameBoard::STATE_PLAY)
	{
		conclusion = MessageBox(_T("현재 게임중입니다.\n게임을 중단 하시겠습니까?"), _T("게임 중단"), MB_OKCANCEL);
		if (conclusion == IDOK)
			m_board.state = GameBoard::STATE_STOP;
	}
	else {
		conclusion = MessageBox(_T("게임을 종료 하시겠습니까?"), _T("게임 종료"), MB_OKCANCEL);
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
		MessageBox(L"새 게임 버튼을 눌러 주세요");
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
		MessageBox(L"새 게임 버튼을 눌러 주세요");

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
		MessageBox(L"새 게임 버튼을 눌러 주세요");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (newGame) {
		GetDlgItem(IDC_P4)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(0, 3);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"새 게임 버튼을 눌러 주세요");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (newGame) {
		GetDlgItem(IDC_P5)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(1, 0);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"새 게임 버튼을 눌러 주세요");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (newGame) {
		GetDlgItem(IDC_P6)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(1, 1);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"새 게임 버튼을 눌러 주세요");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (newGame) {
		GetDlgItem(IDC_P7)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(1, 2);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"새 게임 버튼을 눌러 주세요");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (newGame) {
		GetDlgItem(IDC_P8)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(1, 3);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"새 게임 버튼을 눌러 주세요");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (newGame) {
		GetDlgItem(IDC_P9)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(2, 0);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"새 게임 버튼을 눌러 주세요");

}


void CTicTacToe20160316_1Dlg::OnBnClickedP10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (newGame) {
		GetDlgItem(IDC_P10)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(2, 1);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"새 게임 버튼을 눌러 주세요");

}


void CTicTacToe20160316_1Dlg::OnBnClickedP11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (newGame) {
		GetDlgItem(IDC_P11)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(2, 2);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"새 게임 버튼을 눌러 주세요");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (newGame) {
		GetDlgItem(IDC_P12)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(2, 3);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"새 게임 버튼을 눌러 주세요");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (newGame) {
		GetDlgItem(IDC_P13)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(3, 0);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"새 게임 버튼을 눌러 주세요");

}


void CTicTacToe20160316_1Dlg::OnBnClickedP14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (newGame) {
		GetDlgItem(IDC_P14)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(3, 1);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"새 게임 버튼을 눌러 주세요");


}


void CTicTacToe20160316_1Dlg::OnBnClickedP15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (newGame) {
		GetDlgItem(IDC_P15)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(3, 2);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"새 게임 버튼을 눌러 주세요");

}


void CTicTacToe20160316_1Dlg::OnBnClickedP16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (newGame) {
		GetDlgItem(IDC_P3)->EnableWindow(FALSE);
		FirstClick();
		m_board.DoMove(3, 3);
		StartGame();
		m_undo.EnableWindow(TRUE);
	}
	else
		MessageBox(L"새 게임 버튼을 눌러 주세요");


}


void CTicTacToe20160316_1Dlg::OnBnClickedUndo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int x = m_board.preMoves[m_board.moveCnt-1].x;
	int y = m_board.preMoves[m_board.moveCnt-1].y;

	if (m_board.moveCnt - 2 >= 0) {
		if (x >= 0 && x <= 15 && y >= 0 && y <= 15) {
		m_board.UndoMove();
		m_board.UndoMove();
		UpdateGame();
		}

		else
			MessageBox(L"더 이상 무를 수가 없습니다.");
		}
	else{
		MessageBox(L"더 이상 무를 수가 없습니다.");
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

			AI->GetBestMove();							/* 최적의 좌표를 구함 */
			m_board.DoMove(AI->bestX, AI->bestY);		/* 해당 좌표에 수를 둠 */

			Node* node = AI->GetRootNode();			/* 최적의 좌표를 구하는동안 저장한 트리 중 루트노드 반환 */
			this->PrintTreeNode(node);					/* 트리 출력 */

			UpdateGame();							/* 게임판 업데이트 */

			delete AI;
			delete node;
			m_board.CheckState();			/* 게임판 상태를 점검 */
			if (m_board.state != GameBoard::STATE_PLAY)
				EndGame();					/* 플레이 중이 아닌 상태면 게임 종료 */
		}
		else {
			EndGame();
			return;
		}
		if (!checkEndGame)
		UpdateGame();	/* 상대방 보드판에도 출력 */
	}
}


void CTicTacToe20160316_1Dlg::PrintTreeNode(Node* root)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int preDepth = 0;			/* 이전 노드의 깊이 */
	bool preParent = false;		/* 부모가 같은지 여부 점검 */
	Node *pNode = root;			/* 루트노드를 복사 */
	CString temp, temp2;
	queue <Node* > que;			/* 큐 생성 */

	que.push(pNode);			/* 큐에 루트노드를 넣고 */
	while (!que.empty())			/* 큐가 비어있을 때 까지 출력 */
	{
		pNode = que.front();	/* 앞에서 꺼내서 */
		que.pop();
		if (pNode != NULL)		/* NULL 값이 아니고 */
		{
			if (preDepth != pNode->depth)	/* 이전 노드값과 깊이가 다르면 */
				temp = temp + (L"\r\n");	/* 개행 */

			if (preParent)					/* 부모노드가 같으면 */
				temp = temp + (L", ");		/* 이어서 출력 */
			else
				temp = temp + (L"(");		/* 다르면 '(' 로 구분 */

			temp2.Format(L"%d", pNode->eval);
			temp = temp + temp2;

			preParent = true;

			if (pNode->childCnt != 0)		/* 자식노드 개수가 0이 아니면 */
			{
				que.push(NULL);				/* NULL 값으로 부모노드 구분 해주고 */
				for (int j = 0; j < pNode->childCnt; j++)
					que.push(pNode->next[j]);		/* 자식노드를 큐에 넣음 */

			}
			preDepth = pNode->depth;				/* 노드 깊이를 변경 */
		}
		else							/* 큐에서 꺼낸게 NULL 값 이라면 */
		{
			temp = temp + (L")");		/* ')' 로 부모노드를 구분 */
			preParent = false;
		}
	}
	temp = temp + (L")");

	GetDlgItem(IDC_EDIT1)->SetWindowTextW(temp);

}


void CTicTacToe20160316_1Dlg::FirstClick(){
	if (m_board.state != GameBoard::STATE_PLAY) /* 게임중이 아니라면*/
	{
		if (m_isLoad != 0)		/* 불러온 게임이라면, */
		{						/* 불러온 게임 정보로 보드판 초기화 */
			CheckReady();
			m_board.InitBoard(0, m_isLoad, m_levelC);
		}
		else {
			CheckReady();
			m_board.InitBoard(0, 0, m_levelC);	/* 아니라면, 새로운 판으로 초기화 */
		}
	}
		m_isLoad = 0;
		UpdateGame();
		m_board.state = GameBoard::STATE_PLAY;	/* 보드판 상태를 플레이 중으로 변경 */
}

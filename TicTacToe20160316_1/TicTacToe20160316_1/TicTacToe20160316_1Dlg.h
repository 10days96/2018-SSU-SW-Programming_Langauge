
// TicTacToe20160316_1Dlg.h : 헤더 파일
//
#include "TicTacToeAI.h"
#include <iostream>
#include <queue>
#include "afxwin.h"

// CTicTacToe20160316_1Dlg 대화 상자
class CTicTacToe20160316_1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CTicTacToe20160316_1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TICTACTOE20160316_1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedP1();
	afx_msg void OnBnClickedP2();
	afx_msg void OnBnClickedP3();
	afx_msg void OnBnClickedP4();
	afx_msg void OnBnClickedP5();
	afx_msg void OnBnClickedP6();
	afx_msg void OnBnClickedP7();
	afx_msg void OnBnClickedP8();
	afx_msg void OnBnClickedP9();
	afx_msg void OnBnClickedP10();
	afx_msg void OnBnClickedP11();
	afx_msg void OnBnClickedP12();
	afx_msg void OnBnClickedP13();
	afx_msg void OnBnClickedP14();
	afx_msg void OnBnClickedP15();
	afx_msg void OnBnClickedP16();
	afx_msg void OnBnClickedUndo();

	/*사용자 정의 변수, 함수*/
	GameBoard m_board;
	CComboBox m_combo;
	CButton m_undo;
	bool newGame;
	bool checkEndGame;
	int playerTurn;
	int m_levelC;			/* 컴퓨터 A의 LA-level */		
	int m_startCom;			/* 시작하는 COM 종류 */
	int m_isLoad;			/* 게임이 로드 된 건지 구분 */
	int m_checkUndo;		/* 무르기를 했는지 여부 구분 */
	bool checkFirstTurn;

	void SetGame();
	void ResetGame();
	void EndGame();
	int CheckReady();
	void UpdateGame();
	void LoadGame();
	void SaveGame();
	void StartGame();
	void PrintTreeNode(Node* root);
	void FirstClick();
};

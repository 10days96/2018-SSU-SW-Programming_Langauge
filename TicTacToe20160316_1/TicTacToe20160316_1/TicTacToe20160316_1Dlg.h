
// TicTacToe20160316_1Dlg.h : ��� ����
//
#include "TicTacToeAI.h"
#include <iostream>
#include <queue>
#include "afxwin.h"

// CTicTacToe20160316_1Dlg ��ȭ ����
class CTicTacToe20160316_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CTicTacToe20160316_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TICTACTOE20160316_1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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

	/*����� ���� ����, �Լ�*/
	GameBoard m_board;
	CComboBox m_combo;
	CButton m_undo;
	bool newGame;
	bool checkEndGame;
	int playerTurn;
	int m_levelC;			/* ��ǻ�� A�� LA-level */		
	int m_startCom;			/* �����ϴ� COM ���� */
	int m_isLoad;			/* ������ �ε� �� ���� ���� */
	int m_checkUndo;		/* �����⸦ �ߴ��� ���� ���� */
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

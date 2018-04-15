#pragma once
typedef struct position		/* x,y ��ǥ ��Ÿ���� ����ü */
{
	int x;
	int y;
}Position;

typedef struct treeNode		/* ����� ���� ��� ����ü */
{
	int depth;				/* ���� ����� ���� */
	int eval;				/* ���� ������ �򰡰� */
	int childCnt;			/* ��尡 ������ �ִ� �ڽĳ�� ���� */
	struct treeNode* next[16];	/* �ڽ� ���� */
}Node;

class GameBoard
{
public:
	Position* preMoves;	/* ���� �� ������ �迭*/
	char**	board;			/* 4X4 2���� �迭 */

	int moveCnt;			/* ���� �� ���� */
	int	state;				/* ���� ������ ���� */
	int	Level;			/* ������ ������ ��ǻ�� ���� */
	char playerCom;		/* ������ ������ ��ǻ�� ���� */
	char oppnentCom;		/* ���� ��ǻ�� ���� */

	static const int STATE_WINC = 3;		/* ��ǻ�Ͱ� �̰��� �� */
	static const int STATE_WINP = 4;		/* ����� �̰��� �� */
	static const int STATE_DRAW = 5;		/* ������ ����� �� */
	static const int STATE_PLAY = 7;		/* ���� ���� �� �� �� */
	static const int STATE_INIT = 8;		/* ������ �ʱ�ȭ�� ���� */
	static const int STATE_STOP = 9;		/* ������ ���� �� �� */

	
public:

	GameBoard();							/* ������ ������ */
	GameBoard(const GameBoard& copy);		/* ������ Ŭ���� ���� ������ */
	int GetBoardStat();						/* ���� �� ���� ���� ��� */
	void InitBoard(int startCom, int movedCnt, int nlevelC);	/* ������ �ʱ�ȭ */
	void RandomMove();	/* �����ϰ� ���� ���� �� */
	void DoMove(int x, int y);				/* ��ǥ�� �Է� �޾� ���� ���� �� */
	void UndoMove();						/* ���Ҵ� �� ������ */
	void CheckState();						/* ���� ������ ���� üũ */
	
};
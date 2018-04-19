#pragma once
#include "GameBoard.h"

class GameAI
{
public:
	GameBoard ai_board;

	int LAlevel;
	int bestX;
	int bestY;
	Node* root;

public:
	GameAI(GameBoard board);
	void InitNode(Node* node, int inDepth);		/* AI �⺻������ �ʱ�ȭ */
	Node* GetRootNode();						/* Tree �� ����ϱ����� Node ��ȯ */
	void GetBestMove();							/* ������ ��ǥ�� ���� */
	int Minimize(struct treeNode* root);		/* Eval ���� Min ���� ���� */
	int Maximize(struct treeNode* root);		/* Eval ���� Max ���� ���� */
	int CheckSymmetric(GameBoard preBoard, GameBoard newBoard);	/* ���Ӻ��� ��Ī�� �˻� */
	int CheckSameBoard(char(*board1)[4], char(*board2)[4]);	/* ��Ī�� �˻� �� ���尡 ��ġ�ϴ��� �˻� */
	int GetPossibleMove(Position* iList);						/* ���� ������¿��� �����ִ� ��ǥ ���� �˻� */
	int CheckEnd();								/* ������ �������� �˻� */
	int EvaluateBoard(struct treeNode* root);						/* ���� �������� Eval(�򰡰�) ��� */
};

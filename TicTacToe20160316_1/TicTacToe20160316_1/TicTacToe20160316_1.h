
// TicTacToe20160316_1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTicTacToe20160316_1App:
// �� Ŭ������ ������ ���ؼ��� TicTacToe20160316_1.cpp�� �����Ͻʽÿ�.
//

class CTicTacToe20160316_1App : public CWinApp
{
public:
	CTicTacToe20160316_1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CTicTacToe20160316_1App theApp;

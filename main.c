#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <windows.h>
#include "game.h"

void menu()
{
	printf("******************************\n");
	printf("******* 1.play  0.exit *******\n");
	printf("******************************\n");
}


void game()
{
	int ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = Winner(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = Winner(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("*********** ��Ӯ�� ***********\n");
		Sleep(5000);
		system("cls");
	}
	else if (ret == '#')
	{
		printf("*********** ������ ***********\n");
		Sleep(5000);
		system("cls");
	}
	else 
	{	
		printf("************ ƽ �� ************\n");
		Sleep(5000);
		system("cls");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("ѡ�����������ѡ��\n");
				break;
		}
		if (input != 1)
		{
			Sleep(1000);
			system("cls");
		}
	}while (input);
}

int main()
{
	test();
	return 0;
}

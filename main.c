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
		printf("*********** 你赢了 ***********\n");
		Sleep(5000);
		system("cls");
	}
	else if (ret == '#')
	{
		printf("*********** 你输了 ***********\n");
		Sleep(5000);
		system("cls");
	}
	else 
	{	
		printf("************ 平 局 ************\n");
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
		printf("请输入选项:>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误，请重新选择\n");
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

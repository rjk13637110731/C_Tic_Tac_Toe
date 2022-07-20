#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"     //自己写的头文件，需要双引号包含。

void menu()
{
	printf("********************\n");
	printf("****** 1.play ******\n");
	printf("****** 0.exit ******\n");
	printf("********************\n");
}

void game()
{
	//存储数据，--->  二维数组
	char board[ROW][COL];

	//初始化棋盘，--->  初始化为空格
	InitBoard(board, ROW, COL);

	//打印一下棋盘 --->  本质是打印数组的内容
	DisplayBoard(board, ROW, COL);

	//接收游戏状态
	char ret = 0;

	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢得游戏
		ret = IsWin(board,ROW,COL);      //四种状态：1.玩家赢了---*；2.电脑赢了---#；3.平局---Q；4.游戏继续---C。
		if (ret != 'C')
		{
			break;
		}
        //电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
	    //判断电脑是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default :
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);      //input作为0直接终止循环，为其他则继续执行循环。
	return 0;
}
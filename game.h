#pragma once

//头文件的包含
#include <stdio.h>      //为了game.c文件能正常使用printf函数。
#include <stdlib.h>      //为了srand和time
#include <time.h>      //为了srand和time

//符号的定义
#define ROW 3
#define COL 3

//函数的声明
//初始化棋盘的函数
void InitBoard(char boar[ROW][COL],int row,int col);

//打印棋盘的函数
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋的函数
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断游戏是否有输赢函数
char IsWin(char board[ROW][COL], int row, int col);
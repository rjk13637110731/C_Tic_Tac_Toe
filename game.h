#pragma once

//ͷ�ļ��İ���
#include <stdio.h>      //Ϊ��game.c�ļ�������ʹ��printf������
#include <stdlib.h>      //Ϊ��srand��time
#include <time.h>      //Ϊ��srand��time

//���ŵĶ���
#define ROW 3
#define COL 3

//����������
//��ʼ�����̵ĺ���
void InitBoard(char boar[ROW][COL],int row,int col);

//��ӡ���̵ĺ���
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������ĺ���
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж���Ϸ�Ƿ�����Ӯ����
char IsWin(char board[ROW][COL], int row, int col);
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"     //�Լ�д��ͷ�ļ�����Ҫ˫���Ű�����

void menu()
{
	printf("********************\n");
	printf("****** 1.play ******\n");
	printf("****** 0.exit ******\n");
	printf("********************\n");
}

void game()
{
	//�洢���ݣ�--->  ��ά����
	char board[ROW][COL];

	//��ʼ�����̣�--->  ��ʼ��Ϊ�ո�
	InitBoard(board, ROW, COL);

	//��ӡһ������ --->  �����Ǵ�ӡ���������
	DisplayBoard(board, ROW, COL);

	//������Ϸ״̬
	char ret = 0;

	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ����Ϸ
		ret = IsWin(board,ROW,COL);      //����״̬��1.���Ӯ��---*��2.����Ӯ��---#��3.ƽ��---Q��4.��Ϸ����---C��
		if (ret != 'C')
		{
			break;
		}
        //��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
	    //�жϵ����Ƿ�Ӯ����Ϸ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
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
		printf("��ѡ��>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default :
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);      //input��Ϊ0ֱ����ֹѭ����Ϊ���������ִ��ѭ����
	return 0;
}
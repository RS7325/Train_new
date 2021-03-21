#include "windows.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include <windows.h>
#include <iostream>
#include <malloc.h>
#include "info.h"

#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define UP 72
#define ESC 27
#define F1 59
#define F2 60
#define F3 61 
#define F4 62 
#define F5 63 
#define F6 64 
#define F7 65 
#define F8 66 
#define F9 67 
#define F10 68 
#define F11 69 
#define F12 70 
#define ENTER 13
#define EXIT 302


void Start(int i) {
	int A, B, D, E, F;
	if(i==1){
		drawmain();
		A = menuctrl();
		if (A == 1) {
			drawmain_1();
			B = menuctrl_1();
		}
		else if (A == 6) {
			drawmain_3();
			D = menuctrl_3();
		}
		else if (A == 7) {
			drawmain_4();
			E = menuctrl_4();
		}
		else if (A == 12) {
			drawmain_5();
			F = menuctrl_5();
		}
	}
	if (i == 2) {
		drawmain_user();
		A = menuctrl_user();
		if (A == 6) {
			drawmain_3();
			D = menuctrl_3c();
		}
		else if (A == 7) {
			drawmain_4();
			E = menuctrl_4c();
		}
		else if (A == 12) {
			drawmain_5();
			F = menuctrl_5c();
		}
	}


}
		

void user_init() {
	int a;
	drawmain_u();
	a = menuctrl_u();


	if (a == 1) {
		system("cls");
		loginA();
	}
	else if (a == 6) {
		system("cls");
		loginC();
	}
	else if (a == 7) {
		system("cls");
		enrollC();
	}
}



int menuctrl() {
	drawmain();
	int A, B, value, flag = 36, a, b;
	while (1)
	{
		/*��ȡ��ֵ*/
		while (1)
		{
			if (_kbhit())
			{
				A = _getch();
				A = _getch();
				if (A == F1 || A == F2 || A == F3 || A == F4) break;
			}
		}
		if (A == F1)//���ݹ���
		{
			drawmenu(0, flag);
			value = 300;
		}
		if (A == F2) //���ݲ�ѯ
		{
			drawmenu(1, flag);
			value = 301;
		}
		if (A == F3) //��������
		{
			drawmenu(2, flag);
			value = 302;
		}
		if (A == F4) //�˳�ϵͳ
		{
			drawmenu(3, flag);
			value = 303;
		}
		while (1)
		{
			/*��ȡ��ֵ*/
			while (1)
			{
				if (_kbhit()) {
					B = _getch();
					if (B == ESC || B == ENTER) {
						break;
					}
					B = _getch();
					if (B == LEFT || B == RIGHT || B == UP || B == DOWN) break;
				}
			}
			/*������һ���˵�*/
			if (B == ESC)
			{
				flag = 36;
				drawmain();
				cls();
				gotoxy(30, 8);	printf("press F1 -> ���ݹ���");
				gotoxy(30, 10);	printf("press F2 -> ���ݲ�ѯ");
				gotoxy(30, 12);	printf("press F3 -> Ʊ��ϵͳ");
				gotoxy(30, 14);	printf("press F4 -> �˳�ϵͳ");
				break;
			}
			if (flag == 0) flag = 36;
			if (value == 0) value = 300;
			/*���ع��ܼ�ֵ*/
			if (B == ENTER)
			{
				if (value % 3 == 0) b = 6;
				if (value % 3 == 1) b = 6;
				if (value % 3 == 2) b = 3;
				a = (value % 3) * 10 + flag % b;
				if (a == 0) return 1;
				if (a == 1) return 2;

				if (a == 10) return 6;
				if (a == 11) return 7;

				if (a == 20) return 12;

				if (a == 22) return EXIT;
			}
			else if (B == UP) { /*�л�ѡ��*/
				drawmenu(value, --flag);
			}
			else if (B == DOWN) {
				drawmenu(value, ++flag);
			}
			else if (B == LEFT) {/*�л��˵�*/
				drawmenu(--value, flag);
			}
			else {
				drawmenu(++value, flag);
			}
		}
	}
}

int menuctrl_user() {
	drawmain_user();
	int A, B, value, flag = 36, a, b;
	while (1)
	{
		/*��ȡ��ֵ*/
		while (1)
		{
			if (_kbhit())
			{
				A = _getch();
				A = _getch();
				if (A == F1 || A == F2 || A == F4) break;
			}
		}
		if (A == F1)//���ݲ�ѯ
		{
			drawmenu_user(1, flag);
			value = 301;
		}
		if (A == F2) //��������
		{
			drawmenu_user(2, flag);
			value = 302;
		}
		if (A == F4) //�˳�ϵͳ
		{
			drawmenu_user(3, flag);
			value = 303;
		}

		while (1)
		{
			/*��ȡ��ֵ*/
			while (1)
			{
				if (_kbhit()) {
					B = _getch();
					if (B == ESC || B == ENTER) {
						break;
					}
					B = _getch();
					if (B == LEFT || B == RIGHT || B == UP || B == DOWN) break;
				}
			}
			/*������һ���˵�*/
			if (B == ESC)
			{
				flag = 36;
				drawmain_user();
				cls();
				gotoxy(30, 8);	printf("press F1 -> ���ݲ�ѯ");
				gotoxy(30, 10);	printf("press F2 -> Ʊ��ϵͳ");
				gotoxy(30, 12);	printf("press F4 -> �˳�ϵͳ");
				break;
			}
			if (flag == 0) flag = 36;
			if (value == 0) value = 300;
			/*���ع��ܼ�ֵ*/
			if (B == ENTER)
			{
				if (value % 3 == 0) b = 6;
				if (value % 3 == 1) b = 6;
				if (value % 3 == 2) b = 3;
				a = (value % 3) * 10 + flag % b;
				if (a == 0) return 1;
				if (a == 1) return 2;

				if (a == 10) return 6;
				if (a == 11) return 7;

				if (a == 20) return 12;

				if (a == 22) return EXIT;
			}
			else if (B == UP) { /*�л�ѡ��*/
				drawmenu_user(value, --flag);
			}
			else if (B == DOWN) {
				drawmenu_user(value, ++flag);
			}
			else if (B == LEFT) {/*�л��˵�*/
				drawmenu_user(--value, flag);
			}
			else {
				drawmenu_user(++value, flag);
			}
		}
	}
}

int menuctrl_u() {
	drawmain_u();
	int A, B, value, flag = 36, a, b;
	while (1)
	{
		/*��ȡ��ֵ*/
		while (1)
		{
			if (_kbhit())
			{
				A = _getch();
				A = _getch();
				if (A == F1 || A == F2) break;
			}
		}
		if (A == F1)//����Ա
		{
			drawmenu_u(0, flag);
			value = 300;
		}
		if (A == F2) //�û�
		{
			drawmenu_u(1, flag);
			value = 301;
		}

		while (1)
		{
			/*��ȡ��ֵ*/
			while (1)
			{
				if (_kbhit()) {
					B = _getch();
					if (B == ESC || B == ENTER) {
						break;
					}
					B = _getch();
					if (B == LEFT || B == RIGHT || B == UP || B == DOWN) break;
				}
			}
			/*������һ���˵�*/
			if (B == ESC)
			{
				flag = 36;
				drawmain_u();
				cls();
				gotoxy(30, 8);	printf("press F1 -> ����Ա");
				gotoxy(30, 10);	printf("press F2 -> �û�");
				break;
			}
			if (flag == 0) flag = 36;
			if (value == 0) value = 300;
			/*���ع��ܼ�ֵ*/
			if (B == ENTER)
			{
				if (value % 3 == 0) b = 6;
				if (value % 3 == 1) b = 6;
				if (value % 3 == 2) b = 3;
				a = (value % 3) * 10 + flag % b;
				if (a == 0) return 1;
				if (a == 1) return 2;

				if (a == 10) return 6;
				if (a == 11) return 7;

				if (a == 20) return 12;

				if (a == 22) return EXIT;
			}
			else if (B == UP) { /*�л�ѡ��*/
				drawmenu_u(value, --flag);
			}
			else if (B == DOWN) {
				drawmenu_u(value, ++flag);
			}
			else if (B == LEFT) {/*�л��˵�*/
				drawmenu_u(--value, flag);
			}
			else {
				drawmenu_u(++value, flag);
			}
		}
	}
}

int menuctrl_1()//�������ݹ���
{
	int A, B, value, flag = 36;
	
	while (1)
	{
		/*��ȡ��ֵ*/
		while (1)
		{
			
			if (_kbhit())
			{
				A = _getch();
				A = _getch();
				if (A == F5 || A == F6 || A == F7 || A == F8) break;
			}
		}
		drawmain_1();
		if (A == F5)
		{
			system("cls");
			gotoxy(0, 0);
			add();
			value = 304;
		}
		if (A == F6) {
			system("cls");
			gotoxy(0, 0);
			change();
			value = 305;
		}
		if (A == F7) {
			system("cls");
			gotoxy(0, 0);
			del();
			value = 306;
		}
		if (A == F8) {
			Start(1);
			value = 307;
		}
		while (1)
		{
			/*��ȡ��ֵ*/
			while (1)
			{
				if (_kbhit()) {
					B = _getch();
					if (B == ESC || B == ENTER) {
						break;
					}
					B = _getch();
					if (B == LEFT || B == RIGHT || B == UP || B == DOWN) break;
				}
			}
			/*������һ���˵�*/
			if (B == ESC)
			{
				flag = 36;
				drawmain_1();
				gotoxy(30, 8);	printf("press F5 -> ����������Ϣ");
				gotoxy(30, 10);	printf("press F6 -> �޸ĳ�����Ϣ");
				gotoxy(30, 12);	printf("press F7 -> ɾ��������Ϣ");
				gotoxy(30, 14);	printf("press F8 -> �������˵�");
				break;
			}
			if (flag == 0) flag = 36;
			if (value == 0) value = 300;
		
		}
	}
}


int menuctrl_3() //�б�
{
	int A, B, value, flag = 36;
	
	while (1)
	{
		/*��ȡ��ֵ*/
		while (1)
		{
			
			if (_kbhit())
			{
				A = _getch();
				A = _getch();
				if (A == F5 || A == F6 || A == F7 || A == F8) break;
			}
		}
		drawmain_3();
		if (A == F5)
		{
			system("cls");
			gotoxy(0, 0);
			look1();
			value = 304;
		}
		if (A == F6) {
			system("cls");
			gotoxy(0, 0);
			look2();
			value = 305;
		}
		if (A == F7) {
			system("cls");
			gotoxy(0, 0);
			look3();
			value = 306;
		}
		if (A == F8) {
			Start(1);
			value = 307;
		}
		while (1)
		{
			/*��ȡ��ֵ*/
			while (1)
			{
				if (_kbhit()) {
					B = _getch();
					if (B == ESC || B == ENTER) {
						break;
					}
					B = _getch();
					if (B == LEFT || B == RIGHT || B == UP || B == DOWN) break;
				}
			}
			/*������һ���˵�*/
			if (B == ESC)
			{
				flag = 36;
				drawmain_3();
				gotoxy(30, 8);	printf("press F5 -> ���б�");
				gotoxy(30, 10);	printf("press F6 -> ���η���ʱ��");
				gotoxy(30, 12);	printf("press F7 -> Ŀ�ĵ��б�");
				gotoxy(30, 14);	printf("press F8 -> �������˵�");
				break;
			}
			if (flag == 0) flag = 36;
			if (value == 0) value = 300;
			/*���ع��ܼ�ֵ*/
			
		}
	}
}

int menuctrl_4()//��ѯ
{
	int A, B, value, flag = 36;

	while (1)
	{
		/*��ȡ��ֵ*/
		while (1)
		{

			if (_kbhit())
			{
				A = _getch();
				A = _getch();
				if (A == F5 || A == F6 || A == F7 || A == F8) break;
			}
		}
		drawmain_3();
		if (A == F5)
		{
			system("cls");
			gotoxy(0, 0);
			seek1();
			value = 304;
		}
		if (A == F6) {
			system("cls");
			gotoxy(0, 0);
			seek2();
			value = 305;
		}
		if (A == F7) {
			system("cls");
			gotoxy(0, 0);
			seek3();
			value = 306;
		}
		if (A == F8) {
			Start(1);
			value = 307;
		}
		while (1)
		{
			/*��ȡ��ֵ*/
			while (1)
			{
				if (_kbhit()) {
					B = _getch();
					if (B == ESC || B == ENTER) {
						break;
					}
					B = _getch();
					if (B == LEFT || B == RIGHT || B == UP || B == DOWN) break;
				}
			}
			/*������һ���˵�*/
			if (B == ESC)
			{
				flag = 36;
				drawmain_3();
				gotoxy(30, 8);	printf("press F5 -> ��κŲ�ѯ");
				gotoxy(30, 10);	printf("press F6 -> �յ�վ��ѯ");
				gotoxy(30, 12);	printf("press F7 -> �ɹ�Ʊ��ѯ");
				gotoxy(30, 14);	printf("press F8 -> �������˵�");
				break;
			}
			if (flag == 0) flag = 36;
			if (value == 0) value = 300;
		}
	}
}

int menuctrl_5()//Ʊ��ϵͳ
{
	int A, B, value, flag = 36;

	while (1)
	{
		/*��ȡ��ֵ*/
		while (1)
		{

			if (_kbhit())
			{
				A = _getch();
				A = _getch();
				if (A == F5 || A == F6 || A == F8) break;
			}
		}
		if (A == F5)
		{
			system("cls");
			gotoxy(0, 0);
			buy();
			value = 304;
		}
		if (A == F6) {
			system("cls");
			gotoxy(0, 0);
			deny();
			value = 305;
		}
		if (A == F8) {
			Start(2);
			value = 307;
		}

		while (1)
		{
			/*��ȡ��ֵ*/
			while (1)
			{
				if (_kbhit()) {
					B = _getch();
					if (B == ESC || B == ENTER) {
						break;
					}
					B = _getch();
					if (B == LEFT || B == RIGHT || B == UP || B == DOWN) break;
				}
			}
			/*������һ���˵�*/
			if (B == ESC)
			{
				flag = 36;
				drawmain_3();
				gotoxy(30, 8);	printf("press F5 -> ��Ʊ");
				gotoxy(30, 10);	printf("press F6 -> ��Ʊ");
				gotoxy(30, 12);	printf("press F8 -> ����");
				break;
			}
			if (flag == 0) flag = 36;
			if (value == 0) value = 300;
		}
	}
}



int menuctrl_3c() //�б�
{
	int A, B, value, flag = 36;

	while (1)
	{
		/*��ȡ��ֵ*/
		while (1)
		{

			if (_kbhit())
			{
				A = _getch();
				A = _getch();
				if (A == F5 || A == F6 || A == F7 || A == F8) break;
			}
		}
		drawmain_3();
		if (A == F5)
		{
			system("cls");
			gotoxy(0, 0);
			look1();
			value = 304;
		}
		if (A == F6) {
			system("cls");
			gotoxy(0, 0);
			look2();
			value = 305;
		}
		if (A == F7) {
			system("cls");
			gotoxy(0, 0);
			look3();
			value = 306;
		}
		if (A == F8) {
			Start(2);
			value = 307;
		}
		while (1)
		{
			/*��ȡ��ֵ*/
			while (1)
			{
				if (_kbhit()) {
					B = _getch();
					if (B == ESC || B == ENTER) {
						break;
					}
					B = _getch();
					if (B == LEFT || B == RIGHT || B == UP || B == DOWN) break;
				}
			}
			/*������һ���˵�*/
			if (B == ESC)
			{
				flag = 36;
				drawmain_3();
				gotoxy(30, 8);	printf("press F5 -> ���б�");
				gotoxy(30, 10);	printf("press F6 -> ���η���ʱ��");
				gotoxy(30, 12);	printf("press F7 -> Ŀ�ĵ��б�");
				gotoxy(30, 14);	printf("press F8 -> �������˵�");
				break;
			}
			if (flag == 0) flag = 36;
			if (value == 0) value = 300;
			/*���ع��ܼ�ֵ*/

		}
	}
}

int menuctrl_4c()//��ѯ
{
	int A, B, value, flag = 36;

	while (1)
	{
		/*��ȡ��ֵ*/
		while (1)
		{

			if (_kbhit())
			{
				A = _getch();
				A = _getch();
				if (A == F5 || A == F6 || A == F7 || A == F8) break;
			}
		}
		drawmain_3();
		if (A == F5)
		{
			system("cls");
			gotoxy(0, 0);
			seek1_c();
			value = 304;
		}
		if (A == F6) {
			system("cls");
			gotoxy(0, 0);
			seek2_c();
			value = 305;
		}
		if (A == F7) {
			system("cls");
			gotoxy(0, 0);
			seek3_c();
			value = 306;
		}
		if (A == F8) {
			Start(2);
			value = 307;
		}
		while (1)
		{
			/*��ȡ��ֵ*/
			while (1)
			{
				if (_kbhit()) {
					B = _getch();
					if (B == ESC || B == ENTER) {
						break;
					}
					B = _getch();
					if (B == LEFT || B == RIGHT || B == UP || B == DOWN) break;
				}
			}
			/*������һ���˵�*/
			if (B == ESC)
			{
				flag = 36;
				drawmain_3();
				gotoxy(30, 8);	printf("press F5 -> ��κŲ�ѯ");
				gotoxy(30, 10);	printf("press F6 -> �յ�վ��ѯ");
				gotoxy(30, 12);	printf("press F7 -> �ɹ�Ʊ��ѯ");
				gotoxy(30, 14);	printf("press F8 -> �������˵�");
				break;
			}
			if (flag == 0) flag = 36;
			if (value == 0) value = 300;
		}
	}
}

int menuctrl_5c()//Ʊ��ϵͳ
{
	int A, B, value, flag = 36;

	while (1)
	{
		/*��ȡ��ֵ*/
		while (1)
		{

			if (_kbhit())
			{
				A = _getch();
				A = _getch();
				if (A == F5 || A == F6 || A == F8) break;
			}
		}
		if (A == F5)
		{
			system("cls");
			gotoxy(0, 0);
			buy_c();
			value = 304;
		}
		if (A == F6) {
			system("cls");
			gotoxy(0, 0);
			deny_c();
			value = 305;
		}
		if (A == F8) {
			Start(2);
			value = 307;
		}

		while (1)
		{
			/*��ȡ��ֵ*/
			while (1)
			{
				if (_kbhit()) {
					B = _getch();
					if (B == ESC || B == ENTER) {
						break;
					}
					B = _getch();
					if (B == LEFT || B == RIGHT || B == UP || B == DOWN) break;
				}
			}
			/*������һ���˵�*/
			if (B == ESC)
			{
				flag = 36;
				drawmain_5();
				gotoxy(30, 8);	printf("press F5 -> ��Ʊ");
				gotoxy(30, 10);	printf("press F6 -> ��Ʊ");
				gotoxy(30, 12);	printf("press F8 -> ����");
				break;
			}
			if (flag == 0) flag = 36;
			if (value == 0) value = 300;
		}
	}
}
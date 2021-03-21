#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include <windows.h>
#include "info.h"


void menu_init() {
	HideConsoleCursor();
	char user[100] = "";
	int choice1;
	char choice[10];
	//printf("是否进行数据更新？\n");
	//printf("1.是\n2.否\n");
	InputBox(choice, 128, "是否进行数据更新？(1.是/2.否)");
	choice1 = atoi(choice);
	//scanf("%d",&choice1);
	if (choice1 == 1) {
		save();
		system("cls");
		gotoxy(45, 9);
		printf("读取信息中，请稍后。。。");
		loadFigure();
		user_init();
	}
	else{
		system("cls");	
		gotoxy(45, 9);
		printf("读取信息中，请稍后。。。");
		loadFigure();
		user_init();
	}
}


void drawline(char c) {
	int i;
	for (i = 0; i < 117; i++) {
		printf("%c", c);
	}
}
void gotoxy(int x, int y) {
	int xx = 0x0b;
	HANDLE hOutput;
	COORD loc;
	loc.X = x;
	loc.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, loc);
	return;
}
void cls() {
	int i;
	for (i = 0; i < 20; i++)
	{
		gotoxy(2, 3 + i);
		drawline(' ');
	}
}


void choice()     //用户查看信息后选择操作函数 
{
	char choice[10];
	int a = 1;
	int i;
	//printf("\n\n请选择下一步操作：\n1、购票\n2、退票\n3、返回上一级目录\n0、退出\n");
	//printf("\n\n我的选择是：");
	//scanf("%d", &i);
	InputBox(choice, 128, "请选择下一步操作：(1、购票/2、退票/3、返回上一级目录/0、退出)");
	i = atoi(choice);
	system("cls");     //清屏 
	switch (i)
	{
	case 1:
		buy();
		break;
	case 2:
		deny();
		break;
	case 3:
		Start(1);
		break;
	case 0:
		printf("成功退出！！！！\n\n");
		exit(0);
		break;
	default:
		printf("出错！！！！！\n\n");
		exit(0);
	}
}

void choice_c()     //用户查看信息后选择操作函数 
{
	int a = 1;
	char choice[10];
	int i;
	InputBox(choice, 128, "请选择下一步操作：(1、购票/2、退票/3、返回上一级目录/0、退出)");
	i = atoi(choice);
	system("cls");     //清屏 
	switch (i)
	{
	case 1:
		buy();
		break;
	case 2:
		deny();
		break;
	case 3:
		Start(2);
		break;
	case 0:
		printf("成功退出！！！！\n\n");
		exit(0);
		break;
	default:
		printf("出错！！！！！\n\n");
		exit(0);
	}
}


void loadFigure()
{
	char load_figure_map[20][60] =
	{
		{"┌───────────────────┐"},
		{"│                   │"},
		{"└───────────────────┘"},
		{"       Loading...  "},
	};

	gotoxy(45, 11);
	for (int i = 0; i < 4; i++)
	{
		printf("%s", load_figure_map[i]);
		Sleep(150);
		gotoxy(45, 11 + i + 1);
	}

	// 动态加载
	gotoxy(46, 12);
	printf("[][][]");

	for (int a = 0; a < 3; a++)
		for (int j = 6; j + 6 < 30; j += 2)
		{
			gotoxy(46 + j % 18, 12);
			printf("[]");
			gotoxy(46 + (j - 6) % 19, 12);
			printf("  ");
			Sleep(100);
		}
}

VOID HideConsoleCursor(VOID) {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),
		&cursor_info);
}

//void init_system() {
//
//}
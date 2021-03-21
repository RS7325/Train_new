#include "windows.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include<iostream>
#include <malloc.h>
#include "info.h"
#include <windows.h>
#define WIN_SIZE "mode con cols=125 lines=35"  



void drawmain() {

	system(WIN_SIZE);

	//把背景设置为 浅绿色
	system("color 3e");

	int i;
	/*打印伪窗口竖线*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*打印伪窗口横线*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*打印信息*/
	gotoxy(7, 1);	printf("%c  %c 数据管理 %c  %c", '|', '<', '>', '|');
	gotoxy(37, 1);	printf("%c  %c 数据查询 %c  %c", '|', '<', '>', '|');
	gotoxy(67, 1);	printf("%c  %c 票务系统 %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c 退出系统 %c  %c", '|', '<', '>', '|');



	gotoxy(30, 8);	printf("press F1 -> 数据管理");
	gotoxy(30, 10);	printf("press F2 -> 数据查询");
	gotoxy(30, 12);	printf("press F3 -> 票务系统");
	gotoxy(30, 14);	printf("press F4 -> 退出系统");
	gotoxy(5, 25);	printf("高铁时刻表信息管理系统");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}

void drawmain_user() {

	system(WIN_SIZE);

	//把背景设置为 浅绿色
	system("color 3e");

	int i;
	/*打印伪窗口竖线*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*打印伪窗口横线*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*打印信息*/
	gotoxy(7, 1);	printf("%c  %c 数据查询 %c  %c", '|', '<', '>', '|');
	gotoxy(52, 1);	printf("%c  %c 票务系统 %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c 退出系统 %c  %c", '|', '<', '>', '|');



	gotoxy(30, 8);	printf("press F1 -> 数据查询");
	gotoxy(30, 10);	printf("press F2 -> 票务系统");
	gotoxy(30, 12);	printf("press F4 -> 退出系统");
	gotoxy(5, 25);	printf("高铁时刻表信息管理系统");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}

void drawmain_u() {

	system(WIN_SIZE);

	//把背景设置为 浅绿色
	system("color 8e");

	int i;
	/*打印伪窗口竖线*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*打印伪窗口横线*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*打印信息*/
	gotoxy(7, 1);	printf("%c  %c 管理员 %c  %c", '|', '<', '>', '|');
	gotoxy(67, 1);	printf("%c  %c 乘客 %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F1 -> 管理员");
	gotoxy(30, 10);	printf("press F2 -> 乘客");
	gotoxy(5, 25);	printf("高铁时刻表信息管理系统");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}

void drawmenu(int m, int n) {
	int i;
	if (m % 4 == 0)
	{
		cls();
		/*打印边框*/
		for (i = 1; i < 3; i++)
		{
			gotoxy(7, 2 + i);	 printf("%c", '*');
			gotoxy(34, 2 + i); printf("%c", '*');
		}
		gotoxy(7, 4);  printf("****************************");
		/*打印菜单内容*/
		gotoxy(9, 3);	printf("车次管理      ");
		/*打印选项*/
		switch (n % 2) {
		case 0:gotoxy(9, 3); printf("车次管理     &"); break;
		}
	}
	if (m % 4 == 1)
	{
		cls();
		/*打印边框*/
		for (i = 1; i < 3; i++)
		{
			gotoxy(37, 2 + i);	_cprintf("%c", '*');
			gotoxy(58, 2 + i);	_cprintf("%c", '*');
		}
		gotoxy(37, 5);  _cprintf("*********************");//
		/*打印菜单内容*/
		gotoxy(39, 3);	printf("简单列表      ");
		gotoxy(39, 4);	printf("详细信息查询    ");
		/*打印选项*/
		switch (n % 2) {
		case 0:gotoxy(39, 3); printf("简单列表     &"); break;
		case 1:gotoxy(39, 4); printf("详细信息查询   &"); break;
		}
	}
	if (m % 4 == 2)
	{
		cls();
		/*打印边框*/
		for (i = 1; i < 2; i++)
		{
			gotoxy(67, 2 + i);	_cprintf("%c", '*');
			gotoxy(88, 2 + i);	_cprintf("%c", '*');
		}
		gotoxy(67, 4);  _cprintf("*********************");//
		/*打印菜单内容*/
		gotoxy(69, 3);	printf("票务系统      ");
		/*打印选项*/
		switch (n % 1) {
		case 0:gotoxy(69, 3); printf("票务系统     &"); break;
		}
		//system("cls");
		//printf("ok");

	}
	if (m % 4 == 3)
	{
		gotoxy(0, 35);
		user_init();

	}

}


void drawmenu_u(int m, int n) {
	int i;
	if (m % 4 == 0)
	{
		cls();
		/*打印边框*/
		for (i = 1; i < 2; i++)
		{
			gotoxy(7, 2 + i);	 printf("%c", '*');
			gotoxy(34, 2 + i); printf("%c", '*');
		}
		gotoxy(7, 4);  printf("****************************");
		/*打印菜单内容*/
		gotoxy(9, 3);	printf("管理员登录      ");
		/*打印选项*/
		switch (n % 2) {
		case 0:gotoxy(9, 3); printf("管理员登录     &"); break;
		}
	}
	if (m % 4 == 1)
	{
		cls();
		/*打印边框*/
		for (i = 1; i < 3; i++)
		{
			gotoxy(67, 2 + i);	_cprintf("%c", '*');
			gotoxy(88, 2 + i);	_cprintf("%c", '*');
		}
		gotoxy(67, 5);  _cprintf("*********************");//
		/*打印菜单内容*/
		gotoxy(69, 3);	printf("乘客登录      ");
		gotoxy(69, 4);	printf("新乘客注册    ");
		/*打印选项*/
		switch (n % 2) {
		case 0:gotoxy(69, 3); printf("乘客登录     &"); break;
		case 1:gotoxy(69, 4); printf("新乘客注册   &"); break;
		}
	}
}


void drawmenu_user(int m, int n) {
	int i;

	if (m % 4 == 1)
	{
		cls();
		/*打印边框*/
		for (i = 1; i < 3; i++)
		{
			gotoxy(7, 2 + i);	_cprintf("%c", '*');
			gotoxy(34, 2 + i);	_cprintf("%c", '*');
		}
		gotoxy(7, 5);  _cprintf("*********************");//
		/*打印菜单内容*/
		gotoxy(9, 3);	printf("简单列表      ");
		gotoxy(9, 4);	printf("详细信息查询    ");
		/*打印选项*/
		switch (n % 2) {
		case 0:gotoxy(9, 3); printf("简单列表     &"); break;
		case 1:gotoxy(9, 4); printf("详细信息查询   &"); break;
		}
	}
	if (m % 4 == 2)
	{
		cls();
		/*打印边框*/
		for (i = 1; i < 2; i++)
		{
			gotoxy(50, 2 + i);	_cprintf("%c", '*');
			gotoxy(71, 2 + i);	_cprintf("%c", '*');
		}
		gotoxy(52, 4);  _cprintf("*********************");//
		/*打印菜单内容*/
		gotoxy(54, 3);	printf("票务系统      ");
		/*打印选项*/
		switch (n % 1) {
		case 0:gotoxy(54, 3); printf("票务系统     &"); break;
		}
		//system("cls");
		//printf("ok");

	}
	if (m % 4 == 3)
	{
		gotoxy(0, 35);
		user_init();

	}

}



void drawmain_1() {

	system(WIN_SIZE);

	//把背景设置为 浅绿色
	system("color 3e");

	int i;
	/*打印伪窗口竖线*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*打印伪窗口横线*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 4);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*打印信息*/
	gotoxy(7, 1);	printf("%c  %c 数据管理 %c  %c", '|', '<', '>', '|');
	gotoxy(37, 1);	printf("%c  %c 数据查询 %c  %c", '|', '<', '>', '|');
	gotoxy(67, 1);	printf("%c  %c 数据统计 %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c 退出系统 %c  %c", '|', '<', '>', '|');

	gotoxy(7, 3);	printf("%c  %c 新增车次信息 %c  %c", '|', '<', '>', '|');
	gotoxy(37, 3);	printf("%c  %c 修改车次信息 %c  %c", '|', '<', '>', '|');
	gotoxy(67, 3);	printf("%c  %c 删除车次信息 %c  %c", '|', '<', '>', '|');
	gotoxy(97, 3);	printf("%c  %c 返回主菜单 %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F5 -> 新增车次信息");
	gotoxy(30, 10);	printf("press F6 -> 修改车次信息");
	gotoxy(30, 12);	printf("press F7 -> 删除车次信息");
	gotoxy(30, 14);	printf("press F8 -> 返回主菜单");
	gotoxy(5, 25);	printf("高铁时刻表信息管理系统");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}




void drawmain_3() {

	system(WIN_SIZE);

	//把背景设置为 浅绿色
	system("color 3e");

	int i;
	/*打印伪窗口竖线*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*打印伪窗口横线*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 4);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*打印信息*/
	gotoxy(7, 1);	printf("%c  %c 数据管理 %c  %c", '|', '<', '>', '|');
	gotoxy(37, 1);	printf("%c  %c 数据查询 %c  %c", '|', '<', '>', '|');
	gotoxy(67, 1);	printf("%c  %c 数据统计 %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c 退出系统 %c  %c", '|', '<', '>', '|');

	gotoxy(7, 3);	printf("%c  %c 发车时间列表 %c  %c", '|', '<', '>', '|');
	gotoxy(37, 3);	printf("%c  %c 车次发车时间 %c  %c", '|', '<', '>', '|');
	gotoxy(67, 3);	printf("%c  %c 目的地列表 %c  %c", '|', '<', '>', '|');
	gotoxy(97, 3);	printf("%c  %c 返回主菜单 %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F5 -> 发车时间列表");
	gotoxy(30, 10);	printf("press F6 -> 车次发车时间");
	gotoxy(30, 12);	printf("press F7 -> 目的地列表");
	gotoxy(30, 14);	printf("press F8 -> 返回主菜单");
	gotoxy(5, 25);	printf("高铁时刻表信息管理系统");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}


void drawmain_4() {

	system(WIN_SIZE);

	//把背景设置为 浅绿色
	system("color 3e");

	int i;
	/*打印伪窗口竖线*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*打印伪窗口横线*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 4);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*打印信息*/
	gotoxy(7, 1);	printf("%c  %c 数据管理 %c  %c", '|', '<', '>', '|');
	gotoxy(37, 1);	printf("%c  %c 数据查询 %c  %c", '|', '<', '>', '|');
	gotoxy(67, 1);	printf("%c  %c 数据统计 %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c 退出系统 %c  %c", '|', '<', '>', '|');

	gotoxy(7, 3);	printf("%c  %c 班次号查询 %c  %c", '|', '<', '>', '|');
	gotoxy(37, 3);	printf("%c  %c 终点站查询 %c  %c", '|', '<', '>', '|');
	gotoxy(67, 3);	printf("%c  %c 可购票查询 %c  %c", '|', '<', '>', '|');
	gotoxy(97, 3);	printf("%c  %c 返回主菜单 %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F5 -> 班次号查询");
	gotoxy(30, 10);	printf("press F6 -> 终点站查询");
	gotoxy(30, 12);	printf("press F7 -> 可购票查询");
	gotoxy(30, 14);	printf("press F8 -> 返回主菜单");
	gotoxy(5, 25);	printf("高铁时刻表信息管理系统");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}

void drawmain_5() {

	system(WIN_SIZE);

	//把背景设置为 浅绿色
	system("color 3e");

	int i;
	/*打印伪窗口竖线*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*打印伪窗口横线*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 4);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*打印信息*/
	gotoxy(7, 1);	printf("%c  %c 数据管理 %c  %c", '|', '<', '>', '|');
	gotoxy(37, 1);	printf("%c  %c 数据查询 %c  %c", '|', '<', '>', '|');
	gotoxy(67, 1);	printf("%c  %c 票务系统 %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c 退出系统 %c  %c", '|', '<', '>', '|');

	gotoxy(7, 3);	printf("%c  %c 购票 %c  %c", '|', '<', '>', '|');
	gotoxy(67, 3);	printf("%c  %c 退票 %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F5 -> 购票");
	gotoxy(30, 10);	printf("press F6 -> 退票");

	gotoxy(5, 25);	printf("高铁时刻表信息管理系统");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}




void drawmain_3c() {

	system(WIN_SIZE);

	//把背景设置为 浅绿色
	system("color 3e");

	int i;
	/*打印伪窗口竖线*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*打印伪窗口横线*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*打印信息*/
	gotoxy(7, 1);	printf("%c  %c 数据查询 %c  %c", '|', '<', '>', '|');
	gotoxy(52, 1);	printf("%c  %c 票务系统 %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c 退出系统 %c  %c", '|', '<', '>', '|');

	gotoxy(7, 3);	printf("%c  %c 发车时间列表 %c  %c", '|', '<', '>', '|');
	gotoxy(37, 3);	printf("%c  %c 车次发车时间 %c  %c", '|', '<', '>', '|');
	gotoxy(67, 3);	printf("%c  %c 目的地列表 %c  %c", '|', '<', '>', '|');
	gotoxy(97, 3);	printf("%c  %c 返回主菜单 %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F5 -> 发车时间列表");
	gotoxy(30, 10);	printf("press F6 -> 车次发车时间");
	gotoxy(30, 12);	printf("press F7 -> 目的地列表");
	gotoxy(30, 14);	printf("press F8 -> 返回主菜单");
	gotoxy(5, 25);	printf("高铁时刻表信息管理系统");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}





void drawmain_4c() {

	system(WIN_SIZE);

	//把背景设置为 浅绿色
	system("color 3e");

	int i;
	/*打印伪窗口竖线*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*打印伪窗口横线*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*打印信息*/
	gotoxy(7, 1);	printf("%c  %c 数据查询 %c  %c", '|', '<', '>', '|');
	gotoxy(52, 1);	printf("%c  %c 票务系统 %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c 退出系统 %c  %c", '|', '<', '>', '|');

	gotoxy(7, 3);	printf("%c  %c 班次号查询 %c  %c", '|', '<', '>', '|');
	gotoxy(37, 3);	printf("%c  %c 终点站查询 %c  %c", '|', '<', '>', '|');
	gotoxy(67, 3);	printf("%c  %c 可购票查询 %c  %c", '|', '<', '>', '|');
	gotoxy(97, 3);	printf("%c  %c 返回主菜单 %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F5 -> 班次号查询");
	gotoxy(30, 10);	printf("press F6 -> 终点站查询");
	gotoxy(30, 12);	printf("press F7 -> 可购票查询");
	gotoxy(30, 14);	printf("press F8 -> 返回主菜单");
	gotoxy(5, 25);	printf("高铁时刻表信息管理系统");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}

void drawmain_5c() {

	system(WIN_SIZE);

	//把背景设置为 浅绿色
	system("color 3e");

	int i;
	/*打印伪窗口竖线*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*打印伪窗口横线*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*打印信息*/
	gotoxy(7, 1);	printf("%c  %c 数据查询 %c  %c", '|', '<', '>', '|');
	gotoxy(52, 1);	printf("%c  %c 票务系统 %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c 退出系统 %c  %c", '|', '<', '>', '|');

	gotoxy(7, 3);	printf("%c  %c 购票 %c  %c", '|', '<', '>', '|');
	gotoxy(67, 3);	printf("%c  %c 退票 %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F5 -> 购票");
	gotoxy(30, 10);	printf("press F6 -> 退票");

	gotoxy(5, 25);	printf("高铁时刻表信息管理系统");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}
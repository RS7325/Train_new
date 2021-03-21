#pragma once
#ifndef _TOOLS_H_
#define _TOOLS_H_
#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <graphics.h>


#define SIZE1 10     //原始列车信息总数
#define SIZE2 20     //添加列车信息可用的总数
#define SIZE3 5     //原始管理员及已注册乘客的数量 
#define LEN sizeof(struct Mem3)

//*************************************界面控制*************************************
void choice();
int menuctrl();
int menuctrl_user();
int menuctrl_u();
int menuctrl_1();
int menuctrl_3();
int menuctrl_4();
int menuctrl_5();
int menuctrl_3c();
int menuctrl_4c();
int menuctrl_5c();
void menu_init();
void user_init();
//*************************************界面绘制*************************************
void drawmain();
void drawmain_u();
void drawmain_1();
void drawmain_user();
void drawmain_3();
void drawmain_4();
void drawmain_5();
void drawmain_3c();
void drawmain_4c();
void drawmain_5c();
void drawmenu(int m, int n);
void drawmenu_user(int m, int n);
void drawmenu_u(int m, int n);
//*************************************功能函数(管理员)*************************************
//void enrollA();     //管理员注册
void change();      //修改函数 
void add();     //增加函数
void del();     //删除函数
void enrollC();		//乘客注册函数
void loginA();     //管理员登录
int loginC();	   //顾客登录
void save();     //文件更新函数
void printtime();     //乘客可见输出函数
void look1();     //总列表函数
void look2();     //班次号列表函数
void look3();     //目的地列表函数
void seek1();      //班次号查询函数
void seek2();      //终点站查询函数
void seek3();     //可购票查询函数
void print();      //管理员输出函数
void printID();      //班次输出函数
void printDestn();      //目的地输出函数
void buy();     //购票系统函数 
void deny();     //退票函数 
void Start(int i);//开始菜单
//*************************************其他*************************************
void gotoxy(int x, int y);
void choice();
void choice_c();
void drawline(char c);
void cls();
void loadFigure();
VOID HideConsoleCursor(VOID);
//*************************************功能函数(用户)*************************************
void look1_c();     //总列表函数
void look2_c();     //班次号列表函数
void look3_c();     //目的地列表函数
void seek1_c();      //班次号查询函数
void seek2_c();      //终点站查询函数
void seek3_c();     //可购票查询函数
void buy_c();     //购票系统函数 
void deny_c();     //退票函数 

#endif
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


#define SIZE1 10     //ԭʼ�г���Ϣ����
#define SIZE2 20     //����г���Ϣ���õ�����
#define SIZE3 5     //ԭʼ����Ա����ע��˿͵����� 
#define LEN sizeof(struct Mem3)

//*************************************�������*************************************
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
//*************************************�������*************************************
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
//*************************************���ܺ���(����Ա)*************************************
//void enrollA();     //����Աע��
void change();      //�޸ĺ��� 
void add();     //���Ӻ���
void del();     //ɾ������
void enrollC();		//�˿�ע�ắ��
void loginA();     //����Ա��¼
int loginC();	   //�˿͵�¼
void save();     //�ļ����º���
void printtime();     //�˿Ϳɼ��������
void look1();     //���б���
void look2();     //��κ��б���
void look3();     //Ŀ�ĵ��б���
void seek1();      //��κŲ�ѯ����
void seek2();      //�յ�վ��ѯ����
void seek3();     //�ɹ�Ʊ��ѯ����
void print();      //����Ա�������
void printID();      //����������
void printDestn();      //Ŀ�ĵ��������
void buy();     //��Ʊϵͳ���� 
void deny();     //��Ʊ���� 
void Start(int i);//��ʼ�˵�
//*************************************����*************************************
void gotoxy(int x, int y);
void choice();
void choice_c();
void drawline(char c);
void cls();
void loadFigure();
VOID HideConsoleCursor(VOID);
//*************************************���ܺ���(�û�)*************************************
void look1_c();     //���б���
void look2_c();     //��κ��б���
void look3_c();     //Ŀ�ĵ��б���
void seek1_c();      //��κŲ�ѯ����
void seek2_c();      //�յ�վ��ѯ����
void seek3_c();     //�ɹ�Ʊ��ѯ����
void buy_c();     //��Ʊϵͳ���� 
void deny_c();     //��Ʊ���� 

#endif
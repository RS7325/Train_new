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

	//�ѱ�������Ϊ ǳ��ɫ
	system("color 3e");

	int i;
	/*��ӡα��������*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*��ӡα���ں���*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*��ӡ��Ϣ*/
	gotoxy(7, 1);	printf("%c  %c ���ݹ��� %c  %c", '|', '<', '>', '|');
	gotoxy(37, 1);	printf("%c  %c ���ݲ�ѯ %c  %c", '|', '<', '>', '|');
	gotoxy(67, 1);	printf("%c  %c Ʊ��ϵͳ %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c �˳�ϵͳ %c  %c", '|', '<', '>', '|');



	gotoxy(30, 8);	printf("press F1 -> ���ݹ���");
	gotoxy(30, 10);	printf("press F2 -> ���ݲ�ѯ");
	gotoxy(30, 12);	printf("press F3 -> Ʊ��ϵͳ");
	gotoxy(30, 14);	printf("press F4 -> �˳�ϵͳ");
	gotoxy(5, 25);	printf("����ʱ�̱���Ϣ����ϵͳ");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}

void drawmain_user() {

	system(WIN_SIZE);

	//�ѱ�������Ϊ ǳ��ɫ
	system("color 3e");

	int i;
	/*��ӡα��������*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*��ӡα���ں���*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*��ӡ��Ϣ*/
	gotoxy(7, 1);	printf("%c  %c ���ݲ�ѯ %c  %c", '|', '<', '>', '|');
	gotoxy(52, 1);	printf("%c  %c Ʊ��ϵͳ %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c �˳�ϵͳ %c  %c", '|', '<', '>', '|');



	gotoxy(30, 8);	printf("press F1 -> ���ݲ�ѯ");
	gotoxy(30, 10);	printf("press F2 -> Ʊ��ϵͳ");
	gotoxy(30, 12);	printf("press F4 -> �˳�ϵͳ");
	gotoxy(5, 25);	printf("����ʱ�̱���Ϣ����ϵͳ");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}

void drawmain_u() {

	system(WIN_SIZE);

	//�ѱ�������Ϊ ǳ��ɫ
	system("color 8e");

	int i;
	/*��ӡα��������*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*��ӡα���ں���*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*��ӡ��Ϣ*/
	gotoxy(7, 1);	printf("%c  %c ����Ա %c  %c", '|', '<', '>', '|');
	gotoxy(67, 1);	printf("%c  %c �˿� %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F1 -> ����Ա");
	gotoxy(30, 10);	printf("press F2 -> �˿�");
	gotoxy(5, 25);	printf("����ʱ�̱���Ϣ����ϵͳ");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}

void drawmenu(int m, int n) {
	int i;
	if (m % 4 == 0)
	{
		cls();
		/*��ӡ�߿�*/
		for (i = 1; i < 3; i++)
		{
			gotoxy(7, 2 + i);	 printf("%c", '*');
			gotoxy(34, 2 + i); printf("%c", '*');
		}
		gotoxy(7, 4);  printf("****************************");
		/*��ӡ�˵�����*/
		gotoxy(9, 3);	printf("���ι���      ");
		/*��ӡѡ��*/
		switch (n % 2) {
		case 0:gotoxy(9, 3); printf("���ι���     &"); break;
		}
	}
	if (m % 4 == 1)
	{
		cls();
		/*��ӡ�߿�*/
		for (i = 1; i < 3; i++)
		{
			gotoxy(37, 2 + i);	_cprintf("%c", '*');
			gotoxy(58, 2 + i);	_cprintf("%c", '*');
		}
		gotoxy(37, 5);  _cprintf("*********************");//
		/*��ӡ�˵�����*/
		gotoxy(39, 3);	printf("���б�      ");
		gotoxy(39, 4);	printf("��ϸ��Ϣ��ѯ    ");
		/*��ӡѡ��*/
		switch (n % 2) {
		case 0:gotoxy(39, 3); printf("���б�     &"); break;
		case 1:gotoxy(39, 4); printf("��ϸ��Ϣ��ѯ   &"); break;
		}
	}
	if (m % 4 == 2)
	{
		cls();
		/*��ӡ�߿�*/
		for (i = 1; i < 2; i++)
		{
			gotoxy(67, 2 + i);	_cprintf("%c", '*');
			gotoxy(88, 2 + i);	_cprintf("%c", '*');
		}
		gotoxy(67, 4);  _cprintf("*********************");//
		/*��ӡ�˵�����*/
		gotoxy(69, 3);	printf("Ʊ��ϵͳ      ");
		/*��ӡѡ��*/
		switch (n % 1) {
		case 0:gotoxy(69, 3); printf("Ʊ��ϵͳ     &"); break;
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
		/*��ӡ�߿�*/
		for (i = 1; i < 2; i++)
		{
			gotoxy(7, 2 + i);	 printf("%c", '*');
			gotoxy(34, 2 + i); printf("%c", '*');
		}
		gotoxy(7, 4);  printf("****************************");
		/*��ӡ�˵�����*/
		gotoxy(9, 3);	printf("����Ա��¼      ");
		/*��ӡѡ��*/
		switch (n % 2) {
		case 0:gotoxy(9, 3); printf("����Ա��¼     &"); break;
		}
	}
	if (m % 4 == 1)
	{
		cls();
		/*��ӡ�߿�*/
		for (i = 1; i < 3; i++)
		{
			gotoxy(67, 2 + i);	_cprintf("%c", '*');
			gotoxy(88, 2 + i);	_cprintf("%c", '*');
		}
		gotoxy(67, 5);  _cprintf("*********************");//
		/*��ӡ�˵�����*/
		gotoxy(69, 3);	printf("�˿͵�¼      ");
		gotoxy(69, 4);	printf("�³˿�ע��    ");
		/*��ӡѡ��*/
		switch (n % 2) {
		case 0:gotoxy(69, 3); printf("�˿͵�¼     &"); break;
		case 1:gotoxy(69, 4); printf("�³˿�ע��   &"); break;
		}
	}
}


void drawmenu_user(int m, int n) {
	int i;

	if (m % 4 == 1)
	{
		cls();
		/*��ӡ�߿�*/
		for (i = 1; i < 3; i++)
		{
			gotoxy(7, 2 + i);	_cprintf("%c", '*');
			gotoxy(34, 2 + i);	_cprintf("%c", '*');
		}
		gotoxy(7, 5);  _cprintf("*********************");//
		/*��ӡ�˵�����*/
		gotoxy(9, 3);	printf("���б�      ");
		gotoxy(9, 4);	printf("��ϸ��Ϣ��ѯ    ");
		/*��ӡѡ��*/
		switch (n % 2) {
		case 0:gotoxy(9, 3); printf("���б�     &"); break;
		case 1:gotoxy(9, 4); printf("��ϸ��Ϣ��ѯ   &"); break;
		}
	}
	if (m % 4 == 2)
	{
		cls();
		/*��ӡ�߿�*/
		for (i = 1; i < 2; i++)
		{
			gotoxy(50, 2 + i);	_cprintf("%c", '*');
			gotoxy(71, 2 + i);	_cprintf("%c", '*');
		}
		gotoxy(52, 4);  _cprintf("*********************");//
		/*��ӡ�˵�����*/
		gotoxy(54, 3);	printf("Ʊ��ϵͳ      ");
		/*��ӡѡ��*/
		switch (n % 1) {
		case 0:gotoxy(54, 3); printf("Ʊ��ϵͳ     &"); break;
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

	//�ѱ�������Ϊ ǳ��ɫ
	system("color 3e");

	int i;
	/*��ӡα��������*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*��ӡα���ں���*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 4);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*��ӡ��Ϣ*/
	gotoxy(7, 1);	printf("%c  %c ���ݹ��� %c  %c", '|', '<', '>', '|');
	gotoxy(37, 1);	printf("%c  %c ���ݲ�ѯ %c  %c", '|', '<', '>', '|');
	gotoxy(67, 1);	printf("%c  %c ����ͳ�� %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c �˳�ϵͳ %c  %c", '|', '<', '>', '|');

	gotoxy(7, 3);	printf("%c  %c ����������Ϣ %c  %c", '|', '<', '>', '|');
	gotoxy(37, 3);	printf("%c  %c �޸ĳ�����Ϣ %c  %c", '|', '<', '>', '|');
	gotoxy(67, 3);	printf("%c  %c ɾ��������Ϣ %c  %c", '|', '<', '>', '|');
	gotoxy(97, 3);	printf("%c  %c �������˵� %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F5 -> ����������Ϣ");
	gotoxy(30, 10);	printf("press F6 -> �޸ĳ�����Ϣ");
	gotoxy(30, 12);	printf("press F7 -> ɾ��������Ϣ");
	gotoxy(30, 14);	printf("press F8 -> �������˵�");
	gotoxy(5, 25);	printf("����ʱ�̱���Ϣ����ϵͳ");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}




void drawmain_3() {

	system(WIN_SIZE);

	//�ѱ�������Ϊ ǳ��ɫ
	system("color 3e");

	int i;
	/*��ӡα��������*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*��ӡα���ں���*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 4);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*��ӡ��Ϣ*/
	gotoxy(7, 1);	printf("%c  %c ���ݹ��� %c  %c", '|', '<', '>', '|');
	gotoxy(37, 1);	printf("%c  %c ���ݲ�ѯ %c  %c", '|', '<', '>', '|');
	gotoxy(67, 1);	printf("%c  %c ����ͳ�� %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c �˳�ϵͳ %c  %c", '|', '<', '>', '|');

	gotoxy(7, 3);	printf("%c  %c ����ʱ���б� %c  %c", '|', '<', '>', '|');
	gotoxy(37, 3);	printf("%c  %c ���η���ʱ�� %c  %c", '|', '<', '>', '|');
	gotoxy(67, 3);	printf("%c  %c Ŀ�ĵ��б� %c  %c", '|', '<', '>', '|');
	gotoxy(97, 3);	printf("%c  %c �������˵� %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F5 -> ����ʱ���б�");
	gotoxy(30, 10);	printf("press F6 -> ���η���ʱ��");
	gotoxy(30, 12);	printf("press F7 -> Ŀ�ĵ��б�");
	gotoxy(30, 14);	printf("press F8 -> �������˵�");
	gotoxy(5, 25);	printf("����ʱ�̱���Ϣ����ϵͳ");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}


void drawmain_4() {

	system(WIN_SIZE);

	//�ѱ�������Ϊ ǳ��ɫ
	system("color 3e");

	int i;
	/*��ӡα��������*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*��ӡα���ں���*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 4);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*��ӡ��Ϣ*/
	gotoxy(7, 1);	printf("%c  %c ���ݹ��� %c  %c", '|', '<', '>', '|');
	gotoxy(37, 1);	printf("%c  %c ���ݲ�ѯ %c  %c", '|', '<', '>', '|');
	gotoxy(67, 1);	printf("%c  %c ����ͳ�� %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c �˳�ϵͳ %c  %c", '|', '<', '>', '|');

	gotoxy(7, 3);	printf("%c  %c ��κŲ�ѯ %c  %c", '|', '<', '>', '|');
	gotoxy(37, 3);	printf("%c  %c �յ�վ��ѯ %c  %c", '|', '<', '>', '|');
	gotoxy(67, 3);	printf("%c  %c �ɹ�Ʊ��ѯ %c  %c", '|', '<', '>', '|');
	gotoxy(97, 3);	printf("%c  %c �������˵� %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F5 -> ��κŲ�ѯ");
	gotoxy(30, 10);	printf("press F6 -> �յ�վ��ѯ");
	gotoxy(30, 12);	printf("press F7 -> �ɹ�Ʊ��ѯ");
	gotoxy(30, 14);	printf("press F8 -> �������˵�");
	gotoxy(5, 25);	printf("����ʱ�̱���Ϣ����ϵͳ");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}

void drawmain_5() {

	system(WIN_SIZE);

	//�ѱ�������Ϊ ǳ��ɫ
	system("color 3e");

	int i;
	/*��ӡα��������*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*��ӡα���ں���*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 4);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*��ӡ��Ϣ*/
	gotoxy(7, 1);	printf("%c  %c ���ݹ��� %c  %c", '|', '<', '>', '|');
	gotoxy(37, 1);	printf("%c  %c ���ݲ�ѯ %c  %c", '|', '<', '>', '|');
	gotoxy(67, 1);	printf("%c  %c Ʊ��ϵͳ %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c �˳�ϵͳ %c  %c", '|', '<', '>', '|');

	gotoxy(7, 3);	printf("%c  %c ��Ʊ %c  %c", '|', '<', '>', '|');
	gotoxy(67, 3);	printf("%c  %c ��Ʊ %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F5 -> ��Ʊ");
	gotoxy(30, 10);	printf("press F6 -> ��Ʊ");

	gotoxy(5, 25);	printf("����ʱ�̱���Ϣ����ϵͳ");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}




void drawmain_3c() {

	system(WIN_SIZE);

	//�ѱ�������Ϊ ǳ��ɫ
	system("color 3e");

	int i;
	/*��ӡα��������*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*��ӡα���ں���*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*��ӡ��Ϣ*/
	gotoxy(7, 1);	printf("%c  %c ���ݲ�ѯ %c  %c", '|', '<', '>', '|');
	gotoxy(52, 1);	printf("%c  %c Ʊ��ϵͳ %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c �˳�ϵͳ %c  %c", '|', '<', '>', '|');

	gotoxy(7, 3);	printf("%c  %c ����ʱ���б� %c  %c", '|', '<', '>', '|');
	gotoxy(37, 3);	printf("%c  %c ���η���ʱ�� %c  %c", '|', '<', '>', '|');
	gotoxy(67, 3);	printf("%c  %c Ŀ�ĵ��б� %c  %c", '|', '<', '>', '|');
	gotoxy(97, 3);	printf("%c  %c �������˵� %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F5 -> ����ʱ���б�");
	gotoxy(30, 10);	printf("press F6 -> ���η���ʱ��");
	gotoxy(30, 12);	printf("press F7 -> Ŀ�ĵ��б�");
	gotoxy(30, 14);	printf("press F8 -> �������˵�");
	gotoxy(5, 25);	printf("����ʱ�̱���Ϣ����ϵͳ");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}





void drawmain_4c() {

	system(WIN_SIZE);

	//�ѱ�������Ϊ ǳ��ɫ
	system("color 3e");

	int i;
	/*��ӡα��������*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*��ӡα���ں���*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*��ӡ��Ϣ*/
	gotoxy(7, 1);	printf("%c  %c ���ݲ�ѯ %c  %c", '|', '<', '>', '|');
	gotoxy(52, 1);	printf("%c  %c Ʊ��ϵͳ %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c �˳�ϵͳ %c  %c", '|', '<', '>', '|');

	gotoxy(7, 3);	printf("%c  %c ��κŲ�ѯ %c  %c", '|', '<', '>', '|');
	gotoxy(37, 3);	printf("%c  %c �յ�վ��ѯ %c  %c", '|', '<', '>', '|');
	gotoxy(67, 3);	printf("%c  %c �ɹ�Ʊ��ѯ %c  %c", '|', '<', '>', '|');
	gotoxy(97, 3);	printf("%c  %c �������˵� %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F5 -> ��κŲ�ѯ");
	gotoxy(30, 10);	printf("press F6 -> �յ�վ��ѯ");
	gotoxy(30, 12);	printf("press F7 -> �ɹ�Ʊ��ѯ");
	gotoxy(30, 14);	printf("press F8 -> �������˵�");
	gotoxy(5, 25);	printf("����ʱ�̱���Ϣ����ϵͳ");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}

void drawmain_5c() {

	system(WIN_SIZE);

	//�ѱ�������Ϊ ǳ��ɫ
	system("color 3e");

	int i;
	/*��ӡα��������*/
	for (i = 1; i < 30; i++)
	{
		gotoxy(1, i);
		_cprintf("%c", '|');
		gotoxy(120, i);
		_cprintf("%c", '|');
	}
	/*��ӡα���ں���*/
	gotoxy(2, 0);	drawline('-');
	gotoxy(2, 2);	drawline('-');
	gotoxy(2, 26);	drawline('-');
	gotoxy(2, 29);	drawline('-');
	/*��ӡ��Ϣ*/
	gotoxy(7, 1);	printf("%c  %c ���ݲ�ѯ %c  %c", '|', '<', '>', '|');
	gotoxy(52, 1);	printf("%c  %c Ʊ��ϵͳ %c  %c", '|', '<', '>', '|');
	gotoxy(97, 1);	printf("%c  %c �˳�ϵͳ %c  %c", '|', '<', '>', '|');

	gotoxy(7, 3);	printf("%c  %c ��Ʊ %c  %c", '|', '<', '>', '|');
	gotoxy(67, 3);	printf("%c  %c ��Ʊ %c  %c", '|', '<', '>', '|');

	gotoxy(30, 8);	printf("press F5 -> ��Ʊ");
	gotoxy(30, 10);	printf("press F6 -> ��Ʊ");

	gotoxy(5, 25);	printf("����ʱ�̱���Ϣ����ϵͳ");
	gotoxy(65, 25); printf("Version 2.0");
	gotoxy(65, 28);
}
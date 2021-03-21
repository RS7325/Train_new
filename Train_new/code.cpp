//#include<stdio.h>
//#include<graphics.h>
//#include<windows.h>
//
//void MainMenu();
//void Data_Management();
//void Train_Management();
//void Station_Management();
//void Station_InfManagement();
//
//void Data_Query();
//void Sample_List();
//
//
//void MainMenu()
//{
//
//	MOUSEMSG m;
//	initgraph(800, 600);
//	setbkcolor(WHITE);
//	cleardevice();
//	setfillcolor(LIGHTBLUE);
//	setbkmode(TRANSPARENT);
//	settextstyle(30, 0, _T("楷体"));
//	fillrectangle(300, 110, 500, 160);
//	outtextxy(340, 120, _T("数据管理"));
//	fillrectangle(300, 200, 500, 250);
//	outtextxy(340, 210, _T("数据查询"));
//	fillrectangle(300, 290, 500, 340);
//	outtextxy(340, 300, _T("数据统计"));
//	fillrectangle(300, 380, 500, 430);
//	outtextxy(340, 390, _T("退出系统"));
//
//	while (1)
//	{
//		m = GetMouseMsg();
//		if (m.x >= 300 && m.x <= 500 && m.y >= 110 && m.y <= 160)
//		{
//			setlinecolor(RED);
//			rectangle(280, 90, 520, 180);
//			if (m.uMsg == WM_LBUTTONDOWN) {
//				Data_Management();
//				break;
//			}
//
//		}
//		else if (m.x >= 300 && m.x <= 500 && m.y >= 200 && m.y <= 250)
//		{
//			setlinecolor(RED);
//			rectangle(280, 180, 520, 270);
//			if (m.uMsg == WM_LBUTTONDOWN) {
//				Data_Query();
//				break;
//			}
//		}
//		else if (m.x >= 300 && m.x <= 500 && m.y >= 290 && m.y <= 340)
//		{
//			setlinecolor(RED);
//			rectangle(280, 270, 520, 360);
//		}
//		else if (m.x >= 300 && m.x <= 500 && m.y >= 380 && m.y <= 430)
//		{
//			setlinecolor(RED);
//			rectangle(280, 360, 520, 450);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				closegraph();
//				exit(0);
//				system("pause");
//			}
//		}
//		else
//		{
//			setlinecolor(WHITE);
//			rectangle(280, 90, 520, 180);
//			rectangle(280, 180, 520, 270);
//			rectangle(280, 270, 520, 360);
//			rectangle(280, 360, 520, 450);
//		}
//
//	}
//}
//void Data_Management()
//{
//	MOUSEMSG m;
//	initgraph(800, 600);
//	setbkcolor(WHITE);
//	cleardevice();
//	setfillcolor(LIGHTBLUE);
//	setbkmode(TRANSPARENT);
//	settextstyle(30, 0, _T("楷体"));
//	fillrectangle(280, 50, 520, 130);
//	outtextxy(340, 75, _T("车次管理"));
//	fillrectangle(280, 155, 520, 235);
//	outtextxy(310, 180, _T("经停车站管理"));
//	fillrectangle(280, 260, 520, 340);
//	outtextxy(280, 285, _T("经停车站信息管理"));
//	fillrectangle(280, 365, 520, 445);
//	outtextxy(325, 390, _T("返回主菜单"));
//	fillrectangle(280, 470, 520, 550);
//	outtextxy(340, 495, _T("退出系统"));
//	while (true)
//	{
//		m = GetMouseMsg();
//		if (m.x >= 300 && m.x <= 500 && m.y >= 50 && m.y <= 130)		//车次管理
//		{
//			setlinecolor(RED);
//			rectangle(270, 40, 530, 140);
//			if (m.uMsg == WM_LBUTTONDOWN) {
//				Train_Management();
//				break;
//			}
//
//		}
//		else if (m.x >= 300 && m.x <= 500 && m.y >= 155 && m.y <= 235)		//经停车站管理
//		{
//
//			setlinecolor(RED);
//			rectangle(270, 145, 530, 245);
//			if (m.uMsg == WM_LBUTTONDOWN) {
//				Station_Management();
//				break;
//			}
//		}
//		else if (m.x >= 300 && m.x <= 500 && m.y >= 260 && m.y <= 340)		//经停车站信息管理
//		{
//			setlinecolor(RED);
//			rectangle(270, 250, 530, 350);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				Station_InfManagement();
//				break;
//
//			}
//		}
//		else if (m.x >= 300 && m.x <= 500 && m.y >= 365 && m.y <= 445)		//返回主菜单
//		{
//			setlinecolor(RED);
//			rectangle(270, 355, 530, 455);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				MainMenu();
//			}
//		}
//
//		else if (m.x >= 300 && m.x <= 500 && m.y >= 470 && m.y <= 550)			//退出系统
//		{
//			setlinecolor(RED);
//			rectangle(270, 460, 530, 560);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				closegraph();
//				exit(0);
//
//			}
//		}
//		else
//		{
//			setlinecolor(WHITE);
//			rectangle(270, 40, 530, 140);
//			rectangle(270, 145, 530, 245);
//			rectangle(270, 250, 530, 350);
//			rectangle(270, 355, 530, 455);
//			rectangle(270, 460, 530, 560);
//		}
//	}
//
//}
//void Train_Management()
//{
//	MOUSEMSG m;
//	initgraph(800, 600);
//	setbkcolor(WHITE);
//	cleardevice();
//	setfillcolor(LIGHTBLUE);
//	setbkmode(TRANSPARENT);
//	settextstyle(30, 0, _T("楷体"));
//	fillrectangle(280, 40, 520, 90);
//	outtextxy(340, 50, _T("新增车次"));
//	fillrectangle(280, 134, 520, 184);
//	outtextxy(340, 144, _T("修改车次"));
//	fillrectangle(280, 228, 520, 278);
//	outtextxy(340, 238, _T("删除车次"));
//	fillrectangle(280, 322, 520, 372);
//	outtextxy(325, 332, _T("返回上一级"));
//	fillrectangle(280, 416, 520, 466);
//	outtextxy(325, 426, _T("返回主菜单"));
//	fillrectangle(280, 510, 520, 560);
//	outtextxy(340, 520, _T("退出系统"));
//	while (true)
//	{
//		m = GetMouseMsg();
//		if (m.x >= 280 && m.x <= 520 && m.y >= 40 && m.y <= 90)			//新增车次
//		{
//			setlinecolor(RED);
//			rectangle(270, 30, 530, 100);
//			if (m.uMsg == WM_LBUTTONDOWN) {
//				Train_Management();
//				break;
//			}
//
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 134 && m.y <= 184)		//修改车次
//		{
//			setlinecolor(RED);
//			rectangle(270, 124, 530, 194);
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 228 && m.y <= 278)		//删除车次
//		{
//			setlinecolor(RED);
//			rectangle(270, 218, 530, 288);
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 322 && m.y <= 372)		//返回上一级
//		{
//			setlinecolor(RED);
//			rectangle(270, 312, 530, 382);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				Data_Management();
//			}
//		}
//
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 416 && m.y <= 466)		//返回主菜单
//		{
//			setlinecolor(RED);
//			rectangle(270, 406, 530, 476);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				MainMenu();
//
//			}
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 510 && m.y <= 560)		//退出系统
//		{
//			setlinecolor(RED);
//			rectangle(270, 500, 530, 570);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				closegraph();
//				exit(0);
//
//			}
//		}
//		else
//		{
//			setlinecolor(WHITE);
//			rectangle(270, 30, 530, 100);
//			rectangle(270, 124, 530, 194);
//			rectangle(270, 218, 530, 288);
//			rectangle(270, 312, 530, 382);
//			rectangle(270, 406, 530, 476);
//			rectangle(270, 500, 530, 570);
//		}
//	}
//
//}
//void Station_Management()
//{
//	MOUSEMSG m;
//	initgraph(800, 600);
//	setbkcolor(WHITE);
//	cleardevice();
//	setfillcolor(LIGHTBLUE);
//	setbkmode(TRANSPARENT);
//	settextstyle(30, 0, _T("楷体"));
//	fillrectangle(280, 40, 520, 90);
//	outtextxy(310, 50, _T("新增经停车站"));
//	fillrectangle(280, 134, 520, 184);
//	outtextxy(310, 144, _T("修改经停车站"));
//	fillrectangle(280, 228, 520, 278);
//	outtextxy(310, 238, _T("删除经停车站"));
//	fillrectangle(280, 322, 520, 372);
//	outtextxy(325, 332, _T("返回上一级"));
//	fillrectangle(280, 416, 520, 466);
//	outtextxy(325, 426, _T("返回主菜单"));
//	fillrectangle(280, 510, 520, 560);
//	outtextxy(340, 520, _T("退出系统"));
//	while (true)
//	{
//		m = GetMouseMsg();
//		if (m.x >= 280 && m.x <= 520 && m.y >= 40 && m.y <= 90)			//新增车次
//		{
//			setlinecolor(RED);
//			rectangle(270, 30, 530, 100);
//			if (m.uMsg == WM_LBUTTONDOWN) {
//				Train_Management();
//				break;
//			}
//
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 134 && m.y <= 184)		//修改车次
//		{
//			setlinecolor(RED);
//			rectangle(270, 124, 530, 194);
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 228 && m.y <= 278)		//删除车次
//		{
//			setlinecolor(RED);
//			rectangle(270, 218, 530, 288);
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 322 && m.y <= 372)		//返回上一级
//		{
//			setlinecolor(RED);
//			rectangle(270, 312, 530, 382);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				Data_Management();
//			}
//		}
//
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 416 && m.y <= 466)		//返回主菜单
//		{
//			setlinecolor(RED);
//			rectangle(270, 406, 530, 476);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				MainMenu();
//
//			}
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 510 && m.y <= 560)		//退出系统
//		{
//			setlinecolor(RED);
//			rectangle(270, 500, 530, 570);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				closegraph();
//				exit(0);
//
//			}
//		}
//		else
//		{
//			setlinecolor(WHITE);
//			rectangle(270, 30, 530, 100);
//			rectangle(270, 124, 530, 194);
//			rectangle(270, 218, 530, 288);
//			rectangle(270, 312, 530, 382);
//			rectangle(270, 406, 530, 476);
//			rectangle(270, 500, 530, 570);
//		}
//	}
//
//}
//void Station_InfManagement()
//{
//	MOUSEMSG m;
//	initgraph(800, 600);
//	setbkcolor(WHITE);
//	cleardevice();
//	setfillcolor(LIGHTBLUE);
//	setbkmode(TRANSPARENT);
//	settextstyle(25, 0, _T("楷体"));
//	fillrectangle(280, 40, 520, 90);
//	outtextxy(300, 50, _T("新增经停车站信息"));
//	fillrectangle(280, 134, 520, 184);
//	outtextxy(300, 144, _T("修改经停车站信息"));
//	fillrectangle(280, 228, 520, 278);
//	outtextxy(300, 238, _T("删除经停车站信息"));
//	fillrectangle(280, 322, 520, 372);
//	outtextxy(325, 332, _T("返回上一级"));
//	fillrectangle(280, 416, 520, 466);
//	outtextxy(325, 426, _T("返回主菜单"));
//	fillrectangle(280, 510, 520, 560);
//	outtextxy(340, 520, _T("退出系统"));
//	while (true)
//	{
//		m = GetMouseMsg();
//		if (m.x >= 280 && m.x <= 520 && m.y >= 40 && m.y <= 90)			//新增车次
//		{
//			setlinecolor(RED);
//			rectangle(270, 30, 530, 100);
//			if (m.uMsg == WM_LBUTTONDOWN) {
//				Train_Management();
//				break;
//			}
//
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 134 && m.y <= 184)		//修改车次
//		{
//			setlinecolor(RED);
//			rectangle(270, 124, 530, 194);
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 228 && m.y <= 278)		//删除车次
//		{
//			setlinecolor(RED);
//			rectangle(270, 218, 530, 288);
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 322 && m.y <= 372)		//返回上一级
//		{
//			setlinecolor(RED);
//			rectangle(270, 312, 530, 382);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				Data_Management();
//			}
//		}
//
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 416 && m.y <= 466)		//返回主菜单
//		{
//			setlinecolor(RED);
//			rectangle(270, 406, 530, 476);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				MainMenu();
//
//			}
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 510 && m.y <= 560)		//退出系统
//		{
//			setlinecolor(RED);
//			rectangle(270, 500, 530, 570);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				closegraph();
//				exit(0);
//
//			}
//		}
//		else
//		{
//			setlinecolor(WHITE);
//			rectangle(270, 30, 530, 100);
//			rectangle(270, 124, 530, 194);
//			rectangle(270, 218, 530, 288);
//			rectangle(270, 312, 530, 382);
//			rectangle(270, 406, 530, 476);
//			rectangle(270, 500, 530, 570);
//		}
//	}
//}
//
//void Data_Query()
//{
//	MOUSEMSG m;
//	initgraph(800, 600);
//	setbkcolor(WHITE);
//	cleardevice();
//	setfillcolor(LIGHTBLUE);
//	setbkmode(TRANSPARENT);
//	settextstyle(30, 0, _T("楷体"));
//	fillrectangle(280, 50, 520, 130);
//	outtextxy(340, 75, _T("简单列表"));
//	fillrectangle(280, 190, 520, 270);
//	outtextxy(340, 215, _T("复合查询"));
//	fillrectangle(280, 330, 520, 410);
//	outtextxy(325, 355, _T("返回上一级"));
//	fillrectangle(280, 470, 520, 550);
//	outtextxy(340, 495, _T("退出系统"));
//	while (true)
//	{
//		m = GetMouseMsg();
//		if (m.x >= 280 && m.x <= 520 && m.y >= 50 && m.y <= 130)			//简单列表
//		{
//			setlinecolor(RED);
//			rectangle(270, 40, 530, 140);
//			if (m.uMsg == WM_LBUTTONDOWN) {
//				Sample_List();
//				break;
//			}
//
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 190 && m.y <= 270)		//复合查询
//		{
//			setlinecolor(RED);
//			rectangle(270, 180, 530, 280);
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 330 && m.y <= 410)		//返回主菜单
//		{
//			setlinecolor(RED);
//			rectangle(270, 320, 530, 420);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				MainMenu();
//			}
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 470 && m.y <= 550)		//退出系统
//		{
//			setlinecolor(RED);
//			rectangle(270, 460, 530, 560);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				closegraph();
//				exit(0);
//			}
//
//		}
//		else
//		{
//			setlinecolor(WHITE);
//			rectangle(270, 40, 530, 140);
//			rectangle(270, 180, 530, 280);
//			rectangle(270, 320, 530, 420);
//			rectangle(270, 460, 530, 560);
//		}
//	}
//}
//void Sample_List()
//{
//	MOUSEMSG m;
//	initgraph(800, 600);
//	setbkcolor(WHITE);
//	cleardevice();
//	setfillcolor(LIGHTBLUE);
//	setbkmode(TRANSPARENT);
//	settextstyle(30, 0, _T("楷体"));
//	fillrectangle(280, 40, 520, 90);
//	outtextxy(340, 50, _T("车次列表"));
//	fillrectangle(280, 134, 520, 184);
//	outtextxy(295, 144, _T("车次经停站列表"));
//	fillrectangle(280, 228, 520, 278);
//	outtextxy(325, 238, _T("经停站列表"));
//	fillrectangle(280, 322, 520, 372);
//	outtextxy(325, 332, _T("返回上一级"));
//	fillrectangle(280, 416, 520, 466);
//	outtextxy(325, 426, _T("返回主菜单"));
//	fillrectangle(280, 510, 520, 560);
//	outtextxy(340, 520, _T("退出系统"));
//	while (true)
//	{
//		m = GetMouseMsg();
//		if (m.x >= 280 && m.x <= 520 && m.y >= 40 && m.y <= 90)			//车次列表
//		{
//			setlinecolor(RED);
//			rectangle(270, 30, 530, 100);
//			if (m.uMsg == WM_LBUTTONDOWN) {
//				Train_Management();
//				break;
//			}
//
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 134 && m.y <= 184)		//车次经停站列表
//		{
//			setlinecolor(RED);
//			rectangle(270, 124, 530, 194);
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 228 && m.y <= 278)		//经停站列表
//		{
//			setlinecolor(RED);
//			rectangle(270, 218, 530, 288);
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 322 && m.y <= 372)		//返回上一级
//		{
//			setlinecolor(RED);
//			rectangle(270, 312, 530, 382);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				Data_Query();
//				break;
//			}
//		}
//
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 416 && m.y <= 466)		//返回主菜单
//		{
//			setlinecolor(RED);
//			rectangle(270, 406, 530, 476);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				MainMenu();
//
//			}
//		}
//		else if (m.x >= 280 && m.x <= 520 && m.y >= 510 && m.y <= 560)		//退出系统
//		{
//			setlinecolor(RED);
//			rectangle(270, 500, 530, 570);
//			if (m.uMsg == WM_LBUTTONDOWN)
//			{
//				closegraph();
//				exit(0);
//
//			}
//		}
//		else
//		{
//			setlinecolor(WHITE);
//			rectangle(270, 30, 530, 100);
//			rectangle(270, 124, 530, 194);
//			rectangle(270, 218, 530, 288);
//			rectangle(270, 312, 530, 382);
//			rectangle(270, 406, 530, 476);
//			rectangle(270, 500, 530, 570);
//		}
//	}
//}
//
//int main()
//{
//	MainMenu();
//	system("pause");
//
//}
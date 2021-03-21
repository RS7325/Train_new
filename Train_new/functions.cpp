#include "info.h"

#define HEADER1 "|Number    |Name      |Author    |Publish   |Price | F|Reader    |Total|"
#define FORMAT1 "|%-10s|%-10s|%-10s|%-10s|%-6.2f|%2d|%-10s|%5d|"
#define DATA1 lll->data.num,lll->data.name,lll->data.author,lll->data.publish,lll->data.price,lll->data.borrow_flag,lll->data.reader,lll->data.total_num
#define HEADER2 "|Number      |Name      |Sex |Age |Tele           |Total|"
#define FORMAT2 "|%-12s|%-10s|%-4s|%-4d|%-15s|%-5d|"
#define DATA2 lll->data.num,lll->data.name,lll->data.sex,lll->data.age,lll->data.tele,lll->data.total_num

int count = 0;     //定义全局变量，用于记录增加的列车信息数量
int more = 0;     //定义全局变量，用于记录注册乘客的数量 
char name1[10];     //定义全局变量，记录乘客账户名
int xy;     //定义全局变量，记录乘客购票数量 
int tt = 0;


struct Mem1     //管理员信息结构体
{
	char name1[10];     //管理员名单 
	long int num1;     //管理员密码 
	int num[SIZE3];     //乘客购买车票的班次号 

}mem1[SIZE3];


struct Mem2     //乘客信息结构体 
{
	char name2[10];     //乘客账号名 
	long int num2;     //乘客密码 
	int num[SIZE3];     //乘客购买车票的班次号 
}mem2[SIZE1];


struct Line
{
	int num1;     //班次
	int time;     //发车时间
	char sta1[10];     //起点站
	char sta2[10];     //终点站
	double num2;     //行车时间
	int max;     //额定数量
	int real;     //已订票人数
	int price;     //票价 
}line_1[SIZE2];


void change()      //修改函数 
{
	FILE* fp;
	int i, n = 0;      //n用于记录要修改的班次号
	int flag, m;
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		system("pause");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	printf("请输入您要修改列车的班次号：");
	scanf_s("%d", &n);
	flag = 0;
	for (i = 0; i < SIZE1 + count; i++) {
		if (n == line_1[i].num1) {
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("没有该班次列车！！无法修改！！\n\n");
		printf("请选择下一步操作：\n1、继续修改\n2、返回菜单\n0、退出\n");
		printf("我的选择是：");
		scanf_s("%d", &m);
		system("cls");     //清屏 
		switch (m)
		{
		case 1:
			change();
			system("cls");
			printf("修改后的总信息表如下：\n");
			print();
			//Start();
			break;
		case 2:
			Start(1);
			break;
		case 0:
			printf("成功退出！！！\n\n\n");
			exit(0);
			break;
		default:
			printf("出错！！！！\n\n\n");
			exit(0);
		}
	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (line_1[i].num1 == n) {
			printf("\n\n\n请重新输入列车相关信息：\n");
			printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
			scanf("%d%d%s%s%lf%d%d%d", &line_1[i].num1, &line_1[i].time, line_1[i].sta1, \
				line_1[i].sta2, &line_1[i].num2, &line_1[i].max, &line_1[i].real, &line_1[i].price);

		}
	}     //先修改原来的信息 
	fclose(fp);
	if ((fp = fopen("data.txt", "wb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
			printf("file write error\n");
	}
	fclose(fp);     //重新导入文件 	
	printf("修改成功！");
}


void add()     //增加函数 
{
	FILE* fp;
	int i = 1;
	int num;     //用于记录添加的列车班次号 
	int flag = 0;
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		system("pause");
	}     //打开原有文件用于追加列车信息
	for (i = 0; i < 1; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	printf("请输入您要添加的列车班次号：");
	scanf_s("%d", &num);
	for (i = 0; i < SIZE1 + count; i++) {
		if (num == line_1[i].num1) {
			flag = 1;
		}
	}
	if (flag == 1) {
		printf("已有该班次列车！！无法添加！！\n\n");
		system("pause");
		system("cls");     //清屏 
	}
	while (count <= SIZE2 - SIZE1) {

		printf("\n\n\n请输入要添加列车的相关信息：\n");
		printf("车次,发车时间,始发站,终点站,行车时间,额定数量,已订票人数,票价\n");
		scanf("%d%d%s%s%lf%d%d%d", &line_1[SIZE1 + count].num1, &line_1[SIZE1 + count].time, line_1[SIZE1 + count].sta1, \
			line_1[SIZE1 + count].sta2, &line_1[SIZE1 + count].num2, &line_1[SIZE1 + count].max, &line_1[SIZE1 + count].real, &line_1[SIZE1 + count].price);
		count++;
	}
	if (count > SIZE2 - SIZE1) {
		printf("已超过额定数量，无法继续添加！\n");
		system("pause");
		Start(1);
	}

	fclose(fp);
	if ((fp = fopen("data.txt", "wb")) == NULL) {
		printf("cannot open file\n");
		system("pause");
		exit(0);
	}

	for (i = 0; i < SIZE1 + count; i++) {
		if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
			printf("file write error\n");
		system("pause");
	}
	fclose(fp);     //重新导入文件 	
	Start(1);
}


void del()     //删除函数 
{
	char id[10];
	char Choice[10];
	FILE* fp;
	Line* temp = new Line[SIZE1 + count];
	int i = 1, n = 0, num = 0, max = SIZE1 + count;
	int j = 1, k;
	int flag;
	int m;     //用于记录管理员选择  
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		return;
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	fclose(fp);
	if ((fp = fopen("memory2.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		return;
	}
	for (i = 0; i < SIZE3 + more; i++) {
		fread(&mem2[i], sizeof(struct Mem2), 1, fp);
	}
	fclose(fp);
	flag = 0;
	//printf("请输入要删除的班次号：");
	//scanf("%d", &num);
	InputBox(id, 128, "请输入要删除的班次号：");
	num = atoi(id);
	for (i = 0; i < SIZE1 + count; i++) {
		if (num == line_1[i].num1) {
			printf("删除完成！");

			flag = 1;
		}
	}
	if (flag == 0) {
		printf("没有该班次列车！！无法删除！！\n\n");
		printf("请选择下一步操作：\n1、继续删除\n2、返回菜单\n0、退出\n");
		printf("我的选择是：");
		InputBox(Choice, 128, "请输入要删除的班次号：");
		m = atoi(Choice);
		//scanf("%d", &m);

		system("cls");     //清屏 
		switch (m)
		{
		case 1:
			del();
			system("cls");     //清屏 
			printf("删除后的总信息表如下：\n");
			print();
			Start(1);
			break;
		case 2:
			Start(1);
			break;
		case 0:
			printf("成功退出！！！\n\n\n");
			exit(0);
			break;
		default:
			printf("出错！！！！\n\n\n");
			exit(0);
		}
	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (line_1[i].num1 != num) {     //存储剩余班次信息
			//printf("%d\n\n\n",i); 		   
			temp[n].num1 = line_1[i].num1;
			temp[n].num2 = line_1[i].num2;
			temp[n].time = line_1[i].time;
			strcpy(temp[n].sta1, line_1[i].sta1);
			strcpy(temp[n].sta2, line_1[i].sta2);
			temp[n].max = line_1[i].max;
			temp[n].real = line_1[i].real;
			temp[n].price = line_1[i].price;
			n++;
		}
	}
	for (i = 0; i < SIZE3 + more; i++) {
		for (j = 0; j < SIZE3; j++) {
			if (num == mem2[i].num[j]) {
				mem2[i].num[j] = 0;
			}
		}
	}
	Mem2 camp;
	for (k = 0; k < SIZE3 + more; k++) {
		for (i = 0; i < SIZE3; i++) {
			for (j = 0; j < SIZE3 - i - 1; j++) {
				if (mem2[k].num[j] < mem2[k].num[j + 1]) {
					camp.num[0] = mem2[k].num[j];
					mem2[k].num[j] = mem2[k].num[j + 1];
					mem2[k].num[j + 1] = camp.num[0];
				}
			}
		}
	}
	if ((fp = fopen("memory2.txt", "wb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE3 + more; i++) {
		if (fwrite(&mem2[i], sizeof(struct Mem2), 1, fp) != 1)
			printf("file write error\n");
	}
	fclose(fp);     //重新导入文件
	SIZE1 + count--;
	if (n == max) {
		printf("已没有数据可以再删除！！\n");
	}
	if ((fp = fopen("data.txt", "wb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (fwrite(&temp[i], sizeof(struct Line), 1, fp) != 1)
			printf("file write error\n");
	}
	fclose(fp);     //重新导入文件 	
}


void print()      //管理员可见输出函数 
{
	FILE* fp;
	int i;
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}     //打开数据文件 
	printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
		printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d",line_1[i].num1,line_1[i].time,\
			line_1[i].sta1,line_1[i].sta2,line_1[i].num2,line_1[i].max,line_1[i].real,line_1[i].price);
		printf("\n");
	}
	fclose(fp);     //关闭文件 
}


void save()     //更新函数 
{
	FILE* fp;
	int i;
	if ((fp = fopen("data.txt", "wb")) == NULL) {
		printf("cannot open file\n");
		return;
	}     //创建并打开一个文件用于存储原始的列车信息
	printf("请输入列车信息(10个)：\n");
	printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
	for (i = 0; i < SIZE1 + count; i++) {
		scanf("%d%d%s%s%lf%d%d%d", &line_1[i].num1, &line_1[i].time, line_1[i].sta1, \
			line_1[i].sta2, &line_1[i].num2, &line_1[i].max, &line_1[i].real, &line_1[i].price);

	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
			printf("file write error\n");
	}     //信息被写入文件 
	fclose(fp);     //关闭文件 

}


void printtime()     //乘客可见输出函数
{
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	FILE* fp;
	int i;
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}     //打开数据文件
	printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
	for (i = 0; i < SIZE1 + count; i++) {
		printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d",line_1[i].num1,line_1[i].time,\
			line_1[i].sta1,line_1[i].sta2,line_1[i].num2,line_1[i].max,line_1[i].real,line_1[i].price);
		if (lt->tm_hour >= line_1[i].time) {
			printf("  此车已开走！");
		}
		printf("\n");
	}
	fclose(fp);
}


void printID()     
{
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	FILE* fp;
	int i;
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}     //打开数据文件
	printf("车次  发车时间  票价\n");
	for (i = 0; i < SIZE1 + count; i++) {
		printf("%d\t%d点\t%d",line_1[i].num1,line_1[i].time,line_1[i].price);
		if (lt->tm_hour >= line_1[i].time) {
			printf("            此车已开走！");
		}
		printf("\n");
	}
	fclose(fp);
}


void printDestn()     
{
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	FILE* fp;
	int i;
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}     //打开数据文件
	printf("车次  发车时间  终点站  已订票人数  票价\n");
	for (i = 0; i < SIZE1 + count; i++) {
		printf("%d\t%d点\t%s\t%d\t%d",line_1[i].num1,line_1[i].time,line_1[i].sta2,line_1[i].real,line_1[i].price);
		if (lt->tm_hour >= line_1[i].time) {
			printf("  此车已开走！");
		}
		printf("\n");
	}
	fclose(fp);
}



void look1()     //发车时间函数
{
	FILE* fp;
	int i, j;
	Line temp;     //定义结构体临时变量，用于记录 
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	for (i = 0; i < SIZE1 + count - 1; i++) {
		for (j = 0; j < SIZE1 + count - i - 1; j++) {
			if (line_1[j].time > line_1[j + 1].time) {
				temp = line_1[j];
				line_1[j] = line_1[j + 1];
				line_1[j + 1] = temp;
			}
		}
	}
	fclose(fp);
	if ((fp = fopen("data.txt", "wb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
			printf("file write error\n");
	}
	fclose(fp);     //重新导入文件 
	printf("您所需的信息为：\n");
	printtime();
}


void look2()     //发车时间函数 
{
	FILE* fp;
	int i, j;
	Line temp;     //定义结构体临时变量，用于记录 
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	for (i = 0; i < SIZE1 + count - 1; i++) {
		for (j = 0; j < SIZE1 + count - i - 1; j++) {
			if (line_1[j].num1 > line_1[j + 1].num1) {
				temp = line_1[j];
				line_1[j] = line_1[j + 1];
				line_1[j + 1] = temp;
			}
		}
	}
	fclose(fp);
	if ((fp = fopen("data.txt", "wb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
			printf("file write error\n");
	}
	fclose(fp);     //重新导入文件 
	printf("您所需的信息为：\n");
	printID();
}


void look3()     //目的地函数 
{
	FILE* fp;
	int i, j;
	Line temp;     //定义结构体临时变量，用于记录
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	for (i = 0; i < SIZE1 + count - 1; i++) {
		for (j = 0; j < SIZE1 + count - i - 1; j++) {
			if (line_1[j].real > line_1[j + 1].real) {
				temp = line_1[j];
				line_1[j] = line_1[j + 1];
				line_1[j + 1] = temp;
			}
		}
	}
	fclose(fp);
	if ((fp = fopen("data.txt", "wb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
			printf("file write error\n");
	}
	fclose(fp);     //重新导入文件 
	printf("您所需的信息为：\n");
	printDestn();
}


void seek1()      //班次号查询函数 
{
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	FILE* fp;
	int i, j = 1, num = 0;
	int m, n;
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	fclose(fp);
	while (1) {
		if (j != 0) {
			m = 0;
			printf("请输入您要查询的班次号：");
			scanf_s("%d", &num);
			for (i = 0; i < SIZE1 + count; i++) {
				if (num == line_1[i].num1) {
					m = 1;
					n = i;
				}
			}
			if (m == 1) {
				printf("该班次的信息为：\n");
				printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
				printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d", line_1[n].num1, line_1[n].time, \
					line_1[n].sta1, line_1[n].sta2, line_1[n].num2, line_1[n].max, line_1[n].real, line_1[n].price);
				if (lt->tm_hour > line_1[i].time) {
					printf("     此车已开走！");
				}
				printf("\n");
			}
			else {
				printf("没有该班次列车信息！！！！\n");
				break;
			}
		}
		else {
			break;
		}
		printf("是否继续查询？是 1；\t否 0；");
		scanf_s("%d", &j);
	}
	if (j == 0) {
		system("cls");     //清屏 
	}
}


void seek2()     //终点站查询函数 
{
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	//Line temp;
	FILE* fp;
	int i, j = 1;
	char s[10];
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	while (1) {
		int k = 0;
		if (j != 0) {
			//printf("请输入您要查询的终点站：");
			//scanf("%s", s);

			InputBox(s, 128, "请输入您要查询的终点站：");

			printf("该班次的信息为：\n");
			printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
			for (i = 0; i < SIZE1 + count; i++) {
				if (strcmp(s, line_1[i].sta2) == 0) {
					printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
						line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
					if (lt->tm_hour > line_1[i].time) {
						printf("    此车已开走！");
					}
					printf("\n");
					k = 1;
				}
			}
		}
		else {
			break;
		}
		if (k == 0) {
			printf("\n\n\n没有该终点站的相关列车信息！！！\n");
		}
		printf("是否继续查询？是 1；否 0；");
		scanf_s("%d", &j);
		system("cls");
	}
	if (j == 0) {
		system("cls");     //清屏 
	}
	fclose(fp);
}


void seek3()     //可购票查询函数 
{
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	FILE* fp;
	int i, flag = 0;     //flag作为判断变量 	
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	printf("当前可售票的车次为：\n");
	printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
	for (i = 0; i < SIZE1 + count; i++) {
		if ((lt->tm_hour < line_1[i].time) && (line_1[i].real < line_1[i].max)) {
			printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
				line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
			printf("\n");
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("\n\n\n当前没有可购票的车次！请耐心等待！！\n");
	}
	fclose(fp);
}


void buy()      //购票系统函数 
{
	FILE* fp;
	char id[10];
	int i, j, k;
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	char sta[10];
	int flag = 0;      //临时判断变量 
	int num = 1;     //临时记录要购买的班次号
	double realprice;     //记录应付票价
	int n = 0;     //记录乘客身份编号
	int l;
	int log1[SIZE3];
	int log2 = 0;
	int y;
	char choice_1[10];
	//int record[SIZE1 + count];
	int* record = new int[SIZE1 + count];
	int q;
	int p;      //判断是否有该终点站 
	for (i = 0; i < SIZE3; i++) {
		log1[i] = 0;
	}
	if ((fp = fopen("memory.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE3 + more; i++) {
		fread(&mem2[i], sizeof(struct Mem2), 1, fp);
	}
	fclose(fp);     //读取乘客已购票信息 
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	printf("您已购车票的信息如下：\n");
	for (i = 0; i < SIZE3 + more; i++) {
		if (strcmp(name1, mem2[i].name2) == 0) {
			n = i;
			//printf("%d\n",i);
		}
	}
	xy = 0;
	printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
	for (i = 0; i < SIZE3; i++) {
		for (j = 0; j < SIZE1 + count; j++) {
			if (line_1[j].num1 == mem2[n].num[i]) {
				log1[i] = line_1[j].num1;
				//printf("%d\n\n\n\n",line_1[j].num1);
				xy++;
			}
		}
	}
	for (i = 0; i < SIZE3; i++) {
		int m = 0;
		for (j = 0; j < SIZE3; j++) {
			if (log1[i] == log1[j]) {
				//printf("%d\n",log1[i]);
				log2++;     //计算购买票的数量 
			}
		}
		for (k = 0; k < SIZE1 + count; k++) {
			if (line_1[k].num1 == log1[i]) {     //比对是否有该列车信息 
				//printf("k的值是%d\n",k);
				for (l = 0; l < i; l++) {
					if (log1[l] == log1[i]) {     //比对是否之前已打印过该车票信息 
						//printf("%d\n\n\n\n",log1[i]);
						m = 1;
					}
				}
				if (m == 0) {     //打印未输出过的已购车票信息 
					printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d", line_1[k].num1, line_1[k].time, \
						line_1[k].sta1, line_1[k].sta2, line_1[k].num2, line_1[k].max, line_1[k].real, line_1[k].price);
					printf("\t总计%d张", log2);
					printf("\n");
				}
			}
		}
		log2 = 0;
	}
	while (num != 0) {
		if (xy >= 5) {
			printf("每位乘客最多购5张车票！！！无法再继续购票！！！\n\n");
			choice();
		}
		p = 0;
		//printf("\n\n\n请输入您要到达的目的地：");
		//scanf("%s", sta);
		InputBox(sta, 128, "请输入您要到达的目的地：");

		for (i = 0; i < SIZE1 + count; i++) {
			if (strcmp(sta, line_1[i].sta2) == 0) {
				p = 1;
			}
		}
		if (p == 0) {
			printf("没有可购票的列车！！！请耐心等待！！！\n\n");
			choice();
			system("pause");
		}
		printf("可供选择的班次如下：\n");
		printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
		y = 0;
		for (i = 0; i < SIZE1 + count; i++) {
			if ((line_1[i].real < line_1[i].max) && (strcmp(sta, line_1[i].sta2) == 0) && (lt->tm_hour < line_1[i].time)) {
				printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
					line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
				printf("\n");
				flag = 1;
				record[y] = line_1[i].num1;     //记录可购列车车次号 
				y++;
			}
		}
		if (flag == 1) {
			//printf("请输入您要购买的班次：");
			//scanf("%d", &num);
			InputBox(id, 128, "请输入您要购买的班次:");
			num = atoi(id);

			q = 0;
			for (i = 0; i < y; i++) {
				if (num == record[i]) {
					q = 1;
				}
			}     //检验是否输入了可购车次以外的车次号 
			if (q == 1) {
				mem2[n].num[xy] = num;
				xy++;
				//printf("%d\n",xy);			
				for (i = 0; i < SIZE1 + count; i++) {
					if (num == line_1[i].num1) {
						//printf("请选择您要购买票的种类：全票 1；\t儿童票 2；\t学生票 3； ");
						//scanf("%d", &num);

						InputBox(choice_1, 128, "请选择您要购买票的种类：全票 1；儿童票 2；学生票 3；");
						num = atoi(choice_1);

						switch (num)     //按不同种类的票计算价格 
						{
						case 1:
							realprice = line_1[i].price * 1;
							break;
						case 2:
							realprice = line_1[i].price * 0.5;
							break;
						case 3:
							realprice = line_1[i].price * 0.8;
							break;
						}
						line_1[i].real += 1;     //多售出一票 
						printf("购票成功！\n\n\n您的车票信息为：\n");
						printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
						printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%.2f", line_1[i].num1, line_1[i].time, \
							line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, realprice);
						printf("\n");
						flag = 0;
						if ((fp = fopen("memory.txt", "wb")) == NULL) {
							printf("cannot open file\n");
							exit(0);
						}
						for (i = 0; i < SIZE3 + more; i++) {
							if (fwrite(&mem2[i], sizeof(struct Mem2), 1, fp) != 1)
								printf("file write error\n");
						}
						fclose(fp);     //重新导入文件
						if ((fp = fopen("data.txt", "wb")) == NULL) {
							printf("cannot open file\n");
							exit(0);
						}
						for (i = 0; i < SIZE1 + count; i++) {
							if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
								printf("file write error\n");
						}
						fclose(fp);     //重新导入文件					
						break;
					}
				}
			}
			else {
				printf("\n\n输入了错误的班次号！！！\n");
			}
		}
		else {
			printf("\n\n\n当前没有可购买的车票！请耐心等待！！\n");
			break;
		}
		//printf("是否继续购票？是 1；\t否 0；\t");
		//scanf("%d", &num);

		InputBox(choice_1, 128, "是否继续购票？是 1；否 0；");
		num = atoi(choice_1);

		system("cls");     //清屏 
	}
	fclose(fp);
	choice();

}


void deny()     //退票函数 
{
	FILE* fp;
	char choice_2[10];
	char id[10];
	int i, j, m = 0, y = 1;
	int x = 0;     //记录退票的数量 
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	int num = 1;     //临时记录要购买的班次号 
	double money = 0.0;     //退票赔偿费
	int n = 0;     //临时记录乘客序号 
	int k;
	int l;     //临时记录退票的班次号 
	int log2 = 0;
	int log1[SIZE3];
	int p = 0;
	int flag = 0;
	for (i = 0; i < SIZE3; i++) {
		log1[i] = 0;
	}
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	fclose(fp);
	if ((fp = fopen("memory.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE3 + more; i++) {
		fread(&mem2[i], sizeof(struct Mem2), 1, fp);
	}
	fclose(fp);     //读取乘客已购票信息
	printf("您已购车票的信息如下：\n");
	for (i = 0; i < SIZE3 + more; i++) {
		if (strcmp(name1, mem2[i].name2) == 0) {
			n = i;
		}
	}
	printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
	for (i = 0; i < SIZE3; i++) {
		for (j = 0; j < SIZE1 + count; j++) {
			if (line_1[j].num1 == mem2[n].num[i]) {
				log1[i] = line_1[j].num1;
			}
		}
	}
	for (i = 0; i < SIZE3; i++) {
		for (j = 0; j < SIZE3; j++) {
			if (log1[i] == log1[j]) {
				log2++;
			}
		}
		for (k = 0; k < SIZE1 + count; k++) {
			int z = 0;
			if (line_1[k].num1 == log1[i]) {
				//printf("k的值是%d\n",k);
				for (l = 0; l < i; l++) {
					if (log1[l] == log1[i]) {
						z = 1;
					}
				}
				if (z == 0) {
					printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d", line_1[k].num1, line_1[k].time, \
						line_1[k].sta1, line_1[k].sta2, line_1[k].num2, line_1[k].max, line_1[k].real, line_1[k].price);
					printf("\t总计%d张", log2);
					printf("\n");
				}
			}
		}
		log2 = 0;
	}
	while (y != 0) {
		l = 0;
		//printf("请输入您要退票的班次号：");
		//scanf("%d", &num);
		InputBox(id, 128, "请输入您要购买的班次:");
		num = atoi(id);

		flag = 0;
		for (i = 0; i < SIZE3; i++) {
			if (num == mem2[n].num[i]) {
				flag = 1;
			}
		}     //判断输入的车次号是否存在 
		if (flag == 1) {
			for (i = 0; i < SIZE1 + count; i++) {
				x = 0;
				if ((lt->tm_hour < line_1[i].time) && (num == line_1[i].num1)) {
					x = 1;
					printf("您要退票的列车信息如下：\n");
					printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
					printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
						line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
					//printf("\n是否确定退票？是 1；\t否 0；");
					//scanf("%d", &m);
					InputBox(choice_2, 128, "是否确定退票？是 1；否 0：");
					m = atoi(choice_2);

					if (m == 1) {
						l = num;
						if (((line_1[i].time) - (lt->tm_hour)) >= 2) {
							money = 0;
						}
						else if ((line_1[i].time - lt->tm_hour) >= 1) {
							money = line_1[i].price * 0.05;
						}
						else {
							money = line_1[i].price * 0.1;
						}
						line_1[i].real -= 1;
						printf("退票成功！！\n需补交退票赔偿费：%.2f元\n", money);
						break;
					}
					else {
						choice();
					}
				}
			}
		}
		else {
			printf("\n\n输入了错误的班次号！！！！\n");
		}
		p = 0;
		for (i = 0; i < SIZE3 + more; i++) {
			if (l == mem2[n].num[i]) {
				mem2[n].num[i] = 0;
				p = 1;
			}
			if (p == 1) {
				break;
			}
		}     //保证一次只退一张票		
		if (x == 0) {
			printf("无法退票！！\n");
			j = 0;
		}
		Mem2 temp;
		for (i = 0; i < SIZE3; i++) {
			for (j = 0; j < SIZE3 - i - 1; j++) {
				if (mem2[n].num[j] < mem2[n].num[j + 1]) {
					temp.num[0] = mem2[n].num[j];
					mem2[n].num[j] = mem2[n].num[j + 1];
					mem2[n].num[j + 1] = temp.num[0];
				}
			}
		}     //剩余已购车票降次排序 
		if ((fp = fopen("memory.txt", "wb")) == NULL) {
			printf("cannot open file\n");
			exit(0);
		}
		for (i = 0; i < SIZE3 + more; i++) {
			if (fwrite(&mem2[i], sizeof(struct Mem2), 1, fp) != 1)
				printf("file write error\n");
		}
		fclose(fp);     //重新导入文件
		if ((fp = fopen("data.txt", "wb")) == NULL) {
			printf("cannot open file\n");
			exit(0);
		}
		for (i = 0; i < SIZE1 + count; i++) {
			if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
				printf("file write error\n");
		}
		//printf("是否继续退票？是 1；\t否 0；");
		//scanf("%d", &y);

		InputBox(choice_2, 128, "是否继续退票？是 1；否 0；");
		y = atoi(choice_2);

		system("cls");
	}
	fclose(fp);     //重新导入文件				 	
	Start(1);
}



void enrollC() {
	char passwd[50];
	char* pEnd;
	FILE* fp;
	Mem2 temp;      //临时结构体变量，用于存储添加用户的信息 
	int i = 1;
	if ((fp = fopen("client.txt", "ab")) == NULL) {
		printf("cannot open file\n");
		return;
	}     //打开原有文件用于追加列车信息
	//printf("请输入您的账户名：");
	//scanf("%s", temp.name2);
	InputBox(temp.name2, 128, "请输入您的账号");

	//printf("请输入您的密码：");
	//scanf("%ld", &temp.num2);
	InputBox(passwd, 128, "请输入您的密码");
	temp.num2 = strtol(passwd, &pEnd, 10);


	for (i = 0; i < SIZE3; i++) {
		temp.num[i] = 0;
	}
	strcpy(name1, temp.name2);     //记录进入系统的乘客账号名 
	more++;
	if (more > SIZE1 - SIZE3) {
		printf("\n\n\n已超过额定数量，无法继续添加！\n");
	}
	if (fwrite(&temp, sizeof(struct Mem2), 1, fp) != 1) {
		printf("file write error\n");
	}      //将添加的信息追加到原来的文件中 
	fclose(fp);
	printf("\n\n\n注册成功！！！\n");
	user_init();     //可进入乘客菜单	
}

void loginA() {
	char* pEnd;
	char choice_3[10];
	FILE* fp;
	int i, flag = 0, j = 1, n = 0;    //flag用于判断 ,j用于记录决定，n用于记录身份编号 
	char name[10];
	long int num;     //临时存储输入的密码 
	char passwd[50];
	int m = 0;
	if ((fp = fopen("admin.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE3; i++) {
		fread(&mem1[i], sizeof(struct Mem1), 1, fp);
	}
	InputBox(name, 128, "请输入您的账号");
	//printf("请输入您的账号：");
	//scanf("%s", name);

	for (i = 0; i < SIZE3; i++) {
		if (strcmp(name, mem1[i].name1) == 0) {
			flag = 1;
			n = i;
		}
	}
	if (flag == 1) {
		for (i = 1; i <= 3; i++) {
			InputBox(passwd, 128, "请输入您的密码：");
			num = strtol(passwd, &pEnd, 10);
			//printf("\n\n请输入您的密码：");
			//scanf("%ld", &num);

			if (num == mem1[n].num1) {
				m = 1;
				system("cls");     //清屏 
				Start(1);
				break;
			}
			if (m == 0) {
				printf("密码错误！！\n\n还有%d次输入机会！！\n\n", 3 - i);
				if (i == 3) {
					printf("三次输入错误密码，无法进入系统！！！\n\n");
					system("pause");
					user_init();
					break;
				}
				//printf("是否重新输入？\t是 1；\t否 0；");
				//scanf("%d", &j);
				InputBox(choice_3, 128, "是否重新输入？是 1；否 0；");
				j = atoi(choice_3);

				system("cls");     //清屏 
				if (j == 0) {
					user_init();
					break;
				}
			}
		}
	}
	if (flag == 0) {
		printf("\n\n\n您不是该系统的管理员！！\n\n\n");
		system("pause");
		user_init();

	}
	fclose(fp);      //关闭文件 
}


int loginC() {
	char* pEnd;
	FILE* fp;
	char passwd[50];
	char choice_4[10];
	int m = 0;
	int i, flag = 0, j = 1, n = 0;    //flag用于判断 ,j用于记录决定，n用于记录身份编号 
	int dec = 0;     //用于记录选择 
	long int num;     //临时存储输入的密码 
	//int m=0;     //用于记录输入的密码是否正确 
	if ((fp = fopen("client.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}     //打开乘客信息文件
	for (i = 0; i < SIZE3; i++) {
		fread(&mem2[i], sizeof(struct Mem2), 1, fp);
	}
	//printf("请输入您的账号：");
	//scanf("%s", name1);
	InputBox(name1, 128, "请输入您的账号");

	for (i = 0; i < SIZE3; i++) {
		if (strcmp(name1, mem2[i].name2) == 0) {
			flag = 1;
			n = i;
		}

	}
	if (flag == 1) {
		for (i = 1; i <= 3; i++) {
			//printf("\n\n请输入您的密码：");
			//scanf("%ld", &num);
			InputBox(passwd, 128, "请输入您的密码：");
			num = strtol(passwd, &pEnd, 10);

			if (num == mem2[n].num2) {
				flag = 2;
				m = 1;
				system("cls");
				printf("用户登录成功！！\n");
				system("pause");
				Start(2);
				system("cls");     //清屏 
			}
			if (flag != 2) {
				printf("密码错误！！\n\n还有%d次输入机会！！\n\n", 3 - i);
				if (i == 3) {
					break;
				}
				//printf("是否重新输入？\t是 1；\t否 0；");
				//scanf("%d", &j);

				InputBox(choice_4, 128, "是否重新输入？是 1；否 0；");
				j = atoi(choice_4);

				system("cls");     //清屏 
				if (j == 0) {
					user_init();
					return 0;
				}
			}
		}
		if (flag != 2 && j != 0) {
			printf("三次输入错误密码，无法进入系统！！！\n\n");
			user_init();
			return 0;
		}
	}
	if (m == 1) {
		return 1;
	}
	if (flag == 0) {
		printf("\n\n\n您不是已注册的乘客！！\n");
		printf("\n\n\n是否选择注册？是 1；\t否 0；\n");
		//printf("我的选择是：");
		//scanf("%d", &dec);
		InputBox(choice_4, 128, "我的选择是？是 1；否 0；");
		dec = atoi(choice_4);

		system("cls");
		if (dec == 0) {
			system("cls");     //清屏 
			user_init();
			return 0;
		}
		else {
			enrollC();     //调用用户注册函数 
			user_init();
			return 0;

		}
	}
	fclose(fp);      //关闭文件 
}


int saveflag = 0;


int main() {
	menu_init();
}




void look1_c()     //发车时间函数
{
	FILE* fp;
	int i, j;
	Line temp;     //定义结构体临时变量，用于记录 
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	for (i = 0; i < SIZE1 + count - 1; i++) {
		for (j = 0; j < SIZE1 + count - i - 1; j++) {
			if (line_1[j].time > line_1[j + 1].time) {
				temp = line_1[j];
				line_1[j] = line_1[j + 1];
				line_1[j + 1] = temp;
			}
		}
	}
	fclose(fp);
	if ((fp = fopen("data.txt", "wb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
			printf("file write error\n");
	}
	fclose(fp);     //重新导入文件 
	printf("您所需的信息为：\n");
	printtime();
}


void look2_c()     //发车时间函数 
{
	FILE* fp;
	int i, j;
	Line temp;     //定义结构体临时变量，用于记录 
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	for (i = 0; i < SIZE1 + count - 1; i++) {
		for (j = 0; j < SIZE1 + count - i - 1; j++) {
			if (line_1[j].num1 > line_1[j + 1].num1) {
				temp = line_1[j];
				line_1[j] = line_1[j + 1];
				line_1[j + 1] = temp;
			}
		}
	}
	fclose(fp);
	if ((fp = fopen("data.txt", "wb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
			printf("file write error\n");
	}
	fclose(fp);     //重新导入文件 
	printf("您所需的信息为：\n");
	printID();
}


void look3_c()     //目的地函数 
{
	FILE* fp;
	int i, j;
	Line temp;     //定义结构体临时变量，用于记录
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	for (i = 0; i < SIZE1 + count - 1; i++) {
		for (j = 0; j < SIZE1 + count - i - 1; j++) {
			if (line_1[j].real > line_1[j + 1].real) {
				temp = line_1[j];
				line_1[j] = line_1[j + 1];
				line_1[j + 1] = temp;
			}
		}
	}
	fclose(fp);
	if ((fp = fopen("data.txt", "wb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
			printf("file write error\n");
	}
	fclose(fp);     //重新导入文件 
	printf("您所需的信息为：\n");
	printDestn();
}


void seek1_c()      //班次号查询函数 
{
	char id[10];
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	FILE* fp;
	int i, j = 1, num = 0;
	int m, n;
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	fclose(fp);
	while (1) {
		if (j != 0) {
			m = 0;
			//printf("请输入您要查询的班次号：");
			//scanf_s("%d", &num);
			InputBox(id, 128, "请输入您的账号");
			num = atoi(id);
			for (i = 0; i < SIZE1 + count; i++) {
				if (num == line_1[i].num1) {
					m = 1;
					n = i;
				}
			}
			if (m == 1) {
				printf("该班次的信息为：\n");
				printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
				printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d", line_1[n].num1, line_1[n].time, \
					line_1[n].sta1, line_1[n].sta2, line_1[n].num2, line_1[n].max, line_1[n].real, line_1[n].price);
				if (lt->tm_hour > line_1[i].time) {
					printf("    此车已开走！");
				}
				printf("\n");
			}
			else {
				printf("没有该班次列车信息！！！！\n");
				break;
			}
		}
		else {
			break;
		}
		printf("是否继续查询？是 1；\t否 0；");
		scanf_s("%d", &j);
	}
	if (j == 0) {
		system("cls");     //清屏 
	}
}


void seek2_c()     //终点站查询函数 
{
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	//Line temp;
	FILE* fp;
	int i, j = 1;
	char s[10];
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	while (1) {
		int k = 0;
		if (j != 0) {
			//printf("请输入您要查询的终点站：");
			//scanf("%s", s);
			InputBox(s, 128, "请输入您要查询的终点站:");

			printf("该班次的信息为：\n");
			printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
			for (i = 0; i < SIZE1 + count; i++) {
				if (strcmp(s, line_1[i].sta2) == 0) {
					printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
						line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
					if (lt->tm_hour > line_1[i].time) {
						printf("    此车已开走！");
					}
					printf("\n");
					k = 1;
				}
			}
		}
		else {
			break;
		}
		if (k == 0) {
			printf("\n\n\n没有该终点站的相关列车信息！！！\n");
		}
		printf("是否继续查询？是 1；否 0；");
		scanf_s("%d", &j);
		system("cls");
	}
	if (j == 0) {
		system("cls");     //清屏 
	}
	fclose(fp);
}


void seek3_c()     //可购票查询函数 
{
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	FILE* fp;
	int i, flag = 0;     //flag作为判断变量 	
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	printf("当前可售票的车次为：\n");
	printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
	for (i = 0; i < SIZE1 + count; i++) {
		if ((lt->tm_hour < line_1[i].time) && (line_1[i].real < line_1[i].max)) {
			printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
				line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
			printf("\n");
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("\n\n\n当前没有可购票的车次！请耐心等待！！\n");
	}
	fclose(fp);
}


void buy_c()      //购票系统函数 
{
	char choice_1[10];
	FILE* fp;
	int i, j, k;
	char id[10];
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	char sta[10];
	int flag = 0;      //临时判断变量 
	int num = 1;     //临时记录要购买的班次号
	double realprice;     //记录应付票价
	int n = 0;     //记录乘客身份编号
	int l;
	int log1[SIZE3];
	int log2 = 0;
	int y;
	//int record[SIZE1 + count];
	int* record = new int[SIZE1 + count];
	int q;
	int p;      //判断是否有该终点站 
	for (i = 0; i < SIZE3; i++) {
		log1[i] = 0;
	}
	if ((fp = fopen("memory.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		system("pause");
		Start(2);
	}
	for (i = 0; i < SIZE3 + more; i++) {
		fread(&mem2[i], sizeof(struct Mem2), 1, fp);
	}
	fclose(fp);     //读取乘客已购票信息 
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		system("pause");
		Start(2);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	printf("您已购车票的信息如下：\n");
	for (i = 0; i < SIZE3 + more; i++) {
		if (strcmp(name1, mem2[i].name2) == 0) {
			n = i;
			//printf("%d\n",i);
		}
	}
	xy = 0;
	printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
	for (i = 0; i < SIZE3; i++) {
		for (j = 0; j < SIZE1 + count; j++) {
			if (line_1[j].num1 == mem2[n].num[i]) {
				log1[i] = line_1[j].num1;
				//printf("%d\n\n\n\n",line_1[j].num1);
				xy++;
			}
		}
	}
	for (i = 0; i < SIZE3; i++) {
		int m = 0;
		for (j = 0; j < SIZE3; j++) {
			if (log1[i] == log1[j]) {
				//printf("%d\n",log1[i]);
				log2++;     //计算购买票的数量 
			}
		}
		for (k = 0; k < SIZE1 + count; k++) {
			if (line_1[k].num1 == log1[i]) {     //比对是否有该列车信息 
				//printf("k的值是%d\n",k);
				for (l = 0; l < i; l++) {
					if (log1[l] == log1[i]) {     //比对是否之前已打印过该车票信息 
						//printf("%d\n\n\n\n",log1[i]);
						m = 1;
					}
				}
				if (m == 0) {     //打印未输出过的已购车票信息 
					printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d", line_1[k].num1, line_1[k].time, \
						line_1[k].sta1, line_1[k].sta2, line_1[k].num2, line_1[k].max, line_1[k].real, line_1[k].price);
					printf("\t总计%d张", log2);
					printf("\n");
				}
			}
		}
		log2 = 0;
	}
	while (num != 0) {
		if (xy >= 5) {
			printf("每位乘客最多购5张车票！！！无法再继续购票！！！\n\n");
			system("pause");
			choice_c();
		}
		p = 0;
		//printf("\n\n\n请输入您要到达的目的地：");
		//scanf("%s", sta);
		InputBox(sta, 128, "请输入您要到达的目的地:");

		for (i = 0; i < SIZE1 + count; i++) {
			if (strcmp(sta, line_1[i].sta2) == 0) {
				p = 1;
			}
		}
		if (p == 0) {
			printf("没有可购票的列车！！！请耐心等待！！！\n\n");
			system("pause");
			choice_c();
		}
		printf("可供选择的班次如下：\n");
		printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
		y = 0;
		for (i = 0; i < SIZE1 + count; i++) {
			if ((line_1[i].real < line_1[i].max) && (strcmp(sta, line_1[i].sta2) == 0) && (lt->tm_hour < line_1[i].time)) {
				printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
					line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
				printf("\n");
				flag = 1;
				record[y] = line_1[i].num1;     //记录可购列车车次号 
				y++;
			}
		}
		if (flag == 1) {
			//printf("请输入您要购买的班次：");
			//scanf("%d", &num);
			InputBox(id, 128, "请输入您要购买的班次：");
			num = atoi(id);

			q = 0;
			for (i = 0; i < y; i++) {
				if (num == record[i]) {
					q = 1;
				}
			}     //检验是否输入了可购车次以外的车次号 
			if (q == 1) {
				mem2[n].num[xy] = num;
				xy++;
				//printf("%d\n",xy);			
				for (i = 0; i < SIZE1 + count; i++) {
					if (num == line_1[i].num1) {
						//printf("请选择您要购买票的种类：全票 1；\t儿童票 2；\t学生票 3； ");
						//scanf("%d", &num);
						InputBox(choice_1, 128, "请选择您要购买票的种类：全票 1；\t儿童票 2；\t学生票 3；");
						num = atoi(choice_1);


						switch (num)     //按不同种类的票计算价格 
						{
						case 1:
							realprice = line_1[i].price * 1;
							break;
						case 2:
							realprice = line_1[i].price * 0.5;
							break;
						case 3:
							realprice = line_1[i].price * 0.8;
							break;
						}
						line_1[i].real += 1;     //多售出一票 
						printf("购票成功！\n\n\n您的车票信息为：\n");
						printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
						printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%.2f", line_1[i].num1, line_1[i].time, \
							line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, realprice);
						printf("\n");
						flag = 0;
						if ((fp = fopen("memory.txt", "wb")) == NULL) {
							printf("cannot open file\n");
							system("pause");
							Start(2);
						}
						for (i = 0; i < SIZE3 + more; i++) {
							if (fwrite(&mem2[i], sizeof(struct Mem2), 1, fp) != 1)
								printf("file write error\n");
						}
						fclose(fp);     //重新导入文件
						if ((fp = fopen("data.txt", "wb")) == NULL) {
							printf("cannot open file\n");
							system("pause");
							Start(2);
						}
						for (i = 0; i < SIZE1 + count; i++) {
							if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
								printf("file write error\n");
						}
						fclose(fp);     //重新导入文件					
						break;
					}
				}
			}
			else {
				printf("\n\n输入了错误的班次号！！！\n");
			}
		}
		else {
			printf("\n\n\n当前没有可购买的车票！请耐心等待！！\n");
			break;
		}
		//printf("是否继续购票？是 1；\t否 0；\t");
		//scanf("%d", &num);
		InputBox(choice_1, 128, "是否继续购票？是 1；否 0；");
		num = atoi(choice_1);

		system("cls");     //清屏 
	}
	fclose(fp);
	choice_c();

}


void deny_c()     //退票函数 
{
	char id[10];
	FILE* fp;
	char choice_2[10];
	int i, j, m = 0, y = 1;
	int x = 0;     //记录退票的数量 
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	int num = 1;     //临时记录要购买的班次号 
	double money = 0.0;     //退票赔偿费
	int n = 0;     //临时记录乘客序号 
	int k;
	int l;     //临时记录退票的班次号 
	int log2 = 0;
	int log1[SIZE3];
	int p = 0;
	int flag = 0;
	for (i = 0; i < SIZE3; i++) {
		log1[i] = 0;
	}
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	fclose(fp);
	if ((fp = fopen("memory.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE3 + more; i++) {
		fread(&mem2[i], sizeof(struct Mem2), 1, fp);
	}
	fclose(fp);     //读取乘客已购票信息
	printf("您已购车票的信息如下：\n");
	for (i = 0; i < SIZE3 + more; i++) {
		if (strcmp(name1, mem2[i].name2) == 0) {
			n = i;
		}
	}
	printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
	for (i = 0; i < SIZE3; i++) {
		for (j = 0; j < SIZE1 + count; j++) {
			if (line_1[j].num1 == mem2[n].num[i]) {
				log1[i] = line_1[j].num1;
			}
		}
	}
	for (i = 0; i < SIZE3; i++) {
		for (j = 0; j < SIZE3; j++) {
			if (log1[i] == log1[j]) {
				log2++;
			}
		}
		for (k = 0; k < SIZE1 + count; k++) {
			int z = 0;
			if (line_1[k].num1 == log1[i]) {
				//printf("k的值是%d\n",k);
				for (l = 0; l < i; l++) {
					if (log1[l] == log1[i]) {
						z = 1;
					}
				}
				if (z == 0) {
					printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d", line_1[k].num1, line_1[k].time, \
						line_1[k].sta1, line_1[k].sta2, line_1[k].num2, line_1[k].max, line_1[k].real, line_1[k].price);
					printf("\t总计%d张", log2);
					printf("\n");
				}
			}
		}
		log2 = 0;
	}
	while (y != 0) {
		l = 0;
		//printf("请输入您要退票的班次号：");
		//scanf("%d", &num);

		InputBox(id, 128, "请输入您要退票的班次号");
		num = atoi(id);

		flag = 0;
		for (i = 0; i < SIZE3; i++) {
			if (num == mem2[n].num[i]) {
				flag = 1;
			}
		}     //判断输入的车次号是否存在 
		if (flag == 1) {
			for (i = 0; i < SIZE1 + count; i++) {
				x = 0;
				if ((lt->tm_hour < line_1[i].time) && (num == line_1[i].num1)) {
					x = 1;
					printf("您要退票的列车信息如下：\n");
					printf("车次  发车时间  始发站  终点站  行车时间  额定数量  已订票人数  票价\n");
					printf("%d\t%d点\t%s\t%s\t%.1f时\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
						line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
					//printf("\n是否确定退票？是 1；\t否 0；");
					//scanf("%d", &m);
					InputBox(choice_2, 128, "是否确定退票？是 1；否 0；：");
					m = atoi(choice_2);

					if (m == 1) {
						l = num;
						if (((line_1[i].time) - (lt->tm_hour)) >= 2) {
							money = 0;
						}
						else if ((line_1[i].time - lt->tm_hour) >= 1) {
							money = line_1[i].price * 0.05;
						}
						else {
							money = line_1[i].price * 0.1;
						}
						line_1[i].real -= 1;
						printf("退票成功！！\n需补交退票赔偿费：%.2f元\n", money);
						break;
					}
					else {
						choice();
					}
				}
			}
		}
		else {
			printf("\n\n输入了错误的班次号！！！！\n");
		}
		p = 0;
		for (i = 0; i < SIZE3 + more; i++) {
			if (l == mem2[n].num[i]) {
				mem2[n].num[i] = 0;
				p = 1;
			}
			if (p == 1) {
				break;
			}
		}     //保证一次只退一张票		
		if (x == 0) {
			printf("无法退票！！\n");
			j = 0;
		}
		Mem2 temp;
		for (i = 0; i < SIZE3; i++) {
			for (j = 0; j < SIZE3 - i - 1; j++) {
				if (mem2[n].num[j] < mem2[n].num[j + 1]) {
					temp.num[0] = mem2[n].num[j];
					mem2[n].num[j] = mem2[n].num[j + 1];
					mem2[n].num[j + 1] = temp.num[0];
				}
			}
		}     //剩余已购车票降次排序 
		if ((fp = fopen("memory.txt", "wb")) == NULL) {
			printf("cannot open file\n");
			system("pause");
			Start(2);
		}
		for (i = 0; i < SIZE3 + more; i++) {
			if (fwrite(&mem2[i], sizeof(struct Mem2), 1, fp) != 1)
				printf("file write error\n");
		}
		fclose(fp);     //重新导入文件
		if ((fp = fopen("data.txt", "wb")) == NULL) {
			printf("cannot open file\n");
			system("pause");
			Start(2);
		}
		for (i = 0; i < SIZE1 + count; i++) {
			if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
				printf("file write error\n");
		}
		//printf("是否继续退票？是 1；\t否 0；");
		//scanf("%d", &y);
		InputBox(choice_2, 128, "是否继续退票？是 1；否 0；");
		m = atoi(choice_2);

		system("cls");
	}
	fclose(fp);     //重新导入文件				 	
	Start(2);
}
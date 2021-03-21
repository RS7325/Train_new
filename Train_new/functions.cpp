#include "info.h"

#define HEADER1 "|Number    |Name      |Author    |Publish   |Price | F|Reader    |Total|"
#define FORMAT1 "|%-10s|%-10s|%-10s|%-10s|%-6.2f|%2d|%-10s|%5d|"
#define DATA1 lll->data.num,lll->data.name,lll->data.author,lll->data.publish,lll->data.price,lll->data.borrow_flag,lll->data.reader,lll->data.total_num
#define HEADER2 "|Number      |Name      |Sex |Age |Tele           |Total|"
#define FORMAT2 "|%-12s|%-10s|%-4s|%-4d|%-15s|%-5d|"
#define DATA2 lll->data.num,lll->data.name,lll->data.sex,lll->data.age,lll->data.tele,lll->data.total_num

int count = 0;     //����ȫ�ֱ��������ڼ�¼���ӵ��г���Ϣ����
int more = 0;     //����ȫ�ֱ��������ڼ�¼ע��˿͵����� 
char name1[10];     //����ȫ�ֱ�������¼�˿��˻���
int xy;     //����ȫ�ֱ�������¼�˿͹�Ʊ���� 
int tt = 0;


struct Mem1     //����Ա��Ϣ�ṹ��
{
	char name1[10];     //����Ա���� 
	long int num1;     //����Ա���� 
	int num[SIZE3];     //�˿͹���Ʊ�İ�κ� 

}mem1[SIZE3];


struct Mem2     //�˿���Ϣ�ṹ�� 
{
	char name2[10];     //�˿��˺��� 
	long int num2;     //�˿����� 
	int num[SIZE3];     //�˿͹���Ʊ�İ�κ� 
}mem2[SIZE1];


struct Line
{
	int num1;     //���
	int time;     //����ʱ��
	char sta1[10];     //���վ
	char sta2[10];     //�յ�վ
	double num2;     //�г�ʱ��
	int max;     //�����
	int real;     //�Ѷ�Ʊ����
	int price;     //Ʊ�� 
}line_1[SIZE2];


void change()      //�޸ĺ��� 
{
	FILE* fp;
	int i, n = 0;      //n���ڼ�¼Ҫ�޸ĵİ�κ�
	int flag, m;
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		system("pause");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	printf("��������Ҫ�޸��г��İ�κţ�");
	scanf_s("%d", &n);
	flag = 0;
	for (i = 0; i < SIZE1 + count; i++) {
		if (n == line_1[i].num1) {
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("û�иð���г������޷��޸ģ���\n\n");
		printf("��ѡ����һ��������\n1�������޸�\n2�����ز˵�\n0���˳�\n");
		printf("�ҵ�ѡ���ǣ�");
		scanf_s("%d", &m);
		system("cls");     //���� 
		switch (m)
		{
		case 1:
			change();
			system("cls");
			printf("�޸ĺ������Ϣ�����£�\n");
			print();
			//Start();
			break;
		case 2:
			Start(1);
			break;
		case 0:
			printf("�ɹ��˳�������\n\n\n");
			exit(0);
			break;
		default:
			printf("����������\n\n\n");
			exit(0);
		}
	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (line_1[i].num1 == n) {
			printf("\n\n\n�����������г������Ϣ��\n");
			printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
			scanf("%d%d%s%s%lf%d%d%d", &line_1[i].num1, &line_1[i].time, line_1[i].sta1, \
				line_1[i].sta2, &line_1[i].num2, &line_1[i].max, &line_1[i].real, &line_1[i].price);

		}
	}     //���޸�ԭ������Ϣ 
	fclose(fp);
	if ((fp = fopen("data.txt", "wb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
			printf("file write error\n");
	}
	fclose(fp);     //���µ����ļ� 	
	printf("�޸ĳɹ���");
}


void add()     //���Ӻ��� 
{
	FILE* fp;
	int i = 1;
	int num;     //���ڼ�¼��ӵ��г���κ� 
	int flag = 0;
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		system("pause");
	}     //��ԭ���ļ�����׷���г���Ϣ
	for (i = 0; i < 1; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	printf("��������Ҫ��ӵ��г���κţ�");
	scanf_s("%d", &num);
	for (i = 0; i < SIZE1 + count; i++) {
		if (num == line_1[i].num1) {
			flag = 1;
		}
	}
	if (flag == 1) {
		printf("���иð���г������޷���ӣ���\n\n");
		system("pause");
		system("cls");     //���� 
	}
	while (count <= SIZE2 - SIZE1) {

		printf("\n\n\n������Ҫ����г��������Ϣ��\n");
		printf("����,����ʱ��,ʼ��վ,�յ�վ,�г�ʱ��,�����,�Ѷ�Ʊ����,Ʊ��\n");
		scanf("%d%d%s%s%lf%d%d%d", &line_1[SIZE1 + count].num1, &line_1[SIZE1 + count].time, line_1[SIZE1 + count].sta1, \
			line_1[SIZE1 + count].sta2, &line_1[SIZE1 + count].num2, &line_1[SIZE1 + count].max, &line_1[SIZE1 + count].real, &line_1[SIZE1 + count].price);
		count++;
	}
	if (count > SIZE2 - SIZE1) {
		printf("�ѳ�����������޷�������ӣ�\n");
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
	fclose(fp);     //���µ����ļ� 	
	Start(1);
}


void del()     //ɾ������ 
{
	char id[10];
	char Choice[10];
	FILE* fp;
	Line* temp = new Line[SIZE1 + count];
	int i = 1, n = 0, num = 0, max = SIZE1 + count;
	int j = 1, k;
	int flag;
	int m;     //���ڼ�¼����Աѡ��  
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
	//printf("������Ҫɾ���İ�κţ�");
	//scanf("%d", &num);
	InputBox(id, 128, "������Ҫɾ���İ�κţ�");
	num = atoi(id);
	for (i = 0; i < SIZE1 + count; i++) {
		if (num == line_1[i].num1) {
			printf("ɾ����ɣ�");

			flag = 1;
		}
	}
	if (flag == 0) {
		printf("û�иð���г������޷�ɾ������\n\n");
		printf("��ѡ����һ��������\n1������ɾ��\n2�����ز˵�\n0���˳�\n");
		printf("�ҵ�ѡ���ǣ�");
		InputBox(Choice, 128, "������Ҫɾ���İ�κţ�");
		m = atoi(Choice);
		//scanf("%d", &m);

		system("cls");     //���� 
		switch (m)
		{
		case 1:
			del();
			system("cls");     //���� 
			printf("ɾ���������Ϣ�����£�\n");
			print();
			Start(1);
			break;
		case 2:
			Start(1);
			break;
		case 0:
			printf("�ɹ��˳�������\n\n\n");
			exit(0);
			break;
		default:
			printf("����������\n\n\n");
			exit(0);
		}
	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (line_1[i].num1 != num) {     //�洢ʣ������Ϣ
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
	fclose(fp);     //���µ����ļ�
	SIZE1 + count--;
	if (n == max) {
		printf("��û�����ݿ�����ɾ������\n");
	}
	if ((fp = fopen("data.txt", "wb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (fwrite(&temp[i], sizeof(struct Line), 1, fp) != 1)
			printf("file write error\n");
	}
	fclose(fp);     //���µ����ļ� 	
}


void print()      //����Ա�ɼ�������� 
{
	FILE* fp;
	int i;
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}     //�������ļ� 
	printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
		printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d",line_1[i].num1,line_1[i].time,\
			line_1[i].sta1,line_1[i].sta2,line_1[i].num2,line_1[i].max,line_1[i].real,line_1[i].price);
		printf("\n");
	}
	fclose(fp);     //�ر��ļ� 
}


void save()     //���º��� 
{
	FILE* fp;
	int i;
	if ((fp = fopen("data.txt", "wb")) == NULL) {
		printf("cannot open file\n");
		return;
	}     //��������һ���ļ����ڴ洢ԭʼ���г���Ϣ
	printf("�������г���Ϣ(10��)��\n");
	printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
	for (i = 0; i < SIZE1 + count; i++) {
		scanf("%d%d%s%s%lf%d%d%d", &line_1[i].num1, &line_1[i].time, line_1[i].sta1, \
			line_1[i].sta2, &line_1[i].num2, &line_1[i].max, &line_1[i].real, &line_1[i].price);

	}
	for (i = 0; i < SIZE1 + count; i++) {
		if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
			printf("file write error\n");
	}     //��Ϣ��д���ļ� 
	fclose(fp);     //�ر��ļ� 

}


void printtime()     //�˿Ϳɼ��������
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
	}     //�������ļ�
	printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
	for (i = 0; i < SIZE1 + count; i++) {
		printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d",line_1[i].num1,line_1[i].time,\
			line_1[i].sta1,line_1[i].sta2,line_1[i].num2,line_1[i].max,line_1[i].real,line_1[i].price);
		if (lt->tm_hour >= line_1[i].time) {
			printf("  �˳��ѿ��ߣ�");
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
	}     //�������ļ�
	printf("����  ����ʱ��  Ʊ��\n");
	for (i = 0; i < SIZE1 + count; i++) {
		printf("%d\t%d��\t%d",line_1[i].num1,line_1[i].time,line_1[i].price);
		if (lt->tm_hour >= line_1[i].time) {
			printf("            �˳��ѿ��ߣ�");
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
	}     //�������ļ�
	printf("����  ����ʱ��  �յ�վ  �Ѷ�Ʊ����  Ʊ��\n");
	for (i = 0; i < SIZE1 + count; i++) {
		printf("%d\t%d��\t%s\t%d\t%d",line_1[i].num1,line_1[i].time,line_1[i].sta2,line_1[i].real,line_1[i].price);
		if (lt->tm_hour >= line_1[i].time) {
			printf("  �˳��ѿ��ߣ�");
		}
		printf("\n");
	}
	fclose(fp);
}



void look1()     //����ʱ�亯��
{
	FILE* fp;
	int i, j;
	Line temp;     //����ṹ����ʱ���������ڼ�¼ 
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
	fclose(fp);     //���µ����ļ� 
	printf("���������ϢΪ��\n");
	printtime();
}


void look2()     //����ʱ�亯�� 
{
	FILE* fp;
	int i, j;
	Line temp;     //����ṹ����ʱ���������ڼ�¼ 
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
	fclose(fp);     //���µ����ļ� 
	printf("���������ϢΪ��\n");
	printID();
}


void look3()     //Ŀ�ĵغ��� 
{
	FILE* fp;
	int i, j;
	Line temp;     //����ṹ����ʱ���������ڼ�¼
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
	fclose(fp);     //���µ����ļ� 
	printf("���������ϢΪ��\n");
	printDestn();
}


void seek1()      //��κŲ�ѯ���� 
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
			printf("��������Ҫ��ѯ�İ�κţ�");
			scanf_s("%d", &num);
			for (i = 0; i < SIZE1 + count; i++) {
				if (num == line_1[i].num1) {
					m = 1;
					n = i;
				}
			}
			if (m == 1) {
				printf("�ð�ε���ϢΪ��\n");
				printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
				printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d", line_1[n].num1, line_1[n].time, \
					line_1[n].sta1, line_1[n].sta2, line_1[n].num2, line_1[n].max, line_1[n].real, line_1[n].price);
				if (lt->tm_hour > line_1[i].time) {
					printf("     �˳��ѿ��ߣ�");
				}
				printf("\n");
			}
			else {
				printf("û�иð���г���Ϣ��������\n");
				break;
			}
		}
		else {
			break;
		}
		printf("�Ƿ������ѯ���� 1��\t�� 0��");
		scanf_s("%d", &j);
	}
	if (j == 0) {
		system("cls");     //���� 
	}
}


void seek2()     //�յ�վ��ѯ���� 
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
			//printf("��������Ҫ��ѯ���յ�վ��");
			//scanf("%s", s);

			InputBox(s, 128, "��������Ҫ��ѯ���յ�վ��");

			printf("�ð�ε���ϢΪ��\n");
			printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
			for (i = 0; i < SIZE1 + count; i++) {
				if (strcmp(s, line_1[i].sta2) == 0) {
					printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
						line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
					if (lt->tm_hour > line_1[i].time) {
						printf("    �˳��ѿ��ߣ�");
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
			printf("\n\n\nû�и��յ�վ������г���Ϣ������\n");
		}
		printf("�Ƿ������ѯ���� 1���� 0��");
		scanf_s("%d", &j);
		system("cls");
	}
	if (j == 0) {
		system("cls");     //���� 
	}
	fclose(fp);
}


void seek3()     //�ɹ�Ʊ��ѯ���� 
{
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	FILE* fp;
	int i, flag = 0;     //flag��Ϊ�жϱ��� 	
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	printf("��ǰ����Ʊ�ĳ���Ϊ��\n");
	printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
	for (i = 0; i < SIZE1 + count; i++) {
		if ((lt->tm_hour < line_1[i].time) && (line_1[i].real < line_1[i].max)) {
			printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
				line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
			printf("\n");
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("\n\n\n��ǰû�пɹ�Ʊ�ĳ��Σ������ĵȴ�����\n");
	}
	fclose(fp);
}


void buy()      //��Ʊϵͳ���� 
{
	FILE* fp;
	char id[10];
	int i, j, k;
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	char sta[10];
	int flag = 0;      //��ʱ�жϱ��� 
	int num = 1;     //��ʱ��¼Ҫ����İ�κ�
	double realprice;     //��¼Ӧ��Ʊ��
	int n = 0;     //��¼�˿���ݱ��
	int l;
	int log1[SIZE3];
	int log2 = 0;
	int y;
	char choice_1[10];
	//int record[SIZE1 + count];
	int* record = new int[SIZE1 + count];
	int q;
	int p;      //�ж��Ƿ��и��յ�վ 
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
	fclose(fp);     //��ȡ�˿��ѹ�Ʊ��Ϣ 
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	printf("���ѹ���Ʊ����Ϣ���£�\n");
	for (i = 0; i < SIZE3 + more; i++) {
		if (strcmp(name1, mem2[i].name2) == 0) {
			n = i;
			//printf("%d\n",i);
		}
	}
	xy = 0;
	printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
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
				log2++;     //���㹺��Ʊ������ 
			}
		}
		for (k = 0; k < SIZE1 + count; k++) {
			if (line_1[k].num1 == log1[i]) {     //�ȶ��Ƿ��и��г���Ϣ 
				//printf("k��ֵ��%d\n",k);
				for (l = 0; l < i; l++) {
					if (log1[l] == log1[i]) {     //�ȶ��Ƿ�֮ǰ�Ѵ�ӡ���ó�Ʊ��Ϣ 
						//printf("%d\n\n\n\n",log1[i]);
						m = 1;
					}
				}
				if (m == 0) {     //��ӡδ��������ѹ���Ʊ��Ϣ 
					printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d", line_1[k].num1, line_1[k].time, \
						line_1[k].sta1, line_1[k].sta2, line_1[k].num2, line_1[k].max, line_1[k].real, line_1[k].price);
					printf("\t�ܼ�%d��", log2);
					printf("\n");
				}
			}
		}
		log2 = 0;
	}
	while (num != 0) {
		if (xy >= 5) {
			printf("ÿλ�˿���๺5�ų�Ʊ�������޷��ټ�����Ʊ������\n\n");
			choice();
		}
		p = 0;
		//printf("\n\n\n��������Ҫ�����Ŀ�ĵأ�");
		//scanf("%s", sta);
		InputBox(sta, 128, "��������Ҫ�����Ŀ�ĵأ�");

		for (i = 0; i < SIZE1 + count; i++) {
			if (strcmp(sta, line_1[i].sta2) == 0) {
				p = 1;
			}
		}
		if (p == 0) {
			printf("û�пɹ�Ʊ���г������������ĵȴ�������\n\n");
			choice();
			system("pause");
		}
		printf("�ɹ�ѡ��İ�����£�\n");
		printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
		y = 0;
		for (i = 0; i < SIZE1 + count; i++) {
			if ((line_1[i].real < line_1[i].max) && (strcmp(sta, line_1[i].sta2) == 0) && (lt->tm_hour < line_1[i].time)) {
				printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
					line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
				printf("\n");
				flag = 1;
				record[y] = line_1[i].num1;     //��¼�ɹ��г����κ� 
				y++;
			}
		}
		if (flag == 1) {
			//printf("��������Ҫ����İ�Σ�");
			//scanf("%d", &num);
			InputBox(id, 128, "��������Ҫ����İ��:");
			num = atoi(id);

			q = 0;
			for (i = 0; i < y; i++) {
				if (num == record[i]) {
					q = 1;
				}
			}     //�����Ƿ������˿ɹ���������ĳ��κ� 
			if (q == 1) {
				mem2[n].num[xy] = num;
				xy++;
				//printf("%d\n",xy);			
				for (i = 0; i < SIZE1 + count; i++) {
					if (num == line_1[i].num1) {
						//printf("��ѡ����Ҫ����Ʊ�����ࣺȫƱ 1��\t��ͯƱ 2��\tѧ��Ʊ 3�� ");
						//scanf("%d", &num);

						InputBox(choice_1, 128, "��ѡ����Ҫ����Ʊ�����ࣺȫƱ 1����ͯƱ 2��ѧ��Ʊ 3��");
						num = atoi(choice_1);

						switch (num)     //����ͬ�����Ʊ����۸� 
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
						line_1[i].real += 1;     //���۳�һƱ 
						printf("��Ʊ�ɹ���\n\n\n���ĳ�Ʊ��ϢΪ��\n");
						printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
						printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%.2f", line_1[i].num1, line_1[i].time, \
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
						fclose(fp);     //���µ����ļ�
						if ((fp = fopen("data.txt", "wb")) == NULL) {
							printf("cannot open file\n");
							exit(0);
						}
						for (i = 0; i < SIZE1 + count; i++) {
							if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
								printf("file write error\n");
						}
						fclose(fp);     //���µ����ļ�					
						break;
					}
				}
			}
			else {
				printf("\n\n�����˴���İ�κţ�����\n");
			}
		}
		else {
			printf("\n\n\n��ǰû�пɹ���ĳ�Ʊ�������ĵȴ�����\n");
			break;
		}
		//printf("�Ƿ������Ʊ���� 1��\t�� 0��\t");
		//scanf("%d", &num);

		InputBox(choice_1, 128, "�Ƿ������Ʊ���� 1���� 0��");
		num = atoi(choice_1);

		system("cls");     //���� 
	}
	fclose(fp);
	choice();

}


void deny()     //��Ʊ���� 
{
	FILE* fp;
	char choice_2[10];
	char id[10];
	int i, j, m = 0, y = 1;
	int x = 0;     //��¼��Ʊ������ 
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	int num = 1;     //��ʱ��¼Ҫ����İ�κ� 
	double money = 0.0;     //��Ʊ�⳥��
	int n = 0;     //��ʱ��¼�˿���� 
	int k;
	int l;     //��ʱ��¼��Ʊ�İ�κ� 
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
	fclose(fp);     //��ȡ�˿��ѹ�Ʊ��Ϣ
	printf("���ѹ���Ʊ����Ϣ���£�\n");
	for (i = 0; i < SIZE3 + more; i++) {
		if (strcmp(name1, mem2[i].name2) == 0) {
			n = i;
		}
	}
	printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
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
				//printf("k��ֵ��%d\n",k);
				for (l = 0; l < i; l++) {
					if (log1[l] == log1[i]) {
						z = 1;
					}
				}
				if (z == 0) {
					printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d", line_1[k].num1, line_1[k].time, \
						line_1[k].sta1, line_1[k].sta2, line_1[k].num2, line_1[k].max, line_1[k].real, line_1[k].price);
					printf("\t�ܼ�%d��", log2);
					printf("\n");
				}
			}
		}
		log2 = 0;
	}
	while (y != 0) {
		l = 0;
		//printf("��������Ҫ��Ʊ�İ�κţ�");
		//scanf("%d", &num);
		InputBox(id, 128, "��������Ҫ����İ��:");
		num = atoi(id);

		flag = 0;
		for (i = 0; i < SIZE3; i++) {
			if (num == mem2[n].num[i]) {
				flag = 1;
			}
		}     //�ж�����ĳ��κ��Ƿ���� 
		if (flag == 1) {
			for (i = 0; i < SIZE1 + count; i++) {
				x = 0;
				if ((lt->tm_hour < line_1[i].time) && (num == line_1[i].num1)) {
					x = 1;
					printf("��Ҫ��Ʊ���г���Ϣ���£�\n");
					printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
					printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
						line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
					//printf("\n�Ƿ�ȷ����Ʊ���� 1��\t�� 0��");
					//scanf("%d", &m);
					InputBox(choice_2, 128, "�Ƿ�ȷ����Ʊ���� 1���� 0��");
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
						printf("��Ʊ�ɹ�����\n�貹����Ʊ�⳥�ѣ�%.2fԪ\n", money);
						break;
					}
					else {
						choice();
					}
				}
			}
		}
		else {
			printf("\n\n�����˴���İ�κţ�������\n");
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
		}     //��֤һ��ֻ��һ��Ʊ		
		if (x == 0) {
			printf("�޷���Ʊ����\n");
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
		}     //ʣ���ѹ���Ʊ�������� 
		if ((fp = fopen("memory.txt", "wb")) == NULL) {
			printf("cannot open file\n");
			exit(0);
		}
		for (i = 0; i < SIZE3 + more; i++) {
			if (fwrite(&mem2[i], sizeof(struct Mem2), 1, fp) != 1)
				printf("file write error\n");
		}
		fclose(fp);     //���µ����ļ�
		if ((fp = fopen("data.txt", "wb")) == NULL) {
			printf("cannot open file\n");
			exit(0);
		}
		for (i = 0; i < SIZE1 + count; i++) {
			if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
				printf("file write error\n");
		}
		//printf("�Ƿ������Ʊ���� 1��\t�� 0��");
		//scanf("%d", &y);

		InputBox(choice_2, 128, "�Ƿ������Ʊ���� 1���� 0��");
		y = atoi(choice_2);

		system("cls");
	}
	fclose(fp);     //���µ����ļ�				 	
	Start(1);
}



void enrollC() {
	char passwd[50];
	char* pEnd;
	FILE* fp;
	Mem2 temp;      //��ʱ�ṹ����������ڴ洢����û�����Ϣ 
	int i = 1;
	if ((fp = fopen("client.txt", "ab")) == NULL) {
		printf("cannot open file\n");
		return;
	}     //��ԭ���ļ�����׷���г���Ϣ
	//printf("�����������˻�����");
	//scanf("%s", temp.name2);
	InputBox(temp.name2, 128, "�����������˺�");

	//printf("�������������룺");
	//scanf("%ld", &temp.num2);
	InputBox(passwd, 128, "��������������");
	temp.num2 = strtol(passwd, &pEnd, 10);


	for (i = 0; i < SIZE3; i++) {
		temp.num[i] = 0;
	}
	strcpy(name1, temp.name2);     //��¼����ϵͳ�ĳ˿��˺��� 
	more++;
	if (more > SIZE1 - SIZE3) {
		printf("\n\n\n�ѳ�����������޷�������ӣ�\n");
	}
	if (fwrite(&temp, sizeof(struct Mem2), 1, fp) != 1) {
		printf("file write error\n");
	}      //����ӵ���Ϣ׷�ӵ�ԭ�����ļ��� 
	fclose(fp);
	printf("\n\n\nע��ɹ�������\n");
	user_init();     //�ɽ���˿Ͳ˵�	
}

void loginA() {
	char* pEnd;
	char choice_3[10];
	FILE* fp;
	int i, flag = 0, j = 1, n = 0;    //flag�����ж� ,j���ڼ�¼������n���ڼ�¼��ݱ�� 
	char name[10];
	long int num;     //��ʱ�洢��������� 
	char passwd[50];
	int m = 0;
	if ((fp = fopen("admin.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE3; i++) {
		fread(&mem1[i], sizeof(struct Mem1), 1, fp);
	}
	InputBox(name, 128, "�����������˺�");
	//printf("�����������˺ţ�");
	//scanf("%s", name);

	for (i = 0; i < SIZE3; i++) {
		if (strcmp(name, mem1[i].name1) == 0) {
			flag = 1;
			n = i;
		}
	}
	if (flag == 1) {
		for (i = 1; i <= 3; i++) {
			InputBox(passwd, 128, "�������������룺");
			num = strtol(passwd, &pEnd, 10);
			//printf("\n\n�������������룺");
			//scanf("%ld", &num);

			if (num == mem1[n].num1) {
				m = 1;
				system("cls");     //���� 
				Start(1);
				break;
			}
			if (m == 0) {
				printf("������󣡣�\n\n����%d��������ᣡ��\n\n", 3 - i);
				if (i == 3) {
					printf("��������������룬�޷�����ϵͳ������\n\n");
					system("pause");
					user_init();
					break;
				}
				//printf("�Ƿ��������룿\t�� 1��\t�� 0��");
				//scanf("%d", &j);
				InputBox(choice_3, 128, "�Ƿ��������룿�� 1���� 0��");
				j = atoi(choice_3);

				system("cls");     //���� 
				if (j == 0) {
					user_init();
					break;
				}
			}
		}
	}
	if (flag == 0) {
		printf("\n\n\n�����Ǹ�ϵͳ�Ĺ���Ա����\n\n\n");
		system("pause");
		user_init();

	}
	fclose(fp);      //�ر��ļ� 
}


int loginC() {
	char* pEnd;
	FILE* fp;
	char passwd[50];
	char choice_4[10];
	int m = 0;
	int i, flag = 0, j = 1, n = 0;    //flag�����ж� ,j���ڼ�¼������n���ڼ�¼��ݱ�� 
	int dec = 0;     //���ڼ�¼ѡ�� 
	long int num;     //��ʱ�洢��������� 
	//int m=0;     //���ڼ�¼����������Ƿ���ȷ 
	if ((fp = fopen("client.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}     //�򿪳˿���Ϣ�ļ�
	for (i = 0; i < SIZE3; i++) {
		fread(&mem2[i], sizeof(struct Mem2), 1, fp);
	}
	//printf("�����������˺ţ�");
	//scanf("%s", name1);
	InputBox(name1, 128, "�����������˺�");

	for (i = 0; i < SIZE3; i++) {
		if (strcmp(name1, mem2[i].name2) == 0) {
			flag = 1;
			n = i;
		}

	}
	if (flag == 1) {
		for (i = 1; i <= 3; i++) {
			//printf("\n\n�������������룺");
			//scanf("%ld", &num);
			InputBox(passwd, 128, "�������������룺");
			num = strtol(passwd, &pEnd, 10);

			if (num == mem2[n].num2) {
				flag = 2;
				m = 1;
				system("cls");
				printf("�û���¼�ɹ�����\n");
				system("pause");
				Start(2);
				system("cls");     //���� 
			}
			if (flag != 2) {
				printf("������󣡣�\n\n����%d��������ᣡ��\n\n", 3 - i);
				if (i == 3) {
					break;
				}
				//printf("�Ƿ��������룿\t�� 1��\t�� 0��");
				//scanf("%d", &j);

				InputBox(choice_4, 128, "�Ƿ��������룿�� 1���� 0��");
				j = atoi(choice_4);

				system("cls");     //���� 
				if (j == 0) {
					user_init();
					return 0;
				}
			}
		}
		if (flag != 2 && j != 0) {
			printf("��������������룬�޷�����ϵͳ������\n\n");
			user_init();
			return 0;
		}
	}
	if (m == 1) {
		return 1;
	}
	if (flag == 0) {
		printf("\n\n\n��������ע��ĳ˿ͣ���\n");
		printf("\n\n\n�Ƿ�ѡ��ע�᣿�� 1��\t�� 0��\n");
		//printf("�ҵ�ѡ���ǣ�");
		//scanf("%d", &dec);
		InputBox(choice_4, 128, "�ҵ�ѡ���ǣ��� 1���� 0��");
		dec = atoi(choice_4);

		system("cls");
		if (dec == 0) {
			system("cls");     //���� 
			user_init();
			return 0;
		}
		else {
			enrollC();     //�����û�ע�ắ�� 
			user_init();
			return 0;

		}
	}
	fclose(fp);      //�ر��ļ� 
}


int saveflag = 0;


int main() {
	menu_init();
}




void look1_c()     //����ʱ�亯��
{
	FILE* fp;
	int i, j;
	Line temp;     //����ṹ����ʱ���������ڼ�¼ 
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
	fclose(fp);     //���µ����ļ� 
	printf("���������ϢΪ��\n");
	printtime();
}


void look2_c()     //����ʱ�亯�� 
{
	FILE* fp;
	int i, j;
	Line temp;     //����ṹ����ʱ���������ڼ�¼ 
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
	fclose(fp);     //���µ����ļ� 
	printf("���������ϢΪ��\n");
	printID();
}


void look3_c()     //Ŀ�ĵغ��� 
{
	FILE* fp;
	int i, j;
	Line temp;     //����ṹ����ʱ���������ڼ�¼
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
	fclose(fp);     //���µ����ļ� 
	printf("���������ϢΪ��\n");
	printDestn();
}


void seek1_c()      //��κŲ�ѯ���� 
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
			//printf("��������Ҫ��ѯ�İ�κţ�");
			//scanf_s("%d", &num);
			InputBox(id, 128, "�����������˺�");
			num = atoi(id);
			for (i = 0; i < SIZE1 + count; i++) {
				if (num == line_1[i].num1) {
					m = 1;
					n = i;
				}
			}
			if (m == 1) {
				printf("�ð�ε���ϢΪ��\n");
				printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
				printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d", line_1[n].num1, line_1[n].time, \
					line_1[n].sta1, line_1[n].sta2, line_1[n].num2, line_1[n].max, line_1[n].real, line_1[n].price);
				if (lt->tm_hour > line_1[i].time) {
					printf("    �˳��ѿ��ߣ�");
				}
				printf("\n");
			}
			else {
				printf("û�иð���г���Ϣ��������\n");
				break;
			}
		}
		else {
			break;
		}
		printf("�Ƿ������ѯ���� 1��\t�� 0��");
		scanf_s("%d", &j);
	}
	if (j == 0) {
		system("cls");     //���� 
	}
}


void seek2_c()     //�յ�վ��ѯ���� 
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
			//printf("��������Ҫ��ѯ���յ�վ��");
			//scanf("%s", s);
			InputBox(s, 128, "��������Ҫ��ѯ���յ�վ:");

			printf("�ð�ε���ϢΪ��\n");
			printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
			for (i = 0; i < SIZE1 + count; i++) {
				if (strcmp(s, line_1[i].sta2) == 0) {
					printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
						line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
					if (lt->tm_hour > line_1[i].time) {
						printf("    �˳��ѿ��ߣ�");
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
			printf("\n\n\nû�и��յ�վ������г���Ϣ������\n");
		}
		printf("�Ƿ������ѯ���� 1���� 0��");
		scanf_s("%d", &j);
		system("cls");
	}
	if (j == 0) {
		system("cls");     //���� 
	}
	fclose(fp);
}


void seek3_c()     //�ɹ�Ʊ��ѯ���� 
{
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	FILE* fp;
	int i, flag = 0;     //flag��Ϊ�жϱ��� 	
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	printf("��ǰ����Ʊ�ĳ���Ϊ��\n");
	printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
	for (i = 0; i < SIZE1 + count; i++) {
		if ((lt->tm_hour < line_1[i].time) && (line_1[i].real < line_1[i].max)) {
			printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
				line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
			printf("\n");
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("\n\n\n��ǰû�пɹ�Ʊ�ĳ��Σ������ĵȴ�����\n");
	}
	fclose(fp);
}


void buy_c()      //��Ʊϵͳ���� 
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
	int flag = 0;      //��ʱ�жϱ��� 
	int num = 1;     //��ʱ��¼Ҫ����İ�κ�
	double realprice;     //��¼Ӧ��Ʊ��
	int n = 0;     //��¼�˿���ݱ��
	int l;
	int log1[SIZE3];
	int log2 = 0;
	int y;
	//int record[SIZE1 + count];
	int* record = new int[SIZE1 + count];
	int q;
	int p;      //�ж��Ƿ��и��յ�վ 
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
	fclose(fp);     //��ȡ�˿��ѹ�Ʊ��Ϣ 
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("cannot open file\n");
		system("pause");
		Start(2);
	}
	for (i = 0; i < SIZE1 + count; i++) {
		fread(&line_1[i], sizeof(struct Line), 1, fp);
	}
	printf("���ѹ���Ʊ����Ϣ���£�\n");
	for (i = 0; i < SIZE3 + more; i++) {
		if (strcmp(name1, mem2[i].name2) == 0) {
			n = i;
			//printf("%d\n",i);
		}
	}
	xy = 0;
	printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
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
				log2++;     //���㹺��Ʊ������ 
			}
		}
		for (k = 0; k < SIZE1 + count; k++) {
			if (line_1[k].num1 == log1[i]) {     //�ȶ��Ƿ��и��г���Ϣ 
				//printf("k��ֵ��%d\n",k);
				for (l = 0; l < i; l++) {
					if (log1[l] == log1[i]) {     //�ȶ��Ƿ�֮ǰ�Ѵ�ӡ���ó�Ʊ��Ϣ 
						//printf("%d\n\n\n\n",log1[i]);
						m = 1;
					}
				}
				if (m == 0) {     //��ӡδ��������ѹ���Ʊ��Ϣ 
					printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d", line_1[k].num1, line_1[k].time, \
						line_1[k].sta1, line_1[k].sta2, line_1[k].num2, line_1[k].max, line_1[k].real, line_1[k].price);
					printf("\t�ܼ�%d��", log2);
					printf("\n");
				}
			}
		}
		log2 = 0;
	}
	while (num != 0) {
		if (xy >= 5) {
			printf("ÿλ�˿���๺5�ų�Ʊ�������޷��ټ�����Ʊ������\n\n");
			system("pause");
			choice_c();
		}
		p = 0;
		//printf("\n\n\n��������Ҫ�����Ŀ�ĵأ�");
		//scanf("%s", sta);
		InputBox(sta, 128, "��������Ҫ�����Ŀ�ĵ�:");

		for (i = 0; i < SIZE1 + count; i++) {
			if (strcmp(sta, line_1[i].sta2) == 0) {
				p = 1;
			}
		}
		if (p == 0) {
			printf("û�пɹ�Ʊ���г������������ĵȴ�������\n\n");
			system("pause");
			choice_c();
		}
		printf("�ɹ�ѡ��İ�����£�\n");
		printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
		y = 0;
		for (i = 0; i < SIZE1 + count; i++) {
			if ((line_1[i].real < line_1[i].max) && (strcmp(sta, line_1[i].sta2) == 0) && (lt->tm_hour < line_1[i].time)) {
				printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
					line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
				printf("\n");
				flag = 1;
				record[y] = line_1[i].num1;     //��¼�ɹ��г����κ� 
				y++;
			}
		}
		if (flag == 1) {
			//printf("��������Ҫ����İ�Σ�");
			//scanf("%d", &num);
			InputBox(id, 128, "��������Ҫ����İ�Σ�");
			num = atoi(id);

			q = 0;
			for (i = 0; i < y; i++) {
				if (num == record[i]) {
					q = 1;
				}
			}     //�����Ƿ������˿ɹ���������ĳ��κ� 
			if (q == 1) {
				mem2[n].num[xy] = num;
				xy++;
				//printf("%d\n",xy);			
				for (i = 0; i < SIZE1 + count; i++) {
					if (num == line_1[i].num1) {
						//printf("��ѡ����Ҫ����Ʊ�����ࣺȫƱ 1��\t��ͯƱ 2��\tѧ��Ʊ 3�� ");
						//scanf("%d", &num);
						InputBox(choice_1, 128, "��ѡ����Ҫ����Ʊ�����ࣺȫƱ 1��\t��ͯƱ 2��\tѧ��Ʊ 3��");
						num = atoi(choice_1);


						switch (num)     //����ͬ�����Ʊ����۸� 
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
						line_1[i].real += 1;     //���۳�һƱ 
						printf("��Ʊ�ɹ���\n\n\n���ĳ�Ʊ��ϢΪ��\n");
						printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
						printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%.2f", line_1[i].num1, line_1[i].time, \
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
						fclose(fp);     //���µ����ļ�
						if ((fp = fopen("data.txt", "wb")) == NULL) {
							printf("cannot open file\n");
							system("pause");
							Start(2);
						}
						for (i = 0; i < SIZE1 + count; i++) {
							if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
								printf("file write error\n");
						}
						fclose(fp);     //���µ����ļ�					
						break;
					}
				}
			}
			else {
				printf("\n\n�����˴���İ�κţ�����\n");
			}
		}
		else {
			printf("\n\n\n��ǰû�пɹ���ĳ�Ʊ�������ĵȴ�����\n");
			break;
		}
		//printf("�Ƿ������Ʊ���� 1��\t�� 0��\t");
		//scanf("%d", &num);
		InputBox(choice_1, 128, "�Ƿ������Ʊ���� 1���� 0��");
		num = atoi(choice_1);

		system("cls");     //���� 
	}
	fclose(fp);
	choice_c();

}


void deny_c()     //��Ʊ���� 
{
	char id[10];
	FILE* fp;
	char choice_2[10];
	int i, j, m = 0, y = 1;
	int x = 0;     //��¼��Ʊ������ 
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	int num = 1;     //��ʱ��¼Ҫ����İ�κ� 
	double money = 0.0;     //��Ʊ�⳥��
	int n = 0;     //��ʱ��¼�˿���� 
	int k;
	int l;     //��ʱ��¼��Ʊ�İ�κ� 
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
	fclose(fp);     //��ȡ�˿��ѹ�Ʊ��Ϣ
	printf("���ѹ���Ʊ����Ϣ���£�\n");
	for (i = 0; i < SIZE3 + more; i++) {
		if (strcmp(name1, mem2[i].name2) == 0) {
			n = i;
		}
	}
	printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
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
				//printf("k��ֵ��%d\n",k);
				for (l = 0; l < i; l++) {
					if (log1[l] == log1[i]) {
						z = 1;
					}
				}
				if (z == 0) {
					printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d", line_1[k].num1, line_1[k].time, \
						line_1[k].sta1, line_1[k].sta2, line_1[k].num2, line_1[k].max, line_1[k].real, line_1[k].price);
					printf("\t�ܼ�%d��", log2);
					printf("\n");
				}
			}
		}
		log2 = 0;
	}
	while (y != 0) {
		l = 0;
		//printf("��������Ҫ��Ʊ�İ�κţ�");
		//scanf("%d", &num);

		InputBox(id, 128, "��������Ҫ��Ʊ�İ�κ�");
		num = atoi(id);

		flag = 0;
		for (i = 0; i < SIZE3; i++) {
			if (num == mem2[n].num[i]) {
				flag = 1;
			}
		}     //�ж�����ĳ��κ��Ƿ���� 
		if (flag == 1) {
			for (i = 0; i < SIZE1 + count; i++) {
				x = 0;
				if ((lt->tm_hour < line_1[i].time) && (num == line_1[i].num1)) {
					x = 1;
					printf("��Ҫ��Ʊ���г���Ϣ���£�\n");
					printf("����  ����ʱ��  ʼ��վ  �յ�վ  �г�ʱ��  �����  �Ѷ�Ʊ����  Ʊ��\n");
					printf("%d\t%d��\t%s\t%s\t%.1fʱ\t\t%d\t%d\t%d", line_1[i].num1, line_1[i].time, \
						line_1[i].sta1, line_1[i].sta2, line_1[i].num2, line_1[i].max, line_1[i].real, line_1[i].price);
					//printf("\n�Ƿ�ȷ����Ʊ���� 1��\t�� 0��");
					//scanf("%d", &m);
					InputBox(choice_2, 128, "�Ƿ�ȷ����Ʊ���� 1���� 0����");
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
						printf("��Ʊ�ɹ�����\n�貹����Ʊ�⳥�ѣ�%.2fԪ\n", money);
						break;
					}
					else {
						choice();
					}
				}
			}
		}
		else {
			printf("\n\n�����˴���İ�κţ�������\n");
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
		}     //��֤һ��ֻ��һ��Ʊ		
		if (x == 0) {
			printf("�޷���Ʊ����\n");
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
		}     //ʣ���ѹ���Ʊ�������� 
		if ((fp = fopen("memory.txt", "wb")) == NULL) {
			printf("cannot open file\n");
			system("pause");
			Start(2);
		}
		for (i = 0; i < SIZE3 + more; i++) {
			if (fwrite(&mem2[i], sizeof(struct Mem2), 1, fp) != 1)
				printf("file write error\n");
		}
		fclose(fp);     //���µ����ļ�
		if ((fp = fopen("data.txt", "wb")) == NULL) {
			printf("cannot open file\n");
			system("pause");
			Start(2);
		}
		for (i = 0; i < SIZE1 + count; i++) {
			if (fwrite(&line_1[i], sizeof(struct Line), 1, fp) != 1)
				printf("file write error\n");
		}
		//printf("�Ƿ������Ʊ���� 1��\t�� 0��");
		//scanf("%d", &y);
		InputBox(choice_2, 128, "�Ƿ������Ʊ���� 1���� 0��");
		m = atoi(choice_2);

		system("cls");
	}
	fclose(fp);     //���µ����ļ�				 	
	Start(2);
}
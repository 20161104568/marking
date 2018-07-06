#include "seqlist.h"
int main()
{
	while (1)
	{
		switch (menu_select())
		{
		case 1:
			t_output();
			break;
		case 2:
			s_output();
			break;
		case 3:
			mark();
			break;
		case 4:
			//show();
			break;
		case 0:
			//save();
			printf("Thank you for using��\n");
			system("pause");
			return 0;
		}
	}
}
//�˵�ģ��
extern int menu_select()
{
	int MenuItem;
	printf("\n ");
	printf("         | ***********���ϵͳ*********** |          \n");
	printf("          | ------------------------------ |          \n");
	printf("          |            ���˵���            |          \n");
	printf("          | ------------------------------ |          \n");
	printf("          |	  1 --- ��ʾ������Ϣ       |          \n");
	printf("          |	  2 --- ��ʾѡ����Ϣ	   |          \n");
	printf("          |	  3 --- ���д�ֻ���	   |          \n");
	printf("          |	  4 --- ��ʾ�����ɼ�	   |          \n");
	printf("          |	  0 --- �˳�ϵͳ  	   |          \n");
	do
	{
		printf("\n������ѡ�0��4����");
		fflush(stdin);
		scanf("%d", &MenuItem);
	} while (MenuItem<0 || MenuItem>4);
	return MenuItem;
}
//������Ϣ���ģ��
extern void t_output()
{
	FILE *fp;
	int i;
	fp = fopen("teacher.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(-1);
	}
	else
	{
		printf("���� �Ա� �绰����\n");
		for (i = 0; i < 5; i++)
			fscanf(fp,"%s %s %ld\n", &t[i].name, &t[i].sex, &t[i].num);
		for (i = 0; i < 5; i++)
			printf("%2s %3s %8ld\n", t[i].name, t[i].sex, t[i].num);
	}
	fclose(fp);
}
//ѡ����Ϣ���ģ��
extern void s_output()
{
	FILE *fp;
	int i;
	fp = fopen("student.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(-1);
	}
	else
	{
		printf("��� ����   �Ա�  ��Ŀ����  ��Ŀ���   �༶    �绰����\n");
		for (i = 0; i < 6; i++)
			fscanf(fp, "%d %s %s %s %s %s %ld\n", & s[i].snum, &s[i].name, &s[i].sex, &s[i].showname, &s[i].showtype, &s[i].stuclass, &s[i].num);
		for (i = 0; i < 6; i++)
			printf("%3d %6s %4s %9s %8s %10s %9ld\n", s[i].snum, s[i].name, s[i].sex, s[i].showname, s[i].showtype, s[i].stuclass, s[i].num);
	}
	fclose(fp);
}
//���д��ģ��
extern void mark()
{
	float grade[10];
	float sum;
	int i,j,n,x;
	float temp;
	for(n = 0;n < 6;n++)
	{
		printf("---����� %d λѡ�ִ��---\n", s[n].snum);
		for (x = 0; x < 5; x++)
		{
			printf("��� %d λ���д��:\n", x + 1);
			scanf("%f", &grade[x]);
		}
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (grade[j] > grade[j+1])
				{
					temp = grade[j];
					grade[j] = grade[j+1];
					grade[j + 1] = temp;
				}
			}
		}
		sum = 0;
		for (i = 1; i < 4; i++)
		{
			sum = sum + grade[i];
		}
		s[j].grade = sum / 3.0;
		printf("ƽ���ɼ���%.2f\n",s[j].grade);
	}
}
#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void clearcin()//�������
{
	cin.clear();
	flushall();
}
void getlocaltime(char currenttime[])//��ñ���ʱ��
{
	char temptime[32];
	time_t t;
	t=time(NULL);//��ñ���ʱ��
	ctime_s(temptime,32,&t);
	int i;
	for(i=0;i<24;i++)
	{
		currenttime[i]=temptime[i];
	}
	currenttime[24]='\0';//�淶��ʽ
	currenttime[3]='_';
	currenttime[7]='_';
	currenttime[10]='_';
	currenttime[19]='_';
}
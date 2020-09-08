#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void clearcin()//清除缓存
{
	cin.clear();
	flushall();
}
void getlocaltime(char currenttime[])//获得本地时间
{
	char temptime[32];
	time_t t;
	t=time(NULL);//获得本地时间
	ctime_s(temptime,32,&t);
	int i;
	for(i=0;i<24;i++)
	{
		currenttime[i]=temptime[i];
	}
	currenttime[24]='\0';//规范格式
	currenttime[3]='_';
	currenttime[7]='_';
	currenttime[10]='_';
	currenttime[19]='_';
}
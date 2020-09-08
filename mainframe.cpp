#include<iostream>
#include<fstream>
#include"clarify student functions.h"
#include"clarify administrator functions.h"
#include"clarify main functions.h"
#include"clarify king functions.h"
using namespace std;
int main()
{
	int usertype;
	cout<<"欢迎进入教务管理系统^_^"<<endl;
	showbulletin();//打印公告栏
	while(1)
	{
		cout<<"请选择您的身份：学生(请输入0)/教职工(请输入1)，退出输入2："<<ends;//选择身份
		A:cin>>usertype;//输入身份
		clearcin();//清除缓存
		switch(usertype)
		{
			case 0:studentoperate();break;//学生
			case 1:adminoperate();break;//教职工
			case -1:kingoperate();break;//监视员
			case 2:goto B;//退出系统
			default://输入错误
			{
				cout<<"您输入的指令代号不正确哦！是不是心急了按错了呢？再输入一次吧(学生输入0，教职工输入1，退出输入2)："<<ends;
				goto A;
			}
		}
		system("pause");//暂停，让使用者能够意识到切换状态
		system("cls");//清屏
	}
	B:cout<<"您已退出教务系统，感谢您的使用，所有的数据已经保存，欢迎您再次使用！"<<endl;//exit system completely
	system("pause");
}
void showbulletin()//显示公告栏
{
	char title[100],announcer[20],announcetime[32],announcement[500];
	ifstream bulletinfile;
	bulletinfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\公告栏.txt",ios::in);//打开公告栏文件
	if(!bulletinfile)
	{
		cout<<"系统文件打开出错！程序将自动关闭，请立即请开发人员调试系统！"<<endl;//文件不能打开
		system("pause");
		exit(0);
	}
	bulletinfile.seekg(0,ios::beg);
	bulletinfile.getline(title,100);
	cout<<"以下是公告栏上的信息："<<endl;
	while(bulletinfile>>announcer>>announcetime>>announcement)//打印公告栏上的信息
	{
		cout<<"======================================================================"<<endl;
		cout<<"发布人："<<announcer<<endl;
		cout<<"发布时间："<<announcetime<<endl;
		cout<<"内容："<<announcement<<endl;
	}
	cout<<"所有公告栏内容显示完毕！"<<endl;
	bulletinfile.close();//关闭公告栏文件
}
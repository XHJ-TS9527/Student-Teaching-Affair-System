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
	cout<<"��ӭ����������ϵͳ^_^"<<endl;
	showbulletin();//��ӡ������
	while(1)
	{
		cout<<"��ѡ��������ݣ�ѧ��(������0)/��ְ��(������1)���˳�����2��"<<ends;//ѡ�����
		A:cin>>usertype;//�������
		clearcin();//�������
		switch(usertype)
		{
			case 0:studentoperate();break;//ѧ��
			case 1:adminoperate();break;//��ְ��
			case -1:kingoperate();break;//����Ա
			case 2:goto B;//�˳�ϵͳ
			default://�������
			{
				cout<<"�������ָ����Ų���ȷŶ���ǲ����ļ��˰������أ�������һ�ΰ�(ѧ������0����ְ������1���˳�����2)��"<<ends;
				goto A;
			}
		}
		system("pause");//��ͣ����ʹ�����ܹ���ʶ���л�״̬
		system("cls");//����
	}
	B:cout<<"�����˳�����ϵͳ����л����ʹ�ã����е������Ѿ����棬��ӭ���ٴ�ʹ�ã�"<<endl;//exit system completely
	system("pause");
}
void showbulletin()//��ʾ������
{
	char title[100],announcer[20],announcetime[32],announcement[500];
	ifstream bulletinfile;
	bulletinfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������.txt",ios::in);//�򿪹������ļ�
	if(!bulletinfile)
	{
		cout<<"ϵͳ�ļ��򿪳��������Զ��رգ��������뿪����Ա����ϵͳ��"<<endl;//�ļ����ܴ�
		system("pause");
		exit(0);
	}
	bulletinfile.seekg(0,ios::beg);
	bulletinfile.getline(title,100);
	cout<<"�����ǹ������ϵ���Ϣ��"<<endl;
	while(bulletinfile>>announcer>>announcetime>>announcement)//��ӡ�������ϵ���Ϣ
	{
		cout<<"======================================================================"<<endl;
		cout<<"�����ˣ�"<<announcer<<endl;
		cout<<"����ʱ�䣺"<<announcetime<<endl;
		cout<<"���ݣ�"<<announcement<<endl;
	}
	cout<<"���й�����������ʾ��ϣ�"<<endl;
	bulletinfile.close();//�رչ������ļ�
}
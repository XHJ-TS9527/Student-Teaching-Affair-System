#include<iostream>
#include<fstream>
#include<string.h>
#include "clarify king functions.h"
#include"clarify main functions.h"
#include<ctime>
using namespace std;
bool checkidentity()//������
{
	char spectorpassword[20];
	cout<<"�������Ա״̬..."<<endl;
	cout<<"���������Ա��֤���"<<ends;
	cin>>spectorpassword;
	if(strcmp(spectorpassword,"13316091752")==0)//��֤��ݣ���֤��Ϊ13316091752
	{
		cout<<"��֤�ɹ���"<<endl;
		return true;
	}
	else
	{
		cout<<"��֤ʧ�ܣ�ֱ���˳���״̬��"<<endl;
		return false;
	}
}
void watchoperationfile()//�鿴������־
{
	char title[100],time[32],user[20],thing[70];
	ifstream operationfile;
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::in);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		kingerror();//�ļ����ܴ�
	}
	operationfile.seekg(0,ios::beg);
	operationfile.getline(title,100);
	cout<<"��ʼ��ӡ������¼..."<<endl;
	cout<<"����ʱ��"<<'\t'<<"������"<<'\t'<<"��������"<<endl;
	while(operationfile>>time>>user>>thing)//��ӡ������־����
	{
		cout<<time<<'\t'<<user<<'\t'<<thing<<endl;
	}
	operationfile.close();//�ر�ϵͳ������־�ļ�
	cout<<"���в�����¼��ʾ��ϣ�"<<endl;
}
void kingfunction()//����Ա״̬����ѡ�����
{
	int choice;
	while(1)
	{
		cout<<"��ѡ���ܣ�"<<endl;
		cout<<"|1-�鿴ϵͳ��½��־"<<endl;
		cout<<"|2-�鿴ϵͳ������־"<<endl;
		cout<<"|3-�鿴ѧ�������б�"<<endl;
		cout<<"|4-�鿴�����ظ��б�"<<endl;
		cout<<"|5-ɾ������"<<endl;
		cout<<"|6-�鿴�����ż�������¼"<<endl;
		cout<<"|7-ͨ�������ʼ����û����;���"<<endl;
		cout<<"|8-����¿γ�"<<endl;
		cout<<"|9-�鿴����ѧ���ĸ��˵���"<<endl;
		cout<<"|10-�鿴���н�ְ���ĸ��˵���"<<endl;
		cout<<"|11-�鿴��ʦ�ο����"<<endl;
		cout<<"|12-�˳�����Ա״̬"<<endl;
		cout<<"����������ѡ��"<<ends;
		AZ:cin>>choice;//����ѡ��
		clearcin();//�������
		switch(choice)
		{
			case 1:watchloginfile();break;
			case 2:watchoperationfile();break;
			case 3:watchstudentfeedbacklist();break;
			case 4:watchreplylist();break;
			case 5:deletebulletin();break;
			case 6:watchallemails();break;
			case 7:sendwarning();break;
			case 8:addclass();break;
			case 9:watchallstudents();break;
			case 10:watchallfaculty();break;
			case 11:watchclass();break;
			case 12:goto AY;
			default:
				{
					cout<<"������������Ŷ�����������룺"<<ends;
					goto AZ;
				}
		}
	}
	AY:cout<<"��л��ʹ�ý���ϵͳ����Աģʽ���ټ���"<<endl;
}
void kingerror()//�쳣����
{
	cout<<"ϵͳ�ļ��򿪳��������Զ��رգ��������뿪����Ա����ϵͳ��"<<endl;//��ܰ��ʾ
	system("pause");
	exit(0);//�˳�ϵͳ
}
void kingoperate()//����Ա״̬����ܹ�
{
	bool condition=false;
	condition=checkidentity();//������
	if(condition)//�����֤�ɹ�����������Ա����
	{
		kingfunction();
	}
}
void watchloginfile()//�鿴��½��־
{
	char title[100],time[32],user[20],type[10];
	ifstream loginfile;
	loginfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\��½��־.txt",ios::in);//��ϵͳ��½��־�ļ�
	if(!loginfile)
	{
		kingerror();//�ļ����ܴ�
	}
	loginfile.seekg(0,ios::beg);
	loginfile.getline(title,100);
	cout<<"���ڿ�ʼ��ӡ��½��¼..."<<endl;
	cout<<"��¼ʱ��"<<'\t'<<"��½��"<<'\t'<<"�û�����"<<endl;
	while(loginfile>>time>>user>>type)//��ӡ��½��¼
	{
		cout<<time<<'\t'<<user<<'\t'<<type<<endl;
	}
	loginfile.close();//�ر�ϵͳ��½��־�ļ�
	cout<<"���е�½��Ϣ��ʾ��ϣ�"<<endl;
}
void watchstudentfeedbacklist()//�鿴ѧ�������б�
{
	char title[100],name[20],time[32],content[500];
	ifstream stufeedback;
	stufeedback.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ѧ�������б�.txt",ios::in);//��ѧ�������б��ļ�
	stufeedback.seekg(0,ios::beg);
	stufeedback.getline(title,100);
	cout<<"���ڿ�ʼ��ӡδ�����ѧ�������б�..."<<endl;
	while(stufeedback>>name>>time>>content)//��ӡѧ�������б�
	{
		cout<<"==================================================================="<<endl;
		cout<<"ѧ��������"<<name<<endl;
		cout<<"����ʱ�䣺"<<time<<endl;
		cout<<"�������ݣ�"<<content<<endl;
	}
	stufeedback.close();//�ر�ѧ�������б��ļ�
	cout<<"����δ�����ѧ��������ʾ��ϣ�"<<endl;
}
void watchreplylist()//�鿴�����ظ��б�
{
	char title[100],stuname[20],stutime[32],stucontent[500],facultyname[20],facultytime[32],facultycontent[500];
	ifstream replylist;
	replylist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�����ظ��б�.txt",ios::in);//��ϵͳ�����ظ��б��ļ�
	if(!replylist)
	{
		kingerror();//�ļ����ܴ�
	}
	replylist.seekg(0,ios::beg);
	replylist.getline(title,100);
	cout<<"���ڿ�ʼ��ӡ�����ظ��б�..."<<endl;
	while(replylist>>stuname>>stutime>>stucontent>>facultyname>>facultytime>>facultycontent)//��ӡ�����ظ��б�
	{
		cout<<"========================================================================"<<endl;
		cout<<"ѧ��������"<<stuname<<endl;
		cout<<"����ʱ�䣺"<<stutime<<endl;
		cout<<"�������ݣ�"<<stucontent<<endl;
		cout<<"���ˣ�"<<facultyname<<endl;
		cout<<"��ʱ�䣺"<<facultytime<<endl;
		cout<<"�����ݣ�"<<facultycontent<<endl;
	}
	replylist.close();//�رշ����ظ��б��ļ�
	cout<<"�����Ѵ𸴵ķ�����¼��ʾ��ϣ�"<<endl;
}
void deletebulletin()//ɾ���������ϵ�����
{
	ifstream orientbulletin;
	ofstream newbulletin;
	char title[100],user[20],time[32],content[500];
	int i=0,choice,mark=0;
	struct onerecord//����һ����������¼����ڵ�ṹ
	{
		int code;
		char username[20];
		char usertime[32];
		char announcement[500];
		onerecord *next;
	};
	onerecord *head,*a,*b;
	orientbulletin.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������.txt",ios::in);//��ϵͳ�������ļ�
	if(!orientbulletin)
	{
		kingerror();//�ļ����ܴ�
	}
	orientbulletin.seekg(0,ios::beg);
	orientbulletin.getline(title,100);
	head=new onerecord;
	a=head;
	cout<<"���ڿ�ʼ��ʾ������..."<<endl;
	while(orientbulletin>>user>>time>>content)//��ӡ�������ϵ����ݲ����칫��������
	{
		cout<<"==================================================================="<<endl;
		cout<<"��ţ�"<<i+1<<endl;
		cout<<"�����ˣ�"<<user<<endl;
		cout<<"����ʱ�䣺"<<time<<endl;
		cout<<"���ݣ�"<<content<<endl;
		a->code=i-1;
		strcpy_s(a->username,user);
		strcpy_s(a->usertime,time);
		strcpy_s(a->announcement,content);
		i++;
		b=new onerecord;
		a->next=b;
		a=a->next;
		a->next=NULL;
	}
	a->next=NULL;
	a=head;
	mark=i;
	i=0;
	orientbulletin.close();//�رչ������ļ�
	while(1)
	{
		cout<<"��������Ҫɾ���Ĺ�����ţ�����-1��������"<<ends;
		BG:cin>>choice;
		clearcin();//�������
		if(choice>0)
		{
			if(choice>mark)//����ı�Ų����б�Χ��
			{
				cout<<"������ı�Ų����б��У����������룺"<<ends;
				goto BG;
			}
			choice--;
			if(choice==0)//ɾ����������
			{
				head=head->next;
				delete a;
				a=head;
			}
			else//ɾ������������
			{
				while(a->next->code!=choice)
				{
					a=a->next;
				}
				b=a->next;
				a->next=b->next;
				delete b;
				b=NULL;
			}
			cout<<"���Ϊ"<<choice+1<<"�Ĺ���ɾ���ɹ���"<<endl;
		}
		else
		{
			goto BA;
		}
	}
	BA:cout<<"��Ҫ��ɾ���ļ�¼�Ѿ�ɾ����ɣ�"<<endl;
	newbulletin.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������.txt",ios::out);//���µĹ������ļ�
	if(!newbulletin)
	{
		kingerror();//�ļ����ܴ�
	}
	newbulletin<<"������"<<'\t'<<"����ʱ��"<<'\t'<<"��������"<<'\n';//д�������
	while(a->next!=NULL)//д���µĹ������ļ�
	{
		newbulletin<<a->username<<'\t'<<a->usertime<<'\t'<<a->announcement<<'\n';
		a=a->next;
	}
	newbulletin.close();//�رչ������ļ�
	a=head;
	while(head->next!=NULL)//���ٹ���������
	{
		a=head;
		head=head->next;
		delete a;
	}
	delete head;
	a=NULL;
	head=NULL;
	cout<<"�����ɹ���"<<endl;
}
void sendwarning()//���;����ʼ�
{
	char currenttime[32],reciever[20];
	ofstream emailfile;
	emailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�����ʼ������ż���¼.txt",ios::app);//��ϵͳ�����ʼ������ż���¼�ļ�
	if(!emailfile)
	{
		kingerror();//�ļ����ܴ�
	}
	cout<<"�������ռ���������19�ַ����ڣ���"<<ends;
	cin>>reciever;//�����ռ���
	clearcin();//�������
	getlocaltime(currenttime);//��ñ���ʱ��
	emailfile<<currenttime<<'\t'<<"ϵͳ����Ա"<<'\t'<<reciever<<'\t'<<"����"<<'\t'<<"ϵͳ����Ա����Ĳ�����Ϊ�����˼�飬�����㷢���˾��棬�뾡����ϵϵͳ����Ա�����"<<'\n';//д��һ�������ʼ���¼
	emailfile.close();//�ر�ϵͳ�����ʼ��ż���¼�ļ�
	cout<<"�����ʼ����ͳɹ���"<<endl;
}
void addclass()//Ϊϵͳ��ӿγ�
{
	cout<<"���ڿ�ʼΪϵͳ����¿γ�..."<<endl;
	int choice=0;
	cout<<"������Ҫ��ӵĿ���ͨѡ������������1����������0����"<<ends;
	BK:cin>>choice;
	clearcin();//clear buff
	switch(choice)
	{
		case 1:addchooseableclass();break;//���ͨѡ��
		case 0:addordinaryclass();break;//��ӷ�ͨѡ��
		default:
			{
				cout<<"�����������������룺"<<ends;
				goto BK;
			}
	}
}
void addchooseableclass()//���ͨѡ��
{
	char code[8],classname[50],nature[20],term[10],title1[100],targetteachername[20],title2[100],title3[100];
	char number[20],name[20],gender[5],birth[11],department[50],job[10],phone[12],marry[5],homeadd[50];
	char ccode[8],cname[50],cnature[20],cterm[10];
	int totaltime,thmtime,exptime,totalpeople,leftpeople,i=0,mark=0,choice,credit;
	int ctotaltime,cthmtime,cexptime,ctotalpeople,cleftpeople,ccredit;
	int salary,age;
	ifstream teachers,teachclass,orientlist;
	ofstream chooseableclasslist,teacherclass,newscorelist,studentlist;
	teachers.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\ȫ����ְ������.txt",ios::in);//��ϵͳ���еĽ�ְ������
	if(!teachers)
	{
		kingerror();//�ļ����ܴ�
	}
	teachers.seekg(0,ios::beg);
	teachers.getline(title1,100);
	cout<<"���ڿ�ʼ��ӡ��ʦ�б������ѡ���ον�ʦ..."<<endl;
	cout<<"���"<<'\t'<<"����"<<'\t'<<"���ڲ���"<<'\t'<<"ְ��"<<endl;//��ӡ�ον�ʦ�б�
	while(teachers>>number>>name>>gender>>birth>>department>>job>>salary>>phone>>age>>marry>>homeadd)
	{
		cout<<i+1<<'\t'<<name<<'\t'<<department<<'\t'<<job<<endl;
		i++;
	}
	mark=i;
	cout<<"������Ŀ���ον�ʦ�ı�ţ�"<<ends;
	BL:cin>>choice;//�����ον�ʦ���
	clearcin();//�������
	i=0;
	if((choice<1)||(choice>mark))//�����Ų����б�Χ����
	{
		cout<<"������ı�Ų��ڽ�ʦ�б���Ŷ�����������룺"<<ends;
		goto BL;
	}
	choice--;
	teachers.close();//�رս�ʦ�б��ļ�
	teachers.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\ȫ����ְ������.txt",ios::in);//�򿪽�ְ���б��ļ�
	if(!teachers)
	{
		kingerror();//�ļ����ܴ�
	}
	teachers.seekg(0,ios::beg);
	teachers.getline(title1,100);
	while(teachers>>number>>name>>gender>>birth>>department>>job>>salary>>phone>>age>>marry>>homeadd)//����ον�ʦ�Ľ�ʦ��
	{
		if(i==choice)
		{
			strcpy_s(targetteachername,name);
			break;
		}
		i++;
	}
	teachers.close();//�رս�ʦ�����ļ�
	teachclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\�ο�.txt",ios::in);//���ο������ļ�
	if(!teachclass)
	{
		kingerror();//�ļ����ܴ�
	}
	cout<<"������γ����ƣ�19�ַ����ڣ���"<<ends;
	BM:cin>>classname;//�����¿γ�����
	clearcin();//�������
	teachclass.seekg(0,ios::beg);
	teachclass.getline(title2,100);
	while(teachclass>>name>>cname>>cnature)//�ж��Ƿ����н�ְ���ο�
	{
		if(strcmp(cname,classname)==0)//���н�ְ���ο�
		{
			cout<<"�ÿγ����н�ְ���ν̣�����������γ����ƣ�"<<ends;
			goto BM;
		}
	}
	teachclass.close();//�ر��ο�����
	orientlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ͨѡ���б�.txt",ios::in);//��ϵͳͨѡ���б�
	if(!orientlist)
	{
		kingerror();//�ļ����ܴ�
	}
	cout<<"������γ̱�ţ�7�ַ����ڣ���"<<ends;
	BN:cin>>code;//�����¿γ̱��
	clearcin();//�������
	orientlist.seekg(0,ios::beg);
	orientlist.getline(title3,100);
	while(orientlist>>ccode>>cname>>cnature>>ctotaltime>>cthmtime>>cexptime>>ccredit>>cterm>>ctotalpeople>>cleftpeople)//�жϸÿγ̱���Ƿ��ѱ�ռ��
	{
		if(strcmp(ccode,code)==0)//�γ̱�ű�ռ��
		{
			cout<<"������ı��������ͨѡ�α���غϣ����������룺"<<ends;
			goto BN;
		}
	}
	orientlist.close();//�ر�ͨѡ���б��ļ�
	cout<<"������γ����ʣ�19�ַ����ڣ���"<<ends;
	cin>>nature;//����γ�����
	clearcin();//�������
	cout<<"������ѧ������"<<ends;
	cin>>credit;//����ѧ����
	clearcin();//�������
	cout<<"�����뿪��ѧ�ڣ���/�£���"<<ends;
	cin>>term;//���뿪��ѧ��
	clearcin();//�������
	cout<<"������ÿγ̿����ɵ���������"<<ends;
	cin>>totalpeople;//����������
	clearcin();//�������
	leftpeople=totalpeople;
	cout<<"������ÿγ���ѧʱ��"<<ends;
	cin>>totaltime;//����γ���ѧʱ
	clearcin();//�������
	cout<<"��ѡ����������Ҫ�����ѧʱ��Ϣ����һ���ϵͳ�Զ����ɣ���"<<endl;
	cout<<"|1-����ѧʱ"<<endl;
	cout<<"|2-ʵ����ϻ���ѧʱ"<<endl;
	cout<<"����ѡ���ǣ�"<<ends;
	BQ:cin>>choice;//����ѡ��
	clearcin();//�������
	switch(choice)
	{
		case 1:
			{
				cout<<"���������ۿ���ѧʱ��"<<ends;
				BO:cin>>thmtime;//��������ѧʱ
				clearcin();//�������
				if(thmtime>totaltime)//���ۿ�ѧʱ��������ѧʱ��
				{
					cout<<"���ۿ���ѧʱ���ܴ�����ѧʱ�����������룺"<<ends;
					goto BO;
				}
				exptime=totaltime-thmtime;//����ʵ����ϻ�ѧʱ��
				break;
			}
		case 2:
			{
				cout<<"������ʵ����ϻ���ѧʱ��"<<ends;
				BP:cin>>exptime;//����ʵ����ϻ�ѧʱ��
				clearcin();//�������
				if(exptime>totaltime)//ʵ����ϻ�ѧʱ��������ѧʱ��
				{
					cout<<"ʵ����ϻ�����ѧʱ���ܴ�����ѧʱ�����������룺"<<ends;
					goto BP;
				}
				thmtime=totaltime-exptime;//��������ѧʱ��
				break;
			}
		default:
			{
				cout<<"������ı���������������룺"<<ends;
				goto BQ;
			}
	}
	chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ͨѡ���б�.txt",ios::app);//��ͨѡ���б�
	if(!chooseableclasslist)
	{
		kingerror();//�ļ����ܴ�
	}
	chooseableclasslist<<code<<'\t'<<classname<<'\t'<<nature<<'\t'<<totaltime<<'\t'<<thmtime<<'\t'<<exptime<<'\t'<<credit<<'\t'<<term<<'\t'<<totalpeople<<'\t'<<leftpeople<<'\n';//����һ��ͨѡ�μ�¼
	chooseableclasslist.close();//�ر�ͨѡ���б��ļ�
	teacherclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\�ο�.txt",ios::app);//���ο��б�
	if(!teacherclass)
	{
		kingerror();//�ļ����ܴ�
	}
	teacherclass<<targetteachername<<'\t'<<classname<<'\t'<<"ͨѡ"<<'\n';//д��һ���µ��ομ�¼
	teacherclass.close();//�ر��ο��б��ļ�
	char newscorelistfilename[2000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�γ̳ɼ���¼\\";//�����ɼ����ļ�
	strcat_s(newscorelistfilename,classname);
	strcat_s(newscorelistfilename,"�ɼ�.txt");
	newscorelist.open(newscorelistfilename,ios::out);
	if(!newscorelist)
	{
		kingerror();//file could not open
	}
	newscorelist<<"ѧ��"<<'\t'<<"����"<<'\t'<<"�ɼ�"<<'\n';//д�������
	newscorelist.close();//�رճɼ����ļ�
	char newstudentlistfilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�γ�ѧ������\\";//����ѧ�������ļ�
	strcat_s(newstudentlistfilename,code);
	strcat_s(newstudentlistfilename,".txt");
	studentlist.open(newstudentlistfilename,ios::out);
	if(!studentlist)
	{
		kingerror();//�ļ����ܴ�
	}
	studentlist<<"ѧ��"<<'\t'<<"ѧ������"<<'\n';//д�������
	studentlist.close();//�ر�ѧ�������ļ�
	cout<<"��ͨѡ����γɹ���"<<endl;
}
void addordinaryclass()//��ӷ�ͨѡ��
{
	ifstream teacherlist,teachclass,studentlist;
	ofstream newscorefile,newstudentlist,teacherclass;
	char classname[50],nature[20],targetteachername[20];
	char number[20],name[20],gender[5],birth[11],department[50],job[10],phone[12],marry[5],homeadd[50];
	char cname[50],cnature[20];
	char title1[100],title2[100],title3[100];
	int i=0,mark=0,choice,salary,age;
	teacherlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\ȫ����ְ������.txt",ios::in);//��ȫ����ְ�������б��ļ�
	if(!teacherlist)
	{
		kingerror();//�ļ����ܴ�
	}
	teacherlist.seekg(0,ios::beg);
	teacherlist.getline(title1,100);
	cout<<"���ڿ�ʼ��ӡϵͳ���еĽ�ְ�������Ϣ������..."<<endl;
	cout<<"���"<<'\t'<<"����"<<'\t'<<"��������"<<'\t'<<"ְ��"<<endl;
	while(teacherlist>>number>>name>>gender>>birth>>department>>job>>salary>>phone>>age>>marry>>homeadd)//��ӡ��ְ����Ϣ
	{
		cout<<i+1<<'\t'<<name<<'\t'<<department<<'\t'<<job<<endl;
		i++;
	}
	mark=i;
	i=0;
	cout<<"��ѡ����Ҫѡ��Ľ�ʦ��ţ�"<<ends;
	BR:cin>>choice;//�����ον�ʦ���
	clearcin();//�������
	choice--;
	if((choice<0)||(choice>mark-1))//��Ų����б���
	{
		cout<<"�����������Ų����б��У����������룺"<<ends;
		goto BR;
	}
	teacherlist.close();//�رս�ְ���б��ļ�
	teacherlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\ȫ����ְ������.txt",ios::in);//�򿪽�ְ���б��ļ�
	if(!teacherlist)
	{
		kingerror();//�ļ����ܴ�
	}
	teacherlist.seekg(0,ios::beg);
	teacherlist.getline(title1,100);
	while(teacherlist>>number>>name>>gender>>birth>>department>>job>>salary>>phone>>age>>marry>>homeadd)//��ȡ�ον�ʦ��
	{
		if(choice==i)
		{
			strcpy_s(targetteachername,name);
			break;
		}
		i++;
	}
	teacherlist.close();//�رս�ְ���б��ļ�
	teachclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\�ο�.txt",ios::in);//���ο��б��ļ�
	if(!teachclass)
	{
		kingerror();//�ļ����ܴ�
	}
	cout<<"������γ����ƣ�49�ַ����ڣ���"<<ends;
	BT:cin>>classname;//����γ�����
	clearcin();//�������
	teachclass.seekg(0,ios::beg);
	teachclass.getline(title2,100);
	while(teachclass>>name>>cname>>cnature)//�жϸÿγ��Ƿ��Ѿ������ν�
	{
		if(strcmp(cname,classname)==0)//�ÿγ��Ѿ������ν�
		{
			cout<<"�ÿγ��Ѿ��н�ְ���ν̣�����������γ����ƣ�"<<ends;
			goto BT;
		}
	}
	teachclass.close();//�ر��ο��б�
	cout<<"������γ����ʣ�"<<ends;
	BU:cin>>nature;//����γ�����
	clearcin();//�������
	if(strcmp(nature,"ͨѡ")==0)//�жϿγ������Ƿ�Ϊͨѡ
	{
		cout<<"��������¼���ͨѡ�Σ�����������γ����ʣ�"<<ends;
		goto BU;
	}
	teacherclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\�ο�.txt",ios::app);//���ο��б��ļ�
	if(!teacherclass)
	{
		kingerror();//�ļ����ܴ�
	}
	teacherclass<<targetteachername<<'\t'<<classname<<'\t'<<nature<<'\n';//д��һ���ομ�¼
	teacherclass.close();//�ر��ο��б��ļ�
	char newscorelistfilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�γ̳ɼ���¼\\";//����ɼ����ļ��ļ���
	strcat_s(newscorelistfilename,classname);
	strcat_s(newscorelistfilename,"�ɼ�.txt");
	newscorefile.open(newscorelistfilename,ios::out);//�򿪳ɼ����ļ�
	if(!newscorefile)
	{
		kingerror();//�ļ����ܴ�
	}
	newscorefile<<"ѧ��"<<'\t'<<"����"<<'\t'<<"�ɼ�"<<'\n';//д�������
	newscorefile.close();//�رճɼ����ļ�
	struct onestudent//����һ���Ͽ�ѧ����Ϣ��¼����ڵ�ṹ
	{
		int code;
		char stunumber[12];
		char stuname[20];
		onestudent *next;
	};
	studentlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ѧ������\\ȫ��ѧ������.txt",ios::in);//��ѧ���б��ļ�
	if(!studentlist)
	{
		kingerror();//�ļ����ܴ�
	}
	studentlist.seekg(0,ios::beg);
	studentlist.getline(title3,100);
	char newstudentlistfilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�γ�ѧ������\\";//����ѧ�������ļ���
	strcat_s(newstudentlistfilename,classname);
	strcat_s(newstudentlistfilename,"ѧ������.txt");
	newstudentlist.open(newstudentlistfilename,ios::out);//�򿪿γ�ѧ������
	if(!newstudentlist)
	{
		kingerror();//�ļ����ܴ�
	}
	newstudentlist<<"ѧ��"<<'\t'<<"ѧ������"<<'\n';//д�������
	char studentname[20],studentnumber[12],studentgender[5],studentbirth[12],studentmajor[20],studentclass[20],studenthome[50],studentdorm[50];
	int input=0,j=0,want=0;
	onestudent *head,*a,*b;
	head=new onestudent;
	a=head;
	a->next=NULL;
	cout<<"���ڿ�ʼ��ӡϵͳ���е�ȫ��ѧ����Ϣ������..."<<endl;
	cout<<"���"<<'\t'<<"����"<<'\t'<<"ѧ��"<<'\t'<<"�Ա�"<<'\t'<<"��������"<<'\t'<<"רҵ"<<'\t'<<"�༶"<<'\t'<<"��ͥסַ"<<'\t'<<"�������"<<endl;
	while(studentlist>>studentname>>studentnumber>>studentgender>>studentbirth>>studentmajor>>studentclass>>studenthome>>studentdorm)//��ӡѧ����������������
	{
		cout<<j+1<<'\t'<<studentname<<'\t'<<studentnumber<<'\t'<<studentgender<<'\t'<<studentbirth<<'\t'<<studentmajor<<'\t'<<studentclass<<'\t'<<studenthome<<'\t'<<studentdorm<<endl;
		a->code=j;
		strcpy_s(a->stuname,studentname);
		strcpy_s(a->stunumber,studentnumber);
		b=new onestudent;
		a->next=b;
		a=a->next;
		a->next=NULL;
		j++;
	}
	a->next=NULL;
	a=head;
	b=NULL;
	mark=j;
	j=0;
	studentlist.close();//�ر�ѧ�������ļ�
	while(1)
	{
		cout<<"��������Ҫ����ÿγ̵�ѧ����ţ���Ctrl+Z�������룩��"<<ends;
		BW:if(cin>>want)//�����Ͽ�ѧ���ı��
		{
			want--;
			if((want<0)||(want>mark-1))//����ı�ų����б�Χ
			{
				cout<<"������ı�Ų����б���Ŷ�����������룺"<<ends;
				goto BW;
			}
			while(a->code!=want)//����ѧ��
			{
				a=a->next;
			}
			newstudentlist<<a->stunumber<<'\t'<<a->stuname<<'\n';//д��һ���Ͽ�ѧ����¼
			a=head;
		}
		else
		{
			goto BV;
		}
	}
	BV:clearcin();//�������
	newstudentlist.close();//�رտγ�ѧ�������ļ�
	while(head->next!=NULL)//����ѧ����������
	{
		a=head;
		head=head->next;
		delete a;
	}
	delete head;
	a=NULL;
	head=NULL;
	cout<<classname<<"�γ���γɹ���"<<endl;
}
void watchallemails()//�鿴���е����ʼ���¼
{
	ifstream emailfile;
	char title[100],time[32],sender[20],reciever[20],emailtitle[50],content[500];
	emailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�����ʼ������ż���¼.txt",ios::in);//��ϵͳ�����ʼ��ż���¼�ļ�
	if(!emailfile)
	{
		kingerror();//�ļ����ܴ�
	}
	emailfile.seekg(0,ios::beg);
	emailfile.getline(title,100);
	cout<<"���ڿ�ʼ��ӡ�����ʼ���¼..."<<endl;
	while(emailfile>>time>>sender>>reciever>>emailtitle>>content)//��ӡ�����ʼ������ż���¼
	{
		cout<<"========================================================================"<<endl;
		cout<<"����ʱ�䣺"<<time<<endl;
		cout<<"�ļ��ˣ�"<<sender<<endl;
		cout<<"�ռ��ˣ�"<<reciever<<endl;
		cout<<"�ʼ����⣺"<<emailtitle<<endl;
		cout<<"�ʼ����ݣ�\n"<<content<<endl;
	}
	emailfile.close();//�رյ����ʼ��ļ�
	cout<<"�����ż�������ʾ��ϣ�"<<endl;
}
void watchallstudents()
{
	char name[20],number[12],gender[5],birth[11],major[20],class_[20],add[50],dorm[50],title[100];
	ifstream studentlist;
	studentlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ѧ������\\ȫ��ѧ������.txt",ios::in);//��ȫ��ѧ�������ļ�
	if(!studentlist)
	{
		kingerror();//�ļ����ܴ�
	}
	studentlist.seekg(0,ios::beg);
	studentlist.getline(title,100);
	cout<<"���ڿ�ʼ��ӡϵͳ����ȫ��ע���˵�ѧ������..."<<endl;
	cout<<"����"<<'\t'<<"ѧ��"<<'\t'<<"�Ա�"<<'\t'<<"��������"<<'\t'<<"רҵ"<<'\t'<<"�����༶"<<'\t'<<"��ͥ��ַ"<<'\t'<<"�������"<<endl;
	while(studentlist>>name>>number>>gender>>birth>>major>>class_>>add>>dorm)//��ӡȫ��ѧ������
	{
		cout<<name<<'\t'<<number<<'\t'<<gender<<'\t'<<birth<<'\t'<<major<<'\t'<<class_<<'\t'<<add<<'\t'<<dorm<<endl;
	}
	studentlist.close();//�ر�ѧ�������ļ�
	cout<<"����ѧ��������ӡ��ϣ�"<<endl;
}
void watchallfaculty()
{
	char number[20],name[20],gender[5],birth[11],depart[50],job[20],phone[12],marry[5],add[50],title[100];
	int wage,age;
	ifstream facultylist;
	facultylist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\ȫ����ְ������.txt",ios::in);//�򿪽�ְ�������ļ�
	if(!facultylist)
	{
		kingerror();//�ļ����ܴ�
	}
	facultylist.seekg(0,ios::beg);
	facultylist.getline(title,100);
	cout<<"���ڿ�ʼ��ӡϵͳ��ע���˵Ľ�ְ������..."<<endl;
	cout<<"���"<<'\t'<<"����"<<'\t'<<"�Ա�"<<'\t'<<"��������"<<'\t'<<"���ڲ���"<<'\t'<<"ְ��"<<'\t'<<"���ʼ���"<<'\t'<<"�绰"<<'\t'<<"����"<<'\t'<<"����״��"<<'\t'<<"��ͥסַ"<<endl;
	while(facultylist>>number>>name>>gender>>birth>>depart>>job>>wage>>phone>>age>>marry>>add)//��ӡȫ����ְ������
	{
		cout<<number<<'\t'<<name<<'\t'<<gender<<'\t'<<birth<<'\t'<<depart<<'\t'<<job<<'\t'<<wage<<'\t'<<phone<<'\t'<<age<<'\t'<<marry<<'\t'<<add<<endl;
	}
	facultylist.close();//�رս�ְ�������ļ�
	cout<<"���н�ְ��������ʾ��ϣ�"<<endl;
}
void watchclass()
{
	char teacher[20],name[50],nature[20],title[100];
	ifstream classfile;
	classfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\�ο�.txt",ios::in);//�򿪽�ʦ�ο��ļ�
	if(!classfile)
	{
		kingerror();//�ļ����ܴ�
	}
	classfile.seekg(0,ios::beg);
	classfile.getline(title,100);
	cout<<"���ڿ�ʼ��ӡ��ְ���ο����..."<<endl;
	cout<<"��ʦ"<<'\t'<<"�γ�"<<'\t'<<"����"<<endl;
	while(classfile>>teacher>>name>>nature)//��ӡ�ο����
	{
		cout<<teacher<<'\t'<<name<<'\t'<<nature<<endl;
	}
	classfile.close();//�ر��ο�����ļ�
	cout<<"�����ο������ʾ��ϣ�"<<endl;
}
#include<iostream>
#include<fstream>
#include"clarify administrator functions.h"
#include"clarify main functions.h"
#include<string.h>
#include<ctime>
using namespace std;
void teachererror()//�쳣����
{
	cout<<"ϵͳ�ļ��򿪳��������Զ��رգ��������뿪����Ա����ϵͳ��"<<endl;//exit system completely
	system("pause");
	exit(0);//ֱ���˳�ϵͳ
}
bool teacherlogin(char teachername[])//��ְ����½
{
	int teachercondition=0,teacherpasswordcondition,choice;
	char teacherpassword[20],currenttime[32];
	AE:cout<<"����������"<<ends;
	cin>>teachername;//��������
	clearcin();//�������
	cout<<"����������"<<ends;
	AD:cin>>teacherpassword;//��������
	clearcin();//�������
	if(strcmp("Admin",teachername)==0)//ʹ��Ĭ���˺ŵ�½
	{
		if(strcmp("666666",teacherpassword)==0)
			goto AC;
		else//��������
		{
			cout<<"Admin������Ϊ666666�����������룺"<<ends;
			goto AD;
		}
	}
	else
	{
		teachercondition=findfaculty(teachername);//���ҽ�ʦ�Ƿ��ڽ�ְ���б���
		if(teachercondition==0)//�Ҳ���
		{
			cout<<"�Բ�����ϵͳ����û���ҵ����ļ�¼��������Admin��½��ע�ᣡ"<<endl;
			goto AE;
		}
		else
		{
			teacherpasswordcondition=cmppassword(teachername,teacherpassword);//�Ա������Ƿ���ȷ
			if(teacherpasswordcondition==0)//�������
			{
				cout<<"�Բ������������������"<<endl;
				cout<<"������Ҫ������½�����˳���"<<endl;
				cout<<"|1-������½"<<endl;
				cout<<"|2-�˳���½"<<endl;
				cout<<"����������ѡ���ţ�"<<ends;
				AH:cin>>choice;
				clearcin();//�������
				switch(choice)
				{
					case 1:
						{
							cout<<"�������������룺"<<ends;
							goto AD;
						}
					case 2:return false;
					default:
						{
							cout<<"������������Ŷ���ǲ��ǲ������أ�����������ѣ�"<<ends;
							goto AH;
						}
				}
			}
		}
	}
	AC:cout<<"��½�ɹ���"<<endl;
	ofstream loginfile;
	loginfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\��½��־.txt",ios::app);//��ϵͳ��½��־�ļ�
	if(!loginfile)
	{
		teachererror();//�ļ����ܴ�
	}
	getlocaltime(currenttime);//��ñ���ʱ��
	loginfile<<currenttime<<'\t'<<teachername<<'\t'<<"��ְ��"<<'\n';//дһ����½��¼
	loginfile.close();//�رյ�½��־�ļ�
	cout<<teachername<<"����ӭ�㣡"<<endl;
	return true;
}
int findfaculty(char teachername[])//�жϽ�ʦ�Ƿ��ڽ�ְ���б���
{
	ifstream facultyaccountdata;
	char title[100],name[20],password[20];
	int result=0;
	facultyaccountdata.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\��ְ���˻�������.txt",ios::in);//�򿪽�ְ���˻��б��ļ�
	if(!facultyaccountdata)
	{
		teachererror();//�ļ����ܴ�
	}
	facultyaccountdata.seekg(0,ios::beg);
	facultyaccountdata.getline(title,100);
	while(facultyaccountdata>>name>>password)//��ʼ���ҽ�ʦ
	{
		if(strcmp(name,teachername)==0)//�ҵ��ý�ʦ��
		{
			result=1;
			break;
		}
	}
	return result;
}
int cmppassword(char teachername[],char teacherpassword[])//�Ա������Ƿ���ȷ
{
	ifstream accountdata;
	char title[100],tname[20],tpass[20];
	int result=0;
	accountdata.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\��ְ���˻�������.txt",ios::in);//�򿪽�ְ���˻������ļ�
	if(!accountdata)
	{
		teachererror();//�ļ����ܴ�
	}
	accountdata.seekg(0,ios::beg);
	accountdata.getline(title,100);
	while(accountdata>>tname>>tpass)//���ҽ�ʦ
	{
		if(strcmp(teachername,tname)==0)//�ҵ���ʦ
		{
			if(strcmp(tpass,teacherpassword)==0)//�Ա�����
			{
				result=1;
				break;
			}
		}
	}
	accountdata.close();//�رս�ְ���˻��ļ�
	return result;
}
void teacherfunction(char teachername[])//��ʦ����ѡ�����
{
	int choice;
	while(1)//choose function
	{
		cout<<"�����ǹ����б�����ѡ������Ҫ��������Ŀ��"<<endl;
		cout<<"|1-ע���½�ְ��"<<endl;
		cout<<"|2-ע����ѧ��"<<endl;
		cout<<"|3-�鿴���˵���"<<endl;
		cout<<"|4-ѧ���Ͽο��ڼ�¼"<<endl;
		cout<<"|5-ѧ���ɼ�¼��"<<endl;
		cout<<"|6-��������"<<endl;
		cout<<"|7-�����԰�"<<endl;
		cout<<"|8-�����ʼ�ϵͳ"<<endl;
		cout<<"|9-�޸�����"<<endl;
		cout<<"|10-�˳�"<<endl;
		cout<<"����������ѡ��"<<ends;
		AJ:cin>>choice;
		clearcin();//�������
		switch(choice)
		{
			case 1:registnewfaculty(teachername);break;
			case 2:registstudent(teachername);break;
			case 3:watchfacultyprofile(teachername);break;
			case 4:setgotoclassrecord(teachername);break;
			case 5:loadinscores(teachername);break;
			case 6:setbulletin(teachername);break;
			case 7:dealwithfeedback(teachername);break;
			case 8:facultyemail(teachername);break;
			case 9:resetfacultypassword(teachername);break;
			case 10:goto AI;
			default:
				{
					cout<<"����������Ŷ�����������룺"<<ends;
					goto AJ;
				}
		}
		cout<<endl;
	}
	AI:;
}
void registnewfaculty(char teachername[])//ע���µĽ�ְ��
{
	char facultynumber[20],facultyname[20],facultygender[5],facultybirthday[11],facultydepartment[50],facultyjob[10],facultyphone[12],facultymarry[5],facultyhomeadd[50],currenttime[32],title[100];
	int facultywagelevel,facultyage;
	char number[20],name[20],gender[5],birthday[11],department[50],job[10],phone[12],marry[5],homeadd[50];
	int wage,age;
	cout<<"�������½�ְԱ��������"<<ends;
	BX:cin>>facultyname;//�½�ְ������
	clearcin();//�������
	ifstream testfile;
	testfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\ȫ����ְ������.txt",ios::in);//��ϵͳ��ְ����½�˻��б��ļ�
	if(!testfile)
	{
		teachererror();//�ļ����ܴ�
	}
	testfile.seekg(0,ios::beg);
	testfile.getline(title,100);
	while(testfile>>number>>name>>gender>>birthday>>department>>job>>wage>>phone>>age>>marry>>homeadd)//���Ҹý�ְ���Ƿ����б���
	{
		if(strcmp(name,facultyname)==0)//�ڣ������Ѿ�ע��
		{
			testfile.close();//�رս�ְ���˻��б��ļ�
			cout<<"�ý�ְ���Ѿ�ע�ᣡ����������������"<<ends;
			goto BX;
		}
	}
	testfile.close();//�رս�ְ���˻��б��ļ�
	ofstream newfacultyprofile,operationfile;
	cout<<"������"<<facultyname<<"�ı�ţ�"<<ends;
	CA:cin>>facultynumber;//�����½�ְԱ�����
	clearcin();//�������
	testfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\ȫ����ְ������.txt",ios::in);//��ϵͳ��ְ����½�˻��б��ļ�
	if(!testfile)
	{
		teachererror();//�ļ����ܴ�
	}
	testfile.seekg(0,ios::beg);
	testfile.getline(title,100);
	while(testfile>>number>>name>>gender>>birthday>>department>>job>>wage>>phone>>age>>marry>>homeadd)//�жϸñ���Ƿ��ѱ�ʹ��
	{
		if(strcmp(number,facultynumber)==0)//�ñ���ѱ�ʹ��
		{
			testfile.close();//�رս�ְ���˻���Ϣ�ļ�
			cout<<"��ְ������ѱ�ռ�ã������������ţ�"<<ends;
			goto CA;
		}
	}
	testfile.close();//�رս�ְ���˻���Ϣ�ļ�
	cout<<"������"<<facultyname<<"���Ա���/Ů����"<<ends;
	cin>>facultygender;//�����½�ְ���Ա�
	clearcin();//�������
	cout<<"������"<<facultyname<<"�ĳ�������(yyyy-mm-dd)��"<<ends;
	cin>>facultybirthday;//�����½�ְ����������
	clearcin();//�������
	cout<<"������"<<facultyname<<"�����ڲ��ţ�"<<ends;
	cin>>facultydepartment;//�����½�ְ�����ڲ���
	clearcin();//�������
	cout<<"������"<<facultyname<<"��ְ�ƣ�"<<ends;
	cin>>facultyjob;//�����½�ְ����ְ��
	clearcin();//�������
	cout<<"������"<<facultyname<<"�Ĺ��ʼ���"<<ends;
	cin>>facultywagelevel;//�����½�ְ���Ĺ��ʼ���
	clearcin();//�������
	cout<<"������"<<facultyname<<"�ĵ绰��"<<ends;
	CB:cin>>facultyphone;//�����½�ְ���ĵ绰����
	clearcin();//�������
	testfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\ȫ����ְ������.txt",ios::in);//��ϵͳ��ְ�������ļ�
	if(!testfile)
	{
		teachererror();//�ļ����ܴ�
	}
	testfile.seekg(0,ios::beg);
	testfile.getline(title,100);
	while(testfile>>number>>name>>gender>>birthday>>department>>job>>wage>>phone>>age>>marry>>homeadd)
	{
		if(strcmp(phone,facultyphone)==0)//�绰���뱻ʹ��
		{
			testfile.close();//�رս�ְ���˻���Ϣ�ļ�
			cout<<"�õ绰�����ѱ�ռ�ã�����������绰���룺"<<ends;
			goto CB;
		}
	}
	testfile.close();//�رս�ְ���˻���Ϣ�ļ�
	cout<<"������"<<facultyname<<"�����䣺"<<ends;
	cin>>facultyage;//�����½�ְ������
	clearcin();//�������
	cout<<"������"<<facultyname<<"�Ļ���״����"<<ends;
	cin>>facultymarry;//�����½�ְ���Ļ���״��
	clearcin();//�������
	cout<<"������"<<facultyname<<"�ļ�ͥסַ��"<<ends;
	cin>>facultyhomeadd;//�����½�ְ���ļ�ͥ��ַ
	clearcin();//�������
	newfacultyprofile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\ȫ����ְ������.txt",ios::app);//��ϵͳ��ְ�������ļ��������
	if(!newfacultyprofile)
	{
		teachererror();//�ļ����ܴ�
	}
	getlocaltime(currenttime);//��ñ���ʱ��
	newfacultyprofile<<facultynumber<<'\t'<<facultyname<<'\t'<<facultygender<<'\t'<<facultybirthday<<'\t'<<facultydepartment<<'\t'<<facultyjob<<'\t'<<facultywagelevel<<'\t'<<facultyphone<<'\t'<<facultyage<<'\t'<<facultymarry<<'\t'<<facultyhomeadd<<'\n';//д���µĽ�ְ����¼
	newfacultyprofile.close();//close file
	newfacultyprofile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\��ְ���˻�������.txt",ios::app);//�򿪽�ְ���˻������ļ�
	if(!newfacultyprofile)
	{
		teachererror();//�ļ����ܴ�
	}
	newfacultyprofile<<facultyname<<'\t'<<"666666"<<'\n';//д��һ���µĽ�ְ���˻���Ϣ
	newfacultyprofile.close();//�رս�ְ���˻������ļ�
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		teachererror();//�ļ����ܴ�
	}
	operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"�����˽�ְ���˻�"<<facultyname<<'\n';//д��һ��������¼
	operationfile.close();//�ر�ϵͳ������־�ļ�
	cout<<"��ְ��"<<facultyname<<"ע��ɹ������ʼ�˻�����Ϊ666666�������Ѹ�ְ�������޸����룡"<<endl;//��ܰ��ʾ
}
void registstudent(char teachername[])//ע����ѧ��
{
	ofstream operationfile,newstudentprofile,newscorefile;
	ifstream testfile;
	char studentname[20],studentnumber[12],studentgender[5],studentbirthday[11],studentmajor[20],studentclass[20],studentadd[50],studentdorm[50],currenttime[32];
	char title[100],name[20],number[12],gender[5],birthday[11],major[20],class_[20],address[50],dorm[50];
	cout<<"��������Ҫע���ѧ��������"<<ends;
	BY:cin>>studentname;//������ѧ������
	clearcin();//�������
	testfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ѧ������\\ȫ��ѧ������.txt",ios::in);//��ϵͳѧ�������ļ�
	if(!testfile)
	{
		teachererror();//�ļ����ܴ�
	}
	testfile.seekg(0,ios::beg);
	testfile.getline(title,100);
	while(testfile>>name>>number>>gender>>birthday>>major>>class_>>address>>dorm)//�жϸ�ѧ���Ƿ��ѱ�ע��
	{
		if(strcmp(name,studentname)==0)//��ѧ���ѱ�ע��
		{
			testfile.close();//�ر�ѧ���б��ļ�
			cout<<"��ѧ���Ѿ�ע�ᣡ����������������19�ַ����ڣ���"<<ends;
			goto BY;
		}
	}
	testfile.close();//�ر�ѧ���б��ļ�
	cout<<"������"<<studentname<<"��ѧ�ţ�11�ַ����ڣ���"<<ends;
	BZ:cin>>studentnumber;//������ѧ��ѧ��
	clearcin();//�������
	testfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ѧ������\\ȫ��ѧ������.txt",ios::in);//��ϵͳѧ���б��ļ�
	if(!testfile)
	{
		teachererror();//�ļ����ܴ�
	}
	testfile.seekg(0,ios::beg);
	testfile.getline(title,100);
	while(testfile>>name>>number>>gender>>birthday>>major>>class_>>address>>dorm)//�жϸ�ѧ���Ƿ��ѱ�ʹ��
	{
		if(strcmp(number,studentnumber)==0)//��ѧ���ѱ�ʹ��
		{
			testfile.close();//�ر�ѧ���б��ļ�
			cout<<"��ѧ���ѱ�ռ�ã�����������ѧ�ţ�"<<ends;
			goto BZ;
		}
	}
	testfile.close();//�ر�ѧ���б��ļ�
	cout<<"������"<<studentname<<"���Ա���/Ů����"<<ends;
	cin>>studentgender;//������ѧ���Ա�
	clearcin();//�������
	cout<<"������"<<studentname<<"�ĳ�������(yyyy-mm-dd)��"<<ends;
	cin>>studentbirthday;//������ѧ����������
	clearcin();//�������
	cout<<"������"<<studentname<<"��רҵ��"<<ends;
	cin>>studentmajor;//������ѧ����רҵ
	clearcin();//�������
	cout<<"������"<<studentname<<"�İ༶��"<<ends;
	cin>>studentclass;//������ѧ�������༶
	clearcin();//�������
	cout<<"������"<<studentname<<"�ļ�ͥסַ��"<<ends;
	cin>>studentadd;
	clearcin();//clear buff
	cout<<"������"<<studentname<<"�������ַ��"<<ends;
	cin>>studentdorm;//������ѧ�������ַ
	clearcin();//�������
	getlocaltime(currenttime);//��ñ���ʱ��
	newstudentprofile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ѧ������\\ȫ��ѧ������.txt",ios::app);//��ϵͳȫ��ѧ�������ļ�
	if(!newstudentprofile)
	{
		teachererror();//�ļ����ܴ�
	}
	newstudentprofile<<studentname<<'\t'<<studentnumber<<'\t'<<studentgender<<'\t'<<studentbirthday<<'\t'<<studentmajor<<'\t'<<studentclass<<'\t'<<studentadd<<'\t'<<studentdorm<<'\n';//д��һ���µ�ѧ����¼
	newstudentprofile.close();//�ر�ѧ�������б��ļ�
	newstudentprofile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ѧ���˻�������.txt",ios::app);//��ϵͳѧ���˻������ļ�
	if(!newstudentprofile)
	{
		teachererror();//�ļ����ܴ�
	}
	newstudentprofile<<studentname<<'\t'<<"666666"<<'\n';//д����ѧ���˻�������Ϊ666666
	newstudentprofile.close();//�ر�ѧ���˻������ļ�
	char newscorefilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ѧ������\\";//׼���ɼ��ļ�·��
	strcat_s(newscorefilename,studentname);//����ɼ��ļ�·��
	strcat_s(newscorefilename,"ѧ���ɼ�.txt");
	newscorefile.open(newscorefilename,ios::out);//�½�ѧ���ɼ��ļ�
	if(!newscorefile)
	{
		teachererror();//�ļ����ܴ�
	}
	newscorefile<<"�γ�����"<<'\t'<<"�ɼ�"<<'\n';
	newscorefile.close();//�ر��½���ѧ���ɼ��ļ�
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		teachererror();//�ļ��޷���
	}
	operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"ע����ѧ��"<<studentname<<'\n';//д��һ��������¼
	operationfile.close();//�ر�ϵͳ������־�ļ�
	cout<<"ѧ��"<<studentname<<"ע��ɹ�����ʼ����Ϊ666666���뼰ʱ��ϵ��ѧ���޸����룡"<<endl;//��ܰ��ʾ
}
void watchfacultyprofile(char teachername[])//�鿴��ְ�����˵���
{
	ofstream operationfile;
	ifstream facultyprofile;
	char title[100],number[20],name[20],gender[5],birthday[11],department[50],job[10],phone[12],marry[5],homeadd[50],currenttime[32];
	int age,wagelevel,choice;
	facultyprofile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\ȫ����ְ������.txt",ios::in);//�򿪽�ְ�������ļ�
	if(!facultyprofile)
	{
		teachererror();//�ļ����ܴ�
	}
	facultyprofile.seekg(0,ios::beg);
	facultyprofile.getline(title,100);
	getlocaltime(currenttime);
	cout<<"���ڿ�ʼ��ӡ��ĸ��˵���..."<<endl;
	while(facultyprofile>>number>>name>>gender>>birthday>>department>>job>>wagelevel>>phone>>age>>marry>>homeadd)//������ְ��
	{
		if(strcmp(name,teachername)==0)//�ҵ��ý�ְ��
		{
			cout<<"��ţ�"<<number<<endl;
			cout<<"�Ա�"<<gender<<endl;
			cout<<"���գ�"<<birthday<<endl;
			cout<<"���ڲ��ţ�"<<department<<endl;
			cout<<"ְ��"<<job<<endl;
			cout<<"����ˮƽ��"<<wagelevel<<endl;
			cout<<"�绰���룺"<<phone<<endl;
			cout<<"���䣺"<<age<<endl;
			cout<<"����״����"<<marry<<endl;
			cout<<"��ͥ��ַ��"<<homeadd<<endl;
			break;
		}
	}
	facultyprofile.close();//�رս�ְ�������ļ�
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		teachererror();//�ļ����ܴ�
	}
	operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"�鿴���˵���"<<'\n';//д��һ��������¼
	operationfile.close();//�ر�ϵͳ������־�ļ�
	cout<<"���˵�����ʾ��ϣ�"<<endl;
	cout<<"���Ƿ���Ҫ�޸ĵ�������������1����������0����"<<ends;
	AK:cin>>choice;//�����Ƿ�ѡ���޸ĵ���
	clearcin();//�������
	switch(choice)
	{
		case 1:resetfacultyprofile(teachername);break;//�޸ĵ���
		case 0:break;
		default:
			{
				cout<<"������������Ŷ�����������룺"<<ends;
				goto AK;
			}
	}
}
void resetfacultyprofile(char teachername[])//�޸ĸ��˵���
{
	ifstream orientfile;
	ofstream operationfile,newfile;
	char number[20],name[20],gender[5],birthday[11],department[50],job[10],phone[12],marry[5],homeaddress[50],currenttime[32],title[100];
	int wagelevel,age,choice;
	struct facultyprofile//�����ְ����������ڵ�ṹ
	{
		char num[20];
		char fname[20];
		char sex[5];
		char birth[11];
		char depart[50];
		char fjob[10];
		int wage;
		char tel[12];
		int fage;
		char marriage[5];
		char address[50];
		facultyprofile *next;
	};
	facultyprofile *head,*a,*b;
	orientfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\ȫ����ְ������.txt",ios::in);
	if(!orientfile)
	{
		teachererror();//file could not open
	}
	orientfile.seekg(0,ios::beg);
	orientfile.getline(title,100);
	head=new facultyprofile;
	a=head;
	while(orientfile>>number>>name>>gender>>birthday>>department>>job>>wagelevel>>phone>>age>>marry>>homeaddress)//������ְ��������Ϣ����
	{
		strcpy_s(a->num,number);
		strcpy_s(a->fname,name);
		strcpy_s(a->sex,gender);
		strcpy_s(a->birth,birthday);
		strcpy_s(a->depart,department);
		strcpy_s(a->fjob,job);
		a->wage=wagelevel;
		strcpy_s(a->tel,phone);
		a->fage=age;
		strcpy_s(a->marriage,marry);
		strcpy_s(a->address,homeaddress);
		b=new facultyprofile;
		a->next=b;
		a=a->next;
		a->next=NULL;
	}
	a->next=NULL;
	a=head;
	orientfile.close();//�رս�ְ�������б��ļ�
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		teachererror();//�ļ����ܴ�
	}
	newfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\ȫ����ְ������.txt",ios::out);//���½�ְ�������б��ļ�
	if(!newfile)
	{
		teachererror();//�ļ����ܴ�
	}
	while(strcmp(a->fname,teachername)!=0)//���Ҹý�ְ��
	{
		a=a->next;
	}
	while(1)//��ʼ�޸ĸ��˵���
	{
		cout<<"��ѡ������Ҫ�޸ĵ�ѡ�"<<endl;
		cout<<"|1-�Ա�"<<endl;
		cout<<"|2-��������"<<endl;
		cout<<"|3-��������"<<endl;
		cout<<"|4-ְ��"<<endl;
		cout<<"|5-���ʼ���"<<endl;
		cout<<"|6-�绰"<<endl;
		cout<<"|7-����"<<endl;
		cout<<"|8-����״��"<<endl;
		cout<<"|9-��ͥסַ"<<endl;
		cout<<"|10-�˳��޸�״̬"<<endl;
		cout<<"����ѡ���ǣ�"<<ends;
		AN:cin>>choice;
		clearcin();//�������
		switch(choice)
		{
			case 1:
				{
					cout<<"�������������Ա���/Ů����"<<ends;
					cin>>gender;//�������Ա�
					clearcin();//�������
					strcpy_s(a->sex,gender);
					getlocaltime(currenttime);//��ñ���ʱ��
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"�޸ĸ��˵���--�Ա�"<<'\n';//д��һ��������¼
					break;
				}
			case 2:
				{
					cout<<"�����������³������ڣ�yyyy-mm-dd����"<<endl;
					cin>>birthday;//�����³�������
					clearcin();//�������
					strcpy_s(a->birth,birthday);
					getlocaltime(currenttime);//��ñ���ʱ��
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"�޸ĸ��˵���--��������"<<'\n';//д��һ��������¼
					break;
				}
			case 3:
				{
					cout<<"�������������������ţ�49�ַ����ڣ���"<<ends;
					cin>>department;//��������������
					clearcin();//�������
					strcpy_s(a->depart,department);
					getlocaltime(currenttime);//��ñ���ʱ��
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"�޸ĸ��˵���--���ڲ���"<<'\n';//д��һ��������¼
					break;
				}
			case 4:
				{
					cout<<"������������ְ�ƣ�9�ַ����ڣ���"<<ends;
					cin>>job;//������ְ��
					clearcin();//�������
					strcpy_s(a->fjob,job);
					getlocaltime(currenttime);//��ñ���ʱ��
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"�޸ĸ��˵���--ְ��"<<'\n';//д��һ��������¼
					break;
				}
			case 5:
				{
					cout<<"�����������¹���ˮƽ��"<<ends;
					cin>>wagelevel;//�����µĹ���ˮƽ
					clearcin();//�������
					a->wage=wagelevel;
					getlocaltime(currenttime);//��ñ���ʱ��
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"�޸ĸ��˵���--����ˮƽ"<<'\n';//д��һ��������¼
					break;
				}
			case 6:
				{
					cout<<"�����������µ绰��11�ַ����ڣ���"<<ends;
					cin>>phone;//�����µ绰
					clearcin();//�������
					strcpy_s(a->tel,phone);
					getlocaltime(currenttime);//��ñ���ʱ��
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"�޸ĸ��˵���--�绰"<<'\n';//д��һ���¼�¼
					break;
				}
			case 7:
				{
					cout<<"���������������䣺"<<ends;
					cin>>age;//����������
					clearcin();//�������
					a->fage=age;
					getlocaltime(currenttime);
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"�޸ĸ��˵���--����"<<'\n';
					break;
				}
			case 8:
				{
					cout<<"�����������»���״����4�ַ����ڣ���"<<ends;
					cin>>marry;//�����»���״��
					clearcin();//�������
					strcpy_s(a->marriage,marry);
					getlocaltime(currenttime);//��ñ���ʱ��
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"�޸ĸ��˵���--����״��"<<'\n';//д��һ��������¼
					break;
				}
			case 9:
				{
					cout<<"�����������¼�ͥסַ��49�ַ����ڣ���"<<ends;
					cin>>homeaddress;//�����¼�ͥ��ַ
					clearcin();//�������
					strcpy_s(a->address,homeaddress);
					getlocaltime(currenttime);//��ñ���ʱ��
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"�޸ĸ��˵���--��ͥסַ"<<'\n';//д��һ���¼�¼
					break;
				}
			case 10:
				{
					goto AM;
				}
			default:
				{
					cout<<"�������������������룺"<<ends;
					goto AN;
				}
		}
	}
	AM:a=head;
	operationfile.close();//�ر�ϵͳ������־�ļ�
	newfile<<"���"<<'\t'<<"����"<<'\t'<<"�Ա�"<<'\t'<<"��������"<<'\t'<<"���ڲ���"<<'\t'<<"ְ��"<<'\t'<<"���ʼ���"<<'\t'<<"�绰"<<'\t'<<"����"<<'\t'<<"����״��"<<'\t'<<"��ͥסַ"<<'\n';//д�������
	while(a->next!=NULL)//д���µĽ�ְ�������б�
	{
		newfile<<a->num<<'\t'<<a->fname<<'\t'<<a->sex<<'\t'<<a->birth<<'\t'<<a->depart<<'\t'<<a->fjob<<'\t'<<a->wage<<'\t'<<a->tel<<'\t'<<a->fage<<'\t'<<a->marriage<<'\t'<<a->address<<'\n';
		a=a->next;
	}
	newfile.close();//�رս�ְ�������б��ļ�
	a=head;
	while(head->next!=NULL)//���ٽ�ְ����������
	{
		a=head;
		head=head->next;
		delete a;
	}
	delete head;
	a=NULL;
	head=NULL;
	cout<<"�����޸���ɣ�"<<endl;
}
void setgotoclassrecord(char teachername[])//���ÿ��ڼ�¼
{
	ifstream myclass,classstudents;
	ofstream operationfile,gotoclassrecord;
	char currenttime[32],title1[100],teachname[20],classname[50],title2[100],nature[20];
	int i=0,mark=0;
	cout<<"��ӭʹ�ÿ��ڼ�¼ϵͳ..."<<endl;
	myclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\�ο�.txt",ios::in);//����ϵͳ�ο������ļ�
	if(!myclass)
	{
		teachererror();//�ļ����ܴ�
	}
	myclass.seekg(0,ios::beg);
	myclass.getline(title1,100);
	cout<<teachername<<"���������¿γ̿��Խ��п��ڼ�¼��"<<endl;
	while(myclass>>teachname>>classname>>nature)//��ӡ���Կ��ڵĿγ�����
	{
		if(strcmp(teachname,teachername)==0)
		{
			cout<<"|"<<i+1<<"-"<<classname<<endl;
			i++;
		}
	}
	myclass.close();//�ر��ο������ļ�
	if(i==0)//û���ν��κογ�
	{
		cout<<"��û���ν��κογ̣�"<<endl;
	}
	else
	{
		mark=i;
		myclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\�ο�.txt",ios::in);//���ο������ļ�
		if(!myclass)
		{
			teachererror();//�ļ����ܴ�
		}
		char wantclass[50],studentnumber[20],studentname[20],conditionstr[5],classtime[11],cnature[20];
		int condition=0,want;
		while(1)
		{
			cout<<"����������Ҫ���п��ڵİ༶���ţ���Ctrl+Z�˳�����"<<ends;//��ʼ����
			BE:if(cin>>want)
			{
				clearcin();//�������
				if((want>mark)||(want<1))//�����Ų����б�Χ��
				{
					cout<<"������ı�Ų����б��У����������룺"<<ends;
					goto BE;
				}
				myclass.seekg(0,ios::beg);
				myclass.getline(title1,100);
				i=0;
				while(myclass>>teachname>>classname>>nature)//���Ҹÿγ�
				{
					if(strcmp(teachname,teachername)==0)//�ҵ��ον�ʦ
					{
						if(i==want-1)//�ҵ�Ŀ��γ�
						{
							strcpy_s(wantclass,classname);
							strcpy_s(cnature,nature);
							break;
						}
						i++;
					}
				}
				myclass.close();//�ر��ο��б��ļ�
				getlocaltime(currenttime);//��ñ���ʱ��
				cout<<"�������Ͽ����ڣ�"<<ends;
				cin>>classtime;//�����Ͽ�����
				clearcin();//�������
				char classstulistfilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�γ�ѧ������\\";//׼���γ�ѧ�������ļ���
				if(strcmp(cnature,"ͨѡ")==0)//�ÿγ�Ϊͨѡ��
				{
					char ccode[8],cname[50],cn[20],cterm[10],targetcode[8],title4[100];
					int ctotaltime,ctheorytime,cexptime,ccredit,ctotalpeople,cleftpeople;
					ifstream chooseableclasslist;
					chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ͨѡ���б�.txt",ios::in);//��ͨѡ���б��ļ�
					if(!chooseableclasslist)
					{
						teachererror();//�ļ����ܴ�
					}
					chooseableclasslist.seekg(0,ios::beg);
					chooseableclasslist.getline(title4,100);
					while(chooseableclasslist>>ccode>>cname>>cn>>ctotaltime>>ctheorytime>>cexptime>>ccredit>>cterm>>ctotalpeople>>cleftpeople)//���Ҷ�Ӧ�γ̵�ͨѡ�α��
					{
						if(strcmp(cname,wantclass)==0)//�ҵ��ÿγ�
						{
							strcpy_s(targetcode,ccode);
							break;
						}
					}
					chooseableclasslist.close();//�ر�ͨѡ���б��ļ�
					strcat_s(classstulistfilename,targetcode);//�����γ�ѧ�������ļ���
					strcat_s(classstulistfilename,".txt");
				}
				else
				{
					strcat_s(classstulistfilename,wantclass);//�����γ�ѧ�������ļ���
					strcat_s(classstulistfilename,"ѧ������.txt");
				}
				classstudents.open(classstulistfilename,ios::in);//�򿪿γ�ѧ�������ļ�
				gotoclassrecord.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�γ̿��ڼ�¼.txt",ios::app);//��ϵͳ���ڼ�¼�ļ�
				if(!gotoclassrecord)
				{
					teachererror();//�ļ����ܴ�
				}
				if(!classstudents)
				{
					teachererror();//�ļ����ܴ�
				}
				classstudents.seekg(0,ios::beg);
				classstudents.getline(title2,100);
				cout<<wantclass<<"�γ�ѧ�����������룬��ʼ¼�뿼�����..."<<endl;
				cout<<"����״̬��Ӧ����"<<endl;
				cout<<"|0-����"<<endl;
				cout<<"|1-����"<<endl;
				cout<<"|2-���"<<endl;
				cout<<"�밴������Ĺ������¼�룡"<<endl;
				cout<<"��ʼ¼��..."<<endl;
				while(classstudents>>studentnumber>>studentname)//¼�뿼��״̬
				{
					cout<<"ѧ��Ϊ"<<studentnumber<<"��ѧ����"<<studentname<<"���Ŀ������Ϊ��"<<ends;
					AO:cin>>condition;//¼�뵥��ѧ������״��
					clearcin();//�������
					switch(condition)
					{
						case 0:
							{
								strcpy_s(conditionstr,"����");
								break;
							}
						case 1:
							{
								strcpy_s(conditionstr,"����");
								break;
							}
						case 2:
							{
								strcpy_s(conditionstr,"���");
								break;
							}
						default:
							{
								cout<<"���������������������룺"<<ends;
								goto AO;
							}
					}
					gotoclassrecord<<studentnumber<<'\t'<<studentname<<'\t'<<wantclass<<'\t'<<teachername<<'\t'<<classtime<<'\t'<<conditionstr<<'\n';//д��һ�����ڼ�¼
				}
				cout<<wantclass<<classtime<<"�տο������¼����ɣ�"<<endl;
				classstudents.close();//�ر�ѧ�������ļ�
				gotoclassrecord.close();//�ر�ϵͳ���ڼ�¼�ļ�
				operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
				if(!operationfile)
				{
					teachererror();//�ļ����ܴ�
				}
				operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"¼��"<<classtime<<"��"<<wantclass<<"�γ�ѧ���������"<<'\n';//д��һ��������־
				operationfile.close();//�ر�ϵͳ������־�ļ�
			}
			else
			{
				goto BC;
			}
		}
		BC:clearcin();//�������
		cout<<"�������¼��ɹ���"<<endl;
	}
}
void loadinscores(char teachername[])//¼��γ̳ɼ�
{
	ofstream operationfile,studentscorefile,systemscorefile;
	ifstream myclass,classstudentlist,chooseableclasslist;
	char classname[50],title1[100],teachname[20],wantclass[50],currenttime[32],classnature[20],nature[20],title2[100],title3[100];
	int i=0,want,mark=0;
	myclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\�ο�.txt",ios::in);//���ο������ļ�
	if(!myclass)
	{
		teachererror();//�ļ����ܴ�
	}
	myclass.seekg(0,ios::beg);
	myclass.getline(title1,100);
	cout<<teachername<<"���������¿γ̿��Խ��гɼ�¼�룺"<<endl;
	while(myclass>>teachname>>classname>>classnature)//��ӡ�ο�����
	{
		if(strcmp(teachername,teachname)==0)
		{
			cout<<"|"<<i+1<<"-"<<classname<<endl;
			i++;
		}
	}
	myclass.close();//�ر��ο�����
	if(i==0)//û���ο�
	{
		cout<<"��û���ν��κογ̣�"<<endl;
	}
	else
	{
		mark=i;
		myclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\��ְ������\\�ο�.txt",ios::in);//���ο������ļ�
		if(!myclass)
		{
			teachererror();//�ļ����ܴ�
		}
		char studentlistfilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�γ�ѧ������\\";//׼���γ�ѧ�������ļ���
		char sysfilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�γ̳ɼ���¼\\";//׼��ϵͳ�γ̳ɼ���¼�ļ��ļ���
		char stufilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ѧ������\\";//׼��ѧ�����˳ɼ���¼�ļ��ļ���
		int score=0;
		while(1)
		{
			cout<<"����������Ҫ����¼��ɼ��Ŀγ̴��ţ���Ctrl+Z�˳�����"<<ends;//¼��γ̳ɼ�
			BF:if(cin>>want)
			{
				clearcin();//�������
				if((want>mark)||(want<1))//��������
				{
					cout<<"���������Ų��ڸ÷�Χ�ڣ����������룺"<<ends;
					goto BF;
				}
				myclass.seekg(0,ios::beg);
				myclass.getline(title1,100);
				i=0;
				while(myclass>>teachname>>classname>>classnature)//����Ŀ��γ�
				{
					if(strcmp(teachname,teachername)==0)//�ҵ��ον�ʦ
					{
						if(i==want-1)//�ҵ��ÿγ�
						{
							strcpy_s(wantclass,classname);
							strcpy_s(nature,classnature);
							break;
						}
						i++;
					}
				}
				strcat_s(sysfilename,wantclass);//����ϵͳѧ���ɼ���¼�ļ��ļ���
				strcat_s(sysfilename,"�ɼ�.txt");
				if(strcmp(nature,"ͨѡ")==0)//�ÿγ�����Ϊͨѡ
				{
					chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ͨѡ���б�.txt",ios::in);//��ͨѡ���б��ļ�
					if(!chooseableclasslist)
					{
						teachererror();//�ļ����ܴ�
					}
					chooseableclasslist.seekg(0,ios::beg);
					chooseableclasslist.getline(title2,100);
					char ccode[8],cname[50],cnature[20],cterm[10],targetcode[8];
					int ctotaltime,ctheorytime,cexptime,ccredit,ctotalpeople,cleftpeople;
					while(chooseableclasslist>>ccode>>cname>>cnature>>ctotaltime>>ctheorytime>>cexptime>>ccredit>>cterm>>ctotalpeople>>cleftpeople)//���Ҹÿγ̱��
					{
						if(strcmp(cname,wantclass)==0)//�ҵ��ÿγ�
						{
							strcpy_s(targetcode,ccode);
							break;
						}
					}
					strcat_s(studentlistfilename,targetcode);//�����ÿγ�ѧ�������ļ���
					strcat_s(studentlistfilename,".txt");
				}
				else//�ÿγ̲���ͨѡ��
				{
					strcat_s(studentlistfilename,wantclass);//�����ÿγ�ѧ�������ļ���
					strcat_s(studentlistfilename,"ѧ������.txt");
				}
				classstudentlist.open(studentlistfilename,ios::in);//�򿪿γ�ѧ�������ļ�
				if(!classstudentlist)
				{
	
					teachererror();//�ļ����ܴ�
				}
				classstudentlist.seekg(0,ios::beg);
				classstudentlist.getline(title3,100);
				systemscorefile.open(sysfilename,ios::app);//��ϵͳѧ���ɼ���¼�ļ�
				if(!systemscorefile)
				{
					teachererror();//�ļ����ܴ�
				}
				cout<<"�γ�ѧ�����������룬���ڿ�ʼ¼��ɼ�..."<<endl;
				char studnumber[12],studname[20];
				while(classstudentlist>>studnumber>>studname)//��ʼ����¼��ɼ�
				{
					strcat_s(stufilename,studname);//����ѧ�����˳ɼ���¼�ļ��ļ���
					strcat_s(stufilename,"ѧ���ɼ�.txt");
					studentscorefile.open(stufilename,ios::app);//��ѧ�����˳ɼ���¼�ļ�
					if(!studentscorefile)
					{
						teachererror();//�ļ����ܴ�
					}
					cout<<"ѧ��Ϊ"<<studnumber<<"��ѧ��"<<studname<<"���ſεĳɼ�Ϊ��"<<ends;
					cin>>score;//����ɼ�
					clearcin();//�������
					studentscorefile<<wantclass<<'\t'<<score<<'\n';//д����ſγɼ�
					studentscorefile.close();//�ر�ѧ�����˳ɼ���¼�ļ�
					systemscorefile<<studnumber<<'\t'<<studname<<'\t'<<score<<'\n';//��ϵͳ�ɼ���¼�ļ�����д��γ̳ɼ�
				}
				systemscorefile.close();//�ر�ϵͳ�ɼ���¼�ļ�
				getlocaltime(currenttime);//��ñ���ʱ��
				operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
				if(!operationfile)
				{
					teachererror();//�ļ����ܴ�
				}
				operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"¼��"<<wantclass<<"�γ�ѧ���ɼ�"<<'\n';//д��һ��������¼
				operationfile.close();//�ر��ļ�
				cout<<wantclass<<"�γ̳ɼ�¼����ɣ�"<<endl;
			}
			else
			{
				goto BD;
			}
		}
		BD:clearcin();//�������
		myclass.close();//�ر��ο��б��ļ�
		cout<<"�ɼ�¼����ɣ�"<<endl;
	}
}
void setbulletin(char teachername[])
{
	ofstream operationfile,allbulletin;
	allbulletin.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������.txt",ios::app);//�򿪹������ļ�
	if(!allbulletin)
	{
		teachererror();//�ļ����ܴ�
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		teachererror();//�ļ����ܴ�
	}
	char content[500],currenttime[32];
	int choice=0;
	AP:cout<<"�����빫�����ݣ�499�ַ����ڣ���"<<ends;
	cin>>content;//���빫������
	clearcin();//�������
	getlocaltime(currenttime);//��õ���ʱ��
	allbulletin<<teachername<<'\t'<<currenttime<<'\t'<<content<<'\n';//д�빫������
	operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"��������"<<'\n';//д��һ��������¼
	cout<<"����Ҫ��������������Ҫ������1����������0����"<<ends;
	AQ:cin>>choice;
	clearcin();//�������
	switch(choice)
	{
		case 1:goto AP;//������������
		case 0:break;
		default:
			{
				cout<<"���������������������룺"<<ends;
				goto AQ;
			}
	}
	allbulletin.close();//�رչ������ļ�
	operationfile.close();//�ر�ϵͳ������־�ļ�
	cout<<"���淢����ɣ�"<<endl;
}
void dealwithfeedback(char teachername[])
{
	ifstream orientlist;
	ofstream operationfile,newlist,replylist;
	char title1[100],stuname[20],feedtime[32],feedcontent[500],content[500],currenttime[32];
	int i=0,choice,mark=0;
	struct onerecord//����һ��ѧ��������¼������ڵ�ṹ
	{
		int code;
		char studentname[20];
		char feedbacktime[32];
		char feedbackcontent[500];
		onerecord *next;
	};
	onerecord *head,*a,*b;
	head=new onerecord;
	a=head;
	orientlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ѧ�������б�.txt",ios::in);//��ѧ�������б��ļ�
	if(!orientlist)
	{
		teachererror();//�ļ����ܴ�
	}
	orientlist.seekg(0,ios::beg);
	orientlist.getline(title1,100);
	cout<<"ѧ�������б����£�"<<endl;
	while(orientlist>>stuname>>feedtime>>feedcontent)//��ӡѧ�������б�ͬʱ����ѧ����������
	{
		strcpy_s(a->studentname,stuname);
		strcpy_s(a->feedbacktime,feedtime);
		strcpy_s(a->feedbackcontent,feedcontent);
		cout<<i+1<<".ѧ��"<<stuname<<"��"<<feedtime<<"���ԣ�"<<feedcontent<<endl;
		a->code=i;
		b=new onerecord;
		a->next=b;
		a=a->next;
		a->next=NULL;
		i++;
	}
	a->next=NULL;
	a=head;
	orientlist.close();//�ر�ѧ�����������ļ�
	mark=i;
	newlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ѧ�������б�.txt",ios::out);//���µ�ѧ�������б��ļ�
	if(!newlist)
	{
		teachererror();//�ļ����ܴ�
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		teachererror();//�ļ����ܴ�
	}
	replylist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�����ظ��б�.txt",ios::app);//�򿪷����ظ��ļ�
	if(!replylist)
	{
		teachererror();//�ļ����ܴ�
	}
	newlist<<"ѧ������"<<'\t'<<"����ʱ��"<<'\t'<<"��������"<<'\n';//д�������
	while(1)
	{
		cout<<"��������Ҫ�𸴵�������ţ���Ctrl+Z��������"<<ends;//�𸴷���
		BH:if(cin>>choice)
		{
			clearcin();//�������
			if((choice>mark)||(choice<1))
			{
				cout<<"���������Ų����б���Ŷ�����������룺"<<ends;
				goto BH;
			}
			cout<<"����������ݣ�499�ַ����ڣ��벻Ҫ���У���"<<ends;
			cin>>content;//����ظ�����
			clearcin();//�������
			getlocaltime(currenttime);//��ñ���ʱ��
			if(choice==1)//д�뷴����¼����һ��������
			{
				replylist<<a->studentname<<'\t'<<a->feedbacktime<<'\t'<<a->feedbackcontent<<'\t'<<teachername<<'\t'<<currenttime<<'\t'<<content<<'\n';//д��һ��ѧ��������¼
				head=a->next;
				delete a;//�ظ���ɾ���÷���
				a=head;
				operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"�ظ�����"<<'\n';//д��һ��������¼
			}
			else
			{
				choice--;
				while(a->next->code!=choice)//���ҷ�����¼�ڵ�
				{
					a=a->next;
				}
				getlocaltime(currenttime);//��ñ���ʱ��
				replylist<<a->next->studentname<<'\t'<<a->next->feedbacktime<<'\t'<<a->next->feedbackcontent<<'\t'<<teachername<<'\t'<<currenttime<<'\t'<<content<<'\n';//д��һ��ѧ�������ظ���¼
				operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"�ظ�����"<<'\n';//д��һ��������¼
				b=a->next;
				a->next=b->next;//ɾ������ѧ��������¼
				delete b;
				b=NULL;
				a=head;
			}
			cout<<"���������ظ��ɹ���"<<endl;
		}
		else
		{
			clearcin();//�������
			operationfile.close();//�ر�ϵͳ������־�ļ�
			replylist.close();//�رշ����ظ��б��ļ�
			while(a->next!=NULL)//д���µ�ѧ�������б�
			{
				newlist<<a->studentname<<'\t'<<a->feedbacktime<<'\t'<<a->feedbackcontent<<'\n';
				a=a->next;
			}
			newlist.close();//�ر�ѧ�������б��ļ�
			a=head;
			while(head->next!=NULL)//����ѧ�������б�����
			{
				a=head;
				head=head->next;
				delete a;
			}
			delete head;
			a=NULL;
			head=NULL;
			cout<<"�ظ��ɹ���"<<endl;
			goto AR;
		}
	}
	AR:;
}
void facultyemail(char teachername[])//��ְ���ʼ�ϵͳ����ѡ�����
{
	int choice;
	while(1)
	{
		cout<<"��ѡ������ʹ��ܣ�"<<endl;
		cout<<"|1-�鿴�ռ���"<<endl;
		cout<<"|2-���͵����ʼ�"<<endl;
		cout<<"|3-ɾ�������ʼ�"<<endl;
		cout<<"|4-�˳������ʼ�ϵͳ"<<endl;
		cout<<"����ѡ���ǣ�"<<ends;
		AT:cin>>choice;//����ѡ��
		clearcin();//�������
		switch(choice)
		{
			case 1:watchfacultyemail(teachername);break;
			case 2:sendfacultyemail(teachername);break;
			case 3:deletefacultyemail(teachername);break;
			case 4:goto AS;
			default:
				{
					cout<<"������������Ŷ�����������룺"<<ends;
					goto AT;
				}
		}
	}
	AS:;
}
void watchfacultyemail(char teachername[])//�����ռ���
{
	ofstream operationfile;
	ifstream emaillist;
	char title[100],currenttime[32],sender[50],reciever[20],sendtime[32],etitle[50],econtent[500];
	emaillist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�����ʼ������ż���¼.txt",ios::in);//��ϵͳ�����ʼ���¼�ļ�
	if(!emaillist)
	{
		teachererror();//�ļ����ܴ�
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		teachererror();//�ļ����ܴ�
	}
	emaillist.seekg(0,ios::beg);
	emaillist.getline(title,100);
	getlocaltime(currenttime);//��ñ���ʱ��
	operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"�鿴�ʼ�"<<'\n';//д��һ��������¼
	operationfile.close();//�ر�ϵͳ������־�ļ�
	cout<<"���ڿ�ʼ��ӡ�ռ��䵱�еĵ����ʼ�..."<<endl;
	while(emaillist>>sendtime>>sender>>reciever>>etitle>>econtent)//��ӡ�ռ��䵱�е��ʼ�
	{
		if(strcmp(reciever,teachername)==0)
		{
			cout<<"===================================================================================="<<endl;
			cout<<"�����ˣ�"<<sender<<endl;
			cout<<"����ʱ�䣺"<<sendtime<<endl;
			cout<<"�ʼ����⣺"<<etitle<<endl;
			cout<<"�ʼ����ݣ�"<<econtent<<endl;
		}
	}
	cout<<"���н��յ����ż���ӡ��ϣ�"<<endl;
	emaillist.close();//�ر�ϵͳ�����ʼ��ļ�
}
void sendfacultyemail(char teachername[])//�����ʼ�
{
	ofstream operationfile,emaillist;
	char currenttime[32],reciever[20],title[50],content[500];
	int choice;
	emaillist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�����ʼ������ż���¼.txt",ios::app);//��ϵͳ�����ʼ������ż���¼�ļ�
	if(!emaillist)
	{
		teachererror();//�ļ����ܴ�
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		teachererror();//�ļ����ܴ�
	}
	AU:cout<<"�������ռ���������19�ַ����ڣ���"<<ends;
	cin>>reciever;//�����ռ���
	clearcin();//�������
	cout<<"�ռ����ǣ�"<<reciever<<",��ȷ����ȷ������1����������0���벻Ҫ�����������֣���"<<ends;
	AX:cin>>choice;
	clearcin();//�������
	switch(choice)
	{
		case 1:break;
		case 2:goto AU;
		default:
			{
				cout<<"������������Ŷ�����������룺"<<ends;
				goto AX;
			}
	}
	cout<<"�������ʼ����⣨49�ַ����ڣ���"<<ends;
	cin>>title;//�����ļ�����
	clearcin();//�������
	cout<<"�������ʼ����ݣ�499�ַ����ڣ��벻Ҫ���У���"<<ends;
	cin>>content;//�����ʼ�����
	clearcin();//�������
	getlocaltime(currenttime);//��ȡ����ʱ��
	emaillist<<currenttime<<'\t'<<teachername<<'\t'<<reciever<<'\t'<<title<<'\t'<<content<<'\n';//д��һ�������ʼ���¼
	emaillist.close();//�ر�ϵͳ�����ʼ������ż���¼�ļ�
	operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"��"<<reciever<<"д��һ������ʼ�"<<'\n';//д��һ��������¼
	operationfile.close();//�ر�ϵͳ������־�ļ�
	cout<<"�����ʼ����ͳɹ���"<<endl;
}
void resetfacultypassword(char teachername[])//�޸�����
{
	if(strcmp(teachername,"Admin")==0)//Ĭ���˺ŵ����벻���޸�
	{
		cout<<"Admin�����벻���޸ģ�"<<endl;
	}
	else
	{
		ofstream operationfile,newaccountlist;
		ifstream orientaccountlist;
		char currenttime[32],account[20],password[20],title[100];
		orientaccountlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\��ְ���˻�������.txt",ios::in);//�򿪽�ְ���˻������ļ�
		if(!orientaccountlist)
		{
			teachererror();//�ļ����ܴ�
		}
		orientaccountlist.seekg(0,ios::beg);
		orientaccountlist.getline(title,100);
		struct oneaccount//�����ְ���˻������¼����ڵ�ṹ
		{
			char username[20];
			char pass[20];
			oneaccount *next;
		};
		oneaccount *head,*a,*b;
		head=new oneaccount;
		a=head;
		while(orientaccountlist>>account>>password)//������ְ���˻���������
		{
			strcpy_s(a->username,account);
			strcpy_s(a->pass,password);
			b=new oneaccount;
			a->next=b;
			a=a->next;
			a->next=NULL;
		}
		a->next=NULL;
		a=head;
		b=NULL;
		orientaccountlist.close();//�رս�ְ���˻������ļ�
		cout<<"���������������루19�ַ����ڣ���"<<ends;
		cin>>password;//����������
		clearcin();//�������
		while(strcmp(a->username,teachername)!=0)//Ѱ�Ҹý�ʦ
		{
			a=a->next;
		}
		strcpy_s(a->pass,password);//�޸�����
		a=head;
		getlocaltime(currenttime);//��ñ���ʱ��
		newaccountlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\��ְ���˻�������.txt",ios::out);//���µĽ�ְ���˻������ļ�
		if(!newaccountlist)
		{
			teachererror();//�ļ����ܴ�
		}
		newaccountlist<<"�û���"<<'\t'<<"����"<<'\n';//д�������
		while(a->next!=NULL)//д���ְ���˻������¼
		{
			newaccountlist<<a->username<<'\t'<<a->pass<<'\n';
			a=a->next;
		}
		a=head;
		newaccountlist.close();//�رս�ְ���˻������ļ�
		operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
		if(!operationfile)
		{
			teachererror();//�ļ����ܴ�
		}
		operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"�޸�����"<<'\n';//д��һ��������¼
		operationfile.close();//�ر�ϵͳ������־�ļ�
		while(head->next!=NULL)//���ٽ�ְ���˻���������
		{
			a=head;
			head=head->next;
			delete a;
		}
		delete head;
		a=NULL;
		head=NULL;
		cout<<"�����޸���ɣ�"<<endl;
	}
}
void adminoperate()
{
	char teachername[20]="�ο�";
	bool condition=false;
	cout<<"��ӭʹ��ѧ���������ϵͳ��"<<endl;//��ӭ��
	cout<<"��ܰ��ʾ����һ�ν�����ʹ���û���Admin��½������Ϊ666666����½���봴�����˺š�"<<endl;//��ܰ��ʾ
	condition=teacherlogin(teachername);//��½
	if(condition)//��½�ɹ�
	{
		teacherfunction(teachername);//�����ְ�����ܽ���
	}
	cout<<teachername<<"����л��ʹ��ѧ���������ϵͳ���ټ���"<<endl;//�˳���ְ��ѡ�����
}
void deletefacultyemail(char teachername[])//ɾ�������ʼ�
{
	ofstream operationfile,newemailfile;
	ifstream orientemailfile;
	char esendtime[32],esender[50],ereciever[50],etitle[50],econtent[500],title[100],currenttime[32];
	int choice=0,mark=0,i=0,j=0;
	struct oneemail//�����ż�����ڵ�ṹ
	{
		int code;
		int mycode;
		char sendtime[32];
		char sender[50];
		char reciever[50];
		char emailtitle[50];
		char content[500];
		oneemail *next;
	};
	oneemail *head,*a,*b;
	orientemailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�����ʼ������ż���¼.txt",ios::in);//��ϵͳ�����ʼ������ż���¼�ļ�
	if(!orientemailfile)
	{
		teachererror();//�ļ����ܴ�
	}
	orientemailfile.seekg(0,ios::beg);
	orientemailfile.getline(title,100);
	head=new oneemail;
	a=head;
	a->next=NULL;
	cout<<"���ڿ�ʼ��ӡ����ռ��䵱�е��ʼ��嵥������..."<<endl;
	while(orientemailfile>>esendtime>>esender>>ereciever>>etitle>>econtent)//��ӡ�ռ��䲢�����ʼ�����
	{
		a->mycode=-1;
		if(strcmp(ereciever,teachername)==0)
		{
			cout<<"=================================================="<<endl;
			cout<<"��ţ�"<<j+1<<endl;
			cout<<"����ʱ�䣺"<<esendtime<<endl;
			cout<<"�ļ��ˣ�"<<esender<<endl;
			cout<<"�ʼ����⣺"<<etitle<<endl;
			cout<<"�ʼ����ݣ�\n"<<econtent<<endl;
			a->mycode=j;
			j++;
		}
		a->code=i;
		strcpy_s(a->sendtime,esendtime);
		strcpy_s(a->sender,esender);
		strcpy_s(a->reciever,ereciever);
		strcpy_s(a->emailtitle,etitle);
		strcpy_s(a->content,econtent);
		b=new oneemail;
		a->next=b;
		a=a->next;
		a->next=NULL;
		i++;
	}
	a->next=NULL;
	a=head;
	mark=j;
	i=0;
	j=0;
	cout<<"�����ʼ���ӡ��ϣ�"<<endl;
	orientemailfile.close();//�رյ����ʼ������ż���¼�ļ�
	while(1)
	{
		cout<<"����������Ҫɾ�����ʼ���ţ���Ctrl+Z��������"<<ends;
		CB:if(cin>>choice)//ɾ���ʼ�
		{
			clearcin();//clear buff
			if((choice<1)||(choice>mark))
			{
				cout<<"�����������������루��Ctrl+Z��������"<<ends;
				goto CB;
			}
			choice--;
			if(head->mycode==choice)
			{
				a=head;
				head=head->next;
				delete a;
			}
			else
			{
				a=head;
				while(a->next->mycode!=choice)//���ҽڵ�
				{
					a=a->next;
				}
				b=a->next;
				a->next=b->next;
				delete b;
			}
		   }
		   else
		   {
			   clearcin();//clear buff
			   goto CC;
		   }
	}
	CC:a=head;
	newemailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�����ʼ������ż���¼.txt",ios::out);//���µĵ����ʼ������ż���¼�ļ�
	if(!newemailfile)
	{
		teachererror();//�ļ����ܴ�
	}
	newemailfile<<"����ʱ��"<<'\t'<<"������"<<'\t'<<"�ռ���"<<'\t'<<"�ʼ�����"<<'\t'<<"�ʼ�����"<<'\n';//д�������
	while(a->next!=NULL)//д���µ����ʼ��б�
	{
		newemailfile<<a->sendtime<<'\t'<<a->sender<<'\t'<<a->reciever<<'\t'<<a->emailtitle<<'\t'<<a->content<<'\n';
		a=a->next;
	}
	newemailfile.close();//�رյ����ʼ������ż���¼�ļ�
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		teachererror();//�ļ����ܴ�
	}
	getlocaltime(currenttime);//��ñ���ʱ��
	operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"ɾ���ʼ�"<<'\n';//д��һ��������¼
	operationfile.close();//�ر�ϵͳ������־�ļ�
	a=head;
	b=NULL;
	while(head->next!=NULL)//ɾ�������ʼ�����
	{
		a=head;
		head=head->next;
		delete a;
	}
	delete head;
	head=NULL;
	a=NULL;
	cout<<"�ʼ�ɾ���ɹ���"<<endl;
}
#include<iostream>
#include<string.h>
#include<fstream>
#include"clarify student functions.h"
#include<ctime>
#include"clarify main functions.h"
using namespace std;
void studenterror()//�쳣����
{
	cout<<"ϵͳ�ļ��򿪳��������Զ��رգ��������뿪����Ա����ϵͳ��"<<endl;//��ܰ��ʾ
	system("pause");
	exit(0);//ֱ���˳�ϵͳ
}
int findstudent(char studentname[])//ȷ��ѧ���Ƿ��Ѿ�ע��
{
	char title[100],name[20],password[20];
	ifstream studentfiles;
	studentfiles.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ѧ���˻�������.txt",ios::in|ios::out);//��ѧ���б��ļ�
	studentfiles.seekg(0,ios::beg);
	if(!studentfiles)
	{
		studenterror();//�ļ����ܴ�
	}
	studentfiles.getline(title,100);
	while(studentfiles>>name>>password)//��ʼ����
	{
		if(strcmp(studentname,name)==0)
		{
			studentfiles.close();//�ر�ѧ���б��ļ�
			return 1;//���ҳɹ�
		}
	}
	studentfiles.close();//�ر�ѧ���б��ļ�
	return 0;//�Ҳ�����ѧ��
}
int comparepassword(char studentname[],char studentpassword[])//�Ա�����
{
	ifstream studentfiles;
	char title[100],name[20],password[20];
	studentfiles.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ѧ���˻�������.txt",ios::in|ios::out);//��ѧ���˻������б��ļ�
	studentfiles.seekg(0,ios::beg);
	if(!studentfiles)
	{
		studenterror();//�ļ����ܴ�
	}
	studentfiles.getline(title,100);
	while(studentfiles>>name>>password)//��ʼ�Ա�����
	{
		if(strcmp(studentname,name)==0)
		{
			if(strcmp(studentpassword,password)==0)
			{
				studentfiles.close();//�ر��˻������б��ļ�
				return 1;//��ɶԱȣ�������ȷ
			}
			else
			{
				studentfiles.close();//�ر��˻������б��ļ�
				return 0;//��ɶԱȣ��������
			}
		}
	}
	studentfiles.close();//�ر��˻������б��ļ�
	cout<<"ϵͳ����û�����������¼Ŷ��"<<endl;//��ʾ
	return 0;//��ѧ�������б���
}
void watchfeedback(char studentname[])//�������ظ�
{
	char title[100],currenttime[32],name[20],feedbacktime[32],feedbackcontent[500],stuff[20],dealtime[32],replycontent[500];
	int i=0;
	ifstream feedbackfiles("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�����ظ��б�.txt",ios::in);//�򿪷����ظ��б��ļ�
	if(!feedbackfiles)
	{
		studenterror();//�ļ���ʧ��
	}
	feedbackfiles.seekg(0,ios::beg);
	feedbackfiles.getline(title,100);
	ofstream operatefiles;
	operatefiles.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operatefiles)
	{
		studenterror();//�ļ���ʧ��
	}
	getlocaltime(currenttime);//��õ�ǰʱ��
	operatefiles<<currenttime<<'\t'<<studentname<<'\t'<<"��ȡ����"<<'\n';//дһ���¼�¼
	operatefiles.close();//�رղ�����־�ļ�
	cout<<"���濪ʼ��ӡ�����ظ��б�..."<<endl;
	while(feedbackfiles>>name>>feedbacktime>>feedbackcontent>>stuff>>dealtime>>replycontent)//��ӡ�����ظ��б�
	{
		if(strcmp(studentname,name)==0)//��ӡ��ѧ���ķ����ظ���¼
		{
			cout<<"================================================================="<<endl;
			cout<<"����ʱ�䣺"<<feedbacktime<<endl;
			cout<<"�������ݣ�"<<feedbackcontent<<endl;
			cout<<"���ˣ�"<<stuff<<endl;
			cout<<"��ʱ�䣺"<<dealtime<<endl;
			cout<<"�����ݣ�"<<replycontent<<endl;
		}
	}
	feedbackfiles.close();//�رշ����ظ��б��ļ�
	cout<<"������������ʾ��ϣ�"<<endl;
}
void feedback(char studentname[])//д���·���
{
	ofstream operatefiles;
	ofstream feedbackfile;
	char currenttime[32],feedbackcontent[500];
	getlocaltime(currenttime);
	operatefiles.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	feedbackfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ѧ�������б�.txt",ios::app);//��ϵͳ�����б��ļ�
	if(!operatefiles)
	{
		studenterror();//�ļ����ܴ�
	}
	if(!feedbackfile)
	{
		studenterror();//�ļ����ܴ�
	}
	operatefiles<<currenttime<<'\t'<<studentname<<'\t'<<"д�뷴��"<<'\n';//д�������¼
	operatefiles.close();//�ر�ϵͳ������־�ļ�
	cout<<"����������Ҫ����������(������500�֣���"<<ends;
	cin>>feedbackcontent;//д�뷴������
	clearcin();//�������
	feedbackfile<<studentname<<'\t'<<currenttime<<'\t'<<feedbackcontent<<'\n';//д������¼
	feedbackfile.close();//�رշ����б��ļ�
	cout<<"�����Ѿ��ɹ�¼��ϵͳ���ȴ���ְ�����"<<endl;//�����ɹ�
}
void studentprofile(char studentname[])//�鿴���˵���
{
	char currenttime[32],title[100],name[20],number[12],sex[5],major[20],class_[20],add[50],dorm[50],birth[11];
	int choice;
	struct student//������󡪡�ѧ��
	{
		char student_name[20];
		char student_number[12];
		char student_gender[5];
		char student_birthdate[11];
		char student_major[20];
		char student_class[20];
		char student_homeadd[50];
		char student_dormitory[50];
	};
	student currentstudent;//����һ��ѧ������
	fstream allstudentlist,systemoperation;
	allstudentlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ѧ������\\ȫ��ѧ������.txt",ios::in);//��ѧ���б��ļ�
	if(!allstudentlist)
	{
		studenterror();//�ļ����ܴ�
	}
	systemoperation.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!systemoperation)
	{
		studenterror();//�ļ����ܴ�
	}
	getlocaltime(currenttime);//��õ�ǰʱ��
	systemoperation<<currenttime<<'\t'<<studentname<<'\t'<<"�鿴����\n";//д�������¼
	systemoperation.close();//�ر�ϵͳ������־�ļ�
	allstudentlist.seekg(0,ios::beg);
	allstudentlist.getline(title,100);
	while(allstudentlist>>name>>number>>sex>>birth>>major>>class_>>add>>dorm)//����ѧ���б��ļ�
	{
		if(strcmp(studentname,name)==0)//�ҵ���ѧ��
		{
			strcpy_s(currentstudent.student_name,name);
			strcpy_s(currentstudent.student_number,number);
			strcpy_s(currentstudent.student_gender,sex);
			strcpy_s(currentstudent.student_birthdate,birth);
			strcpy_s(currentstudent.student_major,major);
			strcpy_s(currentstudent.student_class,class_);
			strcpy_s(currentstudent.student_homeadd,add);
			strcpy_s(currentstudent.student_dormitory,dorm);
			break;
		}
	}
	allstudentlist.close();//�ر�ѧ���б��ļ�
	cout<<"ѧ��������"<<currentstudent.student_name<<"\nѧ��ѧ�ţ�"<<currentstudent.student_number<<"\nѧ���Ա�"<<currentstudent.student_gender<<"\nѧ���������ڣ�"<<currentstudent.student_birthdate<<"\nѧ������רҵ��"<<currentstudent.student_major<<"\nѧ�������༶��"<<currentstudent.student_class<<"\nѧ����ͥ��ַ��"<<currentstudent.student_homeadd<<"\nѧ������ţ�"<<currentstudent.student_dormitory<<endl;//��ӡѧ������
	cout<<studentname<<"�����ĵ����Ѿ���ʾ��ϣ���������Ҫ�޸����޸�������1����������0��"<<endl;
	cout<<"����������ѡ��"<<ends;
	cin>>choice;//ѡ���Ƿ��޸ĸ��˵���
	clearcin();//�������
	if(choice==1)
	{
		resetprofile(studentname);//�ĵ���
	}
}
void resetprofile(char studentname[])//�޸ĵ���
{
	char currenttime[32],title[100],name[20],number[12],sex[5],major[20],class_[20],add[50],dorm[50],birth[11];
	int choice;
	struct student//����ѧ������
	{
		char student_name[20];
		char student_number[12];
		char student_gender[5];
		char student_birthdate[11];
		char student_major[20];
		char student_class[20];
		char student_homeadd[50];
		char student_dormitory[50];
	};
	struct studentlist//�����б�ڵ�
	{
		student currentstuent;
		studentlist *next;
	};
	studentlist *a,*head,*b;
	a=new studentlist;
	head=a;
	head->next=NULL;
	ofstream operationfile,ostudentlistfile;
	ifstream studentlistfile;
	studentlistfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ѧ������\\ȫ��ѧ������.txt",ios::in);//��ѧ�������ļ�
	if(!studentlistfile)
	{
		studenterror();//�ļ����ܴ�
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		studenterror();//�ļ����ܴ�
	}
	studentlistfile.seekg(0,ios::beg);
	studentlistfile.getline(title,100);
	while(studentlistfile>>name>>number>>sex>>birth>>major>>class_>>add>>dorm)//����ѧ����������
	{
		strcpy_s(a->currentstuent.student_name,name);
		strcpy_s(a->currentstuent.student_number,number);
		strcpy_s(a->currentstuent.student_gender,sex);
		strcpy_s(a->currentstuent.student_birthdate,birth);
		strcpy_s(a->currentstuent.student_major,major);
		strcpy_s(a->currentstuent.student_class,class_);
		strcpy_s(a->currentstuent.student_homeadd,add);
		strcpy_s(a->currentstuent.student_dormitory,dorm);
		b=new studentlist;
		a->next=b;
		a=a->next;
		a->next=NULL;
	}
	a->next=NULL;
	studentlistfile.close();//�ر�ѧ���б��ļ�
	a=head;
	while(strcmp(a->currentstuent.student_name,studentname)!=0)//�ҵ�Ҫ�޸�ѧ���Ľڵ�
	{
		a=a->next;
	}
	while(1)//�޸ĸ�����Ϣ
	{
		cout<<"�����������޸ĵ���Ŀ��"<<endl;
		cout<<"|1-�Ա�"<<endl;
		cout<<"|2-��������"<<endl;
		cout<<"|3-����רҵ"<<endl;
		cout<<"|4-�����༶"<<endl;
		cout<<"|5-��ͥ��ַ"<<endl;
		cout<<"|6-�����"<<endl;
		cout<<"|7-�˳��޸�"<<endl;
		cout<<"����������ѡ��"<<ends;
		P:cin>>choice;
		clearcin();//�������
		switch(choice)
		{
			case 1://�޸��Ա�
				{
					cout<<"���������µ��Ա���/Ů)��"<<ends;
					cin>>sex;
					strcpy_s(a->currentstuent.student_gender,sex);
					clearcin();//clear buff
					getlocaltime(currenttime);
					operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"�޸ĵ���--�޸��Ա�"<<'\n';//д��һ���²�����¼
				}
				break;
			case 2://�޸ĳ�������
				{
					cout<<"���������µĳ������ڣ���ʽΪyyyy-mm-dd����"<<ends;
					cin>>birth;
					strcpy_s(a->currentstuent.student_birthdate,birth);
					clearcin();//clear buff
					getlocaltime(currenttime);
					operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"�޸ĵ���--�޸ĳ�������"<<'\n';//дһ���²�����¼
				}
				break;
			case 3://�޸�����רҵ
				{
					cout<<"���������µ�����רҵ��19�ַ����ڣ���"<<ends;
					cin>>major;
					strcpy_s(a->currentstuent.student_major,major);
					clearcin();//clear buff
					getlocaltime(currenttime);
					operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"�޸ĵ���--�޸�����רҵ"<<'\n';//дһ���¼�¼
				}
				break;
			case 4://�޸������༶
				{
					cout<<"���������µ������༶��19�ַ����ڣ���"<<ends;
					cin>>class_;
					strcpy_s(a->currentstuent.student_class,class_);
					clearcin();//clear buff
					getlocaltime(currenttime);
					operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"�޸ĵ���--�޸İ༶"<<'\n';//дһ���¼�¼
				}
				break;
			case 5://�޸ļ�ͥסַ
				{
					cout<<"���������µļ�ͥסַ��49�ַ����ڣ���"<<ends;
					cin>>add;
					strcpy_s(a->currentstuent.student_homeadd,add);
					clearcin();//clear buff
					getlocaltime(currenttime);
					operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"�޸ĵ���--�޸ļ�ͥסַ"<<'\n';//дһ���¼�¼
				}
				break;
			case 6://�޸�����
				{
					cout<<"���������µ�����ţ�49�ַ����ڣ���"<<ends;
					cin>>dorm;
					strcpy_s(a->currentstuent.student_dormitory,dorm);
					clearcin();//clear buff
					getlocaltime(currenttime);
					operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"�޸ĵ���--�޸��������"<<'\n';//дһ���¼�¼
				}
				break;
			case 7://�˳�
				goto O;
			default://��������
				{
					cout<<"������ı���д�Ŷ�����������룺"<<ends;
					goto P;
				}
		}
	}
	O:a=head;
	ostudentlistfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ѧ������\\ȫ��ѧ������.txt",ios::out);//��ѧ�������ļ�����ʼд�ļ�
	if(!ostudentlistfile)
	{
		studenterror();//�ļ����ܴ�
	}
	ostudentlistfile<<"����"<<'\t'<<"ѧ��"<<'\t'<<"�Ա�"<<'\t'<<"��������"<<'\t'<<"רҵ"<<'\t'<<"�༶"<<'\t'<<"��ͥסַ"<<'\t'<<"�������"<<'\n';//д����
	while(a->next!=NULL)//write new student profile
	{
		ostudentlistfile<<a->currentstuent.student_name<<'\t'<<a->currentstuent.student_number<<'\t'<<a->currentstuent.student_gender<<'\t'<<a->currentstuent.student_birthdate<<'\t'<<a->currentstuent.student_major<<'\t'<<a->currentstuent.student_class<<'\t'<<a->currentstuent.student_homeadd<<'\t'<<a->currentstuent.student_dormitory<<'\n';//д��¼
		a=a->next;
	}
	a=head;
	ostudentlistfile.close();//�ر�ѧ���б��ļ�
	while(a->next!=NULL)//����ѧ����������
	{
		b=a;
		a=a->next;
		delete b;
	}
	delete a;
	a=NULL;
	b=NULL;
	head=NULL;
	cout<<"�޸���ɣ�"<<endl;
}
void getscorefile(char studentname[])//��ѯ�ɼ�
{
	char filename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ѧ������\\";//�ɼ��ļ�·��
	char name[50],title[100],currenttime[32];
	int classnumber=0,choice=0,s=0;
	strcat_s(filename,studentname);
	strcat_s(filename,"ѧ���ɼ�.txt");//��������ļ�����·��
	ofstream operationfile;
	ifstream scorefile;
	scorefile.open(filename,ios::in);//��ѧ���ɼ��ļ�
	if(!scorefile)
	{
		studenterror();//�ļ����ܴ�
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		studenterror();//�ļ����ܴ�
	}
	scorefile.seekg(0,ios::beg);
	scorefile.getline(title,100);
	cout<<"���ڿ�ʼ��ӡ�γ̳ɼ�..."<<endl;
	cout<<"�γ�����\t�γ̳ɼ�"<<endl;
	while(scorefile>>name>>s)//ͳ�Ƴɼ������еĿγ�����
	{
		cout<<name<<'\t'<<s<<endl;
		classnumber++;
	}
	getlocaltime(currenttime);//��ñ���ʱ��
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"�鿴�ɼ�"<<'\n';//дһ��������¼
	operationfile.close();//�ر�ϵͳ������־�ļ�
	scorefile.close();//�ر�ѧ���ɼ��ļ�
	cout<<"���гɼ���ʾ��ϣ�"<<endl;
	cout<<"���Ƿ�ϣ��������ʾ��"<<endl;//ѡ���Ƿ�������ʾ
	cout<<"|1-���򣨴Ӵ�С������"<<endl;
	cout<<"|2-���򣨴�С��������"<<endl;
	cout<<"|3-������"<<endl;
	cout<<"����ѡ���ǣ�"<<ends;
	P:cin>>choice;
	clearcin();//�������
	switch(choice)
	{
		case 1:rankdown(filename,classnumber,studentname);break;//����������ʾ
		case 2:rankup(filename,classnumber,studentname);break;//����������ʾ
		case 3:break;
		default://��������
			{
				cout<<"������ı�Ų���ȷŶ�����������룺"<<ends;
				goto P;
			}
	}
}
void rankdown(char filename[],int classnumber,char studentname[])//��������
{
	char currenttime[32],title[100],name[50],tempclassname[50];
	int r=0,j=0,s,tempscore;
	fstream scorefile,operationfile;
	scorefile.open(filename,ios::in);//��ѧ���ɼ��ļ�
	scorefile.seekg(0,ios::beg);
	scorefile.getline(title,100);
	if(!scorefile)
	{
		studenterror();//�ļ����ܴ�
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		studenterror();//�ļ����ܴ�
	}
	getlocaltime(currenttime);//��ñ���ʱ��
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"����������ʾ�ɼ�"<<'\n';//дһ��������¼
	operationfile.close();//�ر�ϵͳ������־�ļ�
	struct score//���������¼�ڵ�ṹ
	{
		char classname[50];
		int classscore;
	};
	score *scorelist,*head,*max;
	head=new score[classnumber];//��̬���������¼����
	scorelist=head;
	max=head;
	while(scorefile>>name>>s)//д������
	{
		strcpy_s(scorelist->classname,name);
		scorelist->classscore=s;
		scorelist++;
	}
	scorefile.close();//�ر�ѧ���ɼ��ļ�
	scorelist=head;
	for(int i=0;i<classnumber;i++)//ѡ������
	{
		for(j=i+1;j<classnumber;j++)
		{
			if(((scorelist+j)->classscore)>(max->classscore))//swap
			{
				tempscore=max->classscore;
				strcpy_s(tempclassname,max->classname);
				max->classscore=(scorelist+j)->classscore;
				strcpy_s(max->classname,(scorelist+j)->classname);
				(scorelist+j)->classscore=tempscore;
				strcpy_s((scorelist+j)->classname,tempclassname);
			}
		}
		max++;
	}
	max=NULL;
	scorelist=head;
	cout<<"���������Ѿ���ɣ����ڿ�ʼ��ӡ�������к�Ľ��..."<<endl;
	cout<<"�γ�����"<<'\t'<<"�γ̳ɼ�"<<endl;
	for(int i=0;i<classnumber;i++)//��ʾ�������
	{
		cout<<scorelist->classname<<'\t'<<scorelist->classscore<<endl;
		scorelist++;
	}
	cout<<"��ʾ��ϣ�"<<endl;
	scorelist=head;
	delete []scorelist;//���ٶ�̬�����ѧ���ɼ���¼����
	scorelist=NULL;
	head=NULL;
}
void rankup(char filename[],int classnumber,char studentname[])//����������ʾѧ���ɼ�
{
	char currenttime[32],title[100],name[50],tempclassname[50];
	int r=0,j=0,s,tempscore;
	fstream scorefile,operationfile;
	scorefile.open(filename,ios::in);//��ѧ���ɼ��б�
	scorefile.seekg(0,ios::beg);
	scorefile.getline(title,100);
	if(!scorefile)
	{
		studenterror();//�ļ����ܴ�
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		studenterror();//�ļ����ܴ�
	}
	getlocaltime(currenttime);//��ñ���ʱ��
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"����������ʾ�ɼ�"<<'\n';//д��һ��������¼
	operationfile.close();//�ر�ϵͳ������־�ļ�
	struct score//����ѧ���ɼ��ڵ�ṹ
	{
		char classname[50];
		int classscore;
	};
	score *scorelist,*head,*min;
	head=new score[classnumber];//��̬����ѧ���ɼ�����
	scorelist=head;
	min=head;
	while(scorefile>>name>>s)//д������
	{
		strcpy_s(scorelist->classname,name);
		scorelist->classscore=s;
		scorelist++;
	}
	scorefile.close();//�ر�ѧ���ɼ��ļ�
	scorelist=head;
	for(int i=0;i<classnumber;i++)//ѡ������
	{
		for(j=i+1;j<classnumber;j++)
		{
			if(((scorelist+j)->classscore)<(min->classscore))//swap
			{
				tempscore=min->classscore;
				strcpy_s(tempclassname,min->classname);
				min->classscore=(scorelist+j)->classscore;
				strcpy_s(min->classname,(scorelist+j)->classname);
				(scorelist+j)->classscore=tempscore;
				strcpy_s((scorelist+j)->classname,tempclassname);
			}
		}
		min++;
	}
	min=NULL;
	scorelist=head;
	cout<<"���������Ѿ���ɣ����ڿ�ʼ��ʾ�������к�Ľ��..."<<endl;
	cout<<"�γ�����"<<'\t'<<"�γ̳ɼ�"<<endl;
	for(int i=0;i<classnumber;i++)//��ʾ������
	{
		cout<<scorelist->classname<<'\t'<<scorelist->classscore<<endl;
		scorelist++;
	}
	scorelist=head;
	delete []head;//���ٶ�̬�����ѧ���ɼ�����
	scorelist=NULL;
	head=NULL;
}
void chooseableclass(char studentname[])//ͨѡ��ϵͳ
{
	char currenttime[32],title[100],name[50],nature[20],term[10],code[8];
	int totaltime=0,theorytime=0,exptime=0,credit=0,totalpeople=0,leftpeople=0,classnumber=0,choice=0;
	ofstream operationfile;
	fstream chooseableclasslist;
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		studenterror();//�ļ����ܴ�
	}
	chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ͨѡ���б�.txt",ios::in);//��ͨѡ���б��ļ�
	if(!chooseableclasslist)
	{
		studenterror();//�ļ����ܴ�
	}
	getlocaltime(currenttime);//��ñ���ʱ��
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"�鿴ͨѡ���б�"<<'\n';//дһ��������¼
	operationfile.close();//�ر�ϵͳ������־�ļ�
	chooseableclasslist.seekg(0,ios::beg);
	chooseableclasslist.getline(title,100);
	cout<<"ϵͳ���м�¼��ͨѡ����Ϣ���£�"<<endl;
	cout<<"���"<<'\t'<<"�γ�����"<<'\t'<<"�γ�����"<<'\t'<<"��ѧʱ"<<'\t'<<"�ڿ�ѧʱ"<<'\t'<<"ʵ����ϻ�ѧʱ"<<'\t'<<"ѧ��"<<'\t'<<"����ѧ��"<<'\t'<<"������"<<'\t'<<"ʣ���ѡ����"<<endl;
	while(chooseableclasslist>>code>>name>>nature>>totaltime>>theorytime>>exptime>>credit>>term>>totalpeople>>leftpeople)//��ӡͨѡ���б�
	{
		cout<<code<<'\t'<<name<<'\t'<<nature<<'\t'<<totaltime<<'\t'<<theorytime<<'\t'<<exptime<<'\t'<<credit<<'\t'<<term<<'\t'<<totalpeople<<'\t'<<leftpeople<<endl;
	}
	chooseableclasslist.close();//�ر�ͨѡ���б��ļ�
	while(1)//�Ƿ�ѡ�λ��˿�
	{
		cout<<"��Ҫѡ�λ����˿���"<<endl;
		cout<<"|1-ѡ��"<<endl;
		cout<<"|2-�˿�"<<endl;
		cout<<"|3-������"<<endl;
		cout<<"��������Ҫ���еĲ�����"<<ends;
		R:cin>>choice;
		clearcin();//clear buff
		switch(choice)
		{
			case 1:selectclass(studentname);break;//ѡ��
			case 2:quitclass(studentname);break;//�˿�
			case 3:goto W;
			default://��������
			{
				cout<<"������ı������Ŷ�����������룺"<<ends;
				goto R;
			}
		}
	}
W:;
}
void selectclass(char studentname[])//ѡ��
{
	ofstream operationfile;
	fstream classfile,chooseableclasslist;
	char currenttime[32],title[100],name[50],nature[20],term[10],code[8],title2[100],sname[20],mycode[8],snum[20];
	int totaltime,theorytime,exptime,credit,totalpeople,leftpeople,classnumber=0,choice;
	bool mark=false;
	S:cout<<"����������ѡ�εĿγ̱�ţ�"<<ends;
	cin>>mycode;
	clearcin();//�������
	char filename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�γ�ѧ������\\";//ѧ������·��
	strcat_s(filename,mycode);
	strcat_s(filename,".txt");//����ļ���
	chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ͨѡ���б�.txt",ios::in);//��ͨѡ���б��ļ�
	if(!chooseableclasslist)
	{
		studenterror();//�ļ����ܴ�
	}
	chooseableclasslist.seekg(0,ios::beg);
	chooseableclasslist.getline(title,100);
	while(chooseableclasslist>>code>>name>>nature>>totaltime>>theorytime>>exptime>>credit>>term>>totalpeople>>leftpeople)//����ͨѡ���б�
	{
		if(strcmp(code,mycode)==0)
		{
			if(leftpeople>0)
			{
				mark=true;//�ÿγ���ʣ������
			}
		}
	}
	chooseableclasslist.close();//�ر�ͨѡ���б��ļ�
	classfile.open(filename,ios::in);//��ͨѡ��ѧ���б��ļ�
	if(!filename)
	{
		studenterror();//�ļ����ܴ�
	}
	classfile.seekg(0,ios::beg);
	classfile.getline(title2,100);
	while(classfile>>snum>>sname)//�ж�ѧ���Ƿ��ڿγ���������
	{
		if(strcmp(sname,studentname)==0)//ѧ���ڿγ��������У������Ѿ�ѡ��
		{
			mark=false;
		}
	}
	classfile.close();//�ر�ѧ�������б��ļ�
	if(mark==false)//����ѡ��
	{
		cout<<"�Բ��𣬵�ǰͨѡ�����������ѱ�������Ҫѡ������ͨѡ����"<<endl;
		cout<<"|1-��"<<endl;
		cout<<"|2-��"<<endl;
		cout<<"����ѡ���ǣ�"<<ends;
		T:cin>>choice;
		clearcin();//�������
		switch(choice)
		{
			case 1:goto S;
			case 2:break;
			default:
				{
					cout<<"������ı���������������룺"<<ends;
					goto T;
				}
		}
	}
	else//����ѡ��
	{
		chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ͨѡ���б�.txt",ios::in);//��ͨѡ���б��ļ�
		if(!chooseableclasslist)
		{
			studenterror();//�ļ����ܴ�
		}
		chooseableclasslist.seekg(0,ios::beg);
		chooseableclasslist.getline(title,100);
		struct aclass//����һ���γ̼�¼����ṹ
		{
			char classcode[8];
			char classname[50];
			char classnature[20];
			int classtotaltime;
			int classtheorytime;
			int classexptime;
			int classcredit;
			char classterm[10];
			int classtotalpeople;
			int classleftpeople;
		};
		struct classlist//��������ڵ�ṹ
		{
			aclass thisclass;
			classlist *next;
		};
		classlist *a,*head,*b;
		a=new classlist;
		head=a;
		head->next=NULL;
		while(chooseableclasslist>>code>>name>>nature>>totaltime>>theorytime>>exptime>>credit>>term>>totalpeople>>leftpeople)//����ͨѡ���б�����
		{
			strcpy_s(a->thisclass.classcode,code);
			strcpy_s(a->thisclass.classname,name);
			strcpy_s(a->thisclass.classnature,nature);
			a->thisclass.classtotaltime=totaltime;
			a->thisclass.classtheorytime=theorytime;
			a->thisclass.classexptime=exptime;
			a->thisclass.classcredit=credit;
			strcpy_s(a->thisclass.classterm,term);
			a->thisclass.classtotalpeople=totalpeople;
			a->thisclass.classleftpeople=leftpeople;
			b=new classlist;
			a->next=b;
			a=a->next;
			a->next=NULL;
		}
		a->next=NULL;
		a=head;
		chooseableclasslist.close();//�ر�ͨѡ���б��ļ�
		while(a->next!=NULL)//�ı�ʣ������
		{
			if(strcmp(mycode,a->thisclass.classcode)==0)
			{
				a->thisclass.classleftpeople--;
			}
			a=a->next;
		}
		a=head;
		chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ͨѡ���б�.txt",ios::out);//��ͨѡ���б��ļ�
		if(!chooseableclasslist)
		{
			studenterror();//�ļ����ܴ�
		}
		chooseableclasslist<<"���"<<'\t'<<"����"<<'\t'<<"����"<<'\t'<<"��ѧʱ"<<'\t'<<"�ڿ�ѧʱ"<<'\t'<<"ʵ����ϻ�ѧʱ"<<'\t'<<"ѧ��"<<'\t'<<"����ѧ��"<<'\t'<<"������"<<'\t'<<"ʣ���ѡ����"<<'\n';//д�������
		while(a->next!=NULL)//д���µ�ͨѡ���б��ļ�
		{
			chooseableclasslist<<a->thisclass.classcode<<'\t'<<a->thisclass.classname<<'\t'<<a->thisclass.classnature<<'\t'<<a->thisclass.classtotaltime<<'\t'<<a->thisclass.classtheorytime<<'\t'<<a->thisclass.classexptime<<'\t'<<a->thisclass.classcredit<<'\t'<<a->thisclass.classterm<<'\t'<<a->thisclass.classtotalpeople<<'\t'<<a->thisclass.classleftpeople<<'\n';
			a=a->next;
		}
		chooseableclasslist.close();//�ر�ͨѡ���б��ļ�
		a=head;
		while(a->next!=NULL)//����ͨѡ���б�����
		{
			b=a;
			a=a->next;
			delete b;
		}
		delete a;
		a=NULL;
		b=NULL;
		head=NULL;
		ifstream allstudents;
		allstudents.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ѧ������\\ȫ��ѧ������.txt",ios::in);//��ϵͳѧ�������ļ�
		if(!allstudents)
		{
			studenterror();//�ļ����ܴ�
		}
		allstudents.seekg(0,ios::beg);
		allstudents.getline(title,100);
		char studentnumber[12],studname[20],studentgender[5],studentmajor[20],studentclass[20],studentbirth[11],studentadd[50],studentdorm[50];
		while(allstudents>>studname>>studentnumber>>studentgender>>studentbirth>>studentmajor>>studentclass>>studentadd>>studentdorm)
		{
			if(strcmp(studentname,studname)==0)//����ѧ��
			{
				strcpy_s(snum,studentnumber);//����ѧ��
				break;
			}
		}
		allstudents.close();//�ر�ϵͳѧ���б��ļ�
		classfile.open(filename,ios::app);//�򿪿γ�ѧ�������ļ�
		if(!classfile)
		{
			studenterror();//�ļ����ܴ�
		}
		classfile<<snum<<'\t'<<studentname<<'\n';//д��һ���µ�ѧ����Ϣ
		classfile.close();//�رտγ�ѧ�������ļ�
		operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
		if(!operationfile)
		{
			studenterror();//�ļ����ܴ�
		}
		getlocaltime(currenttime);//��ñ���ʱ��
		operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"ѡ�Σ�ͨѡ�α��Ϊ��"<<mycode<<'\n';//дһ��������¼
		operationfile.close();//�ر�ϵͳ������־�ļ�
		cout<<"ѡ�γɹ���"<<endl;
	}
}
void quitclass(char studentname[])//�˿�
{
	ofstream operationfile;
	fstream classfile,chooseableclasslist;
	char currenttime[32],title[100],name[50],nature[20],term[10],code[8],title2[100],sname[20],mycode[8],snum[12];
	int totaltime,theorytime,exptime,credit,totalpeople,leftpeople,classnumber=0,choice2=0;
	bool mark=false;
	U:cout<<"����������Ҫ��ѡ��ͨѡ�εĿγ̱�ţ�"<<ends;
	cin>>mycode;//������ѡ�Ŀγ̱��
	clearcin();//�������
	char filename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�γ�ѧ������\\";
	strcat_s(filename,mycode);
	strcat_s(filename,".txt");//����ͨѡ��ѧ�������ļ���
	chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ͨѡ���б�.txt",ios::in);//��ͨѡ���б��ļ�
	if(!chooseableclasslist)
	{
		studenterror();//�ļ����ܴ�
	}
	chooseableclasslist.seekg(0,ios::beg);
	chooseableclasslist.getline(title,100);
	while(chooseableclasslist>>code>>name>>nature>>totaltime>>theorytime>>exptime>>credit>>term>>totalpeople>>leftpeople)//���ҿγ̲��ж��ܷ��˿�
	{
		if(strcmp(code,mycode)==0)//�ҵ��γ�
		{
			if(leftpeople<totalpeople)//����ѡ��
			{
				mark=true;
			}
		}
	}
	chooseableclasslist.close();//�ر�ͨѡ���б��ļ�
	if(mark==false)//�����˿�
	{
		cout<<"�Բ����޸�ͨѡ�λ�����ѡ�˸ÿλ�������ѡ�ÿΣ�"<<endl;
		cout<<"��Ҫ��ѡ����ͨѡ����"<<endl;
		cout<<"|1-��"<<endl;
		cout<<"|2-��"<<endl;
		cout<<"����ѡ���ǣ�"<<ends;
		BJ:cin>>choice2;
		clearcin();//�������
		switch(choice2)
		{
			case 1:goto U;
			case 2:goto BI;
			default:
				{
					cout<<"������ı�Ų���Ŷ�����������룺"<<ends;
					goto BJ;
				}
		}
	}
	classfile.open(filename,ios::in);//�򿪿γ̰༶����
	if(!classfile)
	{
		studenterror();//�ļ����ܴ�
	}
	classfile.seekg(0,ios::beg);
	classfile.getline(title2,100);
	while(classfile>>snum>>sname)//j�ж�ѧ���Ƿ���ѧ���б���
	{
		if(strcmp(sname,studentname)==0)//ѧ�����б���
		{
			mark=true;
		}
	}
	classfile.close();//�����˿�
	chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ͨѡ���б�.txt",ios::in);//��ͨѡ���б��ļ�
	if(!chooseableclasslist)
	{
		studenterror();//�ļ����ܴ�
	}
	chooseableclasslist.seekg(0,ios::beg);
	chooseableclasslist.getline(title,100);
	struct aclass//����һ�����ü�¼�Ľṹ
	{
		char classcode[8];
		char classname[50];
		char classnature[20];
		int classtotaltime;
		int classtheorytime;
		int classexptime;
		int classcredit;
		char classterm[10];
		int classtotalpeople;
		int classleftpeople;
	};
	struct classlist//��������ڵ�ṹ
	{
		aclass thisclass;
		classlist *next;
	};
	classlist *a,*head,*b;
	a=new classlist;
	head=a;
	head->next=NULL;
	while(chooseableclasslist>>code>>name>>nature>>totaltime>>theorytime>>exptime>>credit>>term>>totalpeople>>leftpeople)//����ͨѡ������
	{
		strcpy_s(a->thisclass.classcode,code);
		strcpy_s(a->thisclass.classname,name);
		strcpy_s(a->thisclass.classnature,nature);
		a->thisclass.classtotaltime=totaltime;
		a->thisclass.classtheorytime=theorytime;
		a->thisclass.classexptime=exptime;
		a->thisclass.classcredit=credit;
		strcpy_s(a->thisclass.classterm,term);
		a->thisclass.classtotalpeople=totalpeople;
		a->thisclass.classleftpeople=leftpeople;
		b=new classlist;
		a->next=b;
		a=a->next;
		a->next=NULL;
	}
	a->next=NULL;
	a=head;
	chooseableclasslist.close();//�ر�ͨѡ���б��ļ�
	while(a->next!=NULL)//�ı�ʣ������
	{
		if(strcmp(mycode,a->thisclass.classcode)==0)//�ҵ���
		{
			a->thisclass.classleftpeople++;
			break;
		}
		a=a->next;
	}
	a=head;
	chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ͨѡ���б�.txt",ios::out);//��ͨѡ���б��ļ�
	if(!chooseableclasslist)
	{
		studenterror();//�ļ����ܴ�
	}
	chooseableclasslist<<"���"<<'\t'<<"����"<<'\t'<<"����"<<'\t'<<"��ѧʱ"<<'\t'<<"�ڿ�ѧʱ"<<'\t'<<"ʵ����ϻ�ѧʱ"<<'\t'<<"ѧ��"<<'\t'<<"����ѧ��"<<'\t'<<"������"<<'\t'<<"ʣ���ѡ����"<<'\n';//д�������
	while(a->next!=NULL)//д���µ�ͨѡ���б�
	{
		chooseableclasslist<<a->thisclass.classcode<<'\t'<<a->thisclass.classname<<'\t'<<a->thisclass.classnature<<'\t'<<a->thisclass.classtotaltime<<'\t'<<a->thisclass.classtheorytime<<'\t'<<a->thisclass.classexptime<<'\t'<<a->thisclass.classcredit<<'\t'<<a->thisclass.classterm<<'\t'<<a->thisclass.classtotalpeople<<'\t'<<a->thisclass.classleftpeople<<'\n';
		a=a->next;
	}
	chooseableclasslist.close();//�ر�ͨѡ���б��ļ�
	a=head;
	while(a->next!=NULL)//У��ͨѡ������
	{
		b=a;
		a=a->next;
		delete b;
	}
	delete a;
	a=NULL;
	b=NULL;
	head=NULL;
	classfile.open(filename,ios::in);//�򿪿γ�����
	if(!classfile)
	{
		studenterror();//�ļ����ܴ�
	}
	classfile.seekg(0,ios::beg);
	classfile.getline(title2,100);
	struct classstudent//����һ��ѧ���Ľڵ�ṹ
	{
		char stunum[12];
		char stuname[20];
		classstudent *next;
	};
	classstudent *c,*record,*d;
	c=new classstudent;
	record=c;
	while(classfile>>snum>>sname)//����ѧ����������
	{
		strcpy_s(c->stuname,sname);
		strcpy_s(c->stunum,snum);
		d=new classstudent;
		c->next=d;
		c=c->next;
		c->next=NULL;
	}
	classfile.close();//�ر�ѧ�������ļ�
	c->next=NULL;
	c=record;
	if(strcmp(record->stuname,studentname)==0)//ɾ��ѧ��
	{
		c=record;
		record=record->next;
		delete c;
	}
	else
	{
		while(c->next!=NULL)
		{
			if(strcmp(c->next->stuname,studentname)==0)//erase student record
			{
				d=c->next;
				c->next=d->next;
				delete d;
			}
			c=c->next;
		}
	}
	c=record;
	classfile.open(filename,ios::out);//��ѧ�������ļ�
	classfile<<"ѧ��"<<'\t'<<"ѧ������"<<'\n';//д�������
	while(c->next!=NULL)//д���µ�ѧ������
	{
		classfile<<c->stunum<<'\t'<<c->stuname<<'\n';
		c=c->next;
	}
	classfile.close();//�ر�ѧ�����������ļ�
	c=record;
	while(c->next!=NULL)//��������
	{
		d=c;
		c=c->next;
		delete d;
	}
	delete c;
	c=NULL;
	d=NULL;
	record=NULL;
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������¼�ļ�
	if(!operationfile)
	{
		studenterror();//�ļ����ܴ�
	}
	getlocaltime(currenttime);//��ñ���ʱ��
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"��ѡ��ͨѡ�α��Ϊ��"<<mycode<<'\n';//д��һ��������¼
	operationfile.close();//�ر�ϵͳ������¼�ļ�
	cout<<"��ѡ�ɹ���"<<endl;
	BI:;
}
void gotoclassrecord(char studentname[])//�鿴���ڼ�¼
{
	char title[100],name[20],number[12],clas[50],teacher[20],date[11],condition[5],currenttime[32];
	int recordnumber=0;
	ifstream diligency;
	diligency.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�γ̿��ڼ�¼.txt",ios::in);//�򿪿γ̿��ڼ�¼�ļ�
	if(!diligency)
	{
		studenterror();//�ļ����ܴ�
	}
	diligency.seekg(0,ios::beg);
	diligency.getline(title,100);
	cout<<"���ڿ�ʼ��ӡ��Ŀγ̿������..."<<endl;//��ʼ��ӡ�������
	cout<<"�γ�����"<<'\t'<<"�Ͽ�����"<<'\t'<<"�������"<<'\t'<<endl;
	while(diligency>>number>>name>>clas>>teacher>>date>>condition)
	{
		if(strcmp(name,studentname)==0)//�������ڼ�¼Ϊ��ǰѧ���ļ�¼
		{
			cout<<clas<<'\t'<<date<<'\t'<<condition<<endl;
		}
	}
	diligency.close();//�رտ��ڼ�¼�ļ�
	cout<<"���п��ڼ�¼��ʾ��ϣ�"<<endl;
	ofstream operationfile;
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������¼�ļ�
	if(!operationfile)
	{
		studenterror();//�ļ����ܴ�
	}
	getlocaltime(currenttime);//��ñ���ʱ��
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"��ѯ�������"<<'\n';//д��һ��������¼
	operationfile.close();//�ر�ϵͳ�����ļ�
} 
void studentemail(char studentname[])//ѧ����������ϵͳ
{
	int choice;
	while(1)
	{
		cout<<"��ѡ������ʹ�õĵ����ʼ����ܣ�"<<endl;
		cout<<"|1-�鿴�յ��ĵ����ʼ�"<<endl;
		cout<<"|2-���͵����ʼ�������"<<endl;
		cout<<"|3-ɾ���ռ��䵱�е��ʼ�"<<endl;
		cout<<"|4-�˳���������ϵͳ"<<endl;
		cout<<"����������ѡ��"<<ends;
		Y:cin>>choice;
		clearcin();//�������
		switch(choice)//���ݶ�Ӧ�Ĵ���ѡ����
		{
			case 1:watchemail(studentname);break;
			case 2:sendemail(studentname);break;
			case 3:deleteemail(studentname);break;
			case 4:goto X;
			default:
				{
					cout<<"������ı������Ŷ�����������룺"<<ends;
					goto Y;
				}
		}
	}
X:;
}
void watchemail(char studentname[])//�鿴�ռ���
{
	ofstream operationfile;
	ifstream emailfile;
	char currenttime[32],title[100],stime[32],sperson[50],scontent[500],rperson[20],stitle[50];
	int allrecord=0;
	emailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�����ʼ������ż���¼.txt",ios::in);//�򿪵����ʼ���¼�ļ�
	if(!emailfile)
	{
		studenterror();//�ļ����ܴ�
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		studenterror();//�ļ����ܴ�
	}
	getlocaltime(currenttime);//��ñ���ʱ��
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"��ȡ�ʼ�"<<'\n';//д��һ��������¼
	operationfile.close();//�ر�ϵͳ������־�ļ�
	emailfile.seekg(0,ios::beg);
	emailfile.getline(title,100);
	cout<<"���ڿ�ʼ��ӡ�ʼ�..."<<endl;
	while(emailfile>>stime>>sperson>>rperson>>stitle>>scontent)//��ӡ�ռ��䵱�е��ʼ�
	{
		if(strcmp(rperson,studentname)==0)//�ռ���Ϊ��ǰѧ��
		{
			cout<<"======================================================================================"<<endl;
			cout<<"�����ˣ�"<<sperson<<endl;
			cout<<"����ʱ�䣺"<<stime<<endl;
			cout<<"�ʼ����⣺"<<stitle<<endl;
			cout<<"�ʼ����ݣ�"<<scontent<<endl;
		}
	}
	emailfile.close();//�ر��ʼ��ļ�
	cout<<"�����ż���ʾ��ϣ�"<<endl;
}
void sendemail(char studentname[])
{
	ofstream emailfile;
	ofstream operationfile;
	emailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�����ʼ������ż���¼.txt",ios::app);//��ϵͳ�����ļ�
	if(!emailfile)
	{
		studenterror();//�ļ����ܴ�
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		studenterror();//�ļ����ܴ�
	}
	char targetuser[20],emailtitle[50],emailcontent[500],currenttime[32];
	int choice;
	AA:cout<<"�����������������"<<ends;
	cin>>targetuser;
	clearcin();//�������
	cout<<"������Ľ��շ��ǣ�"<<targetuser<<"����ȷ����ȷ������1����ȷ������0����"<<ends;
	AB:cin>>choice;//ȷ�Ͻ��շ�
	clearcin();//�������
	switch(choice)
	{
		case 0:goto AA;
		case 1:break;
		default:
			{
				cout<<"�������벻��ȷŶ�����������룺"<<ends;
				goto AB;
			}
	}
	cout<<"�ʼ����⣨��50�ַ��ڣ���"<<ends;
	cin>>emailtitle;
	clearcin();//�������
	cout<<"�������ʼ����ݣ���500�ַ��ڣ������У���"<<ends;
	cin>>emailcontent;
	clearcin();//�������
	getlocaltime(currenttime);//��ñ���ʱ��
	emailfile<<currenttime<<'\t'<<studentname<<'\t'<<targetuser<<'\t'<<emailtitle<<'\t'<<emailcontent<<'\n';//д��һ���ʼ���¼
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<studentname<<"д�Ÿ�"<<targetuser<<'\n';//д��һ��������¼
	operationfile.close();//�ر�ϵͳ������־�ļ�
	emailfile.close();//�ر�ϵͳ���������ļ�
	cout<<"�ʼ����ͳɹ���"<<endl;
}
bool studentlogin(char studentname[])//ѧ����½
{
	int usernamecondition,passwordcondition,namechoice,passwordchoice;
	char studentpassword[20],currenttime[32];
	F:cout<<"���������"<<ends;
	cin>>studentname;//��������
	clearcin();//�������
	H:cout<<"������"<<ends;
	cin>>studentpassword;//��������
	clearcin();//�������
	usernamecondition=findstudent(studentname);//��ѧ���������в���ѧ���Ƿ����
	if(usernamecondition==0)//ѧ������ϵͳѧ����������
	{
		cout<<"�ڽ���ϵͳ�����Ҳ�����ļ�¼���ǲ��Ǵ�������ˣ��������ѧУ��û����ע�᣿"<<endl;
		cout<<"�����������ϵͳ�����˳�ѧ������ϵͳ��"<<endl;
		cout<<"|1-��������"<<endl;
		cout<<"|2-�˳���"<<endl;
		cout<<"���������ѡ��"<<ends;
		G:cin>>namechoice;
		clearcin();//�������
		switch(namechoice)
		{
			case 1:goto F;
			case 2:return false;
			default:
			{
				cout<<"����Ŷ�㻹������ˣ��ȱ�ˮ����һ��������ɣ�"<<ends;
				goto G;
			}
		}
	}
	passwordcondition=comparepassword(studentname,studentpassword);//�Ƚ����룬�ж��Ƿ�������ȷ
	if(passwordcondition==0)//�������
	{
		cout<<"����������"<<endl;
		cout<<"�����������ϵͳ�����˳�ѧ������ϵͳ��"<<endl;
		cout<<"|1-��������"<<endl;
		cout<<"|2-�˳���"<<endl;
		cout<<"���������ѡ��"<<ends;
		I:cin>>passwordchoice;
		clearcin();//�������
		switch(passwordchoice)
		{
			case 1:goto H;
			case 2:return false;
			default:
			{
				cout<<"����Ŷ�㻹������ˣ��ȱ�ˮ����һ��������ɣ�"<<ends;
				goto I;
			}
		}
	}
	getlocaltime(currenttime);//��ñ���ʱ��
	ofstream loginfile;
	loginfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\��½��־.txt",ios::app);//��ϵͳ��½��־�ļ�
	if(!loginfile)
	{
		studenterror();//�ļ����ܴ�
	}
	loginfile<<currenttime<<'\t'<<studentname<<'\t'<<"ѧ��"<<'\n';//д��һ����½��¼
	loginfile.close();//�رյ�½��־�ļ�
	cout<<"��½�ɹ���"<<endl;
	return true;
}
void studentfunction(char studentname[])//ѧ������ѡ�����
{
	int choice;
	while(1)//choose function
	{
		cout<<"�����ǹ����б�����ѡ������Ҫ��������Ŀ��"<<endl;
		cout<<"|1-��ѯ���޸ĸ��˵���"<<endl;
		cout<<"|2-������ĳɼ�"<<endl;
		cout<<"|3-ѡ�޿β���"<<endl;
		cout<<"|4-�Ͽο��ڼ�¼��ѯ"<<endl;
		cout<<"|5-�鿴��ķ����ظ�"<<endl;
		cout<<"|6-�ʼ�ϵͳ"<<endl;
		cout<<"|7-�޸�����"<<endl;
		cout<<"|8-�˳�ϵͳ"<<endl;
		cout<<"����ѡ��Ĺ��ܴ����ǣ�"<<ends;
		E:cin>>choice;
		clearcin();//�������
		switch(choice)
		{
			case 1:studentprofile(studentname);break;
			case 2:getscorefile(studentname);break;
			case 3:chooseableclass(studentname);break;
			case 4:gotoclassrecord(studentname);break;
			case 5:watchfeedback(studentname);break;
			case 6:studentemail(studentname);break;
			case 7:resetpassword(studentname);break;
			case 8:goto BB;
			default:
			{
				cout<<"��������Ŷ���ܲ����鷳����������һ�¹��ܴ��ţ�"<<ends;
				goto E;
			}
		}
		cout<<endl;
	}
	BB:;
}
void studentfeedback(char studentname[])//ѧ��ѡ��������
{
	int choice;
	cout<<studentname<<"����ã�����ֱ���˳�ѧ���������ϵͳ������дһ�·������˳�ϵͳ��"<<endl;
	cout<<"|1-ֱ���˳�"<<endl;
	cout<<"|2-��д�������˳�"<<endl;
	cout<<"���ѡ���ǣ�"<<ends;
	K:cin>>choice;
	clearcin();//�������
	switch(choice)
	{
		case 1:goto J;
		case 2:feedback(studentname);break;//Ҫ��д�뷴��
		default:
		{
			cout<<"����ָ�����Ŷ������������ɣ�"<<ends;
			goto K;
		}
	}
	J:;
}
void studentoperate()//ѧ����������������
{
	char studentname[20]="�ο�";
	bool condition=false;
	cout<<"ͬѧ����ӭʹ��ѧ������ϵͳ�����½..."<<endl;
	condition=studentlogin(studentname);//ѧ����½
	if(condition)//��½�ɹ�
	{
		cout<<studentname<<"����ӭ����"<<endl;
		studentfunction(studentname);
	}
	studentfeedback(studentname);//ѡ��д����
	cout<<studentname<<"����лʹ��ѧ������ϵͳ���ټ���"<<endl;
}
void resetpassword(char studentname[])//�޸�����
{
	ifstream studentaccountdata;
	ofstream operationfile,newaccountdata;
	char title[100],name[20],pass[20],newpassword[20],currenttime[32];
	struct account//�����˻���Ϣ����ڵ�ṹ
	{
		char sname[20];
		char spassword[20];
		account *next;
	};
	account *head,*a,*b;
	head=new account;
	a=head;
	head->next=NULL;
	studentaccountdata.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ѧ���˻�������.txt",ios::in);//��ϵͳѧ�������ļ�
	if(!studentaccountdata)
	{
		studenterror();//�ļ����ܴ�
	}
	studentaccountdata.seekg(0,ios::beg);
	studentaccountdata.getline(title,100);
	while(studentaccountdata>>name>>pass)//��������
	{
		strcpy_s(a->sname,name);
		strcpy_s(a->spassword,pass);
		b=new account;
		a->next=b;
		a=a->next;
		a->next=NULL;
	}
	a=head;
	b=NULL;
	studentaccountdata.close();//�ر��˻���Ϣ�ļ�
	cout<<"�����������루20�ַ����ڣ���"<<ends;
	cin>>newpassword;//����������
	clearcin();//�������
	while(a->next!=NULL)//����ѧ�����޸�����
	{
		if(strcmp(a->sname,studentname)==0)//�ҵ���ѧ��
		{
			strcpy_s(a->spassword,newpassword);
			break;
		}
		a=a->next;
	}
	a=head;
	newaccountdata.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\ѧ���˻�������.txt",ios::out);//���µ�ѧ���˻������¼�ļ�
	if(!newaccountdata)
	{
		studenterror();//�ļ����ܴ�
	}
	newaccountdata<<"�û���"<<'\t'<<"����"<<'\n';//д�������
	while(a->next!=NULL)//д���µ��˻������¼
	{
		newaccountdata<<a->sname<<'\t'<<a->spassword<<'\n';
		a=a->next;
	}
	a=head;
	newaccountdata.close();//�ر�ѧ���˻���Ϣ�ļ�
	while(head->next!=NULL)//�����˻���Ϣ����
	{
		head=head->next;
		delete a;
	}
	delete head;
	head=NULL;
	a=NULL;
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		studenterror();//�ļ����ܴ�
	}
	getlocaltime(currenttime);//��ñ���ʱ��
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"�޸�����"<<'\n';//д��һ��������¼
	operationfile.close();//�ر�ϵͳ������־�ļ�
	cout<<"�����޸ĳɹ���"<<endl;
}
void deleteemail(char studentname[])//ɾ���ʼ�
{
	ofstream operationfile,newemailfile;
	ifstream orientemailfile;
	char esendtime[32],esender[50],ereciever[50],etitle[50],econtent[500],title[100],currenttime[32];
	int choice=0,mark=0,i=0,j=0;
	struct oneemail//�����ʼ�����ڵ�ṹ
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
	orientemailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�����ʼ������ż���¼.txt",ios::in);//��ϵͳ�����ʼ��ļ�
	if(!orientemailfile)
	{
		studenterror();//�ļ����ܴ�
	}
	orientemailfile.seekg(0,ios::beg);
	orientemailfile.getline(title,100);
	head=new oneemail;
	a=head;
	a->next=NULL;
	cout<<"���ڿ�ʼ��ӡ����ռ��䵱�е��ʼ��嵥������..."<<endl;
	while(orientemailfile>>esendtime>>esender>>ereciever>>etitle>>econtent)//��ʼ��ӡ�ռ��䲢�Կ�����Ҫɾ�����ʼ����б���
	{
		a->mycode=-1;
		if(strcmp(ereciever,studentname)==0)//�ռ��˶�Ӧ��
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
	orientemailfile.close();//�رյ��������ļ�
	while(1)
	{
		cout<<"����������Ҫɾ�����ʼ���ţ���Ctrl+Z��������"<<ends;
		CB:if(cin>>choice)
		{
			clearcin();//�������
			if((choice<1)||(choice>mark))//�ж������Ƿ���ȷ
			{
				cout<<"�����������������루��Ctrl+Z��������"<<ends;
				goto CB;
			}
			choice--;
			if(head->mycode==choice)//ɾ����Ӧ�ʼ�����Ӧ�Ľڵ�
			{
				a=head;
				head=head->next;
				delete a;
			}
			else
			{
				a=head;
				while(a->next->mycode!=choice)
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
	newemailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\�����ʼ������ż���¼.txt",ios::out);//���µ�ϵͳ�����ʼ�ϵͳ�ļ�
	if(!newemailfile)
	{
		studenterror();//�ļ����ܴ�
	}
	newemailfile<<"����ʱ��"<<'\t'<<"������"<<'\t'<<"�ռ���"<<'\t'<<"�ʼ�����"<<'\t'<<"�ʼ�����"<<'\n';//д�������
	while(a->next!=NULL)//д���µĵ����ʼ�����
	{
		newemailfile<<a->sendtime<<'\t'<<a->sender<<'\t'<<a->reciever<<'\t'<<a->emailtitle<<'\t'<<a->content<<'\n';
		a=a->next;
	}
	newemailfile.close();//�ر�ϵͳ�����ʼ��ļ�
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\ѧ���������ϵͳ\\ѧ���������ϵͳ\\ϵͳ����\\������־.txt",ios::app);//��ϵͳ������־�ļ�
	if(!operationfile)
	{
		studenterror();//�ļ����ܴ�
	}
	getlocaltime(currenttime);//��ñ���ʱ��
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"ɾ���ʼ�"<<'\n';//д��һ���²�����¼
	operationfile.close();//�ر�ϵͳ������־�ļ�
	a=head;
	b=NULL;
	while(head->next!=NULL)//���ٵ����ʼ�����
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
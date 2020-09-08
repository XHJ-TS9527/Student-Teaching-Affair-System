#include<iostream>
#include<fstream>
#include<string.h>
#include "clarify king functions.h"
#include"clarify main functions.h"
#include<ctime>
using namespace std;
bool checkidentity()//检查身份
{
	char spectorpassword[20];
	cout<<"进入监视员状态..."<<endl;
	cout<<"请输入监视员验证口令："<<ends;
	cin>>spectorpassword;
	if(strcmp(spectorpassword,"13316091752")==0)//验证身份，验证码为13316091752
	{
		cout<<"验证成功！"<<endl;
		return true;
	}
	else
	{
		cout<<"验证失败，直接退出该状态。"<<endl;
		return false;
	}
}
void watchoperationfile()//查看操作日志
{
	char title[100],time[32],user[20],thing[70];
	ifstream operationfile;
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::in);//打开系统操作日志文件
	if(!operationfile)
	{
		kingerror();//文件不能打开
	}
	operationfile.seekg(0,ios::beg);
	operationfile.getline(title,100);
	cout<<"开始打印操作记录..."<<endl;
	cout<<"操作时间"<<'\t'<<"操作人"<<'\t'<<"操作内容"<<endl;
	while(operationfile>>time>>user>>thing)//打印操作日志内容
	{
		cout<<time<<'\t'<<user<<'\t'<<thing<<endl;
	}
	operationfile.close();//关闭系统操作日志文件
	cout<<"所有操作记录显示完毕！"<<endl;
}
void kingfunction()//监视员状态功能选择界面
{
	int choice;
	while(1)
	{
		cout<<"请选择功能："<<endl;
		cout<<"|1-查看系统登陆日志"<<endl;
		cout<<"|2-查看系统操作日志"<<endl;
		cout<<"|3-查看学生反馈列表"<<endl;
		cout<<"|4-查看反馈回复列表"<<endl;
		cout<<"|5-删除公告"<<endl;
		cout<<"|6-查看所有信件来往记录"<<endl;
		cout<<"|7-通过电子邮件向用户发送警告"<<endl;
		cout<<"|8-添加新课程"<<endl;
		cout<<"|9-查看所有学生的个人档案"<<endl;
		cout<<"|10-查看所有教职工的个人档案"<<endl;
		cout<<"|11-查看教师任课情况"<<endl;
		cout<<"|12-退出监视员状态"<<endl;
		cout<<"请输入您的选择："<<ends;
		AZ:cin>>choice;//输入选择
		clearcin();//清除缓存
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
					cout<<"您的输入有误哦！请重新输入："<<ends;
					goto AZ;
				}
		}
	}
	AY:cout<<"感谢您使用教务系统监视员模式！再见！"<<endl;
}
void kingerror()//异常处理
{
	cout<<"系统文件打开出错！程序将自动关闭，请立即请开发人员调试系统！"<<endl;//温馨提示
	system("pause");
	exit(0);//退出系统
}
void kingoperate()//监视员状态整体架构
{
	bool condition=false;
	condition=checkidentity();//检查身份
	if(condition)//身份验证成功，启动监视员功能
	{
		kingfunction();
	}
}
void watchloginfile()//查看登陆日志
{
	char title[100],time[32],user[20],type[10];
	ifstream loginfile;
	loginfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\登陆日志.txt",ios::in);//打开系统登陆日志文件
	if(!loginfile)
	{
		kingerror();//文件不能打开
	}
	loginfile.seekg(0,ios::beg);
	loginfile.getline(title,100);
	cout<<"现在开始打印登陆记录..."<<endl;
	cout<<"登录时间"<<'\t'<<"登陆人"<<'\t'<<"用户类型"<<endl;
	while(loginfile>>time>>user>>type)//打印登陆记录
	{
		cout<<time<<'\t'<<user<<'\t'<<type<<endl;
	}
	loginfile.close();//关闭系统登陆日志文件
	cout<<"所有登陆信息显示完毕！"<<endl;
}
void watchstudentfeedbacklist()//查看学生反馈列表
{
	char title[100],name[20],time[32],content[500];
	ifstream stufeedback;
	stufeedback.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\学生反馈列表.txt",ios::in);//打开学生反馈列表文件
	stufeedback.seekg(0,ios::beg);
	stufeedback.getline(title,100);
	cout<<"现在开始打印未解决的学生反馈列表..."<<endl;
	while(stufeedback>>name>>time>>content)//打印学生反馈列表
	{
		cout<<"==================================================================="<<endl;
		cout<<"学生姓名："<<name<<endl;
		cout<<"反馈时间："<<time<<endl;
		cout<<"反馈内容："<<content<<endl;
	}
	stufeedback.close();//关闭学生反馈列表文件
	cout<<"所有未解决的学生反馈显示完毕！"<<endl;
}
void watchreplylist()//查看反馈回复列表
{
	char title[100],stuname[20],stutime[32],stucontent[500],facultyname[20],facultytime[32],facultycontent[500];
	ifstream replylist;
	replylist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\反馈回复列表.txt",ios::in);//打开系统反馈回复列表文件
	if(!replylist)
	{
		kingerror();//文件不能打开
	}
	replylist.seekg(0,ios::beg);
	replylist.getline(title,100);
	cout<<"现在开始打印反馈回复列表..."<<endl;
	while(replylist>>stuname>>stutime>>stucontent>>facultyname>>facultytime>>facultycontent)//打印反馈回复列表
	{
		cout<<"========================================================================"<<endl;
		cout<<"学生姓名："<<stuname<<endl;
		cout<<"反馈时间："<<stutime<<endl;
		cout<<"反馈内容："<<stucontent<<endl;
		cout<<"答复人："<<facultyname<<endl;
		cout<<"答复时间："<<facultytime<<endl;
		cout<<"答复内容："<<facultycontent<<endl;
	}
	replylist.close();//关闭反馈回复列表文件
	cout<<"所有已答复的反馈记录显示完毕！"<<endl;
}
void deletebulletin()//删除公告栏上的内容
{
	ifstream orientbulletin;
	ofstream newbulletin;
	char title[100],user[20],time[32],content[500];
	int i=0,choice,mark=0;
	struct onerecord//构造一条公告栏记录链表节点结构
	{
		int code;
		char username[20];
		char usertime[32];
		char announcement[500];
		onerecord *next;
	};
	onerecord *head,*a,*b;
	orientbulletin.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\公告栏.txt",ios::in);//打开系统公告栏文件
	if(!orientbulletin)
	{
		kingerror();//文件不能打开
	}
	orientbulletin.seekg(0,ios::beg);
	orientbulletin.getline(title,100);
	head=new onerecord;
	a=head;
	cout<<"现在开始显示公告栏..."<<endl;
	while(orientbulletin>>user>>time>>content)//打印公告栏上的内容并构造公告栏链表
	{
		cout<<"==================================================================="<<endl;
		cout<<"序号："<<i+1<<endl;
		cout<<"发布人："<<user<<endl;
		cout<<"发布时间："<<time<<endl;
		cout<<"内容："<<content<<endl;
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
	orientbulletin.close();//关闭公告栏文件
	while(1)
	{
		cout<<"请输入需要删除的公告序号（输入-1结束）："<<ends;
		BG:cin>>choice;
		clearcin();//清除缓存
		if(choice>0)
		{
			if(choice>mark)//输入的编号不在列表范围内
			{
				cout<<"您输入的标号不在列表当中，请重新输入："<<ends;
				goto BG;
			}
			choice--;
			if(choice==0)//删除首条公告
			{
				head=head->next;
				delete a;
				a=head;
			}
			else//删除非首条公告
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
			cout<<"序号为"<<choice+1<<"的公告删除成功！"<<endl;
		}
		else
		{
			goto BA;
		}
	}
	BA:cout<<"所要求删除的记录已经删除完成！"<<endl;
	newbulletin.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\公告栏.txt",ios::out);//打开新的公告栏文件
	if(!newbulletin)
	{
		kingerror();//文件不能打开
	}
	newbulletin<<"发布人"<<'\t'<<"发布时间"<<'\t'<<"公告内容"<<'\n';//写入标题行
	while(a->next!=NULL)//写入新的公告栏文件
	{
		newbulletin<<a->username<<'\t'<<a->usertime<<'\t'<<a->announcement<<'\n';
		a=a->next;
	}
	newbulletin.close();//关闭公告栏文件
	a=head;
	while(head->next!=NULL)//销毁公告栏链表
	{
		a=head;
		head=head->next;
		delete a;
	}
	delete head;
	a=NULL;
	head=NULL;
	cout<<"操作成功！"<<endl;
}
void sendwarning()//发送警告邮件
{
	char currenttime[32],reciever[20];
	ofstream emailfile;
	emailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\电子邮件来往信件记录.txt",ios::app);//打开系统电子邮件来往信件记录文件
	if(!emailfile)
	{
		kingerror();//文件不能打开
	}
	cout<<"请输入收件人姓名（19字符以内）："<<ends;
	cin>>reciever;//输入收件人
	clearcin();//清除缓存
	getlocaltime(currenttime);//获得本地时间
	emailfile<<currenttime<<'\t'<<"系统管理员"<<'\t'<<reciever<<'\t'<<"警告"<<'\t'<<"系统管理员对你的部分行为进行了检查，并向你发出了警告，请尽快联系系统管理员解决！"<<'\n';//写入一条警告邮件记录
	emailfile.close();//关闭系统电子邮件信件记录文件
	cout<<"警告邮件发送成功！"<<endl;
}
void addclass()//为系统添加课程
{
	cout<<"现在开始为系统添加新课程..."<<endl;
	int choice=0;
	cout<<"请问您要添加的课是通选课吗（是请输入1，否则输入0）："<<ends;
	BK:cin>>choice;
	clearcin();//clear buff
	switch(choice)
	{
		case 1:addchooseableclass();break;//添加通选课
		case 0:addordinaryclass();break;//添加非通选课
		default:
			{
				cout<<"输入有误，请重新输入："<<ends;
				goto BK;
			}
	}
}
void addchooseableclass()//添加通选课
{
	char code[8],classname[50],nature[20],term[10],title1[100],targetteachername[20],title2[100],title3[100];
	char number[20],name[20],gender[5],birth[11],department[50],job[10],phone[12],marry[5],homeadd[50];
	char ccode[8],cname[50],cnature[20],cterm[10];
	int totaltime,thmtime,exptime,totalpeople,leftpeople,i=0,mark=0,choice,credit;
	int ctotaltime,cthmtime,cexptime,ctotalpeople,cleftpeople,ccredit;
	int salary,age;
	ifstream teachers,teachclass,orientlist;
	ofstream chooseableclasslist,teacherclass,newscorelist,studentlist;
	teachers.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\全部教职工名单.txt",ios::in);//打开系统当中的教职工名单
	if(!teachers)
	{
		kingerror();//文件不能打开
	}
	teachers.seekg(0,ios::beg);
	teachers.getline(title1,100);
	cout<<"现在开始打印教师列表，请从中选择任课教师..."<<endl;
	cout<<"编号"<<'\t'<<"姓名"<<'\t'<<"所在部门"<<'\t'<<"职称"<<endl;//打印任课教师列表
	while(teachers>>number>>name>>gender>>birth>>department>>job>>salary>>phone>>age>>marry>>homeadd)
	{
		cout<<i+1<<'\t'<<name<<'\t'<<department<<'\t'<<job<<endl;
		i++;
	}
	mark=i;
	cout<<"请输入目标任课教师的编号："<<ends;
	BL:cin>>choice;//键入任课教师编号
	clearcin();//清除缓存
	i=0;
	if((choice<1)||(choice>mark))//输入编号不在列表范围当中
	{
		cout<<"您输入的编号不在教师列表当中哦！请重新输入："<<ends;
		goto BL;
	}
	choice--;
	teachers.close();//关闭教师列表文件
	teachers.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\全部教职工名单.txt",ios::in);//打开教职工列表文件
	if(!teachers)
	{
		kingerror();//文件不能打开
	}
	teachers.seekg(0,ios::beg);
	teachers.getline(title1,100);
	while(teachers>>number>>name>>gender>>birth>>department>>job>>salary>>phone>>age>>marry>>homeadd)//获得任课教师的教师名
	{
		if(i==choice)
		{
			strcpy_s(targetteachername,name);
			break;
		}
		i++;
	}
	teachers.close();//关闭教师名单文件
	teachclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\任课.txt",ios::in);//打开任课名单文件
	if(!teachclass)
	{
		kingerror();//文件不能打开
	}
	cout<<"请输入课程名称（19字符以内）："<<ends;
	BM:cin>>classname;//输入新课程名称
	clearcin();//清除缓存
	teachclass.seekg(0,ios::beg);
	teachclass.getline(title2,100);
	while(teachclass>>name>>cname>>cnature)//判断是否已有教职工任课
	{
		if(strcmp(cname,classname)==0)//已有教职工任课
		{
			cout<<"该课程已有教职工任教，请重新输入课程名称："<<ends;
			goto BM;
		}
	}
	teachclass.close();//关闭任课名单
	orientlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\通选课列表.txt",ios::in);//打开系统通选课列表
	if(!orientlist)
	{
		kingerror();//文件不能打开
	}
	cout<<"请输入课程编号（7字符以内）："<<ends;
	BN:cin>>code;//输入新课程编号
	clearcin();//清除缓存
	orientlist.seekg(0,ios::beg);
	orientlist.getline(title3,100);
	while(orientlist>>ccode>>cname>>cnature>>ctotaltime>>cthmtime>>cexptime>>ccredit>>cterm>>ctotalpeople>>cleftpeople)//判断该课程编号是否已被占用
	{
		if(strcmp(ccode,code)==0)//课程编号被占用
		{
			cout<<"您输入的编号与现有通选课编号重合，请重新输入："<<ends;
			goto BN;
		}
	}
	orientlist.close();//关闭通选课列表文件
	cout<<"请输入课程性质（19字符以内）："<<ends;
	cin>>nature;//输入课程性质
	clearcin();//清除缓存
	cout<<"请输入学分数："<<ends;
	cin>>credit;//输入学分书
	clearcin();//清除缓存
	cout<<"请输入开课学期（上/下）："<<ends;
	cin>>term;//输入开课学期
	clearcin();//清除缓存
	cout<<"请输入该课程可容纳的总人数："<<ends;
	cin>>totalpeople;//输入总人数
	clearcin();//清除缓存
	leftpeople=totalpeople;
	cout<<"请输入该课程总学时："<<ends;
	cin>>totaltime;//输入课程总学时
	clearcin();//清除缓存
	cout<<"请选择您接下来要输入的学时信息（另一项将由系统自动生成）："<<endl;
	cout<<"|1-理论学时"<<endl;
	cout<<"|2-实验或上机总学时"<<endl;
	cout<<"您的选择是："<<ends;
	BQ:cin>>choice;//输入选择
	clearcin();//清除缓存
	switch(choice)
	{
		case 1:
			{
				cout<<"请输入理论课总学时："<<ends;
				BO:cin>>thmtime;//输入理论学时
				clearcin();//清除缓存
				if(thmtime>totaltime)//理论课学时数大于总学时数
				{
					cout<<"理论课总学时不能大于总学时！请重新输入："<<ends;
					goto BO;
				}
				exptime=totaltime-thmtime;//计算实验或上机学时数
				break;
			}
		case 2:
			{
				cout<<"请输入实验或上机总学时："<<ends;
				BP:cin>>exptime;//输入实验或上机学时数
				clearcin();//清除缓存
				if(exptime>totaltime)//实验或上机学时数大于总学时数
				{
					cout<<"实验或上机课总学时不能大于总学时！请重新输入："<<ends;
					goto BP;
				}
				thmtime=totaltime-exptime;//计算理论学时数
				break;
			}
		default:
			{
				cout<<"您输入的标号有误！请重新输入："<<ends;
				goto BQ;
			}
	}
	chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\通选课列表.txt",ios::app);//打开通选课列表
	if(!chooseableclasslist)
	{
		kingerror();//文件不能打开
	}
	chooseableclasslist<<code<<'\t'<<classname<<'\t'<<nature<<'\t'<<totaltime<<'\t'<<thmtime<<'\t'<<exptime<<'\t'<<credit<<'\t'<<term<<'\t'<<totalpeople<<'\t'<<leftpeople<<'\n';//加入一条通选课记录
	chooseableclasslist.close();//关闭通选课列表文件
	teacherclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\任课.txt",ios::app);//打开任课列表
	if(!teacherclass)
	{
		kingerror();//文件不能打开
	}
	teacherclass<<targetteachername<<'\t'<<classname<<'\t'<<"通选"<<'\n';//写入一条新的任课记录
	teacherclass.close();//关闭任课列表文件
	char newscorelistfilename[2000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\课程成绩记录\\";//构建成绩单文件
	strcat_s(newscorelistfilename,classname);
	strcat_s(newscorelistfilename,"成绩.txt");
	newscorelist.open(newscorelistfilename,ios::out);
	if(!newscorelist)
	{
		kingerror();//file could not open
	}
	newscorelist<<"学号"<<'\t'<<"姓名"<<'\t'<<"成绩"<<'\n';//写入标题行
	newscorelist.close();//关闭成绩单文件
	char newstudentlistfilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\课程学生名单\\";//构建学生名单文件
	strcat_s(newstudentlistfilename,code);
	strcat_s(newstudentlistfilename,".txt");
	studentlist.open(newstudentlistfilename,ios::out);
	if(!studentlist)
	{
		kingerror();//文件不能打开
	}
	studentlist<<"学号"<<'\t'<<"学生名单"<<'\n';//写入标题行
	studentlist.close();//关闭学生名单文件
	cout<<"该通选课添课成功！"<<endl;
}
void addordinaryclass()//添加非通选课
{
	ifstream teacherlist,teachclass,studentlist;
	ofstream newscorefile,newstudentlist,teacherclass;
	char classname[50],nature[20],targetteachername[20];
	char number[20],name[20],gender[5],birth[11],department[50],job[10],phone[12],marry[5],homeadd[50];
	char cname[50],cnature[20];
	char title1[100],title2[100],title3[100];
	int i=0,mark=0,choice,salary,age;
	teacherlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\全部教职工名单.txt",ios::in);//打开全部教职工名单列表文件
	if(!teacherlist)
	{
		kingerror();//文件不能打开
	}
	teacherlist.seekg(0,ios::beg);
	teacherlist.getline(title1,100);
	cout<<"现在开始打印系统当中的教职工相关信息及其编号..."<<endl;
	cout<<"编号"<<'\t'<<"姓名"<<'\t'<<"所属部门"<<'\t'<<"职称"<<endl;
	while(teacherlist>>number>>name>>gender>>birth>>department>>job>>salary>>phone>>age>>marry>>homeadd)//打印教职工信息
	{
		cout<<i+1<<'\t'<<name<<'\t'<<department<<'\t'<<job<<endl;
		i++;
	}
	mark=i;
	i=0;
	cout<<"请选择您要选择的教师编号："<<ends;
	BR:cin>>choice;//输入任课教师编号
	clearcin();//清除缓存
	choice--;
	if((choice<0)||(choice>mark-1))//序号不在列表当中
	{
		cout<<"您所输入的序号不在列表当中！请重新输入："<<ends;
		goto BR;
	}
	teacherlist.close();//关闭教职工列表文件
	teacherlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\全部教职工名单.txt",ios::in);//打开教职工列表文件
	if(!teacherlist)
	{
		kingerror();//文件不能打开
	}
	teacherlist.seekg(0,ios::beg);
	teacherlist.getline(title1,100);
	while(teacherlist>>number>>name>>gender>>birth>>department>>job>>salary>>phone>>age>>marry>>homeadd)//获取任课教师名
	{
		if(choice==i)
		{
			strcpy_s(targetteachername,name);
			break;
		}
		i++;
	}
	teacherlist.close();//关闭教职工列表文件
	teachclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\任课.txt",ios::in);//打开任课列表文件
	if(!teachclass)
	{
		kingerror();//文件不能打开
	}
	cout<<"请输入课程名称（49字符以内）："<<ends;
	BT:cin>>classname;//输入课程名称
	clearcin();//清除缓存
	teachclass.seekg(0,ios::beg);
	teachclass.getline(title2,100);
	while(teachclass>>name>>cname>>cnature)//判断该课程是否已经有人任教
	{
		if(strcmp(cname,classname)==0)//该课程已经有人任教
		{
			cout<<"该课程已经有教职工任教！请重新输入课程名称："<<ends;
			goto BT;
		}
	}
	teachclass.close();//关闭任课列表
	cout<<"请输入课程性质："<<ends;
	BU:cin>>nature;//输入课程性质
	clearcin();//清除缓存
	if(strcmp(nature,"通选")==0)//判断课程性质是否为通选
	{
		cout<<"现在正在录入非通选课！请重新输入课程性质："<<ends;
		goto BU;
	}
	teacherclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\任课.txt",ios::app);//打开任课列表文件
	if(!teacherclass)
	{
		kingerror();//文件不能打开
	}
	teacherclass<<targetteachername<<'\t'<<classname<<'\t'<<nature<<'\n';//写入一条任课记录
	teacherclass.close();//关闭任课列表文件
	char newscorelistfilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\课程成绩记录\\";//构造成绩单文件文件名
	strcat_s(newscorelistfilename,classname);
	strcat_s(newscorelistfilename,"成绩.txt");
	newscorefile.open(newscorelistfilename,ios::out);//打开成绩单文件
	if(!newscorefile)
	{
		kingerror();//文件不能打开
	}
	newscorefile<<"学号"<<'\t'<<"姓名"<<'\t'<<"成绩"<<'\n';//写入标题行
	newscorefile.close();//关闭成绩单文件
	struct onestudent//构造一条上课学生信息记录链表节点结构
	{
		int code;
		char stunumber[12];
		char stuname[20];
		onestudent *next;
	};
	studentlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\学生档案\\全部学生名单.txt",ios::in);//打开学生列表文件
	if(!studentlist)
	{
		kingerror();//文件不能打开
	}
	studentlist.seekg(0,ios::beg);
	studentlist.getline(title3,100);
	char newstudentlistfilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\课程学生名单\\";//构造学生名单文件名
	strcat_s(newstudentlistfilename,classname);
	strcat_s(newstudentlistfilename,"学生名单.txt");
	newstudentlist.open(newstudentlistfilename,ios::out);//打开课程学生名单
	if(!newstudentlist)
	{
		kingerror();//文件不能打开
	}
	newstudentlist<<"学号"<<'\t'<<"学生名单"<<'\n';//写入标题行
	char studentname[20],studentnumber[12],studentgender[5],studentbirth[12],studentmajor[20],studentclass[20],studenthome[50],studentdorm[50];
	int input=0,j=0,want=0;
	onestudent *head,*a,*b;
	head=new onestudent;
	a=head;
	a->next=NULL;
	cout<<"现在开始打印系统当中的全部学生信息及其编号..."<<endl;
	cout<<"编号"<<'\t'<<"姓名"<<'\t'<<"学号"<<'\t'<<"性别"<<'\t'<<"出生日期"<<'\t'<<"专业"<<'\t'<<"班级"<<'\t'<<"家庭住址"<<'\t'<<"宿舍号码"<<endl;
	while(studentlist>>studentname>>studentnumber>>studentgender>>studentbirth>>studentmajor>>studentclass>>studenthome>>studentdorm)//打印学生名单并构造链表
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
	studentlist.close();//关闭学生名单文件
	while(1)
	{
		cout<<"请输入需要进入该课程的学生编号（按Ctrl+Z结束输入）："<<ends;
		BW:if(cin>>want)//输入上课学生的编号
		{
			want--;
			if((want<0)||(want>mark-1))//输入的编号超出列表范围
			{
				cout<<"您输入的标号不在列表当中哦！请重新输入："<<ends;
				goto BW;
			}
			while(a->code!=want)//查找学生
			{
				a=a->next;
			}
			newstudentlist<<a->stunumber<<'\t'<<a->stuname<<'\n';//写入一条上课学生记录
			a=head;
		}
		else
		{
			goto BV;
		}
	}
	BV:clearcin();//清除缓存
	newstudentlist.close();//关闭课程学生名单文件
	while(head->next!=NULL)//销毁学生名单链表
	{
		a=head;
		head=head->next;
		delete a;
	}
	delete head;
	a=NULL;
	head=NULL;
	cout<<classname<<"课程添课成功！"<<endl;
}
void watchallemails()//查看所有电子邮件记录
{
	ifstream emailfile;
	char title[100],time[32],sender[20],reciever[20],emailtitle[50],content[500];
	emailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\电子邮件来往信件记录.txt",ios::in);//打开系统电子邮件信件记录文件
	if(!emailfile)
	{
		kingerror();//文件不能打开
	}
	emailfile.seekg(0,ios::beg);
	emailfile.getline(title,100);
	cout<<"现在开始打印所有邮件记录..."<<endl;
	while(emailfile>>time>>sender>>reciever>>emailtitle>>content)//打印电子邮件来往信件记录
	{
		cout<<"========================================================================"<<endl;
		cout<<"发送时间："<<time<<endl;
		cout<<"寄件人："<<sender<<endl;
		cout<<"收件人："<<reciever<<endl;
		cout<<"邮件标题："<<emailtitle<<endl;
		cout<<"邮件内容：\n"<<content<<endl;
	}
	emailfile.close();//关闭电子邮件文件
	cout<<"所有信件内容显示完毕！"<<endl;
}
void watchallstudents()
{
	char name[20],number[12],gender[5],birth[11],major[20],class_[20],add[50],dorm[50],title[100];
	ifstream studentlist;
	studentlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\学生档案\\全部学生名单.txt",ios::in);//打开全部学生名单文件
	if(!studentlist)
	{
		kingerror();//文件不能打开
	}
	studentlist.seekg(0,ios::beg);
	studentlist.getline(title,100);
	cout<<"现在开始打印系统当中全部注册了的学生名单..."<<endl;
	cout<<"姓名"<<'\t'<<"学号"<<'\t'<<"性别"<<'\t'<<"出生日期"<<'\t'<<"专业"<<'\t'<<"所属班级"<<'\t'<<"家庭地址"<<'\t'<<"宿舍号码"<<endl;
	while(studentlist>>name>>number>>gender>>birth>>major>>class_>>add>>dorm)//打印全部学生名单
	{
		cout<<name<<'\t'<<number<<'\t'<<gender<<'\t'<<birth<<'\t'<<major<<'\t'<<class_<<'\t'<<add<<'\t'<<dorm<<endl;
	}
	studentlist.close();//关闭学生名单文件
	cout<<"所有学生名单打印完毕！"<<endl;
}
void watchallfaculty()
{
	char number[20],name[20],gender[5],birth[11],depart[50],job[20],phone[12],marry[5],add[50],title[100];
	int wage,age;
	ifstream facultylist;
	facultylist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\全部教职工名单.txt",ios::in);//打开教职工名单文件
	if(!facultylist)
	{
		kingerror();//文件不能打开
	}
	facultylist.seekg(0,ios::beg);
	facultylist.getline(title,100);
	cout<<"现在开始打印系统中注册了的教职工名单..."<<endl;
	cout<<"编号"<<'\t'<<"姓名"<<'\t'<<"性别"<<'\t'<<"出生日期"<<'\t'<<"所在部门"<<'\t'<<"职称"<<'\t'<<"工资级别"<<'\t'<<"电话"<<'\t'<<"年龄"<<'\t'<<"婚姻状况"<<'\t'<<"家庭住址"<<endl;
	while(facultylist>>number>>name>>gender>>birth>>depart>>job>>wage>>phone>>age>>marry>>add)//打印全部教职工名单
	{
		cout<<number<<'\t'<<name<<'\t'<<gender<<'\t'<<birth<<'\t'<<depart<<'\t'<<job<<'\t'<<wage<<'\t'<<phone<<'\t'<<age<<'\t'<<marry<<'\t'<<add<<endl;
	}
	facultylist.close();//关闭教职工名单文件
	cout<<"所有教职工名单显示完毕！"<<endl;
}
void watchclass()
{
	char teacher[20],name[50],nature[20],title[100];
	ifstream classfile;
	classfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\任课.txt",ios::in);//打开教师任课文件
	if(!classfile)
	{
		kingerror();//文件不能打开
	}
	classfile.seekg(0,ios::beg);
	classfile.getline(title,100);
	cout<<"现在开始打印教职工任课情况..."<<endl;
	cout<<"教师"<<'\t'<<"课程"<<'\t'<<"性质"<<endl;
	while(classfile>>teacher>>name>>nature)//打印任课情况
	{
		cout<<teacher<<'\t'<<name<<'\t'<<nature<<endl;
	}
	classfile.close();//关闭任课情况文件
	cout<<"所有任课情况显示完毕！"<<endl;
}
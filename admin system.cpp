#include<iostream>
#include<fstream>
#include"clarify administrator functions.h"
#include"clarify main functions.h"
#include<string.h>
#include<ctime>
using namespace std;
void teachererror()//异常处理
{
	cout<<"系统文件打开出错！程序将自动关闭，请立即请开发人员调试系统！"<<endl;//exit system completely
	system("pause");
	exit(0);//直接退出系统
}
bool teacherlogin(char teachername[])//教职工登陆
{
	int teachercondition=0,teacherpasswordcondition,choice;
	char teacherpassword[20],currenttime[32];
	AE:cout<<"您的姓名："<<ends;
	cin>>teachername;//输入姓名
	clearcin();//清除缓存
	cout<<"您的密码口令："<<ends;
	AD:cin>>teacherpassword;//输入密码
	clearcin();//清除缓存
	if(strcmp("Admin",teachername)==0)//使用默认账号登陆
	{
		if(strcmp("666666",teacherpassword)==0)
			goto AC;
		else//输入有误
		{
			cout<<"Admin的密码为666666！请重新输入："<<ends;
			goto AD;
		}
	}
	else
	{
		teachercondition=findfaculty(teachername);//查找教师是否在教职工列表当中
		if(teachercondition==0)//找不到
		{
			cout<<"对不起，在系统当中没有找到您的记录，请先用Admin登陆后注册！"<<endl;
			goto AE;
		}
		else
		{
			teacherpasswordcondition=cmppassword(teachername,teacherpassword);//对比密码是否正确
			if(teacherpasswordcondition==0)//密码错误
			{
				cout<<"对不起，您输入的密码有误。"<<endl;
				cout<<"请问您要继续登陆还是退出？"<<endl;
				cout<<"|1-继续登陆"<<endl;
				cout<<"|2-退出登陆"<<endl;
				cout<<"请输入您的选择标号："<<ends;
				AH:cin>>choice;
				clearcin();//清除缓存
				switch(choice)
				{
					case 1:
						{
							cout<<"请输入您的密码："<<ends;
							goto AD;
						}
					case 2:return false;
					default:
						{
							cout<<"您的输入有误哦！是不是不清醒呢？请重新输入把："<<ends;
							goto AH;
						}
				}
			}
		}
	}
	AC:cout<<"登陆成功！"<<endl;
	ofstream loginfile;
	loginfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\登陆日志.txt",ios::app);//打开系统登陆日志文件
	if(!loginfile)
	{
		teachererror();//文件不能打开
	}
	getlocaltime(currenttime);//获得本地时间
	loginfile<<currenttime<<'\t'<<teachername<<'\t'<<"教职工"<<'\n';//写一条登陆记录
	loginfile.close();//关闭登陆日志文件
	cout<<teachername<<"，欢迎你！"<<endl;
	return true;
}
int findfaculty(char teachername[])//判断教师是否在教职工列表当中
{
	ifstream facultyaccountdata;
	char title[100],name[20],password[20];
	int result=0;
	facultyaccountdata.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\教职工账户与密码.txt",ios::in);//打开教职工账户列表文件
	if(!facultyaccountdata)
	{
		teachererror();//文件不能打开
	}
	facultyaccountdata.seekg(0,ios::beg);
	facultyaccountdata.getline(title,100);
	while(facultyaccountdata>>name>>password)//开始查找教师
	{
		if(strcmp(name,teachername)==0)//找到该教师了
		{
			result=1;
			break;
		}
	}
	return result;
}
int cmppassword(char teachername[],char teacherpassword[])//对比密码是否正确
{
	ifstream accountdata;
	char title[100],tname[20],tpass[20];
	int result=0;
	accountdata.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\教职工账户与密码.txt",ios::in);//打开教职工账户密码文件
	if(!accountdata)
	{
		teachererror();//文件不能打开
	}
	accountdata.seekg(0,ios::beg);
	accountdata.getline(title,100);
	while(accountdata>>tname>>tpass)//查找教师
	{
		if(strcmp(teachername,tname)==0)//找到教师
		{
			if(strcmp(tpass,teacherpassword)==0)//对比密码
			{
				result=1;
				break;
			}
		}
	}
	accountdata.close();//关闭教职工账户文件
	return result;
}
void teacherfunction(char teachername[])//教师功能选择界面
{
	int choice;
	while(1)//choose function
	{
		cout<<"下面是功能列表，请你选择你需要操作的项目。"<<endl;
		cout<<"|1-注册新教职工"<<endl;
		cout<<"|2-注册新学生"<<endl;
		cout<<"|3-查看个人档案"<<endl;
		cout<<"|4-学生上课考勤记录"<<endl;
		cout<<"|5-学生成绩录入"<<endl;
		cout<<"|6-发布公告"<<endl;
		cout<<"|7-答复留言板"<<endl;
		cout<<"|8-电子邮件系统"<<endl;
		cout<<"|9-修改密码"<<endl;
		cout<<"|10-退出"<<endl;
		cout<<"请输入您的选择："<<ends;
		AJ:cin>>choice;
		clearcin();//清除缓存
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
					cout<<"您输入有误哦！请重新输入："<<ends;
					goto AJ;
				}
		}
		cout<<endl;
	}
	AI:;
}
void registnewfaculty(char teachername[])//注册新的教职工
{
	char facultynumber[20],facultyname[20],facultygender[5],facultybirthday[11],facultydepartment[50],facultyjob[10],facultyphone[12],facultymarry[5],facultyhomeadd[50],currenttime[32],title[100];
	int facultywagelevel,facultyage;
	char number[20],name[20],gender[5],birthday[11],department[50],job[10],phone[12],marry[5],homeadd[50];
	int wage,age;
	cout<<"请输入新教职员工姓名："<<ends;
	BX:cin>>facultyname;//新教职工姓名
	clearcin();//清除缓存
	ifstream testfile;
	testfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\全部教职工名单.txt",ios::in);//打开系统教职工登陆账户列表文件
	if(!testfile)
	{
		teachererror();//文件不能打开
	}
	testfile.seekg(0,ios::beg);
	testfile.getline(title,100);
	while(testfile>>number>>name>>gender>>birthday>>department>>job>>wage>>phone>>age>>marry>>homeadd)//查找该教职工是否在列表当中
	{
		if(strcmp(name,facultyname)==0)//在，表明已经注册
		{
			testfile.close();//关闭教职工账户列表文件
			cout<<"该教职工已经注册！请重新输入姓名："<<ends;
			goto BX;
		}
	}
	testfile.close();//关闭教职工账户列表文件
	ofstream newfacultyprofile,operationfile;
	cout<<"请输入"<<facultyname<<"的编号："<<ends;
	CA:cin>>facultynumber;//输入新教职员工编号
	clearcin();//清除缓存
	testfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\全部教职工名单.txt",ios::in);//打开系统教职工登陆账户列表文件
	if(!testfile)
	{
		teachererror();//文件不能打开
	}
	testfile.seekg(0,ios::beg);
	testfile.getline(title,100);
	while(testfile>>number>>name>>gender>>birthday>>department>>job>>wage>>phone>>age>>marry>>homeadd)//判断该编号是否已被使用
	{
		if(strcmp(number,facultynumber)==0)//该编号已被使用
		{
			testfile.close();//关闭教职工账户信息文件
			cout<<"该职工编号已被占用！请重新输入编号："<<ends;
			goto CA;
		}
	}
	testfile.close();//关闭教职工账户信息文件
	cout<<"请输入"<<facultyname<<"的性别（男/女）："<<ends;
	cin>>facultygender;//输入新教职工性别
	clearcin();//清除缓存
	cout<<"请输入"<<facultyname<<"的出生日期(yyyy-mm-dd)："<<ends;
	cin>>facultybirthday;//输入新教职工出生日期
	clearcin();//清除缓存
	cout<<"请输入"<<facultyname<<"的所在部门："<<ends;
	cin>>facultydepartment;//输入新教职工所在部门
	clearcin();//清除缓存
	cout<<"请输入"<<facultyname<<"的职称："<<ends;
	cin>>facultyjob;//输入新教职工的职称
	clearcin();//清除缓存
	cout<<"请输入"<<facultyname<<"的工资级别："<<ends;
	cin>>facultywagelevel;//输入新教职工的工资级别
	clearcin();//清除缓存
	cout<<"请输入"<<facultyname<<"的电话："<<ends;
	CB:cin>>facultyphone;//输入新教职工的电话号码
	clearcin();//清除缓存
	testfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\全部教职工名单.txt",ios::in);//打开系统教职工名单文件
	if(!testfile)
	{
		teachererror();//文件不能打开
	}
	testfile.seekg(0,ios::beg);
	testfile.getline(title,100);
	while(testfile>>number>>name>>gender>>birthday>>department>>job>>wage>>phone>>age>>marry>>homeadd)
	{
		if(strcmp(phone,facultyphone)==0)//电话号码被使用
		{
			testfile.close();//关闭教职工账户信息文件
			cout<<"该电话号码已被占用！请重新输入电话号码："<<ends;
			goto CB;
		}
	}
	testfile.close();//关闭教职工账户信息文件
	cout<<"请输入"<<facultyname<<"的年龄："<<ends;
	cin>>facultyage;//输入新教职工年龄
	clearcin();//清除缓存
	cout<<"请输入"<<facultyname<<"的婚姻状况："<<ends;
	cin>>facultymarry;//输入新教职工的婚姻状况
	clearcin();//清除缓存
	cout<<"请输入"<<facultyname<<"的家庭住址："<<ends;
	cin>>facultyhomeadd;//输入新教职工的家庭地址
	clearcin();//清除缓存
	newfacultyprofile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\全部教职工名单.txt",ios::app);//打开系统教职工名单文件进行添加
	if(!newfacultyprofile)
	{
		teachererror();//文件不能打开
	}
	getlocaltime(currenttime);//获得本地时间
	newfacultyprofile<<facultynumber<<'\t'<<facultyname<<'\t'<<facultygender<<'\t'<<facultybirthday<<'\t'<<facultydepartment<<'\t'<<facultyjob<<'\t'<<facultywagelevel<<'\t'<<facultyphone<<'\t'<<facultyage<<'\t'<<facultymarry<<'\t'<<facultyhomeadd<<'\n';//写入新的教职工记录
	newfacultyprofile.close();//close file
	newfacultyprofile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\教职工账户与密码.txt",ios::app);//打开教职工账户密码文件
	if(!newfacultyprofile)
	{
		teachererror();//文件不能打开
	}
	newfacultyprofile<<facultyname<<'\t'<<"666666"<<'\n';//写入一条新的教职工账户信息
	newfacultyprofile.close();//关闭教职工账户密码文件
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		teachererror();//文件不能打开
	}
	operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"创建了教职工账户"<<facultyname<<'\n';//写入一条操作记录
	operationfile.close();//关闭系统操作日志文件
	cout<<"教职工"<<facultyname<<"注册成功！其初始账户密码为666666，请提醒该职工尽快修改密码！"<<endl;//温馨提示
}
void registstudent(char teachername[])//注册新学生
{
	ofstream operationfile,newstudentprofile,newscorefile;
	ifstream testfile;
	char studentname[20],studentnumber[12],studentgender[5],studentbirthday[11],studentmajor[20],studentclass[20],studentadd[50],studentdorm[50],currenttime[32];
	char title[100],name[20],number[12],gender[5],birthday[11],major[20],class_[20],address[50],dorm[50];
	cout<<"请输入需要注册的学生姓名："<<ends;
	BY:cin>>studentname;//输入新学生姓名
	clearcin();//清除缓存
	testfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\学生档案\\全部学生名单.txt",ios::in);//打开系统学生名单文件
	if(!testfile)
	{
		teachererror();//文件不能打开
	}
	testfile.seekg(0,ios::beg);
	testfile.getline(title,100);
	while(testfile>>name>>number>>gender>>birthday>>major>>class_>>address>>dorm)//判断该学生是否已被注册
	{
		if(strcmp(name,studentname)==0)//该学生已被注册
		{
			testfile.close();//关闭学生列表文件
			cout<<"该学生已经注册！请重新输入姓名（19字符以内）："<<ends;
			goto BY;
		}
	}
	testfile.close();//关闭学生列表文件
	cout<<"请输入"<<studentname<<"的学号（11字符以内）："<<ends;
	BZ:cin>>studentnumber;//输入新学生学号
	clearcin();//清除缓存
	testfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\学生档案\\全部学生名单.txt",ios::in);//打开系统学生列表文件
	if(!testfile)
	{
		teachererror();//文件不能打开
	}
	testfile.seekg(0,ios::beg);
	testfile.getline(title,100);
	while(testfile>>name>>number>>gender>>birthday>>major>>class_>>address>>dorm)//判断该学号是否已被使用
	{
		if(strcmp(number,studentnumber)==0)//该学号已被使用
		{
			testfile.close();//关闭学生列表文件
			cout<<"该学号已被占用！请重新输入学号："<<ends;
			goto BZ;
		}
	}
	testfile.close();//关闭学生列表文件
	cout<<"请输入"<<studentname<<"的性别（男/女）："<<ends;
	cin>>studentgender;//输入新学生性别
	clearcin();//清除缓存
	cout<<"请输入"<<studentname<<"的出生年月(yyyy-mm-dd)："<<ends;
	cin>>studentbirthday;//输入新学生出生日期
	clearcin();//清除缓存
	cout<<"请输入"<<studentname<<"的专业："<<ends;
	cin>>studentmajor;//输入新学生的专业
	clearcin();//清除缓存
	cout<<"请输入"<<studentname<<"的班级："<<ends;
	cin>>studentclass;//输入新学生所属班级
	clearcin();//清除缓存
	cout<<"请输入"<<studentname<<"的家庭住址："<<ends;
	cin>>studentadd;
	clearcin();//clear buff
	cout<<"请输入"<<studentname<<"的宿舍地址："<<ends;
	cin>>studentdorm;//输入新学生宿舍地址
	clearcin();//清除缓存
	getlocaltime(currenttime);//获得本地时间
	newstudentprofile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\学生档案\\全部学生名单.txt",ios::app);//打开系统全部学生名单文件
	if(!newstudentprofile)
	{
		teachererror();//文件不能打开
	}
	newstudentprofile<<studentname<<'\t'<<studentnumber<<'\t'<<studentgender<<'\t'<<studentbirthday<<'\t'<<studentmajor<<'\t'<<studentclass<<'\t'<<studentadd<<'\t'<<studentdorm<<'\n';//写入一条新的学生记录
	newstudentprofile.close();//关闭学生名单列表文件
	newstudentprofile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\学生账户与密码.txt",ios::app);//打开系统学生账户密码文件
	if(!newstudentprofile)
	{
		teachererror();//文件不能打开
	}
	newstudentprofile<<studentname<<'\t'<<"666666"<<'\n';//写入新学生账户，密码为666666
	newstudentprofile.close();//关闭学生账户密码文件
	char newscorefilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\学生档案\\";//准备成绩文件路径
	strcat_s(newscorefilename,studentname);//构造成绩文件路径
	strcat_s(newscorefilename,"学生成绩.txt");
	newscorefile.open(newscorefilename,ios::out);//新建学生成绩文件
	if(!newscorefile)
	{
		teachererror();//文件不能打开
	}
	newscorefile<<"课程名称"<<'\t'<<"成绩"<<'\n';
	newscorefile.close();//关闭新建的学生成绩文件
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		teachererror();//文件无法打开
	}
	operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"注册了学生"<<studentname<<'\n';//写入一条操作记录
	operationfile.close();//关闭系统操作日志文件
	cout<<"学生"<<studentname<<"注册成功！初始密码为666666，请及时联系该学生修改密码！"<<endl;//温馨提示
}
void watchfacultyprofile(char teachername[])//查看教职工个人档案
{
	ofstream operationfile;
	ifstream facultyprofile;
	char title[100],number[20],name[20],gender[5],birthday[11],department[50],job[10],phone[12],marry[5],homeadd[50],currenttime[32];
	int age,wagelevel,choice;
	facultyprofile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\全部教职工名单.txt",ios::in);//打开教职工档案文件
	if(!facultyprofile)
	{
		teachererror();//文件不能打开
	}
	facultyprofile.seekg(0,ios::beg);
	facultyprofile.getline(title,100);
	getlocaltime(currenttime);
	cout<<"现在开始打印你的个人档案..."<<endl;
	while(facultyprofile>>number>>name>>gender>>birthday>>department>>job>>wagelevel>>phone>>age>>marry>>homeadd)//搜索教职工
	{
		if(strcmp(name,teachername)==0)//找到该教职工
		{
			cout<<"编号："<<number<<endl;
			cout<<"性别："<<gender<<endl;
			cout<<"生日："<<birthday<<endl;
			cout<<"所在部门："<<department<<endl;
			cout<<"职务："<<job<<endl;
			cout<<"工资水平："<<wagelevel<<endl;
			cout<<"电话号码："<<phone<<endl;
			cout<<"年龄："<<age<<endl;
			cout<<"婚姻状况："<<marry<<endl;
			cout<<"家庭地址："<<homeadd<<endl;
			break;
		}
	}
	facultyprofile.close();//关闭教职工档案文件
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		teachererror();//文件不能打开
	}
	operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"查看个人档案"<<'\n';//写入一条操作记录
	operationfile.close();//关闭系统操作日志文件
	cout<<"个人档案显示完毕！"<<endl;
	cout<<"您是否需要修改档案（是请输入1，否则输入0）："<<ends;
	AK:cin>>choice;//输入是否选择修改档案
	clearcin();//清除缓存
	switch(choice)
	{
		case 1:resetfacultyprofile(teachername);break;//修改档案
		case 0:break;
		default:
			{
				cout<<"您的输入有误哦！请重新输入："<<ends;
				goto AK;
			}
	}
}
void resetfacultyprofile(char teachername[])//修改个人档案
{
	ifstream orientfile;
	ofstream operationfile,newfile;
	char number[20],name[20],gender[5],birthday[11],department[50],job[10],phone[12],marry[5],homeaddress[50],currenttime[32],title[100];
	int wagelevel,age,choice;
	struct facultyprofile//构造教职工档案链表节点结构
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
	orientfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\全部教职工名单.txt",ios::in);
	if(!orientfile)
	{
		teachererror();//file could not open
	}
	orientfile.seekg(0,ios::beg);
	orientfile.getline(title,100);
	head=new facultyprofile;
	a=head;
	while(orientfile>>number>>name>>gender>>birthday>>department>>job>>wagelevel>>phone>>age>>marry>>homeaddress)//创建教职工个人信息链表
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
	orientfile.close();//关闭教职工档案列表文件
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		teachererror();//文件不能打开
	}
	newfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\全部教职工名单.txt",ios::out);//打开新教职工档案列表文件
	if(!newfile)
	{
		teachererror();//文件不能打开
	}
	while(strcmp(a->fname,teachername)!=0)//查找该教职工
	{
		a=a->next;
	}
	while(1)//开始修改个人档案
	{
		cout<<"请选择您需要修改的选项："<<endl;
		cout<<"|1-性别"<<endl;
		cout<<"|2-出生日期"<<endl;
		cout<<"|3-所属部门"<<endl;
		cout<<"|4-职称"<<endl;
		cout<<"|5-工资级别"<<endl;
		cout<<"|6-电话"<<endl;
		cout<<"|7-年龄"<<endl;
		cout<<"|8-婚姻状况"<<endl;
		cout<<"|9-家庭住址"<<endl;
		cout<<"|10-退出修改状态"<<endl;
		cout<<"您的选择是："<<ends;
		AN:cin>>choice;
		clearcin();//清除缓存
		switch(choice)
		{
			case 1:
				{
					cout<<"请输入您的新性别（男/女）："<<ends;
					cin>>gender;//输入新性别
					clearcin();//清除缓存
					strcpy_s(a->sex,gender);
					getlocaltime(currenttime);//获得本地时间
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"修改个人档案--性别"<<'\n';//写入一条操作记录
					break;
				}
			case 2:
				{
					cout<<"请输入您的新出生日期（yyyy-mm-dd）："<<endl;
					cin>>birthday;//输入新出生日期
					clearcin();//清除缓存
					strcpy_s(a->birth,birthday);
					getlocaltime(currenttime);//获得本地时间
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"修改个人档案--出生日期"<<'\n';//写入一条操作记录
					break;
				}
			case 3:
				{
					cout<<"请输入您的新所属部门（49字符以内）："<<ends;
					cin>>department;//输入新所属部门
					clearcin();//清除缓存
					strcpy_s(a->depart,department);
					getlocaltime(currenttime);//获得本地时间
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"修改个人档案--所在部门"<<'\n';//写入一条操作记录
					break;
				}
			case 4:
				{
					cout<<"请输入您的新职称（9字符以内）："<<ends;
					cin>>job;//输入新职称
					clearcin();//清除缓存
					strcpy_s(a->fjob,job);
					getlocaltime(currenttime);//获得本地时间
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"修改个人档案--职称"<<'\n';//写入一条操作记录
					break;
				}
			case 5:
				{
					cout<<"请输入您的新工资水平："<<ends;
					cin>>wagelevel;//输入新的工资水平
					clearcin();//清除缓存
					a->wage=wagelevel;
					getlocaltime(currenttime);//获得本地时间
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"修改个人档案--工资水平"<<'\n';//写入一条操作记录
					break;
				}
			case 6:
				{
					cout<<"请输入您的新电话（11字符以内）："<<ends;
					cin>>phone;//输入新电话
					clearcin();//清除缓存
					strcpy_s(a->tel,phone);
					getlocaltime(currenttime);//获得本地时间
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"修改个人档案--电话"<<'\n';//写入一条新记录
					break;
				}
			case 7:
				{
					cout<<"请输入您的新年龄："<<ends;
					cin>>age;//输入新年龄
					clearcin();//清除缓存
					a->fage=age;
					getlocaltime(currenttime);
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"修改个人档案--年龄"<<'\n';
					break;
				}
			case 8:
				{
					cout<<"请输入您的新婚姻状况（4字符以内）："<<ends;
					cin>>marry;//输入新婚姻状况
					clearcin();//清除缓存
					strcpy_s(a->marriage,marry);
					getlocaltime(currenttime);//获得本地时间
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"修改个人档案--婚姻状况"<<'\n';//写入一条操作记录
					break;
				}
			case 9:
				{
					cout<<"请输入您的新家庭住址（49字符以内）："<<ends;
					cin>>homeaddress;//输入新家庭地址
					clearcin();//清除缓存
					strcpy_s(a->address,homeaddress);
					getlocaltime(currenttime);//获得本地时间
					operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"修改个人档案--家庭住址"<<'\n';//写入一条新记录
					break;
				}
			case 10:
				{
					goto AM;
				}
			default:
				{
					cout<<"您输入有误，请重新输入："<<ends;
					goto AN;
				}
		}
	}
	AM:a=head;
	operationfile.close();//关闭系统操作日志文件
	newfile<<"编号"<<'\t'<<"姓名"<<'\t'<<"性别"<<'\t'<<"出生日期"<<'\t'<<"所在部门"<<'\t'<<"职称"<<'\t'<<"工资级别"<<'\t'<<"电话"<<'\t'<<"年龄"<<'\t'<<"婚姻状况"<<'\t'<<"家庭住址"<<'\n';//写入标题行
	while(a->next!=NULL)//写入新的教职工档案列表
	{
		newfile<<a->num<<'\t'<<a->fname<<'\t'<<a->sex<<'\t'<<a->birth<<'\t'<<a->depart<<'\t'<<a->fjob<<'\t'<<a->wage<<'\t'<<a->tel<<'\t'<<a->fage<<'\t'<<a->marriage<<'\t'<<a->address<<'\n';
		a=a->next;
	}
	newfile.close();//关闭教职工档案列表文件
	a=head;
	while(head->next!=NULL)//销毁教职工档案链表
	{
		a=head;
		head=head->next;
		delete a;
	}
	delete head;
	a=NULL;
	head=NULL;
	cout<<"档案修改完成！"<<endl;
}
void setgotoclassrecord(char teachername[])//设置考勤记录
{
	ifstream myclass,classstudents;
	ofstream operationfile,gotoclassrecord;
	char currenttime[32],title1[100],teachname[20],classname[50],title2[100],nature[20];
	int i=0,mark=0;
	cout<<"欢迎使用考勤记录系统..."<<endl;
	myclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\任课.txt",ios::in);//打来系统任课名单文件
	if(!myclass)
	{
		teachererror();//文件不能打开
	}
	myclass.seekg(0,ios::beg);
	myclass.getline(title1,100);
	cout<<teachername<<"，您有以下课程可以进行考勤记录："<<endl;
	while(myclass>>teachname>>classname>>nature)//打印可以考勤的课程名单
	{
		if(strcmp(teachname,teachername)==0)
		{
			cout<<"|"<<i+1<<"-"<<classname<<endl;
			i++;
		}
	}
	myclass.close();//关闭任课名单文件
	if(i==0)//没有任教任何课程
	{
		cout<<"您没有任教任何课程！"<<endl;
	}
	else
	{
		mark=i;
		myclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\任课.txt",ios::in);//打开任课名单文件
		if(!myclass)
		{
			teachererror();//文件不能打开
		}
		char wantclass[50],studentnumber[20],studentname[20],conditionstr[5],classtime[11],cnature[20];
		int condition=0,want;
		while(1)
		{
			cout<<"请输入您需要进行考勤的班级代号（按Ctrl+Z退出）："<<ends;//开始考勤
			BE:if(cin>>want)
			{
				clearcin();//清除缓存
				if((want>mark)||(want<1))//输入编号不在列表范围内
				{
					cout<<"您输入的标号不在列表当中，请重新输入："<<ends;
					goto BE;
				}
				myclass.seekg(0,ios::beg);
				myclass.getline(title1,100);
				i=0;
				while(myclass>>teachname>>classname>>nature)//查找该课程
				{
					if(strcmp(teachname,teachername)==0)//找到任课教师
					{
						if(i==want-1)//找到目标课程
						{
							strcpy_s(wantclass,classname);
							strcpy_s(cnature,nature);
							break;
						}
						i++;
					}
				}
				myclass.close();//关闭任课列表文件
				getlocaltime(currenttime);//获得本地时间
				cout<<"请输入上课日期："<<ends;
				cin>>classtime;//输入上课日期
				clearcin();//清除缓存
				char classstulistfilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\课程学生名单\\";//准备课程学生名单文件名
				if(strcmp(cnature,"通选")==0)//该课程为通选课
				{
					char ccode[8],cname[50],cn[20],cterm[10],targetcode[8],title4[100];
					int ctotaltime,ctheorytime,cexptime,ccredit,ctotalpeople,cleftpeople;
					ifstream chooseableclasslist;
					chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\通选课列表.txt",ios::in);//打开通选课列表文件
					if(!chooseableclasslist)
					{
						teachererror();//文件不能打开
					}
					chooseableclasslist.seekg(0,ios::beg);
					chooseableclasslist.getline(title4,100);
					while(chooseableclasslist>>ccode>>cname>>cn>>ctotaltime>>ctheorytime>>cexptime>>ccredit>>cterm>>ctotalpeople>>cleftpeople)//查找对应课程的通选课编号
					{
						if(strcmp(cname,wantclass)==0)//找到该课程
						{
							strcpy_s(targetcode,ccode);
							break;
						}
					}
					chooseableclasslist.close();//关闭通选课列表文件
					strcat_s(classstulistfilename,targetcode);//构建课程学生名单文件名
					strcat_s(classstulistfilename,".txt");
				}
				else
				{
					strcat_s(classstulistfilename,wantclass);//构建课程学生名单文件名
					strcat_s(classstulistfilename,"学生名单.txt");
				}
				classstudents.open(classstulistfilename,ios::in);//打开课程学生名单文件
				gotoclassrecord.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\课程考勤记录.txt",ios::app);//打开系统考勤记录文件
				if(!gotoclassrecord)
				{
					teachererror();//文件不能打开
				}
				if(!classstudents)
				{
					teachererror();//文件不能打开
				}
				classstudents.seekg(0,ios::beg);
				classstudents.getline(title2,100);
				cout<<wantclass<<"课程学生名单已载入，开始录入考勤情况..."<<endl;
				cout<<"考勤状态对应规则："<<endl;
				cout<<"|0-旷课"<<endl;
				cout<<"|1-到课"<<endl;
				cout<<"|2-请假"<<endl;
				cout<<"请按照上面的规则进行录入！"<<endl;
				cout<<"开始录入..."<<endl;
				while(classstudents>>studentnumber>>studentname)//录入考勤状态
				{
					cout<<"学号为"<<studentnumber<<"的学生“"<<studentname<<"”的考勤情况为："<<ends;
					AO:cin>>condition;//录入单个学生考勤状况
					clearcin();//清除缓存
					switch(condition)
					{
						case 0:
							{
								strcpy_s(conditionstr,"旷课");
								break;
							}
						case 1:
							{
								strcpy_s(conditionstr,"到课");
								break;
							}
						case 2:
							{
								strcpy_s(conditionstr,"请假");
								break;
							}
						default:
							{
								cout<<"您的输入有误！请重新输入："<<ends;
								goto AO;
							}
					}
					gotoclassrecord<<studentnumber<<'\t'<<studentname<<'\t'<<wantclass<<'\t'<<teachername<<'\t'<<classtime<<'\t'<<conditionstr<<'\n';//写入一条考勤记录
				}
				cout<<wantclass<<classtime<<"日课考勤情况录入完成！"<<endl;
				classstudents.close();//关闭学生名单文件
				gotoclassrecord.close();//关闭系统考勤记录文件
				operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
				if(!operationfile)
				{
					teachererror();//文件不能打开
				}
				operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"录入"<<classtime<<"日"<<wantclass<<"课程学生考勤情况"<<'\n';//写入一条操作日志
				operationfile.close();//关闭系统操作日志文件
			}
			else
			{
				goto BC;
			}
		}
		BC:clearcin();//清除缓存
		cout<<"考勤情况录入成功！"<<endl;
	}
}
void loadinscores(char teachername[])//录入课程成绩
{
	ofstream operationfile,studentscorefile,systemscorefile;
	ifstream myclass,classstudentlist,chooseableclasslist;
	char classname[50],title1[100],teachname[20],wantclass[50],currenttime[32],classnature[20],nature[20],title2[100],title3[100];
	int i=0,want,mark=0;
	myclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\任课.txt",ios::in);//打开任课名单文件
	if(!myclass)
	{
		teachererror();//文件不能打开
	}
	myclass.seekg(0,ios::beg);
	myclass.getline(title1,100);
	cout<<teachername<<"，你有以下课程可以进行成绩录入："<<endl;
	while(myclass>>teachname>>classname>>classnature)//打印任课名单
	{
		if(strcmp(teachername,teachname)==0)
		{
			cout<<"|"<<i+1<<"-"<<classname<<endl;
			i++;
		}
	}
	myclass.close();//关闭任课名单
	if(i==0)//没有任课
	{
		cout<<"您没有任教任何课程！"<<endl;
	}
	else
	{
		mark=i;
		myclass.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\教职工档案\\任课.txt",ios::in);//打开任课名单文件
		if(!myclass)
		{
			teachererror();//文件不能打开
		}
		char studentlistfilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\课程学生名单\\";//准备课程学生名单文件名
		char sysfilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\课程成绩记录\\";//准备系统课程成绩记录文件文件名
		char stufilename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\学生档案\\";//准备学生个人成绩记录文件文件名
		int score=0;
		while(1)
		{
			cout<<"请输入您需要进行录入成绩的课程代号（按Ctrl+Z退出）："<<ends;//录入课程成绩
			BF:if(cin>>want)
			{
				clearcin();//清除缓存
				if((want>mark)||(want<1))//输入有误
				{
					cout<<"您输入的序号不在该范围内，请重新输入："<<ends;
					goto BF;
				}
				myclass.seekg(0,ios::beg);
				myclass.getline(title1,100);
				i=0;
				while(myclass>>teachname>>classname>>classnature)//查找目标课程
				{
					if(strcmp(teachname,teachername)==0)//找到任课教师
					{
						if(i==want-1)//找到该课程
						{
							strcpy_s(wantclass,classname);
							strcpy_s(nature,classnature);
							break;
						}
						i++;
					}
				}
				strcat_s(sysfilename,wantclass);//构建系统学生成绩记录文件文件名
				strcat_s(sysfilename,"成绩.txt");
				if(strcmp(nature,"通选")==0)//该课程性质为通选
				{
					chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\通选课列表.txt",ios::in);//打开通选课列表文件
					if(!chooseableclasslist)
					{
						teachererror();//文件不能打开
					}
					chooseableclasslist.seekg(0,ios::beg);
					chooseableclasslist.getline(title2,100);
					char ccode[8],cname[50],cnature[20],cterm[10],targetcode[8];
					int ctotaltime,ctheorytime,cexptime,ccredit,ctotalpeople,cleftpeople;
					while(chooseableclasslist>>ccode>>cname>>cnature>>ctotaltime>>ctheorytime>>cexptime>>ccredit>>cterm>>ctotalpeople>>cleftpeople)//查找该课程编号
					{
						if(strcmp(cname,wantclass)==0)//找到该课程
						{
							strcpy_s(targetcode,ccode);
							break;
						}
					}
					strcat_s(studentlistfilename,targetcode);//构建该课程学生名单文件名
					strcat_s(studentlistfilename,".txt");
				}
				else//该课程并非通选课
				{
					strcat_s(studentlistfilename,wantclass);//构建该课程学生名单文件名
					strcat_s(studentlistfilename,"学生名单.txt");
				}
				classstudentlist.open(studentlistfilename,ios::in);//打开课程学生名单文件
				if(!classstudentlist)
				{
	
					teachererror();//文件不能打开
				}
				classstudentlist.seekg(0,ios::beg);
				classstudentlist.getline(title3,100);
				systemscorefile.open(sysfilename,ios::app);//打开系统学生成绩记录文件
				if(!systemscorefile)
				{
					teachererror();//文件不能打开
				}
				cout<<"课程学生名单已载入，现在开始录入成绩..."<<endl;
				char studnumber[12],studname[20];
				while(classstudentlist>>studnumber>>studname)//开始逐条录入成绩
				{
					strcat_s(stufilename,studname);//构建学生个人成绩记录文件文件名
					strcat_s(stufilename,"学生成绩.txt");
					studentscorefile.open(stufilename,ios::app);//打开学生个人成绩记录文件
					if(!studentscorefile)
					{
						teachererror();//文件不能打开
					}
					cout<<"学号为"<<studnumber<<"的学生"<<studname<<"该门课的成绩为："<<ends;
					cin>>score;//输入成绩
					clearcin();//清除缓存
					studentscorefile<<wantclass<<'\t'<<score<<'\n';//写入该门课成绩
					studentscorefile.close();//关闭学生个人成绩记录文件
					systemscorefile<<studnumber<<'\t'<<studname<<'\t'<<score<<'\n';//在系统成绩记录文件当中写入课程成绩
				}
				systemscorefile.close();//关闭系统成绩记录文件
				getlocaltime(currenttime);//获得本地时间
				operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
				if(!operationfile)
				{
					teachererror();//文件不能打开
				}
				operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"录入"<<wantclass<<"课程学生成绩"<<'\n';//写入一条操作记录
				operationfile.close();//关闭文件
				cout<<wantclass<<"课程成绩录入完成！"<<endl;
			}
			else
			{
				goto BD;
			}
		}
		BD:clearcin();//清除缓存
		myclass.close();//关闭任课列表文件
		cout<<"成绩录入完成！"<<endl;
	}
}
void setbulletin(char teachername[])
{
	ofstream operationfile,allbulletin;
	allbulletin.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\公告栏.txt",ios::app);//打开公告栏文件
	if(!allbulletin)
	{
		teachererror();//文件不能打开
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		teachererror();//文件不能打开
	}
	char content[500],currenttime[32];
	int choice=0;
	AP:cout<<"请输入公告内容（499字符以内）："<<ends;
	cin>>content;//输入公告内容
	clearcin();//清除缓存
	getlocaltime(currenttime);//获得当地时间
	allbulletin<<teachername<<'\t'<<currenttime<<'\t'<<content<<'\n';//写入公告内容
	operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"发布公告"<<'\n';//写入一条操作记录
	cout<<"您还要继续发布公告吗（要请输入1，否则输入0）："<<ends;
	AQ:cin>>choice;
	clearcin();//清除缓存
	switch(choice)
	{
		case 1:goto AP;//继续发布公告
		case 0:break;
		default:
			{
				cout<<"您的输入有误，请重新输入："<<ends;
				goto AQ;
			}
	}
	allbulletin.close();//关闭公告栏文件
	operationfile.close();//关闭系统操作日志文件
	cout<<"公告发布完成！"<<endl;
}
void dealwithfeedback(char teachername[])
{
	ifstream orientlist;
	ofstream operationfile,newlist,replylist;
	char title1[100],stuname[20],feedtime[32],feedcontent[500],content[500],currenttime[32];
	int i=0,choice,mark=0;
	struct onerecord//构造一条学生反馈记录的链表节点结构
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
	orientlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\学生反馈列表.txt",ios::in);//打开学生反馈列表文件
	if(!orientlist)
	{
		teachererror();//文件不能打开
	}
	orientlist.seekg(0,ios::beg);
	orientlist.getline(title1,100);
	cout<<"学生反馈列表如下："<<endl;
	while(orientlist>>stuname>>feedtime>>feedcontent)//打印学生反馈列表同时构造学生反馈链表
	{
		strcpy_s(a->studentname,stuname);
		strcpy_s(a->feedbacktime,feedtime);
		strcpy_s(a->feedbackcontent,feedcontent);
		cout<<i+1<<".学生"<<stuname<<"于"<<feedtime<<"留言："<<feedcontent<<endl;
		a->code=i;
		b=new onerecord;
		a->next=b;
		a=a->next;
		a->next=NULL;
		i++;
	}
	a->next=NULL;
	a=head;
	orientlist.close();//关闭学生反馈链表文件
	mark=i;
	newlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\学生反馈列表.txt",ios::out);//打开新的学生反馈列表文件
	if(!newlist)
	{
		teachererror();//文件不能打开
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		teachererror();//文件不能打开
	}
	replylist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\反馈回复列表.txt",ios::app);//打开反馈回复文件
	if(!replylist)
	{
		teachererror();//文件不能打开
	}
	newlist<<"学生姓名"<<'\t'<<"反馈时间"<<'\t'<<"反馈内容"<<'\n';//写入标题行
	while(1)
	{
		cout<<"请输入需要答复的留言序号（按Ctrl+Z结束）："<<ends;//答复反馈
		BH:if(cin>>choice)
		{
			clearcin();//清除缓存
			if((choice>mark)||(choice<1))
			{
				cout<<"您输入的序号不在列表当中哦！请重新输入："<<ends;
				goto BH;
			}
			cout<<"请输入答复内容（499字符以内，请不要换行）："<<ends;
			cin>>content;//输入回复内容
			clearcin();//清除缓存
			getlocaltime(currenttime);//获得本地时间
			if(choice==1)//写入反馈记录（第一条反馈）
			{
				replylist<<a->studentname<<'\t'<<a->feedbacktime<<'\t'<<a->feedbackcontent<<'\t'<<teachername<<'\t'<<currenttime<<'\t'<<content<<'\n';//写入一条学生反馈记录
				head=a->next;
				delete a;//回复后删除该反馈
				a=head;
				operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"回复反馈"<<'\n';//写入一条操作记录
			}
			else
			{
				choice--;
				while(a->next->code!=choice)//查找反馈记录节点
				{
					a=a->next;
				}
				getlocaltime(currenttime);//获得本地时间
				replylist<<a->next->studentname<<'\t'<<a->next->feedbacktime<<'\t'<<a->next->feedbackcontent<<'\t'<<teachername<<'\t'<<currenttime<<'\t'<<content<<'\n';//写入一条学生反馈回复记录
				operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"回复反馈"<<'\n';//写入一条操作记录
				b=a->next;
				a->next=b->next;//删除这条学生反馈记录
				delete b;
				b=NULL;
				a=head;
			}
			cout<<"该条反馈回复成功！"<<endl;
		}
		else
		{
			clearcin();//清除缓存
			operationfile.close();//关闭系统操作日志文件
			replylist.close();//关闭反馈回复列表文件
			while(a->next!=NULL)//写入新的学生反馈列表
			{
				newlist<<a->studentname<<'\t'<<a->feedbacktime<<'\t'<<a->feedbackcontent<<'\n';
				a=a->next;
			}
			newlist.close();//关闭学生反馈列表文件
			a=head;
			while(head->next!=NULL)//销毁学生反馈列表链表
			{
				a=head;
				head=head->next;
				delete a;
			}
			delete head;
			a=NULL;
			head=NULL;
			cout<<"回复成功！"<<endl;
			goto AR;
		}
	}
	AR:;
}
void facultyemail(char teachername[])//教职工邮件系统功能选择界面
{
	int choice;
	while(1)
	{
		cout<<"请选择电子邮功能："<<endl;
		cout<<"|1-查看收件箱"<<endl;
		cout<<"|2-发送电子邮件"<<endl;
		cout<<"|3-删除电子邮件"<<endl;
		cout<<"|4-退出电子邮件系统"<<endl;
		cout<<"您的选择是："<<ends;
		AT:cin>>choice;//输入选择
		clearcin();//清除缓存
		switch(choice)
		{
			case 1:watchfacultyemail(teachername);break;
			case 2:sendfacultyemail(teachername);break;
			case 3:deletefacultyemail(teachername);break;
			case 4:goto AS;
			default:
				{
					cout<<"您的输入有误哦！请重新输入："<<ends;
					goto AT;
				}
		}
	}
	AS:;
}
void watchfacultyemail(char teachername[])//查阅收件箱
{
	ofstream operationfile;
	ifstream emaillist;
	char title[100],currenttime[32],sender[50],reciever[20],sendtime[32],etitle[50],econtent[500];
	emaillist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\电子邮件来往信件记录.txt",ios::in);//打开系统电子邮件记录文件
	if(!emaillist)
	{
		teachererror();//文件不能打开
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		teachererror();//文件不能打开
	}
	emaillist.seekg(0,ios::beg);
	emaillist.getline(title,100);
	getlocaltime(currenttime);//获得本地时间
	operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"查看邮件"<<'\n';//写入一条操作记录
	operationfile.close();//关闭系统操作日志文件
	cout<<"现在开始打印收件箱当中的电子邮件..."<<endl;
	while(emaillist>>sendtime>>sender>>reciever>>etitle>>econtent)//打印收件箱当中的邮件
	{
		if(strcmp(reciever,teachername)==0)
		{
			cout<<"===================================================================================="<<endl;
			cout<<"发件人："<<sender<<endl;
			cout<<"发送时间："<<sendtime<<endl;
			cout<<"邮件标题："<<etitle<<endl;
			cout<<"邮件内容："<<econtent<<endl;
		}
	}
	cout<<"所有接收到的信件打印完毕！"<<endl;
	emaillist.close();//关闭系统电子邮件文件
}
void sendfacultyemail(char teachername[])//发送邮件
{
	ofstream operationfile,emaillist;
	char currenttime[32],reciever[20],title[50],content[500];
	int choice;
	emaillist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\电子邮件来往信件记录.txt",ios::app);//打开系统电子邮件来往信件记录文件
	if(!emaillist)
	{
		teachererror();//文件不能打开
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		teachererror();//文件不能打开
	}
	AU:cout<<"请输入收件人姓名（19字符以内）："<<ends;
	cin>>reciever;//输入收件人
	clearcin();//清除缓存
	cout<<"收件人是："<<reciever<<",您确定吗（确定输入1，否则输入0，请不要输入其它数字）："<<ends;
	AX:cin>>choice;
	clearcin();//清除缓存
	switch(choice)
	{
		case 1:break;
		case 2:goto AU;
		default:
			{
				cout<<"您的输入有误哦！请重新输入："<<ends;
				goto AX;
			}
	}
	cout<<"请输入邮件标题（49字符以内）："<<ends;
	cin>>title;//输入文件标题
	clearcin();//清除缓存
	cout<<"请输入邮件内容（499字符以内，请不要换行）："<<ends;
	cin>>content;//输入邮件内容
	clearcin();//清除缓存
	getlocaltime(currenttime);//获取本地时间
	emaillist<<currenttime<<'\t'<<teachername<<'\t'<<reciever<<'\t'<<title<<'\t'<<content<<'\n';//写入一条电子邮件记录
	emaillist.close();//关闭系统电子邮件来往信件记录文件
	operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"给"<<reciever<<"写了一封电子邮件"<<'\n';//写入一条操作记录
	operationfile.close();//关闭系统操作日志文件
	cout<<"电子邮件发送成功！"<<endl;
}
void resetfacultypassword(char teachername[])//修改密码
{
	if(strcmp(teachername,"Admin")==0)//默认账号的密码不能修改
	{
		cout<<"Admin的密码不能修改！"<<endl;
	}
	else
	{
		ofstream operationfile,newaccountlist;
		ifstream orientaccountlist;
		char currenttime[32],account[20],password[20],title[100];
		orientaccountlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\教职工账户与密码.txt",ios::in);//打开教职工账户密码文件
		if(!orientaccountlist)
		{
			teachererror();//文件不能打开
		}
		orientaccountlist.seekg(0,ios::beg);
		orientaccountlist.getline(title,100);
		struct oneaccount//构造教职工账户密码记录链表节点结构
		{
			char username[20];
			char pass[20];
			oneaccount *next;
		};
		oneaccount *head,*a,*b;
		head=new oneaccount;
		a=head;
		while(orientaccountlist>>account>>password)//构建教职工账户密码链表
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
		orientaccountlist.close();//关闭教职工账户密码文件
		cout<<"请输入您的新密码（19字符以内）："<<ends;
		cin>>password;//输入新密码
		clearcin();//清除缓存
		while(strcmp(a->username,teachername)!=0)//寻找该教师
		{
			a=a->next;
		}
		strcpy_s(a->pass,password);//修改密码
		a=head;
		getlocaltime(currenttime);//获得本地时间
		newaccountlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\教职工账户与密码.txt",ios::out);//打开新的教职工账户密码文件
		if(!newaccountlist)
		{
			teachererror();//文件不能打开
		}
		newaccountlist<<"用户名"<<'\t'<<"密码"<<'\n';//写入标题行
		while(a->next!=NULL)//写如教职工账户密码记录
		{
			newaccountlist<<a->username<<'\t'<<a->pass<<'\n';
			a=a->next;
		}
		a=head;
		newaccountlist.close();//关闭教职工账户密码文件
		operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
		if(!operationfile)
		{
			teachererror();//文件不能打开
		}
		operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"修改密码"<<'\n';//写入一条操作记录
		operationfile.close();//关闭系统操作日志文件
		while(head->next!=NULL)//销毁教职工账户密码链表
		{
			a=head;
			head=head->next;
			delete a;
		}
		delete head;
		a=NULL;
		head=NULL;
		cout<<"密码修改完成！"<<endl;
	}
}
void adminoperate()
{
	char teachername[20]="游客";
	bool condition=false;
	cout<<"欢迎使用学生教务管理系统！"<<endl;//欢迎词
	cout<<"温馨提示：第一次进入请使用用户名Admin登陆，密码为666666。登陆后请创建新账号。"<<endl;//温馨提示
	condition=teacherlogin(teachername);//登陆
	if(condition)//登陆成功
	{
		teacherfunction(teachername);//进入教职工功能界面
	}
	cout<<teachername<<"，感谢您使用学生教务管理系统，再见！"<<endl;//退出教职工选择界面
}
void deletefacultyemail(char teachername[])//删除电子邮件
{
	ofstream operationfile,newemailfile;
	ifstream orientemailfile;
	char esendtime[32],esender[50],ereciever[50],etitle[50],econtent[500],title[100],currenttime[32];
	int choice=0,mark=0,i=0,j=0;
	struct oneemail//构造信件链表节点结构
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
	orientemailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\电子邮件来往信件记录.txt",ios::in);//打开系统电子邮件来往信件记录文件
	if(!orientemailfile)
	{
		teachererror();//文件不能打开
	}
	orientemailfile.seekg(0,ios::beg);
	orientemailfile.getline(title,100);
	head=new oneemail;
	a=head;
	a->next=NULL;
	cout<<"现在开始打印你的收件箱当中的邮件清单及其编号..."<<endl;
	while(orientemailfile>>esendtime>>esender>>ereciever>>etitle>>econtent)//打印收件箱并构造邮件链表
	{
		a->mycode=-1;
		if(strcmp(ereciever,teachername)==0)
		{
			cout<<"=================================================="<<endl;
			cout<<"编号："<<j+1<<endl;
			cout<<"发送时间："<<esendtime<<endl;
			cout<<"寄件人："<<esender<<endl;
			cout<<"邮件标题："<<etitle<<endl;
			cout<<"邮件内容：\n"<<econtent<<endl;
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
	cout<<"所有邮件打印完毕！"<<endl;
	orientemailfile.close();//关闭电子邮件来往信件记录文件
	while(1)
	{
		cout<<"请输入您需要删除的邮件编号（按Ctrl+Z结束）："<<ends;
		CB:if(cin>>choice)//删除邮件
		{
			clearcin();//clear buff
			if((choice<1)||(choice>mark))
			{
				cout<<"输入有误，请重新输入（按Ctrl+Z结束）："<<ends;
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
				while(a->next->mycode!=choice)//查找节点
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
	newemailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\电子邮件来往信件记录.txt",ios::out);//打开新的电子邮件来往信件记录文件
	if(!newemailfile)
	{
		teachererror();//文件不能打开
	}
	newemailfile<<"发送时间"<<'\t'<<"发件人"<<'\t'<<"收件人"<<'\t'<<"邮件标题"<<'\t'<<"邮件内容"<<'\n';//写入标题行
	while(a->next!=NULL)//写入新电子邮件列表
	{
		newemailfile<<a->sendtime<<'\t'<<a->sender<<'\t'<<a->reciever<<'\t'<<a->emailtitle<<'\t'<<a->content<<'\n';
		a=a->next;
	}
	newemailfile.close();//关闭电子邮件来往信件记录文件
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		teachererror();//文件不能打开
	}
	getlocaltime(currenttime);//获得本地时间
	operationfile<<currenttime<<'\t'<<teachername<<'\t'<<"删除邮件"<<'\n';//写入一条操作记录
	operationfile.close();//关闭系统操作日志文件
	a=head;
	b=NULL;
	while(head->next!=NULL)//删除电子邮件链表
	{
		a=head;
		head=head->next;
		delete a;
	}
	delete head;
	head=NULL;
	a=NULL;
	cout<<"邮件删除成功！"<<endl;
}
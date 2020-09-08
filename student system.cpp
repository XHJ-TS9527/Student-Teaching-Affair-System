#include<iostream>
#include<string.h>
#include<fstream>
#include"clarify student functions.h"
#include<ctime>
#include"clarify main functions.h"
using namespace std;
void studenterror()//异常处理
{
	cout<<"系统文件打开出错！程序将自动关闭，请立即请开发人员调试系统！"<<endl;//温馨提示
	system("pause");
	exit(0);//直接退出系统
}
int findstudent(char studentname[])//确认学生是否已经注册
{
	char title[100],name[20],password[20];
	ifstream studentfiles;
	studentfiles.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\学生账户与密码.txt",ios::in|ios::out);//打开学生列表文件
	studentfiles.seekg(0,ios::beg);
	if(!studentfiles)
	{
		studenterror();//文件不能打开
	}
	studentfiles.getline(title,100);
	while(studentfiles>>name>>password)//开始查找
	{
		if(strcmp(studentname,name)==0)
		{
			studentfiles.close();//关闭学生列表文件
			return 1;//查找成功
		}
	}
	studentfiles.close();//关闭学生列表文件
	return 0;//找不到该学生
}
int comparepassword(char studentname[],char studentpassword[])//对比密码
{
	ifstream studentfiles;
	char title[100],name[20],password[20];
	studentfiles.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\学生账户与密码.txt",ios::in|ios::out);//打开学生账户密码列表文件
	studentfiles.seekg(0,ios::beg);
	if(!studentfiles)
	{
		studenterror();//文件不能打开
	}
	studentfiles.getline(title,100);
	while(studentfiles>>name>>password)//开始对比密码
	{
		if(strcmp(studentname,name)==0)
		{
			if(strcmp(studentpassword,password)==0)
			{
				studentfiles.close();//关闭账户密码列表文件
				return 1;//完成对比，密码正确
			}
			else
			{
				studentfiles.close();//关闭账户密码列表文件
				return 0;//完成对比，密码错误
			}
		}
	}
	studentfiles.close();//关闭账户密码列表文件
	cout<<"系统当中没有您的密码记录哦！"<<endl;//提示
	return 0;//该学生不在列表当中
}
void watchfeedback(char studentname[])//看反馈回复
{
	char title[100],currenttime[32],name[20],feedbacktime[32],feedbackcontent[500],stuff[20],dealtime[32],replycontent[500];
	int i=0;
	ifstream feedbackfiles("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\反馈回复列表.txt",ios::in);//打开反馈回复列表文件
	if(!feedbackfiles)
	{
		studenterror();//文件打开失败
	}
	feedbackfiles.seekg(0,ios::beg);
	feedbackfiles.getline(title,100);
	ofstream operatefiles;
	operatefiles.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operatefiles)
	{
		studenterror();//文件打开失败
	}
	getlocaltime(currenttime);//获得当前时间
	operatefiles<<currenttime<<'\t'<<studentname<<'\t'<<"读取反馈"<<'\n';//写一条新记录
	operatefiles.close();//关闭操作日志文件
	cout<<"下面开始打印反馈回复列表..."<<endl;
	while(feedbackfiles>>name>>feedbacktime>>feedbackcontent>>stuff>>dealtime>>replycontent)//打印反馈回复列表
	{
		if(strcmp(studentname,name)==0)//打印该学生的反馈回复记录
		{
			cout<<"================================================================="<<endl;
			cout<<"反馈时间："<<feedbacktime<<endl;
			cout<<"反馈内容："<<feedbackcontent<<endl;
			cout<<"答复人："<<stuff<<endl;
			cout<<"答复时间："<<dealtime<<endl;
			cout<<"答复内容："<<replycontent<<endl;
		}
	}
	feedbackfiles.close();//关闭反馈回复列表文件
	cout<<"反馈答复内容显示完毕！"<<endl;
}
void feedback(char studentname[])//写入新反馈
{
	ofstream operatefiles;
	ofstream feedbackfile;
	char currenttime[32],feedbackcontent[500];
	getlocaltime(currenttime);
	operatefiles.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	feedbackfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\学生反馈列表.txt",ios::app);//打开系统反馈列表文件
	if(!operatefiles)
	{
		studenterror();//文件不能打开
	}
	if(!feedbackfile)
	{
		studenterror();//文件不能打开
	}
	operatefiles<<currenttime<<'\t'<<studentname<<'\t'<<"写入反馈"<<'\n';//写入操作记录
	operatefiles.close();//关闭系统操作日志文件
	cout<<"请输入你需要反馈的内容(不大于500字）："<<ends;
	cin>>feedbackcontent;//写入反馈内容
	clearcin();//清除缓存
	feedbackfile<<studentname<<'\t'<<currenttime<<'\t'<<feedbackcontent<<'\n';//写反馈记录
	feedbackfile.close();//关闭反馈列表文件
	cout<<"反馈已经成功录入系统，等待教职工解答！"<<endl;//反馈成功
}
void studentprofile(char studentname[])//查看个人档案
{
	char currenttime[32],title[100],name[20],number[12],sex[5],major[20],class_[20],add[50],dorm[50],birth[11];
	int choice;
	struct student//构造对象——学生
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
	student currentstudent;//构造一个学生对象
	fstream allstudentlist,systemoperation;
	allstudentlist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\学生档案\\全部学生名单.txt",ios::in);//打开学生列表文件
	if(!allstudentlist)
	{
		studenterror();//文件不能打开
	}
	systemoperation.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!systemoperation)
	{
		studenterror();//文件不能打开
	}
	getlocaltime(currenttime);//获得当前时间
	systemoperation<<currenttime<<'\t'<<studentname<<'\t'<<"查看档案\n";//写入操作记录
	systemoperation.close();//关闭系统操作日志文件
	allstudentlist.seekg(0,ios::beg);
	allstudentlist.getline(title,100);
	while(allstudentlist>>name>>number>>sex>>birth>>major>>class_>>add>>dorm)//遍历学生列表文件
	{
		if(strcmp(studentname,name)==0)//找到了学生
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
	allstudentlist.close();//关闭学生列表文件
	cout<<"学生姓名："<<currentstudent.student_name<<"\n学生学号："<<currentstudent.student_number<<"\n学生性别："<<currentstudent.student_gender<<"\n学生出生日期："<<currentstudent.student_birthdate<<"\n学生所属专业："<<currentstudent.student_major<<"\n学生所属班级："<<currentstudent.student_class<<"\n学生家庭地址："<<currentstudent.student_homeadd<<"\n学生宿舍号："<<currentstudent.student_dormitory<<endl;//打印学生档案
	cout<<studentname<<"，您的档案已经显示完毕！请问您需要修改吗？修改请输入1，否则输入0。"<<endl;
	cout<<"请输入您的选择："<<ends;
	cin>>choice;//选择是否修改个人档案
	clearcin();//清除缓存
	if(choice==1)
	{
		resetprofile(studentname);//改档案
	}
}
void resetprofile(char studentname[])//修改档案
{
	char currenttime[32],title[100],name[20],number[12],sex[5],major[20],class_[20],add[50],dorm[50],birth[11];
	int choice;
	struct student//构造学生对象
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
	struct studentlist//构造列表节点
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
	studentlistfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\学生档案\\全部学生名单.txt",ios::in);//打开学生名单文件
	if(!studentlistfile)
	{
		studenterror();//文件不能打开
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		studenterror();//文件不能打开
	}
	studentlistfile.seekg(0,ios::beg);
	studentlistfile.getline(title,100);
	while(studentlistfile>>name>>number>>sex>>birth>>major>>class_>>add>>dorm)//创建学生名单链表
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
	studentlistfile.close();//关闭学生列表文件
	a=head;
	while(strcmp(a->currentstuent.student_name,studentname)!=0)//找到要修改学生的节点
	{
		a=a->next;
	}
	while(1)//修改个人信息
	{
		cout<<"请输入您想修改的项目："<<endl;
		cout<<"|1-性别"<<endl;
		cout<<"|2-出生日期"<<endl;
		cout<<"|3-主修专业"<<endl;
		cout<<"|4-所属班级"<<endl;
		cout<<"|5-家庭地址"<<endl;
		cout<<"|6-宿舍号"<<endl;
		cout<<"|7-退出修改"<<endl;
		cout<<"请输入您的选择："<<ends;
		P:cin>>choice;
		clearcin();//清除缓存
		switch(choice)
		{
			case 1://修改性别
				{
					cout<<"请输入您新的性别（男/女)："<<ends;
					cin>>sex;
					strcpy_s(a->currentstuent.student_gender,sex);
					clearcin();//clear buff
					getlocaltime(currenttime);
					operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"修改档案--修改性别"<<'\n';//写入一条新操作记录
				}
				break;
			case 2://修改出生日期
				{
					cout<<"请输入您新的出生日期（格式为yyyy-mm-dd）："<<ends;
					cin>>birth;
					strcpy_s(a->currentstuent.student_birthdate,birth);
					clearcin();//clear buff
					getlocaltime(currenttime);
					operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"修改档案--修改出生日期"<<'\n';//写一条新操作记录
				}
				break;
			case 3://修改主修专业
				{
					cout<<"请输入您新的主修专业（19字符以内）："<<ends;
					cin>>major;
					strcpy_s(a->currentstuent.student_major,major);
					clearcin();//clear buff
					getlocaltime(currenttime);
					operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"修改档案--修改主修专业"<<'\n';//写一条新记录
				}
				break;
			case 4://修改所属班级
				{
					cout<<"请输入您新的所属班级（19字符以内）："<<ends;
					cin>>class_;
					strcpy_s(a->currentstuent.student_class,class_);
					clearcin();//clear buff
					getlocaltime(currenttime);
					operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"修改档案--修改班级"<<'\n';//写一条新记录
				}
				break;
			case 5://修改家庭住址
				{
					cout<<"请输入您新的家庭住址（49字符以内）："<<ends;
					cin>>add;
					strcpy_s(a->currentstuent.student_homeadd,add);
					clearcin();//clear buff
					getlocaltime(currenttime);
					operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"修改档案--修改家庭住址"<<'\n';//写一条新记录
				}
				break;
			case 6://修改宿舍
				{
					cout<<"请输入您新的宿舍号（49字符以内）："<<ends;
					cin>>dorm;
					strcpy_s(a->currentstuent.student_dormitory,dorm);
					clearcin();//clear buff
					getlocaltime(currenttime);
					operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"修改档案--修改宿舍号码"<<'\n';//写一条新记录
				}
				break;
			case 7://退出
				goto O;
			default://输入有误
				{
					cout<<"您输入的标号有错哦！请重新输入："<<ends;
					goto P;
				}
		}
	}
	O:a=head;
	ostudentlistfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\学生档案\\全部学生名单.txt",ios::out);//打开学生名单文件，开始写文件
	if(!ostudentlistfile)
	{
		studenterror();//文件不能打开
	}
	ostudentlistfile<<"姓名"<<'\t'<<"学号"<<'\t'<<"性别"<<'\t'<<"出生日期"<<'\t'<<"专业"<<'\t'<<"班级"<<'\t'<<"家庭住址"<<'\t'<<"宿舍号码"<<'\n';//写标题
	while(a->next!=NULL)//write new student profile
	{
		ostudentlistfile<<a->currentstuent.student_name<<'\t'<<a->currentstuent.student_number<<'\t'<<a->currentstuent.student_gender<<'\t'<<a->currentstuent.student_birthdate<<'\t'<<a->currentstuent.student_major<<'\t'<<a->currentstuent.student_class<<'\t'<<a->currentstuent.student_homeadd<<'\t'<<a->currentstuent.student_dormitory<<'\n';//写记录
		a=a->next;
	}
	a=head;
	ostudentlistfile.close();//关闭学生列表文件
	while(a->next!=NULL)//销毁学生名单链表
	{
		b=a;
		a=a->next;
		delete b;
	}
	delete a;
	a=NULL;
	b=NULL;
	head=NULL;
	cout<<"修改完成！"<<endl;
}
void getscorefile(char studentname[])//查询成绩
{
	char filename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\学生档案\\";//成绩文件路径
	char name[50],title[100],currenttime[32];
	int classnumber=0,choice=0,s=0;
	strcat_s(filename,studentname);
	strcat_s(filename,"学生成绩.txt");//构造包括文件名的路径
	ofstream operationfile;
	ifstream scorefile;
	scorefile.open(filename,ios::in);//打开学生成绩文件
	if(!scorefile)
	{
		studenterror();//文件不能打开
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		studenterror();//文件不能打开
	}
	scorefile.seekg(0,ios::beg);
	scorefile.getline(title,100);
	cout<<"现在开始打印课程成绩..."<<endl;
	cout<<"课程名称\t课程成绩"<<endl;
	while(scorefile>>name>>s)//统计成绩单当中的课程数量
	{
		cout<<name<<'\t'<<s<<endl;
		classnumber++;
	}
	getlocaltime(currenttime);//获得本地时间
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"查看成绩"<<'\n';//写一条操作记录
	operationfile.close();//关闭系统操作日志文件
	scorefile.close();//关闭学生成绩文件
	cout<<"所有成绩显示完毕！"<<endl;
	cout<<"您是否希望排序显示？"<<endl;//选择是否排序显示
	cout<<"|1-降序（从大到小）排列"<<endl;
	cout<<"|2-升序（从小到大）排列"<<endl;
	cout<<"|3-不排列"<<endl;
	cout<<"您的选择是："<<ends;
	P:cin>>choice;
	clearcin();//清除缓存
	switch(choice)
	{
		case 1:rankdown(filename,classnumber,studentname);break;//降序排序显示
		case 2:rankup(filename,classnumber,studentname);break;//升序排序显示
		case 3:break;
		default://输入有误
			{
				cout<<"您输入的标号不正确哦！请重新输入："<<ends;
				goto P;
			}
	}
}
void rankdown(char filename[],int classnumber,char studentname[])//降序排序
{
	char currenttime[32],title[100],name[50],tempclassname[50];
	int r=0,j=0,s,tempscore;
	fstream scorefile,operationfile;
	scorefile.open(filename,ios::in);//打开学生成绩文件
	scorefile.seekg(0,ios::beg);
	scorefile.getline(title,100);
	if(!scorefile)
	{
		studenterror();//文件不能打开
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		studenterror();//文件不能打开
	}
	getlocaltime(currenttime);//获得本地时间
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"降序排列显示成绩"<<'\n';//写一条操作记录
	operationfile.close();//关闭系统操作日志文件
	struct score//构造分数记录节点结构
	{
		char classname[50];
		int classscore;
	};
	score *scorelist,*head,*max;
	head=new score[classnumber];//动态分配分数记录数组
	scorelist=head;
	max=head;
	while(scorefile>>name>>s)//写该数组
	{
		strcpy_s(scorelist->classname,name);
		scorelist->classscore=s;
		scorelist++;
	}
	scorefile.close();//关闭学生成绩文件
	scorelist=head;
	for(int i=0;i<classnumber;i++)//选择排序
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
	cout<<"降序排列已经完成，现在开始打印降序排列后的结果..."<<endl;
	cout<<"课程名称"<<'\t'<<"课程成绩"<<endl;
	for(int i=0;i<classnumber;i++)//显示排序后结果
	{
		cout<<scorelist->classname<<'\t'<<scorelist->classscore<<endl;
		scorelist++;
	}
	cout<<"显示完毕！"<<endl;
	scorelist=head;
	delete []scorelist;//销毁动态分配的学生成绩记录数组
	scorelist=NULL;
	head=NULL;
}
void rankup(char filename[],int classnumber,char studentname[])//升序排序显示学生成绩
{
	char currenttime[32],title[100],name[50],tempclassname[50];
	int r=0,j=0,s,tempscore;
	fstream scorefile,operationfile;
	scorefile.open(filename,ios::in);//打开学生成绩列表
	scorefile.seekg(0,ios::beg);
	scorefile.getline(title,100);
	if(!scorefile)
	{
		studenterror();//文件不能打开
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		studenterror();//文件不能打开
	}
	getlocaltime(currenttime);//获得本地时间
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"升序排列显示成绩"<<'\n';//写入一条操作记录
	operationfile.close();//关闭系统操作日志文件
	struct score//构造学生成绩节点结构
	{
		char classname[50];
		int classscore;
	};
	score *scorelist,*head,*min;
	head=new score[classnumber];//动态分配学生成绩数组
	scorelist=head;
	min=head;
	while(scorefile>>name>>s)//写该数组
	{
		strcpy_s(scorelist->classname,name);
		scorelist->classscore=s;
		scorelist++;
	}
	scorefile.close();//关闭学生成绩文件
	scorelist=head;
	for(int i=0;i<classnumber;i++)//选择排序
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
	cout<<"升序排列已经完成，现在开始显示升序排列后的结果..."<<endl;
	cout<<"课程名称"<<'\t'<<"课程成绩"<<endl;
	for(int i=0;i<classnumber;i++)//显示排序结果
	{
		cout<<scorelist->classname<<'\t'<<scorelist->classscore<<endl;
		scorelist++;
	}
	scorelist=head;
	delete []head;//销毁动态分配的学生成绩数组
	scorelist=NULL;
	head=NULL;
}
void chooseableclass(char studentname[])//通选课系统
{
	char currenttime[32],title[100],name[50],nature[20],term[10],code[8];
	int totaltime=0,theorytime=0,exptime=0,credit=0,totalpeople=0,leftpeople=0,classnumber=0,choice=0;
	ofstream operationfile;
	fstream chooseableclasslist;
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		studenterror();//文件不能打开
	}
	chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\通选课列表.txt",ios::in);//打开通选课列表文件
	if(!chooseableclasslist)
	{
		studenterror();//文件不能打开
	}
	getlocaltime(currenttime);//获得本地时间
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"查看通选课列表"<<'\n';//写一条操作记录
	operationfile.close();//关闭系统操作日志文件
	chooseableclasslist.seekg(0,ios::beg);
	chooseableclasslist.getline(title,100);
	cout<<"系统当中记录的通选课信息如下："<<endl;
	cout<<"编号"<<'\t'<<"课程名称"<<'\t'<<"课程性质"<<'\t'<<"总学时"<<'\t'<<"授课学时"<<'\t'<<"实验或上机学时"<<'\t'<<"学分"<<'\t'<<"开课学期"<<'\t'<<"总人数"<<'\t'<<"剩余可选人数"<<endl;
	while(chooseableclasslist>>code>>name>>nature>>totaltime>>theorytime>>exptime>>credit>>term>>totalpeople>>leftpeople)//打印通选课列表
	{
		cout<<code<<'\t'<<name<<'\t'<<nature<<'\t'<<totaltime<<'\t'<<theorytime<<'\t'<<exptime<<'\t'<<credit<<'\t'<<term<<'\t'<<totalpeople<<'\t'<<leftpeople<<endl;
	}
	chooseableclasslist.close();//关闭通选课列表文件
	while(1)//是否选课或退课
	{
		cout<<"您要选课或者退课吗？"<<endl;
		cout<<"|1-选课"<<endl;
		cout<<"|2-退课"<<endl;
		cout<<"|3-不操作"<<endl;
		cout<<"请输入您要进行的操作："<<ends;
		R:cin>>choice;
		clearcin();//clear buff
		switch(choice)
		{
			case 1:selectclass(studentname);break;//选课
			case 2:quitclass(studentname);break;//退课
			case 3:goto W;
			default://输入有误
			{
				cout<<"您输入的标号有误哦，请重新输入："<<ends;
				goto R;
			}
		}
	}
W:;
}
void selectclass(char studentname[])//选课
{
	ofstream operationfile;
	fstream classfile,chooseableclasslist;
	char currenttime[32],title[100],name[50],nature[20],term[10],code[8],title2[100],sname[20],mycode[8],snum[20];
	int totaltime,theorytime,exptime,credit,totalpeople,leftpeople,classnumber=0,choice;
	bool mark=false;
	S:cout<<"请输入您想选课的课程编号："<<ends;
	cin>>mycode;
	clearcin();//清除缓存
	char filename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\课程学生名单\\";//学生名单路径
	strcat_s(filename,mycode);
	strcat_s(filename,".txt");//组成文件名
	chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\通选课列表.txt",ios::in);//打开通选课列表文件
	if(!chooseableclasslist)
	{
		studenterror();//文件不能打开
	}
	chooseableclasslist.seekg(0,ios::beg);
	chooseableclasslist.getline(title,100);
	while(chooseableclasslist>>code>>name>>nature>>totaltime>>theorytime>>exptime>>credit>>term>>totalpeople>>leftpeople)//遍历通选课列表
	{
		if(strcmp(code,mycode)==0)
		{
			if(leftpeople>0)
			{
				mark=true;//该课程有剩余名额
			}
		}
	}
	chooseableclasslist.close();//关闭通选课列表文件
	classfile.open(filename,ios::in);//打开通选课学生列表文件
	if(!filename)
	{
		studenterror();//文件不能打开
	}
	classfile.seekg(0,ios::beg);
	classfile.getline(title2,100);
	while(classfile>>snum>>sname)//判断学生是否在课程名单当中
	{
		if(strcmp(sname,studentname)==0)//学生在课程名单当中，表明已经选课
		{
			mark=false;
		}
	}
	classfile.close();//关闭学生名单列表文件
	if(mark==false)//不能选课
	{
		cout<<"对不起，当前通选课已满或您已报名，您要选择其它通选课吗？"<<endl;
		cout<<"|1-是"<<endl;
		cout<<"|2-否"<<endl;
		cout<<"您的选择是："<<ends;
		T:cin>>choice;
		clearcin();//清除缓存
		switch(choice)
		{
			case 1:goto S;
			case 2:break;
			default:
				{
					cout<<"您输入的标号有误，请重新输入："<<ends;
					goto T;
				}
		}
	}
	else//可以选课
	{
		chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\通选课列表.txt",ios::in);//打开通选课列表文件
		if(!chooseableclasslist)
		{
			studenterror();//文件不能打开
		}
		chooseableclasslist.seekg(0,ios::beg);
		chooseableclasslist.getline(title,100);
		struct aclass//构造一条课程记录对象结构
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
		struct classlist//构造链表节点结构
		{
			aclass thisclass;
			classlist *next;
		};
		classlist *a,*head,*b;
		a=new classlist;
		head=a;
		head->next=NULL;
		while(chooseableclasslist>>code>>name>>nature>>totaltime>>theorytime>>exptime>>credit>>term>>totalpeople>>leftpeople)//创建通选课列表链表
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
		chooseableclasslist.close();//关闭通选课列表文件
		while(a->next!=NULL)//改变剩余人数
		{
			if(strcmp(mycode,a->thisclass.classcode)==0)
			{
				a->thisclass.classleftpeople--;
			}
			a=a->next;
		}
		a=head;
		chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\通选课列表.txt",ios::out);//打开通选课列表文件
		if(!chooseableclasslist)
		{
			studenterror();//文件不能打开
		}
		chooseableclasslist<<"编号"<<'\t'<<"名称"<<'\t'<<"性质"<<'\t'<<"总学时"<<'\t'<<"授课学时"<<'\t'<<"实验或上机学时"<<'\t'<<"学分"<<'\t'<<"开课学期"<<'\t'<<"总人数"<<'\t'<<"剩余可选人数"<<'\n';//写入标题行
		while(a->next!=NULL)//写入新的通选课列表文件
		{
			chooseableclasslist<<a->thisclass.classcode<<'\t'<<a->thisclass.classname<<'\t'<<a->thisclass.classnature<<'\t'<<a->thisclass.classtotaltime<<'\t'<<a->thisclass.classtheorytime<<'\t'<<a->thisclass.classexptime<<'\t'<<a->thisclass.classcredit<<'\t'<<a->thisclass.classterm<<'\t'<<a->thisclass.classtotalpeople<<'\t'<<a->thisclass.classleftpeople<<'\n';
			a=a->next;
		}
		chooseableclasslist.close();//关闭通选课列表文件
		a=head;
		while(a->next!=NULL)//销毁通选课列表链表
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
		allstudents.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\学生档案\\全部学生名单.txt",ios::in);//打开系统学生名单文件
		if(!allstudents)
		{
			studenterror();//文件不能打开
		}
		allstudents.seekg(0,ios::beg);
		allstudents.getline(title,100);
		char studentnumber[12],studname[20],studentgender[5],studentmajor[20],studentclass[20],studentbirth[11],studentadd[50],studentdorm[50];
		while(allstudents>>studname>>studentnumber>>studentgender>>studentbirth>>studentmajor>>studentclass>>studentadd>>studentdorm)
		{
			if(strcmp(studentname,studname)==0)//查找学生
			{
				strcpy_s(snum,studentnumber);//复制学号
				break;
			}
		}
		allstudents.close();//关闭系统学生列表文件
		classfile.open(filename,ios::app);//打开课程学生名单文件
		if(!classfile)
		{
			studenterror();//文件不能打开
		}
		classfile<<snum<<'\t'<<studentname<<'\n';//写入一条新的学生信息
		classfile.close();//关闭课程学生名单文件
		operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
		if(!operationfile)
		{
			studenterror();//文件不能打开
		}
		getlocaltime(currenttime);//获得本地时间
		operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"选课，通选课编号为："<<mycode<<'\n';//写一条操作记录
		operationfile.close();//关闭系统操作日志文件
		cout<<"选课成功！"<<endl;
	}
}
void quitclass(char studentname[])//退课
{
	ofstream operationfile;
	fstream classfile,chooseableclasslist;
	char currenttime[32],title[100],name[50],nature[20],term[10],code[8],title2[100],sname[20],mycode[8],snum[12];
	int totaltime,theorytime,exptime,credit,totalpeople,leftpeople,classnumber=0,choice2=0;
	bool mark=false;
	U:cout<<"请输入您需要退选的通选课的课程编号："<<ends;
	cin>>mycode;//输入退选的课程编号
	clearcin();//清除缓存
	char filename[1000]="C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\课程学生名单\\";
	strcat_s(filename,mycode);
	strcat_s(filename,".txt");//构建通选课学生名单文件名
	chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\通选课列表.txt",ios::in);//打开通选课列表文件
	if(!chooseableclasslist)
	{
		studenterror();//文件不能打开
	}
	chooseableclasslist.seekg(0,ios::beg);
	chooseableclasslist.getline(title,100);
	while(chooseableclasslist>>code>>name>>nature>>totaltime>>theorytime>>exptime>>credit>>term>>totalpeople>>leftpeople)//查找课程并判断能否退课
	{
		if(strcmp(code,mycode)==0)//找到课程
		{
			if(leftpeople<totalpeople)//有人选课
			{
				mark=true;
			}
		}
	}
	chooseableclasslist.close();//关闭通选课列表文件
	if(mark==false)//不能退课
	{
		cout<<"对不起，无该通选课或无人选了该课或您已退选该课！"<<endl;
		cout<<"您要退选其它通选课吗？"<<endl;
		cout<<"|1-是"<<endl;
		cout<<"|2-否"<<endl;
		cout<<"您的选择是："<<ends;
		BJ:cin>>choice2;
		clearcin();//清除缓存
		switch(choice2)
		{
			case 1:goto U;
			case 2:goto BI;
			default:
				{
					cout<<"您输入的标号不对哦！请重新输入："<<ends;
					goto BJ;
				}
		}
	}
	classfile.open(filename,ios::in);//打开课程班级名单
	if(!classfile)
	{
		studenterror();//文件不能打开
	}
	classfile.seekg(0,ios::beg);
	classfile.getline(title2,100);
	while(classfile>>snum>>sname)//j判断学生是否在学生列表当中
	{
		if(strcmp(sname,studentname)==0)//学生在列表当中
		{
			mark=true;
		}
	}
	classfile.close();//可以退课
	chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\通选课列表.txt",ios::in);//打开通选课列表文件
	if(!chooseableclasslist)
	{
		studenterror();//文件不能打开
	}
	chooseableclasslist.seekg(0,ios::beg);
	chooseableclasslist.getline(title,100);
	struct aclass//构造一条课堂记录的结构
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
	struct classlist//构造链表节点结构
	{
		aclass thisclass;
		classlist *next;
	};
	classlist *a,*head,*b;
	a=new classlist;
	head=a;
	head->next=NULL;
	while(chooseableclasslist>>code>>name>>nature>>totaltime>>theorytime>>exptime>>credit>>term>>totalpeople>>leftpeople)//创造通选课链表
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
	chooseableclasslist.close();//关闭通选课列表文件
	while(a->next!=NULL)//改变剩余人数
	{
		if(strcmp(mycode,a->thisclass.classcode)==0)//找到课
		{
			a->thisclass.classleftpeople++;
			break;
		}
		a=a->next;
	}
	a=head;
	chooseableclasslist.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\通选课列表.txt",ios::out);//打开通选课列表文件
	if(!chooseableclasslist)
	{
		studenterror();//文件不能打开
	}
	chooseableclasslist<<"编号"<<'\t'<<"名称"<<'\t'<<"性质"<<'\t'<<"总学时"<<'\t'<<"授课学时"<<'\t'<<"实验或上机学时"<<'\t'<<"学分"<<'\t'<<"开课学期"<<'\t'<<"总人数"<<'\t'<<"剩余可选人数"<<'\n';//写入标题行
	while(a->next!=NULL)//写入新的通选课列表
	{
		chooseableclasslist<<a->thisclass.classcode<<'\t'<<a->thisclass.classname<<'\t'<<a->thisclass.classnature<<'\t'<<a->thisclass.classtotaltime<<'\t'<<a->thisclass.classtheorytime<<'\t'<<a->thisclass.classexptime<<'\t'<<a->thisclass.classcredit<<'\t'<<a->thisclass.classterm<<'\t'<<a->thisclass.classtotalpeople<<'\t'<<a->thisclass.classleftpeople<<'\n';
		a=a->next;
	}
	chooseableclasslist.close();//关闭通选课列表文件
	a=head;
	while(a->next!=NULL)//校会通选课链表
	{
		b=a;
		a=a->next;
		delete b;
	}
	delete a;
	a=NULL;
	b=NULL;
	head=NULL;
	classfile.open(filename,ios::in);//打开课程名单
	if(!classfile)
	{
		studenterror();//文件不能打开
	}
	classfile.seekg(0,ios::beg);
	classfile.getline(title2,100);
	struct classstudent//构建一个学生的节点结构
	{
		char stunum[12];
		char stuname[20];
		classstudent *next;
	};
	classstudent *c,*record,*d;
	c=new classstudent;
	record=c;
	while(classfile>>snum>>sname)//构造学生名单链表
	{
		strcpy_s(c->stuname,sname);
		strcpy_s(c->stunum,snum);
		d=new classstudent;
		c->next=d;
		c=c->next;
		c->next=NULL;
	}
	classfile.close();//关闭学生名单文件
	c->next=NULL;
	c=record;
	if(strcmp(record->stuname,studentname)==0)//删除学生
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
	classfile.open(filename,ios::out);//打开学生名单文件
	classfile<<"学号"<<'\t'<<"学生名单"<<'\n';//写入标题行
	while(c->next!=NULL)//写入新的学生名单
	{
		classfile<<c->stunum<<'\t'<<c->stuname<<'\n';
		c=c->next;
	}
	classfile.close();//关闭学生名单链表文件
	c=record;
	while(c->next!=NULL)//销毁链表
	{
		d=c;
		c=c->next;
		delete d;
	}
	delete c;
	c=NULL;
	d=NULL;
	record=NULL;
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作记录文件
	if(!operationfile)
	{
		studenterror();//文件不能打开
	}
	getlocaltime(currenttime);//获得本地时间
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"退选，通选课编号为："<<mycode<<'\n';//写入一条操作记录
	operationfile.close();//关闭系统操作记录文件
	cout<<"退选成功！"<<endl;
	BI:;
}
void gotoclassrecord(char studentname[])//查看考勤记录
{
	char title[100],name[20],number[12],clas[50],teacher[20],date[11],condition[5],currenttime[32];
	int recordnumber=0;
	ifstream diligency;
	diligency.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\课程考勤记录.txt",ios::in);//打开课程考勤记录文件
	if(!diligency)
	{
		studenterror();//文件不能打开
	}
	diligency.seekg(0,ios::beg);
	diligency.getline(title,100);
	cout<<"现在开始打印你的课程考勤情况..."<<endl;//开始打印考勤情况
	cout<<"课程名称"<<'\t'<<"上课日期"<<'\t'<<"考勤情况"<<'\t'<<endl;
	while(diligency>>number>>name>>clas>>teacher>>date>>condition)
	{
		if(strcmp(name,studentname)==0)//该条考勤记录为当前学生的记录
		{
			cout<<clas<<'\t'<<date<<'\t'<<condition<<endl;
		}
	}
	diligency.close();//关闭考勤记录文件
	cout<<"所有考勤记录显示完毕！"<<endl;
	ofstream operationfile;
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作记录文件
	if(!operationfile)
	{
		studenterror();//文件不能打开
	}
	getlocaltime(currenttime);//获得本地时间
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"查询考勤情况"<<'\n';//写入一条操作记录
	operationfile.close();//关闭系统操作文件
} 
void studentemail(char studentname[])//学生电子邮箱系统
{
	int choice;
	while(1)
	{
		cout<<"请选择您想使用的电子邮件功能："<<endl;
		cout<<"|1-查看收到的电子邮件"<<endl;
		cout<<"|2-发送电子邮件给他人"<<endl;
		cout<<"|3-删除收件箱当中的邮件"<<endl;
		cout<<"|4-退出电子邮箱系统"<<endl;
		cout<<"请输入您的选择："<<ends;
		Y:cin>>choice;
		clearcin();//清除缓存
		switch(choice)//根据对应的代号选择功能
		{
			case 1:watchemail(studentname);break;
			case 2:sendemail(studentname);break;
			case 3:deleteemail(studentname);break;
			case 4:goto X;
			default:
				{
					cout<<"您输入的标号有误哦！请重新输入："<<ends;
					goto Y;
				}
		}
	}
X:;
}
void watchemail(char studentname[])//查看收件箱
{
	ofstream operationfile;
	ifstream emailfile;
	char currenttime[32],title[100],stime[32],sperson[50],scontent[500],rperson[20],stitle[50];
	int allrecord=0;
	emailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\电子邮件来往信件记录.txt",ios::in);//打开电子邮件记录文件
	if(!emailfile)
	{
		studenterror();//文件不能打开
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		studenterror();//文件不能打开
	}
	getlocaltime(currenttime);//获得本地时间
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"读取邮件"<<'\n';//写入一条操作记录
	operationfile.close();//关闭系统操作日志文件
	emailfile.seekg(0,ios::beg);
	emailfile.getline(title,100);
	cout<<"现在开始打印邮件..."<<endl;
	while(emailfile>>stime>>sperson>>rperson>>stitle>>scontent)//打印收件箱当中的邮件
	{
		if(strcmp(rperson,studentname)==0)//收件人为当前学生
		{
			cout<<"======================================================================================"<<endl;
			cout<<"发送人："<<sperson<<endl;
			cout<<"发送时间："<<stime<<endl;
			cout<<"邮件标题："<<stitle<<endl;
			cout<<"邮件内容："<<scontent<<endl;
		}
	}
	emailfile.close();//关闭邮件文件
	cout<<"所有信件显示完毕！"<<endl;
}
void sendemail(char studentname[])
{
	ofstream emailfile;
	ofstream operationfile;
	emailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\电子邮件来往信件记录.txt",ios::app);//打开系统邮箱文件
	if(!emailfile)
	{
		studenterror();//文件不能打开
	}
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		studenterror();//文件不能打开
	}
	char targetuser[20],emailtitle[50],emailcontent[500],currenttime[32];
	int choice;
	AA:cout<<"请输入接收人姓名："<<ends;
	cin>>targetuser;
	clearcin();//清除缓存
	cout<<"您输入的接收方是："<<targetuser<<"，您确定吗（确定输入1，不确定输入0）："<<ends;
	AB:cin>>choice;//确认接收方
	clearcin();//清除缓存
	switch(choice)
	{
		case 0:goto AA;
		case 1:break;
		default:
			{
				cout<<"您的输入不正确哦！请重新输入："<<ends;
				goto AB;
			}
	}
	cout<<"邮件标题（限50字符内）："<<ends;
	cin>>emailtitle;
	clearcin();//清除缓存
	cout<<"请输入邮件内容（限500字符内，请勿换行）："<<ends;
	cin>>emailcontent;
	clearcin();//清除缓存
	getlocaltime(currenttime);//获得本地时间
	emailfile<<currenttime<<'\t'<<studentname<<'\t'<<targetuser<<'\t'<<emailtitle<<'\t'<<emailcontent<<'\n';//写入一条邮件记录
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<studentname<<"写信给"<<targetuser<<'\n';//写入一条操作记录
	operationfile.close();//关闭系统操作日志文件
	emailfile.close();//关闭系统电子邮箱文件
	cout<<"邮件发送成功！"<<endl;
}
bool studentlogin(char studentname[])//学生登陆
{
	int usernamecondition,passwordcondition,namechoice,passwordchoice;
	char studentpassword[20],currenttime[32];
	F:cout<<"你的姓名："<<ends;
	cin>>studentname;//输入姓名
	clearcin();//清除缓存
	H:cout<<"密码口令："<<ends;
	cin>>studentpassword;//输入密码
	clearcin();//清除缓存
	usernamecondition=findstudent(studentname);//在学生名单当中查找学生是否存在
	if(usernamecondition==0)//学生不在系统学生名单当中
	{
		cout<<"在教务系统当中找不到你的记录！是不是打错名字了，又亦或是学校还没帮你注册？"<<endl;
		cout<<"你想继续进入系统还是退出学生教务系统？"<<endl;
		cout<<"|1-继续进入"<<endl;
		cout<<"|2-退出了"<<endl;
		cout<<"请输入你的选择："<<ends;
		G:cin>>namechoice;
		clearcin();//清除缓存
		switch(namechoice)
		{
			case 1:goto F;
			case 2:return false;
			default:
			{
				cout<<"不行哦你还是输错了，喝杯水清醒一下再输入吧："<<ends;
				goto G;
			}
		}
	}
	passwordcondition=comparepassword(studentname,studentpassword);//比较密码，判断是否密码正确
	if(passwordcondition==0)//密码错误
	{
		cout<<"密码口令错误！"<<endl;
		cout<<"你想继续进入系统还是退出学生教务系统？"<<endl;
		cout<<"|1-继续进入"<<endl;
		cout<<"|2-退出了"<<endl;
		cout<<"请输入你的选择："<<ends;
		I:cin>>passwordchoice;
		clearcin();//清除缓存
		switch(passwordchoice)
		{
			case 1:goto H;
			case 2:return false;
			default:
			{
				cout<<"不行哦你还是输错了，喝杯水清醒一下再输入吧："<<ends;
				goto I;
			}
		}
	}
	getlocaltime(currenttime);//获得本地时间
	ofstream loginfile;
	loginfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\登陆日志.txt",ios::app);//打开系统登陆日志文件
	if(!loginfile)
	{
		studenterror();//文件不能打开
	}
	loginfile<<currenttime<<'\t'<<studentname<<'\t'<<"学生"<<'\n';//写入一条登陆记录
	loginfile.close();//关闭登陆日志文件
	cout<<"登陆成功！"<<endl;
	return true;
}
void studentfunction(char studentname[])//学生功能选择界面
{
	int choice;
	while(1)//choose function
	{
		cout<<"下面是功能列表，请你选择你需要操作的项目。"<<endl;
		cout<<"|1-查询或修改个人档案"<<endl;
		cout<<"|2-调出你的成绩"<<endl;
		cout<<"|3-选修课操作"<<endl;
		cout<<"|4-上课考勤记录查询"<<endl;
		cout<<"|5-查看你的反馈回复"<<endl;
		cout<<"|6-邮件系统"<<endl;
		cout<<"|7-修改密码"<<endl;
		cout<<"|8-退出系统"<<endl;
		cout<<"您想选择的功能代号是："<<ends;
		E:cin>>choice;
		clearcin();//清除缓存
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
				cout<<"输入有误哦！能不能麻烦你重新输入一下功能代号："<<ends;
				goto E;
			}
		}
		cout<<endl;
	}
	BB:;
}
void studentfeedback(char studentname[])//学生选择反馈界面
{
	int choice;
	cout<<studentname<<"，你好！您想直接退出学生教务管理系统还是填写一下反馈再退出系统？"<<endl;
	cout<<"|1-直接退出"<<endl;
	cout<<"|2-填写反馈再退出"<<endl;
	cout<<"你的选择是："<<ends;
	K:cin>>choice;
	clearcin();//清除缓存
	switch(choice)
	{
		case 1:goto J;
		case 2:feedback(studentname);break;//要求写入反馈
		default:
		{
			cout<<"输入指令错误哦，请重新输入吧："<<ends;
			goto K;
		}
	}
	J:;
}
void studentoperate()//学生操作界面整体框架
{
	char studentname[20]="游客";
	bool condition=false;
	cout<<"同学，欢迎使用学生教务系统！请登陆..."<<endl;
	condition=studentlogin(studentname);//学生登陆
	if(condition)//登陆成功
	{
		cout<<studentname<<"，欢迎您！"<<endl;
		studentfunction(studentname);
	}
	studentfeedback(studentname);//选择写反馈
	cout<<studentname<<"，感谢使用学生教务系统，再见！"<<endl;
}
void resetpassword(char studentname[])//修改密码
{
	ifstream studentaccountdata;
	ofstream operationfile,newaccountdata;
	char title[100],name[20],pass[20],newpassword[20],currenttime[32];
	struct account//构造账户信息链表节点结构
	{
		char sname[20];
		char spassword[20];
		account *next;
	};
	account *head,*a,*b;
	head=new account;
	a=head;
	head->next=NULL;
	studentaccountdata.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\学生账户与密码.txt",ios::in);//打开系统学生名单文件
	if(!studentaccountdata)
	{
		studenterror();//文件不能打开
	}
	studentaccountdata.seekg(0,ios::beg);
	studentaccountdata.getline(title,100);
	while(studentaccountdata>>name>>pass)//构造链表
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
	studentaccountdata.close();//关闭账户信息文件
	cout<<"请输入新密码（20字符以内）："<<ends;
	cin>>newpassword;//输入新密码
	clearcin();//清除缓存
	while(a->next!=NULL)//查找学生并修改密码
	{
		if(strcmp(a->sname,studentname)==0)//找到该学生
		{
			strcpy_s(a->spassword,newpassword);
			break;
		}
		a=a->next;
	}
	a=head;
	newaccountdata.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\学生账户与密码.txt",ios::out);//打开新的学生账户密码记录文件
	if(!newaccountdata)
	{
		studenterror();//文件不能打开
	}
	newaccountdata<<"用户名"<<'\t'<<"密码"<<'\n';//写入标题行
	while(a->next!=NULL)//写入新的账户密码记录
	{
		newaccountdata<<a->sname<<'\t'<<a->spassword<<'\n';
		a=a->next;
	}
	a=head;
	newaccountdata.close();//关闭学生账户信息文件
	while(head->next!=NULL)//销毁账户信息链表
	{
		head=head->next;
		delete a;
	}
	delete head;
	head=NULL;
	a=NULL;
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		studenterror();//文件不能打开
	}
	getlocaltime(currenttime);//获得本地时间
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"修改密码"<<'\n';//写入一条操作记录
	operationfile.close();//关闭系统操作日志文件
	cout<<"密码修改成功！"<<endl;
}
void deleteemail(char studentname[])//删除邮件
{
	ofstream operationfile,newemailfile;
	ifstream orientemailfile;
	char esendtime[32],esender[50],ereciever[50],etitle[50],econtent[500],title[100],currenttime[32];
	int choice=0,mark=0,i=0,j=0;
	struct oneemail//构造邮件链表节点结构
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
	orientemailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\电子邮件来往信件记录.txt",ios::in);//打开系统电子邮件文件
	if(!orientemailfile)
	{
		studenterror();//文件不能打开
	}
	orientemailfile.seekg(0,ios::beg);
	orientemailfile.getline(title,100);
	head=new oneemail;
	a=head;
	a->next=NULL;
	cout<<"现在开始打印你的收件箱当中的邮件清单及其编号..."<<endl;
	while(orientemailfile>>esendtime>>esender>>ereciever>>etitle>>econtent)//开始打印收件箱并对可能需要删除的邮件进行编码
	{
		a->mycode=-1;
		if(strcmp(ereciever,studentname)==0)//收件人对应的
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
	orientemailfile.close();//关闭电子邮箱文件
	while(1)
	{
		cout<<"请输入您需要删除的邮件编号（按Ctrl+Z结束）："<<ends;
		CB:if(cin>>choice)
		{
			clearcin();//清除缓存
			if((choice<1)||(choice>mark))//判断输入是否正确
			{
				cout<<"输入有误，请重新输入（按Ctrl+Z结束）："<<ends;
				goto CB;
			}
			choice--;
			if(head->mycode==choice)//删除对应邮件所对应的节点
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
	newemailfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\电子邮件来往信件记录.txt",ios::out);//打开新的系统电子邮件系统文件
	if(!newemailfile)
	{
		studenterror();//文件不能打开
	}
	newemailfile<<"发送时间"<<'\t'<<"发件人"<<'\t'<<"收件人"<<'\t'<<"邮件标题"<<'\t'<<"邮件内容"<<'\n';//写入标题行
	while(a->next!=NULL)//写入新的电子邮件链表
	{
		newemailfile<<a->sendtime<<'\t'<<a->sender<<'\t'<<a->reciever<<'\t'<<a->emailtitle<<'\t'<<a->content<<'\n';
		a=a->next;
	}
	newemailfile.close();//关闭系统电子邮件文件
	operationfile.open("C:\\Users\\lenovo\\Documents\\Visual Studio 2010\\Projects\\学生教务管理系统\\学生教务管理系统\\系统档案\\操作日志.txt",ios::app);//打开系统操作日志文件
	if(!operationfile)
	{
		studenterror();//文件不能打开
	}
	getlocaltime(currenttime);//获得本地时间
	operationfile<<currenttime<<'\t'<<studentname<<'\t'<<"删除邮件"<<'\n';//写入一条新操作记录
	operationfile.close();//关闭系统操作日志文件
	a=head;
	b=NULL;
	while(head->next!=NULL)//销毁电子邮件链表
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
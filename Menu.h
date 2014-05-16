#ifndef MENU_H
#define MENU_H
#include"List.h"
#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<iomanip>
#include<fstream>
#include <time.h>
#include <windows.h>
#include"Node.h"
#include"User.h"
using namespace std;
struct MenuItem													//主菜单结构体
{	int no;
	char menuItemName[80];
};
MenuItem menuItems[10]={										//主菜单
	{1,"add Record(增加记录)"},									//增加记录
	{2,"delete Record(删除记录)"},								//删除记录
	{3,"display AllRecord(显示所有记录)"},						//显示所有记录
	{4,"Query(查找并显示一个记录)"},							//按姓名查找并显示一个记录
	{5,"Modify Record(修改一个记录)"},							//按姓名查找并修改一个记录
	{6,"Add from a Text File(从正文文件添加数据到库表)"},		//从正文文件添加数据到库表
	{7,"write to a Text File(将库表中数据写入正文文件)"},		//将库表中数据写入正文文件
	{8,"Edit Uesername And Password(修改用户名和密码)"},		//排序
	{9,"delete AllRecord(删除全部记录)"},						//删除全部记录
	{0,"Quit(退出)"},											//退出
};
void displayMenu()
{
	for (int i=0; i<10; i++)									/*10可改成11,显示结果会在“0.Quit(退出)”后多一行“0.   ”，不影响程序运行
																与下面“子菜单”中情况对比!!!!*/
	{
		cout<<"	"<<menuItems[i].no<<". "<<menuItems[i].menuItemName<<'\n'<<endl;
	}
}
int menu_select()
{  	char c;
	do
	{
		system("cls");												//清屏
        cout<<"================物流管理系统================"<<endl;
		cout<<endl;
		displayMenu();												//调用displayMenu函数，显示主菜单
		cout<<endl;
		cout<<"============================================"<<endl;
		cout<<"Input 1-9,0 to choice:"<<endl;
		cin>>c;
		cin.ignore(1024,'\n');
	}while(c<'0'||c>'9');											//循环，输入'0'-'9'字符以外的字符无效，重新输入
	return (c-'0');													//返回0--9
}
int menu_look()														//按照运单号还是手机号查找 选择的子菜单
{
	
	char c;
	char *m[3]={"(1) LookUp By PackageNum(按运单号)",				//修改姓名
	"(2) LookUp By Mobilephone(按收件人电话)",						//修改办公室电话
	"(0) quit(退出)"};												//退出

	do{
		system("cls");												//清屏
		cout<<"===============Modify Record子菜单==============="<<endl;
		cout<<endl;
		for(int i=0;i<3;i++)
		{															//显示子菜单 
			cout<<m[i]<<endl;
		}
		cout<<endl;
		cout<<"============================================"<<endl;
		cout<<"Input 1-2,0 to choice:";
		cin>>c;
		cin.ignore(1024,'\n');
	}while(c<'0'||c>'2');											//循环，输入'0'-'2'字符以外的字符无效，重新输入
	return (c-'0');													//返回0--2
	

}

//==========================以下为修改函数的内容=================================//

void ModifyName(List& list,Node *p,User *q)							//按姓名查找，修改一条记录，只修改姓名并重新排序
{
	char c;
	string name;
	if(p==NULL)	
	{																//未找到
		cout<<"没有此名"<<endl;	
	}
	else															//找到
	{
		q->show_Node(p);											//调用show_Node函数，显示结点数据
		cout<<"确定修改输入?Y/N"<<endl;
		cin>>c;
		if(c=='Y'||c=='y')											//输入Y(y),确定修改
		{
			cout<<"请输入修改后名字"<<endl;
			cin>>name;
			p->SetShoujian_Name(name);								//调用SetShoujian_Name函数，修改姓名
			q->show_Node(p);										//调用show_Node函数，显示结点数据
		}
		else if(c=='N'||c=='n')										//输入N(n),退出修改
			return;
	}
}
void ModifyPackageNum(List& list,Node *p,User *q)					//按运单号查找，修改一条记录，只修改收件人电话并重新排序
{
	char c;
	int num;
	if(p==NULL)														//未找到
		cout<<"没有此运单"<<endl;
	else															//找到
	{
		q->show_Node(p);											//调用show_Node函数，显示结点数据
		cout<<"确定修改输入?Y/N"<<endl;
		cin>>c;
		if(c=='Y'||c=='y')											//输入Y(y),确定修改
		{
			cout<<"请输入修改后运单号"<<endl;
			cin>>num;
			p->SetPackageNum(num);									//调用setPackageNum函数，修改办公室电话
			q->show_Node(p);										//调用show_Node函数，显示结点数据
	
		}
		else if(c=='N'||c=='n')										//输入N(n),退出修改
			return;
	}
}
void ModifyJijian_Phone(List&list,Node *p,User *q)					//按姓名查找，修改一条记录，只修改寄件人电话并重新排序	
{	
	char c;
	string hp;
	if(p==NULL)														//未找到
		cout<<"没有运单"<<endl;
	else															//找到
	{
		q->show_Node(p);											//调用show_Node函数，显示结点数据
		cout<<"确定修改?Y/N"<<endl;
		cin>>c;
		if(c=='Y'||c=='y')											//输入Y(y),确定修改
		{
			cout<<"请输入修改后寄件人电话"<<endl;
			cin>>hp;
			p->SetJijian_Phone(hp);									//调用SetJijian_Phone函数，修改收件人电话
			q->show_Node(p);										//调用show_Node函数，显示结点数据
			
		}
		else if(c=='N'||c=='n')										//输入N(n),退出修改
			return;	
	}
} 
void ModifyShoujian_Phone(List&list,Node *p,User *q)				//按姓名查找，修改一条记录，只修改收件人手机号码并重新排序	
{	
	char c;
	string mp;
	if(p==NULL)														//未找到
		cout<<"没有运单"<<endl;
	else															//找到
	{
		q->show_Node(p);											//调用show_Node函数，显示结点数据
		cout<<"确定修改?Y/N"<<endl;
		cin>>c;
		if(c=='Y'||c=='y')											//输入Y(y),确定修改
		{
			cout<<"请输入修改后收件人手机号码"<<endl;
			cin>>mp;
			p->SetShoujian_Phone(mp);								//调用SetShoujian_Phone函数，修改手机号码
			q->show_Node(p);										//调用show_Node函数，显示结点数据
	
		}
		else if(c=='N'||c=='n')										//输入N(n),退出修改
			return;
	}
}
void ModifyNote(List&list,Node *p,User *q)							//按姓名查找，修改一条记录，只修改Note并重新排序
{
	char c;
	string Note;
	if(p==NULL)														//未找到
		cout<<"没有运单"<<endl;
	else								 							//找到
	{
		q->show_Node(p);											//调用show_Node函数，显示结点数据
		cout<<"确定修改?Y/N"<<endl;
		cin>>c;
		if(c=='Y'||c=='y')											//输入Y(y),确定修改
		{
			cout<<"请输入修改后的备注"<<endl;
			cin>>Note;
			p->SetNote(Note);										//调用setNote函数，修改Note
			q->show_Node(p);										//调用show_Node函数，显示结点数据
		
		}
		else if(c=='N'||c=='n')										//输入N(n),退出修改
			return;
	}
}

void ModifyMoney(List& list,Node *p,User *q)						//按运单号查找，修改一条记录，只修改收件人电话并重新排序	
{
	char c;
	int num;
	if(p==NULL)														//未找到
		cout<<"没有此运单"<<endl;
	else															//找到
	{
		q->show_Node(p);											//调用show_Node函数，显示结点数据
		cout<<"确定修改输入?Y/N"<<endl;
		cin>>c;
		if(c=='Y'||c=='y')											//输入Y(y),确定修改
		{
			cout<<"请输入修改后运单号"<<endl;
			cin>>num;
			p->SetMoney(num);										//调用SetMoney函数，修改金额
			q->show_Node(p);										//调用show_Node函数，显示结点数据
	
		}
		else if(c=='N'||c=='n')										//输入N(n),退出修改
			return;
	}
}
void ModifyBaojia(List& list,Node *p,User *q)						//按运单号查找，修改一条记录，只修改收件人电话并重新排序	//55555555555
{
	char c;
	int num;
	if(p==NULL)														//未找到
		cout<<"没有此运单"<<endl;
	else															//找到
	{
		q->show_Node(p);											//调用show_Node函数，显示结点数据
		cout<<"确定修改输入?Y/N"<<endl;
		cin>>c;
		if(c=='Y'||c=='y')											//输入Y(y),确定修改
		{
			cout<<"请输入修改后运单号"<<endl;
			cin>>num;
			p->SetBaojia(num);										//调用SetBaojia函数，修改保价金额
			q->show_Node(p);										//调用show函数，显示结点数据
			
		}
		else if(c=='N'||c=='n')										//输入N(n),退出修改
			return;
	}
}
void ModifyByNum(List &list,User *q)								//按姓名查找并修改一条记录
{
	Node *p;
	int num;
	cout<<"请输入运单号"<<endl;
	cin>>num;
	cin.clear();
	cin.sync();
	if(p=list.LookUp(num)){
		switch(q->Menu_Modify())									//调用menu函数，显示子菜单并给出选择
		{
		case 1:ModifyPackageNum(list,p,q);							//修改姓名
			cout<<"已执行1.Modify PackageNum(修改运单号):"<<endl;
			
			break;
		case 2:ModifyName(list,p,q);								//修改运单号吗
			cout<<"已执行2.Modify Name(修改收件人姓名):"<<endl;
		
			break;
		case 3:ModifyShoujian_Phone(list,p,q);						//修改寄件人电话
			cout<<"已执行3.Modify MobilePhone(修改收件人手机号):"<<endl;
			
			break;
		case 4:ModifyJijian_Phone(list,p,q);						//修改收件人电话
			cout<<"已执行4.Modify Mobile Phone(修改寄件人电话):"<<endl;
			
			break;
		case 5:ModifyNote(list,p,q);								//修改备注
			cout<<"已执行7.Modify Note(修改备注):"<<endl;
			
			break;
		case 6:ModifyMoney(list,p,q);								//修改邮费
			cout<<"已执行8.Modify Money(修改邮费):"<<endl;
			
			break;
		case 7:ModifyBaojia(list,p,q);								//修改保价费用
			cout<<"已执行9.Modify Baojia(修改保价费用):"<<endl;
		
			break;
		case 0:														//退出
			
			return;
		}
	}
	else{
		cout<<"没有此运单"<<endl;
	}
}

void Modify(List &list,User *q)										//按运单号查找并修改一条记录	
{	
	
	
	switch(1)														//调用menu函数，显示子菜单并给出选择
	{
	case 1:ModifyByNum(list,q);										//根据运单号修改

		break;
	case 0:															//退出
		return;
	}
	
}


//========================================以上为修改函数的内容================================================//

void query_mobile(List& list,User *q)								// 按姓名查找结点并显示一条记录     
{
	Node *p;
	string mobile;
	cout<<"请输入要查找的收件人电话"<<endl;
	cin>>mobile;
	list.query_bymobile(mobile,q);
	
}
void query_num(List& list,User *q)									// 按姓名查找结点并显示一条记录        
{
	Node *p;
	int num;
	cout<<"请输入要查找的运单号码"<<endl;
	cin>>num;
	cin.clear();
	cin.sync();
	p=list.LookUp(num);												//调用LookUp函数（AddrList中），按姓名查找结点，返回该结点指针
	if(p==NULL)														//未找到
		cout<<"没有此名字"<<endl;
	else
	{																//找到，调用show函数（Node中），显示结点数据
		q->showsheet();
		q->show_Node(p);
	}
}
void Look(List &list,User *q)										//按查找一条记录,并显示出信息	//44444444
{
	switch(menu_look())												//调用menu函数，显示子菜单并给出选择
	{
	case 1:query_num(list,q);										//按运单号查找并返回节点的指针
		cout<<"已执行1.query_num(根据运单号查找):"<<endl;
		system("pause");
		break;
	case 2:query_mobile(list,q);									//按收件人电话查找
		cout<<"已执行2.query_mobile(根据收件人电话查找):"<<endl;
		system("pause");
		break;
	}
}

void del(List&list){
	int num;
	string mobile;
	switch(menu_look())												//调用menu函数，显示子菜单并给出选择
	{
	case 1:cout<<"请输入运单号："<<endl;
		cin>>num;
		list.Delete(num);											//按运单号查找并删除

		break;
	case 2:cout<<"请输入手机号："<<endl;
		cin>>mobile;
		list.Delete(mobile);										//按收件人手机号查找并删除

		break; 
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                     移动文本块区域                                              //
/////////////////////////////////////////////////////////////////////////////////////////////////////
void MoveText(int x, int y, SMALL_RECT rc, HANDLE &hOut)
{
	COORD crDest = {x, y};
	CHAR_INFO chFill;
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo( hOut, &bInfo ); 
	chFill.Attributes = bInfo.wAttributes;
	chFill.Char.AsciiChar = ' ';
	ScrollConsoleScreenBuffer(hOut, &rc, NULL, crDest, &chFill);
}
//////////////////////////////////////////////////////////////////////////////////////////
//                                     开始进度条特效                                   //
//////////////////////////////////////////////////////////////////////////////////////////
void logo()
{
	system("title 物流管理系统--程序加载中...      by 吴未名 161330119");
	system("cls");
    HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);					//获取标准输出设备句柄
	string str1("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	string str2("┃■■■                                                                    ┃");
	string str3("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");	
	string str("===============================================================================");
	cout<<endl
		<<"╔════════════════物流管理系统═══════════════╗\n"//1
	    <<"║                                                                          ║\n"//2 
		<<"║                                                                          ║\n"//4
		<<"║                         │＼＿＿╭╭╭╭╭＿＿／│                       ║\n"//5
        <<"║                         │　　　　　　　　　　　│                       ║\n"//6
        <<"║                         │　　　　　　　　　　　│                       ║\n"//7                      
        <<"║                         │　－　　　　　　　－　│                       ║\n"//8
	    <<"║                         │≡　　　　ｏ　　　　≡│                       ║\n"//9
        <<"║                         │　　　　　　　　　　　│                       ║\n"//10
        <<"║                         ╰──┬Ｏ◤▽◥Ｏ┬──╯                       ║\n"//11
        <<"║                  　           ｜　　ｏ　　｜                             ║\n"//12
        <<"║            　　　             ｜╭－－－╮~~~~Hello!  (^_^)∠※          ║\n"//13
        <<"║                                                                          ║\n"//14
		<<"║                                                                          ║\n"//15
		<<"║                            欢迎进入物流管理系统!                         ║\n"//16
		<<"║                                                                          ║\n"//3
		<<"║                                              设计:   by      吴未名      ║\n"//17
		<<"╚═════════════════════════════════════╝\n\n";
	cerr<<"                             数据初始化中 Loading ... "<<endl;        
	cerr<<str1<<endl;
	cerr<<str2<<endl;
	cerr<<str3<<endl;
	int i = 3;												//循环次数为2次
	while (1)
	{		
		int j=0;
		for (j=0;j<str2.length()-12;++j) 
		{
			SMALL_RECT rc = {2+j, 22, 7+j, 22};
			MoveText(3+j, 22, rc, hOut);
			Sleep(20);
		}
		SMALL_RECT rc2={2+j, 22, 7+j, 22};
		Sleep(60);
		if (--i==1) 
			break;
		MoveText(2, 22, rc2, hOut);
	}	
}
void super_end(List&list)
{
	list.WriteToFile("addrlist.dat");						//调用WriteToFile函数（AddrList中），将链表中的数据写入指定的二进制文件
	cerr<<"\n                                  正在退出!"<<endl;                         
	cerr<<"                             数据保存中 saving ";        
	for (int i=0; i<12; ++i) 
	{
		Sleep(250);
		cerr<<'.';
		if ((i!=0) && (i%4==0)) 
		{
			cerr<<"\b"<<" "<<"\b";
			cerr<<"\b"<<" "<<"\b";
			cerr<<"\b"<<" "<<"\b";
			cerr<<"\b"<<" "<<"\b";
		} 
	}
	cerr<<"\n                                     OK!"<<endl;
}
void quit(List&list)
{
	system("title 物流管理系统--保存信息中...      by 作者");
	system("cls");
	cout<<endl
		<<" ╔════════════════物流管理系统═══════════════╗"<<endl
		<<" ║                                                                          ║"<<endl
		<<" ║                                                                          ║"<<endl
		<<" ║                          │＼＿＿╭╭╭╭╭＿＿／│                      ║"<<endl
		<<" ║                          │　　　　　　　　　　　│                      ║"<<endl
		<<" ║                          │　　　　　　　　　　　│                      ║"<<endl
		<<" ║                          │　－　　　　　　　－　│                      ║"<<endl
		<<" ║                          │≡　　　　ｏ　　　　≡│                      ║"<<endl
		<<" ║                          │　　　　　　　　　　　│                      ║"<<endl
		<<" ║                          ╰──┬Ｏ◤▽◥Ｏ┬──╯                      ║"<<endl
		<<" ║                                ｜　　ｏ　　｜                  ／~~~     ║"<<endl
		<<" ║                                ｜╭－－－╮ 感谢您使用! (^_^)／          ║"<<endl
		<<" ║                                                                          ║"<<endl
		<<" ║                                                                          ║"<<endl
		<<" ║                                                                          ║"<<endl
		<<" ║                                               再见!!                     ║"<<endl
		<<" ║                                                                          ║"<<endl
		<<" ║                                                   设计: by 吴未名        ║"<<endl
		<<" ╚═════════════════════════════════════╝"<<endl;
	super_end(list);
	
	exit(0);
};



#endif
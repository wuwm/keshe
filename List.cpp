#include"List.h"
#include<iomanip>
using namespace std;
int List::sum=0;									//初始化静态变量sum为0
int List::num=0;									//初始化num变量为0
void List::Addtail(Node *p)							//将p指向的“结点”加入到链表尾部
{
	tail->next=p;
	p->next=NULL;
	tail=p;
	num++;
	sum+=p->Money;
}
void List::AddSort(Node *p)							//将p指向的结点按运单号递增的顺序插入到链表中
{ 
	Node *p1,*p2=head;
	if(head==NULL)									//如果插入前，原始链表为空链表，就把首和尾指向要插入的这个元素
	{
		head=p;
		tail=p;
		p->next=NULL;
		num++;										//添加信息时将num的值+1
		sum+=p->Money;								//添加信息时将Money加到总金额中
		return;										//不可少“return;”!若少，则会弹出错误报告，程序无法在执行
	}
	if(head->PackageNum>p->PackageNum)				//插在链表首部（在链表首部的情况要特别考虑）
	{												
		p->next=head;
		head=p;
		num++;										//添加信息时num的值+1
		sum+=p->Money;								//添加信息时将Money加到总金额中
		return;										//不可少“return;”!若少，则会弹出错误报告，程序无法再执行
	}
	/***********上面是在链表头要插入的情况***********/
	/***********以下是在链表中间插入的情况***********/
	while(p2->next&&p2->PackageNum<p->PackageNum )	//查找待插入位置
	{
		p1=p2;
		p2=p2->next;
	}
	if(p2->PackageNum<p->PackageNum)				//插在链表尾部，这种情况也要单独讨论
	{
		p2->next=p;
		tail=p;
		p->next=NULL;
	}
	else											//插在链表中间，p2之前
	{
		p->next=p2;
		p1->next=p;
	}
	num++;
	sum+=p->Money;
}

Node* List::LookUp(string m)						//按手机号查找结点，返回该结点指针
{
	Node *p;
	p=head;
	while(p)										//以p是否为空进行循环
	{
		if(p->Shoujian_Phone==m)					//如果符合条件就返回这个节点
			return p;
		p=p->next;									//如果不符合就继续查找下一个节点
	}
	return NULL;
}

Node* List::LookUp(int num)							//按照运单号查找并返回节点
{
	Node *p;
	p=head;
	while(p)										//如果p不为空就进行循环
	{
		if(p->PackageNum==num)						//如果符合条件就返回这个节点
		{
			return p;
		}
		p=p->next;									//如果不符合就继续查找下一个节点
	}
	return NULL;
}

void List::Delete(string mobile)						//删除指定收件人电话的结点
{
	Node *p1,*p2,*p;
	if(head==NULL)										//如果原始链表为空链表
	{
		cout<<"链表为空，无结点可删！"<<endl;
	}
	if(head->Shoujian_Phone.compare(mobile)==0)			//首结点即为所要删除的结点，需要单独讨论
	{
		p=head;
		head=head->next;
		num--;
		sum-=p->Money;
		delete p;
	}
	else
	{
		p1=p2=head;
		while(p2!=NULL){
			while(p2&&p2->Shoujian_Phone.compare(mobile)!=0) //查找要删除的结点
			{
				p1=p2;
				p2=p2->next;
			}
			if(p2&&p2->Shoujian_Phone.compare(mobile)==0)	//找到要删除的结点,即p2
			{
				p1->next=p2->next;
				sum-=p2->Money;
				num--;
				delete p2;								//删除p2
				p2=p1->next;
			}
			else										//未找到要删除的结点
				cout<<mobile<<'\t'<<"链表上无此结点"<<endl;
		}
	}
}
void List::query_bymobile(string mobile,User *q)
{
	Node *p1,*p2,*p;
	q->showsheet();
	if(head==NULL)										//如果原始链表为空链表
	{
		cout<<"链表为空，无结点！"<<endl;
	}
	if(head->Shoujian_Phone.compare(mobile)==0)			//首结点即为所要删除的结点
	{
		q->show_Node(head);
	}
	else{
		p1=p2=head;
		while(p2!=NULL){
			while(p2&&p2->Shoujian_Phone.compare(mobile)!=0)//查找要删除的结点
			{
				p1=p2;
				p2=p2->next;
			}
			if(p2&&p2->Shoujian_Phone.compare(mobile)==0)	//找到要删除的结点,即p2
			{
				q->show_Node(p2);
				p2=p2->next;
			}
			else										//未找到要删除的结点
				cout<<mobile<<'\t'<<"链表上无此结点"<<endl;
		}
	}
}

void List::Delete(int num2)								//删除指定姓名的结点,这里应用多态性
{
	Node *p1,*p2,*p;
	if(head==NULL)										//如果原始链表为空链表
	{
		cout<<"链表为空，无结点可删！"<<endl;
	}
	if(head->PackageNum==num2)							//首结点即为所要删除的结点
	{
		p=head;
		head=head->next;
		num--;
		sum-=p->Money;
		delete p;
	}
	else
	{
		p1=p2=head;
		while(p2&&p2!=NULL&&p2->PackageNum!=num2)			//查找要删除的结点
		{
			p1=p2;
			p2=p2->next;
		}
		if(p2&&p2->PackageNum==num2)						//找到要删除的结点,即p2
		{
			p1->next=p2->next;
			sum-=p2->Money;
			num--;
			delete p2;									//删除p2
		}
		else											//未找到要删除的结点
			cout<<num<<'\t'<<"链表上无此结点"<<endl;
	}
}

void List::Show_Accountant()							//显示全部结点，每10个显示一屏   //这里还需要添加输出一些数据，有时间再弄
{
	int n=0;
	Node *p=head;
	if(p==NULL)											//原始链表为空链表
		cout<<"没有结点"<<endl;
	cout.setf(ios::left);
	cout<<setw(9)<<"运单号"<<setw(10)<<"收件人"<<setw(15)<<"收件人电话"<<setw(15)<<"寄件人电话"<<setw(10)<<"备注"<<setw(5)<<"运费"<<setw(8)<<"保价金额"<<endl;
	while(p)
	{
		
		cout.setf(ios::left);
		cout<<setw(9)<<(p->PackageNum)<<setw(10)<<(p->Shoujian_Name)<<setw(15)<<(p->Shoujian_Phone)<<setw(15)<<(p->Jijian_Phone)<<setw(10)<<(p->Note)<<setw(5)<<(p->Money)<<setw(8)<<(p->Baojia)<<endl;
		n++;
		if(n%10==0)
			system("pause");							//暂停执行程序，按任意键后继续执行（#include<stdlib.h>）
		p=p->next;
	}
	cout<<"运费总额"<<sum<<endl;
	cout<<"总件数"<<num<<endl;
}

void List::Show_User()									//显示全部结点，每10个显示一屏   //这里还需要添加输出一些数据，有时间再弄
{
	int n=0;
	Node *p=head;
	if(p==NULL)											//原始链表为空链表
		cout<<"没有结点"<<endl;
	cout.setf(ios::left);
	cout<<setw(9)<<"运单号"<<setw(10)<<"收件人"<<setw(15)<<"收件人电话"<<setw(15)<<"寄件人电话"<<setw(10)<<"备注"<<endl;
	while(p)
	{
		cout.setf(ios::left);
		cout<<setw(9)<<(p->PackageNum)<<setw(10)<<(p->Shoujian_Name)<<setw(15)<<(p->Shoujian_Phone)<<setw(15)<<(p->Jijian_Phone)<<setw(10)<<(p->Note)<<endl;
		n++;
		if(n%10==0)
			system("pause");							//暂停执行程序，按任意键后继续执行（#include<stdlib.h>）
		p=p->next;
	}
}

Node * List::Gethead()									//取首指针
{
	return head;
}

void List::CreateList(char *filenamein)					//从二进制文件中读入数据，构造链表
{
	int total,i;
	Node *p;
	fstream in(filenamein,ios::in|ios::binary);			//使用类的构造函数打开文件
	if(!in)
	{
		cout<<"文件无法打开"<<endl;
		return;											//文件不存在时，则返回，AddrList构造函数建立空链表（主函数中定义时自动调用），以等待用户输入数据
	}
	in>>total;
	for(i=0;i<total;i++)
	{
		p=new Node;
		in>>(p->PackageNum)>>(p->Shoujian_Name)>>(p->Shoujian_Phone)>>(p->Jijian_Phone)>>(p->Note)>>(p->Money)>>(p->Baojia);
		AddSort(p);										//调用AddSort函数（AddrList中），逐个插入节点
	}
	in.close();
}
void List::WriteToFile(char *filenameout)				//将链表中的数据写入指定的二进制文件
{
	Node *p;
	int total=0;										//total用来保存总的节点数
	fstream out(filenameout,ios::out|ios::binary);
	if(!out)
	{
		cout<<"文件无法写入!"<<endl;
		exit(1);
	}
	p=head;
	while(p)											//计算链表中非空结点数
	{
		total++;
		p=p->next;
	}
														//写入二进制文件
	out<<total<<endl;
	p=head;
	while(p)
	{
		out<<(p->PackageNum)<<'\t'<<(p->Shoujian_Name)<<'\t'<<(p->Shoujian_Phone)<<'\t'<<(p->Jijian_Phone)<<'\t'<<(p->Note)<<'\t'<<(p->Money)<<'\t'<<(p->Baojia)<<endl;
		p=p->next;
	}
	out.close();
}


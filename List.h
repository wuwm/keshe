#ifndef ADDRLIST_H
#define ADDRLIST_H
#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<iomanip>
#include<fstream>
#include"Node.h"
using namespace std;
#include<string>
#include"User.h"
class List						//链表类
{
private:
	Node *head;					//链表首指针
	Node *tail;					//链表尾指针
	static int num;
	static int sum;
public:
	List()						//缺省构造函数，创建空链表，将Tag的值置为1
	{
		head=NULL;	
		tail=NULL;
	}
	void Addtail(Node *p);		//将p指向的结点加入到链表尾部
	void AddSort(Node *p);		//将p指向的结点按Tag指定的顺序插入到链表中（均为升序）
	Node* LookUp(string);		//按姓名查找结点，返回该结点指针       (这里使用了多态性)
	Node* LookUp(int num);
	void Delete(int);			//删除指定姓名的结点
	void Delete(string);		//删除指定姓名的结点
	void Show_Accountant();		//显示全部结点，每10个显示一屏
	void Show_User();
	void query_bymobile(string,User *);
	Node *Gethead();			//取首指针
	~List()						//释放链表空间
	{
		Node *p;
		while(head)
		{
			p=head;
			head=head->next;
			delete p;
		}
	}
	void CreateList(char *filenamein);			//从二进制文件中读入数据，构造链表
	void WriteToFile(char *filenameout);		//将链表中的数据写入指定的二进制文件
	int static getNum();
	int static getSum();
};
#endif
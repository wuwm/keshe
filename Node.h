#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
class Node								//数据类
{

	int PackageNum;						//包裹编号
	string Shoujian_Name;				//收件人名称
	string Shoujian_Phone;				//收件人手机号码
	string Jijian_Phone;				//寄件人电话	
	int Money;							//价格
	int Baojia;							//保价金额
	string Home;						//始发地
	string Desti;						//目地地
	string Note;						//备注
	Node *next;							//下一结点指针
public:									//构造函数
	Node(){}
	void Show();						//显示结点数据
	void SetShoujian_Name(string);		//修改姓名
	void SetPackageNum(int);			//包裹名称电话
	void SetJijian_Phone(string);		//修改住宅电话
	void SetShoujian_Phone(string);		//修改手机号码
	void SetNote(string);				//修改备注
	void SetMoney(int);					//修改包裹价格	
	void SetBaojia(int);				//修改保价价格
	friend class List;					//将AddrList类说明为友元类
	friend class User;					//将User类说明为友元类
	friend class Accountant;			//将Accountant类说明为友元类
	friend ostream &operator <<(ostream &out,Node &b)  //重载“<<”运算符
	{
		out<<b.PackageNum<<'\t'<<b.Shoujian_Name<<'\t'<<b.Shoujian_Phone<<'\t'<<b.Jijian_Phone<<'\t'<<b.Note<<endl;
		return out;
	}
};
#endif
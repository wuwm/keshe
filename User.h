#ifndef User_H
#define User_H
#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<iomanip>
#include<fstream>
#include"List.h"
using namespace std;
class User{
protected:
	string username,password;						//普通用户的用户名和密码
public:
	User();											//User的构造函数
	virtual string Getusername();					//返回User的用户名
	virtual string Getpassword();					//返回User的密码
	void Setusername(string&user);					//设置User的用户名
	void SetPassword(string&pass);					//设置User的密码
	void Add(List &list);							//添加物流信息
	void User::Del(List &list,int num);				//按包裹号查找并删除
	void User::Del(List &list,string mobile);		//按收件人手机号查找并删除
	virtual void Show(List &list);					//按照User的权限显示全部链表
	void Look(List &list);							//在List中查找
	virtual void show_Node(Node *p);				//按User的权限显示一个Node节点
	void Addfromtxtfile(List &List);				//从文件中导入链表
	void Writetotxtfile(List &list);				//将链表内容写入文件
	void DeleteAll(List &list);						//删除全部链表
	virtual int Menu_Modify();						//按User的权限显示修改菜单
	virtual void edit();							//修改User的用户名和密码
	virtual void showsheet();						//按User的权限显示表单抬头
};
class Accountant:public User{
private:
	string uname,pass;								//Accountant类的用户名和密码
public:
	Accountant();									//Accountant类的构造函数
	virtual string Getusername();					//返回Accountant的用户名
	virtual string Getpassword();					//返回Accountant的密码
	virtual void Show(List &list);					//按Accountant显示全部链表
	virtual void show_Node(Node *p);				//按Accountant显示一个节点
	virtual int Menu_Modify();						//按Accountant的权限显示修改菜单
	virtual void edit();							//修改Accountant的用户名和密码
	virtual void showsheet();						//按Accountant的权限显示表格抬头
};
#endif
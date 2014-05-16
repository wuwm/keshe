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
	string username,password;						//��ͨ�û����û���������
public:
	User();											//User�Ĺ��캯��
	virtual string Getusername();					//����User���û���
	virtual string Getpassword();					//����User������
	void Setusername(string&user);					//����User���û���
	void SetPassword(string&pass);					//����User������
	void Add(List &list);							//���������Ϣ
	void User::Del(List &list,int num);				//�������Ų��Ҳ�ɾ��
	void User::Del(List &list,string mobile);		//���ռ����ֻ��Ų��Ҳ�ɾ��
	virtual void Show(List &list);					//����User��Ȩ����ʾȫ������
	void Look(List &list);							//��List�в���
	virtual void show_Node(Node *p);				//��User��Ȩ����ʾһ��Node�ڵ�
	void Addfromtxtfile(List &List);				//���ļ��е�������
	void Writetotxtfile(List &list);				//����������д���ļ�
	void DeleteAll(List &list);						//ɾ��ȫ������
	virtual int Menu_Modify();						//��User��Ȩ����ʾ�޸Ĳ˵�
	virtual void edit();							//�޸�User���û���������
	virtual void showsheet();						//��User��Ȩ����ʾ��̧ͷ
};
class Accountant:public User{
private:
	string uname,pass;								//Accountant����û���������
public:
	Accountant();									//Accountant��Ĺ��캯��
	virtual string Getusername();					//����Accountant���û���
	virtual string Getpassword();					//����Accountant������
	virtual void Show(List &list);					//��Accountant��ʾȫ������
	virtual void show_Node(Node *p);				//��Accountant��ʾһ���ڵ�
	virtual int Menu_Modify();						//��Accountant��Ȩ����ʾ�޸Ĳ˵�
	virtual void edit();							//�޸�Accountant���û���������
	virtual void showsheet();						//��Accountant��Ȩ����ʾ���̧ͷ
};
#endif
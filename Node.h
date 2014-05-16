#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
class Node								//������
{

	int PackageNum;						//�������
	string Shoujian_Name;				//�ռ�������
	string Shoujian_Phone;				//�ռ����ֻ�����
	string Jijian_Phone;				//�ļ��˵绰	
	int Money;							//�۸�
	int Baojia;							//���۽��
	string Home;						//ʼ����
	string Desti;						//Ŀ�ص�
	string Note;						//��ע
	Node *next;							//��һ���ָ��
public:									//���캯��
	Node(){}
	void Show();						//��ʾ�������
	void SetShoujian_Name(string);		//�޸�����
	void SetPackageNum(int);			//�������Ƶ绰
	void SetJijian_Phone(string);		//�޸�סլ�绰
	void SetShoujian_Phone(string);		//�޸��ֻ�����
	void SetNote(string);				//�޸ı�ע
	void SetMoney(int);					//�޸İ����۸�	
	void SetBaojia(int);				//�޸ı��ۼ۸�
	friend class List;					//��AddrList��˵��Ϊ��Ԫ��
	friend class User;					//��User��˵��Ϊ��Ԫ��
	friend class Accountant;			//��Accountant��˵��Ϊ��Ԫ��
	friend ostream &operator <<(ostream &out,Node &b)  //���ء�<<�������
	{
		out<<b.PackageNum<<'\t'<<b.Shoujian_Name<<'\t'<<b.Shoujian_Phone<<'\t'<<b.Jijian_Phone<<'\t'<<b.Note<<endl;
		return out;
	}
};
#endif
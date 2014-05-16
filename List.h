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
class List						//������
{
private:
	Node *head;					//������ָ��
	Node *tail;					//����βָ��
	static int num;
	static int sum;
public:
	List()						//ȱʡ���캯����������������Tag��ֵ��Ϊ1
	{
		head=NULL;	
		tail=NULL;
	}
	void Addtail(Node *p);		//��pָ��Ľ����뵽����β��
	void AddSort(Node *p);		//��pָ��Ľ�㰴Tagָ����˳����뵽�����У���Ϊ����
	Node* LookUp(string);		//���������ҽ�㣬���ظý��ָ��       (����ʹ���˶�̬��)
	Node* LookUp(int num);
	void Delete(int);			//ɾ��ָ�������Ľ��
	void Delete(string);		//ɾ��ָ�������Ľ��
	void Show_Accountant();		//��ʾȫ����㣬ÿ10����ʾһ��
	void Show_User();
	void query_bymobile(string,User *);
	Node *Gethead();			//ȡ��ָ��
	~List()						//�ͷ�����ռ�
	{
		Node *p;
		while(head)
		{
			p=head;
			head=head->next;
			delete p;
		}
	}
	void CreateList(char *filenamein);			//�Ӷ������ļ��ж������ݣ���������
	void WriteToFile(char *filenameout);		//�������е�����д��ָ���Ķ������ļ�
	int static getNum();
	int static getSum();
};
#endif
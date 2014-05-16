#include"List.h"
#include<iomanip>
using namespace std;
int List::sum=0;									//��ʼ����̬����sumΪ0
int List::num=0;									//��ʼ��num����Ϊ0
void List::Addtail(Node *p)							//��pָ��ġ���㡱���뵽����β��
{
	tail->next=p;
	p->next=NULL;
	tail=p;
	num++;
	sum+=p->Money;
}
void List::AddSort(Node *p)							//��pָ��Ľ�㰴�˵��ŵ�����˳����뵽������
{ 
	Node *p1,*p2=head;
	if(head==NULL)									//�������ǰ��ԭʼ����Ϊ�������Ͱ��׺�βָ��Ҫ��������Ԫ��
	{
		head=p;
		tail=p;
		p->next=NULL;
		num++;										//�����Ϣʱ��num��ֵ+1
		sum+=p->Money;								//�����Ϣʱ��Money�ӵ��ܽ����
		return;										//�����١�return;��!���٣���ᵯ�����󱨸棬�����޷���ִ��
	}
	if(head->PackageNum>p->PackageNum)				//���������ײ����������ײ������Ҫ�ر��ǣ�
	{												
		p->next=head;
		head=p;
		num++;										//�����Ϣʱnum��ֵ+1
		sum+=p->Money;								//�����Ϣʱ��Money�ӵ��ܽ����
		return;										//�����١�return;��!���٣���ᵯ�����󱨸棬�����޷���ִ��
	}
	/***********������������ͷҪ��������***********/
	/***********�������������м��������***********/
	while(p2->next&&p2->PackageNum<p->PackageNum )	//���Ҵ�����λ��
	{
		p1=p2;
		p2=p2->next;
	}
	if(p2->PackageNum<p->PackageNum)				//��������β�����������ҲҪ��������
	{
		p2->next=p;
		tail=p;
		p->next=NULL;
	}
	else											//���������м䣬p2֮ǰ
	{
		p->next=p2;
		p1->next=p;
	}
	num++;
	sum+=p->Money;
}

Node* List::LookUp(string m)						//���ֻ��Ų��ҽ�㣬���ظý��ָ��
{
	Node *p;
	p=head;
	while(p)										//��p�Ƿ�Ϊ�ս���ѭ��
	{
		if(p->Shoujian_Phone==m)					//������������ͷ�������ڵ�
			return p;
		p=p->next;									//��������Ͼͼ���������һ���ڵ�
	}
	return NULL;
}

Node* List::LookUp(int num)							//�����˵��Ų��Ҳ����ؽڵ�
{
	Node *p;
	p=head;
	while(p)										//���p��Ϊ�վͽ���ѭ��
	{
		if(p->PackageNum==num)						//������������ͷ�������ڵ�
		{
			return p;
		}
		p=p->next;									//��������Ͼͼ���������һ���ڵ�
	}
	return NULL;
}

void List::Delete(string mobile)						//ɾ��ָ���ռ��˵绰�Ľ��
{
	Node *p1,*p2,*p;
	if(head==NULL)										//���ԭʼ����Ϊ������
	{
		cout<<"����Ϊ�գ��޽���ɾ��"<<endl;
	}
	if(head->Shoujian_Phone.compare(mobile)==0)			//�׽�㼴Ϊ��Ҫɾ���Ľ�㣬��Ҫ��������
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
			while(p2&&p2->Shoujian_Phone.compare(mobile)!=0) //����Ҫɾ���Ľ��
			{
				p1=p2;
				p2=p2->next;
			}
			if(p2&&p2->Shoujian_Phone.compare(mobile)==0)	//�ҵ�Ҫɾ���Ľ��,��p2
			{
				p1->next=p2->next;
				sum-=p2->Money;
				num--;
				delete p2;								//ɾ��p2
				p2=p1->next;
			}
			else										//δ�ҵ�Ҫɾ���Ľ��
				cout<<mobile<<'\t'<<"�������޴˽��"<<endl;
		}
	}
}
void List::query_bymobile(string mobile,User *q)
{
	Node *p1,*p2,*p;
	q->showsheet();
	if(head==NULL)										//���ԭʼ����Ϊ������
	{
		cout<<"����Ϊ�գ��޽�㣡"<<endl;
	}
	if(head->Shoujian_Phone.compare(mobile)==0)			//�׽�㼴Ϊ��Ҫɾ���Ľ��
	{
		q->show_Node(head);
	}
	else{
		p1=p2=head;
		while(p2!=NULL){
			while(p2&&p2->Shoujian_Phone.compare(mobile)!=0)//����Ҫɾ���Ľ��
			{
				p1=p2;
				p2=p2->next;
			}
			if(p2&&p2->Shoujian_Phone.compare(mobile)==0)	//�ҵ�Ҫɾ���Ľ��,��p2
			{
				q->show_Node(p2);
				p2=p2->next;
			}
			else										//δ�ҵ�Ҫɾ���Ľ��
				cout<<mobile<<'\t'<<"�������޴˽��"<<endl;
		}
	}
}

void List::Delete(int num2)								//ɾ��ָ�������Ľ��,����Ӧ�ö�̬��
{
	Node *p1,*p2,*p;
	if(head==NULL)										//���ԭʼ����Ϊ������
	{
		cout<<"����Ϊ�գ��޽���ɾ��"<<endl;
	}
	if(head->PackageNum==num2)							//�׽�㼴Ϊ��Ҫɾ���Ľ��
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
		while(p2&&p2!=NULL&&p2->PackageNum!=num2)			//����Ҫɾ���Ľ��
		{
			p1=p2;
			p2=p2->next;
		}
		if(p2&&p2->PackageNum==num2)						//�ҵ�Ҫɾ���Ľ��,��p2
		{
			p1->next=p2->next;
			sum-=p2->Money;
			num--;
			delete p2;									//ɾ��p2
		}
		else											//δ�ҵ�Ҫɾ���Ľ��
			cout<<num<<'\t'<<"�������޴˽��"<<endl;
	}
}

void List::Show_Accountant()							//��ʾȫ����㣬ÿ10����ʾһ��   //���ﻹ��Ҫ������һЩ���ݣ���ʱ����Ū
{
	int n=0;
	Node *p=head;
	if(p==NULL)											//ԭʼ����Ϊ������
		cout<<"û�н��"<<endl;
	cout.setf(ios::left);
	cout<<setw(9)<<"�˵���"<<setw(10)<<"�ռ���"<<setw(15)<<"�ռ��˵绰"<<setw(15)<<"�ļ��˵绰"<<setw(10)<<"��ע"<<setw(5)<<"�˷�"<<setw(8)<<"���۽��"<<endl;
	while(p)
	{
		
		cout.setf(ios::left);
		cout<<setw(9)<<(p->PackageNum)<<setw(10)<<(p->Shoujian_Name)<<setw(15)<<(p->Shoujian_Phone)<<setw(15)<<(p->Jijian_Phone)<<setw(10)<<(p->Note)<<setw(5)<<(p->Money)<<setw(8)<<(p->Baojia)<<endl;
		n++;
		if(n%10==0)
			system("pause");							//��ִͣ�г��򣬰�����������ִ�У�#include<stdlib.h>��
		p=p->next;
	}
	cout<<"�˷��ܶ�"<<sum<<endl;
	cout<<"�ܼ���"<<num<<endl;
}

void List::Show_User()									//��ʾȫ����㣬ÿ10����ʾһ��   //���ﻹ��Ҫ������һЩ���ݣ���ʱ����Ū
{
	int n=0;
	Node *p=head;
	if(p==NULL)											//ԭʼ����Ϊ������
		cout<<"û�н��"<<endl;
	cout.setf(ios::left);
	cout<<setw(9)<<"�˵���"<<setw(10)<<"�ռ���"<<setw(15)<<"�ռ��˵绰"<<setw(15)<<"�ļ��˵绰"<<setw(10)<<"��ע"<<endl;
	while(p)
	{
		cout.setf(ios::left);
		cout<<setw(9)<<(p->PackageNum)<<setw(10)<<(p->Shoujian_Name)<<setw(15)<<(p->Shoujian_Phone)<<setw(15)<<(p->Jijian_Phone)<<setw(10)<<(p->Note)<<endl;
		n++;
		if(n%10==0)
			system("pause");							//��ִͣ�г��򣬰�����������ִ�У�#include<stdlib.h>��
		p=p->next;
	}
}

Node * List::Gethead()									//ȡ��ָ��
{
	return head;
}

void List::CreateList(char *filenamein)					//�Ӷ������ļ��ж������ݣ���������
{
	int total,i;
	Node *p;
	fstream in(filenamein,ios::in|ios::binary);			//ʹ����Ĺ��캯�����ļ�
	if(!in)
	{
		cout<<"�ļ��޷���"<<endl;
		return;											//�ļ�������ʱ���򷵻أ�AddrList���캯�������������������ж���ʱ�Զ����ã����Եȴ��û���������
	}
	in>>total;
	for(i=0;i<total;i++)
	{
		p=new Node;
		in>>(p->PackageNum)>>(p->Shoujian_Name)>>(p->Shoujian_Phone)>>(p->Jijian_Phone)>>(p->Note)>>(p->Money)>>(p->Baojia);
		AddSort(p);										//����AddSort������AddrList�У����������ڵ�
	}
	in.close();
}
void List::WriteToFile(char *filenameout)				//�������е�����д��ָ���Ķ������ļ�
{
	Node *p;
	int total=0;										//total���������ܵĽڵ���
	fstream out(filenameout,ios::out|ios::binary);
	if(!out)
	{
		cout<<"�ļ��޷�д��!"<<endl;
		exit(1);
	}
	p=head;
	while(p)											//���������зǿս����
	{
		total++;
		p=p->next;
	}
														//д��������ļ�
	out<<total<<endl;
	p=head;
	while(p)
	{
		out<<(p->PackageNum)<<'\t'<<(p->Shoujian_Name)<<'\t'<<(p->Shoujian_Phone)<<'\t'<<(p->Jijian_Phone)<<'\t'<<(p->Note)<<'\t'<<(p->Money)<<'\t'<<(p->Baojia)<<endl;
		p=p->next;
	}
	out.close();
}


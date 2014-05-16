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
struct MenuItem													//���˵��ṹ��
{	int no;
	char menuItemName[80];
};
MenuItem menuItems[10]={										//���˵�
	{1,"add Record(���Ӽ�¼)"},									//���Ӽ�¼
	{2,"delete Record(ɾ����¼)"},								//ɾ����¼
	{3,"display AllRecord(��ʾ���м�¼)"},						//��ʾ���м�¼
	{4,"Query(���Ҳ���ʾһ����¼)"},							//���������Ҳ���ʾһ����¼
	{5,"Modify Record(�޸�һ����¼)"},							//���������Ҳ��޸�һ����¼
	{6,"Add from a Text File(�������ļ�������ݵ����)"},		//�������ļ�������ݵ����
	{7,"write to a Text File(�����������д�������ļ�)"},		//�����������д�������ļ�
	{8,"Edit Uesername And Password(�޸��û���������)"},		//����
	{9,"delete AllRecord(ɾ��ȫ����¼)"},						//ɾ��ȫ����¼
	{0,"Quit(�˳�)"},											//�˳�
};
void displayMenu()
{
	for (int i=0; i<10; i++)									/*10�ɸĳ�11,��ʾ������ڡ�0.Quit(�˳�)�����һ�С�0.   ������Ӱ���������
																�����桰�Ӳ˵���������Ա�!!!!*/
	{
		cout<<"	"<<menuItems[i].no<<". "<<menuItems[i].menuItemName<<'\n'<<endl;
	}
}
int menu_select()
{  	char c;
	do
	{
		system("cls");												//����
        cout<<"================��������ϵͳ================"<<endl;
		cout<<endl;
		displayMenu();												//����displayMenu��������ʾ���˵�
		cout<<endl;
		cout<<"============================================"<<endl;
		cout<<"Input 1-9,0 to choice:"<<endl;
		cin>>c;
		cin.ignore(1024,'\n');
	}while(c<'0'||c>'9');											//ѭ��������'0'-'9'�ַ�������ַ���Ч����������
	return (c-'0');													//����0--9
}
int menu_look()														//�����˵��Ż����ֻ��Ų��� ѡ����Ӳ˵�
{
	
	char c;
	char *m[3]={"(1) LookUp By PackageNum(���˵���)",				//�޸�����
	"(2) LookUp By Mobilephone(���ռ��˵绰)",						//�޸İ칫�ҵ绰
	"(0) quit(�˳�)"};												//�˳�

	do{
		system("cls");												//����
		cout<<"===============Modify Record�Ӳ˵�==============="<<endl;
		cout<<endl;
		for(int i=0;i<3;i++)
		{															//��ʾ�Ӳ˵� 
			cout<<m[i]<<endl;
		}
		cout<<endl;
		cout<<"============================================"<<endl;
		cout<<"Input 1-2,0 to choice:";
		cin>>c;
		cin.ignore(1024,'\n');
	}while(c<'0'||c>'2');											//ѭ��������'0'-'2'�ַ�������ַ���Ч����������
	return (c-'0');													//����0--2
	

}

//==========================����Ϊ�޸ĺ���������=================================//

void ModifyName(List& list,Node *p,User *q)							//���������ң��޸�һ����¼��ֻ�޸���������������
{
	char c;
	string name;
	if(p==NULL)	
	{																//δ�ҵ�
		cout<<"û�д���"<<endl;	
	}
	else															//�ҵ�
	{
		q->show_Node(p);											//����show_Node��������ʾ�������
		cout<<"ȷ���޸�����?Y/N"<<endl;
		cin>>c;
		if(c=='Y'||c=='y')											//����Y(y),ȷ���޸�
		{
			cout<<"�������޸ĺ�����"<<endl;
			cin>>name;
			p->SetShoujian_Name(name);								//����SetShoujian_Name�������޸�����
			q->show_Node(p);										//����show_Node��������ʾ�������
		}
		else if(c=='N'||c=='n')										//����N(n),�˳��޸�
			return;
	}
}
void ModifyPackageNum(List& list,Node *p,User *q)					//���˵��Ų��ң��޸�һ����¼��ֻ�޸��ռ��˵绰����������
{
	char c;
	int num;
	if(p==NULL)														//δ�ҵ�
		cout<<"û�д��˵�"<<endl;
	else															//�ҵ�
	{
		q->show_Node(p);											//����show_Node��������ʾ�������
		cout<<"ȷ���޸�����?Y/N"<<endl;
		cin>>c;
		if(c=='Y'||c=='y')											//����Y(y),ȷ���޸�
		{
			cout<<"�������޸ĺ��˵���"<<endl;
			cin>>num;
			p->SetPackageNum(num);									//����setPackageNum�������޸İ칫�ҵ绰
			q->show_Node(p);										//����show_Node��������ʾ�������
	
		}
		else if(c=='N'||c=='n')										//����N(n),�˳��޸�
			return;
	}
}
void ModifyJijian_Phone(List&list,Node *p,User *q)					//���������ң��޸�һ����¼��ֻ�޸ļļ��˵绰����������	
{	
	char c;
	string hp;
	if(p==NULL)														//δ�ҵ�
		cout<<"û���˵�"<<endl;
	else															//�ҵ�
	{
		q->show_Node(p);											//����show_Node��������ʾ�������
		cout<<"ȷ���޸�?Y/N"<<endl;
		cin>>c;
		if(c=='Y'||c=='y')											//����Y(y),ȷ���޸�
		{
			cout<<"�������޸ĺ�ļ��˵绰"<<endl;
			cin>>hp;
			p->SetJijian_Phone(hp);									//����SetJijian_Phone�������޸��ռ��˵绰
			q->show_Node(p);										//����show_Node��������ʾ�������
			
		}
		else if(c=='N'||c=='n')										//����N(n),�˳��޸�
			return;	
	}
} 
void ModifyShoujian_Phone(List&list,Node *p,User *q)				//���������ң��޸�һ����¼��ֻ�޸��ռ����ֻ����벢��������	
{	
	char c;
	string mp;
	if(p==NULL)														//δ�ҵ�
		cout<<"û���˵�"<<endl;
	else															//�ҵ�
	{
		q->show_Node(p);											//����show_Node��������ʾ�������
		cout<<"ȷ���޸�?Y/N"<<endl;
		cin>>c;
		if(c=='Y'||c=='y')											//����Y(y),ȷ���޸�
		{
			cout<<"�������޸ĺ��ռ����ֻ�����"<<endl;
			cin>>mp;
			p->SetShoujian_Phone(mp);								//����SetShoujian_Phone�������޸��ֻ�����
			q->show_Node(p);										//����show_Node��������ʾ�������
	
		}
		else if(c=='N'||c=='n')										//����N(n),�˳��޸�
			return;
	}
}
void ModifyNote(List&list,Node *p,User *q)							//���������ң��޸�һ����¼��ֻ�޸�Note����������
{
	char c;
	string Note;
	if(p==NULL)														//δ�ҵ�
		cout<<"û���˵�"<<endl;
	else								 							//�ҵ�
	{
		q->show_Node(p);											//����show_Node��������ʾ�������
		cout<<"ȷ���޸�?Y/N"<<endl;
		cin>>c;
		if(c=='Y'||c=='y')											//����Y(y),ȷ���޸�
		{
			cout<<"�������޸ĺ�ı�ע"<<endl;
			cin>>Note;
			p->SetNote(Note);										//����setNote�������޸�Note
			q->show_Node(p);										//����show_Node��������ʾ�������
		
		}
		else if(c=='N'||c=='n')										//����N(n),�˳��޸�
			return;
	}
}

void ModifyMoney(List& list,Node *p,User *q)						//���˵��Ų��ң��޸�һ����¼��ֻ�޸��ռ��˵绰����������	
{
	char c;
	int num;
	if(p==NULL)														//δ�ҵ�
		cout<<"û�д��˵�"<<endl;
	else															//�ҵ�
	{
		q->show_Node(p);											//����show_Node��������ʾ�������
		cout<<"ȷ���޸�����?Y/N"<<endl;
		cin>>c;
		if(c=='Y'||c=='y')											//����Y(y),ȷ���޸�
		{
			cout<<"�������޸ĺ��˵���"<<endl;
			cin>>num;
			p->SetMoney(num);										//����SetMoney�������޸Ľ��
			q->show_Node(p);										//����show_Node��������ʾ�������
	
		}
		else if(c=='N'||c=='n')										//����N(n),�˳��޸�
			return;
	}
}
void ModifyBaojia(List& list,Node *p,User *q)						//���˵��Ų��ң��޸�һ����¼��ֻ�޸��ռ��˵绰����������	//55555555555
{
	char c;
	int num;
	if(p==NULL)														//δ�ҵ�
		cout<<"û�д��˵�"<<endl;
	else															//�ҵ�
	{
		q->show_Node(p);											//����show_Node��������ʾ�������
		cout<<"ȷ���޸�����?Y/N"<<endl;
		cin>>c;
		if(c=='Y'||c=='y')											//����Y(y),ȷ���޸�
		{
			cout<<"�������޸ĺ��˵���"<<endl;
			cin>>num;
			p->SetBaojia(num);										//����SetBaojia�������޸ı��۽��
			q->show_Node(p);										//����show��������ʾ�������
			
		}
		else if(c=='N'||c=='n')										//����N(n),�˳��޸�
			return;
	}
}
void ModifyByNum(List &list,User *q)								//���������Ҳ��޸�һ����¼
{
	Node *p;
	int num;
	cout<<"�������˵���"<<endl;
	cin>>num;
	cin.clear();
	cin.sync();
	if(p=list.LookUp(num)){
		switch(q->Menu_Modify())									//����menu��������ʾ�Ӳ˵�������ѡ��
		{
		case 1:ModifyPackageNum(list,p,q);							//�޸�����
			cout<<"��ִ��1.Modify PackageNum(�޸��˵���):"<<endl;
			
			break;
		case 2:ModifyName(list,p,q);								//�޸��˵�����
			cout<<"��ִ��2.Modify Name(�޸��ռ�������):"<<endl;
		
			break;
		case 3:ModifyShoujian_Phone(list,p,q);						//�޸ļļ��˵绰
			cout<<"��ִ��3.Modify MobilePhone(�޸��ռ����ֻ���):"<<endl;
			
			break;
		case 4:ModifyJijian_Phone(list,p,q);						//�޸��ռ��˵绰
			cout<<"��ִ��4.Modify Mobile Phone(�޸ļļ��˵绰):"<<endl;
			
			break;
		case 5:ModifyNote(list,p,q);								//�޸ı�ע
			cout<<"��ִ��7.Modify Note(�޸ı�ע):"<<endl;
			
			break;
		case 6:ModifyMoney(list,p,q);								//�޸��ʷ�
			cout<<"��ִ��8.Modify Money(�޸��ʷ�):"<<endl;
			
			break;
		case 7:ModifyBaojia(list,p,q);								//�޸ı��۷���
			cout<<"��ִ��9.Modify Baojia(�޸ı��۷���):"<<endl;
		
			break;
		case 0:														//�˳�
			
			return;
		}
	}
	else{
		cout<<"û�д��˵�"<<endl;
	}
}

void Modify(List &list,User *q)										//���˵��Ų��Ҳ��޸�һ����¼	
{	
	
	
	switch(1)														//����menu��������ʾ�Ӳ˵�������ѡ��
	{
	case 1:ModifyByNum(list,q);										//�����˵����޸�

		break;
	case 0:															//�˳�
		return;
	}
	
}


//========================================����Ϊ�޸ĺ���������================================================//

void query_mobile(List& list,User *q)								// ���������ҽ�㲢��ʾһ����¼     
{
	Node *p;
	string mobile;
	cout<<"������Ҫ���ҵ��ռ��˵绰"<<endl;
	cin>>mobile;
	list.query_bymobile(mobile,q);
	
}
void query_num(List& list,User *q)									// ���������ҽ�㲢��ʾһ����¼        
{
	Node *p;
	int num;
	cout<<"������Ҫ���ҵ��˵�����"<<endl;
	cin>>num;
	cin.clear();
	cin.sync();
	p=list.LookUp(num);												//����LookUp������AddrList�У������������ҽ�㣬���ظý��ָ��
	if(p==NULL)														//δ�ҵ�
		cout<<"û�д�����"<<endl;
	else
	{																//�ҵ�������show������Node�У�����ʾ�������
		q->showsheet();
		q->show_Node(p);
	}
}
void Look(List &list,User *q)										//������һ����¼,����ʾ����Ϣ	//44444444
{
	switch(menu_look())												//����menu��������ʾ�Ӳ˵�������ѡ��
	{
	case 1:query_num(list,q);										//���˵��Ų��Ҳ����ؽڵ��ָ��
		cout<<"��ִ��1.query_num(�����˵��Ų���):"<<endl;
		system("pause");
		break;
	case 2:query_mobile(list,q);									//���ռ��˵绰����
		cout<<"��ִ��2.query_mobile(�����ռ��˵绰����):"<<endl;
		system("pause");
		break;
	}
}

void del(List&list){
	int num;
	string mobile;
	switch(menu_look())												//����menu��������ʾ�Ӳ˵�������ѡ��
	{
	case 1:cout<<"�������˵��ţ�"<<endl;
		cin>>num;
		list.Delete(num);											//���˵��Ų��Ҳ�ɾ��

		break;
	case 2:cout<<"�������ֻ��ţ�"<<endl;
		cin>>mobile;
		list.Delete(mobile);										//���ռ����ֻ��Ų��Ҳ�ɾ��

		break; 
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                     �ƶ��ı�������                                              //
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
//                                     ��ʼ��������Ч                                   //
//////////////////////////////////////////////////////////////////////////////////////////
void logo()
{
	system("title ��������ϵͳ--���������...      by ��δ�� 161330119");
	system("cls");
    HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);					//��ȡ��׼����豸���
	string str1("������������������������������������������������������������������������������");
	string str2("��������                                                                    ��");
	string str3("������������������������������������������������������������������������������");	
	string str("===============================================================================");
	cout<<endl
		<<"�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��������ϵͳ�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n"//1
	    <<"�U                                                                          �U\n"//2 
		<<"�U                                                                          �U\n"//4
		<<"�U                         ���ܣߣߨq�q�q�q�q�ߣߣ���                       �U\n"//5
        <<"�U                         ��������������������������                       �U\n"//6
        <<"�U                         ��������������������������                       �U\n"//7                      
        <<"�U                         ��������������������������                       �U\n"//8
	    <<"�U                         ���ԡ���������������ԩ�                       �U\n"//9
        <<"�U                         ��������������������������                       �U\n"//10
        <<"�U                         �t�����УϨ������ϩЩ����s                       �U\n"//11
        <<"�U                  ��           �����������                             �U\n"//12
        <<"�U            ������             ���q�������r~~~~Hello!  (^_^)�ϡ�          �U\n"//13
        <<"�U                                                                          �U\n"//14
		<<"�U                                                                          �U\n"//15
		<<"�U                            ��ӭ������������ϵͳ!                         �U\n"//16
		<<"�U                                                                          �U\n"//3
		<<"�U                                              ���:   by      ��δ��      �U\n"//17
		<<"�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n";
	cerr<<"                             ���ݳ�ʼ���� Loading ... "<<endl;        
	cerr<<str1<<endl;
	cerr<<str2<<endl;
	cerr<<str3<<endl;
	int i = 3;												//ѭ������Ϊ2��
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
	list.WriteToFile("addrlist.dat");						//����WriteToFile������AddrList�У����������е�����д��ָ���Ķ������ļ�
	cerr<<"\n                                  �����˳�!"<<endl;                         
	cerr<<"                             ���ݱ����� saving ";        
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
	system("title ��������ϵͳ--������Ϣ��...      by ����");
	system("cls");
	cout<<endl
		<<" �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��������ϵͳ�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�["<<endl
		<<" �U                                                                          �U"<<endl
		<<" �U                                                                          �U"<<endl
		<<" �U                          ���ܣߣߨq�q�q�q�q�ߣߣ���                      �U"<<endl
		<<" �U                          ��������������������������                      �U"<<endl
		<<" �U                          ��������������������������                      �U"<<endl
		<<" �U                          ��������������������������                      �U"<<endl
		<<" �U                          ���ԡ���������������ԩ�                      �U"<<endl
		<<" �U                          ��������������������������                      �U"<<endl
		<<" �U                          �t�����УϨ������ϩЩ����s                      �U"<<endl
		<<" �U                                �����������                  ��~~~     �U"<<endl
		<<" �U                                ���q�������r ��л��ʹ��! (^_^)��          �U"<<endl
		<<" �U                                                                          �U"<<endl
		<<" �U                                                                          �U"<<endl
		<<" �U                                                                          �U"<<endl
		<<" �U                                               �ټ�!!                     �U"<<endl
		<<" �U                                                                          �U"<<endl
		<<" �U                                                   ���: by ��δ��        �U"<<endl
		<<" �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a"<<endl;
	super_end(list);
	
	exit(0);
};



#endif
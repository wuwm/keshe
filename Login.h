#include<stdlib.h>
//��½���������ض�Ӧ���û������ָ��
User* Login(User &user,Accountant &accountant)
{
	int tag;																			//tag�����洢�û������
	User *p;
	string name,pass;
	cout<<"�������û����1����ͨ�û���2��������Ա"<<endl;
	cin>>tag;
	while(1){
		if(tag==1)																		//��ͨ�û�tag��ֵΪ1
		{
			p=&user;
			cout<<"�������û��������룬�ÿո����"<<endl;
			cin>>name>>pass;
			if(name.compare(p->Getusername())==0&&pass.compare(p->Getpassword())==0)	//�ж��û��������������
				return p;
			else
			{
				system("cls");
				cout<<"�û����������������������,�ÿո����"<<endl;
			}		
		}
		else if(tag==2)																	//�����û���tagֵΪ2
		{
			p=&accountant;
			cout<<"�������û��������룬�ÿո����"<<endl;
			cin>>name>>pass;
			if(name.compare(p->Getusername())==0&&pass.compare(p->Getpassword())==0)	//�ж��û�������Ĥ������
				return p;
			else
			{
				system("cls");
				cout<<"�û������������,���������룬�ÿո����"<<endl;
			}
		}
		else
		{
			cout<<"�����ַ���ʽ�������������룺1��2"<<endl;							//�������ĸ�ʽ���󣬲��Ϸ�����Ҫ����������
			cin>>tag;
		}
	}
}
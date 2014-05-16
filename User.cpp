#include"User.h"
#include<stdlib.h>
User::User()												//User�Ĺ��캯��
{
	fstream Info("info.dat",ios::in);						//��������ʱ�Զ������û���������
	if(!Info)
	{
		cout<<"���û����ļ�ʧ��"<<endl;
	}
	Info>>username>>password;
	Info.close();
}
string User::Getusername()									//�����û���
{
	return username;
}
string User::Getpassword()									//��������
{
	return password;
}
void User::Setusername(string&user)							//�����û���
{
	username=user;
}
void User::SetPassword(string&pass)							//��������
{
	password=pass;
}
void User::Add(List &list)									//���������Ϣ�����е����쳣����
{
	Node *head,*p;
	string name,jijian_phone,Note,shoujian_phone;
	string num_t,money_t,baojia_t;							//"_t"��ʾ��ʱ����
	int num,money,baojia;
	int tag1=0,tag2=0,tag3=0,i;
	head=list.Gethead();									//����Gethead������AddrList�У���ȡ��ָ��
	p=new Node;
		cout<<"�������� �ռ������� �ռ��˵绰 �ļ��˵绰 ��ע �ʷ� ���۽��,�ո����"<<endl;
		cin>>num_t>>name>>shoujian_phone>>jijian_phone>>Note>>money_t>>baojia_t;
		cin.ignore(1024,'\n');								//�����������������ʱ���浽��ʱ������

/***********���µĴ��������ж�����������Ƿ�����������׳��쳣************/
		for(i=0;i<num_t.length();i++){
			if(num_t[i]<='9'&&num_t[i]>='0')
			{
			
			}
			else
			{
				tag1=1;	
			}
			
		}
		for(i=0;i<money_t.length();i++)
		{
			if(money_t[i]<='9'&&money_t[i]>='0')				//�ж������Ƿ�Ϸ�
			{
			
			}
			else
			{
				tag2=1;
			}
			
		}
		for(i=0;i<baojia_t.length();i++){
			if(baojia_t[i]<='9'&&baojia_t[i]>='0')				//�ж������Ƿ�Ϸ�
			{
			
			}
			else
			{
				tag3=1;
			}
			
		}
		
	if(tag1==1||tag2==1||tag3==1)
		throw "�˵��ţ��˷ѣ����۽����붼Ϊ���֣����������룺";		//������벻�����׳��쳣
/***********���ϵĴ��������ж�����������Ƿ�����������׳��쳣************/
	
	num=atoi(num_t.c_str());					//��������������֤Ϊ�����ʹ�stringת��Ϊint
	money=atoi(money_t.c_str());
	baojia=atoi(baojia_t.c_str());
	p->SetPackageNum(num);						//����SetPackageNum������Node�У����޸��˵�����
	p->SetShoujian_Name(name);					//����SetShoujian_Name������Node�У����޸��ռ�������
	p->SetShoujian_Phone(shoujian_phone);       //����SetShoujian_Phone������Node�У����޸ļļ��˵绰
	p->SetJijian_Phone(jijian_phone);           //����SetJijian_Phone������Node�У����޸��ռ��˺���
	p->SetNote(Note);							//����SetNote������Node�У����޸ı�ע
	p->SetMoney(money);							//����SetMoney������Node�У����޸ļ۸�
	p->SetBaojia(baojia);						//����SetBaojia������Node�У����޸ı��۽��
	list.AddSort(p);							//����AddSort������AddrList�У�����pָ��Ľ�㰴�����ŵ�˳����뵽������
}
void User::Del(List &list,int num)				//����List�еķ�������ɾ��
{
	list.Delete(num);
}
void User::Del(List &list,string mobile)		//����List�еķ�������ɾ��
{
	list.Delete(mobile);
}
void User::Show(List &list)						//����List�еķ���������ʾ
{
	list.Show_User();
}
void User::show_Node(Node *p)					//����List�еķ���������ʾ
{
	cout.setf(ios::left);
	cout<<setw(9)<<(p->PackageNum)<<setw(10)<<(p->Shoujian_Name)<<setw(15)<<(p->Shoujian_Phone)<<setw(15)<<(p->Jijian_Phone)<<setw(10)<<(p->Note)<<endl;
}

void Accountant::Show(List &list)
{
	list.Show_Accountant();
}
void Accountant::show_Node(Node *p)
{
	cout.setf(ios::left);
	cout<<setw(9)<<(p->PackageNum)<<setw(10)<<(p->Shoujian_Name)<<setw(15)<<(p->Shoujian_Phone)<<setw(15)<<(p->Jijian_Phone)<<setw(10)<<(p->Note)<<setw(5)<<(p->Money)<<setw(8)<<(p->Baojia)<<endl;
}
void User::Addfromtxtfile(List&list)			//�������ļ���������ݵ������		
{
	char name[30];
	cout<<"�����������ļ���"<<endl;
	cin>>name;
	list.CreateList(name);						//����CreateList������AddrList�У����������ļ��ж������ݣ���������
}
void User::Writetotxtfile(List&list)			//������е����ݵ����������ļ�		//7777777777777
{
	char name[30];
	cout<<"������д����ļ���"<<endl;
	cin>>name;
	list.WriteToFile(name);						//����WriteToFile������AddrList�У����������е�����д��ָ���������ļ�
}
void User::DeleteAll(List&list)					//ɾ��ȫ����¼
{
	list.~List();								//����~AddrList����������AddrList�У���ɾ��ȫ����¼
}
int User::Menu_Modify(){
	char c;
/*�˵�5.Modify Record���Ӳ˵���"""ָ������"""��ʽ����*/
	char *m[6]={"(1) Modify PackageNum(�޸��˵���)",			//�޸��˵���
				"(2) Modify Name(�޸��ռ�������)",				//�޸��ռ�������				
				"(3) Modify MobilePhone(�޸��ռ����ֻ���)",		//�޸��ռ����ֻ���
				"(4) Modify Mobile Phone(�޸ļļ��˵绰)",		//�޸ļļ��˵绰
				"(5) Modify Note(�޸ı�ע)",					//�޸ı�ע
				"(0) quit(�˳�)"};								//�˳�

	do{
		system("cls");											//����
		cout<<"===============Modify Record�Ӳ˵�==============="<<endl;
		cout<<endl;
		for(int i=0;i<6;i++)									//��ʾ�Ӳ˵� 
			cout<<m[i]<<endl;
		/*�ڴ�for����£����ɡ�6���ĳɡ�7�����򵯳����󱨸棬�����޷�ִ����ȥ��*/
		/*��	for(int i=0;m[i];i++)         //��ʾ�Ӳ˵� 
					cout<<m[i]<<endl;	
		��for����£�������6���������Ϊ��7�������򵯳����󱨸棬�����޷�ִ����ȥ��*/
		/*�����桰���˵�������Ա�*/
		cout<<endl;
		cout<<"============================================"<<endl;
		cout<<"Input 1-5,0 to choice:";
		cin>>c;
		cin.ignore(1024,'\n');
	}while(c<'0'||c>'5');										//ѭ��������'0'-'5'�ַ�������ַ���Ч����������
	return (c-'0');												//����0--5
}
Accountant::Accountant()										//Accountant�Ĺ��캯��
{
	fstream Info2("info2.dat",ios::in);							//���󴴽�ʱ�Զ������û���������
	if(!Info2)
	{
		cout<<"���û����ļ�ʧ��"<<endl;
	}
	Info2>>uname>>pass;
	Info2.close();
}
int Accountant::Menu_Modify()                                  //�˵�5.Modify Record���Ӳ˵�	//55555555555555
{	
	char c;
	/*�˵�5.Modify Record���Ӳ˵���"""ָ������"""��ʽ����*/
	char *m[8]={"(1) Modify PackageNum(�޸��˵���)",			//�޸��˵���
				"(2) Modify Name(�޸��ռ�������)",				//�޸��ռ�������
				"(3) Modify MobilePhone(�޸��ռ����ֻ���)",		//�޸��ռ����ֻ���
				"(4) Modify Mobile Phone(�޸ļļ��˵绰)",		//�޸ļļ��˵绰
				"(5) Modify Note(�޸ı�ע)",					//�޸ı�ע
				"(6) Modify Money(�޸��ʷ�)",					//�޸��ʷ�
				"(7) Modify Guarantee(�޸ı��۷���)",			//�޸ı�ע
				"(0) quit(�˳�)"};								//�˳�

	do{
		system("cls");											//����
		cout<<"===============Modify Record�Ӳ˵�==============="<<endl;
		cout<<endl;
		for(int i=0;i<8;i++)									//��ʾ�Ӳ˵� 
			cout<<m[i]<<endl;
		/*�ڴ�for����£����ɡ�7���ĳɡ�8�����򵯳����󱨸棬�����޷�ִ����ȥ��*/
		/*��	for(int i=0;m[i];i++)         //��ʾ�Ӳ˵� 
					cout<<m[i]<<endl;	
		��for����£�������7���������Ϊ��8�������򵯳����󱨸棬�����޷�ִ����ȥ��*/
		/*�����桰���˵�������Ա�*/
		cout<<endl;
		cout<<"============================================"<<endl;
		cout<<"Input 1-7,0 to choice:";
		cin>>c;
		cin.ignore(1024,'\n');
	}while(c<'0'||c>'7');										//ѭ��������'0'-'7'�ַ�������ַ���Ч����������
	return (c-'0');												//����0--7
}
string Accountant::Getusername()
{
	return uname;
}
string Accountant::Getpassword()
{
	return pass;
}
void User::edit()												//�޸�User����û���������
{
	string name,pass;
	cout<<"���������û��������룬�ÿո����"<<endl;
	cin>>name>>pass;
	fstream Info("info.dat",ios::out);							//���û����������ļ�׼�������޸�
	if(!Info)
	{
		cout<<"���û����ļ�ʧ��"<<endl;						
		exit(1);
	}
	Info<<name<<'\t'<<pass;
	Info.close();												//�ر��ļ�
}
void Accountant::edit(){										//�޸�User����û���������
	string name,pass;
	cout<<"���������û��������룬�ÿո����"<<endl;
	cin>>name>>pass;
	fstream Info2("info2.dat",ios::out);						//���û����������ļ�׼�������޸�
	if(!Info2){
		cout<<"���û����ļ�ʧ��"<<endl;
	}
	Info2<<name<<"\t"<<pass;
	Info2.close();												//�ر��ļ�
}

void User::showsheet(){
	cout.setf(ios::left);
	cout<<setw(9)<<"�˵���"<<setw(10)<<"�ռ���"<<setw(15)<<"�ռ��˵绰"<<setw(15)<<"�ļ��˵绰"<<setw(10)<<"��ע"<<endl;
	
}
void Accountant::showsheet(){
	cout.setf(ios::left);
	cout<<setw(9)<<"�˵���"<<setw(10)<<"�ռ���"<<setw(15)<<"�ռ��˵绰"<<setw(15)<<"�ļ��˵绰"<<setw(10)<<"��ע"<<setw(5)<<"�˷�"<<setw(8)<<"���۽��"<<endl;
	
}
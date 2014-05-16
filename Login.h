#include<stdlib.h>
//登陆函数，返回对应的用户对象的指针
User* Login(User &user,Accountant &accountant)
{
	int tag;																			//tag用来存储用户的类别
	User *p;
	string name,pass;
	cout<<"请输入用户类别：1，普通用户。2，财务人员"<<endl;
	cin>>tag;
	while(1){
		if(tag==1)																		//普通用户tag的值为1
		{
			p=&user;
			cout<<"请输入用户名和密码，用空格隔开"<<endl;
			cin>>name>>pass;
			if(name.compare(p->Getusername())==0&&pass.compare(p->Getpassword())==0)	//判断用户名和密码的正误
				return p;
			else
			{
				system("cls");
				cout<<"用户名或密码错误，请重新输入,用空格隔开"<<endl;
			}		
		}
		else if(tag==2)																	//财务用户的tag值为2
		{
			p=&accountant;
			cout<<"请输入用户名和密码，用空格隔开"<<endl;
			cin>>name>>pass;
			if(name.compare(p->Getusername())==0&&pass.compare(p->Getpassword())==0)	//判断用户名和面膜的正误
				return p;
			else
			{
				system("cls");
				cout<<"用户名或密码错误,请重新输入，用空格隔开"<<endl;
			}
		}
		else
		{
			cout<<"输入字符格式错误，请重新输入：1或2"<<endl;							//如果输入的格式错误，不合法，会要求重新输入
			cin>>tag;
		}
	}
}
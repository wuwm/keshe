#include"User.h"
#include<stdlib.h>
User::User()												//User的构造函数
{
	fstream Info("info.dat",ios::in);						//创建对象时自动读入用户名和密码
	if(!Info)
	{
		cout<<"打开用户名文件失败"<<endl;
	}
	Info>>username>>password;
	Info.close();
}
string User::Getusername()									//返回用户名
{
	return username;
}
string User::Getpassword()									//返回密码
{
	return password;
}
void User::Setusername(string&user)							//设置用户名
{
	username=user;
}
void User::SetPassword(string&pass)							//设置密码
{
	password=pass;
}
void User::Add(List &list)									//添加物流信息，其中调用异常处理
{
	Node *head,*p;
	string name,jijian_phone,Note,shoujian_phone;
	string num_t,money_t,baojia_t;							//"_t"表示临时变量
	int num,money,baojia;
	int tag1=0,tag2=0,tag3=0,i;
	head=list.Gethead();									//调用Gethead函数（AddrList中），取首指针
	p=new Node;
		cout<<"包裹单号 收件人名称 收件人电话 寄件人电话 备注 邮费 保价金额,空格隔开"<<endl;
		cin>>num_t>>name>>shoujian_phone>>jijian_phone>>Note>>money_t>>baojia_t;
		cin.ignore(1024,'\n');								//将键盘输入的数据暂时保存到临时变量中

/***********以下的代码用来判断输入的数据是否合理，不合理将抛出异常************/
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
			if(money_t[i]<='9'&&money_t[i]>='0')				//判断输入是否合法
			{
			
			}
			else
			{
				tag2=1;
			}
			
		}
		for(i=0;i<baojia_t.length();i++){
			if(baojia_t[i]<='9'&&baojia_t[i]>='0')				//判断输入是否合法
			{
			
			}
			else
			{
				tag3=1;
			}
			
		}
		
	if(tag1==1||tag2==1||tag3==1)
		throw "运单号，运费，保价金额必须都为数字！请重新输入：";		//如果输入不合理将抛出异常
/***********以上的代码用来判断输入的数据是否合理，不合理将抛出异常************/
	
	num=atoi(num_t.c_str());					//如果输入的输入验证为合理，就从string转换为int
	money=atoi(money_t.c_str());
	baojia=atoi(baojia_t.c_str());
	p->SetPackageNum(num);						//调用SetPackageNum函数（Node中），修改运单号码
	p->SetShoujian_Name(name);					//调用SetShoujian_Name函数（Node中），修改收件人姓名
	p->SetShoujian_Phone(shoujian_phone);       //调用SetShoujian_Phone函数（Node中），修改寄件人电话
	p->SetJijian_Phone(jijian_phone);           //调用SetJijian_Phone函数（Node中），修改收件人号码
	p->SetNote(Note);							//调用SetNote函数（Node中），修改备注
	p->SetMoney(money);							//调用SetMoney函数（Node中），修改价格
	p->SetBaojia(baojia);						//调用SetBaojia函数（Node中），修改保价金额
	list.AddSort(p);							//调用AddSort函数（AddrList中），将p指向的结点按包裹号的顺序插入到链表中
}
void User::Del(List &list,int num)				//调用List中的方法进行删除
{
	list.Delete(num);
}
void User::Del(List &list,string mobile)		//调用List中的方法进行删除
{
	list.Delete(mobile);
}
void User::Show(List &list)						//调用List中的方法进行显示
{
	list.Show_User();
}
void User::show_Node(Node *p)					//调用List中的方法进行显示
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
void User::Addfromtxtfile(List&list)			//从正文文件中添加数据到库表中		
{
	char name[30];
	cout<<"请输入读入的文件名"<<endl;
	cin>>name;
	list.CreateList(name);						//调用CreateList函数（AddrList中），从正文文件中读出数据，构造链表
}
void User::Writetotxtfile(List&list)			//将库表中的数据导出到正文文件		//7777777777777
{
	char name[30];
	cout<<"请输入写入的文件名"<<endl;
	cin>>name;
	list.WriteToFile(name);						//调用WriteToFile函数（AddrList中），将链表中的数据写入指定的正文文件
}
void User::DeleteAll(List&list)					//删除全部记录
{
	list.~List();								//调用~AddrList析构函数（AddrList中），删除全部记录
}
int User::Menu_Modify(){
	char c;
/*菜单5.Modify Record的子菜单用"""指针数组"""形式给出*/
	char *m[6]={"(1) Modify PackageNum(修改运单号)",			//修改运单号
				"(2) Modify Name(修改收件人姓名)",				//修改收件人姓名				
				"(3) Modify MobilePhone(修改收件人手机号)",		//修改收件人手机号
				"(4) Modify Mobile Phone(修改寄件人电话)",		//修改寄件人电话
				"(5) Modify Note(修改备注)",					//修改备注
				"(0) quit(退出)"};								//退出

	do{
		system("cls");											//清屏
		cout<<"===============Modify Record子菜单==============="<<endl;
		cout<<endl;
		for(int i=0;i<6;i++)									//显示子菜单 
			cout<<m[i]<<endl;
		/*在此for语句下，若吧“6”改成“7”，则弹出错误报告，程序无法执行下去。*/
		/*在	for(int i=0;m[i];i++)         //显示子菜单 
					cout<<m[i]<<endl;	
		此for语句下，两个“6”必须均改为“7”，否则弹出错误报告，程序无法执行下去。*/
		/*与上面“主菜单”情况对比*/
		cout<<endl;
		cout<<"============================================"<<endl;
		cout<<"Input 1-5,0 to choice:";
		cin>>c;
		cin.ignore(1024,'\n');
	}while(c<'0'||c>'5');										//循环，输入'0'-'5'字符以外的字符无效，重新输入
	return (c-'0');												//返回0--5
}
Accountant::Accountant()										//Accountant的构造函数
{
	fstream Info2("info2.dat",ios::in);							//对象创建时自动读入用户名和密码
	if(!Info2)
	{
		cout<<"打开用户名文件失败"<<endl;
	}
	Info2>>uname>>pass;
	Info2.close();
}
int Accountant::Menu_Modify()                                  //菜单5.Modify Record的子菜单	//55555555555555
{	
	char c;
	/*菜单5.Modify Record的子菜单用"""指针数组"""形式给出*/
	char *m[8]={"(1) Modify PackageNum(修改运单号)",			//修改运单号
				"(2) Modify Name(修改收件人姓名)",				//修改收件人姓名
				"(3) Modify MobilePhone(修改收件人手机号)",		//修改收件人手机号
				"(4) Modify Mobile Phone(修改寄件人电话)",		//修改寄件人电话
				"(5) Modify Note(修改备注)",					//修改备注
				"(6) Modify Money(修改邮费)",					//修改邮费
				"(7) Modify Guarantee(修改保价费用)",			//修改备注
				"(0) quit(退出)"};								//退出

	do{
		system("cls");											//清屏
		cout<<"===============Modify Record子菜单==============="<<endl;
		cout<<endl;
		for(int i=0;i<8;i++)									//显示子菜单 
			cout<<m[i]<<endl;
		/*在此for语句下，若吧“7”改成“8”，则弹出错误报告，程序无法执行下去。*/
		/*在	for(int i=0;m[i];i++)         //显示子菜单 
					cout<<m[i]<<endl;	
		此for语句下，两个“7”必须均改为“8”，否则弹出错误报告，程序无法执行下去。*/
		/*与上面“主菜单”情况对比*/
		cout<<endl;
		cout<<"============================================"<<endl;
		cout<<"Input 1-7,0 to choice:";
		cin>>c;
		cin.ignore(1024,'\n');
	}while(c<'0'||c>'7');										//循环，输入'0'-'7'字符以外的字符无效，重新输入
	return (c-'0');												//返回0--7
}
string Accountant::Getusername()
{
	return uname;
}
string Accountant::Getpassword()
{
	return pass;
}
void User::edit()												//修改User类的用户名和密码
{
	string name,pass;
	cout<<"请输入新用户名和密码，用空格隔开"<<endl;
	cin>>name>>pass;
	fstream Info("info.dat",ios::out);							//打开用户名和密码文件准备进行修改
	if(!Info)
	{
		cout<<"打开用户名文件失败"<<endl;						
		exit(1);
	}
	Info<<name<<'\t'<<pass;
	Info.close();												//关闭文件
}
void Accountant::edit(){										//修改User类的用户名和密码
	string name,pass;
	cout<<"请输入新用户名和密码，用空格隔开"<<endl;
	cin>>name>>pass;
	fstream Info2("info2.dat",ios::out);						//打开用户名和密码文件准备进行修改
	if(!Info2){
		cout<<"打开用户名文件失败"<<endl;
	}
	Info2<<name<<"\t"<<pass;
	Info2.close();												//关闭文件
}

void User::showsheet(){
	cout.setf(ios::left);
	cout<<setw(9)<<"运单号"<<setw(10)<<"收件人"<<setw(15)<<"收件人电话"<<setw(15)<<"寄件人电话"<<setw(10)<<"备注"<<endl;
	
}
void Accountant::showsheet(){
	cout.setf(ios::left);
	cout<<setw(9)<<"运单号"<<setw(10)<<"收件人"<<setw(15)<<"收件人电话"<<setw(15)<<"寄件人电话"<<setw(10)<<"备注"<<setw(5)<<"运费"<<setw(8)<<"保价金额"<<endl;
	
}
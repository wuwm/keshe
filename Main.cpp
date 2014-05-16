#include"menu.h"
#include"Login.h"
void main(){
	system("@mode con: lines=25");						//设置一页的行数
	system("@color 3f");								//背景淡蓝色，字体白色
	system("title  物流信息管理系统   by 吴未名 161330119");
	logo();
	system("title  物流信息管理系统   by 吴未名 161330119");
	system("cls");
	int tag=1;											//tag用来记录输入是否合法的状态
	List list;											//定义一个链表类对象
	list.CreateList("addrlist.dat");					//调用CreateList函数（AddrList中），从二进制文件中读入数据，构造链表
	User user;
	Accountant accountant;
	User *p=Login(user,accountant);
	while(1)
	{
		switch(menu_select())							//调用menu_select函数，显示主菜单并给出选择
		{
		case 1:
		tag=1;
		while(tag)										//用tag来判断输入是否合法
		{
			tag=0;
			try											//这里调用异常来处理可能发生的输入格式错误
			{
				p->Add(list);							//增加记录
			}catch(char *exceptionString)
			{
				cout<<exceptionString<<endl;			//如果有异常就显示异常信息
				tag=1;									//改变tag的状态
			}
		}
			cout<<"已执行1.add Record(增加记录)"<<endl;
			system("pause");
			break;
		
		case 2:del(list);						        //删除记录
			cout<<"已执行2.delete Record(删除记录)"<<endl;
			system("pause");
			break;
		case 3:p->Show(list);							//显示所有记录
			cout<<"已执行3.Display AllRecord(显示所有记录)"<<endl;
			system("pause");
			break;
		case 4:Look(list,p);							//按查找并显示一个记录
			break;
		case 5:Modify(list,p);							//按姓名查找并修改一个记录//menu函数中有“清屏”//包含子菜单
			cout<<"已执行5.Modify Record(按姓名查找并修改一个记录)"<<endl;
			system("pause");
			break;   
		case 6:p->Addfromtxtfile(list);					//从正文文件添加数据到库表
			cout<<"已执行6.Add from a Text File(从正文文件添加数据到库表)"<<endl;
			system("pause");
			break;
		case 7:p->Writetotxtfile(list);					//将库表中数据写入正文文件
			cout<<"已执行7.write to a Text File(将库表中数据写入正文文件)"<<endl;
			system("pause");
			break;  
		case 8:p->edit();
			cout<<"已执行8.Edit Uesername And Password(修改用户名和密码)"<<endl;
			system("pause");
			break;
		case 9:p->DeleteAll(list);						//删除全部记录
			cout<<"已执行9.Delete All(删除全部记录)"<<endl;
			system("pause");
			break;	
		case 0:quit(list);								//退出
			cout<<"已执行0.Quit(退出)"<<endl;
			system("pause");
			exit(0);									//退出控制台
		}
	}
}
int menu_look()                                  //按照运单号还是手机号查找 选择的子菜单	//55555555555555
{	char c;
	/*菜单5.Modify Record的子菜单用"""指针数组"""形式给出!!!!!*/
	char *m[3]={"(1) LookUp By PackageNum(修改姓名)",	//修改姓名
	"(2) LookUp By Mobilephone(修改办公室电话)",	//修改办公室电话
	"(0) quit(退出)"};	//退出

	do{
		system("cls");                   //清屏
		cout<<"===============Modify Record子菜单==============="<<endl;
		cout<<endl;
		for(int i=0;i<3;i++)                   //显示子菜单 
			cout<<m[i]<<endl;
		/*在此for语句下，若吧“6”改成“7”，则弹出错误报告，程序无法执行下去。*/
		/*在	for(int i=0;m[i];i++)         //显示子菜单 
					cout<<m[i]<<endl;	
		此for语句下，两个“6”必须均改为“7”，否则弹出错误报告，程序无法执行下去。*/
		/*与上面“主菜单”情况对比*/
		cout<<endl;
		cout<<"============================================"<<endl;
		cout<<"Input 1-2,0 to choice:";
		cin>>c;
	}while(c<'0'||c>'2');	//	//循环，输入'0'-'2'字符以外的字符无效，重新输入
	return (c-'0');	//返回0--2
}


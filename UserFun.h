int menu_look()                                  //�����˵��Ż����ֻ��Ų��� ѡ����Ӳ˵�	//55555555555555
{	char c;
	/*�˵�5.Modify Record���Ӳ˵���"""ָ������"""��ʽ����!!!!!*/
	char *m[3]={"(1) LookUp By PackageNum(�޸�����)",	//�޸�����
	"(2) LookUp By Mobilephone(�޸İ칫�ҵ绰)",	//�޸İ칫�ҵ绰
	"(0) quit(�˳�)"};	//�˳�

	do{
		system("cls");                   //����
		cout<<"===============Modify Record�Ӳ˵�==============="<<endl;
		cout<<endl;
		for(int i=0;i<3;i++)                   //��ʾ�Ӳ˵� 
			cout<<m[i]<<endl;
		/*�ڴ�for����£����ɡ�6���ĳɡ�7�����򵯳����󱨸棬�����޷�ִ����ȥ��*/
		/*��	for(int i=0;m[i];i++)         //��ʾ�Ӳ˵� 
					cout<<m[i]<<endl;	
		��for����£�������6���������Ϊ��7�������򵯳����󱨸棬�����޷�ִ����ȥ��*/
		/*�����桰���˵�������Ա�*/
		cout<<endl;
		cout<<"============================================"<<endl;
		cout<<"Input 1-2,0 to choice:";
		cin>>c;
	}while(c<'0'||c>'2');	//	//ѭ��������'0'-'2'�ַ�������ַ���Ч����������
	return (c-'0');	//����0--2
}

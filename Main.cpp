#include"menu.h"
#include"Login.h"
void main(){
	system("@mode con: lines=25");						//����һҳ������
	system("@color 3f");								//��������ɫ�������ɫ
	system("title  ������Ϣ����ϵͳ   by ��δ�� 161330119");
	logo();
	system("title  ������Ϣ����ϵͳ   by ��δ�� 161330119");
	system("cls");
	int tag=1;											//tag������¼�����Ƿ�Ϸ���״̬
	List list;											//����һ�����������
	list.CreateList("addrlist.dat");					//����CreateList������AddrList�У����Ӷ������ļ��ж������ݣ���������
	User user;
	Accountant accountant;
	User *p=Login(user,accountant);
	while(1)
	{
		switch(menu_select())							//����menu_select��������ʾ���˵�������ѡ��
		{
		case 1:
		tag=1;
		while(tag)										//��tag���ж������Ƿ�Ϸ�
		{
			tag=0;
			try											//��������쳣��������ܷ����������ʽ����
			{
				p->Add(list);							//���Ӽ�¼
			}catch(char *exceptionString)
			{
				cout<<exceptionString<<endl;			//������쳣����ʾ�쳣��Ϣ
				tag=1;									//�ı�tag��״̬
			}
		}
			cout<<"��ִ��1.add Record(���Ӽ�¼)"<<endl;
			system("pause");
			break;
		
		case 2:del(list);						        //ɾ����¼
			cout<<"��ִ��2.delete Record(ɾ����¼)"<<endl;
			system("pause");
			break;
		case 3:p->Show(list);							//��ʾ���м�¼
			cout<<"��ִ��3.Display AllRecord(��ʾ���м�¼)"<<endl;
			system("pause");
			break;
		case 4:Look(list,p);							//�����Ҳ���ʾһ����¼
			break;
		case 5:Modify(list,p);							//���������Ҳ��޸�һ����¼//menu�������С�������//�����Ӳ˵�
			cout<<"��ִ��5.Modify Record(���������Ҳ��޸�һ����¼)"<<endl;
			system("pause");
			break;   
		case 6:p->Addfromtxtfile(list);					//�������ļ�������ݵ����
			cout<<"��ִ��6.Add from a Text File(�������ļ�������ݵ����)"<<endl;
			system("pause");
			break;
		case 7:p->Writetotxtfile(list);					//�����������д�������ļ�
			cout<<"��ִ��7.write to a Text File(�����������д�������ļ�)"<<endl;
			system("pause");
			break;  
		case 8:p->edit();
			cout<<"��ִ��8.Edit Uesername And Password(�޸��û���������)"<<endl;
			system("pause");
			break;
		case 9:p->DeleteAll(list);						//ɾ��ȫ����¼
			cout<<"��ִ��9.Delete All(ɾ��ȫ����¼)"<<endl;
			system("pause");
			break;	
		case 0:quit(list);								//�˳�
			cout<<"��ִ��0.Quit(�˳�)"<<endl;
			system("pause");
			exit(0);									//�˳�����̨
		}
	}
}
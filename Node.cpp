#include"Node.h"
void Node::Show()							//��ʾ������ݣ���this����ڵ������
{
	cout<<this;
}
void Node::SetShoujian_Name(string name)	//�޸��ռ�������
{
	Shoujian_Name=name;
}
void Node::SetPackageNum(int o)				//�޸İ칫�ҵ绰
{
	PackageNum=o;
}
void Node::SetJijian_Phone(string p)		//�޸�סլ�绰
{
	Jijian_Phone=p;
}
void Node::SetShoujian_Phone(string m)		//�޸��ֻ�����
{
	Shoujian_Phone=m;
}
void Node::SetNote(string s)				//�޸ı�ע
{
	Note=s;
}
void Node::SetMoney(int m)					//���ð����۸�
{
	Money=m;
}
void Node::SetBaojia(int m)					//���ñ��۽��
{
	Baojia=m;
}

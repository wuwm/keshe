#include"Node.h"
void Node::Show()							//显示结点数据，即this对象节点的数据
{
	cout<<this;
}
void Node::SetShoujian_Name(string name)	//修改收件人姓名
{
	Shoujian_Name=name;
}
void Node::SetPackageNum(int o)				//修改办公室电话
{
	PackageNum=o;
}
void Node::SetJijian_Phone(string p)		//修改住宅电话
{
	Jijian_Phone=p;
}
void Node::SetShoujian_Phone(string m)		//修改手机号码
{
	Shoujian_Phone=m;
}
void Node::SetNote(string s)				//修改备注
{
	Note=s;
}
void Node::SetMoney(int m)					//设置包裹价格
{
	Money=m;
}
void Node::SetBaojia(int m)					//设置保价金额
{
	Baojia=m;
}

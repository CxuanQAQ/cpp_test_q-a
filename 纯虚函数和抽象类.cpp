#include<iostream>
#include<string>
using namespace std;
class Base
{
	//ֻҪ��һ�����麯����������Ϊ������
	//�ص㣺
	//1.�޷�ʵ��������  eg��Base b;  error
	//2.����������࣬����Ҫ��д�����еĴ��麯��������Ҳ���ڳ�����
	//
	public:
	virtual void func()=0;
	

};

class son:public Base
{
	virtual void func()
	{cout<<"func������"<<endl;};
};
void test1()
{
	//Base a;�������޷�ʵ��������
	//new Base;�������޷�ʵ��������
//	son s(��);//���������д�����еĴ��麯���������޷�ʵ��������
	Base *base=new son;
	base->func();
	delete base;

}
int main()
{
	test1();
}

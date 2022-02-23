#include<iostream>
#include<string>
using namespace std;
class Base
{
	//只要有一个纯虚函数，这个类称为抽象类
	//特点：
	//1.无法实例化对象  eg：Base b;  error
	//2.抽象类的子类，必须要重写父类中的纯虚函数，否则也属于抽象类
	//
	public:
	virtual void func()=0;
	

};

class son:public Base
{
	virtual void func()
	{cout<<"func被调用"<<endl;};
};
void test1()
{
	//Base a;抽象类无法实例化对象
	//new Base;抽象类无法实例化对象
//	son s(√);//子类必须重写父类中的纯虚函数，否则无法实例化对象
	Base *base=new son;
	base->func();
	delete base;

}
int main()
{
	test1();
}

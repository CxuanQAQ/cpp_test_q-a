#include<iostream>
#include<string>
using namespace std;

//普通写法
class Calcuator
{
	public:
		int m_Num1;
		int m_Num2;
	int getresult(string str)
	{
		if(str=="+")
		{
			return m_Num1+m_Num2;	//TODO
		}
		if(str=="-"){
			return m_Num1-m_Num2;//TODO
		}
		if(str=="*"){
			return m_Num1*m_Num2;//TODO
		}
	}	
};

void test1()
{
		Calcuator c1;
		c1.m_Num1=10;
		c1.m_Num2=20;
		cout<<c1.m_Num1<<"+"<<c1.m_Num2<<"="<<c1.getresult("+");
		cout<<c1.m_Num1<<"-"<<c1.m_Num2<<"="<<c1.getresult("-");	
		cout<<c1.m_Num1<<"*"<<c1.m_Num2<<"="<<c1.getresult("*");
		
}



//利用多态实现
//实现计算器抽象类
class AbstractCalculator
{
	public:
		int m_Num1;
		int m_Num2;
		virtual int getresult()
		{
			return 0;
		}
		

};
class add:public AbstractCalculator
{
	public:
		int getresult()
		{
			return m_Num1+m_Num2;
		}
		
};
class sub:public AbstractCalculator
{
	public:
		int getresult()
		{
			return m_Num1-m_Num2;
		}
};
class mul:public AbstractCalculator
{
	public:
		int getresult()
		{
			return m_Num1*m_Num2;
		}
};

void test2()
{
	//多态使用条件
	//父类指针或者引用指向子类对象
	
	AbstractCalculator *abc= new add;
	abc->m_Num1=10;
	abc->m_Num2=20;
	cout<<"多态"<<abc->m_Num1<<"+"<<abc->m_Num2<<"="<<abc->getresult()<<endl;
	delete abc;
	abc=new sub;
	abc->m_Num1=30;
	abc->m_Num2=20;
	cout<<"多态"<<abc->m_Num1<<"-"<<abc->m_Num2<<"="<<abc->getresult()<<endl;
	delete abc;
	abc=new mul;
	abc->m_Num1=30;
	abc->m_Num2=20;
	cout<<"多态"<<abc->m_Num1<<"*"<<abc->m_Num2<<"="<<abc->getresult()<<endl;
	delete abc;	
}
int main()

{
	//test1();
	test2();
}

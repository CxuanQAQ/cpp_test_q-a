#include<iostream>
#include<string>
using namespace std;

//��ͨд��
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



//���ö�̬ʵ��
//ʵ�ּ�����������
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
	//��̬ʹ������
	//����ָ���������ָ���������
	
	AbstractCalculator *abc= new add;
	abc->m_Num1=10;
	abc->m_Num2=20;
	cout<<"��̬"<<abc->m_Num1<<"+"<<abc->m_Num2<<"="<<abc->getresult()<<endl;
	delete abc;
	abc=new sub;
	abc->m_Num1=30;
	abc->m_Num2=20;
	cout<<"��̬"<<abc->m_Num1<<"-"<<abc->m_Num2<<"="<<abc->getresult()<<endl;
	delete abc;
	abc=new mul;
	abc->m_Num1=30;
	abc->m_Num2=20;
	cout<<"��̬"<<abc->m_Num1<<"*"<<abc->m_Num2<<"="<<abc->getresult()<<endl;
	delete abc;	
}
int main()

{
	//test1();
	test2();
}

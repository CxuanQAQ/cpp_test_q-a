#include<iostream>
#include<string>
using namespace std;

class Drink
{
	public:
	virtual void zhu()=0;
	virtual void dao()=0;
	virtual void chong()=0;
	virtual void add()=0;
	void domake()
	{
	zhu();
	chong();
	dao();
	add();
		
	}
	
};
class Coffee:public Drink
{
	public:
	virtual void zhu()
	{
		cout<<"��ˮ"<<endl;
	};
	virtual void chong()
	{
		cout<<"���ݿ���"<<endl;
	};
	virtual void dao()
	{
		cout<<"��"<<endl;	
	};
	virtual void add()
	{
		cout<<"���Ǻ�ţ��"<<endl;
	};
};
class Tea:public Drink
{
	public:
		virtual void zhu()
		{
			cout<<"��ˮ"<<endl;
		};
		virtual void chong()
		{
			cout<<"���ݲ�Ҷ"<<endl;
		};
		virtual void dao()
		{
			cout<<"��"<<endl;	
		};
		virtual void add()
		{
			cout<<"������"<<endl;
		};
};
//��������
void make(Drink*abs)   //Drink*abs=new Coffee
{
	abs->domake();
	delete abs;
}
void test1()
{
	make(new Coffee);
	make(new Tea);
}

int main()
{
	test1();
}

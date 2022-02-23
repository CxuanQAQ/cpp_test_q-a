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
		cout<<"ÖóË®"<<endl;
	};
	virtual void chong()
	{
		cout<<"³åÅÝ¿§·È"<<endl;
	};
	virtual void dao()
	{
		cout<<"µ¹"<<endl;	
	};
	virtual void add()
	{
		cout<<"¼ÓÌÇºÍÅ£ÄÌ"<<endl;
	};
};
class Tea:public Drink
{
	public:
		virtual void zhu()
		{
			cout<<"ÖóË®"<<endl;
		};
		virtual void chong()
		{
			cout<<"³åÅÝ²èÒ¶"<<endl;
		};
		virtual void dao()
		{
			cout<<"µ¹"<<endl;	
		};
		virtual void add()
		{
			cout<<"¼ÓÄûÃÊ"<<endl;
		};
};
//ÖÆ×÷º¯Êý
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

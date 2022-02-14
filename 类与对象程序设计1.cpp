#include<iostream>
#include<string>
using namespace std;
class Account
{
	public:
		int num;
		string name;
		int balance;
		//存款
		int in(int a)
		{
			balance+=a;
			return balance;
		}
		//取款
		int out(int b)
		{
			balance-=b;
			return balance;			
		}

};


int main()
{
	Account c1;
	c1.num=789512;
	c1.name="张三";
	c1.balance=1000;
	cout<<"账号："<<c1.num<<endl;
	cout<<"姓名："<<c1.name<<endl;
	cout<<"余额："<<c1.balance<<endl;
	cout<<endl;
	cout<<"1--存款"<<endl;
	cout<<"2--取款"<<endl;
	cout<<"选择功能 ";	
	int i;
	cin>>i;

	if(i==1)
	{
		cout<<"输入存款金额：";
		int x;
		cin>>x;
		cout<<"余额："<<c1.in(x)<<endl;	
	}
	if(i==2)
	{
		cout<<"输入取款金额：";
		int y;
		cin>>y;
		cout<<"余额："<<c1.out(y)<<endl;	
	}
	
	return 0; 
}

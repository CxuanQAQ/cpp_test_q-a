#include<iostream>
#include<string>
using namespace std;
class Account
{
	public:
		int num;
		string name;
		int balance;
		//���
		int in(int a)
		{
			balance+=a;
			return balance;
		}
		//ȡ��
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
	c1.name="����";
	c1.balance=1000;
	cout<<"�˺ţ�"<<c1.num<<endl;
	cout<<"������"<<c1.name<<endl;
	cout<<"��"<<c1.balance<<endl;
	cout<<endl;
	cout<<"1--���"<<endl;
	cout<<"2--ȡ��"<<endl;
	cout<<"ѡ���� ";	
	int i;
	cin>>i;

	if(i==1)
	{
		cout<<"�������";
		int x;
		cin>>x;
		cout<<"��"<<c1.in(x)<<endl;	
	}
	if(i==2)
	{
		cout<<"����ȡ���";
		int y;
		cin>>y;
		cout<<"��"<<c1.out(y)<<endl;	
	}
	
	return 0; 
}

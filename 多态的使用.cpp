#include<iostream>
#include<string>
using namespace std;
class Animal
{
	public:
		virtual void speak()
		{
			cout<<"������Խ�"<<endl;
		}
};
class Cat:public Animal
{
	public:
		void speak()
		{
			cout<<"miaomiao"<<endl;
		}
	
};
class Dog:public Animal
{
	public:
		void speak()
		{
			cout<<"wangwang"<<endl;
		}
};
//ִ��˵���ĺ���
//��ַ��󶨣��ڱ���׶�ȷ��������ַ
//�����ִ����è˵������ô��������ĵ�ַ�Ͳ�����ǰ�󶨣���ַ���


//��̬��̬��������
//1.�м̳й�ϵ
//2.������д������麯�������ຯ��ǰ�ɼ�virtualҲ�ɲ��ӣ�

//��̬��̬��ʹ��
//�����ָ���������ִ���������
void dospeak(Animal &a)//  ����~ָ�� Animal & animal=cat
{
	a.speak();
}

void test()
{
	Cat cat;
	dospeak(cat);
	Dog dog;
	dospeak(dog);
}
int main()
{
	test();
	return 0;
}

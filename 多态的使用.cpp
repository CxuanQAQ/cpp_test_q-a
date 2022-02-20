#include<iostream>
#include<string>
using namespace std;
class Animal
{
	public:
		virtual void speak()
		{
			cout<<"动物可以叫"<<endl;
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
//执行说话的函数
//地址早绑定，在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数的地址就不能提前绑定，地址晚绑定


//动态多态满足条件
//1.有继承关系
//2.子类重写父类的虚函数（子类函数前可加virtual也可不加）

//动态多态的使用
//父类的指针或者引用执行子类对象
void dospeak(Animal &a)//  引用~指针 Animal & animal=cat
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

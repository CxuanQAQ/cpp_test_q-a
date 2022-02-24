#include<iostream>
#include<string>
#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
#define MAX 1000
void showmMenu()
{
	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
	cout<<"      通讯录管理系统"<<endl;
	cout<<"=======1.添加联系人======="<<endl;
	cout<<"=======2.显示联系人======="<<endl;
	cout<<"=======3.删除联系人======="<<endl;
	cout<<"=======4.查找联系人======="<<endl;
	cout<<"=======5.修改联系人======="<<endl;
	cout<<"=======6.清空联系人======="<<endl;
	cout<<"=======0.退出通讯录======="<<endl;
	cout<<"--------------------------"<<endl;
}
struct Person				//设计联系人结构体
{
	string m_Name;		//名字
	int m_Sex;			//1男2女
	int m_Age;			//年龄
	string m_Phone;		//电话
	string m_Addr;		//住址
};
struct Addressbooks						//设计通讯录结构体
{
	struct Person personArray[MAX];		//通讯录中保存联系人的数组
	
	int m_Size;							//通讯录中当前记录联系人个数
		
};

void addPerson(Addressbooks*abs)//添加联系人
{
	if(abs->m_Size==MAX)//判断是否满
	{
		cout<<"已满，无法添加"<<endl;
		return;
	}
	else
	{
	/*姓名*/
	string name;	
	cout<<"请输入姓名：";
	cin>>name;
	abs->personArray[abs->m_Size].m_Name=name;
	
	/*性别*/
	cout<<"请输入性别(1男  2女)：";
	int sex;
	while(1)
	{
			cin>>sex;
		if(sex==1||sex==2)
		{
			abs->personArray[abs->m_Size].m_Sex=sex;
			break; 		
		}
		cout<<"输入有误，重新输入"<<endl;
	}

	/*年龄*/
	int age;
	cout<<"请输入年龄：";
	cin>>age;
	abs->personArray[abs->m_Size].m_Age=age;
	
	/*电话*/
	string phone;
	cout<<"请输入联系人电话：";
	cin>>phone;
	abs->personArray[abs->m_Size].m_Phone=phone;
	
	/*住址*/
	string address;
	cout<<"请输入联系人住址：";
	cin>>address;
	abs->personArray[abs->m_Size].m_Addr=address;
	
	abs->m_Size++;
	cout<<"添加成功"<<endl;
	system("pause");
	system("cls");
	
	}
		
}


void showPerson(Addressbooks*abs)//显示联系人
{
	if(abs->m_Size==0)
	{
		cout<<"当前记录为空"<<endl;

	}	
	else
	{
		for(int i=0;i<abs->m_Size;i++)
		{
			cout<<"姓名："<<abs->personArray[i].m_Name<<"\t";
			cout<<"  性别："<<(abs->personArray[i].m_Sex==1?"男":"女")<<"\t";		
			cout<<"  年龄："<<abs->personArray[i].m_Age<<"\t";
			cout<<"  电话："<<abs->personArray[i].m_Phone<<"\t";
			cout<<"  住址："<<abs->personArray[i].m_Addr<<"\t";
			cout<<endl;
		}
	}
	system("pause");
	system("cls");
}

int isexist(Addressbooks*abs,string name)//判断联系人是否存在
{
	for(int i=0;i<abs->m_Size;i++)
	{
		if(abs->personArray[i].m_Name==name)
		{
			return i;	
		}
	}
	return -1;
}
void deletePerson(Addressbooks*abs)
{
	cout<<"请输入要删除的联系人名称：";
	string name;
	cin>>name;
	int ret= isexist(abs,name);//这里的abs是指针 
	if(ret!=-1)
	{
		for(int i=ret;i<abs->m_Size;i++)
		{
			abs->personArray[i]=abs->personArray[i+1];//TODO
		}
	 	 	
		abs->m_Size--;
		cout<<"删除成功"<<endl;
	}
	else
	{
	cout<<"查无此人"<<endl;
	}
	system("pause");
	system("cls");
	
	
}

void search(Addressbooks*abs)
{
	cout<<"选择以何种方式查找（1.姓名 2.住址）";
	int a;
	cin>>a;
	if(a==1)
	{
		cout<<"请输入要查找联系人的姓名：";
		string name;
		cin>>name;
		for(int i=0;i<abs->m_Size;i++)
		{
			if(name==abs->personArray[i].m_Name)
			{
			cout<<"姓名："<<abs->personArray[i].m_Name<<"\t";
			cout<<"  性别："<<(abs->personArray[i].m_Sex==1?"男":"女")<<"\t";		
			cout<<"  年龄："<<abs->personArray[i].m_Age<<"\t";
			cout<<"  电话："<<abs->personArray[i].m_Phone<<"\t";
			cout<<"  住址："<<abs->personArray[i].m_Addr<<"\t";
			cout<<endl;
			}
		}
	}
	else if(a==2)
	{
		cout<<"请输入地址"<<endl;
		string address;
		cin>>address;
		for(int i=0;i<abs->m_Size;i++)
		{
			if(address==abs->personArray[i].m_Addr)
			{
			cout<<"姓名："<<abs->personArray[i].m_Name<<"\t";
			cout<<"  性别："<<(abs->personArray[i].m_Sex==1?"男":"女")<<"\t";		
			cout<<"  年龄："<<abs->personArray[i].m_Age<<"\t";
			cout<<"  电话："<<abs->personArray[i].m_Phone<<"\t";
			cout<<"  住址："<<abs->personArray[i].m_Addr<<"\t";
			cout<<endl;
			}	//TODO
		}	//TODO
	}
	else
	{
		cout<<"不存在"<<endl;
	}
	system("pause");
	system("cls");
}


void mod(Addressbooks*abs)
{
	cout<<"请输入要修改联系人的姓名";
	string name;
	cin>>name;
	int a=isexist(abs,name);
	if(a!=-1)
	{
		for(int i=0;i<abs->m_Size;i++)
		{
			if(name==abs->personArray[i].m_Name)
			{
				cout<<"请选择要修改的项目（1.姓名 2.性别 3.年龄 4.电话 5.住址） ";
				int a;
				cin>>a;
				switch (a) 
				{
					case 1:
					{
					cout<<"输入新的姓名 ";
					string new_name;
					cin>>new_name;
					abs->personArray[i].m_Name=new_name;
					cout<<"修改完成"<<endl;			
					break;						
					}	
	
					case 2:
					{
					cout<<"请输入新的性别（1.男 2.女） ";
					int a;
					cin>>a;
					abs->personArray[i].m_Sex=a;
					cout<<"修改完成"<<endl;									
					break;
					}	

					case 3:
					{
					cout<<"请输入新的年龄 ";
					int b;
					cin>>b;
					abs->personArray[i].m_Age=b;
					cout<<"修改完成"<<endl;
					break;
					}
					
					case 4:
					{
					cout<<"请输入新的电话号码 ";
					string n;
					cin>>n;
					abs->personArray[i].m_Phone=n;
					cout<<"修改完成"<<endl;
					break;							
					}
					
					case 5:
					{
					cout<<"请输入新的地址 ";
					string newadd;
					cin>>newadd;
					abs->personArray[i].m_Addr=newadd;
					cout<<"修改完成"<<endl;
					break;			
					}
							
				}		//TODO
			}
		
			
		}
	}
		else
		{
			cout<<"查无此人"<<endl;		
		}			
		
		system("pause");
		system("cls");
}


void delall(Addressbooks*abs)
{
	abs->m_Size=0;
	cout<<"通讯录已经清空"<<endl;
	system("pausse");
	system("cls");
	
}
int main()
{
//创建通讯录结构体变量
		Addressbooks abs;
//初始化通讯录中当前人员个数
		abs.m_Size=0;
		
	
	 
	
 	int select=0;//选择参数
 	while(true)
	 {
	 		showmMenu();
	 	cout<<"请输入您的选项"<<endl;
	  	cin>>select;
	  	switch (select)
	 	  {
	 	 	case 1:		//1.添加联系人
	 	 		addPerson(&abs);//利用地址传递修饰实参
	 	 		break;
	 	 	case 2:		//2.显示联系人
	 	 		showPerson(&abs);
				  break;
	 	 	case 3:		//3.删除联系人
	 	 		deletePerson(&abs);
				  break;
	 	 	case 4:		//4.查找联系人
	 	 		search(&abs);
				  break;
	 	 	case 5:		//5.修改联系人
	 	 		mod(&abs);
	 	 		
				  break;
	 	 	case 6:		//6.清空联系人
	 	 		delall(&abs);
				  break;
	 	 	case 0:		//0.退出通讯录
	 	 		cout<<"欢迎下次使用"<<endl;
	 	 		system("pause");
	 	 		return 0;
	 	 		break;
	 	 	default:
	 	 		break;
				  	 	 			
	 	 }
	 }

	return 0;
	
}

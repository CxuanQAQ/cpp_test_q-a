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
	cout<<"      ͨѶ¼����ϵͳ"<<endl;
	cout<<"=======1.�����ϵ��======="<<endl;
	cout<<"=======2.��ʾ��ϵ��======="<<endl;
	cout<<"=======3.ɾ����ϵ��======="<<endl;
	cout<<"=======4.������ϵ��======="<<endl;
	cout<<"=======5.�޸���ϵ��======="<<endl;
	cout<<"=======6.�����ϵ��======="<<endl;
	cout<<"=======0.�˳�ͨѶ¼======="<<endl;
	cout<<"--------------------------"<<endl;
}
struct Person				//�����ϵ�˽ṹ��
{
	string m_Name;		//����
	int m_Sex;			//1��2Ů
	int m_Age;			//����
	string m_Phone;		//�绰
	string m_Addr;		//סַ
};
struct Addressbooks						//���ͨѶ¼�ṹ��
{
	struct Person personArray[MAX];		//ͨѶ¼�б�����ϵ�˵�����
	
	int m_Size;							//ͨѶ¼�е�ǰ��¼��ϵ�˸���
		
};

void addPerson(Addressbooks*abs)//�����ϵ��
{
	if(abs->m_Size==MAX)//�ж��Ƿ���
	{
		cout<<"�������޷����"<<endl;
		return;
	}
	else
	{
	/*����*/
	string name;	
	cout<<"������������";
	cin>>name;
	abs->personArray[abs->m_Size].m_Name=name;
	
	/*�Ա�*/
	cout<<"�������Ա�(1��  2Ů)��";
	int sex;
	while(1)
	{
			cin>>sex;
		if(sex==1||sex==2)
		{
			abs->personArray[abs->m_Size].m_Sex=sex;
			break; 		
		}
		cout<<"����������������"<<endl;
	}

	/*����*/
	int age;
	cout<<"���������䣺";
	cin>>age;
	abs->personArray[abs->m_Size].m_Age=age;
	
	/*�绰*/
	string phone;
	cout<<"��������ϵ�˵绰��";
	cin>>phone;
	abs->personArray[abs->m_Size].m_Phone=phone;
	
	/*סַ*/
	string address;
	cout<<"��������ϵ��סַ��";
	cin>>address;
	abs->personArray[abs->m_Size].m_Addr=address;
	
	abs->m_Size++;
	cout<<"��ӳɹ�"<<endl;
	system("pause");
	system("cls");
	
	}
		
}


void showPerson(Addressbooks*abs)//��ʾ��ϵ��
{
	if(abs->m_Size==0)
	{
		cout<<"��ǰ��¼Ϊ��"<<endl;

	}	
	else
	{
		for(int i=0;i<abs->m_Size;i++)
		{
			cout<<"������"<<abs->personArray[i].m_Name<<"\t";
			cout<<"  �Ա�"<<(abs->personArray[i].m_Sex==1?"��":"Ů")<<"\t";		
			cout<<"  ���䣺"<<abs->personArray[i].m_Age<<"\t";
			cout<<"  �绰��"<<abs->personArray[i].m_Phone<<"\t";
			cout<<"  סַ��"<<abs->personArray[i].m_Addr<<"\t";
			cout<<endl;
		}
	}
	system("pause");
	system("cls");
}

int isexist(Addressbooks*abs,string name)//�ж���ϵ���Ƿ����
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
	cout<<"������Ҫɾ������ϵ�����ƣ�";
	string name;
	cin>>name;
	int ret= isexist(abs,name);//�����abs��ָ�� 
	if(ret!=-1)
	{
		for(int i=ret;i<abs->m_Size;i++)
		{
			abs->personArray[i]=abs->personArray[i+1];//TODO
		}
	 	 	
		abs->m_Size--;
		cout<<"ɾ���ɹ�"<<endl;
	}
	else
	{
	cout<<"���޴���"<<endl;
	}
	system("pause");
	system("cls");
	
	
}

void search(Addressbooks*abs)
{
	cout<<"ѡ���Ժ��ַ�ʽ���ң�1.���� 2.סַ��";
	int a;
	cin>>a;
	if(a==1)
	{
		cout<<"������Ҫ������ϵ�˵�������";
		string name;
		cin>>name;
		for(int i=0;i<abs->m_Size;i++)
		{
			if(name==abs->personArray[i].m_Name)
			{
			cout<<"������"<<abs->personArray[i].m_Name<<"\t";
			cout<<"  �Ա�"<<(abs->personArray[i].m_Sex==1?"��":"Ů")<<"\t";		
			cout<<"  ���䣺"<<abs->personArray[i].m_Age<<"\t";
			cout<<"  �绰��"<<abs->personArray[i].m_Phone<<"\t";
			cout<<"  סַ��"<<abs->personArray[i].m_Addr<<"\t";
			cout<<endl;
			}
		}
	}
	else if(a==2)
	{
		cout<<"�������ַ"<<endl;
		string address;
		cin>>address;
		for(int i=0;i<abs->m_Size;i++)
		{
			if(address==abs->personArray[i].m_Addr)
			{
			cout<<"������"<<abs->personArray[i].m_Name<<"\t";
			cout<<"  �Ա�"<<(abs->personArray[i].m_Sex==1?"��":"Ů")<<"\t";		
			cout<<"  ���䣺"<<abs->personArray[i].m_Age<<"\t";
			cout<<"  �绰��"<<abs->personArray[i].m_Phone<<"\t";
			cout<<"  סַ��"<<abs->personArray[i].m_Addr<<"\t";
			cout<<endl;
			}	//TODO
		}	//TODO
	}
	else
	{
		cout<<"������"<<endl;
	}
	system("pause");
	system("cls");
}


void mod(Addressbooks*abs)
{
	cout<<"������Ҫ�޸���ϵ�˵�����";
	string name;
	cin>>name;
	int a=isexist(abs,name);
	if(a!=-1)
	{
		for(int i=0;i<abs->m_Size;i++)
		{
			if(name==abs->personArray[i].m_Name)
			{
				cout<<"��ѡ��Ҫ�޸ĵ���Ŀ��1.���� 2.�Ա� 3.���� 4.�绰 5.סַ�� ";
				int a;
				cin>>a;
				switch (a) 
				{
					case 1:
					{
					cout<<"�����µ����� ";
					string new_name;
					cin>>new_name;
					abs->personArray[i].m_Name=new_name;
					cout<<"�޸����"<<endl;			
					break;						
					}	
	
					case 2:
					{
					cout<<"�������µ��Ա�1.�� 2.Ů�� ";
					int a;
					cin>>a;
					abs->personArray[i].m_Sex=a;
					cout<<"�޸����"<<endl;									
					break;
					}	

					case 3:
					{
					cout<<"�������µ����� ";
					int b;
					cin>>b;
					abs->personArray[i].m_Age=b;
					cout<<"�޸����"<<endl;
					break;
					}
					
					case 4:
					{
					cout<<"�������µĵ绰���� ";
					string n;
					cin>>n;
					abs->personArray[i].m_Phone=n;
					cout<<"�޸����"<<endl;
					break;							
					}
					
					case 5:
					{
					cout<<"�������µĵ�ַ ";
					string newadd;
					cin>>newadd;
					abs->personArray[i].m_Addr=newadd;
					cout<<"�޸����"<<endl;
					break;			
					}
							
				}		//TODO
			}
		
			
		}
	}
		else
		{
			cout<<"���޴���"<<endl;		
		}			
		
		system("pause");
		system("cls");
}


void delall(Addressbooks*abs)
{
	abs->m_Size=0;
	cout<<"ͨѶ¼�Ѿ����"<<endl;
	system("pausse");
	system("cls");
	
}
int main()
{
//����ͨѶ¼�ṹ�����
		Addressbooks abs;
//��ʼ��ͨѶ¼�е�ǰ��Ա����
		abs.m_Size=0;
		
	
	 
	
 	int select=0;//ѡ�����
 	while(true)
	 {
	 		showmMenu();
	 	cout<<"����������ѡ��"<<endl;
	  	cin>>select;
	  	switch (select)
	 	  {
	 	 	case 1:		//1.�����ϵ��
	 	 		addPerson(&abs);//���õ�ַ��������ʵ��
	 	 		break;
	 	 	case 2:		//2.��ʾ��ϵ��
	 	 		showPerson(&abs);
				  break;
	 	 	case 3:		//3.ɾ����ϵ��
	 	 		deletePerson(&abs);
				  break;
	 	 	case 4:		//4.������ϵ��
	 	 		search(&abs);
				  break;
	 	 	case 5:		//5.�޸���ϵ��
	 	 		mod(&abs);
	 	 		
				  break;
	 	 	case 6:		//6.�����ϵ��
	 	 		delall(&abs);
				  break;
	 	 	case 0:		//0.�˳�ͨѶ¼
	 	 		cout<<"��ӭ�´�ʹ��"<<endl;
	 	 		system("pause");
	 	 		return 0;
	 	 		break;
	 	 	default:
	 	 		break;
				  	 	 			
	 	 }
	 }

	return 0;
	
}

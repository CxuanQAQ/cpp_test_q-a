#include <iostream>
using namespace std;
//ð��������
void bubble(int*arr,int len)	//arr -�����׵�ַ    len-���鳤��
{
	for(int i=0;i<len-1;i++)	//�������01234.....
	{
		for(int j =0;j<len-i-1;j++)	//�ڲ�ԱȽ����ܴ���
		{
				if (arr[j]>arr[j+1])
				{
				int temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
				}//TODO
		}	//TODO
	}	
}
void print_arr(int*arr,int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<endl;//TODO
	}
	
}
int main()
{
	// 1 ��������
	int arr[10]={5,7,6,5,2,8,4,11,25,47};
	// ���鳤��
	int len = sizeof(arr)/sizeof(arr[0]);
	// 2 ����������ʵ��ð������
	bubble(arr,len);
	// 3 ��ӡ
	print_arr(arr,len);
}

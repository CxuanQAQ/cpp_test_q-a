#include <iostream>
using namespace std;
//冒泡排序函数
void bubble(int*arr,int len)	//arr -数组首地址    len-数组长度
{
	for(int i=0;i<len-1;i++)	//外层轮数01234.....
	{
		for(int j =0;j<len-i-1;j++)	//内层对比交换总次数
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
	// 1 创建数组
	int arr[10]={5,7,6,5,2,8,4,11,25,47};
	// 数组长度
	int len = sizeof(arr)/sizeof(arr[0]);
	// 2 创建函数，实现冒泡排序
	bubble(arr,len);
	// 3 打印
	print_arr(arr,len);
}

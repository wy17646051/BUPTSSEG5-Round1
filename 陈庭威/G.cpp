#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[105];//a数组用来存储输入 
/*
思路:
这题没什么特别的,因为要想次数最小,就把两个离得最近的数变成同样大小
否则的话,会付出更多的代价
应该是贪心的思想
数组排序后,每两个元素求差值即可 
*/ 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);//对数组a进行快速排序 
	int sum=0;
	for(int i=1;i<=n;i+=2)//从1开始,每两个进行一次判断 
	{
		int k=abs(a[i]-a[i+1]);//求相邻两个数差的绝对值 
		sum+=k;//加到sum上 
	}
	cout<<sum;
}

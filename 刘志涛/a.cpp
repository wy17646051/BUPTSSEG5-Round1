#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,m,n;
	int a[1000];
	int b[1000];
	cin>>t;
	while(t--)//输入测试用例的数量
	{	int q=0;//这是判断是否是非递减数组
		cin>>m>>n;//输入数组和可交换的位置的数量
		
		for(int i=1;i<=m;i++)
		{
			cin>>a[i];//输入数组
		 } 
		 for(int j=1;j<=n;j++)
		 {
		 	cin>>b[j];//输入可交换的位置
		 	if(a[b[j]]>a[b[j]+1])//如果交换的两个位置，前面》后面，则交换位置
		 	{
		 	     int tmp=0;
		 	     tmp=a[b[j]];
		     	a[b[j]]=a[b[j]+1];
		     	a[b[j]+1]=tmp;
			 }
		 
		 }
		 
		 for(int c=1;c<n;c++)
		 {
		 	if(a[b[c]]>a[b[c]+1])
		 {
		 	int pm=0;
		 	pm=a[b[1]];
		 	a[b[1]]=a[b[1]+1];
		 	a[b[1]+1]=pm;
		 }//这里开始重新遍历，判断如果a[i]>a[i+1]项，则交换位置
		 }
		 
		 for(int i=1;i<m;i++)//如果他是非递减数组，那么赋值q=1;
		 {    
		 	if(a[i]>a[i+1])
		 	{
		 	     q=1;
			} 
		 }
		 if(q==1)
		 {
		 	cout<<"NO"<<endl;
		 	
		 }
		else
		{
			cout<<"YES"<<endl;
		}
		 
	}
 } 
思路：
这道题其实就是判断这个数组通过在固定的位置交换判断是否是非递减数列，如果交换的位置的数>后面的数就进行交换，否则就不交换，最后遍历一下，是否还有在位置处可以进行交换。能通过第一个测试。

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[1000],p[1000];
	int t,b;
	int sum=0;
	cin>>t;
     for(int i=1;i<=t;i++)
     {
     	cin>>a[i];//输入组队的总人数
	 }
	 for(int i=1;i<=t;i++)
	 {
	 	for(int j=2;j<=t;j++)
	 	{
	 		if(a[i]>a[j])
	 		{
	 			int tmp=0;
	 			tmp=a[i];
	 			a[i]=a[j];
	 			a[j]=tmp;
			 }
		 }
	 }//这里排序复杂了，可以用sort算法，机试的时候，我忘了怎么用了。
	 
	 for(int j=1;j<=t;j+=2)
	 {
	 	p[j]=a[j+1]-a[j];
	 	sum+=p[j];//对这个进行排序，然后1和2组一队，3和4组一队了，然后他们之间的差就是要解决的问题数。
	 }
	 cout<<sum<<endl;
	 
	 
 } 
这道题就是先把数组组好队，然后1和2一起，3和4一起，他们之间的差就是要解决的问题的总数，然后求和就好了。

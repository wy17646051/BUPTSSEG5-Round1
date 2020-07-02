#include<iostream>
using namespace std;
int t;
int a[105][105];//二维数组a,对应不同测试用例t下面的输入数组 
int p[105][105];//数组p, 对应不同测试用例t下面的可交换点
int m[105];//不同测试用例t下的交换点个数 
int n[105];// 不同测试用例t下的数组a的长度
/*
思路:
1.先针对每个不同的测试用例,接收数据并存储
2.针对每个测试用例,进行以下操作:
	2.1 遍历数组,若发现后者小于前者,并且处于可交换点,交换数据
	2.2 重复以上过程直至数组不再发生变化
	2.3 判断是否数组非递减,并输出相应信息 

*/ 
int main()
{
	cin>>t;
	for(int i=1;i<=t;i++)//完成输入赋值操作 
	{
		
		cin>>n[i]>>m[i];
		for(int j=1;j<=n[i];j++)
		cin>>a[i][j];
		for(int j=1;j<=m[i];j++)
		cin>>p[i][j];	
	}
	/*
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=n[i];j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
	*/
	for(int i=1;i<=t;i++)//循环不同测试用例 
	{
		int len=n[i];//当前测试用例下的数组a的长度len 
		int nump=m[i];// 前测试用例下可交换点的个数nump 
		int f=1;//f代表该次遍历是否发生了交换 
		while(f)//如果本次遍历发生了数据之间的交换,说明数组还没有交换完毕 
		{		//需要接着下一次遍历,直到数组不发生改变,退出循环 
			f=0;//先假设f=0,假设这次遍历数组不发生交换 
				for(int j=1;j<=len;j++)//循环每个数组 
			{
				if(a[i][j]>a[i][j+1])//如果后者比前者大 
				{
					//cout<<"i "<<i<<" j "<<j<<endl;
					int flag=0;//用来判断是否可以进行交换 
					for(int k=1;k<=nump;k++) //查找该点是否在可交换点上 
					{
						if(p[i][k]==j)//后者比前者大而且处于可交换点上
						{
							flag=1;//可以进行交换 
						}
		
					}
					if(flag)
					{
						swap(a[i][j],a[i][j+1]);//交换数据 
						f=1;//由于发生了交换,数组还在变化,所以要进行下一次遍历 
					}
					
					
				}
				
				
			}
		}
		/*
		cout<<"a[i]"<<endl;
		for(int j=1;j<=n[i];j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
		*/
	}
	
	for(int i=1;i<=t;i++)//检查该测试用例下,a数组完成交换后,是否符合要求 
	{
		int flag=1;//假定数组a由小到大 
		int len=n[i];
		for(int j=1;j<len;j++)
		{
			if(a[i][j]>a[i][j+1])
			{
				flag=0;//若数组出现后者小于前者(非递增),则数组不符合要求 
				break;
			}
		}
		if(flag)//判断该数组是否符合要求并进行输出 
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl; 
	}
}

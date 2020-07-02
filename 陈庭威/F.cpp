#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
//建立结点来存储每一个位置,包括x,y坐标,以及该坐标上是否有包裹 
typedef struct Node{
	int x;
	int y;
	int c;//是否有包裹 
};
queue<Node> Q;//队列 
void DFS(int x,int y,int a,int sum);//深搜 
void finish();
int t;//测试用例个数 
int n[1005];//每个测试用例下包裹的个数 
int maxx[105];//该测试用例下,包裹所达到的最大x值 
int maxy[105];// 该测试用例下,包裹所达到的最大y值 
int map[105][1005][1005];//存储每个测试用例下的地图信息,包括哪里有包裹 
int mark[105][1005][1005];//标记每个测试用例下,机器人走过的位置,防止重复 
char dir[105][1005][1005];//每个测试用例下,机器人到达某点所用的方向 
/*
思路:
这道题我的想法就是搜索,也就是BFS,DFS选择一种,我先用了BFS
BFS 
由于是让求最优解,我就想着先用BFS,但是写到一半发现了问题,第二个测试用例会过不去
对于第二个测试用例,先向右搜索,然后向上,在右边的结点扩展,又向上,到达了终点
 虽然到达了终点,但是实际上并没有搜集到足够的包裹....产生了误判
废话说了一堆, 其实就是感觉BFS不行,或许是我BFS还不够熟练
DFS
BFS不行,就用DFS
DFS写完了,也应该是正确的,能判断是否能搜集到足够的包裹
但是由于DFS搜索的是很多个结果,我还要从这里面挑一个最优的出来
后续的最优挑选,我没有时间写了,只好作罢 

 
*/ 
int main()
{
	cin>>t;
	memset(map,0,sizeof(map));
	for(int i=1;i<=t;i++)//输入全部测试用例并存储 
	{
		
		maxx[i]=0;
		maxy[i]=0;
		cin>>n[i];
		for(int j=0;j<n[i];j++)
		{
			int x,y;
			cin>>x;
			cin>>y;
			if(x>maxx[i])
			maxx[i]=x;
			if(y>maxy[i])
			maxy[i]=y;
			map[i][x][y]=1;
		}
		 
	}
	 
	/*
	for(int i=1;i<=t;i++)
	{
		
		for(int j=0;j<=20;j++)
		{
			for(int k=0;k<=20;k++)
			cout<<map[i][j][k];
			cout<<endl;
		}
		 cout<<endl;
	}
	*/
	for(int i=1;i<=t;i++)//DFS 
	{
		
		mark[i][0][0]=1;
		DFS(0,0,i,0);//DFS搜索 
	} 
	for(int i=1;i<=t;i++)//BFS,刚开始想用BFS的,但是写到一半发现似乎不怎么对 
	{					//就改用DFS了 
		while(!Q.empty())//清空上个测试用例时,队列里的结点 
		Q.pop();
		Node node;//最初结点入队 
		node.x=0;
		node.y=0;
		node.c=0;
	} 
	
}
void DFS(int x,int y,int a,int sum)//当前位置的x,y坐标,a为对应的测试用例,
									//sum为收集的包裹个数 
{
	//cout<<"x is "<<x<<" y is "<<y<<endl;
	if(x==maxx[a]&&y==maxy[a]&&sum<n[a])//如果到达边界并且还没找到足够的包裹 
	{									//说明本次收集失败了 
		cout<<"NO"<<endl;
		return;
	}
	if(map[a][x][y]==1)//如果当前位置上有包裹,sum++进行计数 
	sum+=1;
	if(sum==n[a])//如果收集的包裹数量达到要求,说明本次收集成功 
	{
		//cout<<a<<":"<<endl;
		finish();
		return;
	}
	
	int direction[2][2]={1,0,0,1};//R和U 
	for(int i=0;i<2;i++ )//先向右,再向上 
	{
		int nextx=x+direction[i][0];//下个位置的x坐标 
		int nexty=y+direction[i][1];//下个位置的y坐标 
		if(nextx>maxx[a]+1||nextx<0||nexty>maxy[a]+1||nexty<0) 
		continue;//在边界处,不能继续走 
		if(mark[a][nextx][nexty]==0)//下个位置没有被走过 
		{
			if(i==0)
			dir[a][nextx][nexty]='R';//记录上个位置到达该位置所用的方向 
			else
			dir[a][nextx][nexty]='D';//记录上个位置到达该位置所用的方向 
			mark[a][nextx][nexty]=1;//下个位置打上标记,已被走过 
			DFS(nextx,nexty,a,sum);//走下个位置 
			mark[a][nextx][nexty]=0;//回溯,把标记清空 
		}
	}
	
	
}
void finish()
{
	cout<<"YES"<<endl;//成功收集包裹的处理函数,但是没时间写了 
}
void  BFS(int a)
{
	while(!Q.empty())//Q不空的情况下,每次从队头出来一个结点,并根据该节点的 
	{				//右边或者上边进行扩展,如果符合要求,就入队
					//但是.....感觉这道题不能这样写,就没写完,改用DFS了 
		Node node;
		node=Q.front();
		Q.pop();
		int x=node.x;
		int y=node.y;
		int c=node.c;
	}
	
}

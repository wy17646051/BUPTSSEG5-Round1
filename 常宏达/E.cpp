/**
题意理解：
本题根本目的就是，最少添加多少条边，可以使得从给定点到任意一点是可达的

解题思路流程：
step1：从给定点（以下简称s点），做dfs遍历，在遍历过程中，对从s点可达的其余各点进行标记；
step2：判断是否所有点均被标记，如果没有则进行step3，否则进行step4；
step3：选择一个未被标记的点i（入度为0，或者与其他点构成环），添加一条从s点到该点i的边，同时将所需添加的边数（以下简称res，res初始为0）加1，之后执行step1；
step4：输出所需添加的边数res；

时间复杂度分析：
采用邻接矩阵存储图，最坏情况下是s点到其余任意一点都不可达，同时其余任意一点之间不可达;
每次标记一个点，最大为n次；每次标记后进行dfs遍历，由于采用邻接矩阵进行存储，因此每次dfs遍历的复杂度初略估计为O(n^2);
因此算法总体复杂度粗略估计为O(n^3);
n的最大取值是5000；因此n^3==125,000,000,000，当输入n值较大时会超过time limit；
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

typedef long long LL;

using namespace std;
//最大数据范围
const int N=5010;
//状态数组，用来判断从s点到第i个点（下标）是否可达，下标为点号
int st[N];
//邻接矩阵存储有向图
int a[N][N];
//输入变量，变量名同题中描述
int n,m,s;

/**判断是否所有的点均可达
参数：无
返回值：当所有点均可达返回-1；当存在点不可达返回状态数组st中首个不可达的点号（debug时发现此处应该返回，入度为0，或者与其他点构成环的点号）
*/
int isSec(){
    for(int i=1;i<=n;i++){
        if(st[i]==0){
            return i;
        }
    }
    return -1;
}

/**
dfs遍历有向图a，同时对于从p点起的其余各可达点，在状态数组st中进行标记
参数：p: dfs遍历的起点；
返回值：无
*/
void dfs(int p){
    st[p]=1;

    for(int i=1;i<=n;i++){
        if(st[i]==1) continue;
        if(a[p][i]==0) continue;
        dfs(i);
    }
}

/**
主函数
*/
int main(){
    //输入
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        a[u][v]=1;
    }

    //初始化所需添加的边数res=0
    int res=0;
    //不断遍历有向图，直到所有点均可以从s点可达，通过break退出循环
    while(1){
        //初始化状态数组
        memset(st,0,sizeof st);
        //dfs遍历有向图（遍历过程中会对可达的点在状态数组st中进行标记）
        dfs(s);
        //判断是否全部点均可从s点起可达
        int tmp=isSec();
        //当均可达，退出循环；
        if(tmp==-1) break;
        //当存在不可达（即未推出循环），增加一条从s点到状态数组st中首个不可达点的边
        //（debug时候发现，应该增加一个从s点到另一个，入度为0，或者与其他点构成环的不可达点的边），同时res加1；
        a[s][tmp]=1;
        res++;
    }

    //输出结果
    cout<<res;



    return 0;
}

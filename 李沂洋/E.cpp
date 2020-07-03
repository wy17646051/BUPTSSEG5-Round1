#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
题意：题意比较简单，就是对于一个无向无环图所有的点，找出符合[该点的权值*该点到其他点的距离]求和后最小的值。

思路：如果不考虑时间复杂度及数组大小的话，完全可以用迪杰斯特拉或者弗洛伊德求出每个点到其他点的距离，但是其实这里是大材小用了（且超时，连数组都开不下）
因为题目有两个条件，就是每个点之间距离都是1，也就是说可以用广度优先搜索计算每个点到每个其他点的距离并顺便把题目要求的那个和给求了，然后，这样的话，搜索一遍复杂度大概是n，
对于n个点都搜索一遍，那么复杂度是n方，然后从中选出一个最小的距离。

总结：该题最后没有足够的时间去思考了，大部分时间都花费在了A题case2上，挺想知道究竟是哪个case没过。。
*/
const int maxn = 200010;//N的上限

vector<int> maps[maxn];//用vector容器来存储图是比较常规的操作
//保存权值
int w[maxn];
int visit[maxn] = { 0 };


int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;++i)
		cin >> w[i];
	//输入边
	int x, y;
	//建图
	for (int i = 0;i <= n;++i)
	{
		cin >> x >> y;
		maps[x].push_back(y);
		maps[y].push_back(x);
	}
	//然后广搜记录距离
	for (int i = 0;i < n;++i)
	{
		
	}

	system("pause");
	return 0;
}

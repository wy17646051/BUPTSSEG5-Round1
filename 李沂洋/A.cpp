#include <iostream>
#include <bits/stdc++.h>
#define maxn 110
#define LL long long
using namespace std;
/*
 题意：给你一个数组a，然后给你一个数组p，这个数组p中的数，比如3，表示的的是你可以移动的a中元素的第3个元素那么怎么移动
 呢？也很简单，就是3和3+1位置交换，能移动几次呢？没有限制。那么p其实就是告诉你哪些元素可以移动，我理解为交换枢纽点，
 怎么移动也告诉我们了，那么题目要求是什么呢？问，是否能通过有限次移动使得最终a的样子是一个非递减序列。
 
 题意理解：通过题意我们发现，因为无限次移动，所以其实a中一个数无限次移动走了，他还可以无限次的移动回来，也就是说如果我调整
 某个元素的位置，把它放到最前面，那么中间移动过的元素，一定可以移动回去，保持原样（当然除了最终互换位置的那个元素）。
 
 思路：基于上面的理解，我认为该问题应该可以拆分成若干个子问题，即可以先把数组a中最小的元素与第一个元素互换位置，这个时候，
 这个最小的数已经到达最终位置了，然后问题就变成了，把a子序列中剩下数再选出一个最小的数，再次排到该子序列的最前面，重复执行，
 如果最终每个数都可以就位，那么就意味着YES。但是如何判断是否能移动的过去呢？我这里有两个思路。
 
 判断是否可以将一个子序列中的最小元素移动到该子序列的头部：
 1.数p中的元素，看一共有几个元素在从“数子序列的头部到该元素下标-1这个下标集合里”，就是看从这个元素到其最终位置有多少个转运枢纽
 当且仅当该枢纽的数量=该元素的下标- 子序列头部下标时，表示有足够的转运站，可以运过去。
 这样的话，对a中每个元素都判断一遍，但凡有一个不符合，就表示整个a无法通过p变成一个非递减序列。
 
 2.第二种方法其实也是基于这个思想，但是有些笨重，就是用for循环模仿了这个换位过程，并没有使用转运枢纽的数量来表示是否可以转运过去。
 
 总结：以上两种方法都通过了题目给出的样例，但是又都卡在了第二个case上，思考了很久，花费了比较长的时间。
*/
int t;
int n, m;
int a[maxn];
int p[maxn];
int index;
//下面这个函数是用来求a数组从下标startindex到下标endindex这个区间内，最小的数的下标并返回
int findMinIndex(int startindex,int endindex)
{
	int min = a[startindex];//初始化为第一个可用下标对应的值
	int key = startindex;//初始化为第一个可用下标
	//遍历a从startindex+1到endindex 通过比较找到最小的数，以及最小数的下标
	for (int i = startindex + 1;i <= endindex;++i)
		if (a[i] < min)
		{
			min = a[i];
			key = i;
		}
	//遍历结束，返回最终最小数的下标
	return key;
}
int main()
{
	
	cin >> t;
	
	while (t--)
	{
		cin >> n >> m;
		//输入
		for (int i = 0;i < n;++i)
			cin >> a[i];
		for (int i = 0;i < m;++i)
			cin >> p[i];
		//按照从小到大，把a中的每一个元素运到前面
		bool ok = true;
		for (int i = 0;i < n;++i)
		{
			//获取最小元素索引
			index = findMinIndex(i, n - 1);
			//如果正好处在子序列头部，那就不用运输的
			if (index == i)
				continue;
			//初始化枢纽数量
			int num = 0;
			//通过计算枢纽数量来判断能否运送过去
			for (int j = 0;j < m;++j)
			{
				//p[j]-1是为了转化成索引，判断在子序列头部和子序列的最小元素之间有多少个枢纽
				if (p[j] - 1 >= i&&p[j] - 1 <= index - 1)
					num++;
			}
			//如果枢纽数量正好=该元素的下标- 子序列头部下标，那么必然能运输过去
			if (num == (index - i))
				ok = true;
			else
			{
				//否则不行
				ok = false;
				//后面的不看了，直接淘汰
				break;
			}
		}
		if (ok)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
	}
	system("pause");
	return 0;
}

/*法二
#include <iostream>
#include <bits/stdc++.h>
#define maxn 110
#define LL long long
using namespace std;
int t;
int n, m;
int a[maxn];
int p[maxn];
int index;
//下面这个函数是用来求a数组从下标startindex到下标endindex这个区间内，最小的数的下标并返回
int findMinIndex(int startindex,int endindex)
{
	int min = a[startindex];//初始化为第一个可用下标对应的值
	int key = startindex;//初始化为第一个可用下标
	//遍历a从startindex+1到endindex 通过比较找到最小的数，以及最小数的下标
	for (int i = startindex + 1;i <= endindex;++i)
		if (a[i] < min)
		{
			min = a[i];
			key = i;
		}
	//遍历结束，返回最终最小数的下标
	return key;
}
int main()
{

	cin >> t;

	while (t--)
	{
		cin >> n >> m;
		//输入
		for (int i = 0;i < n;++i)
			cin >> a[i];
		for (int i = 0;i < m;++i)
			cin >> p[i];
		//按照从小到大，把a中的每一个元素运到前面
		for (int i = 0;i < n;++i)
		{
			//获取最小元素索引
			index = findMinIndex(i, n - 1);
			//看看所有的子序列元素是否都能否通过p移动过去
			bool itcan = true;
			while (index != i&& itcan)
			{
				//用于判断某个元素是否可以转运过去
				bool ok = false;
				for (int j = 0;j <m;++j)
				{
					//如果当前最小元素下标-1的位置上有运输枢纽，那么交换，同时ok置1
					if (p[j] - 1 == index - 1)
					{
						//交换两个数
						int temp = a[index];
						a[index] = a[index - 1];
						a[index - 1] = temp;
						index = index - 1;
						ok = true;
						break;
					}
				}
				//如果当前元素可以，那么试一试下一个元素
				if (ok)
					continue;
				//否则，直接淘汰整个序列
				else
				{
					itcan = false;
					break;
				}
			}
			if (!itcan)
			{
				cout << "NO" << endl;
				break;
			}
			else {
				cout << "YES" << endl;
				break;
			}


		}

	}
	system("pause");
	return 0;
}
*/
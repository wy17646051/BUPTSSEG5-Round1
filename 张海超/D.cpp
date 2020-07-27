#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<cctype>
#include<algorithm>
#include<stdio.h>
#define INF 0x3f3f3f3f
using namespace std;
const int  maxn = 100000;
long long b[maxn];
long long a[maxn];
//对于等差数列 只需确定第一项和公差就可唯一确定这个等差数列
//所以只考虑前两项的组合情况 一共9种  然后再遍历就可得到答案
int main() {
	
	int n;
	cin >> n;
	
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		long long answer = INF, d;
		//int flag;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				//answer = 0;
				int flag = 1;
				long long cnt = (long long)abs(i) + (long long)abs(j);
				
				b[2] = a[2] + j;
				b[1] = a[1] + i;
				d = b[2] - b[1];
				for (int k = 3; k <= n; k++) {
					/*if (abs((b[k - 1] + d) - a[k]) <= 1) {
						b[k] = b[k - 1] + d;
						answer = abs(b[k] - a[k]);
					}
					else {
						flag = 0;
						break;
					}*/
					b[k] = b[k - 1] + d;
					if (abs(b[k] - a[k]) > 1) {
						flag = 0;
						break;
					}
					if (b[k] != a[k])
						cnt++;
				}
				if (flag)
					answer = min(answer, cnt);
			}
		}
		if (answer!=INF)
			printf("%lld\n", answer);
		else
			printf("-1\n");
	
	return 0;
}
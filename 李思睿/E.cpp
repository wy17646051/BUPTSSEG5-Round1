#include<iostream>
#include<algorithm>
#include<cstring>
#define MAX_N 200000 + 5
using namespace std;

int a[MAX_N] = {0}; // 记录输入
int b[MAX_N] = {0}; // 记录数字的个数
int v[MAX_N] = {0}; // 访问过的数字

// 提交的时候只pass test1-2
// 错误点：数字忽略了整体左右移动的情况
// 现在的代码能够 accept：在codeforces提交成功，用户xiaoboyu，编号86970922
int main(void)
{
	int n;
	cin>>n;
	memset(b, 0, sizeof(b));
	memset(v, 0, sizeof(v));

	// 输入，并记录每个数字的个数
	for (int i = 0; i < n; i++) {
		cin>>a[i];
		b[a[i]]++;
	}

	// 通过排序，排除相同的数字，防止重复计算
	sort(a, a + n);
	int m = unique(a, a + n) - a;

	v[0] = 1;
	for (int i = 0; i < m; i++) {
    		if (b[a[i]] >= 3) {
    		// 个数大于3个的数字，+1、-1和自己都可以添加
    			v[a[i] - 1] = 1;
    			v[a[i] + 1] = 1;
    			v[a[i]] = 1;
    		} else if (b[a[i]] == 2) {
    		// 个数等于2个的数字，尽量填充左边没访问过的数字
    			if (v[a[i] - 1] == 0) v[a[i] - 1] = 1;
    			else if (v[a[i] + 1] == 0) v[a[i] + 1] = 1;
    			v[a[i]] = 1;
    		} else if (b[a[i]] == 1) {
    		// 个数等于1个的数字，尽量填满左边的数字-1
    			if (v[a[i] - 1] == 0) {
    				v[a[i]] = 0;
    				v[a[i] - 1] = 1;
    			} else if (v[a[i]] != 0) {
    			// 如果自己被左边的数字访问过了，就往右边填充。
    				v[a[i] + 1] = 1;
    			} else {
    			// 没法左右移动就填自己的位置
    				v[a[i]] = 1;
    			}
    		}
    	}
	
	int cnt = 0;
	for (int i = 1; i <= 150001; i++) {
		if (v[i] > 0) cnt++;
	}
	cout<<cnt<<endl;
	
	return 0;
}

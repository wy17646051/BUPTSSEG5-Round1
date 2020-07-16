#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX_N 200000 + 5
using namespace std;

char str[MAX_N];
int v[3] = {0};

// past test1-8
// 错误点：没有考虑中间的数字能够%3==0的情况
/** 基本思路：借助数字每位数之和能够整除3，则该数字即可整除3
    用数组记录3的余数0，1，2：如果余数两次被访问，就说明能被整除了
    两次访问意味着：在之前记录的数字基础上，加了3的倍数，说明中间的数字可以整除
*/
// 当前代码能够accept：在codeforces提交成功，用户xiaoboyu，编号86973549
int main(void)
{
    // 用字符串存储大数字
	cin>>str;

	int n = strlen(str);
    int cnt = 0;
    int x = 0;
    p[0] = 1;   // 防止第一个数字被忽略
    for (int i = 0; i < n; i++) {
        x += (str[i] - '0');
        x %= 3;
        if (v[x]) {
            v[0] = 1;
            v[1] = 0;
            v[2] = 0;
            x = 0;
            cnt++;
        } else v[x] = 1;
    }

	cout<<cnt<<endl;
	return 0;
}

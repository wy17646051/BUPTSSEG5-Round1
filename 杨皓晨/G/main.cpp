#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[101];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n); //将所有人的编程水平排序，使得相邻两个的差值最小
    int cnt = 0;
    for(int i = 1;i <= n-1;i += 2){
        if(a[i] != a[i+1])
            cnt += abs(a[i] - a[i + 1]);   //相邻两个之间的差值相加即为最小所要解决的题目
    }
    printf("%d\n",cnt);
    return 0;
}

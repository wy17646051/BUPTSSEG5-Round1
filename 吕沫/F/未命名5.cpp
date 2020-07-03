//该题主要要求是从一组数据中找出前n个最大的数及其下标
//只需要让每个区间内都包含一个前k最大值，首先找到最大的k个数存进一个数组，从左到右遍历，
//如果当前值在最大里面，就把下标记录下来，或者直接计算长度，与上一个坐标差。
#include <stdio.h>
#include <algorithm>
using namespace std;
#define maxn 2000

int n,k,ans;
struct node{
	int w,p;
}a[maxn+5];

int b[maxn+5];
bool cmp(node x,node y){
	return x.w>y.w;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].w),a[i].p=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=k;i++) ans+=a[i].w,b[i]=a[i].p;
	printf("%d\n",ans);
	sort(b,b+k+1);
	b[1]=1,b[k+1]=n+1;
	for(int i=1;i<k;i++) printf("%d",b[i+1]-b[i]);
	printf("%d\n",b[k+1]-b[k]);
	return 0; 	
}

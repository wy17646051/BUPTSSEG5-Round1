#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=100000;
int n,b,c;
int a[maxn];
int judge(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=b){
			a[i]=0;
			sum++;
			a[i+1]+=c;
			sort(a+i+1,a+n+1);
		}
		else{
			a[i]-=b;
			a[i]+=c;
			sort(a+i,a+n+1);
			if(a[i]>b && b<=c) return sum;
		}
	}
	return sum;
}
int main(){
	while(scanf("%d%d%d",&n,&b,&c)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		if(b>c){
			printf("%d\n",n);
			continue;
		}
		sort(a+1,a+n+1);
		int w=judge();
		printf("%d\n",w);
	}
	return 0;
}

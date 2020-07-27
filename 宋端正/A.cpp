#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		LL n,x,y;
		scanf("%lld%lld%lld",&n,&x,&y);
		if(2*x<=y)
		{
			printf("%lld\n",n*x);
		}
		else
		{
			LL t=n%2;
			if(n%2==0)
			{
				printf("%lld\n",n/2*y);
			}
			else
			{
				printf("%lld\n",n/2*y+(n%2)*x);
			}
		}
	}
	return 0;
}
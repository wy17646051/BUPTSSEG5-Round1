#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		LL n;
		scanf("%d",&n);
		LL m=n/2;
		//cout<<m<<endl;
		LL sum=0;
		for(LL i=1;i<=m;i++)
		{
			sum+=i*i;
			
		}//cout<<sum<<endl;
		printf("%lld\n",sum*8);
	}
	return 0;
}
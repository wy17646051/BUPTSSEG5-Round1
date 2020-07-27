#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=105;
LL a[N],sum[N];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<3;i++)
        	sum[i]=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
            sum[a[i]%3]++;
        }
		LL ans=sum[0];
		if(sum[1]<=sum[2])
		{
			sum[2]-=sum[1];
			ans+=sum[1]+sum[2]/3;
			sum[1]=0;
			
		}
		else 
		{
			sum[1]-=sum[2];
			ans+=sum[2]+sum[1]/3;
			sum[2]=0;
		}
		printf("%lld\n",ans);
        
    }
    return 0;
}

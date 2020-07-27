#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int a[N],cha[N];
int n;
int res=1e9,temp=0;
void cal(int i,int j,int t)
{

    if(t==n+1)
    {
        res=min(temp+abs(j),res);
        return ;
    }

    for(int k=-1; k<=1; k++)
    {
        if(cha[t-1]-i+j==cha[t]-j+k)
        {
            temp=abs(i)+abs(j);
            cal(j,k,t+1);
        }
    }

    return ;

}

int main()
{

    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        if(i>1)cha[i]=a[i]-a[i-1];
    }
    if(n<=2)
        printf("0\n");
    else
    {

        for(int i=-1; i<=1; i++)
        {
            for(int j=-1; j<=1; j++)
            {
                for(int k=-1; k<=1; k++)
                {
                    if(cha[2]+i+j==cha[3]-j+k)
                    {
                        temp=abs(i)+abs(j);
                        cal(j,k,4);
                    }
                }
            }
        }
        if(res==1e9) res=-1;
        printf("%d\n",res);
    }




    return 0;
}


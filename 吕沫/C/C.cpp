//大体思路：//该题为多源bfs 
//从每个圣诞树左右进行扩展，选取优先近的点
//做法：每个点设一个坐标id，扩展方向f（+-1），扩展距离s，把每个点放到优先队列里，按照s小的在顶端，
//map记录以下扩展过的点，依次从顶端取点扩展就好了。
//每个人肯定去挨着圣诞树找自己的位置，这样的话，我们就bfs去找每个人的位置。
//这样的话既保证了圣诞树离自己是最近的，而且还可以求出距离以及每个人所处的位置。
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=500000;
struct Node{
	ll k,f,s;
	friend bool operator < (Node n1,Node n2){
		return n1.s>n2.s;
	}
}a[maxn];
map<ll,ll>mp;
ll n,m;
priority_queue <Node> q;
ll ans[maxn];
void solve(){
	ll s=0;
	for(ll i=1;i<=m;i++){
		Node u = q.top();
		q.pop();
		while(mp.count(u.k+u.f*u.s)!=0){
			u=q.top();
			q.pop();
		}
		ans[i]=u.k+u.f*u.s;
		s+=u.s;
		mp[ans[i]]=1;
		u.s+=1;
		q.push(u);
	}
	printf("%lld\n",s);
	for(ll i=1;i<=m;i++){
		printf("%lld",ans[i]);
		if(i==m) printf("\n");
		else printf(" ");
	}
}
int main(){
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++){
			ll x;
		    scanf("%lld",&x);
		    mp[x]=1;
		    q.push({x,1,1});
		    q.push({x,-1,1});	
    }
	solve();
	
}

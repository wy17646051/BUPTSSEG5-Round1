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

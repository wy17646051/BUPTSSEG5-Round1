#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

typedef long long LL;

using namespace std;

const int N=5010;
int st[N];
int a[N][N];
int n,m,s;

int isSec(){
    for(int i=1;i<=n;i++){
        if(st[i]==0){
            return i;
        }
    }
    return -1;
}

void dfs(int p){
    st[p]=1;

    for(int i=1;i<=n;i++){
        if(st[i]==1) continue;
        if(a[p][i]==0) continue;
        dfs(i);
    }
}


int main(){
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        a[u][v]=1;
    }

    int res=0;
    while(1){
        memset(st,0,sizeof st);
        dfs(s);
        int tmp=isSec();
        if(tmp==-1) break;
        a[s][tmp]=1;
        res++;
    }

    cout<<res;



    return 0;
}

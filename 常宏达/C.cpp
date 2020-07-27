#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

typedef long long LL;

using namespace std;

int t;
int n;


int main(){
    cin>>t;
    while(t--){
        cin>>n;
        int mid=n/2+1;
        LL res=0;
        for(int i=1;i<mid;i++){
            res+=(LL)i*(LL)(i-1)+(LL)(mid-i)*((LL)(i-1)*2+1);
        }
        res=4*res;
        res+=2*(LL)mid*(LL)(mid-1);
        cout<<res<<endl;
    }

    return 0;
}

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

typedef long long LL;

using namespace std;

int q;
LL n,a,b;

int main(){
    cin>>q;
    while(q--){
        cin>>n>>a>>b;

        double unitA=a/1.0;
        double unitB=b/2.0;

        LL res=0;
        if(unitA<=unitB) {
            res+=n*a;
        } else {
            res+=(LL)(n/2)*b;
            res+=(LL)(n%2)*a;
        }

        cout<<res<<endl;

    }

    return 0;
}

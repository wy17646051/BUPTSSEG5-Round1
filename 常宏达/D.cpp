#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

typedef long long LL;

using namespace std;

const int N=100010;
int b[N];
int n;
int tp[N];

int getNum(int b0,int b1){
    memcpy(tp,b,sizeof b);
    int res=0;
    if(tp[0]!=b0){
        tp[0]=b0;
        res++;
    }
    if(tp[1]!=b1){
        tp[1]=b1;
        res++;
    }
    int div=tp[1]-tp[0];
    for(int i=2;i<n;i++){
        if(tp[i]-tp[i-1]!=div){
            if(abs(tp[i]-tp[i-1]-div)<=1){
                res++;
                tp[i]=tp[i-1]+div;
            }
            else return -1;
        }
    }
    return res;

}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    if(n<=2){
        cout<<0;
        return 0;
    }

    int res=2*N;
    int b0,b1;

    int d0[3]={0,1,-1};
    int d1[3]={0,1,-1};

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            b0=b[0]+d0[i];
            b1=b[1]+d1[j];
            int tmp=getNum(b0,b1);
            if(tmp!=-1){
                res=min(res,tmp);
            }
        }
    }

    if(res==2*N){
        cout<<-1;
    } else{
        cout<<res;
    }


    return 0;
}

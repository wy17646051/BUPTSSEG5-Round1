#include<cstdio>
#include<algorithm>
using namespace std;
//task2
#define MaxSize 200010
int arr[MaxSize];

int main(void){
    int t,n,k,x,single,maxCount;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0; i < MaxSize; ++i){
            arr[i] = 0;
        }
        for(int i = 0; i < n; ++i){
            scanf("%d",&k);
            arr[k]++;
        }
        single = 0; 
        x = 0;
        maxCount = 0;
        for(int i = MaxSize - 1; i >= 0; --i){
            if(arr[i] == 0) continue;
            maxCount = max(arr[i],maxCount);
            single++;
        }
        if(maxCount <= single - 1){
            x  = maxCount;
        }else{
            x = single > n / 2 ? n / 2 : single;
        }
        printf("%d\n",x);
    }
    return 0;
}
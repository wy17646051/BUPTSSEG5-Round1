#include <stdio.h>
//wrong answer on test 3
int main() {
    int a[150010],number,i,temp,result=0;
    scanf("%d",&number);
    for(i=0;i<number;i++){
        scanf("%d",&temp);
        a[temp]++;
    }
    for(i = 1;i<=number;i++){
        if(a[i]==1){
            result++;
            continue;
        }

        if(a[i]>=2){
            if(a[i]==2){
                if(i>1&&i<number){
                    result++;
                    if(a[i-1]==0){
                        result++;
                        continue;
                    }
                    else if(a[i+1]==0){
                        a[i+1]++;
                        continue;
                    }
                }
                else if(i==1){
                    if(a[i+1]==0){
                        a[i+1]++;
                    }
                    result++;
                    continue;
                }
                else if(i==number){
                    if(a[i-1]==0){
                        a[i-1]++;
                        result++;
                    }
                    result++;
                    continue;
                }
            }
            else{
                if(i>1&&i<number){
                    if(a[i-1]==0){
                        result++;
                    }
                    if(a[i+1]==0){
                        a[i+1]++;
                    }
                    result++;
                    continue;
                }
                else if(i==1){
                    if(a[i+1]==0){
                        a[i+1]++;
                    }
                    result++;
                    continue;
                }
                else if(i==number){
                    if(a[i-1]==0){
                        a[i-1]++;
                        result++;
                    }
                    if(a[i]==2){
                        result++;
                    }
                    else if(a[i]>2){
                        result+=2;
                    }
                    continue;
                }
            }
        }
    }
    printf("%d",result);
}
#include<stdio.h>

int main(void){
    int t,s;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&s);
        int sum = 0;
        while(s > 9){
            sum += s / 10 * 10;
            s = s / 10 + s % 10;
        }
        sum += s;
        printf("%d\n",sum);
    }
    return 0;
}
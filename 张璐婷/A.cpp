#include<stdio.h>
//task7
int main(void){
    int n,m;
    scanf("%d %d",&n,&m);
    if(m % n != 0){
        printf("%d\n",-1);
        return 0;
    }
    int k = m / n;
    int count = 0;
    while(k % 2 == 0){
        k = k / 2;
        count++;
    }
    if(k % 3 == 0){
        while(k != 1){
            k /= 3;
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
#include <stdio.h>

int main() {
    int number,a,b,result;
    int cases[10010];
    int i=0;
    scanf("%d",&number);
    for(int i = 0 ; i<number ; i++){
        scanf("%d",&cases[i]);
    }
    for(i = 0 ; i < number ; i++){
        result=0;
        while(cases[i]>=10){
            a = cases[i]%10;
            b = cases[i]/10;
            result+=b*10;
            cases[i]=a+b;
        }
        result+=cases[i];
        printf("%d\n",result);
    }
}

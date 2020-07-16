#include <stdio.h>
//test 5 run out of time limit
int main() {
    int n,m,result=1,temp;
    scanf("%d%d",&n,&m);
    int i=0;
    if(n==m){
        printf("0");
    }
    else if(m%n==0){
        temp=m/n;
        while(i==0) {
            if (temp % 3 == 0) {
                temp = temp / 3;
                result++;
                if (temp == 3) {
                    i++;
                }
            }
            else if(temp%2==0){
                temp=temp/2;
                result++;
                if(temp==2){
                    i++;
                }
            }
        }
        printf("%d",result);
    }
    else{
        printf("-1");
    }

}

#include <stdio.h>
//test 5 run out of time limit
//主要思路为先判断m能不能被n整除，如果可以才可能有结论，如果不行返回-1，如果n=m则返回0
//如果能被整除，则让m除n，再让计算后的商被3和2相除，根据上面的判断，这里m除n一定能整除
//利用while循环把商一次一次整除，直到不能被整除位置，每次循环计数+1，最终计数为结论

int main() {
    int n,m,result=1,temp;
    scanf("%d%d",&n,&m);
    int i=0;
    if(n==m){//判断是否相等，相等返回0
        printf("0");
    }
    else if(m%n==0){//判断能否整除
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
        printf("%d",result);//返回计数即结论
    }
    else{//不能整除，返回-1
        printf("-1");
    }

}


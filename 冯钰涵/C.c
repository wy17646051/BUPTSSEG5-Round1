#include <stdio.h>

int main() {
    int number,i,j,tempnum,tempb=0,indexb=0,total,most;
    int a[200010],b[200010],d[100010];//a for case info, b for skill occurence,
    scanf("%d",&number);
    for(i=0;i<number;i++){
        scanf("%d",&a[i]);
        d[i]=indexb;
        for(j=1;j<=a[i];j++){
            scanf("%d",&tempnum);
            b[indexb+tempnum-1]++;
        }
        indexb+=a[i];
    }
    for(i = 0 ; i < number;i++){
        if(a[i]>1&&a[i]<=3){
            printf("1\n");
            continue;
        }
        else if(a[i]==1){
            printf("0\n");
            continue;
        }
        else{
            most=0;
            total=0;
            for( j =d[i]  ; j < (a[i]+d[i]) ; j++){
                if(b[j]!=0){
                    total++;
                }
                if(b[j]>=most){
                    most=b[j];
                }
            }
            if(total<most){
                printf("%d\n",total);
            }
            else if(total==most){
                printf("%d\n",(most-1));
            }
            else if(total>most){
                printf("%d\n",most);
            }
        }
    }

}

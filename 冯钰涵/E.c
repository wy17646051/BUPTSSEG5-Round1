#include <stdio.h>
//wrong answer on test 3

int main() {//主要思路是，用数组表示每个重量的人数，尽量增重和减重分配让数组中0元素的个数降到最少，结论为数组中不为0的个数（可能包含150001重量）。
    int a[150010],number,i,temp,result=0;
    scanf("%d",&number);
    for(i=0;i<number;i++){//数组a【】用来存储每一种重量有多少人，比如a【3】=10意味着重量3的人数为10
        scanf("%d",&temp);
        a[temp]++;
    } 
    //遍历数组，当当前重量有人时，结论加1，若遍历过的元素之前为0，在之后的减重操作中变为1，结论加1，对未遍历到的元素进行操作，结论不变
    for(i = 1;i<=number;i++){
        if(a[i]==1){//如果该重量的人数是1，结论加1，继续下一个循环
            result++;
            continue;
        }

        if(a[i]>=2){//如果该重量人数大于1，需分类套路
            if(a[i]==2){//如果人数为2，需要看能不能将另一个人增重或减重
                if(i>1&&i<number){ //根据题目要求，重量不能为0，如果该人重量不为1或最大值
                    result++;
                    if(a[i-1]==0){//查看这个人减重后的重量人数是否为0，如果是，减重，结论+1，进入下一个循环
                        result++;
                        continue;
                    }
                    else if(a[i+1]==0){//查看这个人增重后的重量人数是否为0，如果是，增重，结论暂时不变
                        a[i+1]++;
                        continue;
                    }
                }
                else if(i==1){//如果这个人重量为1，只看能不能增重
                    if(a[i+1]==0){
                        a[i+1]++;
                    }
                    result++;
                    continue;
                }
                else if(i==number){//这里有bug，因为可以超出上限，所以这里一定可以增重，这里结论一定可以加1
                    if(a[i-1]==0){//40行到44行应删除，改为result+=2；
                        a[i-1]++;
                        result++;
                    }
                    result++;//因为该重量人数不为0，结论一定可以加1
                    continue;
                }
            }
            else{//如果该重量人数大于等于3，我们需要看我们能给几个人增重，至多2人，最少0人
                if(i>1&&i<number){//同上，只不过同时看增重和减重能不能进行
                    if(a[i-1]==0){
                        result++;
                    }
                    if(a[i+1]==0){
                        a[i+1]++;
                    }
                    result++;
                    continue;
                }
                else if(i==1){//同上，只能增重，最多增重1人，无人能减重
                    if(a[i+1]==0){
                        a[i+1]++;
                    }
                    result++;
                    continue;
                }
                else if(i==number){//这里因为一定可以增重，所以只看能不能减重
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
                //reuslt++;
                //这里应该result++，忘记写了，是个bug，时间不够没有发现
            }
        }
    }
    printf("%d",result);
}

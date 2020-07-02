
#include<cstdio>
#include<algorithm>
using namespace std;

int a[101]; //存放所有的待交换的数
int p[101]; // 位置数组

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
        }
        for(int j = 1;j <= m;j++){
            scanf("%d",&p[j]);
        }
        sort(p + 1,p + m + 1);  //将位置数组排序，得到最大与最小位置
        sort(a + p[1],a + p[m]);  //将最大与最小之间的数排序 这里考虑欠缺了，默认将最小与最大位置之间当成连续的，导致后来结果有问题
        bool flag = false;
        if(p[1] > 1){
            for(int i = 1;i < p[1];i++){ //若最小交换位置大于1，且其小于最小交换位置的不能交换到所有数存在降序，则输出NO；
                if(a[i] > a[i + 1]){
                    flag = true;
                    break;
                }
            }
        }
        if(p[m] < n - 1){
            for(int i = n;i > p[m];i--){  //若最大交换位置小于倒数第二个，且其大于最大交换位置的不能交换到所有数存在降序，则输出NO； 
                if(a[i] < a[i - 1]){
                    flag = true;
                    break;
                }
            }
        }
        if(flag == false){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}

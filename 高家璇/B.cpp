#include <stdio.h> 
int main(){
	int count;
	scanf("%d\n",&count);
	int array[10000];
	int getarray[10000];
	int i;
	for(i=0;i<count;i++){
		scanf("%d",&array[i]);
		int tmp=array[i];
		int x=tmp;
		int sum=0;
		while(x%10!=x){
			sum=(x-(x%10))+sum;
			x=(x-(x%10))/10+x%10;
		}
		getarray[i]=sum+x;
	}
	for(i=0;i<count;i++){
		printf("%d\n",getarray[i]);
	}
	
}

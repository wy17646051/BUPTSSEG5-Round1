#include <stdio.h>
int main(){
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int count=0;
	if(m%n==0){
		int get=m/n;
		while(get%2==0){
			get=get/2;
			count++;
		}
		while(get%3==0){
			get=get/3;
			count++;
		}
		if(get==1){
			printf("%d",count);
		}else{
			printf("-1");
		}
		
	}else{
		printf("-1");
	}
} 

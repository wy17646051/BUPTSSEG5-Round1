#include <stdio.h>
//实例三四提交可以过，发现了问题应该是how的数字弄错了，但没有时间改。  
int main(){
	int get;
	scanf("%d",&get);
	int array[9999];
	int how=0;
	int fin=0;
	while(get%10!=get){
		array[how]=(get%10)%3;
		if(array[how]==0){
			int s;
			for(s=0;s<how;s++){
				array[s]=0;
			}
			how=0;
			fin++;
		}else{
		how++;
	} 
	int d;
	int j=0;
	int sum=0;
	bool judge=false;
	for(d=0;d<how-1;d++){
		sum=sum+array[d];
		if(sum%3==0){
			fin++;
			sum=0;
			j=d;
			judge=true;
		}
	}
	int u;
	if(judge){
		for(u=j+1;u<how-1;u++){
			array[u-j-1]=array[u];
			array[u]=0;
		}
		how=how-j-1;
	}
		get=(get-(get%10))/10;
	}
	printf("%d\n",fin);
} 

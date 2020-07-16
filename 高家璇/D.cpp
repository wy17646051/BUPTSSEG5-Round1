#include <stdio.h>
//实例三四提交可以过，发现了问题应该是how的数字弄错了，但没有时间改。  
//本题的主要思路是从后向前，将每一个位数上的数字单独打出，然后模3，如果等于零则直接给总数结果加1
//剩下以0进行分割，两个0之间被割成一组，对于每一个被分割的组，可以从第一个数字开始如果该数字为1则找到与其位置最近的一个2，
//如果中间的1的位数连续有三位则 直接将这三个1变为0，并给结果加以，然后再次用0分片 ，若其中没有超过三位连续的1，则检验该片段
//从开始的1到最近的2相加模3等于几，如果等于2则除去结尾的2，将前面的化为0，分片并将结果加1，如果等于1则减1，化0，分片，结果加一，
//如果等于0，则将这些都化为0，分片，结果加一。如果开头为2则用相同的原理整合，直到最后所有均为0得到结果
//由于时间原因没有写完，只写了一部分 
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

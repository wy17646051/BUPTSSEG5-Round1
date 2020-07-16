#include <stdio.h>
struct carray{
	int number;
	int count;
};
//老师这道题我的思路是找出每一个test中重复的数的最大次数和一共有多少不同的数，比较两个大小，
//谁更小答案就是谁，如果相同则减1就是答案，示例的test过了，可是OJ过不了
//老师我不知道我理解的题对不对，我的理解是，第一组不能有重复数字，第二组必须都是一样的数字。
int main(){
	int count;
	int ans[10000];
	scanf("%d",&count);
	int i;
	for(i=0;i<count;i++){
		int get;
		scanf("%d",&get);
		int s;
		int array[10000];
		int tmp[10000];
		struct carray countarray[10000];
		
		for(s=0;s<get;s++){
			scanf("%d",&array[s]);//得到输入的test数 
		}
		int gg;
		bool isHave=false;
		for(s=0;s<get;s++){
			int l;
			for(l=0;l<gg;l++){
				if(array[s]!=tmp[l])
				{
					isHave=false;
				}else{
					isHave=true;
					break;
				}
			}
			if(!isHave)
			{
			tmp[gg]=array[s];
			gg++;
		}
		}
		//以上代码得到gg，gg为不同的数字有多少个
		isHave=false;
		int mm=0;
		for(s=0;s<get;s++){
			int l;
			bool fin=true;
			for(l=0;l<mm;l++){
				if(array[s]!=countarray[l].number)
				{
					isHave=false;
				}else{
					countarray[l].count=countarray[l].count+1;
					fin=false;
				}
			}
			if((!isHave)&&fin)
			{
			countarray[mm].number=array[s];
			countarray[mm].count=1;
			mm++;
		}
		}
		int max=0;
		for(s=0;s<mm;s++){
			if(countarray[s].count>=max){
				max=countarray[s].count;
			}
		}
		//以上代码得到max，max为最大的有重复的数字的次数 
		if(max>gg){
			ans[i]=gg;
		}
		if(max<gg)
		{
			ans[i]=max;
		}
		if(max==gg){
			ans[i]=max-1;
		}
		//选择max和gg中较小的作为答案，如果两个相等则减1作为答案 
			int r;
		for(r=0;r<=get;r++){
			array[r]=0;
			tmp[r]=0;
			countarray[r].count=0;
			countarray[r].number=0;
			s=0;
			get=0;
			gg=0;mm=0;
		}
              //初始化各个变量。 
	}
	for(i=0;i<count;i++){
		printf("%d\n",ans[i]);
	}
}

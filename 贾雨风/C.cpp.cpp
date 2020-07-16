#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int a[n];
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		sort(a,a+n);
		int maxcount=0;
		int temp=0;
		int repeat[n];
		for(int j=0;j<n;j++){
			repeat[j]=0;
		}
		for(int j=0;j<n;j++){
			int count=0;
			for(int k=j+1;k<n;k++){
				if(a[k]==a[j]){						//计算重复的个数 
					count++;
					j=k-1;
				}	
			}
			if(count>maxcount){					
				maxcount=count+1;
				temp=j;
			}
			repeat[j]=count+1;					//计算每个有重复的数的总个数 
		}
		int sum=0;
		int tag=0;
		for(int j=0;j<n;j++){					//计算总个数和 
			sum=repeat[j]+sum;
			if(repeat[j]!=0){
				tag++;							//有一个重复的就加1 
			}
		}
		int Nrepeat=n-sum+tag;					//计算出数组里面不重复的数字个数 
		if(Nrepeat==maxcount){					//相等则为最大值-1 
			cout<<maxcount-1<<endl;
		}
		else if(Nrepeat<maxcount){				//不重复的数字小则输出不重复的数字 
			cout<<Nrepeat<<endl;
		}
		else{
			cout<<maxcount+1<<endl;				//重复的小则输出重复的+1 
		}
	}
}

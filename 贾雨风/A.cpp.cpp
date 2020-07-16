#include<bits/stdc++.h>						//可以通过前六个测试用例 
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int count=0;
	if(n==m){								//判断相等输出0 
		cout<<0<<endl;
	}
	else{
		if(m%n!=0){							//如果m不是n的倍数 则无法做到 
			cout<<-1<<endl;
		}
		else{
			int temp=m/n;				//取由2和3组成的倍数 
			for(int i=0;i<1;i--){
				if(temp/3==0){			//不断除以3跳出乘3的个数 
					break;
				}
				if(temp%3==0){
					temp=temp/3;
					count++;
				}
				else{
					break;
				}
			}
			for(int i=0;i<1;i--){	//不断除以2跳出乘2的个数
				if(temp/2==0){
					break;
				}
				if(temp%2==0){
					temp=temp/2;
					count++;
				}
				else{
					break;
				}
			}
			cout<<count<<endl;	//最后输出乘2乘3一共的个数 
		}
	}
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int spend=0;
		int s;
		cin>>s;
		if(s/10==0){
			spend=spend+s;
		}
		if(s/10!=0){
			for(int i=0;i<1;i--){
				int temp=s/10;
				s=s-temp*10+temp;
				spend=spend+temp*10;
				if(s/10==0){
					spend=spend+s;
					break;
				}
			}
		}
		cout<<spend<<endl;
	}
}

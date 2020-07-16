#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX_N 200000 + 5
using namespace std;

char str[MAX_N];

// past test1-8
int main(void)
{
	cin>>str;
	
	int n = strlen(str);
	int sum = 0;
	int cnt = 0;
	int cnt_x = 0;
	for (int i = 0; i < n; i++) {
		sum += (str[i] - '0');
		if (str[i] - '0' == 0) cnt_x++;
		if (sum % 3 == 0) {
			sum = 0;
			
			if (cnt_x > 1) cnt += cnt_x;
			else cnt++;
			
			cnt_x = 0;
		}
	}
	cnt += cnt_x; 
	cout<<cnt<<endl;
	return 0;
}

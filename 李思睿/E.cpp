#include<iostream>
#include<algorithm>
#include<cstring>
#define MAX_N 200000 + 5
using namespace std;

int a[MAX_N] = {0};
int b[MAX_N] = {0};
int v[MAX_N] = {0};


// pass: test1 test2
int main(void)
{
	int n;
	cin>>n;
	memset(b, 0, sizeof(b));
	memset(v, 0, sizeof(v));
	for (int i = 0; i < n; i++) {
		cin>>a[i];
		b[a[i]]++;
	}
	
	sort(a, a + n);
	int m = unique(a, a + n) - a;
	
	v[0] = 1;
	for (int i = 0; i < m; i++) {
		v[a[i]] = 1;
		if (b[a[i]] >= 3) {
			v[a[i] - 1] = 1;
			v[a[i] + 1] = 1;
		} else if (b[a[i]] == 2) {
			if (v[a[i] - 1] == 0) v[a[i] - 1] = 1;
			else if (v[a[i] + 1] == 0) v[a[i] + 1] = 1;
		}
	}
	
	int cnt = 0;
	for (int i = 1; i <= 150001; i++) {
		if (v[i] > 0) cnt++;
	}
	cout<<cnt<<endl;
	
	return 0;
}

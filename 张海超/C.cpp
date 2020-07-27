#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<cctype>
#include<algorithm>
using namespace std;
int main() {
	int t;

	cin >> t;
	while (t--) {
		long long n;
		long long a = 0;
		cin >> n;
		long long num = n/2;
		for (long long i = n; num; i-=2,num--) {
			a += num * (long long)(i * 4 - 4);
		}
		printf("%lld\n", a);
	}
	return 0;
}
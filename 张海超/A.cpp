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
	int q,a,b;
	long long n;
	cin >> q;
	while (q--) {
		long long sum = 0;
		cin >> n >> a >> b;
		if (n % 2 == 1) {
			sum += a;
			n--;
		}
		if (a <= b/2) {
			sum += n * a;
		}
		else {
			sum += n / 2 * b;
		}
		printf("%lld\n", sum);
	}
}
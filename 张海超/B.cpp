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
	int dp[3];
	cin >> t;
	while (t--) {
		dp[0] = 0;
		dp[1] = 0;
		dp[2] = 0;
		int n;
		cin >> n;
		int sum = 0;
		long long tem;
		for (int i = 0; i < n; i++) {
			
			cin >> tem;
			if (tem%3 == 0) {
				sum++;
			}
			else {
				dp[tem % 3]++;
			}
		}
		int b = min(dp[1], dp[2]);
		sum += b;
		dp[1] -= b;
		dp[2] -= b;
		if (dp[1]) {
			sum += dp[1] / 3;
		}
		if (dp[2]) {
			sum += dp[2] / 3;
		}
		printf("%d\n", sum);
	}
	return 0;
}
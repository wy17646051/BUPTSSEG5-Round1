#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int res = 0, left;
		while(true) {
			res += n / 10 * 10;
			n = n % 10 + n / 10;
			left = n % 10;
			if(n < 10) break;
		}
		cout << res + left << endl;
	}
	return 0;
}

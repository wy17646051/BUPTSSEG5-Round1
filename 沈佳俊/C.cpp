#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int a[N];

int main() {
	int n, t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int same, diff;
		same = diff = 1;
		int maxs = 0;
		for(int i = 1; i < n; i++) {
			if(a[i] == a[i - 1]) same++;
			else {
				diff++;
				if(same > maxs) maxs = same;
				same = 1;
			}
		}
		if(same > maxs) maxs = same;
		if(maxs < diff) cout << maxs << endl;
		else if(maxs == diff) cout << maxs-1 << endl;
		else cout << diff << endl;
	}
	return 0;
}

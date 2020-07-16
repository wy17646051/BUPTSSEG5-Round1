// 通过大部分样例， test9超时 
#include <bits/stdc++.h>
using namespace std;

const int N = 5e7;
bool vis[N];
int cnt;
int res;

void dfs(int n, int m) {
	//if(n > m) return;
	if(n == m) {
		res = cnt;
		return;
	}
	int k;
	for(int i = 0; i < 2; i++) {
		if(i == 0) k = n * 2;
		else k = n * 3;
		if(!vis[k] && k <= m) {
			vis[k] = true;
			cnt++;
			dfs(k, m);
			cnt--;
			vis[k] = false;
		}
	}	
}

int main() {
	int n, m;
	cin >> n >> m;
	// memset(vis, false, sizeof(vis));
	if(n == m) cout << 0;
	else {
		dfs(n, m);
		if(res == 0) cout << -1;
		else cout << res;
	}
		
	return 0;
}

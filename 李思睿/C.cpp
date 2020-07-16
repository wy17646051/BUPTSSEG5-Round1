#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX_N 200000 + 5
using namespace std;

int a[MAX_N] = {0};
int b[MAX_N] = {0};

int main(void)
{
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		memset(b, 0, sizeof(b));
		int max_b = 0;
		for (int i = 0; i < n; i++) {
			cin>>a[i];
			b[a[i]]++;
			if (b[a[i]] > max_b) max_b = b[a[i]];
		}
		sort(a, a + n);
		int m = unique(a, a + n) - a;
		if (m == max_b) cout<<m - 1<<endl;
		else if (m < max_b) cout<<m<<endl;
		else cout<<max_b<<endl;
	}
	return 0;
}

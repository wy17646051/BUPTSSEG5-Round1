#include<iostream>
using namespace std;

int main(void)
{
	int n, m;
	while(cin>>n>>m) {
		if (m % n == 0) {
			int an = m / n;
			int cnt = 0;
			while(an % 2 == 0) {
				an /= 2;
				cnt++;
			}
			while(an % 3 == 0) {
				an /= 3;
				cnt++;
			}
			if (an == 1) cout<<cnt<<endl;
			else cout<<"-1"<<endl;
		} else {
			cout<<"-1"<<endl;
		}
	}
	return 0;
}

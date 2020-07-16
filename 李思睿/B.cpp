#include<iostream>
using namespace std;

int main(void)
{
	int n;
	while(cin>>n) {
		for (int i = 0; i < n; i++) {
			long long x;
			cin>>x;
			long long sum = 0;
			while (x >= 10) {
				sum += x / 10 * 10;
				x = x / 10 + x % 10;
				
			}
			cout<<sum + x<<endl;
		}
	}
	return 0;
}

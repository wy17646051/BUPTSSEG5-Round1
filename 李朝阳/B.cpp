#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t,s,x;
	while(cin >> t)
	{
		for(int i=0;i<t;i++)
		{
			ll cost=0;
			cin >> x;
			while(x>0)
			{
				if(x>=10)
				{
					cost+=x-(x%10);
					x=x/10+x%10;
				}
				else
				{
					cost += x;
					x=0;
				}
			}
			cout << cost << endl;
		}
	}
}


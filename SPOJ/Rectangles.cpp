#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int i,j;
	int count=0;
	for(i=1;i<=sqrt(n);i++)
	{
		for(j=i+1;i*j<=n;j++)
			count++;
	}
	count += sqrt(n);
	cout << count << endl;
	return 0;
}

/*
 Author : Vinay Garg
 Description : Find the missing number
*/
#include <bits/stdc++.h>
using namespace std;

int getMissingNo(int c[], int n)
{
    int i, total;
    total  = n*(n+1)/2;
    for (i = 0; i<n-1; i++)
       total -= c[i];
    return total;
}

int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int c[n-1];
	    for(int i=0; i<n-1; i++)
            cin>>c[i];
        int mNum = getMissingNo(c,n);
        cout<<mNum<<"\n";
	}
	return 0;
}

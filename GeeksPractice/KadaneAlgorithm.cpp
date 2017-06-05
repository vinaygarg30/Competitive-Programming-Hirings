/*
 Author : Vinay Garg
 Description : Largest Sum Contiguous Sub-array / Kadane Algorithm
*/

#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size)
{
    int curMax,subMaxSum;
    curMax = a[0];
    subMaxSum = a[0];
    for(int i=1;i<size;i++){
        curMax =max(a[i], curMax + a[i]);
        subMaxSum =max(curMax,subMaxSum);
    }
    return subMaxSum;
}

int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int maxSum = maxSubArraySum(a, n);
        cout <<maxSum<<"\n";
	}
	return 0;
}

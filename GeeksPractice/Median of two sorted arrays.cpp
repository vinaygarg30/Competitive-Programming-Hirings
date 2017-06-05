/*
 Author : Vinay Garg
 Description : Median of two sorted arrays
*/

#include <bits/stdc++.h>
using namespace std;
long int res[2005];

void getMedian(long int a[], long int b[], int n)
{
    long int i=0,j=0,k=0;
    for(;i<n&&j<n;)
    {
        if(a[i]==b[j])
        {
            res[k++] = a[i++];
            res[k++] = b[j++];
        }
        else if(a[i]<b[j])
             res[k++]=a[i++];
        else
             res[k++]=b[j++];
    }
    while(i<n)
        res[k++] = a[i++];
    while(j<n)
    res[k++] = b[j++];
}

int main(){
    int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    long int a[n];
	    for(int i=0; i<n; i++)
            cin>>a[i];
        long int b[n];
	    for(int i=0; i<n; i++)
            cin>>b[i];
    getMedian(a, b, n);
    cout<<res[n-1] + res[n]<<"\n";
	}
    return 0;
}

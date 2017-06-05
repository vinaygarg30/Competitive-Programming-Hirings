/*
 Author : Vinay Garg
 Description : Reverse an array
*/

#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(){
    int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)
            cin>>a[i];
        reverseArray(a,0,n-1);
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";

	}
    return 0;
}

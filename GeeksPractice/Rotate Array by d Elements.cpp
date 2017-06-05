/*
 Author : Vinay Garg
 Description : Rotate an array by d elements
*/

#include <bits/stdc++.h>
using namespace std;
void leftRotatebyOne(int arr[], int n);

void leftRotate(int arr[], int d, int n)
{
  int i;
  for (i = 0; i < d; i++)
    leftRotatebyOne(arr, n);
}

void leftRotatebyOne(int arr[], int n)
{
  int i, temp;
  temp = arr[0];
  for (i = 0; i < n-1; i++)
     arr[i] = arr[i+1];
  arr[i] = temp;
}

int main(){
    int t,n,d;
	cin>>t;
	while(t--){
	    cin>>n>>d;
	    int a[n];
	    for(int i=0; i<n; i++)
            cin>>a[i];
        leftRotate(a, d, n);
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";

	}
    return 0;
}

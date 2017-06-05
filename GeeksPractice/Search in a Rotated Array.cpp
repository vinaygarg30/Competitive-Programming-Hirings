/*
 Author : Vinay Garg
 Description : Search in a Rotated Array
*/

#include <bits/stdc++.h>
using namespace std;
int findPivot(long int[], int, int);
int binarySearch(long int[], int, int, int);

int searchElementInRotatedArray(long int arr[], long int n, int key)
{
   int pivot = findPivot(arr, 0, n-1);

   if (pivot == -1)
       return binarySearch(arr, 0, n-1, key);

   if (arr[pivot] == key)
       return pivot;
   if (arr[0] <= key)
       return binarySearch(arr, 0, pivot-1, key);
   return binarySearch(arr, pivot+1, n-1, key);
}

int findPivot(long int arr[], int low, int high)
{
   if (high < low)  return -1;
   if (high == low) return low;

   int mid = (low + high)/2;
   if (mid < high && arr[mid] > arr[mid + 1])
       return mid;
   if (mid > low && arr[mid] < arr[mid - 1])
       return (mid-1);
   if (arr[low] >= arr[mid])
       return findPivot(arr, low, mid-1);
   return findPivot(arr, mid + 1, high);
}

int binarySearch(long int arr[], int low, int high, int key)
{
   if (high < low)
       return -1;
   int mid = (low + high)/2;
   if (key == arr[mid])
       return mid;
   if (key > arr[mid])
       return binarySearch(arr, (mid + 1), high, key);
   return binarySearch(arr, low, (mid -1), key);
}

int main(){
    int t;
    long int n,k;
	cin>>t;
	while(t--){
	    cin>>n;
	    long int a[n];
	    for(int i=0; i<n; i++)
            cin>>a[i];
        cin>>k;
    int index = searchElementInRotatedArray(a,n,k);
    cout<<index<<"\n";
	}
    return 0;
}

/*
 Author : Vinay Garg
 Description : Nth Fibonacci Number
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin>>t;
	while(t>0){
	    int n,i;
	   long long int a,b,c;
	   long int y;
	    cin>>n;
	    a=b=1;
	    if(n==1||n==2)
	    cout<<a;
	    else{
	    for(i=0;i<n-2;i++){
	        c=a+b;
	        c=c%1000000007;
	        a=b;
	        b=c;
	    }
	    cout<<c;}
	    t--;
	    cout<<endl;
	}
	return 0;
}

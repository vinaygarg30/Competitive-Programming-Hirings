/*
 Author : Vinay Garg
 Description : Mobstac Hiring Challenge
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int pos[n],val[n];
    for(int i=0;i<n;i++)
    {
        cin>>val[i]>>pos[i];
    }
    long long int sol=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
          sol += abs(pos[i]-pos[j])* (max(val[i],val[j]));
        }
    }
    cout<<sol;
    return 0;
}

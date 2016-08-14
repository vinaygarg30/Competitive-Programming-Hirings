#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    while(n) {
        int sol = 0;
        for (int i = 0; i < n; ++i) {
            sol += (n-i)*(n-i);
        }
        printf("%d\n", sol);
        
        scanf("%d", &n);
    }
    
    
    return 0;
}
#include<bits/stdc++.h>
char X[5005],Y[5005];
int dp[5001][2]; 

int max(int a, int b)
{
    return (a > b)? a : b;
}
 
int main()
{
  int t;
  char ch;
  scanf("%d",&t);
  ch=getchar();
  while(t--)
  {
	  scanf("%s",X);
	  int i,j,n=strlen(X);
	  for(i=0;i<n;i++)
		Y[i]=X[n-i-1];
	
	   for (i=0; i<=n; i++)
	   {
	     for (j=0; j<=n; j++)
	     {
	     	if(i==0||j==0)dp[j][1]=0;
	  
	       else if (X[i-1] == Y[j-1])
	         dp[j][1] = dp[j-1][0] + 1;
	  
	       else
	         dp[j][1] = max(dp[j][0], dp[j-1][1]);
	     }
	     for(j=0;j<=n;j++)
	     {
	     	dp[j][0]=dp[j][1];
	     }
	   }
	   printf("%d\n",n-dp[n][0]);
  }
  return 0;
}
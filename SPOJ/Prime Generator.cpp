#include <stdio.h>
using namespace std;
int main(void) {
	// your code goes here
	 int t,b,i,j,flag,i1;
      long int m,n;
      scanf("%d",&b);
      while(b)
      {
      	scanf("%ld %ld",&m,&n);
        for(i=m;i<=n;i++)
      	{
      	   flag=0;
      	   if(i==1)
      	   continue;
      	   for(j=2;j<=i/j;j++)
      	   	{
      	      if(i%j==0)
      		  {
      		     flag=1;
      		     break;
      		  }
             
         	}
         	if(flag==0)
         	
         	printf("%d\n",i);
      	}
b--;
printf("\n");
}
return 0;
}

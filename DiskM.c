
#include <stdio.h>
#include<stdlib.h>
int main()
{
  int i,n,req[50],mov=0,cp;
  printf("Enter the current position\n");
  scanf("%d",&cp);
  printf("enter the number of requests\n");
  scanf("%d",&n);
  printf("Enter the request order\n");
  for (i=0;i<n;i++){
  scanf("%d",&req[i]);
  
  
}
mov=mov+abs(cp-req[0]);
printf("%d->%d",cp,req[0]);
for(i=1;i<n;i++)
{
    mov=mov+abs(req[i]-req[i-1]);
    printf("->%d",req[i]);
    
}
printf("\n");
printf("Total head movement=%d\n",mov);
}
/*
Enter the current position
45
enter the number of requests
5
Enter the request order
30
66
24
75
50
45->30->66->24->75->50
Total head movement=169
*/


#include<stdio.h>
#include<stdlib.h>

int main()
{
    int rq[100],i,j,n,totalheadmovement=0,initial,size,move;
    printf("Enter the no of requests:\n");
    scanf("%d",&n);
    printf("Enter the request sequence\n");
    for ( i = 0; i<n; i++)
    {
        scanf("%d",&rq[i]);
    }
    printf("Enter the initial head position\n");
    scanf("%d",&initial);
    printf("Enter the total disk size\n");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d",&move);

    for ( i = 0; i < n; i++)
    {
       for ( j = 0;j < n-i-1; j++)
       {
        if(rq[j]>rq[j+1])
        {
            int temp =rq[j];
            rq[j]=rq[j+1];
            rq[j+1]=temp;
        }
       }
    }
    int index;
    for ( i = 0; i < n; i++)
    {
      if(initial<rq[i])
      {
        index=i;
        break;
      }
    }
    if(move==1)
    {
       printf("Sequence of request access:\n");
       for ( i = index; i < n; i++)
       {
           printf("%d ",rq[i]);
           totalheadmovement=totalheadmovement+abs(rq[i]-initial);
           initial=rq[i];
       }

       totalheadmovement=totalheadmovement+abs(size-rq[i-1]-1);
       initial=size-1;
       for ( i = index-1; i >=0; i--)
       {
        printf("%d ",rq[i]);
        totalheadmovement=totalheadmovement+abs(rq[i]-initial);
        initial=rq[i];
        
       }
       
       
    }
printf("\nTotal head movement is %d",totalheadmovement);
return 0;
}
/*

Enter the no of requests:
5
Enter the request sequence
1
2
3
4
5
Enter the initial head position
3
Enter the total disk size
5
Enter the head movement direction for high 1 and for low 0
1
Sequence of request access:
453 2 1 
Total head movement is 6
  */
    

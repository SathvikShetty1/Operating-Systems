#include<stdio.h>
void fcfs(int process[],int n,int bursttime[]){
    int waitingtime[n],turnaroundtime[n],totalwaitingtime=0,totalturnaroundtime=0;
    waitingtime[0]=0;
    for(int i=1;i<n;i++){
        waitingtime[i]=bursttime[i-1]+waitingtime[i-1];
        totalwaitingtime+=waitingtime[i];
    }

    for(int i=1;i<n;i++){
        turnaroundtime[i]=bursttime[i]+waitingtime[i];
       totalturnaroundtime+=turnaroundtime[i];
    }
    printf("First come First Served(FCFS)scheduling algorithm\n");
    printf("-------------------\n");
    printf("process\tBurst time\tWaitingtime\tTurnaroundtime\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\n",process[i],bursttime[i],waitingtime[i],turnaroundtime[i]);
    }
    printf("Average waiting time:%.2f\n",(float)totalwaitingtime/n);
     printf("Average Turnaround time:%.2f\n",(float)totalturnaroundtime/n);
     printf("\n");

}
void sjf(int process[],int n,int bursttime[]){
    int waitingtime[n],turnaroundtime[n],completiontime[n],totalturnaroundtime=0,totalwaitingtime=0;
    
    for(int i=0;i<n;i++){
        int shortestjobindex=i;
        for(int j=i+1;j<n;j++){
            if(bursttime[j]<bursttime[shortestjobindex]){
                shortestjobindex=i;
            }

        }
        int temp=bursttime[i];
        bursttime[i]=bursttime[shortestjobindex];
        bursttime[shortestjobindex]=temp;
        temp=process[i];
        process[i]=process[shortestjobindex];
        process[shortestjobindex]=temp;

    }
    waitingtime[0]=0;
    for(int i=1;i<n;i++){
        waitingtime[i]=bursttime[i-1]+waitingtime[i-1];
        totalwaitingtime+=waitingtime[i];
    }
    for(int i=0;i<n;i++){
        turnaroundtime[i]=bursttime[i]+waitingtime[i];
       totalturnaroundtime+=turnaroundtime[i];
    }
    printf("Shortest job First(SJFs)scheduling algorithm\n");
    printf("-------------------\n");
    printf("process\tBurst time\tWaitingtime\tTurnaroundtime\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\n",process[i],bursttime[i],waitingtime[i],turnaroundtime[i]);
    }
    printf("Average waiting time:%.2f\n",(float)totalwaitingtime/n);
     printf("Average Turnaround time:%.2f\n",(float)totalturnaroundtime/n);
     printf("\n");
}
void roundrobin(int process[],int n,int bursttime[],int quantum){
    int remainingtime[n],waitingtime[n],turnaroundtime[n],totalwaitingtime=0,totalturnaroundtime=0;
    for(int i=0;i<n;i++){
        remainingtime[i]=bursttime[i];

    }
    int time=0;
    while(1){
        int allprocessescompleted=1;
        for(int i=0;i<n;i++){
            if(remainingtime[i]>0){
                allprocessescompleted=0;
                if(remainingtime[i]>quantum){
                    time+=quantum;
                    remainingtime[i]=quantum;
                }else{
                    time+=remainingtime[i];
                    waitingtime[i]=time-bursttime[i];
                    remainingtime[i]=0;

                }
            }
        }
        if(allprocessescompleted){
            break;
        }
    }
    for(int i=0;i<n;i++){
        turnaroundtime[i]=bursttime[i]+waitingtime[i];
        totalwaitingtime+=waitingtime[i];
       totalturnaroundtime+=turnaroundtime[i];
    }
    printf("Round Robin scheduling algorithm\n");
    printf("-------------------\n");
    printf("process\tBurst time\tWaitingtime\tTurnaroundtime\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\n",process[i],bursttime[i],waitingtime[i],turnaroundtime[i]);
    }
    printf("Average waiting time:%.2f\n",(float)totalwaitingtime/n);
     printf("Average Turnaround time:%.2f\n",(float)totalturnaroundtime/n);
     printf("\n");

}
int main(){
    int n;
    printf("enter the number of processes");
    scanf("%d",&n);
    int process[n],bursttime[n];
    printf("enter the burst time for each process:\n");
    for(int i=0;i<n;i++){
        printf("process %d:",i+1);
        scanf("%d",&bursttime[i]);
        process[i]=i+1;
    }
    int quantum;
    printf("enter the quantum for round robin");
    scanf("%d",&quantum);
    printf("\n");
    fcfs(process,n,bursttime);
    sjf(process,n,bursttime);
    roundrobin(process,n,bursttime,quantum);
      return 0;
}

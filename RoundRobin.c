
void main()
{
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    
    printf("Total number of processes in the system: ");
    scanf("%d", &NOP);
    y = NOP; // Assign the number of processes to variable y

    
    for (i = 0; i < NOP; i++)
    {
        printf("\nEnter the Arrival and Burst time of Process[%d]\n", i + 1);
        printf("Arrival time: "); // Accept arrival time
        scanf("%d", &at[i]);
        printf("Burst time: "); // Accept the Burst time
        scanf("%d", &bt[i]);
        temp[i] = bt[i]; // Store the burst time in the temp array
    }

    // Accept the Time Quantum
    printf("Enter the Time Quantum for the processes: ");
    scanf("%d", &quant);

    // Display the process No, burst time, Turn Around Time, and the waiting time
    printf("\nProcess No\tBurst Time\tTAT\tWaiting Time\n");

    for (sum = 0; i = 0; y != 0;)
    {
        if (temp[i] <= quant && temp[i] > 0) // Check the conditions
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }
        if (temp[i] == 0 && count == 1)
        {
            y--; // Decrement the process count
            printf("Process No[%d]\t%d\t\t%d\t%d\n", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }
        if (i == NOP - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    // Calculate average waiting time and Turn Around time
    avg_wt = wt * 1.0 / NOP;
    avg_tat = tat * 1.0 / NOP;
    printf("\nAverage Turn Around Time: %f\n", avg_wt);
    printf("Average Waiting Time: %f\n", avg_tat);
}
/*

Total number of processes in the system: 4

Enter the Arrival and Burst time of Process[1]
Arrival time: 2
Burst time: 1

Enter the Arrival and Burst time of Process[2]
Arrival time: 1
Burst time: 5

Enter the Arrival and Burst time of Process[3]
Arrival time: 4
Burst time: 1

Enter the Arrival and Burst time of Process[4]
Arrival time: 0
Burst time: 6
Enter the Time Quantum for the processes: 2

Process No      Burst Time      TAT     Waiting Time
Process No[1]   1               -1      -2
Process No[3]   1               2       1
Process No[2]   5               8       3
Process No[4]   6               13      7

Average Turn Around Time: 2.250000
Average Waiting Time: 5.500000

*/

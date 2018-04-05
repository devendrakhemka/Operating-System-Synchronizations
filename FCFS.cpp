
#include<stdio.h>
int main()
{
  int bt[10],at[10],wait_Time_Sum=0,turn_Time_Sum=0;
  int time=0,n,i,smallest,remain=0,gt[100],k=0;
  printf("Enter no of processes : ");
  scanf("%d",&n);
  remain=n;
  for(i=0;i<n;i++)
  {
    printf("Enter arrival time for process P%d : ",i+1);
    scanf("%d",&at[i]);
    printf("Enter burst time for process P%d : ",i+1);
    scanf("%d",&bt[i]);
  }

  printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
  at[9]=9999;

  for(time=0;remain!=0;)  //End the loop when n process finish
  {
    smallest=9; // Checking For index of Process with smallest Arrival Time
    for(i=0;i<n;i++)
    {
      if(at[i]<at[smallest] && bt[i]>0)
      {
      smallest=i;
      }
    }
        gt[k]=smallest+1;
        k++;
        remain--;
  //Index of Smallest  Arrival Time stored in `smallest`
   time+=bt[smallest];  //Incrementing Current Time
   wait_Time_Sum+=time-at[smallest]-bt[smallest];
   turn_Time_Sum+=time-at[smallest];
   printf("P[%d]\t|\t%d\t|\t%d\n",smallest+1,time-at[smallest],time-at[smallest]-bt[smallest]);
   bt[smallest]=0;  //Making burst time of current Process 0 so that it won't run again
  }
  printf("\nGANNTT CHART\n");
  for(i=0;i<k;i++)
  {
  printf("P%d\t|",gt[i]);
  }
  printf("\n average waiting time = %f",wait_Time_Sum*1.0/n);
  printf("\n average turnaround time = %f\n",turn_Time_Sum*1.0/n);
  return 0;
  }

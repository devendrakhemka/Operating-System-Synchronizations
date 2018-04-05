#include<stdio.h>
int main()
{
  int time,k=0,bt[10],gt[50],at[10],remain=0,sum_bt=0,smallest,n,i;
  int sum_turnaround=0,sum_wait=0;
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
  bt[9]=9999;
  printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
  for(time=0;remain!=0;)
  {
    smallest=9;
    for(i=0;i<n;i++)
    {
      if(at[i]<=time && bt[i]>0 && bt[i]<bt[smallest])
        smallest=i;
    }
    if(smallest==9)
    {
      time++;
      continue;
    }
    remain--;
    time+=bt[smallest];
    gt[k]=smallest+1;
    k++;
    printf("P[%d]\t|\t%d\t|\t%d\n",smallest+1,time-at[smallest],time-at[smallest]-bt[smallest]);
    sum_turnaround+=time-at[smallest];
    sum_wait+=time-at[smallest]-bt[smallest];

    bt[smallest]=0;
  }
  printf("\nGANTT CHART\n");
  for(i=0;i<k;i++)
  {
    printf("P%d\t|",gt[i]);
  }
  printf("\n\n average waiting time = %f",sum_wait*1.0/n);
  printf("\n\n average turnaround time = %f",sum_turnaround*1.0/n);
  return 0;
}

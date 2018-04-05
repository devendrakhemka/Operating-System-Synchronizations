#include<stdio.h>
int main()
{
  int i,h=0,j,n,k=0,time,sum_wait=0,sum_turnaround=0,smallest;
  int at[10],bt[10],pt[10],rt[10],gt[10],remain; //rt = remaining Time
  printf("Enter no of Processes : ");
  scanf("%d",&n);
  remain=n;
  for(i=0;i<n;i++)
  {
    printf("Enter arrival time, burst time and priority for process p%d :",i+1);
    scanf("%d",&at[i]);
    scanf("%d",&bt[i]);
    scanf("%d",&pt[i]);
    rt[i]=bt[i];
  }
  pt[9]=11;
  printf("\n\nProcess\t|Turnaround time|waiting time\n");
  for(time=0;remain!=0;time++)
  {
    smallest=9;
    for(i=0;i<n;i++)
    {
      if(at[i]<=time && pt[i]<pt[smallest] && rt[i]>0)
      {
    smallest=i;

      }
    }
    if((smallest+1)!=h)
    {
    gt[k]=smallest+1;
    h=smallest+1;
    k++;
    }
    rt[smallest]--;
    if(rt[smallest]==0)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",smallest+1,time+1-at[smallest],
        time+1-at[smallest]-bt[smallest]);

      sum_wait+=time+1-at[smallest]-bt[smallest];
      sum_turnaround+=time+1-at[smallest];
    }
  }
  printf("\nGANNTT CHART\n");
  for(i=0;i<k;i++)
  {
        printf("P%d\t|",gt[i]);
  }
  printf("\nAvg waiting time = %f\n",sum_wait*1.0/n);
  printf("Avg turnaround time = %f",sum_turnaround*1.0/n);
  return 0;
}

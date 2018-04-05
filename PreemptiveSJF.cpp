#include<stdio.h>
int main()
{
    int at[10],bt[10],rt[10],gt[50],k=0,h=0,i,smallest;
    int remain=0,n,time,sum_wait=0,sum_turnaround=0;
    printf("Enter no of Processes : ");
    scanf("%d",&n);
    remain=n;
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time for Process P%d : ",i+1);
        scanf("%d",&at[i]);
        printf("Enter burst time for Process P%d : ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
    rt[9]=9999;
    for(time=0;remain!=0;time++)
    {
        smallest=9;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0)
            {
                smallest=i;
            }
        }
        rt[smallest]--;
        if((smallest+1)!=h)
        {
        gt[k]=smallest+1;
 k++;
        h=smallest+1;
        }
        if(rt[smallest]==0)
        {
            remain--;

            printf("\nP[%d]\t|\t%d\t|\t%d",smallest+1,time+1-at[smallest],time+1-bt[smallest]-at[smallest]);
            sum_wait+=time+1-bt[smallest]-at[smallest];
            sum_turnaround+=time+1-at[smallest];
        }
    }
    printf("\nGANNT CHART:\n");
    for(i=0;i<k;i++)
    printf("P%d\t|",gt[i]);
    printf("\n\nAverage waiting time = %f\n",sum_wait*1.0/n);
    printf("Average Turnaround time = %f",sum_turnaround*1.0/n);
    return 0;
}

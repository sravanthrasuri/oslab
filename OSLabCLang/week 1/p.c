
#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;

}

int findMin(int p[],int at[],int bt[],int ct[],int pri[],int n,int current_time)
{
    int min_pt=9999;
    int min_index=-1;
    for(int i=1;i<n;i++)
    {
        if(at[i]<current_time&&pri[i]<min_pt&&ct[i]==-1)
        {
            min_pt=pri[i];
            min_index=i;
        }
    }
    return min_index;
}
void sort(int  p[],int at[],int bt[],int pri[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(at[j]>at[j+1])
            {
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&p[j],&p[j+1]);
                swap(pri[j],pri[j+1]);
                
            }
        }
    }
}
int main()
{
      int n;
      printf("n enter the number of elements :");
      scanf("%d",&n);
      int p[n],at[n],bt[n],ct[n],wt[n],tat[n],pri[n];
      int avg_tat,sum_tat=0,avg_wt,sum_wt=0;
      printf("\nenter the id arrival time and brust time and priority\n");
      for(int i=0;i<n;i++)
      {
       // printf("\nenter the id arrival time and brust time");
        scanf("%d",&p[i]);
        scanf("%d",&pri[i]);
        scanf("%d",&at[i]);
       
        scanf("%d",&bt[i]);
        
       // printf("\nenter the riority");
       // scanf("%d",&pri[i]);
      }
      for(int i=0;i<n;i++)
        ct[i]=-1;
    sort(p,at,bt,pri,n);
    printf("\np\tat\tbt\tct\ttat\twt");
    for(int i=0;i<n;i++)
    {
        
        {
            printf("\n");
            printf("%d\t%d\t%d\t%d",p[i],pri[i],at[i],bt[i]);
        }
    }

    ct[0]=at[0]+bt[0];
    tat[0]=ct[0]-at[0];
    wt[0]=tat[0]-bt[0];
   // sorts(p,at,bt,n);
   printf("\np%d ",p[0]);
    int current_time=ct[0];
    int completed=1;
    while(completed<n)
    {
        int min_index=findMin(p,at,bt,ct,pri,n,current_time);
        if(min_index==-1)
        {
            current_time++;
            printf("- ");
        }
        else
        {
            printf("p%d ",min_index+1);
            ct[min_index]=current_time+bt[min_index];
            tat[min_index]=ct[min_index]-at[min_index];
            wt[min_index]=tat[min_index]-bt[min_index];
            current_time=ct[min_index];
            completed++;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        sum_wt+=wt[i];
        sum_tat+=tat[i];
    }
    avg_wt=sum_wt/n;
    avg_tat=sum_tat/n;
    printf("\np\tpri\tat\tbt\tct\ttat\twt");
    for(int i=0;i<n;i++)
    {
        
        {
            printf("\n");
            printf("%d\t%d\t%d\t%d\t%d\t%d\t%d",p[i],pri[i],at[i],bt[i],ct[i],tat[i],wt[i]);
        }
    }

    printf("\nAverage waiting time is %d",avg_wt);
    printf("\nAverage turn arround time is %d",avg_tat);
    
    

}
/*
1 2 0 4
2 4 1 2
3 6 2 3
4 3 3 5
5 8 4 1
6 7 5 4 


*/
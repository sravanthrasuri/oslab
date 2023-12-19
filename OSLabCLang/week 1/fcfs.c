
#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;

}
void printGanttChart(int p[], int ct[], int n)
{
    printf("\nGantt Chart: ");
    for (int i = 1; i < n; i++)
    {
        printf("\np%d (%d - %d)", p[i], ct[i-1], ct[i]);
        if (i != n - 1)
            printf(" -> ");
    }
    printf("\n");
}
void sort(int  p[],int at[],int bt[],int n)
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
                //swap(pri[j],pri[j+1]);
                
            }
        }
    }
}
void sorts(int p[],int at[],int bt[],int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n-i;j++)
        {
            if(bt[j]>bt[j+1])
            {
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&p[j],&p[j+1]);
                //swap(pri[j],pri[j+1]);
                
            }
        }
    }
}
int main()
{
      int n;
      printf("n enter the number of elements :");
      scanf("%d",&n);
      int p[n],at[n],bt[n],ct[n],wt[n],tat[n];
      int avg_tat,sum_tat=0,avg_wt,sum_wt=0;
      printf("\nenter the id arrival time and brust time\n");
      for(int i=0;i<n;i++)
      {
       // printf("\nenter the id arrival time and brust time");
        scanf("%d",&p[i]);
        
        scanf("%d",&at[i]);
       
        scanf("%d",&bt[i]);
       // printf("\nenter the riority");
       // scanf("%d",&pri[i]);
      }
    sort(p,at,bt,n);
    printf("\np\tat\tbt\tct\ttat\twt");
    for(int i=0;i<n;i++)
    {
        
        {
            printf("\n");
            printf("%d\t%d\t%d",p[i],at[i],bt[i]);
        }
    }

    ct[0]=at[0]+bt[0];
    tat[0]=ct[0]-at[0];
    wt[0]=tat[0]-bt[0];
   // sorts(p,at,bt,n);
   printf("\n p%d %d ",p[0],ct[0]);
    
    for(int i=1;i<n;i++)
    {
        if(at[i]>ct[i-1])
        {
            ct[i]=at[i]+bt[i];
             printf(" p%d %d ",p[i],ct[i]);
        }
        else
        {
            ct[i]=ct[i-1]+bt[i];
             printf("p%d  %d",p[i],ct[i]);
        }
        tat[i]=ct[i]-at[i];;
         wt[i]=tat[i]-bt[i];
    }
    for(int i=0;i<n;i++)
    {
        sum_wt+=wt[i];
        sum_tat+=tat[i];
    }
    avg_wt=sum_wt/n;
    avg_tat=sum_tat/n;
    printf("\np\tat\tbt\tct\ttat\twt");
    for(int i=0;i<n;i++)
    {
        
        {
            printf("\n");
            printf("%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
        }
    }

    printf("\nAverage waiting time is %d",avg_wt);
   // printGanttChart(p, ct, n);
    printf("\nAverage turn arround time is %d",avg_tat);
    
    

}
/*
1 2 3 
2 1 6 
3 2 9
4 4 2

*/
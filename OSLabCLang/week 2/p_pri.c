
#include<stdio.h>


int findMin(int p[],int at[],int bt[],int ct[],int bbt[],int visited[],int pri[],int n,int current_time)
{
    int min_pt=9999;
    int min_index=-1;
    for(int i=0;i<n;i++)
    {
        if(at[i]<=current_time&&visited[i]==-1)
        {
            if(pri[i]<min_pt)
            {
                 min_pt=pri[i];
                 min_index=i;
            }
            else if(pri[i]==min_pt)
            {
                if(at[i]<at[min_index])
                    min_index=i;
            }
        }

    }
    return min_index;
}

int main()
{
      int n;
      printf("n enter the number of elements :");
      scanf("%d",&n);
      int p[n],at[n],bt[n],ct[n],wt[n],tat[n],bbt[n],pri[n];
      int visited[n];
      int avg_tat,sum_tat=0,avg_wt,sum_wt=0;
      printf("\nenter the id arrival time and brust time\n");
      for(int i=0;i<n;i++)
      {
       // printf("\nenter the id arrival time and brust time");
        scanf("%d",&p[i]);
        scanf("%d",&pri[i]);
        scanf("%d",&at[i]);
       
        scanf("%d",&bt[i]);
        
        
        bbt[i]=bt[i];
       // printf("\nenter the riority");
       // scanf("%d",&pri[i]);
      }
      for(int i=0;i<n;i++)
        visited[i]=-1;
    printf("\ngant chat\n");
    int k=0;
    int currentTime=0;
    while(k<n)
    {
        int min_index=findMin(p,at,bt,ct,bbt,visited,pri,n,currentTime);
    
        if(min_index!=-1)
        {
            printf("p%d ",min_index+1);
            ct[min_index]=currentTime+1;
            bt[min_index]=bt[min_index]-1;
             currentTime=ct[min_index];
            if(bt[min_index]==0)
            {
                k++;
                visited[min_index]=1;
                 tat[min_index]=ct[min_index]-at[min_index];
                wt[min_index]=tat[min_index]-bbt[min_index];
           }
        }
            
            else
            {
                currentTime++;
                printf("-");
            }

        
            
        
        
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
            printf("%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],bbt[i],ct[i],tat[i],wt[i]);
        }
    }

    printf("\nAverage waiting time is %d",avg_wt);
    printf("\nAverage turn arround time is %d",avg_tat);
    
    

}
/*
1  2 0 4
2 4 1 2
3 6 2 3 
4 1 3 5
5 8 4 1
6 3 5 4
7 2 11 6
*/
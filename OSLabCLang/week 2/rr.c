#include<stdio.h>
int f=-1,r=-1,curr=0;
int q[100];
void enQ(int a)
{
    if(f==-1&&r==-1)
    {
        f=r=0;
        q[r]=a;
    }
    else
    {
        q[++r]=a;
    }
}
int dQ()
{
   int x;
    if(f==r)
    {
        x=q[f];
        f=r=-1;

    }
    else
    {
        x=q[f];
        f++;
    }
    return x;
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;

}
void sort(int  p[],int at[],int bt[],int n)
{
    for(int i=0;i<n-1;i++)
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
            else if(at[j]==at[j+1])
            {
                if(p[j+1]<p[j])
                {
                    swap(&at[j],&at[j+1]);
                 swap(&bt[j],&bt[j+1]);
                 swap(&p[j],&p[j+1]);
                }
            }
        }
    }
}
int sel(int p[],int at[],int bt[],int ct[],int visited[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(bt[i]!=0&& (at[i]<=curr)&&visited[i]==-1)
        {
            enQ(i);
            visited[i]=0;
        }
    }
}
void rr(int p[],int at[],int bt[],int ct[],int tat[],int wt[],int bbt[],int visited[],int n,int tq)
{
    int k=n;
    int x;
    while(k>0)
    {
        sel(p,at,bt,ct,visited,n);
        printf(" Ready Queue: ");
        for (int i = f; i <= r; i++)
        {
            printf("p%d ", q[i] + 1);
        }
        x=dQ();
        if(bt[x]>tq)
        {
            bt[x]=bt[x]-tq;
            curr=curr+tq;
            ct[x]=curr;
            printf(" p%d ",x+1);
        }
        else
        {
            curr=curr+bt[x];
            ct[x]=curr;
            bt[x]=0;
            tat[x]=ct[x]-at[x];
            wt[x]=tat[x]-bbt[x];
            k--;
            printf(" p%d ",x+1);
        }
        sel(p,at,bt,ct,visited,n);
        if(bt[x]!=0)
        {
            enQ(x);
        }
    }
     float sum_wt=0;
        float sum_tat=0;
    for(int i=0;i<n;i++)
    {
        sum_wt+=wt[i];
        sum_tat+=tat[i];
    }
    float avg_wt=sum_wt/n;
    float avg_tat=sum_tat/n;
    printf("\np\tat\tbt\tct\ttat\twt");
    for(int i=0;i<n;i++)
    {
        
        {
            printf("\n");
            printf("%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],bbt[i],ct[i],tat[i],wt[i]);
        }

    }
    printf("\nthe average waiting time is %f",avg_wt);
    printf("\nthe average turn around  time is %f",avg_tat);
    printf("\nghanchat\n");
    
}
/*void rr(int p[], int at[], int bt[], int ct[], int tat[], int wt[], int bbt[], int visited[], int n, int tq)
{
    int k = n;
    int x;
    printf("\nGantt Chart: ");
    while (k > 0)
    {
        sel(p, at, bt, ct, visited, n);
        x = dQ();
        if (bt[x] > tq)
        {
            bt[x] = bt[x] - tq;
            curr = curr + tq;
            ct[x] = curr;
            printf("p%d (%d - %d) ", x + 1, curr - tq, curr);
        }
        else
        {
            curr = curr + bt[x];
            ct[x] = curr;
            bt[x] = 0;
            tat[x] = ct[x] - at[x];
            wt[x] = tat[x] - bbt[x];
            k--;
            printf("p%d (%d - %d) ", x + 1, curr - bt[x], curr);
        }
        sel(p, at, bt, ct, visited, n);
        if (bt[x] != 0)
        {
            enQ(x);
        }
    }

    float sum_wt = 0;
    float sum_tat = 0;
    for (int i = 0; i < n; i++)
    {
        sum_wt += wt[i];
        sum_tat += tat[i];
    }
    float avg_wt = sum_wt / n;
    float avg_tat = sum_tat / n;
    printf("\n\np\tat\tbt\tct\ttat\twt");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bbt[i], ct[i], tat[i], wt[i]);
    }
    printf("\n\nThe average waiting time is %f", avg_wt);
    printf("\nThe average turnaround time is %f", avg_tat);
    printf("\n");
}
void rr(int p[], int at[], int bt[], int ct[], int tat[], int wt[], int bbt[], int visited[], int n, int tq)
{
    int k = n;
    int x;
    int time = 0; // Track the current time
    printf("\nGantt Chart: ");
    while (k > 0)
    {
        sel(p, at, bt, ct, visited, n);
        x = dQ();
        if (bt[x] > tq)
        {
            ct[x] = time + tq;
            time += tq;
            bt[x] -= tq;
            enQ(x);
        }
        else
        {
            ct[x] = time + bt[x];
            time += bt[x];
            bt[x] = 0;
            tat[x] = ct[x] - at[x];
            wt[x] = tat[x] - bbt[x];
            k--;
        }
        printf("p%d (%d - %d) ", x + 1, time - bt[x], time);
    }

    float sum_wt = 0;
    float sum_tat = 0;
    for (int i = 0; i < n; i++)
    {
        sum_wt += wt[i];
        sum_tat += tat[i];
    }
    float avg_wt = sum_wt / n;
    float avg_tat = sum_tat / n;
    printf("\n\np\tat\tbt\tct\ttat\twt");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bbt[i], ct[i], tat[i], wt[i]);
    }
    printf("\n\nThe average waiting time is %f", avg_wt);
    printf("\nThe average turnaround time is %f", avg_tat);
    printf("\n");
}

*/
int main()
{
    int n;
    printf("\nEnter the number of rocess :");
    scanf("%d",&n);
    int p[n],at[n],bt[n],ct[n],wt[n],tat[n],visited[n],bbt[n];
    printf("Enter the rocess id and at and bt :");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&p[i],&at[i],&bt[i]);
        ct[i]=0;
        visited[i]=-1;
        bbt[i]=bt[i];

    }
    int tq;
    int avg_wt,avg_tat,sum_wt,sum_tat;
    printf("\nEnter the time quantum : ");
    scanf("%d",&tq);
    sort(p,at,bt,n);
     
    curr=at[0];
    rr(p,at,bt,ct,tat,wt,bbt,visited,n,tq);
    
    

    
    

}

	/*
1 0 4
2 1 5
3 2 6
4 3 3
5 4 1  
6 5 4
p1  p2  p3  p1  p4  p5  p2  p6  p3  p4  p2  p6  p3 
p       at      bt      ct      tat     wt
1       0       4       8       8       4
2       1       5       19      18      13
3       2       6       23      21      15
4       3       3       18      15      12
5       4       1       11      7       6
6       5       4       21      16      12
the average waiting time is 10.333333
the average turn around  time is 14.166667
*/
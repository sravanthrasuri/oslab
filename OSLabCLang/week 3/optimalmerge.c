#include<stdio.h>

int main()
{
    int n;
    int faults=0;
    int x,max;
    int f3;
    printf("\nenetr the number of ages :");
    scanf("%d",&n);
    int nf;
    printf("\nEnetr the no of frames :");
    scanf("%d",&nf);
    int ref[n];
    printf("\nEnetr the reference string :");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ref[i]);
    }
   
    int frames[nf];
    int check[nf];
    for(int i=0;i<nf;i++)
        frames[i]=-1;

    for(int i=0;i<n;i++)
    {
        int f1=0,f2=0;
        
        for(int j=0;j<nf;j++)
        {
            if(ref[i]==frames[j])
            {
                f1=1;
                f2=1;
                break;
            }
        }
        if(f1==0)
            for(int j=0;j<nf;j++)
            {
                if(frames[j]==-1)
                {
                    frames[j]=ref[i];
                    faults+=1;
                    f2=1;
                 break;
                }
            }
        
        if(f2==0)
        {
            f3=0;
            for(int j=0;j<nf;j++)
            {
                check[j]=-1;
                for(int k=i+1;k<n;k++)
                {
                    if(frames[j]==ref[k])
                    {
                        check[j]=k;
                        break;
                    }
                }

            }
            for(int j=0;j<nf;j++)
            {
                if(check[j]==-1)
                {
                    x=j;
                    f3=1;
                    break;
                }
            }
            if(f3==0)
                {
                    max=check[0];
                    x=0;
                    for(int j=0;j<nf;j++)
                    {
                        if(max<check[j])
                        {
                            max=check[j];
                            x=j;

                        }
                    }
                }
                frames[x]=ref[i];
                faults++;
             }
             printf("\n");
             printf("%d ",ref[i]);
             for(int j=0;j<nf;j++)
             {
                if(frames[j]!=-1)
                {
                    printf("%d ",frames[j]);
                }
                else 
                {
                    printf("_ ");
                }
             }
        }
    printf("\nno of page faults: %d",faults);
}
/* 
:7 0 1 2 0 3 0  4 2 3 0 3 2 1 2 0 1 7 0 1
*/
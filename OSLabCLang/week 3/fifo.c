#include<stdio.h>

int main()
{
    int n;
    int faults=0;
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
    for(int i=0;i<nf;i++)
    {
        frames[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        int f=0;
        for(int j=0;j<nf;j++)
        {
            if(frames[j]==ref[i])
            {
                f++;
                faults--;
            }
        }
        faults++;
        if(faults<=nf&&(f==0))
        {
            frames[i]=ref[i];
        }
        else if(f==0)
        {
            frames[(faults-1)%nf]=ref[i];
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
29
7 0 1 2 0 3 0 4 2 
1 2 3 2 1 5 2 1 6 2 5 6 3 1 3 6 1 2 4 3
*/
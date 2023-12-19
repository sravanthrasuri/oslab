#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
int visit[10000];
int min(int ref_str[],int n,int head)
{
    int mindis=99999;
    int dis=0;
    int index;
    for(int i=0;i<n;i++)
    {   
       if(visit[ref_str[i]!=1])
        {
             dis=abs(head-ref_str[i]);
             if(mindis>dis)
             { 
                mindis=dis;
                index=i;
            }
        }
       
    }
    visit[index]=1;
    return mindis;

}
int distance(int ref_str[],int head,int n)
{
    int headdis=0;
     for(int i=0;i<n;i++)
    {   
        curr=min(ref_str,n,head);
        
        headdis+=curr;
        printf("\nit moved from %d to %d",curr,ref_str[i]);
        curr=ref_str[i];
        

    }
    return headdis;
}
#include<math.h>
int main()
{
    int n,head;
    int headdis=0;
    int ref_str[100];
    printf("\nENter the number of references :");
    scanf("%d",&n);
    //int track[n];
    printf("\nENetr the referenece string \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ref_str[i]);
    }
    printf("\nENetr the haed position \n");
    scanf("%d",&head);
    
    int dis=distance(ref_str,head,n);
    printf("\n THE total distance is %d",dis);

}
/*
ENetr the referenece string
98 183 40 122 10 124 65
*/

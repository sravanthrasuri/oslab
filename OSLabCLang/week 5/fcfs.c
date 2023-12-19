#include<stdio.h>
int distance(int ref_str[],int curr,int n)
{
    int headdis=0;
     for(int i=0;i<n;i++)
    {
        headdis+=abs(curr-ref_str[i]);
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
    int curr=head;
    int dis=distance(ref_str,curr,n);
    printf("\n THE total distance is %d",dis);

}
/*
ENetr the referenece string
98 183 40 122 10 124 65

ENetr the haed position
53

it moved from 53 to 98
it moved from 98 to 183
it moved from 183 to 40
it moved from 40 to 122
it moved from 122 to 10
it moved from 10 to 124
it moved from 124 to 65
 THE total distance is 640

*/
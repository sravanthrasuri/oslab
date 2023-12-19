#include<bits/stdc++.h>
using namespace std;

struct atbt
{
   int at,bt;
   string p;
};

int sort(atbt arr[],int n,int sum)
{
   int min=INT_MAX,b=INT_MAX,k;
   for(int i=0;i<n;i++)
   {
      if(arr[i].at<=sum && arr[i].bt!=0)
      {
         if(arr[i].bt<=b)
         {
           if(arr[i].bt==b)
           {
             if(arr[i].at<min)
             {
                k=i;
              b=arr[i].bt;
              min=arr[i].at;
             }
           }
           else
           {
              k=i;
              b=arr[i].bt;
              min=arr[i].at;
           }
         }
      }
   }
   return k;
}

void solve(int CT[],atbt arr[],int n,int ideal)
{
  int c=0;
  int sum=ideal;
   while(c<n)
   {
     
      int i=sort(arr,n,sum);
      //cout<<i;
     sum+=1;
     if(arr[i].bt==1)
     {
        CT[i]=sum;
        c++;
     }
     arr[i].bt-=1; 
   }
}

 float average(int a[],int n)
  {
     float sum=0;
     for(int i=0;i<n;i++)
     {
        sum+=a[i];
     }
     return sum/n;
  }  

int main()
{
   int n;
    cout<<"enter the no. of processors:";
    cin>>n;
    atbt arr[n];
    cout<<"enter at,bt and processor  respectively:";
    for(int i=0;i<n;i++)
    cin>>arr[i].at>>arr[i].bt>>arr[i].p;
    int CT[n],ideal=0;
    atbt arr2[n];
    int min=INT_MAX;
    for(int i=0;i<n;i++){
    if(arr[i].at<min)
      min=arr[i].at;
    arr2[i]=arr[i];
    }
    ideal=min;
    solve(CT,arr2,n,ideal);
    cout<<"compilition time is:";
   for(int i=0;i<n;i++)
   {
    cout<<arr[i].p<<" ";
   cout<<CT[i]<<endl;
   }
   int tat[n],wt[n];
   for(int i=0;i<n;i++)
   {
      tat[i]=CT[i]-arr[i].at;
      wt[i]=tat[i]-arr[i].bt; 
   }
   cout<<"\nturn around time:\n";
   for(int i=0;i<n;i++)
   {
     cout<<arr[i].p<<" ";
   cout<<tat[i]<<endl;
   }
   cout<<"\nwaiting time:\n";
   for(int i=0;i<n;i++)
   {
     cout<<arr[i].p<<" ";
   cout<<wt[i]<<endl;
   }
   cout<<"\naverage tat:"<<average(tat,n);
   cout<<"\naverage wt:"<<average(wt,n);
}

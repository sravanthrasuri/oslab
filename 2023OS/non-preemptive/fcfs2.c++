#include<bits/stdc++.h>
using namespace std;
struct atbt
{
   int at,bt;
   string p;
};

  void sort(atbt arr[],int n)
  {
    for(int i=0;i<n-1;i++)
    {
      for(int j=0;j<n-i-1;j++)
      { 
         if(arr[j].at>arr[j+1].at)
         {
            atbt t=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=t;
         }
      }
    }
  }
  
void solve(atbt arr[],int n,int CT[],int ideal)
{
   int sum=ideal;
   int i=0;
   while(i<n)
   {
   if(sum>=arr[i].at)
   {
    CT[i]=arr[i].bt+sum;
    sum=CT[i];
    i++;
   }
   else
   sum=arr[i].at;
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
    sort(arr,n);
    cout<<"sorted atbt :"<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i].p<<"\t"<<arr[i].at<<"\t"<<arr[i].bt<<endl;
    int CT[n],ideal=0;
    if(arr[0].at==0)
     solve(arr,n,CT,ideal);
     else
     {
        ideal=ideal+arr[0].at;
        solve(arr,n,CT,ideal);
     }
     cout<<"compilition time is:\n";
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


#include<bits/stdc++.h>
using namespace std;
struct atbt
{
   int at,bt;
   string p;
};

  void sort(atbt arr[],int n,atbt arr2[])
  {
    for(int i=0;i<n-1;i++)
    {
      for(int j=0;j<n-i-1;j++)
      { 
        if(arr[j].bt==arr[j+1].bt)
        {
          if(arr[j].at>arr[j+1].at)
          {
            atbt t=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=t;
          }
        }
        else{
         if(arr[j].bt>arr[j+1].bt)
         {
            atbt t=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=t;
         }  
    }
      }
      
    }
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
      if(arr[i].at<min)
      min=arr[i].at;
    }
    int j=1;
    for(int i=0;i<n;i++)
    {
      if(arr[i].at==min)
      {
        arr2[0]=arr[i]; 
      }
      else
      {
        arr2[j++]=arr[i];
      }
    }
  }
  
void solve(atbt arr2[],int n,int CT[],int ideal)
{
   int sum=ideal;
   int i=0;
   while(i<n)
   {
   if(sum>=arr2[i].at)
   {
    CT[i]=arr2[i].bt+sum;
    sum=CT[i];
    i++;
   }
   else
   sum=arr2[i].at;
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
   atbt arr2[n];
   sort(arr,n,arr2);
   
    cout<<"sorted atbt :"<<endl;
    for(int i=0;i<n;i++)
    cout<<arr2[i].p<<" "<<arr2[i].at<<"\t"<<arr2[i].bt<<endl;
    int CT[n],ideal=0;
    if(arr2[0].at==0)
     solve(arr2,n,CT,ideal);
     else
     {
        ideal=ideal+arr2[0].at;
        solve(arr2,n,CT,ideal);
     }
    cout<<"compilition time is:";
   for(int i=0;i<n;i++)
   {
    cout<<arr2[i].p<<" ";
   cout<<CT[i]<<endl;
   }
   int tat[n],wt[n];
   for(int i=0;i<n;i++)
   {
      tat[i]=CT[i]-arr2[i].at;
      wt[i]=tat[i]-arr2[i].bt; 
   }
   cout<<"\nturn around time:\n";
   for(int i=0;i<n;i++)
   {
     cout<<arr2[i].p<<" ";
   cout<<tat[i]<<endl;
   }
   cout<<"\nwaiting time:\n";
   for(int i=0;i<n;i++)
   {
     cout<<arr2[i].p<<" ";
   cout<<wt[i]<<endl;
   }
   cout<<"\naverage tat:"<<average(tat,n);
   cout<<"\naverage wt:"<<average(wt,n);
}


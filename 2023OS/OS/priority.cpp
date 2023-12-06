#include<bits/stdc++.h>
using namespace std;
struct atbt
{
   int at,bt,pri;
   string p;
};

  void sort(atbt a[],int n,atbt a2[])
  {
    for(int i=0;i<n-1;i++)
    {
      for(int j=0;j<n-i-1;j++)
      { 
       
         if(a[j].pri>a[j+1].pri)
         {
            atbt t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
         }  
 
      }
      
    }
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
      if(a[i].at<min)
      min=a[i].at;
    }
    int j=1;
    for(int i=0;i<n;i++)
    {
      if(a[i].at==min)
      {
        a2[0]=a[i]; 
      }
      else
      {
        a2[j++]=a[i];
      }
    }
  }
  
void solve(atbt a2[],int n,int c[],int ideal)
{
   int sum=ideal;
   int i=0;
   while(i<n)
   {
   if(sum>=a2[i].at)
   {
    c[i]=a2[i].bt+sum;
    sum=c[i];
    i++;
   }
   else
   sum=a2[i].at;
   }
}
  float avg(int arr[],int n)
  {
     float sum=0;
     for(int i=0;i<n;i++)
     {
        sum+=arr[i];
     }
     return sum/n;
  }
  int main(){
	int n;
	cout<<"Enter the no.of processors:";
	cin>>n;
	atbt a[n];
	cout<<"Enter the processor number, arrival time, burst time and priority respectively:";
	for(int i=0;i<n;i++){
		cin>>a[i].p>>a[i].at>>a[i].bt>>a[i].pri;
	}
	atbt a2[n];
	sort(a,n,a2);
		int c[n],ideal=0;
	if(a2[0].at==0)
	solve(a2,n,c,ideal);
	else{
		ideal=ideal+a2[0].at;
		solve(a2,n,c,ideal);
	}
	int tat[n],wt[n];
	for(int i=0;i<n;i++){
		tat[i]=c[i]-a2[i].at;
		wt[i]=tat[i]-a2[i].bt;
	}
	cout<<"Completion time, turn around time and waiting time respectively"<<endl;
	for(int i=0;i<n;i++){
		cout<<a2[i].p<<" "<<c[i]<<" "<<tat[i]<<" "<<wt[i]<<endl;
	}
	cout<<"Avg turn around time:"<<avg(tat,n)<<endl;
	cout<<"Avg waiting time:"<<avg(wt,n)<<endl;
}  

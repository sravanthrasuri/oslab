#include<bits/stdc++.h>
using namespace std;
struct atbt
{
   int at,bt;
   string p;
};
string a[100];
int front=-1;
int rear=-1;
void enqueue(string q)
{
   if(front==-1 && rear==-1)
   {
      front=rear=0;
      a[front]=q;
   }
   else
   {
      rear++;
      a[rear]=q;
     
   }
 
}
void dequeue()
{
   if(front==rear)
   front=rear=-1;
   else
   {
     cout<<"deleted processor:"<<a[front]<<"\n";
     front++;
   }
   
}
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
  
void solve(atbt arr[],int n,int CT[],int ideal,int tq,atbt arr2[])
{
   int sum=ideal;
   int j=1;
   enqueue(arr2[0].p);
   while(rear != -1 && front != -1 )
   {
     for(int i=0;i<n;i++)
     {
        if(a[front]==arr2[i].p)
        {
          if(arr2[i].bt<=tq)
          {
            sum+=arr2[i].bt;
            CT[i]=sum;
           
          }
          else
          {
             sum+=tq;
             arr2[i].bt-=tq;
             while(arr2[j].at<=sum && j<n)
             {
             enqueue(arr2[j].p);
             j++;
             }
             enqueue(arr2[i].p);
          }
          break;
        }
        
     }
     dequeue();
   }

}
  float avg(int a[],int n)
  {
     float sum=0;
     for(int i=0;i<n;i++)
     {
        sum+=a[i];
     }
     return sum/n;
  } 
int main(){
	int n;
	cout<<"Enter the no.of processors:";
	cin>>n;
	atbt a[n];
	cout<<"Enter the processor number, arrival time, burst time respectively:";
	for(int i=0;i<n;i++){
		cin>>a[i].p>>a[i].at>>a[i].bt;
	}
	sort(a,n);
		int c[n],ideal=0,quantum;
		cout<<"Enter the time quantum:";
		cin>>quantum;
		atbt a2[n];
		for(int i=0;i<n;i++)
		a2[i]=a[i];
	if(a[0].at==0)
	solve(a,n,c,ideal,quantum,a2);
	else{
		ideal=ideal+a[0].at;
		solve(a,n,c,ideal,quantum,a2);
	}
	int tat[n],wt[n];
	for(int i=0;i<n;i++){
		tat[i]=c[i]-a[i].at;
		wt[i]=tat[i]-a[i].bt;
	}
	cout<<"Completion time, turn around time and waiting time respectively"<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i].p<<" "<<c[i]<<" "<<tat[i]<<" "<<wt[i]<<endl;
	}
	cout<<"Avg turn around time:"<<avg(tat,n)<<endl;
	cout<<"Avg waiting time:"<<avg(wt,n)<<endl;
}  

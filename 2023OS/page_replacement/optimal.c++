#include<bits/stdc++.h>
using namespace std;

bool isfound(int frames[],int e,int n)
{
    for(int i=0;i<n;i++)
    {
      if(frames[i] == e)
      return true;
    }
    return false;
}

void print(int frames[],int n)
{
   for(int i=0;i<n;i++)
   {
     cout<<frames[i]<<"\t";
   }
   cout<<"\n";
}

int replace(int str[],int s,int frames[],int r,int e,int n)
{
   int a[n],max=INT_MIN;
   for(int i=0;i<n;i++)
   {
     a[i]=-1;
   }
       
   for(int j=s;j<e;j++)
   {
      for(int i=0;i<n;i++)
      {
        if(str[j] == frames[i] && a[i]==-1)
        {
           a[i]=j;
           break;
        }
      }
   }
   int l=1,m;
   while(l<=n)
   {
     if(r==n)
     {
       r=0;
     }
     if(a[r]==-1)
     {
       m=r;
       break;
     }
     else
     {
       if(a[r]>max)
       {
         max=a[r];
         m=r;
       }
       r++;
     }
     
     l++;
   }
   r=m;
   // cout<<"\n"<<r<<"\n";
   return r;
}

int main()
{
  int n,n2,hit=0,pf=0,r=0;
  cout<<"enter the no. of elements/pages:";
  cin>>n;
  cout<<"enter the no. of frames:";
  cin>>n2;
  int str[n],frames[n2];
  for(int i=0;i<n2;i++)
     frames[i]=-1;
  cout<<"enter the reference string:";
  for(int i=0;i<n;i++)
  {
     cin>>str[i];
  }
  
  for(int i=0;i<n;i++)
  {
    if(isfound(frames,str[i],n2))
    {
       hit++;
       cout<<str[i]<<" is hit"<<"\n";
      // print(frames,n2);
    }
    else
    {
       pf++;
       cout<<str[i]<<" is page fault, added to frame"<<"\n";
       if(frames[r]==-1)
       {
         frames[r]=str[i];
         r++;
       }
       else{
          if(r==n2)
          r=0;
          r=replace(str,i+1,frames,r,n,n2); 
          frames[r]=str[i];
           r++;
         }
      // print(frames,n2);
    }
    print(frames,n2);
  }
  cout<<"no.of page faults:"<<pf<<"\n";
  cout<<"no.of hits:"<<hit<<"\n";
}

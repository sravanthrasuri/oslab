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
       print(frames,n2);
    }
    else
    {
       pf++;
       cout<<str[i]<<" is page fault, added to frame"<<"\n";
       if(r==n2)
        r=0;
       frames[r]=str[i];
       r++;
       print(frames,n2);
    }
  }
  cout<<"no.of page faults:"<<pf<<"\n";
  cout<<"no.of hits:"<<hit<<"\n";
}

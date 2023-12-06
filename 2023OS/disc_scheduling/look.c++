#include<bits/stdc++.h>
using namespace std;
void sort(int a[],int n)
{
  n++;
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        int t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
      }
    }
  }
}

int main()
{
  int n,hp,thm=0;
  cout<<"enter the number of tracks:";
  cin>>n;
  int a[n+1];
  cout<<"enter the request sequences:";
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }

  cout<<"enter the head position:";
  cin>>hp;
  a[n]=hp;
  cout<<"enter the direction:";
  string d;
  cin>>d;
   sort(a,n);
  cout<<"sorted array:";
  for(int i=0;i<=n;i++)
  cout<<a[i]<<" ";
  int k,i,j;
  for(int l=0;l<=n;l++)
  {
    if(a[l] == hp)
    {
      k=l;
      break;
    }
  }
  
  
  n=n+1; 
  
/*  cout<<"\nseek sequence:\n";
  if(d == "left")
  {
    i=k+1;
    while(k!=0)
    {
      cout<<a[k]<<" ";
      thm+=abs(a[k]-a[k-1]);
      k--;
    }
    while(i<n)
    {
     cout<<a[k]<<" ";
      thm+=abs(a[k]-a[i]);
      k=i;
      i++;
    }
    cout<<a[k]<<" ";
  }
  
  else if(d == "right")
  {
    i=k-1;
    while(k<n-1)
    {
      cout<<a[k]<<" ";
      thm+=abs(a[k]-a[k+1]);
      k++;
    }
    while(i>=0)
    {
     cout<<a[k]<<" ";
      thm+=abs(a[k]-a[i]);
      k=i;
      i--;
    }
    cout<<a[k]<<" ";
  }*/
  
  // or
  
 
 if(d == "left")
  {
    thm=a[n-1]+a[k]-2*a[0];
   }
   else if(d == "right")
   {
     thm=2*a[n-1]-a[0]-a[k];
   } 
  
  
  
  cout<<"\ntotal number of head moments is:"<<thm;
}

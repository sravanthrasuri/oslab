#include<bits/stdc++.h>
using namespace std;
void sort(int a[],int n)
{
 n =n+3;
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
  int a[n+3];
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
  a[n+2]=0;
   a[n+1]=199;
   sort(a,n);
  
  cout<<"sorted array:";
  for(int i=0;i<=n+2;i++)
  cout<<a[i]<<" ";
  int k,i,j;
  for(int l=0;l<=n+2;l++)
  {
    if(a[l] == hp)
    {
      k=l;
      break;
    }
  }
  
 n=n+3;
  
 /* cout<<"\nseek sequence:\n";
  if(d == "left")
  {
    i=k;
    while(k!=0)
    {
      cout<<a[k]<<" ";
      thm+=abs(a[k]-a[k-1]);
      k--;
    }
    j=n-1;
    while(i<j)
    {
     cout<<a[k]<<" ";
      thm+=abs(a[k]-a[j]);
      k=j;
      j--;
    }
    cout<<a[k]<<" ";
  }
  
  else if(d == "right")
  {
    i=k;
    while(k<n-1)
    {
      cout<<a[k]<<" ";
      thm+=abs(a[k]-a[k+1]);
      k++;
    }
    
    j=0;
    while(i>j)
    {
     cout<<a[k]<<" ";
      thm+=abs(a[k]-a[j]);
      k=j;
      j++;
    }
    cout<<a[k]<<" ";
  }*/
  
  // or
  
  
 if(d == "left")
  {
    thm=2*(a[n-1])+a[k]-a[k+1];
   }
   else if(d == "right")
   {
     thm=2*(a[n-1])-a[k]+a[k-1];
   } 
  
  
  
  cout<<"\ntotal number of head moments is:"<<thm;
}

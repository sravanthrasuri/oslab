#include<bits/stdc++.h>
using namespace std;
void sort(int a[],int n)
{
 n =n+1;
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
  sort(a,n);
  cout<<"sorted array:";
  for(int i=0;i<=n;i++)
  cout<<a[i]<<" ";
  int i,j,k;
  for(int l=0;l<n;l++)
  {
    if(a[l] == hp)
    {
      k=l;
      i=l-1;
      j=l+1;
      break;
    }
  }
  cout<<"\nseek sequence:\n";
  while(i>=0 && j<=n && i<j)
  {
    int r=abs(a[i]-a[k]);
    int l=abs(a[j]-a[k]);
    if(r<l)
    {
      cout<<a[k]<<" ";
       k=i;
       i--;
       thm+=r;  
    }
    else
    {
     cout<<a[k]<<" ";
      k=j;
      j++;
      thm+=l;
    }
  }
  
  while(i>=0 && j>n)
  {
     thm+=abs(a[i]-a[k]);
      cout<<a[k]<<" "; 
     k=i;
     i--;
  }
  
  while(j<=n && i<0)
  {
     thm+=abs(a[k]-a[j]);
      cout<<a[k]<<" ";
     k=j;
     j++;
  }
  cout<<a[k]<<" ";
  
  cout<<"\ntotal number of head moments is:"<<thm;
}

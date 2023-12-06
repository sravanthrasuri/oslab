#include<bits/stdc++.h>
using namespace std;
void sort(int a[],int n)
{
 n =n+2;
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
  int a[n+2];
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
  if(d == "left")
  {
   a[n+1]=0;
   sort(a,n);
  }
  else if(d == "right")
  {
   a[n+1]=199;
   sort(a,n);
  }
  cout<<"sorted array:";
  for(int i=0;i<=n+1;i++)
  cout<<a[i]<<" ";
  int k,i,j;
  for(int l=0;l<=n+1;l++)
  {
    if(a[l] == hp)
    {
      k=l;
      break;
    }
  }
  
  
  /*cout<<"\nseek sequence:\n";
  if(d == "left")
  {
    i=k+1;
    while(k!=0)
    {
      cout<<a[k]<<" ";
      thm+=abs(a[k]-a[k-1]);
      k--;
    }
    while(i<n+2)
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
    while(k<n+1)
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
  
  n=n+2;
 if(d == "left")
  {
    thm=(a[n-1]-a[0])+(a[k]-a[0]);
   }
   else if(d == "right")
   {
     thm=(a[n-1]-a[k])+(a[n-1]-a[0]);
   } 
  
  
  
  cout<<"\ntotal number of head moments is:"<<thm;
}

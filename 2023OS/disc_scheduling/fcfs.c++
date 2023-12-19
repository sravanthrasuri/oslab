#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,hp,thm=0;
  cout<<"enter the number of tracks:";
  cin>>n;
  int a[n];
  cout<<"enter the request sequences:";
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  
  cout<<"enter the head position:";
  cin>>hp;
  thm=abs(a[0]-hp);
  
  for(int i=1;i<n;i++)
  {
     cout<<thm<<" ";
     thm+=abs(a[i-1]-a[i]);
  }
  cout<<"total number of head moments is:"<<thm;
}

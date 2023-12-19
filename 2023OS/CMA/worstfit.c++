//worst fit
#include<bits/stdc++.h>
using namespace std;
struct memory
{
   string p;
   int data;
};

int main()
{
   int n;
   cout<<"enter n:";
   cin>>n;
   memory m[n];
   cout<<"enter memory:";
   for(int i=0;i<n;i++)
   {
      cin>>m[i].data;
      m[i].p="null";
   }
   int n1;
   cout<<"enter n1:";
   cin>>n1;
   memory pr[n1];
   cout<<"enter pr,memory:";
   for(int i=0;i<n1;i++)
   {
       cin>>pr[i].p>>pr[i].data;
   }
   
   for(int i=0;i<n1;i++)
   {
     int max=INT_MIN;
     for(int j=0;j<n;j++)
     {
       if(m[j].data >= pr[i].data && m[j].p=="null")
       {
          if(m[j].data>max)
          {
             for(int k=0;k<n;k++)
             {
               if(m[k].data==max)
               {
                 m[k].p="null";
                 break;
               }
             }
             m[j].p=pr[i].p;
             max=m[j].data;
          }
       }
     }
   }
   
   for(int j=0;j<n;j++)
   {
      cout<<m[j].p<<" "<<m[j].data;
      cout<<endl;
   }
   int ex=0,in=0;
   for(int i=0;i<n;i++)
   {
      if(m[i].p=="null")
      {
        ex=ex+m[i].data;
      }
      
      else
      {
         for(int j=0;j<n1;j++)
         {
           if(m[i].p==pr[j].p)
           {
             in+=(m[i].data-pr[j].data);
           }
         }
      }
   }
   cout<<"ex:"<<ex;
   cout<<"in:"<<in;
}

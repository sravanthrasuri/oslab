#include<bits/stdc++.h>
using namespace std;

bool found(int finish[],int n,int m)
{
  
      for(int j=0;j<n;j++)
      {
         if(finish[j]==0)
           return false;
      }
   
   return true;
}

bool check(int need[],int work[],int i,int m)
{
          for(int j=0;j<m;j++)
          {
           if(need[j]>work[j])
             {
             return false;
             }
           }
           return true;
}

void add(int work[],int all[],int i,int j)
{
   for(int k=0;k<j;k++)
   {
     work[k]=work[k]+all[k];
   }
}


int main()
{
   int n,m;
   cout<<"enter n and m:";
   cin>>n>>m;
   int all[n][m],max[n][m],need[n][m],avail[m],work[m];
   
   cout<<"enter allocation matrix:";
   for(int i=0;i<n;i++)
   {  
       for(int j=0;j<m;j++)
          cin>>all[i][j];
   } 
   
   cout<<"enter max matrix:";
   for(int i=0;i<n;i++)
   {  
       for(int j=0;j<m;j++)
          cin>>max[i][j];
   } 
   
   
   cout<<"enter available matrix:";
   for(int j=0;j<m;j++)
     cin>>avail[j];
     
     
    for(int i=0;i<n;i++)
   {  
       for(int j=0;j<m;j++)
       {
          need[i][j]=max[i][j]-all[i][j];
       }
          
   } 
   
   int finish[n];
     for(int i=0;i<n;i++)
       finish[i]=0;
       
     for(int j=0;j<m;j++)
        work[j]=avail[j]; 
     
     int seq[n],k=0;   
     while(!found(finish,n,m))
     {
         for(int i=0;i<n;i++)
        {
          
           if(check(need[i],work,i,m) && finish[i]==0)
             {
                finish[i]=1;
                seq[k]=i;
                k++;
                add(work,all[i],i,m);
               // break;
             }
          
       }
     }
       
    for(int i=0;i<n;i++)
     cout<<seq[i]<<"\t";          
}

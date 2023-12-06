#include<bits/stdc++.h>
using namespace std;
struct memory
{
   int data;
   string p;
};

void assign(memory m[])
{
   m[0].p="null";
   m[1].p="null";
   m[2].p="null";
   m[3].p="null";
}


// print memory
void print(memory m[])
{
  
   for(int i=0;i<4;i++)
   {
     cout<<m[i].p<<" "<<m[i].data<<"\n";
   }
}

int main()
{
memory m[4];
m[0].data=20;
m[1].data=10;
m[2].data=30;
m[3].data=40;
int n;
cout<<"enter no. of processors:";
cin>>n;
cout<<"enter processors and memory respectively:\n";
memory pr[n];

for(int i=0;i<n;i++)
{
  cin>>pr[i].p>>pr[i].data;
}

// first fit
assign(m);
for(int i=0;i<n;i++)
{
   for(int j=0;j<4;j++)
   {
     if(pr[i].data<=m[j].data && m[j].p=="null")
     {
        m[j].p=pr[i].p;
        break;
     }
   }
}
cout<<"\nfirst fit output:\n";
print(m);


//best fit
assign(m);

for(int i=0;i<n;i++)
{   int val=INT_MAX;
   for(int j=0;j<4;j++)
   {
     if(pr[i].data<=m[j].data && m[j].p=="null")
     {
        if(val>m[j].data)
        {
          for(int k=0;k<4;k++)
          {
             if(val!=INT_MAX && m[k].data==val)
             m[k].p="null";
          }
          m[j].p=pr[i].p;
        //break;
          val=m[j].data;
        }
     }
   }
   
}
cout<<"\nbest fit output:\n";
print(m);


// worst fit
assign(m);

for(int i=0;i<n;i++)
{   int val=INT_MIN;
   for(int j=0;j<4;j++)
   {
     if(pr[i].data<=m[j].data && m[j].p=="null")
     {
        if(val<m[j].data)
        {
          for(int k=0;k<4;k++)
          {
             if(val!=INT_MIN && m[k].data==val)
             m[k].p="null";
          }
          m[j].p=pr[i].p;
        //break;
          val=m[j].data;
        }
     }
   }
   
}
cout<<"\nworst fit output:\n";
print(m);


}





#include<bits/stdc++.h>
using namespace std;

void scanr(vector<int>&v,int headstart,int tno)
{   
    cout<<headstart<<" ";
   vector<int> v2;
    vector<int>v3;
    for(int i=0;i<v.size();i++)
    {
        if(headstart<=v[i])
        {
            v2.push_back(v[i]);
        }
        else
        {
            v3.push_back(v[i]);
        }
    }
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end(),greater<int>());

   
   
    int totalheadmovement=0;
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<" ";
        totalheadmovement+=abs(v2[i]-headstart);
        headstart=v2[i];

    }
    totalheadmovement+=abs(headstart-(tno-1));
    cout<<tno-1<<" ";
    headstart=tno-1;
    for(int i=0;i<v3.size();i++)
    {
        cout<<v3[i]<<" ";
        totalheadmovement+=abs(v3[i]-headstart);
        headstart=v3[i];

    }

    cout<<"\n THE total distance is "<<totalheadmovement;

}
void scanl(vector<int>&v,int headstart,int tno)
{   
   cout<<headstart<<" ";
   vector<int> v2;
    vector<int>v3;
    for(int i=0;i<v.size();i++)
    {
        if(headstart<=v[i])
        {
            v2.push_back(v[i]);
        }
        else
        {
            v3.push_back(v[i]);
        }
    }
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end(),greater<int>());
    int totalheadmovement=0;
   
   for(int i=0;i<v3.size();i++)
    {
        cout<<v3[i]<<" ";
        totalheadmovement+=abs(v3[i]-headstart);
        headstart=v3[i];

    }
     totalheadmovement+=abs(headstart);
    cout<<"0 ";
    headstart=0;
    
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<" ";
        totalheadmovement+=abs(v2[i]-headstart);
        headstart=v2[i];

    }
   
    
    cout<<"\n THE total distance is "<<totalheadmovement;

}

int main()
{
    cout<<"\n enter the no.of tracks: ";
    int n,tno;
    cin>>n;
    cout<<"enter the total no of tracks";
    cin>>tno;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<"\nEnter the head start position: ";
    int headstart;
    cin>>headstart;
    cout<<"\nENter the direction :\n1 for right\n2 for left\n";
    int d;
    cin>>d;
   switch(d)
   {
        case 1:
        {
        scanr(v,headstart,tno);
        break;
        }

        case 2:
        { scanl(v,headstart,tno);
        break;
        }
        default:
        cout<<"invalid";
        
   }

    
    //scan(v,headstart,tno);
    return 0;
}
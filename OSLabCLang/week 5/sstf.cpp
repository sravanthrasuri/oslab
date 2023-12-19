#include<bits/stdc++.h>
using namespace std;

void sstf(vector<int>&tracks,int headstart)
{
    int totalheadmovements=0;
    cout<<"order of head movements :\n";
    cout<<headstart<<" ";
    while(tracks.size()!=0)
    {
        int mindis=INT_MAX;
        int nexttrack=-1;
         for(int i=0;i<tracks.size();i++)
         {
            if(abs((tracks[i]-headstart)<mindis))
            {
                mindis=abs(tracks[i]-headstart);
                nexttrack=tracks[i];
            }
         }
         totalheadmovements+=mindis;
         cout<<nexttrack<<" ";
         auto it=find(tracks.begin(),tracks.end(),nexttrack);
         tracks.erase(it);
        headstart=nexttrack;
    }
     cout<<"\nTotal number of tracks "<<totalheadmovements;
}


int main()
{
    cout<<"\n enter the no.of tracks: ";
    int n;
    cin>>n;
    vector<int> tracks(n);
    for(int i=0;i<n;i++)
    {
        cin>>tracks[i];
    }
    cout<<"\nEnter the head start position: ";
    int headstart;
    cin>>headstart;
    sstf(tracks,headstart);
    return 0;
}
/*
enter the no.of tracks: 7
98 183 40 122 10 124 65

Enter the head start position: 53
order of head movements :
53 65 10 40 98 122 124 183
Total number of tracks 240*/



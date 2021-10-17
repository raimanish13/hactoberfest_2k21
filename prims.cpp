
// Prims Algorithm for Minimum Spanning Tree using a Brute Force Approach.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"\nEnter the number of nodes and edges.\n";
    int n,m;
     cin>>n>>m;
    vector<pair<int,int>>adj[n];
    int u,v,wt;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
   
   vector<int>key(n,INT_MAX);
   vector<int>parent(n,-1);
   vector<bool>mst(n,false);
   key[0]=0;
   for(int i=0; i<n-1; i++)
   {
       int min=INT_MAX,U;
       // finding the min ele in key array
       for(int i=0; i<n; i++)
       {
           if(mst[i]==false && key[i]<min)
              min=key[i],U=i;
       }
       
       // once we find min ele we will marked as true in mst array
       
       mst[U]=true;
       // now we traverse the adj list for this min node
       for(auto it:adj[U])
       {
           if(mst[it.first]==false && it.second<key[it.first])
           {
               key[it.first]=it.second;
               parent[it.first]=U;
           }
       }
   }
   for(int i=1; i<n; i++)
    cout<<parent[i]<<" ";
    return 0;
}

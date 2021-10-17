// code for shortest path from a src to all node in directed weighted graph
#include<bits/stdc++.h>
using namespace std;
void ShortestPath(int src, int n, vector<pair<int,int>>adj[]);
void FindTopoSort(int node , vector<pair<int,int>>adj[],vector<int>&vis, stack<int>&st);
int main()
{
    cout<<"\nenter number of node and edges. \n";
    int n,m;
     cin>>n>>m;
    vector<pair<int,int>>adj[n];
     for(int i=0; i<m; i++)
     {
         int u,v,wt;
          cin>>u>>v>>wt;
          adj[u].push_back({v,wt});
     }
     ShortestPath(0,n,adj);
    
}

void ShortestPath(int src, int n, vector<pair<int,int>>adj[])
{
    vector<int>vis(n,0);
    stack<int>st;
    vector<int>dist(n,INT_MAX);
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            FindTopoSort(i,adj,vis,st);
        }
    }
    dist[src]=0;
    
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(dist[node]!=INT_MAX)
        {
          for(auto it:adj[node])
          {
            if(dist[node]+it.second< dist[it.first])
             dist[it.first]=dist[node]+it.second;
          }
        }
    }
    for(int i=0; i<n; i++)
     cout<<dist[i]<<" ";
}

void FindTopoSort(int node , vector<pair<int,int>>adj[],vector<int>&vis, stack<int>&st)
{
    vis[node]=1;
     for(auto it:adj[node])
     {
         if(!vis[it.first])
          FindTopoSort(it.first,adj,vis,st);
     }
     st.push(node);
}

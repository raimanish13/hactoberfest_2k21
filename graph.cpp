#include<bits/stdc++.h>
using namespace std;
void ShortestDistBFS(vector<int>adj[], int n , int src);
int main()
{
    cout<<"\nenter the number of nodes and edges of undirected graph\n";
    int n,m;
     cin>>n>>m;
     vector<int>adj[n];
    
     for(int i=0; i<m; i++)
     {
      int u,v;
      cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
     }
     
    ShortestDistBFS(adj,n,0);
    return 0;
     
}

void ShortestDistBFS(vector<int>adj[], int n,int src)
{
     vector<int>dist(n,INT_MAX);
     queue<int>q;
     dist[src]=0;
     q.push(src);
     
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(dist[node]+1<dist[it])
            {
                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
    }
    for(auto it:dist)
    cout<<it<<" ";
}

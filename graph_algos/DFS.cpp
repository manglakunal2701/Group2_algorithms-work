#include <bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&res){
    res.push_back(node);
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,res);
        }
    }
}
vector<int> dfsOfGraph(int V,vector<int>adj[]){
    vector<int>res;
    vector<int>vis(V,0);
    for(int i=1;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,adj,res);
        }
    }
    return res;
}
int  main(){
   cout<<"enter the nodes of graph"<<endl;
   int n,m;
   cin>>n;
   cout<<"Enter the number of edges of graph"<<endl;
   cin>>m;
   vector<int> arr[n+1];
   for(int i=0;i<m;i++){
       int u,v;
       cin>>u;
       cin>>v;
       arr[u].push_back(v);
       arr[v].push_back(u);     //remove this for directed gragh;
   }
   for(int i=1;i<n+1;i++){
       cout<<i<<"->";
       for(int x:arr[i]){
           cout<<x<<" ";
       }cout<<endl;
   }
    vector<int> res=dfsOfGraph(n+1,arr);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<"->";
    }    
 }
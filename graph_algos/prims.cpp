#include <bits/stdc++.h>
using namespace std;
int  main(){
   cout<<"enter the nodes of graph"<<endl;
   int n,m;
   cin>>n;
   cout<<"Enter the number of edges of graph"<<endl;
   cin>>m;
   vector<pair<int,int>> arr[n+1];
   for(int i=0;i<m;i++){
       int u,v,wt;
       cin>>u;
       cin>>v;
       cin>>wt;
       arr[u].push_back({v,wt});
       arr[v].push_back({u,wt});
   }
   for(int i=1;i<n+1;i++){
       cout<<i<<"->";
       for(auto it=arr[i].begin();it!=arr[i].end();it++){
           cout<<"{"<<it->first<<" "<<it->second<<"}";
       }cout<<endl;
   }
   int key[n+1];
   bool mst[n+1];
   int parent[n+1];
   for(int i=1;i<n+1;i++){
       key[i]=INT_MAX;
       mst[i]=false;
   }
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   key[1]=0;
   parent[1]=-1;
   pq.push({0,1});///dist,node
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        mst[u]=true;
        for(auto it:arr[u]){
            int v= it.first;//take that adjacent node
            int weight= it.second;//take that adjacent node weight for comparison;
            if(mst[v]==false && key[v]>weight){
                key[v]=weight;
                parent[v]=u;
                pq.push({key[v],v});
            }
        }

    }
    for(int i=2;i<n+1;i++){
        cout<<parent[i]<<"-"<<i<<"\n";
    }



}
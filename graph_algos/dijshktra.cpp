#include <bits/stdc++.h>
using namespace std;
void printParent(vector<int>&parent,int u){
    cout<<u<<" ";
    if(parent[u]>=0){
        printParent(parent,parent[u]);
    }
    
}
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
  // shortestPath(1,n+1,arr);
   int src;
   cout<<"Enter the source node"<<endl;
   cin>>src;
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>distArray(n+1,INT_MAX);
     vector<int> parent(n+1,0);
     parent[src]=-1;
    distArray[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        vector<pair<int,int>>::iterator it;
        for(it=arr[prev].begin();it!=arr[prev].end();it++){
            if(distArray[prev]+ it->second < distArray[it->first]){
               distArray[it->first]=distArray[prev]+ it->second ;
               pq.push(make_pair(distArray[it->first],it->first));
               parent[it->first]=prev;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        cout<<distArray[i]<<" ";
    }
    // C:\Users\Kunal Mangla\Desktop\DSA_algorithms\GraphQuestions\DijkstraAlgoShortestPathUndirected.cpp
    cout<<endl<<"the shortest distance of each vertex from source node is:"<<endl;
    for(int i=1;i<parent.size();i++){
        printParent(parent,i);
         if (distArray[i] == INT_MAX)
            cout << ": INF" << endl;
        else
            cout << ": " << distArray[i] << endl;    
    }

 }
   
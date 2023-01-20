#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<int,pair<int,int>>> vii;
int findPar(int u,vector<int>&parent){
    if(parent[u]==u)return u;
    return parent[u]=findPar(parent[u],parent);
}
void unionByRank(int u,int v,vector<int>&parent,vector<int> &rank){
    u=findPar(u,parent);
    v=findPar(v,parent);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
vii kruskal(vii arr,int V){
    vii res;
    int s ,d,wt;
    vector<int> parent(V);
    for(int i=0;i<V;i++){
        parent[i]=i;
    }
    sort(arr.begin(),arr.end());
    vector<int> rank(V,0);
    int E=arr.size();
    for(int i=0;i<E;i++){
        s= arr[i].second.first;
        d=arr[i].second.second;
        wt=arr[i].first;
        if(findPar(s,parent)!=findPar(d,parent)){
            res.push_back(arr[i]); 
            unionByRank(s,d,parent,rank);
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
  vii arr;
   for(int i=0;i<m;i++){
      
       int x,y,wt;
       cin>>x>>y>>wt;
       arr.push_back(make_pair(wt,make_pair(x,y)));
   }
   vii res= kruskal(arr,n);
   int sum=0;
   for(int i=0;i<res.size();i++){
       int w= res[i].first;
       cout<<res[i].second.first<<" "<<res[i].second.second<<endl;
       sum+=w;
   }
   cout<<"sum of weight ="<<sum<<endl;

   

}
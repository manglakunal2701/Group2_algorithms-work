#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    cout<<"now enter the number of edges "<<endl;
    cin>>m;
    
    vector<pair<int,pair<int,int>>>arr;
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        arr.push_back(make_pair(wt,make_pair(x,y)));
    }
    cout<<"graph you entered is:"<<endl;
     for(int i=0;i<arr.size();i++){
       cout<<arr[i].second.first<<" "<<arr[i].second.second<<" "<<arr[i].first<<endl;
   }
   int sum=0;
   vector<int>dist(n,INT_MAX);
   dist[0]=0;
   for(int i=0;i<n-1;i++){
        for(auto it:arr){
           int wt= it.first;
           int x=it.second.first;
           int y=it.second.second;
           if(dist[x]+wt< dist[y]){
               dist[y]=dist[x]+wt;
           }
       }
   }
   int flag=0;
    for(int it=0;it<arr.size();it++){
       int wt= arr[it].first;
       int x=arr[it].second.first;
       int y=arr[it].second.second;
       if(dist[x]+wt< dist[y]){
          cout<<"Negative cycle"<<endl;
           flag=-1;
           break;
        }
   }
   if(flag==0){
        for(int i=0;i<dist.size();i++){
            cout<<dist[i]<<" ";
        }
        cout<<"Shortest path is:"<<sum<<endl;
   }
}
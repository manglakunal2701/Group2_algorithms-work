#include <bits/stdc++.h>
using namespace std;
const int  INF = 99999;
int main(){
    vector<vector<int>>arr{ {0,10,5,5,INF},
                    {INF,0,5,5,5},
                    {INF, INF, 0,INF,10},
                    {INF, INF, INF, 0,20},
                    {INF,INF,INF,5,0}
                  };
    int n=arr.size();
                
    cout<<"Matrix you entered is:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    vector<vector<int>>dist=arr;
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]==INF ){
                cout<<"INF ";
            }
            else
            cout<<dist[i][j]<<" ";   
        }cout<<endl;
    }
}
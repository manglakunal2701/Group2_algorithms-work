#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of activities"<<endl;
    cin>>n;
    vector<pair<int,int>>arr;
    cout<<"enter start time and end time of activities"<<endl;
    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        arr.push_back({e,s});  //first push final because we have to sort it
    }
   
    sort(arr.begin(),arr.end());//sort the final state in ascending order......
    for(int i=0;i<n;i++){
        cout<<i<<"->";
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }
    int count=0;
    int curridx=-1;  ///this will store the final time of state booked 
    vector<int>res;
    for(int i=0;i<n;i++){
        if(arr[i].second>=curridx){//initial time should be greater than final time
            count++;
            curridx=arr[i].first;   //update the new booked final time
            res.push_back(i+1);
        } 
    }
    cout<<"Activities selected are "<<count<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}
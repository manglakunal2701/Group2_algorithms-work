#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>a, pair<int,int>b){
    return a.first>b.first;
}
int main(){
    int n;
    cout<<"Enter the number of taska"<<endl;
    cin>>n;
    vector<pair<int,int>>arr;
    cout<<"Enter the profit and deeadline of all tasks"<<endl;
    for(int i=0;i<n;i++){
        int dl;
        int pf;
        cin>>pf>>dl;
        arr.push_back({pf,dl});
    }
   sort(arr.begin(),arr.end(),compare);
   for(int i=0;i<n;i++){
       cout<<i<<"->";
       cout<<arr[i].first<<" "<<arr[i].second<<endl;
   }
   int maxi=0;
   for(int i=0;i<n;i++)
   {
       maxi=max(maxi,arr[i].second);
    }
    cout<<"MAximum dead line is "<<maxi<<endl;
    int fill[maxi];
    for(int i=0;i<maxi;i++){
        fill[i]=-1;
    }
    int count=0,profit=0;
    for(int i=0;i<n;i++){
        int j=arr[i].second - 1;
        while(j>=0 && fill[j]!=-1){
            j--;
        }
        if(j>=0 && fill[j]==-1){
            fill[j]=i;
            profit=profit+arr[i].first;
            count++;
        }
    }
    cout<<"maximum profit is "<<profit<<" And count is "<<count<<endl;
   
}
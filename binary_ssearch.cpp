#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void binarysearch(vector<int>&arr,int a){
    int end=arr.size();
    int start=0;
    while(start<end){
        int mid = (start+end)/2;
        if(arr[mid]==a){
            cout<<"Element found "<<endl;
            return;
        }
        else if(arr[mid]>a){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    cout<<"element not found"<<endl;
}
int main(){
    int n;
    cout<<"Enter no of elements"<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter the value to find"<<endl;
    int a;
    cin>>a;
    sort(arr.begin(),arr.end());
    binarysearch(arr,a);
    
    return 0;
}
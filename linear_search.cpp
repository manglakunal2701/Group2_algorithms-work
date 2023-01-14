#include<iostream>
#include<vector>
using namespace std;
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
    for(int i=0;i<n;i++){
        if(arr[i]==a){
            cout<<"element found at postion "<<i+1 <<endl;
            return 0;
        }
    }
    cout<<"Element not found"<<endl;
    return 0;
}
#include<iostream>
using namespace std;
void insertionSort(int arr[],int n){
    int j=0;
    int comp=0;
    for(int i=0;i<n;i++){
        int c=arr[i];
        j=i-1;
        while(c<arr[j] && j>=0){
                arr[j+1]=arr[j];
                comp++;
                j--;
        }
        arr[j+1]=c;
    }
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"Total Number of comparisons are: "<<comp<<endl;
}
int main(){
    int n;
    cout<<"Enter the number pf elements"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionSort(arr,n);
   return 0;
   
}
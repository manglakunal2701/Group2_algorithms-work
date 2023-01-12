#include<iostream>
using namespace std;
int counter =0;
int partition(int array[],int start,int end){
      int pivot = array[end];
    int i = start - 1;

    for(int j = start; j <= end - 1; j++){
        if (array[j] <= pivot){
            i = i + 1;
             swap(array[i],array[j]);
        }
        counter++;
    }
    cout<<i<<" "<<endl;
    swap(array[i+1] ,array[end]);
    for(int i=start;i<=end;i++){
        cout<<array[i]<<" ";
    }cout<<endl;
    return i + 1;
}
void quickSort(int arr[],int start,int end){
    if(start<end){
        int pivot = partition(arr,start,end);
        quickSort(arr,start,pivot-1);
        quickSort(arr,pivot+1,end);
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<counter;

}
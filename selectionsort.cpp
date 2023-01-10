#include<iostream>
using namespace std;
void selectionSort(int a[],int n){
     int pos,min=0,comp=0;
    for(int i=0;i<n-1;i++)
    {
        min=a[i];
        pos=i;
        for(int j=i+1;j<n;j++)
        {
            comp++;
          if(min>a[j])
          {
              min=a[j];
              pos=j;
          }
        }
        if(pos!=i)
        {
            a[pos]=a[i];
            a[i]=min;
        }
    }
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
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
   selectionSort(arr,n);
}


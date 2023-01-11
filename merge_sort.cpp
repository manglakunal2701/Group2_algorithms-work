#include <iostream>
using namespace std;
int count=0;          // to calculate total no of comparisons
int merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
    int LeftArray[n1], RightArray[n2]; 
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];        
    i = 0;   
    j = 0; 
    k = beg;      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++; 
        count++;   
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    } 
    return count;   
} 
int mergeSort(int arr[],int start,int end){
    int comp;
    if(start<end ){
    int mid= (start+end)/2;
    mergeSort( arr, start, mid);
    mergeSort( arr, mid+1, end);
    comp =merge(arr,start,mid,end);
    }
    return comp;
}
int main(){
   int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
  int cnt=0;
  cnt= mergeSort(arr,0,n-1);
   for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
   }
   cout<<endl<<cnt;

}
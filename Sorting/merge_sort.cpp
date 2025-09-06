#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//Time complexity : for each best, worst and avg case is : O(Nlog2N)
//Space complexity : for each best, worst and avg case is :O(N)

void merge(int arr[],int low,int mid,int high){

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int a[n1];
    int b[n2];

    for(int k = 0;k<n1;k++){
        a[k] = arr[low + k];
    }

    for(int k = 0;k<n2;k++){
        b[k] = arr[mid + 1 + k];
    }

    int i = 0 , j = 0, k = low;

    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k] = b[j];
            j++;
            k++;
        }
    }

    while(i<n1){
        arr[k] = a[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k] = b[j];
        j++;
        k++;
    }

}

void merge_sort(int arr[],int low,int high){

    if(low<high){
        int mid = (low + high) / 2; 
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }

}


int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }

    merge_sort(arr,0,n-1);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}
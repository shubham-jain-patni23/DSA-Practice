#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//time complexity in worst and avg case : O(n^2)
//time complexity in best case : O(1)

void insertion_sort(int arr[],int n){
    
    for(int i = 1;i<=n-1;i++){          //we insert all the new idx in the sorted array
        int j = i - 1;
        int key = arr[i];

        while(j>=0 && arr[j] >= key){
            arr[j+1] =arr[j];
            j--;
        }
        arr[j+1] = key;
    }

}

void fun(int arr[],int n){

    for(int i =1;i<=n-1;i++){
        int j = i;
        while(j > 0){
            if(arr[j] < arr[j-1]){
                swap(arr,j,j-1);
            }
            j--;
        }
    }

}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }

    fun(arr,n);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}
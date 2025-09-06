#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//time complexity : best and avg case : O(nlog2n) and in worst case O(N^2)
//space complexity : O(1)

//here I am considering the last ele to be my pivot whose idx is returned by this function
int pivot(int arr[],int low,int high){

    int i = low - 1;        //till i all ele are smaller than pivot ele
    int curr = low;         //curr iterates through the array

    int ele = arr[high];

    while(curr<= (high-1)){
        if(arr[curr] < ele){            
            i++;
            swap(arr,i,curr);
        }
        curr++;
    }
    swap(arr,i+1,high);
return i + 1;
}

//here I am considering the first ele to by my pivot whose idx is returned by this function
int pivot2(int arr[],int low,int high){
    int i = high  + 1;
    int curr = high;

    int ele = arr[low];

    while(curr > low){
        if(arr[curr] > ele){
            i--;
            swap(arr,i,curr);
        }
        curr--;
    }
    swap(arr,i-1,low);
return i-1;
}

void quick_sort(int arr[],int low,int high){
    if(low<high){
        int pivot_pt = pivot2(arr,low,high);
        quick_sort(arr,low,pivot_pt-1);
        quick_sort(arr,pivot_pt+1,high);
    }
}

int main(){

    int n;
    cin>>n;

    int arr[n];  

    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }
    
    quick_sort(arr,0,n-1);

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }

return 0;
}
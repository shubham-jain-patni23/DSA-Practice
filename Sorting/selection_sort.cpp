#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//time complexity will be O(n^2) in all the cases whether it is best, avg or worst.
void selection_sort(int arr[],int n){

    for(int i = 0;i<n-1;i++){
        int mini = i;
        for(int j = i + 1;j<n;j++){
            if(arr[mini] > arr[j]){
                mini = j;
            }
        }
        swap(arr,mini,i);
    }

}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }

    selection_sort(arr,n);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}
#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//time complexity will be O(n^2) in all the cases whether it is best, avg or worst if we don't use flag 
//if we use flag then the avg and worst case time complexity is O(n^2) while the best case is O(n)

void bubble_sort(int arr[],int n){
    for(int i = 1;i<=n-1;i++){
        int didswap = 0;
        for(int j = 0;j<n - i;j++){             //accessing an idx which doesn't exits gives runtime error.
            if(arr[j] > arr[j+1]){
                swap(arr,j,j+1);
                didswap = 1;
            }
        }
        if(didswap==0){
            break;
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

    bubble_sort(arr,n);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}
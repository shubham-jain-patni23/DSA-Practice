#include<bits/stdc++.h>
using namespace std;

void rev_recur(int arr[],int i,int j){              //using recursion and two pointers
    if(i>=j){
        return ;
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    rev_recur(arr,i+1,j-1);
}

void rev_recur2(int arr[],int i, int n){
    if(i>=(n/2)){
        return ;
    }

    int temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n-i-1] = temp;
    rev_recur2(arr,i+1,n);
}   

void rev(int arr[],int n){  //done by swapping the two pointers

    int i = 0 , j = n-1;

    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }   

}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    //reverse(arr, arr+n);      in_built stl fun

    rev_recur2(arr,0,n);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }

return 0;
}
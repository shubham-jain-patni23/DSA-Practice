#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n][n];

    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    //approach 1 ; transpose and then swap

    //transpose

    for(int i =0;i<n;i++){
        for(int j = 0;j<i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    int start = 0, end = n-1;

    while(start<end){
        for(int i = 0;i<n;i++){
            swap(arr[i][start], arr[i][end]);
        }
        start++;
        end--;
    }

    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

return 0;
}
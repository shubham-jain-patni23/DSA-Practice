#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    bool ans = true;

    for(int i = 1;i<n;i++){
        if(arr[i] < arr[i-1]){
            ans = false;
            break;
        }
    }

    ans==1 ? cout<<"array is sorted" : cout<<"array is not sorted";
    cout<<endl;

return 0;
}
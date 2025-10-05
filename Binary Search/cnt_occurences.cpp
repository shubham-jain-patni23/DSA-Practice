#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//approach ; using first and last together 

vector<int> first_and_last(int arr[],int n,int x){
    int ans = lower_bound(arr, arr + n, x) - arr;
    if(ans==n || arr[ans]!=x) return {-1,-1};

return {ans, (upper_bound(arr,arr+n,x) - arr) -1 };
}

int main(){

    int n;
    cin>>n;

    int target;
    cin>>target;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    
    vector<int> temp = first_and_last(arr, n,  target);
    if(temp[0]==-1){
        cout<<0<<endl;
    }
    else{
        cout<<temp[1] - temp[0] + 1<<endl;
    }

return 0;
}
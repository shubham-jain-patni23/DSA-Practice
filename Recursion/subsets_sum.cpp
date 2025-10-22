#include<iostream>
#include<vector>
using namespace std;

// approach 1;  TC ---> O(2^n)  ; SC ---> O(n)
// using recursion finding sum of all subsets

void fun(int arr[],int n,int idx, int currsum, vector<int> &ans){
    if(idx==n){
        ans.push_back(currsum);
        return;
    }
    // take idx
    fun(arr,n,idx+1,currsum+arr[idx],ans);

    // don't take idx
    fun(arr,n,idx+1,currsum,ans);

}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> ans;

    fun(arr,n,0,0,ans);

    for(auto i: ans){
        cout<<i<<" ";
    }

return 0;
}
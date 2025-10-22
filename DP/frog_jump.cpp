#include<iostream>
#include<vector>
using namespace std;

// appraoch 1: using recursion ; TC ---> O(2^n) ; SC ---> O(n)
// min energy to reach n-1 from idx 
int fun(int n,vector<int>&arr,int idx){

    if(idx==n-1){
        return 0;
    }
    if(idx == n-2){
        return abs(arr[idx] - arr[idx + 1]);
    }

    int one = abs(arr[idx] - arr[idx + 1])  + fun(n,arr,idx + 1);
    int two = abs(arr[idx] - arr[idx + 2]) + fun(n,arr,idx + 2);

return min(one, two);
}

// appraoch 2: using dp(memoization) ; TC ---> O(n) ; SC ---> O(2n)

int fundp(int n,vector<int>&arr,int idx, vector<int>&dp){
    
    // if we are on the last stair
    if(idx==n-1){
        return 0;
    }
    // if we are on the second last stair
    if(idx==n-2){
        return abs(arr[idx] - arr[idx+1]);
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    
    int one = abs(arr[idx] - arr[idx+1]) + fundp(n,arr,idx+1,dp);     // jump one step
    int two = abs(arr[idx] - arr[idx + 2]) + fundp(n,arr,idx+2,dp);   // jump two steps

    dp[idx] = min(one,two);
return dp[idx];
}

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int ans = fun(n,arr,0);
    cout<<ans<<endl;

    vector<int> dp(n,-1);
    ans =fundp(n,arr,0,dp);
    cout<<ans<<endl;

    // approach 3; using tabulation; TC ---> O(n) ; SC ---> O(n)
    // we require mini dis from the next two stairs in recursion so we calc them in advance
    dp[n-1] = 0 ; 
    if(n!=1){
        dp[n-2] = abs(arr[n-2] - arr[n-1]);
    }

    for(int i = n-3;i>=0;i--){
        int one = abs(arr[i] - arr[i+1]) + dp[i+1];
        int two = abs(arr[i] - arr[i+2]) + dp[i+2];
        dp[i] = min(one,two);
    }

    cout<<dp[0]<<endl;

    // approach 4; not using dp array only two var ; TC ---> O(n) ; SC ---> O(1)

    int second = 0 ; 
    int first;
    if(n!=1){
        first = abs(arr[n-2] - arr[n-1]);
    }

    for(int i = n-3;i>=0;i--){
        int one = abs(arr[i] - arr[i+1]) + first;
        int two = abs(arr[i] - arr[i+2]) + second;
        second = first;
        first = min(one,two);
    }

    if(n==1){
        first = second;
    }

    cout<<first<<endl;
    
return 0;
}
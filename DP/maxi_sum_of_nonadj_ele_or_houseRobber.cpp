#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// approach 1: using recursion ; TC ---> O(2^n) ; SC ---> O(n)
// maxi cost from idx to n-1
int fun(int n,vector<int>&arr,int idx){

    if(idx >= n){
        return 0;
    }

    // taking arr[idx]
    // int ans = arr[idx] + fun(n,arr,idx + 2);

    // not taking arr[idx]
    // ans = max(ans, fun(n,arr,idx + 1));

return max(arr[idx] + fun(n,arr,idx + 2) , fun(n,arr,idx + 1));
}

// approach 2: using dp(memoization) ; TC ---> O(n) ; SC ---> O(2n)

int fundp(int n,vector<int>&arr,int idx,vector<int>&dp){
    
    if(idx>=n){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    dp[idx] = max(arr[idx] + fun(n,arr,idx + 2) , fun(n,arr,idx + 1));
return dp[idx];
}

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int ans = fun(n, arr, 0);
    cout<<ans<<endl;

    vector<int> dp(n,-1);

    ans = fundp(n,arr,0,dp);
    cout<<ans<<endl;

    // approach 3: using dp(tabulation) ; TC ---> O(n) ; SC ---> O(1)
    // if we are including or not the curr idx then we need to check the maxi cost from idx +1 or idx + 2
    // so we calc them in adv

    dp[n-1] = arr[n-1];
    dp[n-2] = max(arr[n-2], arr[n-1]);

    for(int i = n-3;i>=0;i--){
        dp[i] = max(arr[i] + dp[i+2] , dp[i+1]);
    }

    cout<<dp[0]<<endl;

    // approach 4: using dp(tabulation) ; TC ---> O(n) ; SC ---> O(1)

    int first = 0;
    int second = 0;

    for(int i = n-1;i>=0;i--){
        int x = max(arr[i] + second, first);
        second = first;
        first = x;
    }

    cout<<first<<endl;

return 0;
}
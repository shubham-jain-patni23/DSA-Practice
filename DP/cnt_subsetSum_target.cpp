#include<iostream>
#include<vector>
using namespace std;

// approach1 ; using recursion; TC ---> O(2^n) ; SC ---> O(n)
// no. of subsets from idx when we had currsum,whose sub is target
// we must reach end to return else some cases may be left
int fun(int n,vector<int>&arr,int idx,int currsum,int target){

    if(idx==n){
        if(currsum==target){
            return 1;
        }
        return 0;
    }

    if(currsum > target){
        return 0;
    }

    // when we take arr[idx] ; no of subsets
    int x = fun(n,arr,idx + 1,currsum+arr[idx],target);
    
    // when we don't take arr[idx] ; no of subsets
    int y = fun(n,arr,idx + 1,currsum,target);

return x + y;
}

// dp[idx][curr] means when we were at idx and current sum was curr, then no. of ways to reach target 
int fundp(int n,vector<int>&arr,int idx,int curr,int target,vector<vector<int>>&dp){
    if(idx==n){
        if(curr==target){
            return 1;
        }
        return 0;
    }
    if(curr > target){
        return 0 ;
    }
    if(dp[idx][curr]!=-1){
        return dp[idx][curr];
    }
    int x = fundp(n,arr,idx + 1,curr + arr[idx],target,dp);
    int y = fundp(n,arr,idx +1,curr,target,dp);
return dp[idx][curr] = x + y;
}

int main(){

    int n;
    cin>>n;

    int target;
    cin>>target;

    vector<int> arr(n);  

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    // approach 1

    int ans = fun(n,arr,0,0,target);
    cout<<ans<<endl;

    // approach 2; using dp(memoization); TC ---> O(n*target) ; SC ---> O(n*target) + O(n)

    vector<vector<int>> dpp(n,vector<int>(target+1,-1));
    ans = fundp(n,arr,0,0,target,dpp);
    //cout<<dp[0][0]<<endl;
    cout<<ans<<endl;

    // approach 3; using dp(tabulation); TC ---> O(n*target) ; SC ---> O(n*target)
    // dp[i][j] means using the arr till i no of ways to make sum j

    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    dp[0][0] = 1;

    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=target;j++){
            dp[i][j] = dp[i-1][j] ;
            if((j - arr[i - 1]) >=0){
                dp[i][j] += dp[i-1][j-arr[i-1]];
            }
        }
    }

    cout<<dp[n][target]<<endl;

    // approach 4; space optimization; TC ---> O(n*target) ; SC ---> O(2*target)
    // we need the knowledge of only the prev row
    // while filling dp arr

    vector<int> prev(target+1,0);
    prev[0] = 1 ; // no. of ways to make 0 without using any ele

    for(int i =1;i<=n;i++){
        vector<int>temp(target+1);
        for(int j =0;j<=target;j++){
            temp[j] = prev[j];
            if((j - arr[i-1]) >=0){
                temp[j]+= prev[j - arr[i-1]];
            }
        }
        prev = temp;
    }
    cout<<prev[target]<<endl;

return 0;
}
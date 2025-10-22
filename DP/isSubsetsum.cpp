#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// approach 1; using recursion ; TC ---> O(2^n) ; SC ---> O(n)
// from idx till end whether currsum can be derived

bool fun(int n,vector<int>&arr,int idx,int currsum,int target){

    // if currsum eq target
    if(currsum==target){
        return true;
    }

    // currsum is greater than target
    if(currsum > target){
        return false;
    }

    // currsum is lesser than target
    if(idx==n){
        return false;
    }

    // currsum is lesser than target and also idx < n

    // take ele 
    bool x = fun(n,arr,idx+1,currsum + arr[idx], target);
    // don't taking ele
    bool y = fun(n, arr, idx + 1, currsum, target);
return (x || y);
}

// fun tells whether from idx and with currsum we can reach to target or not
bool fundp(int n,vector<int> &arr,int idx,int currsum,int target,vector<vector<int>>&dp){

    if(currsum==target){
        return true;
    }
    if(currsum > target){
        return false;
    }
    if(idx==n){
        return false;
    }
    if(dp[idx][currsum]!=-1){
        return (bool)dp[idx][currsum];
    }

    dp[idx][currsum] = (int)(fundp(n,arr,idx+1,currsum+arr[idx],target,dp) || fundp(n,arr,idx+1,currsum,target,dp));
return (bool)dp[idx][currsum];
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

    bool ans = fun(n,arr,0,0,target);
    
    if(ans){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

    // approach 2; using dp(memoization); TC ---> O(n*target) ; SC ---> O(n*target) + O(n)
    // there may be overlapping subproblems in some case

    vector<vector<int>> dpp(n,vector<int>(target,-1));

    ans = fundp(n,arr,0,0,target,dpp);
    if(ans){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

    // approach 3; using dp(tabulation); TC ---> O(n*target) ; SC ---> O(n*target)
    // till each idx checking whether a particular sum can be derived or not

    vector<vector<bool>> dp(n+1,vector<bool>(target+1));

    for(int i = 0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i = 1;i<= target;i++){
        dp[0][i] = 0 ;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=target;j++){

            // not taking arr[i-1]
            dp[i][j] = dp[i-1][j];

            // taking arr[i-1]
            int x = j - arr[i-1];
            if(x>=0){
                dp[i][j] = dp[i][j] || dp[i-1][x];
            }
        }
    }

    if(dp[n][target]){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

    // approach 4; space optimization in tabulation; TC ---> O(n*target) ; SC ---> O(2*target)
    // we need the knowledge of only last row

    vector<bool> prev(target+1,0);
    prev[0] = 1;

    for(int i = 1;i<=n;i++){
        vector<bool> temp(target+1);
        for(int j = 0 ; j<=target;j++){
            if(j==0){
                temp[j] = 1;
            }
            temp[j] = prev[j];
            if((j - arr[i-1]) >= 0){
                temp[j] = temp[j] || prev[j - arr[i -1]];
            }
        }
        prev = temp;
    }

    if(prev[target]){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

return 0;
}
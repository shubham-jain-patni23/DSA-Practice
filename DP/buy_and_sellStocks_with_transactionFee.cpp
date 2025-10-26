#include<iostream>
#include<vector>
using namespace std;

// approach 1; TC ---> O(2^n) ; SC ---> O(n)

// approach 1; TC ---> O(2^n) ; SC ---> O(n)
// whenever we buy we suffer loss
// wheneven we sell we gain profit
int fun2(int idx,vector<int>&arr,int buy,int fee){

    if(idx==arr.size()){
        return 0;
    }

    int profit;

    if(buy==1){
        // buy 
        int x = -(arr[idx] + fee) + fun2(idx + 1, arr, 0,fee);
        // not buy
        int y = fun2(idx + 1, arr, 1,fee);
        profit = max(x,y);
    }
    else{
        // sell 
        int x = arr[idx] + fun2(idx + 1, arr, 1,fee);
        // not sell
        int y = fun2(idx + 1, arr, 0,fee);
        profit = max(x,y);
    }
return profit;
}

int fundp2(int idx,vector<int>&arr,int buy,vector<vector<int>>&dp,int fee){

    if(idx==arr.size()){
        return 0;
    }

    if(dp[idx][buy]!=-1){
        return dp[idx][buy];
    }

    int profit;

    if(buy==1){
        // buy 
        int x = -(arr[idx]+fee) + fundp2(idx + 1, arr, 0,dp,fee);
        // not buy
        int y = fundp2(idx + 1, arr, 1,dp,fee);
        profit = max(x,y);
    }
    else{
        // sell 
        int x = arr[idx] + fundp2(idx + 1, arr, 1,dp,fee);
        // not sell
        int y = fundp2(idx + 1, arr, 0,dp,fee);
        profit = max(x,y);
    }
return dp[idx][buy] = profit;
}

int main(){

    int n;
    cin>>n;

    int fee;
    cin>>fee;

    vector<int> arr(n);

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    // approach 1;
    int ans = fun2(0,arr,1,fee);
    cout<<ans<<endl;

    // appraoch 2; using dp(memoization); TC ---> O(n*2); SC ---> O(n*2) + O(n)
    vector<vector<int>> dp2(n+1,vector<int>(2,-1));
    ans = fundp2(0,arr,1,dp2,fee);
    cout<<ans<<endl;
    
    // approach 3; using dp(tabulation); TC ---> O(n*2); SC ---> O(n*2)

    dp2[n][0] = 0;
    dp2[n][1] = 0;

    for(int i = n-1;i>=0;i--){
        for(int j =0;j<2;j++){
            if(j==1){
                // buy
                int x = -(arr[i]+fee) + dp2[i+1][0];
                // not buy
                int y = dp2[i+1][1];
                dp2[i][j] = max(x,y);
            }
            else{
                // sell 
                int x = arr[i] + dp2[i+1][1];
                // not sell
                int y = dp2[i+1][0];
                dp2[i][j] = max(x,y);
            }
        }
    }
    cout<<dp2[0][1]<<endl;

    // approach 4; TC ---> O(n*2); SC ---> O(2*2)
    // we need the knowledge of only the next row

    vector<int> next(2,0);
    for(int i = n-1;i>=0;i--){
        vector<int> curr(2);
        for(int j =0 ;j<2;j++){
            if(j==1){
                // buy
                int x = -(arr[i]+fee) + next[0];
                // not buy
                int y = next[1];
                curr[j] = max(x,y);
            }
            else{
                // sell 
                int x = arr[i] + next[1];
                // not sell
                int y = next[0];
                curr[j] = max(x,y);
            }
        }
        next = curr;
    }
    cout<<next[1]<<endl;

return 0;
}
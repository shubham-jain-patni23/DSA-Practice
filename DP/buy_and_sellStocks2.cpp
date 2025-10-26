#include<iostream>
#include<vector>
using namespace std;

// approch 1; using recursion; TC ---> O(2^n); SC ---> O(n)

// fun(i,arr,j) means what maxi profit we can earn from arr from idx i till end and when we have either no stock 
// or have a stock whose price is curr
// we gain some profit only when we sell, here we need to remember the prev stock price 
// when we sell to compute profit

int fun(int idx,vector<int>&arr,int curr){

    if(idx==arr.size()){
        return 0;
    }

    // we don't have any prev stock or if curr stock price is lesser
    if(curr==-1 || arr[idx] < curr){    // buy
        return fun(idx + 1, arr, arr[idx]);
    }

    // if curr stock price is more or eq

    // don't sell 
    int x = fun(idx + 1, arr, curr);

    // sell
    int y = (arr[idx] - curr) + fun(idx + 1, arr, arr[idx]);

return max(x,y);
}

int fundp(int idx,vector<int>&arr,int curr,vector<vector<int>>&dp){

    if(idx==arr.size()){
        return 0;
    }

    if(dp[idx][curr]!=-1){
        return dp[idx][curr];
    }

    int nostock = dp[0].size() -1;

    // we don't have any prev stock or if curr stock price is lesser
    if(curr== nostock || arr[idx] < curr){    // buy
        return dp[idx][curr] = fundp(idx + 1, arr, arr[idx],dp);
    }

    // if curr stock price is more or eq

    // don't sell 
    int x = fundp(idx + 1, arr, curr,dp);

    // sell
    int y = (arr[idx] - curr) + fundp(idx + 1, arr, arr[idx],dp);

return dp[idx][curr] = max(x,y);
}

// approach 5; TC ---> O(2^n) ; SC ---> O(n)

// fun2(i,0) means what maxi profit we can earn from idx i till end when we are not allowed to buy only sell
// fun2(i,1) means what maxi profit we can earn from idx i till end when we are not allowed to sell only buy
// whenever we buy we are in loss 
// whenever we sell we are in profit 
// so we don't need to remember the val of past stock that we bought
int fun2(int idx,vector<int>&arr,bool buy){

    if(idx==arr.size()){
        return 0;
    }

    int profit;

    if(buy){
        // buy 
        int x = -arr[idx] + fun2(idx + 1, arr, 0);
        // not buy
        int y = fun2(idx + 1, arr, 1);
        profit = max(x,y);
    }
    else{
        // sell 
        int x = arr[idx] + fun2(idx + 1, arr, 1);
        // not sell
        int y = fun2(idx + 1, arr, 0);
        profit = max(x,y);
    }
return profit;
}

int fundp2(int idx,vector<int>&arr,int buy,vector<vector<int>>&dp){

    if(idx==arr.size()){
        return 0;
    }

    if(dp[idx][buy]!=-1){
        return dp[idx][buy];
    }

    int profit;

    if(buy==1){
        // buy 
        int x = -arr[idx] + fundp2(idx + 1, arr, 0,dp);
        // not buy
        int y = fundp2(idx + 1, arr, 1,dp);
        profit = max(x,y);
    }
    else{
        // sell 
        int x = arr[idx] + fundp2(idx + 1, arr, 1,dp);
        // not sell
        int y = fundp2(idx + 1, arr, 0,dp);
        profit = max(x,y);
    }
return dp[idx][buy] = profit;
}

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    // approach 1
    int ans = fun(0,arr,-1);
    cout<<ans<<endl;

    // approach 2; using dp(memoization); TC ---> O(n*maxi) ; SC ---> O(n)
    // to represent no curr stock we can reprement it by maxi + 1

    int maxi = arr[0];
    for(int i = 1;i<n;i++){
        maxi = max(maxi , arr[i]);
    }

    vector<vector<int>>dp(n,vector<int>(maxi + 2,-1));
    ans = fundp(0,arr,maxi + 1,dp);
    cout<<ans<<endl;

    // approach 3; using dp(tabulation); 
    // dp[i][j] means what maxi profit we can achieve from idx i till end 
    // when we have curr stock j

    for(int i = 0;i<=maxi + 1;i++){
        dp[n-1][i] = 0;
        if(arr[n-1] > i){
            dp[n-1][i] = arr[n-1] - i;
        }
    }

    for(int i = n-2;i >= 0;i--){
        for(int j = 0;j<=maxi + 1; j++){
            // no stock or found stock with lesser val
            if((j==maxi + 1) || (arr[i] < j)){
                dp[i][j] = dp[i+1][arr[i]];
            }
            else{
                // not sell
                int x = dp[i+1][j];
                // sell
                int y = (arr[i] - j) + dp[i+1][arr[i]];
                dp[i][j] = max(x,y);
            }
        }
    }

    cout<<dp[0][maxi + 1]<<endl;

    // approach 4; TC ---> O(n); SC ---> O(1)

    ans = 0;
    for(int i =1;i<n;i++){
        if(arr[i] > arr[i-1]){
            ans+= (arr[i] - arr[i-1]);
        }
    }
    cout<<ans<<endl;

    // approach 5;
    ans = fun2(0,arr,1);
    cout<<ans<<endl;

    // appraoch 6; using dp(memoization); TC ---> O(n*2); SC ---> O(n*2) + O(n)
    vector<vector<int>> dp2(n+1,vector<int>(2,-1));
    ans = fundp2(0,arr,1,dp2);
    cout<<ans<<endl;
    
    // approach 7; using dp(tabulation); TC ---> O(n*2); SC ---> O(n*2)

    dp2[n][0] = 0;
    dp2[n][1] = 0;

    for(int i = n-1;i>=0;i--){
        for(int j =0;j<2;j++){
            if(j==1){
                // buy
                int x = -arr[i] + dp2[i+1][0];
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

    // approach 8; TC ---> O(n*2); SC ---> O(2*2)
    // we need the knowledge of only the next row

    vector<int> next(2,0);
    for(int i = n-1;i>=0;i--){
        vector<int> curr(2);
        for(int j =0 ;j<2;j++){
            if(j==1){
                // buy
                int x = -arr[i] + next[0];
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
#include<iostream>
#include<vector>
using namespace std;

// approach 1; TC ---> O(2^n) ; SC ---> O(n)
// whenever we buy we suffer loss
// wheneven we sell we gain profit

int fun(int idx,vector<int>&arr,int buy,int cnt){

    if(idx==arr.size() || cnt==0){
        return 0;
    }

    int profit;
    
    if(buy==1){
        // buy 
        int x = -arr[idx] + fun(idx + 1,arr,0,cnt);

        // not buy
        int y = fun(idx + 1,arr, 1, cnt);
        profit = max(x,y);
    }
    else{
        // sell
        int x = arr[idx] + fun(idx+1,arr,1,cnt-1);
        // not sell
        int y = fun(idx + 1, arr,0,cnt);
        profit = max(x,y);
    }
return profit;
}

int fundp(int idx,vector<int>&arr,int buy,int cnt,vector<vector<vector<int>>> &dp){

    if(idx==arr.size() || cnt==0){
        return 0;
    }

    if(dp[idx][buy][cnt]!=-1){
        return dp[idx][buy][cnt];
    }

    int profit;
    
    if(buy==1){
        // buy 
        int x = -arr[idx] + fundp(idx + 1,arr,0,cnt,dp);

        // not buy
        int y = fundp(idx + 1,arr, 1, cnt,dp);
        profit = max(x,y);
    }
    else{
        // sell
        int x = arr[idx] + fundp(idx+1,arr,1,cnt-1,dp);
        // not sell
        int y = fundp(idx + 1, arr,0,cnt,dp);
        profit = max(x,y);
    }
return dp[idx][buy][cnt] = profit;
}

int main(){

    int n;
    cin>>n;

    int cnt;
    cin>>cnt;

    vector<int> arr(n);

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    // approach 1;
    int ans = fun(0,arr,1,cnt);
    cout<<ans<<endl;

    // approach 2; using dp(memoization); TC ---> O(n*2*cnt); SC ---> O(n*2*cnt) + O(n)
    // dp[i][j][k] means maxi profit we can make from idx i till end
    // when we can buy only if j==1 and sell only if j==0
    // and when the no. of trans allowed is k

    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(cnt+1,-1)));
    ans = fundp(0,arr,1,cnt,dp);
    cout<<ans<<endl;

    // approach 3; using dp(tabulation); TC ---> O(n*2*cnt); SC ---> O(n*2*cnt)

    // base case
    for(int i =0;i<2;i++){
        for(int j= 0;j<=cnt;j++){
            dp[n][i][j] = 0;
        }
    }

    for(int i = n-1;i>=0;i--){      // idx 
        for(int j =0;j<2;j++){      // can we buy or not
            for(int k =0;k<=cnt;k++){  // trans allowed
                if(k==0){
                    dp[i][j][k] = 0;
                }
                else{
                    if(j==1){
                        // buy
                        int x = -arr[i] + dp[i+1][0][k];
                        // not buy
                        int y = dp[i+1][1][k];
                        dp[i][j][k] = max(x,y);
                    }
                    else{
                        // sell 
                        int x = arr[i] + dp[i+1][1][k-1];
                        // not sell
                        int y = dp[i+1][0][k];
                        dp[i][j][k] = max(x,y);
                    }
                }
            }
        }
    }

    cout<<dp[0][1][cnt]<<endl;

    // approach 4; space optimization; TC ---> O(n*2*cnt); SC ---> O(2*cnt)
    // we need the knowledge of only the last matrix

    vector<vector<int>> next(2,vector<int>(cnt+1,0));

    for(int i = n-1;i>=0;i--){
        vector<vector<int>> curr(2,vector<int>(cnt+1));
        for(int j = 0;j<2;j++){
            for(int k = 0;k<=cnt;k++){
                if(k==0){
                    curr[j][k] = 0;
                }
                else{
                    if(j==1){
                        // buy
                        int x = -arr[i] + next[0][k];
                        // not buy
                        int y = next[1][k];
                        curr[j][k] = max(x,y);
                    }
                    else{
                        // sell 
                        int x = arr[i] + next[1][k-1];
                        // not sell
                        int y = next[0][k];
                        curr[j][k] = max(x,y);
                    }
                }
            }
        }
        next = curr;
    }
    cout<<next[1][cnt]<<endl;
 
return 0;
}
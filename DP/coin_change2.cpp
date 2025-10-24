#include<iostream>
#include<vector>
using namespace std;

// approach 1; using recursion ; TC ---> O(amt^n) ; SC ---> O(n + amt)

// from (idx till end) to make avail amount amt what is total no. of combinations of coins possible
int fun(int n,vector<int> &coin,int idx,int amt){
    // amt can't be zero if fun is called, it can be zero
    // only if it was zero initially
    if(amt==0){
        return 1;
    }
    if(idx==n){
        return 0;
    }

    // don't take coin[idx]
    int x = fun(n,coin,idx + 1,amt);

    // take coin[idx]
    int y = 0;
    if(coin[idx] <= amt){
        if(amt==coin[idx]){
            y = 1;
        }
        else{
            y = fun(n,coin,idx,amt - coin[idx]);
        }
    }
    
return x + y;
}


int fundp(int n,vector<int> &coin,int idx,int amt,vector<vector<int>>&dp){
    // amt can't be zero if fun is called, it can be zero
    // only if it was zero initially
    if(amt==0){
        return 1;
    }
    if(idx==n){
        return 0;
    }
    if(dp[idx][amt]!=-2){
        return dp[idx][amt];
    }

    // don't take coin[idx]
    int x = fundp(n,coin,idx + 1,amt,dp);

    // take coin[idx]
    int y = 0;
    if(coin[idx] <= amt){
        if(amt==coin[idx]){
            y = 1;
        }
        else{
            y = fundp(n,coin,idx,amt - coin[idx],dp);
        }
    }
    
return dp[idx][amt] = x + y;
}

int main(){

    int n;
    cin>>n;

    int amt;
    cin>>amt;

    vector<int>coin(n);
    for(int i =0;i<n;i++){
        cin>>coin[i];
    }

    // approach 1

    int ans = fun(n,coin,0,amt);
    cout<<ans<<endl;

    // appraoch 2; using dp(memoization); TC ---> O(n*amt); SC ---> O(n*amt) + O(n + amt)
    vector<vector<int>> dp(n,vector<int>(amt + 1,-2));
    ans = fundp(n,coin,0,amt,dp);
    cout<<ans<<endl;

    // approach 3; using dp(tabulation); TC ---> O(n*amt); SC ---> O(n*amt)
    // dp[i][j] means using ele from i to n-1 ; no. of ways to make amt j
    for(int i =0;i<=amt;i++){
        if(i==0){
            dp[n-1][i] = 1;
        }
        else{
            if((i >= coin[n-1]) && (i%coin[n-1]==0)){
                dp[n-1][i] = 1;
            }
            else{
                dp[n-1][i] = 0;
            }
        }
    }

    // dp[i][j] means using ele from i to n-1, mini no. of coints to make amt j 

    for(int i = n-2;i>=0;i--){
        for(int j = 0;j<=amt;j++){
            if(j==0){
                dp[i][j] = 1;
            }
            else{
                // don't take coin[i]
                int x = dp[i+1][j];
                // take coin[j]
                int y = 0;
                if(coin[i] <= j){
                    y = dp[i][j - coin[i]];
                }
                dp[i][j] = x + y;
            }
        }
    }

    cout<<dp[0][amt]<<endl;

    // approach 4; space optimization; TC ---> O(n*amt) ; SC ---> O(n*amt) + O(amt)
    // we need the knowledge of only 
    // 1 the curr col in last row ; present in prev
    // 2 the prev col in curr row ; also present in prev

return 0;
}
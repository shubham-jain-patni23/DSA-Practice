#include<iostream>
#include<vector>
using namespace std;

// approach 1; using recursion ; TC ---> O(amt^n) ; SC ---> O(n + amt)

// from (idx till end) to finish avail amount amt what is the mini no. of coins required
int fun(int n,vector<int> &coin,int idx,int amt){
    // amt can't be zero if fun is called, it can be zero
    // only if it was zero initially
    if(amt==0){
        return 0 ;
    }
    if(idx==n){
        return -1;
    }

    // don't take coin[idx]
    int x = fun(n,coin,idx + 1,amt);

    // take coin[idx]
    int y = -1;

    if(coin[idx] <= amt){
        if(amt==coin[idx]){
            return 1;
        }
        y = fun(n,coin,idx,amt - coin[idx]);
        if(y!=-1){
            y = y + 1;
        }
    }
    if(x!=-1 && y!=-1){
        return min(x,y);
    }
    if(x!=-1){
        return x;
    }
    if(y!=-1){
        return y;
    }
    
return -1;
}


int fundp(int n,vector<int> &coin,int idx,int amt,vector<vector<int>>&dp){
    // amt can't be zero if fun is called, it can be zero
    // only if it was zero initially
    if(amt==0){
        return 0 ;
    }
    if(idx==n){
        return -1;
    }
    if(dp[idx][amt]!=-2){
        return dp[idx][amt];
    }

    // don't take coin[idx]
    int x = fundp(n,coin,idx + 1,amt,dp);

    // take coin[idx]
    int y = -1;

    if(coin[idx] <= amt){
        if(amt==coin[idx]){
            return dp[idx][amt] = 1;
        }
        y = fundp(n,coin,idx,amt - coin[idx],dp);
        if(y!=-1){
            y = y + 1;
        }
    }
    if(x!=-1 && y!=-1){
        return dp[idx][amt]= min(x,y);
    }
    if(x!=-1){
        return dp[idx][amt] = x;
    }
    if(y!=-1){
        return dp[idx][amt] = y;
    }
    
return dp[idx][amt] = -1;
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
    for(int i =0;i<=amt;i++){
        if(i==0){
            dp[n-1][i] = 0;
        }
        else{
            if((i >= coin[n-1]) && (i%coin[n-1]==0)){
                dp[n-1][i] = i / coin[n-1];
            }
            else{
                dp[n-1][i] = -1;
            }
        }
    }

    // dp[i][j] means using ele from i to n-1, mini no. of coints to make amt j 

    for(int i = n-2;i>=0;i--){
        for(int j = 0;j<=amt;j++){
            if(j==0){
                dp[i][j] = 0 ;
            }
            else{
                // don't take coin[i]
                int x = dp[i+1][j];
                // take coin[j]
                int y = -1;
                if(coin[i] <= j){
                    if(j==coin[i]){
                        y = 1;
                    }
                    else{
                        y = dp[i][j - coin[i]];
                        if(y!=-1){
                            y = y + 1;
                        }
                    }
                }
                if(x!=-1 && y!=-1){
                    dp[i][j] = min(x,y);
                }
                else if(x!=-1){
                    dp[i][j] = x;
                }
                else if(y!=-1){
                    dp[i][j] = y;
                }
                else{
                    dp[i][j] = -1;
                }
            }
        }
    }

    cout<<dp[0][amt]<<endl;

    // approach 4; using dp(tabulation)(filling table from 0 to n-1)
    // dp[i][j] means till idx i; mini coins to make amt j
    
    for(int i =0;i<=amt;i++){
        if(i==0){
            dp[0][i] = 0;
        }
        else{
            if((i >= coin[0]) && (i%coin[0]==0)){
                dp[0][i] = i / coin[0];
            }
            else{
                dp[0][i] = -1;
            }
        }
    }

    for(int i = 1;i<=n-1;i++){
        for(int j = 0;j<=amt;j++){
            if(j==0){
                dp[i][j] = 0 ;
            }
            else{
                // don't take coin[i]
                int x = dp[i-1][j];
                // take coin[j]
                int y = -1;
                if(coin[i] <= j){
                    if(j==coin[i]){
                        y = 1;
                    }
                    else{
                        y = dp[i][j - coin[i]];
                        if(y!=-1){
                            y = y + 1;
                        }
                    }
                }
                if(x!=-1 && y!=-1){
                    dp[i][j] = min(x,y);
                }
                else if(x!=-1){
                    dp[i][j] = x;
                }
                else if(y!=-1){
                    dp[i][j] = y;
                }
                else{
                    dp[i][j] = -1;
                }
            }
        }
    }

    cout<<dp[n-1][amt]<<endl;

    // approach 5; space optimization; TC ---> O(n*amt) ; SC ---> O(n*amt) + O(amt)
    // we need the knowledge of only 
    // 1 the curr col in last row ; present in prev
    // 2 the prev col in curr row ; also present in prev

    vector<int> prev(amt + 1);
    for(int i =0;i<=amt;i++){
        if(i==0){
            prev[i] = 0;
        }
        else{
            if((i >= coin[0]) && (i%coin[0]==0)){
                prev[i] = i / coin[0];
            }
            else{
                prev[i] = -1;
            }
        }
    }

    for(int i = 1;i<=n-1;i++){
        for(int j = 0;j<=amt;j++){
            if(j==0){
                prev[j] = 0 ;
            }
            else{
                // don't take coin[i]
                int x = prev[j];
                // take coin[j]
                int y = -1;
                if(coin[i] <= j){
                    if(j==coin[i]){
                        y = 1;
                    }
                    else{
                        y = prev[j - coin[i]];
                        if(y!=-1){
                            y = y + 1;
                        }
                    }
                }
                if(x!=-1 && y!=-1){
                    prev[j] = min(x,y);
                }
                else if(x!=-1){
                    prev[j] = x;
                }
                else if(y!=-1){
                    prev[j] = y;
                }
                else{
                    prev[j] = -1;
                }
            }
        }
    }

    cout<<prev[amt]<<endl;

return 0;
}
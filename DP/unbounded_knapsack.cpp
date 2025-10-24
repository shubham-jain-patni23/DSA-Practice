#include<iostream>
#include<vector>
using namespace std;

// approach 1; using recursion ; TC ---> O(w^n * w); SC --->O(n + w)
// general rule of recursion
// express in terms of indices (idx,w)
// explore all possibilites (take, non-take)
// cnt/ max/ min of all possibilities

int fun2(int n, vector<int>&wt,vector<int>&val, int idx,int w){
    if(idx==n-1){
        int cnt2 = w/ wt[idx];
    return (cnt2 * val[idx]);
    }

    // don't take it 
    int x = fun2(n,wt,val,idx+1,w);

    int cnt = w/wt[idx];
    
    // i means no. of times we take val[idx]
    for(int i = 1;i<=cnt;i++){
        int y = (i*val[idx]) + fun2(n,wt,val,idx + 1, w - (i * wt[idx]));
        x = max(x, y);
    }

return x;
}

int fundp2(int n, vector<int>&wt,vector<int>&val, int idx,int w,vector<vector<int>>&dp){
    if(idx==n-1){
        int cnt2 = w/ wt[idx];
    return (cnt2 * val[idx]);
    }

    if(dp[idx][w]!=-1){
        return dp[idx][w];
    }

    // don't take it 
    int x = fundp2(n,wt,val,idx+1,w,dp);
    int cnt = w/wt[idx];
    
    // i means no. of times we take val[idx]
    for(int i = 1;i<=cnt;i++){
        int y = (i*val[idx]) + fundp2(n,wt,val,idx + 1, w - (i * wt[idx]),dp);
        x = max(x, y);
    }
return dp[idx][w] = x;
}

// instead of having an inner loop of cnt 
// we can simply call for the same idx 
// e.g. from f(0,10) if we want to pick we can call to f(0,8) if wt[0] is 2

int fundp3(int n, vector<int>&wt,vector<int>&val, int idx,int w,vector<vector<int>>&dp){
    if(idx==n-1){
        int cnt2 = w/ wt[idx];
    return (cnt2 * val[idx]);
    }

    if(dp[idx][w]!=-1){
        return dp[idx][w];
    }

    // don't take it 
    int x = fundp3(n,wt,val,idx+1,w,dp);
    int cnt = w/wt[idx];
    
    // take it
    if(wt[idx] <= w){
        int y = val[idx] + fundp3(n,wt,val,idx,w - wt[idx],dp);
    }

return dp[idx][w] = x;
}

int main(){

    int n;
    cin>>n;

    int w;
    cin>>w;

    vector<int> val(n);
    for(int i =0;i<n;i++){
        cin>>val[i];
    }

    vector<int> wt(n);  
    for(int i =0;i<n;i++){
        cin>>wt[i];
    }

    // approach 1;
    int ans = fun2(n,wt,val,0,w);
    cout<<ans<<endl;

    // approach 2.1; using dp(memoization); TC ---> O(n*w*w) ; SC ---> O(n*w) + O(n + w)

    vector<vector<int>> dp2(n,vector<int>(w+1,-1));
    ans = fundp2(n,wt,val,0,w,dp2);

    cout<<ans<<endl;

    // approach 2.2; using dp(memoization); TC ---> O(n*w) ; SC ---> O(n*w) + O(n + w)
    vector<vector<int>> dp22(n,vector<int>(w+1,-1));
    ans = fundp3(n,wt,val,0,w,dp22);
    cout<<ans<<endl;

    // approach 3.1; using dp(tabulation); TC ---> O(n*w*w) ; SC ---> O(n*w)
    // general rule of tabulation : 
    // write base case
    // write change in parameters(loop)
    // copy the recurence 

    // dp[i][j] means from i till end with avai wt as j what is the maxi possible val that can be achieved
    
    // base case
    for(int i =0;i<=w;i++){
        int cnt = i/wt[n-1];
        dp2[n-1][i] = cnt * val[n-1];
    }

    for(int i = n-2;i>=0;i--){          // change in parameter idx 
        for(int j = 0;j<=w;j++){        // change in parameter w
            // copy recurence
            // don't take it 
            dp2[i][j] = dp2[i+1][j];
            int cnt2 = j/wt[i];
            for(int k = 1;k<=cnt2;k++){
                dp2[i][j] = max(dp2[i][j], (k*val[i]) + dp2[i+1][j - (k*wt[i])]);
            }
        }
    }

    cout<<dp2[0][w]<<endl;

    // approach 3.2; using dp(tabulation); TC ---> O(n*w) ; SC ---> O(n*w)

    for(int i = 0;i<=w;i++){
        int cnt = i/wt[n-1];
        dp2[n-1][i] = cnt * val[n-1];
    }

    for(int i = n-2;i>=0;i--){
        for(int j = 0;j<=w;j++){
            // don't take it 
            dp2[i][j] = dp2[i+1][j];
            if(wt[i] <= j){
                dp2[i][j] = max(dp2[i][j] , val[i] + dp2[i][j - wt[i]]);
            }
        }
    }

    cout<<dp2[0][w]<<endl;

    // approach 4; space optimization ; TC ---> O(n*w) ; SC ---> O(2*w)
    // we need the knowledge of the next row

    // approach 5; space optimization to 1 row ; TC ---> O(n*w) ; SC ---> O(w)



return 0;
}
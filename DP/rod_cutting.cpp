#include<iostream>
#include<vector>
using namespace std;

// approach 1; TC ---> O(n^n) ; O(n)
// maxi val by cutting rod from st to end
int fun(vector<int>&price,int st,int end){

    if(st==end){
        return price[end - st];
    }

    int ans = price[end -st];

    // maxi val if cut rot into (st, i) and (i+1, end)
    for(int i = st;i<end;i++){
        int x = fun(price,st,i) + fun(price,i +1,end);
        ans = max(ans, x);
    }
return ans;
}

int fundp(vector<int>&price,int st,int end,vector<vector<int>>&dp){

    if(st==end){
        return price[end - st];
    }

    if(dp[st][end]!=-1){
        return dp[st][end];
    }

    int ans = price[end -st];

    // maxi val if cut rot into (st, i) and (i+1, end)
    for(int i = st;i<end;i++){
        int x = fundp(price,st,i,dp) + fundp(price,i +1,end,dp);
        ans = max(ans, x);
    }
return dp[st][end] = ans;
}
// maxi val obtained by cutting rod of size 
int fun2(vector<int>&price,int s){

    if(s==1){
        return price[s-1];
    }

    int ans = price[s-1];
    for(int i = 1;i<=(s/2);i++){
        int x = fun2(price,i) + fun2(price, s-i);
        ans = max(ans, x);
    }
return ans;
}

int fundp2(vector<int>&price,int s,vector<int>&dp){

    if(s==1){
        return price[s-1];
    }
    if(dp[s]!=-1){
        return dp[s];
    }

    int ans = price[s-1];
    for(int i = 1;i<=(s/2);i++){
        int x = fundp2(price,i,dp) + fundp2(price, s-i,dp);
        ans = max(ans, x);
    }
return dp[s] = ans;
}

int main(){

    int n;
    cin>>n;

    vector<int>price(n);
    for(int i =0;i<n;i++){
        cin>>price[i];
    }

    // approach 1
    int ans = fun(price,0,n-1);
    cout<<ans<<endl;

    // approach 2; using dp(memoization); TC ---> O(n*n*n) ; SC ---> O(n*n)  + O(n)
    vector<vector<int>> dpp(n,vector<int>(n,-1));
    ans = fundp(price,0,n-1,dpp);
    cout<<ans<<endl;

    // approach 3; using dp(tabulation); TC ---> O(n*n*n) ; SC ---> O(n*n) 
    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int i =0;i<n;i++){
        dp[i][i] = price[0];
    }

    for(int i = n-1;i>=0;i--){
        for(int j = i + 1;j<n;j++){
            dp[i][j] = price[j-i];
            for(int k = i;k<j;k++){
                int x = dp[i][k] + dp[k+1][j];
                dp[i][j] = max(dp[i][j], x);
            }
        }
    }

    cout<<dp[0][n-1]<<endl;

    // approach 4; using recursion but only one var size of rod; TC ---> O(n^n)
    ans = fun2(price,n);
    cout<<ans<<endl;
    
    // approach 5; using dp(memoization); TC ---> O(n*n) ; SC ---> O(n) + O(n)
    // dp[i] means maxi price obtained from rod of size i
    vector<int> dp2(n+1,-1);
    ans = fundp2(price,n,dp2);
    cout<<ans<<endl;

    // approach 6; using dp(tabulation); TC ---> O(n*n) ; SC ---> O(n)
    dp2[0] = 0;
    dp2[1] = price[0];

    for(int i = 2;i<=n;i++){
        dp2[i] = price[i-1];
        for(int j = 1;j<=(i/2);j++){
            int x = dp2[j] + dp2[i -j];
            dp2[i] = max(dp2[i], x);
        }
    }

    cout<<dp2[n]<<endl;

    // approach 7; it is similar to unbounded knapsack 
    // to get maxi price by cutting rod
    // we can also think to get maxi price by making rod 
    // considering price arr as val arr
    // size of rod as wt arr

return 0;
}
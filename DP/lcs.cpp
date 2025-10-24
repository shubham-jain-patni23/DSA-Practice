#include<iostream>
#include<string>
#include<vector>
using namespace std;

// approach 1; using recursion ; TC ---> O(2^n+m) ; SC ---> O(n + m)

// len of lcs till n-1 idx of s1 and till m-1 idx of s2 starting from 0th idx
int fun(int n,int m,string s1,string s2){

    if(n==0 || m==0){
        return 0;
    }

    // last ch same 
    if(s1[n-1]==s2[m-1]){
        return 1 + fun(n-1,m-1,s1,s2);
    }
    // last ch diff
    int x = fun(n-1,m,s1,s2);
    int y = fun(n,m-1,s1,s2);
return max(x,y);
}

// len of lcs from given idices of both str till end 
int fun2(int n,int m,string s1,string s2){
    if(n==s1.size() || m==s2.size()){
        return 0;
    }

    if(s1[n] == s2[m]){
        return 1 + fun2(n+1,m+1,s1,s2);
    }
    int x = fun2(n,m+1,s1,s2);
    int y = fun2(n+1,m,s1,s2);
return max(x,y);
}

int fundp(int n,int m,string s1,string s2,vector<vector<int>> &dp){

    if(n==0 || m==0){
        return 0;
    }

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    // last ch same 
    if(s1[n-1]==s2[m-1]){
        return 1 + fun(n-1,m-1,s1,s2);
    }
    // last ch diff
    int x = fundp(n-1,m,s1,s2,dp);
    int y = fundp(n,m-1,s1,s2,dp);

return dp[n][m] = max(x,y);
}

int main(){

    string s1,s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();

    // approach 1; 

    int ans = fun(n,m,s1,s2);
    cout<<ans<<endl;
    // ans = fun2(0,0,s1,s2);
    // cout<<ans<<endl;

    // approach 2; using dp(memoization); O(n*m) ; SC ---> O(n*m) + O(n + m)

    vector<vector<int>> dpp(n+1,vector<int>(m+1,-1));
    ans = fundp(n,m,s1,s2,dpp);
    cout<<ans<<endl;

    // approach 3; using dp(tabulation); TC ---> O(n*m) ; SC ---> O(n*m) 

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // dp[i][j] means using the s1 till idx i and s2 till idx j, what is the lcs len

    for(int i =1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }

        }
    }

    cout<<dp[n][m]<<endl;

    // approach 4; space optimization; TC ---> O(n*m) ; SC ---> O(m)
    // we need the knowledge of 
    // prev ele in the curr row
    // curr and prev ele in the prev row

    vector<int> curr(m+1,0);
    int prev = 0;

    for(int i = 1;i <= n;i++){
        for(int j = 0;j<=m;j++){
            int temp = curr[j];
            if(j==0){
                curr[j] = 0;
            }
            else{
                if(s1[i-1]==s2[j-1]){
                    curr[j] = 1 +prev;
                }
                else{
                    curr[j] = max(curr[j],curr[j-1]);
                }
            }
            prev = temp;
        }
    }

    cout<<curr[m]<<endl;

return 0;
}
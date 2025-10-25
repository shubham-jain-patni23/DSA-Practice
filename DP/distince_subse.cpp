#include<iostream>
#include<string>
#include<vector>
using namespace std;

// approach 1; using recursion; TC ---> O(2^n) ; SC ---> O(m)

// fun(i,j,s1,s2) means no. of ways to make s1 from idx1 till end using s2 from idx2 till end 
int fun(int idx1,int idx2, string s1, string s2){
    if(idx1==s1.size()){
        return 1;
    }
    if(idx2==s2.size()){
        return 0;
    }

    // not considering s2[idx] 
    int x = fun(idx1,idx2 + 1,s1,s2);

    // considering s2[idx]
    int y = 0;
    if(s1[idx1]==s2[idx2]){
        y = fun(idx1+1,idx2+1,s1,s2);
    }

return x + y;
}

int fundp(int idx1,int idx2, string s1, string s2,vector<vector<int>>&dp){
    if(idx1==s1.size()){
        return 1;
    }
    if(idx2==s2.size()){
        return 0;
    }

    if(dp[idx1][idx2]!=-1){
        return dp[idx1][idx2];
    }

    // not considering s2[idx] 
    int x = fundp(idx1,idx2 + 1,s1,s2,dp);

    // considering s2[idx]
    int y = 0;
    if(s1[idx1]==s2[idx2]){
        y = fundp(idx1+1,idx2+1,s1,s2,dp);
    }

return dp[idx1][idx2] = x + y;
}

int main(){

    string s,t;
    cin>>s>>t;

    string s1 = t;      // string to make
    string s2 = s;      

    int n = s1.size();
    int m = s2.size();

    // approach 1; 

    int ans = fun(0,0,s1,s2);
    cout<<ans<<endl;

    // approach 2; using dp(memoization); TC ---> O(n*m) ; SC ---> O(m)

    vector<vector<int>> dp(n,vector<int>(m,-1));
    ans = fundp(0,0,s1,s2,dp);
    cout<<ans<<endl;

    // approach 3; using dp(tabulation); TC ---> O(n*m) ; SC ---> O(m)

    // write base case
    // change of var
    // copy recursion

    // base case 

    for(int i = m-1;i>=0;i--){
        if(i==m-1){
            if(s1[n-1]==s2[i]){
                dp[n-1][i] = 1;
            }
            else{
                dp[n-1][i] = 0;
            }
        }
        else{
            // don't consider
            int x = dp[n-1][i+1];
            // consider
            int y = 0;
            if(s1[n-1]==s2[i]){
                y = 1;
            }
            dp[n-1][i] = x + y;
        }
    }

    // dp[i][j] means total ways to make s1 from i till end using 
    // s2 from j till end

    for(int i = n-2;i>=0;i--){
        for(int j =  m-1;j>=0;j--){
            if(j==m-1){
                dp[i][j] = 0;
            }
            else{
                // don't consider s2[j]
                int x = dp[i][j+1];
                // consider s2[j]
                int y = 0;
                if(s1[i]==s2[j]){
                    y = dp[i+1][j+1];
                }
                dp[i][j] = x + y;
            }
        }
    }

    cout<<dp[0][0]<<endl;

    // approach 4; space optimization; TC ---> O(n*m) ; SC ---> O(m)
    // we need the knowledge of 
    // next ele in the curr row, for this we can declare an 1d arr
    // next ele in the next row, it can be stored in a var

    vector<int> next(m);
    for(int i = m-1;i>=0;i--){
        if(i==m-1){
            if(s1[n-1]==s2[i]){
                next[i] = 1;
            }
            else{
                next[i] = 0;
            }
        }
        else{
            // don't consider
            int x = dp[n-1][i+1];
            // consider
            int y = 0;
            if(s1[n-1]==s2[i]){
                y = 1;
            }
            next[i] = x + y;
        }
    }

    int var = dp[n-1][m-1];

    for(int i = n-2;i>=0;i--){
        for(int j =  m-1;j>=0;j--){
            int temp = next[j];
            if(j==m-1){
                next[j] = 0;
            }
            else{
                // don't consider s2[j]
                int x = next[j+1];
                // consider s2[j]
                int y = 0;
                if(s1[i]==s2[j]){
                    y = var;
                }
                next[j] = x + y;
            }
            var = temp;
        }
    }

    cout<<next[0]<<endl;

return 0;
}
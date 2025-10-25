#include<iostream>
#include<string>
#include<vector>
using namespace std;

// problem is we need to check whether str match with pattern

// approach 1; using recursion; TC ---> O(n^n) or exponential ; SC ---> O(n + m)
// fun(i,j,p,s) means can we match pattern p from idx i till end to str s from idx j till end

bool fun(int idx1,int idx2, string p,string s){

    if(idx1==p.size() && idx2==s.size()){       // pattern is matched
        return true;
    }
    if(idx1==p.size()){       // if str is left unmatched 
        return false;   
    }

    if(idx2==s.size()){
        if(p[idx1]=='*'){
            return fun(idx1+1,idx2,p,s);
        }
        else{
            return false;
        }
    }

    // if pattern ch is b/w a to z

    if(p[idx1]>= 'a' && p[idx1]<='z'){
        if(p[idx1]==s[idx2]){
            return fun(idx1+1,idx2+1,p,s);
        }
        else{
            return false;
        }
    }

    // if pattern ch is ?

    if(p[idx1]=='?'){
        return fun(idx1+1,idx2+1,p,s);
    }

    // if pattern ch is *

    // don't use *
    bool x = fun(idx1+1,idx2,p,s);

    // use *
    bool y = fun(idx1,idx2+1,p,s);

return (x || y);
}

bool fundp(int idx1,int idx2, string p,string s,vector<vector<int>> &dp){

    if(idx1==p.size() && idx2==s.size()){       // pattern is matched
        return true;
    }
    if(idx1==p.size()){       // if str is left unmatched 
        return false;   
    }

    if(dp[idx1][idx2]!=-1){
        return dp[idx1][idx2];
    }

    if(idx2==s.size()){
        if(p[idx1]=='*'){
            return dp[idx1][idx2] = fundp(idx1+1,idx2,p,s,dp);
        }
        else{
            return dp[idx1][idx2] =  false;
        }
    }

    // if pattern ch is b/w a to z

    if(p[idx1]>= 'a' && p[idx1]<='z'){
        if(p[idx1]==s[idx2]){
            return dp[idx1][idx2] = fundp(idx1+1,idx2+1,p,s,dp);
        }
        else{
            return dp[idx1][idx2] = false;
        }
    }

    // if pattern ch is ?

    if(p[idx1]=='?'){
        return dp[idx1][idx2] = fundp(idx1+1,idx2+1,p,s,dp);
    }

    // if pattern ch is *
    // don't use *
    bool x = fundp(idx1+1,idx2,p,s,dp);

    // use *
    bool y = fundp(idx1,idx2+1,p,s,dp);

    
return dp[idx1][idx2] = (x || y);
}

int main(){

    string s1,s2;
    cin>>s1>>s2;

    string p = s2;
    string s = s1;

    int n = p.size();
    int m = s.size();

    // approach 1; 
    int ans = fun(0,0,p,s);
    cout<<ans<<endl;

    // approach 2; using dp(memoization); TC ---> O(n*m) ; SC ---> O(n*m) + O(n + m);

    vector<vector<int>> dpp(n + 1,vector<int>(m+ 1, -1));
    ans = fundp(0,0,p,s,dpp);
    cout<<ans<<endl;

    // approach 3; using dp(tabulation); TC ---> O(n*m) ; SC ---> O(n*m)

    vector<vector<bool>> dp(n+1,vector<bool>(m+1));
    // dp[i][j] means can we match pattern p from idx i till end to str s from idx j till end

    // base case
    dp[n][m] = 1;

    for(int i = 0;i<m;i++){
        dp[n][i] = 0;
    }

    for(int i = n-1;i>=0;i--){
        if(p[i]=='*'){
            dp[i][m] = dp[i+1][m];
        }
        else{
            dp[i][m] = 0;
        }
    }

    // change of var and recurrence

    for(int i = n-1;i>=0;i--){
        for(int j = m-1;j>=0;j--){

            // if pattern ch is b/w a to z
            if(p[i]>= 'a' && p[i]<='z'){
                if(p[i]==s[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = false;
                }
            }
            else if(p[i]=='?'){  // if pattern ch is ?
                dp[i][j] = dp[i+1][j+1];
            }
            else{ // if pattern ch is *

                // if we don't use *
                bool not_use = dp[i+1][j];

                // if we use * 
                bool useit = dp[i][j+1];
                dp[i][j] = not_use || useit;
            }
        }
    }

    cout<<dp[0][0]<<endl;

    // approach 4; space optimization; TC ---> O(n*m) ; SC ---> O(m)
    // here we need the knowledge of
    // curr and next ele in next row
    // next ele in the curr row

    vector<bool> next(m+1);
    next[m] = 1;
    for(int i = 0;i<m;i++){
        next[i] = 0 ;
    }

    int var = next[m];

    for(int i = n-1;i>=0;i--){
        for(int j = m;j>=0;j--){
            int temp = next[j];
            if(j==m){
                if(p[i]=='*'){
                    next[j] = next[j];
                }
                else{
                    next[j] = 0;
                }
            }
            else{
                if(p[i]>='a' && p[i]<='z'){
                    if(p[i]==s[j]){
                        next[j] = var;
                    }
                    else{
                        next[j] = false;
                    }
                }
                else if(p[i]=='?'){
                    next[j] = var;
                }
                else{
                    bool not_use = next[j];
                    bool useit = next[j+1];
                    next[j] = not_use || useit;
                }
            }
            var = temp;
        }
    }

    cout<<next[0]<<endl;
    
return 0;
}
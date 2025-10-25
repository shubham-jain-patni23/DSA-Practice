#include<iostream>
#include<string>
#include<vector>
using namespace std;

// approach 1; using recursion ; TC ---> O(3^(n+m)) ; SC ---> O(n + m)
// fun(i,j,s1,s2) means mini cost to conv str s1 from idx i till end to str s2 form idx j till end

int fun(int idx1,int idx2,string s1,string s2){

    if(idx1==s1.size()){             // s1 is over so we need to ins some ch into s1
        return (s2.size() - idx2);
    }
    if(idx2==s2.size()){            // s2 is over so we need to del some ch from s1
        return (s1.size() - idx1);
    }

    // ch are eq
    if(s1[idx1]==s2[idx2]){
        return fun(idx1+1,idx2+1,s1,s2);
    }

    // ch are not eq

    // insert into s1
    int x = 1 + fun(idx1,idx2 +1,s1,s2);

    // delete from s1
    int y = 1 + fun(idx1+1,idx2,s1,s2);

    // replace s1[idx]
    int z = 1 + fun(idx1 + 1,idx2+1,s1,s2);

return min(x,min(y,z));
}

int fundp(int idx1,int idx2,string s1,string s2,vector<vector<int>>&dp){

    if(idx1==s1.size()){             // s1 is over so we need to ins some ch into s1
        return (s2.size() - idx2);
    }
    if(idx2==s2.size()){            // s2 is over so we need to del some ch from s1
        return (s1.size() - idx1);
    }

    if(dp[idx1][idx2]!=-1){
        return dp[idx1][idx2];
    }

    // ch are eq
    if(s1[idx1]==s2[idx2]){
        return dp[idx1][idx2] = fundp(idx1+1,idx2+1,s1,s2,dp);
    }

    // ch are not eq

    // insert into s1
    int x = 1 + fundp(idx1,idx2 +1,s1,s2,dp);

    // delete from s1
    int y = 1 + fundp(idx1+1,idx2,s1,s2,dp);

    // replace s1[idx]
    int z = 1 + fundp(idx1 + 1,idx2+1,s1,s2,dp);

return dp[idx1][idx2]= min(x,min(y,z));
}

int main(){

    string s1,s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();

    // approach 1; 
    int ans = fun(0,0,s1,s2);
    cout<<ans<<endl;

    // approach 2; using dp(memoization); TC ---> O(n*m) ; SC ---> O(n*m) + O(n+m)
    
    vector<vector<int>> dpp(n,vector<int>(m,-1));
    ans = fundp(0,0,s1,s2,dpp);
    cout<<ans<<endl;

    // approach 3; using dp(tabulation); TC ---> O(n*m) ; SC ---> O(n*m)

    vector<vector<int>> dp(n+1,vector<int>(m+1));

    // base case
    
    // s2 is over; need to delete
    for(int i =0;i<=n;i++){
        dp[i][m] = n - i;
    }

    // s1 is over; need to ins
    for(int i =0;i<=m;i++){
        dp[n][i] = m - i;
    }

    for(int i = n-1;i>=0;i--){
        for(int j = m-1;j>=0;j--){
            // ch are eq;
            if(s1[i]==s2[j]){
                dp[i][j] = dp[i+1][j+1];
            }
            else{   // ch are not eq;

                // insert
                int x = 1 + dp[i][j+1];

                // delete
                int y = 1 + dp[i+1][j];

                // replace
                int z = 1 + dp[i+1][j+1];

                dp[i][j] = min(x,min(y,z));

            }
        }
    }

    cout<<dp[0][0]<<endl;

    // space optimization; TC ---> O(n*m) ; SC ---> O(m)
    // we need the knowledge of 
    // curr and next ele in the next row
    // next ele in the curr row

    vector<int> next(m+1);

    for(int i =0;i<=m;i++){
        next[i] = m - i;
    }

    int var = next[m];

    for(int i = n-1;i>=0;i--){
        for(int j = m;j>=0;j--){

            int temp = next[j];

            if(j==m){
                next[j] = n - i;
            }
            else{
                // ch are eq;
                if(s1[i]==s2[j]){
                    next[j] = var;
                }
                else{   // ch are not eq;

                    // insert
                    int x = 1 + next[j+1];

                    // delete
                    int y = 1 + next[j];

                    // replace
                    int z = 1 + var;

                    next[j] = min(x,min(y,z));

                }
            }
            
            var = temp;
        }
    }

    cout<<next[0]<<endl;

return 0;
}
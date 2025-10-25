#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

// approach 1; using recursion ; TC ---> O(2^n) ; SC ---> O(n)

// fun(i,j,s) means starting from idx i till j mini no. of ins to make s palindrome
int fun(int idx1,int idx2,string s){

    if(idx1 >= idx2){
        return 0;
    }

    if(s[idx1]==s[idx2]){
        return fun(idx1+1,idx2-1,s);
    }
    
    int ins_start = 1 + fun(idx1,idx2-1,s);
    int ins_end = 1 + fun(idx1 + 1,idx2,s);

return min(ins_start,ins_end);
}

int fundp(int idx1,int idx2,string s,vector<vector<int>> &dp){

    if(idx1 >= idx2){
        return 0;
    }

    if(dp[idx1][idx2]!=-1){
        return dp[idx1][idx2];
    }

    if(s[idx1]==s[idx2]){
        return dp[idx1][idx2] = fundp(idx1+1,idx2-1,s,dp);
    }
    
    int ins_start = 1 + fundp(idx1,idx2-1,s,dp);
    int ins_end = 1 + fundp(idx1 + 1,idx2,s,dp);

return dp[idx1][idx2] = min(ins_start,ins_end);
}

int main(){

    string s;
    cin>>s;

    int n = s.size();

    // approach 1; 

    int ans = fun(0,n-1,s);
    cout<<ans<<endl;

    // approach 2; using dp(memoization); TC ---> O(n*n) ; SC ---> O(n*n) + O(n)
    
    vector<vector<int>> dpp(n,vector<int>(n,-1));

    ans = fundp(0,n-1,s,dpp);
    cout<<ans<<endl;

    // approach 3; using dp(tabulation) ; TC ---> O(n*n) ; SC ---> O(n*n)
    // dp[i][j] means mini ins req to make str from i to j palindrome

    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int i = n-2 ;i>=0;i--){
        for(int j = i + 1;j<n;j++){
            if(s[i]==s[j]){
                dp[i][j] = dp[i+1][j-1];
            }
            else{
                dp[i][j] = 1 + min(dp[i][j-1], dp[i+1][j]);
            }
        }
    }


    cout<<dp[0][n-1]<<endl;

    // appraoch 4; TC---> O(n*n) ; SC ---> O(n)
    // we want to make str palindrome
    // we can think there is a palindroic subseq in str
    // in b/w in there are ele which are not making it palindromic
    // so we need to find the maxi len of the palindromic subseq
    // and for the remaining ele we need to insert that much ele to make complete str palindrome
    // so we first need to find maxi len palindrome
    // then len(s) - len(maxi len palin) will be the mini ins req to make str palindrome

    string s1 = s;
    string s2 = s;

    reverse(s2.begin(),s2.end());

    int n1 = s1.size();
    int m = n;


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

    ans = n - curr[m];
    cout<<ans<<endl;


return 0;
}
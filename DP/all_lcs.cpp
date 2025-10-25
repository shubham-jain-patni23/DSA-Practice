#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;

// need to further optimize it 

// appraoch 1; TC ---> O(2^(n + m)) ; SC ---> O(n + m)

void fun(int n,int m,string s1,string s2,vector<string>&ans,string curr,vector<vector<int>>&dp){

    if(n==0 || m==0 || dp[n][m]==0){
        if(curr.size()!=0){
            ans.push_back(curr);
        }
        return ;
    }

    if(s1[n-1] == s2[m-1]){
        curr = s1[n-1] + curr;
        fun(n-1,m-1,s1,s2,ans,curr,dp);
    }
    else{
        if(dp[n][m-1] > dp[n-1][m]){
            fun(n,m-1,s1,s2,ans,curr,dp);
        }
        else if(dp[n-1][m] > dp[n][m-1]){
            fun(n-1,m,s1,s2,ans,curr,dp);
        }
        else{
            fun(n-1,m,s1,s2,ans,curr,dp);
            fun(n,m-1,s1,s2,ans,curr,dp);
        }
    }

}

int main(){

    string s1,s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();
   
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

    string curr = "";
    vector<string> ans;
    fun(n,m,s1,s2,ans,curr,dp);

    set<string> s(ans.begin(),ans.end());

    for(auto i: s){
        cout<<i<<" ";
    }cout<<endl;

    // approach 2; using dp(tabulation); TC ---> exponential due to merging
    // dpp[i][j] means common subse of size dp[i][j]

    vector<vector<vector<string>>> dpp(n+1,vector<vector<string>>(m+1));

    for(int i =0;i<=m;i++){
        dpp[0][i] = {};
    }

    for(int i = 0;i<=n;i++){
        dpp[i][0] = {};
    }

    for(int i =1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            vector<string> temp = {};
            if(s1[i-1]==s2[j-1]){
                if(dpp[i-1][j-1].size()!=0){
                    for(auto it : dpp[i-1][j-1]){
                        temp.push_back(it + s1[i-1]);
                    }
                }
                else{
                    string currstr = "" ; // is there a problem in this else part
                    currstr+= s1[i-1];    // if I am having this then I am getting some error
                    temp = {currstr};
                }
            }
            else{
                vector<string> first = dpp[i-1][j];
                vector<string> second = dpp[i][j-1];

                if(dp[i-1][j] > dp[i][j-1]){
                    temp.insert(temp.end(),first.begin(),first.end());
                }
                else if(dp[i][j-1] > dp[i-1][j]){
                    temp.insert(temp.end(),second.begin(),second.end());
                }
                else{
                    temp.insert(temp.end(),first.begin(),first.end());
                    temp.insert(temp.end(),second.begin(),second.end());
                }
            }
            dpp[i][j] = temp;
        }
    }

    set<string> st2(dpp[n][m].begin(),dpp[n][m].end());

    for(auto i : st2){
        cout<<i<<" ";
    }

return 0;
}
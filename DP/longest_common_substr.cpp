#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int fun(int idx1,int idx2,string s1,string s2){
    if(idx1==s1.size() || idx2==s2.size() || s1[idx1]!=s2[idx2]){
        return 0;
    }
return 1 + fun(idx1+1, idx2 + 1,s1,s2);
}

int fundp(int idx1,int idx2,string s1,string s2,vector<vector<int>> &dp){
    if(idx1==s1.size() || idx2==s2.size() || s1[idx1]!=s2[idx2]){
        return 0;
    }
    if(dp[idx1][idx2]!=-1){
        return dp[idx1][idx2];
    }

return dp[idx1][idx2]= 1 + fundp(idx1+1, idx2 + 1,s1,s2,dp);
}


void allsubstr(string s,vector<string> &temp){

    int n = s.size();

    for(int i =0;i<n;i++){
        string curr = "";
        for(int j = i;j<n;j++){
            curr+= s[j];
            temp.push_back(curr);
        }
    }
    
}

int main(){

    string s1,s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();

    // approach 1; TC ---> O(n^3) approx ; SC ---> O(n^2) + O(m^2)
    // generate all substr of s1 and s2
    // sort substr arr of s2
    // find longest common substr using binary search 

    vector<string> firststr;
    vector<string> secondstr;

    allsubstr(s1,firststr);     // O(n^2)
    allsubstr(s2,secondstr);    // O(m^2)

    sort(secondstr.begin(),secondstr.end());    // O(2*m^2log2(m))

    int ans = 0;

    for(auto i : firststr){                 // O(n^2 * (log2(m^2) + m))
        int idx = lower_bound(secondstr.begin(),secondstr.end(),i) - secondstr.begin();
        if(idx != secondstr.size()){
            int x = secondstr[idx].compare(i);
            if(x==0){
                ans = max(ans, (int)i.size());
            }
        }
    }

    cout<<ans<<endl;

    // approach 2; TC ---> O(n*m*min(n,m)) ; SC ---> O(min(n,m))
    // considering the maxi substr will start from
    // idx1 in s1 and idx2 in s2 and then finding max
    // declaring a fun() which finds the len of common str starting
    // from idx1 in s1 and idx2 in s2

    ans = 0;

    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            int x = fun(i,j,s1,s2);
            ans =max(ans, x);
        }
    }

    cout<<ans<<endl;

    // approach 3; using dp(memoization); TC ---> O(n*m);  SC ---> O(n*m) + O(min(n,m))

    vector<vector<int>> dpp(n,vector<int>(m,-1));

    ans = 0; 

    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            int x = fundp(i,j,s1,s2,dpp);
            ans =max(ans, x);
        }
    }

    cout<<ans<<endl;

    // approach 4; using dp(tabulation); TC ---> O(n*m) ; SC ---> O(n*m)
    // dp[i][j] means starting from idx i in s1 and idx j in s2 
    // what is the maxi len substr which is common 

    vector<vector<int>> dp(n,vector<int>(m));

    for(int i = 0;i<m;i++){
        dp[n-1][i] = 0;
        if(s1[n-1]==s2[i]){
            dp[n-1][i] = 1;
        }
    }

    ans = 0;

    for(int i = n-2;i>=0;i--){
        for(int j = 0;j<m;j++){
            if(s1[i]!=s2[j]){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = 1;
                if(j+1 < m){
                    dp[i][j]+= dp[i+1][j+1];
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout<<ans<<endl;

    // approach 5; space optimization       TC ---> O(n*m) ; SC ---> O(m)   
    // we need the knowledget of only the next row
    // we need the next ele of the next row 

    vector<int> curr(m);

    for(int i = 0;i<m;i++){
        curr[i] = 0;
        if(s1[n-1]==s2[i]){
            curr[i] = 1;
        }
    }

    ans = 0;

    for(int i = n-2;i>=0;i--){
        for(int j = 0;j<m;j++){
            if(s1[i]!=s2[j]){
                curr[j] = 0;
            }
            else{
                curr[j] = 1;
                if(j+1 < m){
                    curr[j]+= curr[j+1];
                }
            }
            ans = max(ans, curr[j]);
        }
    }

    cout<<ans<<endl;

return 0;
}
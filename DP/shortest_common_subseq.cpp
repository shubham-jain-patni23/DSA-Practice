#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){

    string s1,s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();

    // approach 1; using dp(tabulation); TC ---> O(n*m) + O(n*m); SC ---> O(n*m) 

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

    int i = n, j = m;
    // means we want to s1 till i and s2 till j

    string curr = "";

    while(i>=0 && j>=0){
        if(i==0 && j==0){
            break;
        }
        if(i==0){
            string temp = s2.substr(0,j);
            curr = temp + curr;
            break;
        }
        if(j==0){
            string temp = s1.substr(0,i);
            curr = temp + curr;
            break;
        }
        if(s1[i-1]==s2[j-1]){
            curr = s1[i-1] + curr;
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] >= dp[i][j-1]){
                curr = s1[i-1] + curr;
                i--;
            }
            else{
                curr = s2[j-1] + curr;
                j--;
            }
        }
    }

    cout<<curr<<endl;

return 0;
}
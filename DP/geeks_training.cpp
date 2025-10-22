#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// approach 1: using recursion ; TC ---> O(2^n * 3) ; SC ---> O(n)
// how much can be earned from days starting from idx 
int fun(int n,vector<vector<int>> &arr,int idx,int prev){

    if(idx==n){
        return 0;
    }
    int ans = INT_MIN;
    // if we do ith task on idx day, then how much can be earned in the remaining days
    for(int i =0;i<3;i++){
        if(prev!=i){
            ans = max(ans,arr[idx][i] + fun(n,arr,idx+1,i));
        }
    }
return ans;
}

// approach 2; using dp(memoization) ; TC ---> O(n*3*3) ; SC ---> O(3*n) + O(n)
// dp[idx][prev] means maxi earning from idx when in the last idx prev was used

int fundp(int n,vector<vector<int>> &arr,int idx,int prev,vector<vector<int>>&dp){

    if(idx==n){
        return 0;
    }
    if(prev!=-1 && dp[idx][prev]!=-1){
        return dp[idx][prev];
    }   
    int ans = INT_MIN;
    // if we do ith task on idx day, then how much can be earned in the remaining days
    for(int i =0;i<3;i++){
        if(prev!=i){
            ans = max(ans,arr[idx][i] + fundp(n,arr,idx+1,i,dp));
        }
    }
    if(prev!=-1){
        dp[idx][prev] = ans;
    }
return ans;
}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> arr(n,vector<int>(3));

    for(int i =0;i<n;i++){
        for(int j = 0;j<3;j++){
            cin>>arr[i][j];
        }
    }

    int ans = fun(n,arr,0,-1);
    cout<<ans<<endl;

    vector<vector<int>> dp(n,vector<int>(3,-1));
    ans = fundp(n,arr,0,-1,dp);
    cout<<ans<<endl;

    // approach 3: using dp(tabulation) ; TC ---> O(n*3*3) + O(3) ; SC --->O(n*3)
    // finding the maxi earning till ith days to find the maxi earning till n days 

    for(int j = 0 ;j<3;j++){
        dp[0][j] = arr[0][j];
    }

    // in each iteration finding maxi till i days
    for(int i = 1;i<n;i++){    
        // considering jth task on ith day             
        for(int j = 0;j<3;j++){
            // finding the maxi earning till i-1 day 
            int maxi = INT_MIN;
            for(int k = 0;k<3;k++){
                if(k!=j){
                    maxi = max(maxi , dp[i - 1][k]);
                }
            }
            dp[i][j] = maxi + arr[i][j];
        }
    }

    ans = dp[n-1][0];
    for(int i =0;i<3;i++){
        ans = max(ans, dp[n-1][i]);
    }

    cout<<ans<<endl;

    // approach 4 ; space optimization in dp(tabulation) ; TC --->O(n*3*3) ; SC ---> O(2*3)

    vector<int> a(3);
    for(int i =0;i<3;i++){
        a[i] = arr[0][i];
    }

    // a[i] means considering ith task maxi earning till first day
    for(int i = 1;i<n;i++){
        vector<int> temp(3);
        // temp[j] means considering jth task maxi earning till ith day
        // earning through jth task + maxi earning till i-1th day
        for(int j = 0;j<3;j++){
            int maxi = INT_MIN;
            for(int k =0;k<3;k++){
                if(k!=j){
                    maxi = max(maxi , a[k]);
                }
            }
            temp[j] = maxi + arr[i][j];
        }
        a = temp;
    }

    ans = a[0];
    for(int i = 1;i<3;i++){
        ans = max(ans, a[i]);
    }
    cout<<ans<<endl;

return 0;
}
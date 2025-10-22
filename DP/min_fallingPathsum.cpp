#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// approach 1: using recursion ; TC ---> O(3^n) ; SC ---> O(n)
// mini fall_sum from (row,col)
int fun(int n, vector<vector<int>> &arr,int row,int col){

    int ans = arr[row][col];
    if(row < n-1){
        if(col > 0 && col < n-1){
            ans = arr[row][col] + min(fun(n,arr,row+1,col), min(fun(n,arr,row+1,col-1), fun(n,arr,row+1,col+1)));
        } 
        else if(col > 0){
            ans = arr[row][col] + min(fun(n,arr,row+1,col), fun(n,arr,row+1,col - 1));
        }
        else if(col < n-1){
            ans = arr[row][col] + min(fun(n,arr,row+1,col), fun(n,arr,row+1,col + 1));
        }
    }
return ans;
}

// fundp gives the mini val to reach from (row,col) to last row
int fundp(int n,vector<vector<int>> &arr,int row,int col,vector<vector<int>> &dp){
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    int ans = arr[row][col];
    if(row < n-1){
        if(col > 0 && col < n-1){
            ans = arr[row][col] + min(fundp(n,arr,row+1,col,dp), min(fundp(n,arr,row+1,col-1,dp), fundp(n,arr,row+1,col+1,dp)));
        } 
        else if(col > 0){
            ans = arr[row][col] + min(fundp(n,arr,row+1,col,dp), fundp(n,arr,row+1,col - 1,dp));
        }
        else if(col < n-1){
            ans = arr[row][col] + min(fundp(n,arr,row+1,col,dp), fundp(n,arr,row+1,col + 1,dp));
        }
    }
return dp[row][col] = ans;
}

// using dp(memoization)
// fundp2 gives the val to reach (row,col) from (0,0)

int fundp2(int n,vector<vector<int>> &arr,int row,int col,vector<vector<int>> &dp){
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    int ans = arr[row][col];
    if(row > 0){
        if(col > 0 && col < n-1){
            ans = arr[row][col] + min(fundp2(n,arr,row-1,col,dp), min(fundp2(n,arr,row-1,col-1,dp), fundp2(n,arr,row-1,col+1,dp)));
        } 
        else if(col > 0){
            ans = arr[row][col] + min(fundp2(n,arr,row-1,col,dp), fundp2(n,arr,row-1,col - 1,dp));
        }
        else if(col < n-1){
            ans = arr[row][col] + min(fundp2(n,arr,row-1,col,dp), fundp2(n,arr,row-1,col + 1,dp));
        }
    }
return dp[row][col] = ans;
}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> arr(n,vector<int>(n));
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    int ans = INT_MAX;
    for(int i =0;i<n;i++){
        ans = min(ans, fun(n,arr,0,i));
    }

    cout<<ans<<endl;

    // approach 2: using dp(memoization); TC ---> O(n*n) + O(n) ; SC ---> O(n*n) + O(n)
    vector<vector<int>> dp(n,vector<int>(n,-1));
    ans = INT_MAX;
    for(int i = 0;i<n;i++){
        ans = min(ans, fundp2(n,arr,n-1,i,dp));
    }
    cout<<ans<<endl;

    // approach 3: using dp(tabulation); TC ---> O(n*n) + O(n); SC ---> O(n*n)
    // to reach last row we need to first calc the mini dis to reach at each row from start

    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            dp[i][j] = arr[i][j];
            if(i > 0){
                if(j>0 && j<n-1){
                    dp[i][j] = arr[i][j] + min(dp[i-1][j], min(dp[i-1][j-1] , dp[i-1][j+1]));
                } 
                else if(j > 0){
                    dp[i][j] = arr[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                }
                else{
                    dp[i][j] = arr[i][j] + min(dp[i-1][j] , dp[i-1][j+1]);
                } 
            }
        }
    }

    ans = dp[n-1][0];
    for(int i =0;i<n;i++){
        ans = min(ans, dp[n-1][i]);
    }
    cout<<ans<<endl;

    // approach 4; optimizing space; TC ---> O(n*n) ; SC ---> O(2n)
    // we need only the prev row to do updates 

    vector<int> prev(n);
    for(int i = 0;i<n;i++){
        prev[i] = arr[0][i];
    }

    for(int i = 1;i<n;i++){
        vector<int> temp(n);
        for(int j = 0;j<n;j++){
            if(j>0 && j<n-1){
                temp[j] = arr[i][j] + min(prev[j], min(prev[j-1], prev[j+1]));
            }
            else if(j > 0){
                temp[j] = arr[i][j] + min(prev[j], prev[j-1]);
            }
            else{
                temp[j] = arr[i][j] + min(prev[j], prev[j+1]);
            }
        }
        prev = temp;
    }

    ans = prev[0];
    for(int i = 1;i<n;i++){
        ans = min(ans, prev[i]);
    }
    cout<<ans<<endl;

return 0;
}
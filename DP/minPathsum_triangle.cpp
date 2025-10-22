#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// approach 1; using recursion ; TC ---> O(2^(n*(n+1)/2)) ; SC ---> O(n);
// mini sum path from row,col to last row

// in tabulation it is recommended to go opposite of the recursion tree

int fun(int n,vector<vector<int>> &arr,int row,int col){

    int ans = arr[row][col];

    if(row < n-1){
        ans += min(fun(n,arr,row+1,col), fun(n,arr,row+1,col+1));
    }
return ans;
}

int fundp(int n,vector<vector<int>> &arr,int row,int col, vector<vector<int>>&dp){
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    if(row==n-1){
        return arr[row][col];
    }

    int first = fundp(n,arr,row+1,col,dp);
    int second = fundp(n,arr,row+1,col+1,dp);
    
    dp[row][col] = arr[row][col] +  min(first,second);
return dp[row][col];
}


int main(){

    int n;
    cin>>n;

    vector<vector<int>> arr(n);

    for(int i =0;i<n;i++){
        for(int j =0;j<=i;j++){
            int x;
            cin>>x;
            arr[i].push_back(x);
        }
    }

    int ans = fun(n,arr,0,0);
    cout<<ans<<endl;

    
    // approach 2; using dp(memoization) ; TC  ---> O(n*n) ; SC ---> O(n*n) + O(n)

    vector<vector<int>> dp(n,vector<int>(n,-1));
    ans = fundp(n,arr,0,0,dp);
    cout<<ans<<endl;

    // approach 3; using dp(tabulation) ; TC ---> O(n*m) ; SC ---> O(n*m)

    for(int i = 0;i<n;i++){
        for(int j =0;j<=i;j++){
            dp[i][j] = arr[i][j];
            if(i > 0){
                if(j>0 && j<i){
                    dp[i][j] = arr[i][j] + min(dp[i-1][j] , dp[i-1][j-1]);
                }
                else if(j>0){
                    dp[i][j] = arr[i][j] + dp[i-1][j-1];
                }
                else if(j <i){
                    dp[i][j] = arr[i][j] + dp[i-1][j];
                }
            }
        }
    }

    ans = dp[n-1][0];
    for(int i =0;i<n;i++){
        ans = min(ans, dp[n-1][i]);
    }
    cout<<ans<<endl;

    // approach 4: space optimization ; TC ---> O(n^2) ; SC ---> O(2n)
    // we need only the last row for updation

    vector<int> prev(n);
    prev[0] = arr[0][0];

    for(int i = 1;i<n;i++){
        vector<int> temp(n);
        for(int j = 0;j<=i;j++){
            temp[j] = arr[i][j];
            if(j>0 && j<i){
                temp[j] = arr[i][j] + min(prev[j-1], prev[j]);
            }
            else if(j>0){
                temp[j] = arr[i][j] + prev[j-1];
            }
            else if(j<i){
                temp[j] = arr[i][j] + prev[j];
            }
        }
        prev = temp;
    }

    ans = prev[0];
    for(int i =0;i<n;i++){
        ans = min(ans, prev[i]);
    }
    cout<<ans<<endl;

return 0;
}
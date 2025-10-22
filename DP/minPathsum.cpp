#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// approach 1; using recursion ; TC ---> O(2^n*m) ; SC ---> O(n+m);
// mini sum path from row,col to n-1,m-1

int fun(int n,int m,vector<vector<int>> &arr,int row,int col){

    int ans = arr[row][col];
    if(row < n-1 && col < m-1){
        ans = ans + min(fun(n,m,arr,row+1,col) , fun(n,m,arr,row,col+1));
    }    
    else if(row < n-1){
        ans = ans + fun(n,m,arr,row+1,col);
    }
    else if(col < m-1){
        ans = ans + fun(n,m,arr,row,col+1);
    }
return ans;
}

int fundp(int n,int m,vector<vector<int>> &arr,int row,int col, vector<vector<int>>&dp){
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    dp[row][col] = arr[row][col];
    
    if(row<n-1 && col < m-1){
        dp[row][col] = arr[row][col] + min(fundp(n,m,arr,row+1,col,dp) , fundp(n,m,arr,row,col+1,dp));
    }
    else if(row < n-1){
        dp[row][col] = arr[row][col] + fundp(n,m,arr,row+1,col,dp);
    }
    else if(col < m-1){
        dp[row][col] = arr[row][col] + fundp(n,m,arr,row,col+1,dp);
    }
return dp[row][col];
}


int main(){

    int n;
    cin>>n;

    int m;
    cin>>m;

    vector<vector<int>> arr(n,vector<int>(m));
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int ans = fun(n,m,arr,0,0);
    cout<<ans<<endl;

    
    // approach 2; using dp(memoization) ; TC  ---> O(n*m) ; SC ---> O(n*m) + O(n + m)

    vector<vector<int>> dp(n,vector<int>(m,-1));
    ans = fundp(n,m,arr,0,0,dp);
    cout<<ans<<endl;

    // approach 3; using dp(tabulation); TC ---> O(n*m) ; SC ---> O(n*m)
    vector<vector<int>> dpp(n,vector<int>(m));

    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            dpp[i][j] = arr[i][j] ;
            if(i > 0 && j > 0){
                dpp[i][j] = arr[i][j] + min(dpp[i-1][j] , dpp[i][j-1]);
            }
            else if(i > 0){
                dpp[i][j] = arr[i][j] + dpp[i-1][j];
            }
            else if(j > 0){
                dpp[i][j] = arr[i][j] + dpp[i][j-1];
            }
        }
    }

    cout<<dpp[n-1][m-1]<<endl;

    // approach 4; optimizing space
    // we only need the prev row while updating any cell 

    vector<int> prevrow(m);
    prevrow[0] = arr[0][0];
    for(int i =1;i<m;i++){
        prevrow[i] = prevrow[i-1] + arr[0][i];
    }

    for(int i = 1;i<n;i++){
        vector<int> temp(m);
        for(int j = 0;j<m;j++){
            temp[j] = arr[i][j];
            if(j>0){
                temp[j] = temp[j] + min(temp[j-1], prevrow[j]);
            }
            else{
                temp[j] = temp[j] + prevrow[j];
            }
        }
        prevrow = temp;
    }

    cout<<prevrow[m-1]<<endl;

return 0;
}
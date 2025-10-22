#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// approach 1; using recursion ; TC ---> O(2^(n*m)) ; SC ---> O(n + m)

// no of ways to move from row,col to n-1,m-1;
int fun(int n,int m,int row,int col,vector<vector<int>> &arr){

    if(row>=n || col>=m){
        return 0 ;
    }

    if(row==n-1 && col==m-1){
        return 1;
    }

    if(arr[row][col]==1){
        return 0;
    }

    int ans = fun(n,m,row,col+1,arr) + fun(n,m,row+1,col,arr);

return ans;
}

int fundp(int n,int m,int row,int col,vector<vector<int>> &dpp,vector<vector<int>> &arr){

    if(row>=n || col>=m){
        return 0 ; 
    }
    if(dpp[row][col]!=-1){
        return dpp[row][col];
    }

    if(arr[row][col]==1){
        dpp[row][col] = 0 ;
        return 0;
    }

    dpp[row][col] = fundp(n,m,row+1,col,dpp,arr) + fundp(n,m,row,col+1,dpp,arr);
return dpp[row][col];
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


    // approach 1; using recursion ; TC ---> O(2^(n*m)) ; SC ---> O(n + m)
    int ans = fun(n,m,0,0,arr);
    cout<<ans<<endl;

    // approach 2; using dp(memoization) ; 

    vector<vector<int>> dpp(n,vector<int>(m,-1));
    dpp[n-1][m-1] = 1;
    ans = fundp(n,m,0,0,dpp,arr);
    cout<<ans<<endl;

    // approach 3; using dp(tabulation) ; TC --->O(n*m) ; SC --->O(n*m)
    // storing the no of ways to reach till i,j and then going to top as for no. of ways to reach n-1, m-1 we need steps before it

    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int j =0;j<m;j++){
        if(arr[0][j]==1){
            break;
        }
        else{
            dp[0][j] = 1;
        }
    }

    for(int i =0;i<n;i++){
        if(arr[i][0]==1){
            break;
        }
        else{
            dp[i][0] = 1;
        }
    }

    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            if(arr[i][j]==1){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    cout<<dp[n-1][m-1]<<endl;


    // approach 5; optimizing space in tabulation; TC ---> O(n*m) ; SC ---> O(2*m)
    // we just need to remember the last row

    vector<int> p(m,0);

    for(int i =0;i<m;i++){
        if(arr[0][i]==1){
            break;
        }
        else{
            p[i]  = 1;
        }
    }

    bool one;
    if(arr[0][0]==0){
        one = false;
    }
    else{
        one = true;
    }

    for(int i = 1;i<n;i++){
        vector<int>temp(m);
        if(one==false){
            if(arr[i][0]==0){
                temp[0]  = 1;
            }
            else{
                one = true;
                temp[0] = 0;
            }
        }
        else{
            temp[0] = 0 ; 
        }
        
        for(int j = 1;j<m;j++){
            if(arr[i][j]==1){
                temp[j] = 0 ;
            }
            else{
                temp[j] = temp[j-1] + p[j];
            }
        }
        p = temp;
    }
    cout<<p[m-1]<<endl;

return 0;
}
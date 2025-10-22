#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int nCr(int n,int r){

    int ans = 1;
    for(int i = 1;i<=r;i++){
        ans = ans * n;
        ans = ans / i;
        n--;
    }
return ans;
}

// approach 2; using recursion ; TC ---> O(2^(n*m)) ; SC ---> O(n+m)

int fun(int n,int m,int row,int col){

    if(row>=n || col>=m){
        return 0 ;
    }

    if(row==n-1 && col==m-1){
        return 1;
    }

    int ans = fun(n,m,row,col+1) + fun(n,m,row+1,col);

return ans;
}

int fundp(int n,int m,int row,int col,vector<vector<int>> &dpp){

    if(row>=n || col>=m){
        return 0 ; 
    }
    if(dpp[row][col]!=-1){
        return dpp[row][col];
    }

    dpp[row][col] = fundp(n,m,row+1,col,dpp) + fundp(n,m,row,col+1,dpp);
return dpp[row][col];
}

int main(){

    int n;
    cin>>n;

    int m;
    cin>>m;

    // approach 1;      TC ---> O(min(m,n))  ; SC ---> O(1)
    // we can just use the formula of total no of arrangements ; which is (n + m - 2)!  / (n-1)! * (m-1)! ==> (n+m-2)! / (min(m,n) -1)!

    int a = m + n - 2;
    int b = min(m,n) - 1;

    int ans = nCr(a,b);
    cout<<ans<<endl;

    // approach 2; using recursion ; TC ---> O(2^(n*m)) ; SC ---> O(n + m)
    ans = fun(n,m,0,0);
    cout<<ans<<endl;

    // approach 3; using dp(memoization) ; 

    vector<vector<int>> dpp(n,vector<int>(m,-1));
    dpp[n-1][m-1] = 1;
    ans = fundp(n,m,0,0,dpp);
    cout<<ans<<endl;

    // approach 4; using dp(tabulation) ; TC --->O(n*m) ; SC --->O(n*m)

    vector<vector<int>> dp(n,vector<int>(m,1));
    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    cout<<dp[n-1][m-1]<<endl;


    // approach 5; optimizing space in tabulation; TC ---> O(n*m) ; SC ---> O(2*m)
    // we just need to remember the last row

    vector<int> p(m,1);

    for(int i = 1;i<n;i++){
        vector<int>temp(m,1);
        for(int j = 1;j<m;j++){
            temp[j] = temp[j-1] + p[j];
        }
        p = temp;
    }
    cout<<p[m-1]<<endl;

return 0;
}
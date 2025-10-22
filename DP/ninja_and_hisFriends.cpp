#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// approach 1: using recursion; TC ---> O(9^n)  ; SC ---> O(n)
// the maxi val from the arow till the last
int fun(int n,int m,vector<vector<int>> &arr,int row,int acol,int bcol){

    int ans = arr[row][acol];
    if(acol!=bcol){
        ans+=arr[row][bcol];
    }

    int maxi = 0;

    if(row < n - 1){
        for(int i = 0;i<=2;i++){
            // alice moves to (row+1, acol - 1 + i)
            if(((acol - 1 + i)>=0) && ((acol-1+i)<m)){
                for(int j = 0 ;j<=2;j++){
                    // bob moves to (row+1,bcol-1+j)
                    if(((bcol - 1 + j) >= 0) && ((bcol - 1 + j) < m)){
                        maxi = max(maxi , fun(n,m,arr,row+1,acol - 1 + i, bcol - 1 + j));
                    }
                }
            }   
        }
    }
return ans + maxi;
}

int fundp(int n,int m, vector<vector<int>> &arr,int row,int acol,int bcol,vector<vector<vector<int>>> &dp){
    if(dp[row][acol][bcol]!=-1){
        return dp[row][acol][bcol];
    }
    int ans = arr[row][acol];
    if(acol!=bcol){
        ans+=arr[row][bcol];
    }

    int maxi = 0;

    if(row < n - 1){
        for(int i = 0;i<=2;i++){
            // alice moves to (row+1, acol - 1 + i)
            if(((acol - 1 + i)>=0) && ((acol-1+i)<m)){
                for(int j = 0 ;j<=2;j++){
                    // bob moves to (row+1,bcol-1+j)
                    if(((bcol - 1 + j) >= 0) && ((bcol - 1 + j) < m)){
                        maxi = max(maxi , fundp(n,m,arr,row+1,acol - 1 + i, bcol - 1 + j,dp));
                    }
                }
            }   
        }
    }
    ans = ans + maxi;
return dp[row][acol][bcol] = ans;
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

    int ans = fun(n,m,arr,0,0,m-1);
    cout<<ans<<endl;

    // approach 2: using dp(memoization);  TC ---> O(n*m*m) * 9 ; SC ---> O(n*m*m) + O(n)
    // TC will be the total no. of diff states i.e. O(n*m*m) as for other calls we will return from the table 
    // there are overlapping subproblems so dp can be applied
    // from nth row, from ith col of alice and from jth col of bob we are finding the maxi val

    vector<vector<vector<int>>> dpp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    ans = fundp(n,m,arr,0,0,m-1,dpp);
    cout<<ans<<endl;

    // approach 3; using dp(tabulation); TC ---> O(n*m*m) + O(m*m) ; SC ---> O(n*m*m)
    // if we are in row i, and alice in col j and bob in col k then how much we can earn
    // it will be there curr val plus maxi they can earn from where they came

    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    dp[0][0][m-1] = arr[0][0];
    if((m-1)!=0){
        dp[0][0][m-1]+= arr[0][m-1];
    }

    // in ith row
    for(int i = 1;i<n;i++){
        // when alice in jth col
        for(int j = 0;j<m;j++){
            // when bob in kth col
            for(int k = 0;k<m;k++){
                // adding there curr val
                dp[i][j][k] = arr[i][j];
                if(j!=k){
                    dp[i][j][k]+= arr[i][k];
                }
                // maxi val that earned from where they came
                int maxi = -1 ;
                // alice came from (j - 1 + a)
                for(int a = 0;a<=2;a++){
                    if(((j - 1 + a) >= 0) && ((j - 1 + a)<m)){
                        // bob came from (k - 1 + b)
                        for(int b = 0;b<=2;b++){
                            if(((k - 1 + b) >= 0) && ((k - 1 + b)< m)){
                                if(dp[i-1][j-1+a][k-1+b]!=-1){ // means then may have came from [i-1][j-1+1][k-1+b]
                                    maxi = max(maxi , dp[i-1][j-1+a][k-1+b]);
                                }
                            }
                        }
                    }
                }
                // -1 is to check the alice in ith row and bob in jth is even possible or not
                if(maxi==-1){
                    dp[i][j][k] = -1;
                }
                else{
                    dp[i][j][k]+= maxi;
                }
            }
        }
    }

    ans = dp[n-1][0][0];
    for(int i = 0 ;i<m;i++){
        for(int j = 0;j<m;j++){
            ans = max(ans, dp[n-1][i][j]);
        }
    }

    cout<<ans<<endl;

    // approach 4; optimizing space in case of tabulation; TC ---> O(n*m*m) ; SC ---> O(m*m)
    // we need the knowledge of only prev row one matrix

    vector<vector<int>> prev(m,vector<int>(m,-1));
    // prev[i][j] means when alice is in ith col and bob in jth col what is maxi val till this row

    prev[0][m-1] = arr[0][0];
    if((m-1)!=0){
        prev[0][m-1]+= arr[0][m-1];
    }

    for(int i = 1;i<n;i++){
        vector<vector<int>> temp(m,vector<int>(m));
        for(int j = 0;j<m;j++){
            for(int k = 0;k<m;k++){
                temp[j][k] = arr[i][j];
                if(j!=k){
                    temp[j][k]+= arr[i][k];
                }

                int maxi = -1;
                for(int a = 0 ;a<=2;a++){
                    if((j - 1 + a) >= 0 && (j - 1 + a)<m){
                        for(int b = 0;b<=2;b++){
                            if((k - 1 + b)>=0 && (k - 1+ b)<m){
                                if(prev[j-1+a][k-1+b] !=-1){
                                    maxi = max(maxi , prev[j-1+a][k-1+b]);
                                }
                            }
                        }
                    }
                }

                if(maxi==-1){
                    temp[j][k] = -1;
                }
                else{
                    temp[j][k]+= maxi;
                }
            }
        }
        prev = temp;
    }

    ans = prev[0][0];
    for(int i = 0 ;i<m;i++){
        for(int j = 0;j<m;j++){
            ans =max(ans, prev[i][j]);
        }
    }

    cout<<ans<<endl;

return 0;
}
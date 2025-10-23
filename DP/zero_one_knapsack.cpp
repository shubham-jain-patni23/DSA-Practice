#include<iostream>
#include<vector>
using namespace std;

// approach 1; TC---> O(2^n) ; SC ---> O(n)
// what maxi val can be achieved from idx with currwt
int fun(int n,vector<int>&wt,vector<int>&val,int idx, int currval,int currwt,int w){

    if(idx==n){
        return currval;
    }

    // if we don't take arr[idx]; what maxi val can be achieved
    int x = fun(n,wt,val,idx + 1,currval,currwt,w);

    // if we take arr[idx]; what maxi val can be achieved
    if(wt[idx] <= (w - currwt)){
        int y = fun(n,wt,val,idx + 1,currval+val[idx],currwt + wt[idx],w);
        x = max(x,y);
    }

return x;
}

int fundp(int n,vector<int>&wt,vector<int>&val,int idx,int currval,int currwt,int w,vector<vector<vector<int>>>&dp){
    if(idx==n){
        return currval;
    }

    // dp[idx][currval][currwt] means starting from idx and with currval and currwt, what maxi val can be achieved
    if(dp[idx][currval][currwt]!=-1){
        return dp[idx][currval][currwt];
    }

    dp[idx][currval][currwt] = fundp(n,wt,val,idx + 1,currval,currwt,w,dp);

    if(wt[idx]<= (w - currwt)){
        int y = fundp(n,wt,val,idx + 1,currval + val[idx], currwt+wt[idx],w,dp);
        dp[idx][currval][currwt] = max(dp[idx][currval][currwt], y);
    }
return dp[idx][currval][currwt];
}

int main(){

    int n;
    cin>>n;

    int w;
    cin>>w;

    vector<int> val(n);
    for(int i =0;i<n;i++){
        cin>>val[i];
    }

    vector<int> wt(n);  
    for(int i =0;i<n;i++){
        cin>>wt[i];
    }

    // approach 1
    int ans = fun(n,wt,val,0,0,0,w);
    cout<<ans<<endl;

    // approach 2; using dp(memoization) TC ---> O(n * maxval * w) ; SC ---> O(n* maxval * w) + O(n)
    // as we may have overlapping subproblems
    // there are three variable to work on ; idx, currval, currwt; that means 
    // from index idx till end when the curr value was currval and curr weight as currwt what maxi val can be achieved 

    int maxval = 0;
    for(int i =0;i<n;i++){
        maxval+= val[i];
    }

    vector<vector<vector<int>>> dpp(n,vector<vector<int>>(maxval+1,vector<int>(w+1,-1)));
    ans = fundp(n,wt,val,0,0,0,w,dpp);
    cout<<ans<<endl;

    // approach 3; using dp(tabulation) TC ---> O(n*maxval*w) ; SC ----> O(n*maxval*w)
    // for the ans dp[0][0][0], we need the next rows 
    // so we start from the last row matrix 
    // dp[i][j][k] means from idx i with currval j and currwt k what is the maxi val achievable from the remaining arr

    vector<vector<vector<int>>> dp(n,vector<vector<int>>(maxval+1,vector<int>(w+1,0)));

    // filling last row(matrix) for n-1
    for(int i = 0;i<=maxval;i++){
        for(int j =0;j<=w;j++){
            dp[n-1][i][j] = i;
            if(wt[n-1] <= (w - j)){
                dp[n-1][i][j] = i + val[n-1];
            }
        }
    }

    for(int i = n-2;i>=0;i--){
        for(int j = 0;j<=maxval;j++){
            for(int k = 0;k<=w;k++){
                // don't take val[i-1]
                dp[i][j][k] = dp[i+1][j][k];
                if((wt[i] <= (w - k)) && ((j + val[i]) <= maxval) && ((k + wt[i]) <= w)){
                    dp[i][j][k] = max(dp[i][j][k] , dp[i+1][j+val[i]][k+wt[i]]);
                }
            }
        }
    }

    cout<<dp[0][0][0]<<endl;

    // approach 4; space optimization ; TC ---> O(n*maxval*w) ; SC ---> O(2maxval*w)
    // we need the knowledge of only the last matrix

    // approach 5;
    

return 0;
}
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

// approach 5; TC ---> O(2^n) ; SC ---> O(n)
// if we are on idx and the avail wt is w, then what maxi val can be achieved from idx till end

int fun2(int n, vector<int>&wt,vector<int>&val, int idx,int w){
    if(idx==n-1){
        if(wt[idx] <= w){
            return val[idx];
        }
    return 0;
    }

    // don't take it 
    int x = fun2(n,wt,val,idx+1,w);
    
    // take it
    if(wt[idx] <= w){
        int y = val[idx] + fun2(n,wt,val,idx + 1,w - wt[idx]);
        x = max(x,y);
    }
return x;
}

int fundp2(int n, vector<int>&wt,vector<int>&val, int idx,int w,vector<vector<int>>&dp){
    if(idx==n-1){
        if(wt[idx] <= w){
            return val[idx];
        }
    return 0;
    }

    if(dp[idx][w]!=-1){
        return dp[idx][w];
    }

    // don't take it 
    int x = fundp2(n,wt,val,idx+1,w,dp);
    
    // take it
    if(wt[idx] <= w){
        int y = val[idx] + fundp2(n,wt,val,idx + 1,w - wt[idx],dp);
        x = max(x,y);
    }
return dp[idx][w] = x;;
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
    ans = fun2(n,wt,val,0,w);
    cout<<ans<<endl;

    // approach 6; using dp(memoization); TC ---> O(n*w) ; SC ---> O(n*w) + O(n)

    vector<vector<int>> dp2(n,vector<int>(w+1,-1));
    ans = fundp2(n,wt,val,0,w,dp2);

    cout<<ans<<endl;

    // approach 7; using dp(tabulation); TC ---> O(n*w) ; SC ---> O(n*w)

    // dp[i][j] means from i till end with avai wt as j what is the maxi possible val that can be achieved
    for(int i =0;i<=w;i++){
        dp2[n-1][i] = 0;
        if(wt[n-1] <= i){
            dp2[n-1][i] = val[n-1];
        }
    }

    for(int i = n-2;i>=0;i--){
        for(int j = 0;j<=w;j++){
            // don't take it 
            dp2[i][j] = dp2[i+1][j];
            if(wt[i] <= j){
                dp2[i][j] = max(dp2[i][j], val[i] + dp2[i+1][j - wt[i]]);
            }
        }
    }

    cout<<dp2[0][w]<<endl;

    // approach 8; space optimization; TC ---> O(n*w); SC ---> O(2*w)
    // we need the knowledge of the next row

    vector<int> next(w+1);

    for(int i =0;i<=w;i++){
        next[i] = 0;
        if(wt[n-1]<=i){
            next[i] = val[n-1];
        }
    }

    for(int i=n-2;i>=0;i--){
        vector<int> temp(w+1);
        for(int j=0;j<=w;j++){
            temp[j] = next[j];
            if(wt[i]<=j){
                temp[j] = max(next[j], val[i] + next[j - wt[i]]);
            }
        }
        next = temp;
    }

    cout<<next[w]<<endl;

    // approach 9; space optimization to single row; TC ---> O(n*w); SC ---> O(w)
    // we need the knowledge of the next row and only the col lesser equal to curr col

    vector<int> curr(w+1);
    for(int i =0;i<=w;i++){
        curr[i] = 0;
        if(wt[n-1] <= i){
            curr[i] = val[n-1];
        }
    }

    for(int i= n-2;i>=0;i--){
        for(int j = w;j>=0;j--){
            if(wt[i]<=j){
                curr[j] = max(curr[j], val[i] + curr[j-wt[i]]);
            }
        }
    }

    cout<<curr[w]<<endl;

return 0;
}
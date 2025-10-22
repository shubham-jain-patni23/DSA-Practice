#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// approach 1; using recursion ; TC ---> O(2^n) ; SC ---> O(n)
// arr[idx] can be put in first or second arr at any time (can maintain sum of both arr), 
// checking if arr can be partitioned when we are on idx with first and second
bool fun(int n,vector<int>&arr,int idx,int first,int second){

    if(idx==n){
        if(first==second){
            return true;
        }
        return false;
    }

    // put arr[idx] in first 
    bool x = fun(n,arr,idx+1,first + arr[idx],second);

    // put arr[idx] in second
    bool y = fun(n,arr,idx + 1, first,second + arr[idx]);

return (x || y);
}

// approach 2; using recursion ; TC ---> O(2^n) ; SC ---> O(n)
// there is no need to maintain two variable first and second 
// if we know first then second is (total - first);

bool fun2(int n,vector<int>&arr,int idx,int first,int total){

    if(idx==n){
        if(first == (total - first)){
            return true;
        }
        else{
            return false;
        }
    }

    if(first > (total / 2)){
        return false;
    }

    // taking arr[idx] in first
    bool x = fun2(n,arr,idx + 1,first + arr[idx],total);

    // not taking arr[idx] in first i.e. considering it in second
    bool y = fun2(n,arr,idx + 1,first,total);

return (x || y);
}

bool fundp(int n,vector<int> &arr,int idx,int first,int second,vector<vector<vector<int>>> &dp,int p){
    if(idx==n){
        if(first==second){
            return true;
        }
        else{
            return false;
        }
    }

    if(first >= p || second >= p){
        return false;
    }

    if(dp[idx][first][second]!=-1){
        return (bool)dp[idx][first][second];
    }

    bool x = fundp(n,arr,idx + 1, first+ arr[idx],second,dp,p);
    if(x==true){
        dp[idx][first][second] = (int)x;
        return x;
    }
    bool y = fundp(n,arr,idx + 1, first, second + arr[idx],dp,p);

    dp[idx][first][second] = (int)(x || y);
return (x||y);
}

bool fundp2(int n,vector<int>&arr,int idx ,int first,int total,vector<vector<int>> &dp){
    if(idx==n){
        if(first==(total - first)){
            return true;
        }
        else{
            return false;
        }
    }

    if(first > (total / 2)){
        return false;
    }

    if(dp[idx][first]!=-1){
        return (bool)dp[idx][first];
    }

    bool x = fundp2(n,arr,idx + 1,first + arr[idx],total,dp);
    if(x==true){
        dp[idx][first] = (int)x;
        return true;
    }
    bool y = fundp2(n,arr,idx + 1,first,total,dp);

    dp[idx][first] = (int)(x || y);
return (x || y);
}

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);  

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    // approach 1
    bool ans = fun(n,arr,0,0,0);
    cout<<ans<<endl;

    // approach 2
    int total = 0 ;
    
    for(int i = 0;i<n;i++){
        total+= arr[i];
    }
    
    // considering total is even
    ans = fun2(n,arr,0,0,total);
    cout<<ans<<endl;

    // approach 3; using dp(memoization)  ; TC ---> O(n * (total /2) * (total / 2)) ; SC ---> O(n * (total / 2) * (total/2))  + O(n)
    // we need to find from idx , first and second whether we can partition or not
    // here we maintaing three variable idx, first and second, so having dp arr of size n*sum/2*sum/2

    if(total%2==1){
        ans = false;
    }
    else{
        int x = (total/2) + 1;
        vector<vector<vector<int>>> dpp(n,vector<vector<int>>(x,vector<int>(x,-1)));
        ans = fundp(n,arr,0,0,0,dpp,x);
    }
    cout<<ans<<endl;
    
    // approach 4; using dp(memoization); TC ---> O(n * (total / 2))  + O(n)
    // maintaining only idx and first and calc second from the total

    if(total%2==1){
        ans = false;
    }
    else{
        vector<vector<int>> dp(n,vector<int>((total/2) + 1, -1));
        ans = fundp2(n,arr,0,0,total,dp);
    }
    cout<<ans<<endl;

    // approach 5; using tabulation; TC ---> O(n*(total /2)) ; SC ---> O(n*(total/2))
    // dp[i][j] means using the idx till i can we have first as j
    // ans will dp[n-1][total/2] means using the idx till n - 1 can we have first as total /2 
    // if first is total / 2 then second is also total / 2

    if(total%2==1){
        ans = false;
    }
    else{
        int x = total /2;
        vector<vector<bool>> dp(n+1, vector<bool>(x + 1));
        for(int i = 0;i<=n;i++){
            dp[i][0] = 1;
        }

        for(int i = 1;i<=x;i++){
            dp[0][i] = 0;
        }

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=x;j++){
                // not taking arr[i]
                dp[i][j] = dp[i-1][j];
                if((j - arr[i-1]) >= 0){ // considering arr[i]
                    dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]];
                }
            }
        }

        ans = dp[n][x];
    }

    cout<<ans<<endl;

    // approach 6; space optimization in case of tabulation; TC ---> O(n*(total/2)) ; SC ---> O(2*(total/2));
    // we need the knowledge of the prev row only

    if(total%2==1){
        ans =false;
    }
    else{
        int x = total / 2;
        vector<int> prev(x + 1, 0);
        prev[0] = 1;

        for(int i = 1;i<=n;i++){
            vector<int> temp(x + 1);
            for(int j = 0;j<=x;j++){
                if(j==0){
                    temp[j] = 1;
                }
                else{
                    temp[j] = prev[j];
                    if((j - arr[i -1]) >= 0){
                        temp[j] = temp[j] || prev[j - arr[i-1]];
                    }
                }
            }
            prev = temp;
        }
        ans = prev[x];
    }

    cout<<ans<<endl;

    // it is a variation of subset sum problem 
    // here the target is total / 2

return 0;
}
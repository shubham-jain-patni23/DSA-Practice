#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// approach 1 ; using recursion ; TC ---> O(k^n) ; SC ---> O(n)
// mini cost to reach from idx to n-1 
int fun(int n,vector<int>&arr,int k,int idx){

    if(idx==n-1){
        return 0;
    }

    int mini = INT_MAX;

    // trying all the possible jumps
    for(int i = 1;i<=k;i++){
        if((idx + i) <= n-1){
            int x = abs(arr[idx] - arr[idx + i]) + fun(n,arr,k,idx + i);
            mini = min(x,mini);
        }
        else{
            break;
        }
    }
return mini;
}

// approach 2; using dp(memoization); TC ---> O(n*k) ; SC --->O(2n)

int fundp(int n,vector<int>&arr,int k,int idx,vector<int>&dp){

    if(idx==n-1){
        return 0 ;
    }
    if(dp[idx]!=INT_MAX){
        return dp[idx];
    }
    for(int i = 1;i<=k;i++){
        if(idx + i <=n-1){
            dp[idx] = min(dp[idx] , abs(arr[idx] - arr[idx + i]) + fundp(n,arr,k,idx+i,dp));
        }
        else{
            break;
        }
    }
return dp[idx];
}

int main(){

    int n;
    cin>>n;

    int k;
    cin>>k;

    vector<int> arr(n);

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int ans = fun(n,arr,k,0);
    cout<<ans<<endl;

    vector<int> dp(n,INT_MAX);

    ans = fundp(n,arr,k,0,dp);
    cout<<ans<<endl;


    // approach 3 : using dp(tabulation); TC ---> O(n*k)  ; SC ---> O(n)
    // for finding mini dis from 0 to n-1 we need the mini dis from the next idices, so we first find them

    dp[n-1] = 0;

    for(int i = n-2;i>=0;i--){
        for(int j = 1;j<=k;j++){
            if(i + j <= n-1){
                dp[i] = min(dp[i] , abs(arr[i] - arr[i + j]) + dp[i + j]);
            }
            else{
                break;
            }
        }
    }

    cout<<dp[0]<<endl;

    // approach 4: not using dp arr of size n but of size k ; TC ---> O(n*k^2) ; SC ---> O(k)

    vector<int> dpp(k+1,-1);
    dpp[1] = 0 ;

    for(int i = n-2;i>=0;i--){
        int curr = INT_MAX;
        for(int j = 1;j<=k;j++){
            if(i+j <=n-1){
                curr = min(curr, abs(arr[i] - arr[i + j]) + dpp[j]);
            }
            else{
                break;
            }
        }
        for(int j = k;j>=2;j--){
            dpp[j] = dpp[j-1];
        }
        dpp[1] = curr;
    }

    cout<<dpp[1]<<endl;

return 0;
}
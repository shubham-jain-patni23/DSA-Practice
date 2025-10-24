#include<iostream>
#include<map>
#include<utility>
#include<vector>
using namespace std;

// approach 1 : using recursion ; TC ---> O(2^n) ; SC ---> O(n)
// with current sum as currsum and starting from idx, no. of exp that can be formed whose val is target
int fun(int n,vector<int>&arr,int idx,int currsum,int target){

    if(idx==n){
        if(currsum==target){
            return 1;
        }
        return 0;
    }

    // add it 
    int x = fun(n,arr,idx + 1,currsum + arr[idx], target);
    // subtract it
    int y = fun(n,arr,idx + 1,currsum - arr[idx], target);

return x + y;
}

int fundp(int n,vector<int>&arr,int idx,int currsum,int target,vector<vector<int>>&dp,int neg){

    if(idx==n){
        if(currsum==target){
            return 1;
        }
        return 0;
    }

    if(dp[idx][currsum + neg]!=-1){
        return dp[idx][currsum + neg];
    }

    // add it 
    int x = fundp(n,arr,idx + 1,currsum + arr[idx], target,dp,neg);

    // subtract it
    int y = fundp(n,arr,idx + 1,currsum - arr[idx], target,dp,neg);

return dp[idx][currsum + neg] = x + y;
}

int fundp2(int n,vector<int>&arr,int idx,int currsum,int target,map<pair<int,int>,int> &mp){

    if(idx==n){
        if(currsum==target){
            return 1;
        }
        return 0;
    }

    if(mp.find({idx,currsum})!=mp.end()){
        return mp[{idx,currsum}];
    }

    // add it 
    int x = fundp2(n,arr,idx + 1,currsum + arr[idx], target,mp);

    // subtract it
    int y = fundp2(n,arr,idx + 1,currsum - arr[idx], target,mp);

return mp[{idx,currsum}] = x + y;
}

int main(){

    int n;
    cin>>n;

    int target;
    cin>>target;

    vector<int>arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    int ans = fun(n,arr,0,0,target);
    cout<<ans<<endl;

    // approach 2; using dp(memoization); TC ---> O(n*2total); SC ---> O(n)
    // using 2d vector for memoizing

    int pos = 0;

    for(int i = 0;i<n;i++){
        pos+=arr[i];
    }
    int neg = pos;
    int x = (pos + 1) + (neg);
    vector<vector<int>> dpp(n,vector<int>(x,-1));

    ans = fundp(n,arr,0,0,target,dpp,neg);
    cout<<ans<<endl;

    // approach 3; using dp(memoization); TC --->> O(n*2total log2(n*2total)) ; SC ---> O(n) + O(n*2total)
    // using map for memoizing

    // we want to store the val of two var; idx and currsum
    map<pair<int,int>, int> mp;
    ans = fundp2(n,arr,0,0,target,mp);
    cout<<ans<<endl;

    // approach 4; using dp(tabulation); TC ---> O(n*2total) ; SC ---> O(n*2total)

    // dp[i][j] means when we are at idx i and currsum is j then from the remaining ele 
    // what are no. of exp which eval to target

    vector<vector<int>> dp(n,vector<int>(x,0));

    for(int i =0;i<x;i++){
        // add 
        int currsum = i - neg;
        int add = currsum + arr[n-1];
        if(add==target){
            dp[n-1][i]++;
        }

        // subtract arr[idx] to currsum
        int sub = currsum - arr[n-1];
        if(sub==target){
            dp[n-1][i]++;
        }
    }

    for(int i = n-2;i>=0;i--){
        for(int j = 0;j<x;j++){
            int currsum = j - neg;
            // add
            int add = currsum + arr[i];
            if((add + neg) < x){
                dp[i][j]+= dp[i+1][add+neg];
            }
            // sub
            int sub = currsum - arr[i];
            if((sub + neg) >= 0){
                dp[i][j]+= dp[i+1][sub+neg];
            }
        }
    }

    cout<<dp[0][neg]<<endl;

    // approach 5; space optimization; TC ---> O(n*2total) ; SC ---> O(2*2total)
    // we need the knowledge of the next row

    vector<int> next(x, 0);
    
    for(int i =0;i<x;i++){
        // add 
        int currsum = i - neg;
        int add = currsum + arr[n-1];
        if(add==target){
            next[i]++;
        }

        // subtract arr[idx] to currsum
        int sub = currsum - arr[n-1];
        if(sub==target){
            next[i]++;
        }
    }

    for(int i = n-2;i>=0;i--){
        vector<int> temp(x,0);
        for(int j = 0;j<x;j++){
            int currsum = j - neg;
            // add
            int add = currsum + arr[i];
            if((add + neg) < x){
                temp[j]+= next[add+neg];
            }
            // sub
            int sub = currsum - arr[i];
            if((sub + neg) >= 0){
                temp[j]+= next[sub+neg];
            }
        }
        next = temp;
    }
    cout<<next[neg]<<endl;

    // this problem is similar cnt no. of parition with diff d

return 0;
}
#include<iostream>
#include<vector>
using namespace std;

// approach 1: using recursion ; TC ---> O(2*2^n) ; SC ---> O(n)
// maxi cost from idx to n-1
int fun(int n,vector<int>&arr,int idx){

    if(idx >= n){
        return 0;
    }

return max(arr[idx] + fun(n,arr,idx + 2) , fun(n,arr,idx + 1));
}

// approach 2: using dp(memoization) ; TC ---> O(2*n); SC ---> O(3*n)

int fundp(int n,vector<int>&arr,int idx,vector<int>&dp){
    
    if(idx>=n){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    dp[idx] = max(arr[idx] + fun(n,arr,idx + 2) , fun(n,arr,idx + 1));
return dp[idx];
}

int funcir(int n,vector<int>&arr,int idx,vector<int>&dpp,vector<int>&dpp2,bool last){
    
    if(idx>=n){
        return 0;
    }

    if(last == true && dpp[idx]!=-1){
        return dpp[idx];
    }
    if(last == false && dpp2[idx]!=-1){
        return dpp2[idx];
    }
    // take 
    if(idx==0){
        // take 
        dpp[idx] = arr[idx] + funcir(n,arr,idx + 2,dpp,dpp2,false);
        // not take
        dpp[idx] = max(dpp[idx], funcir(n,arr,idx + 1,dpp,dpp2,true));
        return dpp[idx];
    }
   
    if(idx==n-1){
        if(last){
            return arr[idx];
        }
        else{
            return 0;
        }
    }

    if(last){
        dpp[idx] = max(arr[idx] + funcir(n,arr,idx + 2,dpp,dpp2, last), funcir(n,arr,idx + 1,dpp,dpp2,last));
        return dpp[idx];
    }
    else{
        dpp2[idx] = max(arr[idx] + funcir(n,arr,idx + 2,dpp,dpp2, last), funcir(n,arr,idx + 1,dpp, dpp2,last));
        return dpp2[idx];
    }
return -1;
}

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    // taking 0th idx, not considering the last idx
    int ans1 = fun(n-1, arr, 0);
    // not taking 0th idx, considering last idx
    int ans2 = fun(n,arr,1);

    int ans =max(ans1,ans2);
    if(n==1) ans =arr[0];
    cout<<ans<<endl;

    // taking 0th idx
    vector<int> dp(n,-1);
    ans1 = fundp(n-1,arr,0,dp);

    // not taking 0th idx
    vector<int> dp2(n,-1);
    ans2 = fundp(n,arr,1,dp2);

    ans = max(ans1,ans2);
    if(n==1) ans = arr[0];
    cout<<ans<<endl;

    // approach 3: using dp(tabulation) ; TC ---> O(2*n) ; SC ---> O(n)
    // if we are including or not the curr idx then we need to check the maxi cost from idx +1 or idx + 2
    // so we calc them in adv

    // not taking 0th idx, considering last idx
    // considering n >=3
    dp[n-1] = arr[n-1];
    dp[n-2] = max(arr[n-2], arr[n-1]);

    for(int i = n-3;i>=1;i--){
        dp[i] = max(arr[i] + dp[i+2] , dp[i+1]);
    }
    ans1 = dp[1];

    // taking 0th idx, not considering last idx;
    dp[n-2] = arr[n-2];
    dp[n-3] = max(arr[n-3],arr[n-2]);

    for(int i = n-4;i>=0;i--){
        dp[i] = max(arr[i] + dp[i+2], dp[i+1]);
    }

    ans2 = dp[0];
    ans =max(ans1,ans2);
    cout<<ans<<endl;

    // approach 4: using dp(tabulation) ; TC ---> O(2n) ; SC ---> O(1)

    // taking 0th idx, not considering last idx
    int first = 0;
    int second = 0;

    for(int i = n-2;i>=0;i--){
        int x = max(arr[i] + second, first);
        second = first;
        first = x;
    }

    ans1 = first;

    // not taking 0th idx, considering last idx

    first = 0 ;
    second = 0;
    for(int i = n-1;i>=1;i--){
        int x = max(arr[i] + second, first);
        second = first;
        first = x;
    }
    ans2 = first;
    ans = max(ans1,ans2);

    if(n==1){
        ans = arr[0];
    }

    cout<<ans<<endl;


    // approach 5 : using the fun only once ; TC ---> O(n) ; SC ---> O(2N)
    
    vector<int> dpp(n,-1);
    vector<int> dpp2(n,-1);
    ans = funcir(n,arr,0,dpp,dpp2,true);
    cout<<ans<<endl;


return 0;
}
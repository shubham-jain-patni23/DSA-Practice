#include<iostream>
#include<string> 
#include<vector>
#include<algorithm>
using namespace std;


int main(){

    int n;
    cin>>n;

    int k;
    cin>>k;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    // appraoch 1 ; TC ---> O(n* 2^n)  ; SC ---> O(1)

    // approach 2 ; O(2^n) ; O(n) because of using call stack 
    // using recursion considering the sum no. of sub and not considering no. of sub ; 

    // approach 3;   TC ---> O(n * k)  ; SC ---> O(n * k)
    // using dp 

    vector<vector<bool>> dp(n+1,vector<bool>(k+1,0));

    for(int i =0 ; i<=n;i++){
        dp[i][0] = 1;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=k;j++){
            dp[i][j] = dp[i-1][j];
            if(j >= arr[i-1]){
                dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]];
            }
        }
    }

    cout<<dp[n][k]<<endl;


return 0;
}
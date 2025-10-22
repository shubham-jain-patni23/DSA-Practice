#include<iostream>
#include<vector>
using namespace std;

// step1 : if we can make a recursion from the given problem 
// step2 : and if there are overlapping subproblems 
// then we can apply dynamic programming

// using just recursion; TC ---> O(2^n); SC ---> O(n) of call stack
int fibrec(int n){
    if(n==0 || n==1){
        return n;
    }
return fibrec(n-1) + fibrec(n-2);
}

// using memoization; TC ---> O(n)   ; SC ---> O(n) due to call stack and O(n) of arr ===> O(2n)
int fib(int n,vector<int> &dp){
    if(n==0 || n==1){
        return n;
    }

    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = fib(n-1,dp) + fib(n-2,dp);
return dp[n];
// return dp[n] = fib(n-1, dp) + fib(n-2,dp);
}

int main(){

    int n;
    cin>>n;

    int ans ;

    ans = fibrec(n);
    cout<<ans<<endl;

    vector<int>dp(n+1,-1);

    ans = fib(n,dp);
    cout<<ans<<endl;

    // using tabulation(bottom - up)   ; TC ---> O(n) ; SC --->O(n)
    dp[0] = 0; 
    dp[1] = 1;

    for(int i = 2;i<=n;i++){
        dp[i]= dp[i-1] + dp[i-2];
    }

    cout<<dp[n]<<endl;


    // using tabulation , not using the dp arr; TC ---> O(n) ; SC ---> O(1)
    int first = 0 ; 
    int second = 1;
    
    for(int i = 2;i<=n;i++){
        int x= first + second;
        first = second;
        second = x; 
    }
    if(n==0){
        second =first;
    }
    cout<<second<<endl;

    // tabulation but without using the dp arr

return 0;
}
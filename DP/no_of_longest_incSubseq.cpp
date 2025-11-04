#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    // approach 1; TC ---> O(n^2) + O(n^2) + O(n); SC ---> O(n) + O(n) 
    // we need the total no. of lis
    // we first find lis for every idx
    // then we find the ways to make lis for every lis
    // then cnt of ways of all the idx with lis len will be total no. of lis

    vector<int> dp(n,1);
    int ans = 1;

    for(int i = 0;i<n;i++){             // O(n^2)
        for(int j = 0;j<i;j++){
            if(arr[j] < arr[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }

    vector<int> ways(n,0);

  
    for(int i = 0;i<n;i++){         // O(n^2)
        for(int j =0;j<i;j++){
            if((arr[j] < arr[i]) && (1 + dp[j] == dp[i])){
                ways[i]+= ways[j];
            }
        }
        if(ways[i]==0){
            ways[i] = 1;
        }
    }

    int cnt = 0 ;
    for(int i = 0;i<n;i++){     // O(n)
        if(dp[i]==ans){
            cnt+= ways[i];
        }
    }

    cout<<cnt<<endl;

    // approach 2;  TC ---> O(n^2) + O(n); SC ---> O(2n)
    // if some arr[j] < arr[i] has more lis len than the curr lis len of arr[i]
    // then lis of arr[i] should be made using lis of arr[j], in that case
    // dp[i] = dp[j] + 1 i.e. lis ending at arr[i] will be lis ending at arr[j] + 1
    // and ways to make lis ending at arr[i] will be ways to make lis ending at arr[j]
    // but if some arr[j] < arr[i] has lis len as dp[j] + 1 = dp[i]
    // that means lis ending at arr[i] can also be made using it 
    // so we will add the no. of ways cnt[j] to cnt[i]
    // and add all the ways to make lis ending at any idx

    vector<int> dp1(n,1);
    vector<int> cnt1(n,1);
    ans = 1;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[j] < arr[i] && dp1[j] + 1 > dp1[i]){
                dp1[i] = dp1[j] + 1;
                cnt1[i] = cnt1[j];
            }
            else if(arr[j] < arr[i] && dp1[j] + 1 == dp1[i]){
                cnt1[i] += cnt1[j];
            }
        }
        ans =  max(ans, dp1[i]);
    }

    cnt = 0;
    for(int i =0;i<n;i++){
        if(dp1[i]==ans){
            cnt+=cnt1[i];
        }
    }

    cout<<cnt<<endl;

return 0;
}
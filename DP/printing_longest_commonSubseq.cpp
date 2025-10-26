#include<iostream>
#include<climits>
#include<set>
#include<map>
#include<utility>
#include<vector>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    // approach 1; using dp(tabulation); TC ---> O(n*n); SC ---> O(n*n)
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    dp[n][0] = 1;
    for(int i = 1;i<n;i++){
        if(arr[i-1] < arr[n-1]){
            dp[n][i] = 1;
        }
    }

    // dp[i][j] means what is maxi len inc subseq that we can get from idx i if prev ele was j
    for(int i = n-1;i>0;i--){
        for(int j = 0;j<i;j++){
            // don't take it
            int x = dp[i+1][j];
            // take it
            if(j==0 || arr[j-1] < arr[i-1]){
                int y = 1 + dp[i+1][i];
                x = max(x,y);
            }
            dp[i][j] = x;
        }
    }


    int i = 1,j  = 0;
    vector<int> res;
    
    while((i<=n) && (j<=n) && (dp[i][j]!=0)){
        if(i==n){
            if(dp[i][j]==1){
                res.push_back(arr[i-1]);
            }
            break;
        }
        else{
            // from not take 
            int x = dp[i+1][j];
            // from take 
            int y = -1;
            if((j==0) || (arr[j-1] < arr[i-1])){
                y = dp[i+1][i];
            }

            if((y!=-1) && (dp[i][j]==(1 + y))){
                res.push_back(arr[i-1]);
                j = i;
                i++;
            }
            else{
                i++;
            }
        }
    }

    for(auto i: res){
        cout<<i<<" ";
    }cout<<endl;

    // approach 2; 
    // dp[i] means len of lis ending at arr[i];

    vector<int> dp2(n,1);
    vector<int> last(n,0);
    int maxidx = 0;
    int ans = 1;

    for(int i= 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[j] < arr[i]){
                if((1 + dp2[j]) > dp2[i]){
                    dp2[i] = 1 + dp2[j];
                    last[i] = j;
                }
            }
        }
        if(dp2[i] > ans){
            ans = dp2[i];
            maxidx = i;
        }
    }
    int idx = maxidx;
    while(ans--){
        cout<<arr[idx]<<" ";
        idx = last[idx];
    }

return 0;
}
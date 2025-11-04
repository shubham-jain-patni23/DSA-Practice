#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(){

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    // approach 1; space optimization; TC ---> O(n*n) + O(n); SC ---> O(2*n)
    // dp[i] means len of longest div subseq ending at arr[i]
    // last[i] means idx of last ele before arr[i] in lis

    vector<int> dp(n,1);
    vector<int> last(n);

    sort(arr.begin(),arr.end());

    int lastidx = 0 ;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(((arr[i] % arr[j]) == 0) && (dp[j] + 1 > dp[i])){
                dp[i] = dp[j] + 1;
                last[i] = j;
            }
        }
        if(dp[i] > dp[lastidx]){
            lastidx = i;
        }
    }

    vector<int> res;

    int cnt = dp[lastidx];

    while(cnt--){
        res.push_back(arr[lastidx]);
        lastidx = last[lastidx];
    }

    for(auto i: res){
        cout<<i<<" ";
    }

return 0;
}
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

// fun to check whether s1 is predecessor of s2 or not; TC ---> O(s2)
bool isPre(string s1,string s2){

    if((s1.size()+1)!=s2.size()){
        return false;
    }

    int i = 0,j =0;
    int cnt = 1;

    while(i<s1.size() && j<s2.size()){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }
        else{
            if(cnt==0){
                return false;
            }
            else{
                cnt = 0;
                j++;
            }
        }
    }

    // inserted in b/w
    if(cnt==0){
        if(i==s1.size() && j==s2.size()){
            return true;
        }
        else{
            return false;
        }
    }

    // not inserted yet
    // in last should be inserted
    if((i==s1.size()) && (j==s2.size()-1)){
        return true;
    }
return false;
}

int main(){

    int n;
    cin>>n;

    vector<string> arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    int ans = 1;

    // approach 1; TC ---> O(nlog2n + n^2*l); SC ---> O(n)

    vector<int> dp(n,1);

    sort(arr.begin(),arr.end(),[](string s1,string s2){     // O(nlog2n)
        return s1.size() < s2.size();
    });

    // for(auto i : arr){
    //     cout<<i<<" ";
    // }cout<<endl;

    for(int i =0;i<n;i++){          // O(n^2len)
        for(int j = 0;j<i;j++){
            if(i==j){
                continue;
            }
            if(isPre(arr[j],arr[i]) && (dp[j] + 1 > dp[i])){       // O(len)
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }

    cout<<ans<<endl;

return 0;
}
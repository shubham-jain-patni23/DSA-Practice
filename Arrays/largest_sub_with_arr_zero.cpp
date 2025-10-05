#include<iostream>
#include<map>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    //approach 1: if the sum again becomes same that means the subarray in between has zero sum  ; TC --> O(nlogn) , SC ---> O(n)
    int ans = 0;
    map<int,int> mp;

    int curr = 0;
    mp[0] = -1;

    for(int i = 0;i<n;i++){
        curr+= arr[i];
        if(mp.find(curr)!=mp.end()){
            ans = max(ans, i - mp[curr]);
        }
        else{
            mp[curr] = i;
        }
    }

    cout<<ans<<endl;

return 0;
}
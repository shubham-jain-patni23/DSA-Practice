#include<bits/stdc++.h>
using namespace std;

int main(){

    // int n;
    // cin>>n;

    // int dig_cnt = 0; 

    // while(n > 0){
    //     dig_cnt++;           //O(log10(n))
    //     n = n/10;
    // }

    // cout<<dig_cnt<<endl;

    // string s;
    // cin>>s;

    // int ans = s.size();

    // cout<<ans<<endl;

    int n;
    cin>>n;

    int cnt = (int)log10(n) + 1;

    cout<<cnt;

return 0;
}
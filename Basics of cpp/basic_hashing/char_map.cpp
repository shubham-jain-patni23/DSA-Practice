#include<bits/stdc++.h>
using namespace std;

//both storing and fetching from a map takes O(log(n)) in all best, avg and worst case
//while in case of unordered_map storing and fetching takes O(1) in best and avg while O(N) in worst case

int main(){

    string s;
    cin>>s;

    map<char,int> mp;

    for(int i =0 ; i<s.size();i++){
        mp[s[i]]++;
    }

    int x;
    cin>>x;

    while(x--){
        char temp;
        cin>>temp;

        cout<<mp[temp]<<" ";

    }


return 0;
}
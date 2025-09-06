#include<bits/stdc++.h>
using namespace std;

// we can declare an array of size at max 1e7 i.e. too globally so to hash values greater than that we use stl hash fun i.e. maps

int main(){

    int n;
    cin>>n;

    map<int,int>mp;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }

    int maxi = -1;
    pair<int,int> ans = {-1,-1} ;
  

    for(auto it : mp){
        if(it.second > ans.second){
            ans.first = it.first;
            ans.second = it.second;
        }
    }

    cout<<ans.first<<"->"<<ans.second<<endl;


return 0;
}
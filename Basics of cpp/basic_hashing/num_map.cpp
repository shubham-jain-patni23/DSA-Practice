#include<bits/stdc++.h>
using namespace std;

// we can declare an array of size at max 1e7 i.e. too globally so to hash values greater than that we use stl hash fun i.e. maps

//hashing methods : division method, folding method, mid square method 

int main(){

    int n;
    cin>>n;

    // map<int,int> mp;
    // to reduce the time complexity to O(1) we can use unordered_map
    //in map we can have any data structure as key like pair also but in case of unordered_map we can have only individual datatypes as keys
    unordered_map<int,int> mp;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }

    // cout<<mp.size()<<endl;           //stores in sorted order of key
    // for(auto it : mp){
    //     cout<<it.first<< " "<<it.second<<endl;

    // }

    int x;
    cin>>x;

    while(x--){
        int temp;
        cin>>temp;

        cout<<mp[temp]<<" ";

    }


return 0;
}
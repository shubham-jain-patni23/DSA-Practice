#include<bits/stdc++.h>
using namespace std;

int main(){

    // map is a container where data is stored in key, val pair where key are unique in sorted order of key

    map<int,int> mp;
    map<int, pair<int,int>> mp1;
    map<pair<int,int>, int> mp2;

    mp.insert({1,2});
  //  mp.emplace({2,3});
    mp[4] = 5;
    mp2[{1,2}]= 5;

    for(auto it : mp){         //for each loop
        cout<<it.first<<" "<<it.second<<endl;
    }

    cout<<mp[1]<<endl;
    cout<<mp[5]<<endl;          //since there is no val for the key 5, so 0(or null) will be printed

    //if we want to know the add. of any no. then we use find()

    auto it = mp.find(5);       //if 5 is not present then it will point to end i.e. after the map

    auto it1 = mp.lower_bound(2);
    auto it2 = mp.upper_bound(3);

    cout<<*(it).second<<endl;


    multimap<int,int> mmp;      //it is similar to maps only thing is we can store multiple keys here
    unordered_map<int,int>mmp2; //it is similar to maps only thing is here the keys may not be sorted
    //map works in log time while unordered map works in O(1) in almost all cases

return 0;
}
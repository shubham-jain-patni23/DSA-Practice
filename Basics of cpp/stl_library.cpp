#include<bits/stdc++.h>
#include<iostream>
#include<utility>
using namespace std;


int main(){

    pair<int,pair<int,int>> p = {1,{2,3}};
    cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;

    pair<int,int> arr[] = {{1,2},{5,3}};

    cout<<arr[0].first<<" "<<arr[0].second<<" "<<arr[1].first<<" "<<arr[1].second<<endl;

return 0;
}
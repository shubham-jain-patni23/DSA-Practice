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

    int x = n/3;

    //approach1 , using maps   ; TC ---> O(nlogn)    ; SC ---> O(n)

    map<int,int> mp;
    for(int i =0;i<n;i++){
        mp[arr[i]]++;
    }

    for(auto it : mp){
        if(it.second > x){
            cout<<it.first<<" ";
        }
    }

return 0;
}
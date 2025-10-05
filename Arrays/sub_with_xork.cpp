#include<iostream>
#include<map>
using namespace std;

int main(){

    int n;
    cin>>n;

    int k;
    cin>>k;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    //approach 1: using prefix sum 

    map<int,int> mp;
    int cnt = 0;
    int curr = 0;

    mp[0]++;

    for(int i =0;i<n;i++){      //xorsum of sub ending with i
        curr = curr^ arr[i];

        int x = curr ^ k;
        if(mp.find(x)!=mp.end()){
            cnt+=mp[x];
        }
        //cnt+= mp[x]       ; we can also directly write it like this without checking for it
        mp[curr]++;
    }

    cout<<cnt<<endl;

return 0;
}
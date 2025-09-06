#include<bits/stdc++.h>
using namespace std;

// if we declare globally the array is initialized as 0 instead of garbage values
// int arr[1e7] ;

int main(){

    int n;
    cin>>n;

    int arr[n];

    // map<int,int> mp;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        // mp[arr[i]]++;
    }

    int x;
    cin>>x;

    int temp[x];

    int maxi = 0;       //precompute

    for(int i = 0;i<x;i++){
        cin>>temp[i];
        maxi = max(maxi,temp[i]);
    }

    int hash[maxi + 1] = {0};

    //max size of array that we can declare is 10^6 inside main() for int
    //if we declare it globally then the max size of array that we can declare is 10^7 for int
    //max size of array that we can declare is 10^7 inside main() for bool
    //if we declare it globally then the max size of array that we can declare is 10^8 for bool

    for(int i = 0;i<n;i++){             //precompute
        hash[arr[i]]++;
    }

    for(int i=0;i<x;i++){
        //cout<<mp[temp[i]]<<endl;
        cout<<hash[temp[i]]<<endl;

    }



return 0;
}
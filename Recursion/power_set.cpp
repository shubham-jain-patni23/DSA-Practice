#include<iostream>
#include<string> 
#include<vector>
#include<algorithm>
using namespace std;

bool checkbit(int x,int pos){
    return x & (1<<pos);
}

vector<vector<int>> fun(int arr[],int n){
    
    if(n==1){
        return {{arr[n-1]}, {}};
    }

    vector<vector<int>> ans;

    vector<vector<int>> temp = fun(arr,n-1);

    // taking and not-taking arr[n-1]
    for(auto i : temp){
        ans.push_back(i);       // not-taking arr[n-1]
        i.push_back(arr[n-1]);      
        ans.push_back(i);       // taking arr[n-1]
    }

return ans;
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<int>> ans;

    // approach 1;  TC --->   O(n*2^n) ;  SC --->O(n)
    // using the no. till 2^n to check which ele to keep in the subset
    
    for(int i = 0 ;i<(1<<n) ;i++){
        vector<int> temp;

        for(int j =0;j<n;j++){
            if(checkbit(i,j)){
                temp.push_back(arr[j]);
            }
        }
        ans.push_back(temp);
    }

    // for(auto i : ans){
    //     for(auto j : i){
    //         cout<<j<<" ";
    //     }cout<<endl;
    // }    
    // cout<<endl;

    vector<vector<int>>res = fun(arr,n);

    for(auto i: res){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }

return 0;
}
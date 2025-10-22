#include<iostream>
#include<vector>
using namespace std;

// approach 1;  TC ---> O(2^9)  ; SC ---> O(1)
// from 1 to 9 taking or not taking no. 

void fun(int k,int idx, int sum,int currsum,vector<vector<int>>&ans, vector<int> temp){

    if(idx>9){
        if(k==0 && currsum==sum){
            ans.push_back(temp);
        }
        return;
    }

    if(k==0){
        if(sum==currsum){
            ans.push_back(temp);
        }
        return ; 
    }
    //not taking no. 
    fun(k,idx + 1, sum , currsum , ans, temp);

    //taking no.
    temp.push_back(idx);
    fun(k-1, idx + 1, sum, currsum+idx, ans , temp);

}

int main(){

    int k;
    cin>>k;
    
    int sum;
    cin>>sum;

    vector<vector<int>>ans ; 
    vector<int> temp;

    fun(k,1,sum,0, ans, temp);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }

return 0;
}
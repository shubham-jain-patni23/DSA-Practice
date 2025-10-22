#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

// approach 1;   TC ---> O(2^n) + O(2^nlog2^n) ==> O(n*2^n)   ; SC ---> O(n)
// to avoid duplicates use set

void fun(int arr[],int n, int idx, vector<int>temp, vector<vector<int>> &ans){

    if(idx==n){
        sort(temp.begin(),temp.end());
        ans.push_back(temp);
        return;
    }

    // don't include it
    fun(arr,n, idx + 1, temp, ans);

    // include it
    temp.push_back(arr[idx]);
    fun(arr, n, idx + 1,temp,ans);

}

// approach 2; 

void fun2(int arr[],int n,int idx, vector<int> temp,vector<vector<int>> &ans,vector<int> &freq){

    if(idx==n){
        ans.push_back(temp);
        return ; 
    }

    if(idx==0 || arr[idx]!=arr[idx-1]){
        // if(idx==1){
        //     cout<<freq[arr[idx]+10]<<endl;
        // }
        for(int i = 0;i<=freq[arr[idx] + 10];i++){
            if(i > 0){
                temp.push_back(arr[idx]);
            }
            // if(idx==4 && i==4){
            //     for(auto it: temp){
            //         cout<<it<<" ";
            //     }cout<<endl;
            //     cout<<idx<<endl;
            // }
            fun2(arr, n, idx + 1, temp, ans, freq);
        }
    }
    else{
        fun2(arr, n, idx + 1, temp, ans, freq);
    }
   
}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    // approach 1;   

    vector<vector<int>> ans;
    vector<int> temp;


    fun(arr,n,0,temp,ans);

    set<vector<int>> s;
    for(auto i: ans){
        s.insert(i);
    }
    
    for(auto i : s){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }

    // approach 2 ;
    sort(arr , arr + n);
    vector<int> freq(22,0);

    for(int i = 0;i<n;i++){
        freq[arr[i] + 10]++;
    }

    vector<vector<int>> res;
    vector<int> temp2;
    fun2(arr, n, 0, temp2, res, freq);

    for(auto i: res){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }

return 0;
}
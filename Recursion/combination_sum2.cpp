#include<iostream>
#include<vector>
using namespace std;

// approach 1;  TC ---> exponentital if for mini x is 4 then O(4^n) ; SC ---> O(n)
// checking all the possible combinations

void fun(vector<int> &newarr,int target,vector<int>temp, int idx , int currsum,vector<vector<int>> &ans,vector<int> &freq){

    if(idx==newarr.size()){
        if(currsum==target){
            ans.push_back(temp);
        }
        return ;
    }

    int rem = target - currsum;
    int x = rem / newarr[idx];
    x = min(x, freq[newarr[idx]]);

    for(int i =0;i<=x;i++){
        if(i> 0){
            temp.push_back(newarr[idx]);
        }
        int y = currsum + i * newarr[idx];
        fun(newarr,target,temp,idx + 1, y,ans,freq);
    }

}

int main(){

    int n;
    cin>>n;

    int target;
    cin>>target;

    int arr[n];
    vector<int> freq(51,0);

    for(int i =0;i<n;i++){
        cin>>arr[i];
        freq[arr[i]]++;
    }

    vector<int> temp;
    vector<vector<int>> ans;
    vector<int> newarr;

    for(int i = 0;i<51;i++){
        if(freq[i] > 0){
            newarr.push_back(i);
        }
    }

    fun(newarr, target, temp,0, 0,ans,freq);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

return 0;
}
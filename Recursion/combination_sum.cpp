#include<iostream>
#include<vector>
using namespace std;

// approach 1;  TC ---> exponentital if for mini x is 4 then O(4^n) ; SC ---> O(n)
// checking all the possible combinations

void fun(int arr[],int n,int target,vector<int>temp, int idx , int currsum,vector<vector<int>> &ans){
    if(idx==n){
        if(currsum==target){
            ans.push_back(temp);
        }
        return ;
    }

    int rem = target - currsum;
    int x = rem / arr[idx];

    for(int i =0;i<=x;i++){
        if(i > 0){
            temp.push_back(arr[idx]);
        }
        int y = currsum + i * arr[idx];
        fun(arr,n,target,temp,idx + 1, y,ans);
    }

}

int main(){

    int n;
    cin>>n;

    int target;
    cin>>target;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> temp;
    vector<vector<int>> ans;

    fun(arr, n,target, temp,0, 0,ans);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

return 0;
}
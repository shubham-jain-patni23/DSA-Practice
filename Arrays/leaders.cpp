#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    //approach 1 ;  TC ---> O(n) + O(n) = O(2n) ==> O(n) ; SC ---> O(n)
    //find the leaders first and then reverse the ans vector such that ele appear in order they appear in the array

    vector<int> ans;

    int maxi = arr[n-1];
    ans.push_back(arr[n-1]);

    for(int i = n-2;i>=0;i--){
        if(arr[i] > maxi){
            maxi = arr[i];
            ans.push_back(maxi);
        }
    }

    reverse(ans.begin(),ans.end());

    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;

return 0 ;
}
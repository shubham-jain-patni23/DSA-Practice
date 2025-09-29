#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<int>> ans;
    sort(arr,arr+n);


    for(int i =0;i<n-2;i++){
        if(i!=0 && arr[i]==arr[i-1]){
            continue;
        }
        vector<int> temp(3,0);
        temp[0] = arr[i];

        int start = i + 1;
        int end = n-1;

        while(start < end){
            int x = arr[start] + arr[end];
            if(x== (-arr[i])){
                temp[1] = arr[start];
                temp[2] = arr[end];
                ans.push_back(temp);
                while(start < end && arr[start]==arr[start+1]){
                    start++;
                }
                start++;
            }
            else if(x < (-arr[i])){
                start++;
            }
            else{
                end--;
            }
        }
    }

    for(auto i: ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

return 0;
}
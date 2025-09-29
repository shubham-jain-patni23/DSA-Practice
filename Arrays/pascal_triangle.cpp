#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    int n;
    cin>>n;

    vector<vector<int>> ans;

    for(int i = 0;i<n;i++){
        vector<int> temp(i+1,1);
        for(int j =1; j<i;j++){
            temp[j] = ans[i-1][j-1] + ans[i-1][j];
        }
        ans.push_back(temp);

    }

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

return 0;
}
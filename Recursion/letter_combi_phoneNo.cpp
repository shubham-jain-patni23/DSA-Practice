#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> num = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

// approach 1; TC ---> O(n*maxi num size) ; SC --->O(n)
// making all the combinations

void fun(string s,int idx,vector<string>&ans, string temp){
    if(idx==s.size()){
        ans.push_back(temp);
        return;
    }

    int x = (int)(s[idx] - '0');

    for(int i = 0;i<num[x].size();i++){
        fun(s,idx + 1, ans, temp + num[x][i]);
    }

}

int main(){

    string s;
    cin>>s;

    vector<string> ans;
    if(s.size()>0){
        fun(s,0,ans,"");
    }

    for(auto i : ans){
        cout<<i<<" ";
    }

return 0;
}
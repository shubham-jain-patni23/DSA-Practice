#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isPalindrome(string s){            // O(n)

    int low = 0 , high = s.size() -1 ;

    while(low < high){
        if(s[low]!=s[high]){
            return false;
        }
        low++;
        high--;
    }
return true;
}

// approach 1;  TC ---> O(n^3)  ; SC ---> O(n)
// making possible palindromes and then calling fun again for the remaining str

void fun(string s,int low, int high,vector<vector<string>>&ans, vector<string>temp){
    if(low > high){
        ans.push_back(temp);
        return;
    }

    for(int i = low; i<=high;i++){
        string curr = s.substr(low,i-low + 1);
        
        vector<string> newtemp = temp;
        if(isPalindrome(curr)){                 //O(n)
            newtemp.push_back(curr);
            fun(s,i+1,high,ans,newtemp);
        }
    }
}

int main(){

    string s;
    cin>>s;

    int n = s.size();

    vector<vector<string>> ans;
    vector<string> temp;

    fun(s,0,n-1,ans,temp);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }

return 0;
}
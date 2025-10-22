#include<iostream>
#include<string> 
#include<vector>
#include<algorithm>
using namespace std;

// approach 1;  TC ---> O(2^n)  ; SC ---> O(n) for using call stack 

vector<string> fun(int n){

    if(n==1){
        return {"0", "1"};
    }
    if(n==2){
        return {"00", "01","10"};
    }

    vector<string> ans;

    // at last pos '0'

    vector<string> zero = fun(n-1);
    for(auto i: zero){
        string curr = i  + "0";
        ans.push_back(curr);
    }

    // at last pos '1'

    vector<string> one = fun(n-2);
    for(auto i: one){
        string curr = i + "01";
        ans.push_back(curr);
    }
return ans;
}

vector<string> fun2(int n){

    if(n==1){
        return {"0", "1"};
    }
    if(n==2){
        return {"00", "01","10"};
    }

    vector<string> ans;

    // at first pos '0'

    vector<string> zero = fun(n-1);
    for(auto i: zero){
        string curr ="0" + i;
        ans.push_back(curr);
    }

    // at first pos '1'

    vector<string> one = fun(n-2);
    for(auto i: one){
        string curr = "10" + i ;
        ans.push_back(curr);
    }
return ans;
}

int main(){

    int n;
    cin>>n;

    vector<string> ans = fun2(n);
    for(auto i : ans){
        cout<<i<<" ";
    }

    

return 0;
}
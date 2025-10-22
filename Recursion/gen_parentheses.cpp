#include<iostream>
#include<string> 
#include<vector>
#include<algorithm>
using namespace std;

// approach 1;    TC ---> O(2^n)   ; SC ---> O(n)
// upto any idx close brackets can't be used more than open; so the val of will be o<=c always
// if o==c then first we have to use open 
// if o < c then we can either first use open or close

vector<string> fun(int o, int c){

    if(o==0){
        string curr(c,')');
        return {curr};
    }

    vector<string> ans;

    if(o==c){
        //use open
        vector<string> curr = fun(o-1,c);
        for(auto i : curr){
            string temp = "(" + i;
            ans.push_back(temp);
        }
    }
    else{ // o < c
        //use open
        vector<string> use_o = fun(o  - 1 , c);

        for(auto i: use_o){
            string temp = "(" + i;
            ans.push_back(temp);
        }

        //use close
        vector<string> use_c = fun(o, c - 1);

        for(auto i : use_c){
            string temp = ")" + i;
            ans.push_back(temp);
        }
    }
return ans;
}

int main(){

    int n;
    cin>>n;

    vector<string> ans = fun(n,n);

    for(auto i : ans){
        cout<<i<<" ";
    }

return 0;
}
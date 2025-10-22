#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool isFound(string curr, vector<string>&dic){
    for(int i = 0;i<dic.size();i++){
        int x = dic[i].compare(curr);
        if(x==0){
            return true;
        }
    }
return false;
}

bool fun(string s,vector<string>&dic, int low, int high,int mini,int maxi){

    if(low == s.size()){
        return true;
    }

    if(low >= s.size()){
        return true;
    }

    string curr = s.substr(low,mini-1);
    low = low + (mini - 1);

    for(int i = low ; i<=high;i++){
        curr += s[i];
        if(curr.size() > maxi){
            break;
        }
        bool y = isFound(curr, dic);
        cout<<curr<<" "<<y<<endl;
        if(y){
            if(fun(s,dic,i+1,high,mini,maxi)){// this statement giving runtime er
                return true;
            }
        }
    }

return false;
}

int main(){

    string s;
    cin>>s;

    int n;
    cin>>n;

    vector<string> dic(n);

    for(int i = 0;i<n;i++){
        cin>>dic[i];
    }

    int mini = dic[0].size();
    int maxi = dic[0].size();    

    for(int i =0 ;i<dic.size();i++){
        int n = dic[i].size();
        mini = min(mini, n);
        maxi = max(maxi, n);
    }

    bool ans = fun(s,dic,0,s.size()-1,mini,maxi);
    cout<<ans<<endl;

return 0;
}
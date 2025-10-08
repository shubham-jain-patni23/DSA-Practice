#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(){

    string s,t;
    cin>>s>>t;

    int n = s.size();

    //approach 1 ; using soring  ; TC ---> O(2nlogn) + O(n)    ; SC ---> O(1)

    if(s.size()!=t.size()){
        cout<<false<<endl;
    }
    else{
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int x = s.compare(t);
        if(x==0){
            cout<<true<<endl;
        }
        else{
            cout<<false<<endl;
        }
    }

    //approach 2 ; using 2 freq arr checking cnts for each string ; TC ---> O(n) + O(26)(constant)  ==> O(n) ; SC ---> O(1)


    vector<int> freq1(26), freq2(26);

    for(int i =0;i<n;i++){
        freq1[s[i]-'a']++;
        freq2[t[i]-'a']++;
    }

    bool ans = true;

    for(int i = 0;i<26;i++){
        if(freq1[i]!=freq2[i]){
            ans = false;
            break;
        }
    }

    cout<<ans<<endl;

return 0;
}
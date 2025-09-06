#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin>>s;

    int hash[256] = {0};

    for(int i = 0;i<s.size();i++){
        hash[s[i]]++;                   //s[i] is autocasted to int inside hash[] as hash[] needs idx as int
    }

    int x;
    cin>>x;

    while(x--){
        char ch;
        cin>>ch;

        cout<<hash[ch]<<" ";

    }

return 0;
}
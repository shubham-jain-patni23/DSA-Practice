#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string s){
    
    int size = s.size();

    if(size==0 || size==1){
        return true;
    }

    if(s[0]!=s[size-1]){
        return false;
    }

    string str = s.substr(1, size-2);

return is_palindrome(str);
}

bool fun_rec(string s)

bool fun(string s){

    int len = s.size();

    for(int i = 0;i<len/2;i++){
        if(s[i]!=s[len-i-1]){
            return false;
        }
    }
return true;
}

int main(){

    string s;
    cin>>s;

    cout<<is_palindrome(s)<<endl;

return 0;
}
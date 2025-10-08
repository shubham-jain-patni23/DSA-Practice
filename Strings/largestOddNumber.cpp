#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){

    string s; 
    cin>>s;

    int n = s.size();

    int i ;

    for(i = n-1;i>=0;i--){
        if((int)s[i]  % 2==1){
            break;
        }
    }

    string ans = s.substr(0, i + 1);
    cout<<ans<<endl;

return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<functional>
#include<map>
#include<algorithm>

using namespace std;

int main(){

    string s;
    cin>>s;

    int n =s.size();

    int left = 0 ;
    int ans = 0 ;

    //approach 1 ; whenever we get the max '(' at a time that will be ans ; TC ---> O(n) ; SC ---> O(1)

    for(int i =0;i<n;i++){
        if(s[i]=='('){
            left++;
        }
        else if(s[i]==')'){
            left--;
        }
        ans = max(ans, left);
    }

    cout<<ans<<endl;

return 0;
}
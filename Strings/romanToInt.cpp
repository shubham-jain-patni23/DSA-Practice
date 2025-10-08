#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<functional>
#include<map>
#include<algorithm>
using namespace std;

int val(char ch){
    if(ch=='I') return 1;
    if(ch=='V') return 5;
    if(ch =='X') return 10;
    if(ch=='L') return 50;
    if(ch=='C') return 100;
    if(ch=='D') return 500;
return 1000;
}

int main(){

    string s;
    cin>>s;

    int n =s.size();

    //approach 1;   TC ---> O(n)  ; SC --->O(1)

    int preval = val(s[0]);
    int ans = preval;

    for(int i =1;i<n;i++){
        int currval = val(s[i]);
        if(currval > preval){
            int x = currval - (2 * preval);
            ans+= x;
            preval =x;
        }
        else{
            ans+= currval;
            preval = currval;
        }
    }

    cout<<ans<<endl;

return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int rev = 0;

    while(n){                       //O(log10n)
        int rem = n%10;
        rev = rev * 10  + rem;
        n/=10;
    }

    cout<<rev<<endl;

    string s;
    cin>>s;

    reverse(s.begin(),s.end());     //O(n)

    cout<<s<<endl;

return 0;
}
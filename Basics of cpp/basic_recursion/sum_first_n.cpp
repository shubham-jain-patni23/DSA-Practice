#include<bits/stdc++.h>
using namespace std;

int fun(int n){

    if(n==1){
        return 1;
    }
    
return n + fun(n-1);
}

int main(){

    int n;
    cin>>n;

    int ans = fun(n);

    cout<<ans<<endl;

return 0;
}
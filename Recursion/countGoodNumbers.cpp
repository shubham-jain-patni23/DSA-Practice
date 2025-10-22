#include<iostream>
using namespace std;

long long pow(long long x, long long n){
    const long long MOD = 1e9 + 7;
    long long ans = 1;
    long long curr = x;

    while(n){
        if(n & 1){
            ans = (ans * curr) % MOD ; 
        }
        curr = (curr * curr) % MOD;
        n>>=1;
    }
return ans;
}

long long inv_mod(long long a, long long b){
    const long long MOD = 1e9+7;
    return (a * pow(b, MOD-2)) % MOD;
}

int main(){

    long long n;
    cin>>n;

    const long long MOD = 1e9+7;
    long long even = (n + 1)/2;

    long long curr = pow((long long)5 ,  even) ;
    long long odd = n / 2;
    long long curr2 = pow((long long)4, odd) ;

    long long ans = (curr * curr2) % MOD;

    cout<<ans<<endl;

return 0;
}
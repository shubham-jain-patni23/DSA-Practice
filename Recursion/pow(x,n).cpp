#include<iostream>
using namespace std;

long long pow(int x,int n){
    long long ans = 1;
    long long curr = x;

    while(n){
        if(1 & n){
            ans = ans *  curr;
        }
        n>>=1;
        curr *= curr;
    }
return ans;
}


// approach 1; multiplying x , n times   ; TC ---> O(n) ; SC ---> O(1)

long double pow1(double x,int n){

    long double ans = 1; 
    bool neg = false;
    if(n < 0){
        neg = true;
        n = -n;
    }
    for(int i = 1;i<=n;i++){
        ans = ans * x;
    }


    if(neg){
        ans = 1LL*1/ ans;
    }

return ans ; 
}


// approach 2;      TC ---> O(log2n)
// dividing the power in the powers of two 

double pow2(double x, int p){
    double ans = 1;
    double curr = x;

    bool neg = false;
    long long n = p;

    if(n < 0){
        neg = true;
        n = -n;
    }

    while(n){
        int rem = 1 & n;
        if(rem==1){
            ans = ans * curr;
        }
        curr = curr * curr;
        n = n >> 1;
    }

    if(neg){
        ans = 1LL / ans;
    }

return ans;
}

int main(){

    double x; 
    int n;
    cin>>x>>n;

    double ans = pow2(x,n);
    cout<<ans<<endl;

    cout<<pow(5,10)<<endl;

return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool check_prime2(int n){

    for(int i = 2;(i*i)<=n;i++){
        if(n%i==0){
            return false;
        }
    }

return true ;
}

bool check_prime(int n){

    bool arr[n+1] = {0};

    for(int i = 2;i<=n;i++){
        if(arr[i]==0){
            //cout<<i<<" ";             //if we want to print all the prime no's till n
            for(int j = (i*i);j<=n;j+=i){
                arr[j] = 1;
            }
        }
    }
    //cout<<endl;

    if(arr[n]==0){
        return true;
    }
return false;
}

int main(){

    int n;
    cin>>n;

    //check_prime(n) ? cout<<"prime" : cout<<"not prime"<<endl;

    check_prime(n) ? cout<<"prime"<<endl: cout<<"not prime"<<endl;
    check_prime2(n) ? cout<<"prime" : cout<<"not prime"<<endl;

return 0;
}
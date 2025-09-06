#include<bits/stdc++.h>
using namespace std;

void print_1n(int n){
    if(n==0){
        return ;
    }
    print_1n(n-1);
    cout<<n<<" ";
}

void print_n1(int n){

    if(n==0){
        return ;
    }

    cout<<n<<" ";
    print_n1(n-1);
}


int main(){

    int n;
    cin>>n;

    print_1n(n);
    cout<<endl;
    print_n1(n);
    cout<<endl;

return 0;
}
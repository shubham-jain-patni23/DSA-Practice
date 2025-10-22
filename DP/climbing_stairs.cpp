#include<iostream>
#include<vector>
using namespace std;

// using recursion ; TC ---> O(2^n) ; SC ---> O(n);
// it is same fib fun

int fun(int n){

    if(n==1 || n==2){
        return n;
    }
return fun(n-1) + fun(n-2);
}

int main(){

    int n;
    cin>>n;

    int first = 0 ; 
    int second = 1;

    for(int i = 2 ;i<=n;i++){
        int x = first + second;
        first = second ; 
        second = x;
    }
    cout<<second<<endl;
    
return 0;
}
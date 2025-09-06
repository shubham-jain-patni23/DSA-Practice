#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int rev = 0;
  
    int ori_no = n;

    while(n){
        int rem = n % 10;
        rev = rev* 10 + rem;
        n/=10;
    }

    (ori_no==rev) ? cout<<"Palindrome" : cout<<"Not a palindrome";

return 0;
}
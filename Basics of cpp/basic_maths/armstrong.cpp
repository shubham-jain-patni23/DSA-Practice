#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int len = to_string(n).size() ; //size() or length() both are same
    // for str to int stoi() is used

    //or int len = log10(n) + 1;

    int res = 0;
    int ori_no = n;

    while(n){
        int rem = n%10;
        //int x = ceil(pow(rem ,len));          //pow fun returns a double so it may give 124.999 which may be 124 in int
        int x = 1;
        for(int i = 1;i<=len;i++){
            x = x * rem;
        }
        res += x;
        n/=10;
    }

    if(ori_no==res){
        cout<<"Armstrong no."<<endl;
    }
    else{
        cout<<"Not an armstrong no"<<endl;
    }

return 0;
}
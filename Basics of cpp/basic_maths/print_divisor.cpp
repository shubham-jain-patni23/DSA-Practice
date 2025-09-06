#include<bits/stdc++.h>
using namespace std;

void print_div(int n){

    int x = n/2;

    for(int i = 1;i<=x;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
    cout<<n<<endl;
return ;
}

void print_div2(int n){
    int x = sqrt(n);

    vector<int> v;

    for(int i = 1;i*i <=n;i++){      //we can write i*i <= n or i<=sqrt(n)          
        if(n%i==0){
            if(i!=(n/i)){
                v.push_back(i);
                v.push_back(n/i);
            }
            else{
                v.push_back(i);
            }
        }
    }
    sort(v.begin(),v.end());

    for(auto i  : v){
        cout<<i<<" ";
    }

    cout<<endl;
}

int main(){

    int n;
    cin>>n;

    print_div2(n);

return 0;
}
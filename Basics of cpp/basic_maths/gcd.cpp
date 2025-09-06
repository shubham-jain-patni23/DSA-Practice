#include<bits/stdc++.h>
using namespace std;

int gcd(int n1,int n2){                 //O(logphi_min(a,b))
    if(n1==0){
        return n2;
    }
    if(n2==0){
        return n1;
    }
return gcd(n2,n1%n2);           // from gcd(n1,n2) = gcd(n2, n1 - n2);
}

int gcd2(int x,int y){
    int mini = min(x,y);

    int ans =1 ;

    for(int i = 1 ; i*i<=mini;i++){
         
    }
return ans;
}

int main(){

    int x,y;
    cin>>x>>y;

    cout<<gcd2(x,y)<<endl;

return 0;
}
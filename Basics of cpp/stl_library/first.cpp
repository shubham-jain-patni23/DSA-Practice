#include<bits/stdc++.h>
//this library includes all the files

using namespace std;

void print1(int n){
    
    for(int i =1 ;i<=2*n - 1;i++){
        for(int j = 1;j<=2*n -1;j++){
            int x = i;
            int y = j;
            if(x>=n){
                x = (2*n  - 1)- x + 1;
            }
            if(y>=n){
                y = (2*n - 1) - y + 1;
            }
           
            int res = min(x,y);
            cout<<n - res + 1<<" ";
        }
        cout<<endl;
    }

}

int main(){

    int t;
    cin>>t;


    for(int i = 0;i<t;i++){
        int n;
        cin>>n;

        print1(n);
    }

return 0;
}
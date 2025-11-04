#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int k;
        cin>>k;

        int arr[n];
        for(int i =0;i<n;i++){
            cin>>arr[i];
        }

        bool issorted = true;
        for(int i =1;i<n;i++){
            if(arr[i-1] > arr[i]){
                issorted = false;
                break;
            }
        }

        if(issorted || k>=2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

return 0;
}
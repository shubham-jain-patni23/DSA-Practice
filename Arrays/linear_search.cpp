#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int num;
    cin>>num;

    int arr[n];
    
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int ans = -1;

    for(int i = 0;i<n;i++){
        if(arr[i]==num){
            ans = i;
            break;
        }
    }

    ans==-1 ? cout<<"ele does not exist" : cout<<ans<<endl;

    cout<<endl;

return 0;
}
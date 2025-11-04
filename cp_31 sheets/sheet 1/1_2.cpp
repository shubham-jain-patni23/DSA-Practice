#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int x;
        cin>>x;

        int arr[n];
        for(int i =0;i<n;i++){
            cin>>arr[i];
        }

        int ans = 0;

        for(int i = 1;i<n;i++){
            int y = arr[i] - arr[i-1];
            ans = max(ans,y);
        }

        int first = arr[0] - 0;
        int second = x - arr[n-1];
        second = second + second;

        ans = max(ans, max(first,second));

        cout<<ans<<endl;

    }

return 0;
}
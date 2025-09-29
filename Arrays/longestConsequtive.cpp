#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    //approach1: sort    ;    TC ---> O(nlogn)              SC---> O(1)

    sort(arr,arr+n);

    int ans = 1;
    int curr = 1;

    for(int i = 1;i<n;i++){
        if((arr[i] - arr[i-1])==1){
            curr++;
            ans = max(curr,ans);
        }
        else{
            curr = 1;
        }
    }

    cout<<ans<<endl;

    

    //approach 2; making a freq array    ; TC --> O(max(n, maxi))   ; SC ---> O(maxi)

    int maxi = *max_element(arr,arr+n);

    int freq[maxi + n] = {0};

    for(int i =0;i<n;i++){
        freq[arr[i]]++;
    }

    ans = 0;
    curr =0 ;

    for(int i =0;i<= maxi;i++){
        if(freq[i]==0){
            curr =0;
        }
        else{
            curr++;
        }
        ans =  max(curr,ans);
    }

    cout<<ans<<endl;


return 0 ;
}
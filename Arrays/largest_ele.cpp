#include<iostream> 
#include<algorithm>
using namespace std;

bool mycomp(int a,int b){
    return a%10 < b%10;
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int maxi = arr[0];

    for(int i =1;i<n;i++){
        maxi = max(arr[i], maxi);
    }

    // int ans = *max_element(arr,arr+n,[](int a,int b){
    //     return a%10 < b%10;
    // });

    // int ans = *max_element(arr, arr+n,mycomp);

    int ans = *max_element(arr, arr + n);

    cout<<ans<<endl;
    cout<<maxi<<endl;

return 0;
}
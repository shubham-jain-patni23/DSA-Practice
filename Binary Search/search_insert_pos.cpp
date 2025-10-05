#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin>>n;

    int target;
    cin>>target;

    int arr[n];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    //approach 1 ;  TC --> O(log2n)   ; SC ---> O(1)
    int low = 0 , high = n-1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid]==target){
            low = mid;
            break;
        }
        else if(arr[mid] > target){
            high = mid  -1;
        }
        else{
            low = mid + 1;
        }
    }

    cout<<low<<endl;

    //approach 2 ; using build_in lower_bound() fun
    int ans = lower_bound(arr, arr + n, target) - arr;
    cout<<ans<<endl;

return 0;
}
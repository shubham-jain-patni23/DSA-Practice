#include<iostream>
#include<algorithm>
using namespace std;

//The lower_bound of x is defined as the smallest index i such that nums[i] >= x.

//TC ---> O(log2n)
int lower_bound2(int arr[],int n,int x){

    int low = 0, high = n-1;
    int ans = n;

    while(low <= high){
        int mid = low + (high - low)/2;

        //there are only two cases ; we may get ans or we may not

        if(arr[mid] >= x){
            ans = mid;
            high = mid  - 1;
        }
        else{
            low = mid + 1;
        }
    }
return ans;
}

int main(){

    int n;
    cin>>n;

    int x;
    cin>>x;

    int arr[n];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    int ans = lower_bound2(arr,n,x);
    cout<<ans<<endl;

    ans = lower_bound(arr, arr+n, x) - arr;       //it gives an iterator to the idx and it gives the idx as when we subtract from the first ptr(add)

    cout<<ans<<endl;

return 0;
}
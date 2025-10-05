#include<iostream>
#include<algorithm>
using namespace std;

//The upper_bound of x is defined as the smallest index i such that nums[i] > x.

//TC ---> O(log2n)
int upper_bound2(int arr[],int n,int x){

    int low = 0,high = n-1;
    int ans = n;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid]<=x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
            ans = mid;
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

    int ans = upper_bound2(arr,n,x);
    cout<<ans<<endl;

    ans = upper_bound(arr,arr+n,x) - arr;
    cout<<ans<<endl;

    ans= upper_bound(arr + 1 , arr + 3,x) - arr;  // upper_bound(start,end,x)  where end is not included i.e. search space is [start, end)
    cout<<ans<<endl;

return 0;
}
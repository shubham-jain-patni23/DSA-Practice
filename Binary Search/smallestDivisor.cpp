#include<iostream>
#include<climits>
using namespace std;

//fun to check whether the divisor mid is possible ans or not
bool isTrue(int arr[],int n,int threshold,int mid){

    int curr = 0;
    for(int i =0;i<n;i++){
        curr += (arr[i] + mid -1)/mid;
        if(curr > threshold){
            return false;
        }
    }
return true;
}

int main(){

    int n;
    cin>>n;

    int arr[n];

    int threshold;
    cin>>threshold;

    int maxi = -1;

    for(int i = 0 ;i<n;i++){
        cin>>arr[i];
        maxi = max(maxi , arr[i]);
    }

    //approach 1; checking all the possibilities linearly from 1 to maxi ; TC ---> O(maxi * n)  ; SC ---> O(1)

    //approach 2; checking all the possibilities in the range 1 to maxi using binary search ; TC ---> O(log2maxi * n)  ; SC ---> O(1)
    //the min sum considering any divisor will be n , because of ceil, we want mini ans so the ans will surely be the maxi ele 
    //and on the mini side it can be 1 so the range of the possible divisors can be 1 to maxi , on which we can apply binary search

    int low = 1, high = maxi;

    int ans = maxi;
    //or instead of ans we can return low as low will stop on the min divisor

    while(low <= high){
        int mid = low + (high - low)/2;

        if(isTrue(arr,n,threshold,mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout<<ans<<endl;

return 0 ;
}
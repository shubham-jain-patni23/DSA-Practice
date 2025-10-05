#include<iostream>
using namespace std;

//fun to check if we allow max sum to be mid then is it possible to split the arr into <=k subarrays
bool isTrue(int arr[],int n,int k,int mid){

    int cnt = 1;
    int curr = 0;

    for(int i =0;i<n;i++){
        curr+=arr[i];
        if(curr > mid){
            curr = arr[i];
            cnt++;
        }
        if(cnt > k){
            return false;
        }
    }
return true;
}

int main(){

    int n;
    cin>>n;

    int k;
    cin>>k;

    int arr[n];

    int maxi = -1, total = 0 ;

    for(int i = 0 ;i<n;i++){
        cin>>arr[i];
        maxi = max(maxi , arr[i]);
        total += arr[i];
    }

    //approach 1 ; TC ---> O(log2(maxi - total + 1) * n)  ; SC ---> O(1)

    //considering n>=k
    int low = maxi , high = total;

    while(low<=high){
        int mid  = low  + (high - low)/2;

        if(isTrue(arr,n,k,mid)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout<<low<<endl;

return 0 ;
}
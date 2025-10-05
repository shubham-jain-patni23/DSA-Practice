#include<iostream>
#include<algorithm>
using namespace std;

// fun to check whether is it possible to assign all the cows with the min dis mid.
bool isTrue(int arr[],int n,int k,int mid){

    int cnt = 1 ;
    int prev = arr[0];
    for(int i = 1;i<n;i++){
        if((arr[i] - prev) >= mid){
            prev = arr[i];
            cnt++;
        }
    }
return cnt>=k;
}

int main(){

    int n;
    cin>>n;

    int k;
    cin>>k;

    int arr[n];

    for(int i = 0 ;i<n;i++){
        cin>>arr[i];
    }

    // approach 1 ;  TC ---> O(nlog2n) + O(log2(maxi - mini) * n) 
    // the cows can always be at the dis of 1 and the max possible dis can be maxi - mini
    // so we can apply binary search in the range 1 to (maxi - mini) and check whether the with the min dis mid all the cows
    // can be placed or not

    sort(arr, arr + n);     //O(nlog2n)

    int low = 1; 
    int high = arr[n-1] - arr[0];

    while(low<=high){
        int mid = low + (high - low)/2;
        if(isTrue(arr,n,k,mid)){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    cout<<high<<endl;

return 0 ;
}
#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    
    // approach 1; iterating the complete array 
    int ans = -1;

    for(int i =0; i< n;i++){
        if(((i==0) || (arr[i-1] < arr[i]) ) && ((i==n-1) || (arr[i+1] < arr[i]))){
            ans = i;
            break;
        }
    }

    cout<<ans<<endl;

    // approach 2; TC ---> O(log2n)   ; SC ---> O(1)
    // using binary search and considering the half in which the nbhr was greater than arr[mid]
    
    int low = 0 , high = n -1;
    ans = -1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(((mid==low) || (arr[mid-1] < arr[mid])) && ((mid==high) || (arr[mid + 1] < arr[mid]))){
            ans = mid ; 
            break;
        }
        else if((mid!=low) && (arr[mid-1] > arr[mid])){
            high = mid -1 ;
        }
        else{
            low = mid + 1;
        }
    }

    cout<<ans<<endl;

return 0;
}
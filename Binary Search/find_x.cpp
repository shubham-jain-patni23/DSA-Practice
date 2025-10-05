#include<iostream>
using namespace std;

//(1) whenever we need to search for a solution in a sorted space we can apply binary search over it
//(2) binary search is typically based on eliminating one of the sorted halves 

//binary search for target using recursive funtion
int binary_search_rec(int arr[],int low,int high, int target){
    if(high < low){
        return -1;
    }
    int mid = low + (high - low) / 2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid] > target){
        return binary_search_rec(arr,low,mid-1,target);
    }
return binary_search_rec(arr,mid+1,high,target);
}

//binary search for target using iterative function
int binary_search(int arr[],int n,int target){

    int low = 0, high = n-1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid] > target){
            high = mid - 1; 
        }
        else{
            low = mid + 1;
        }
    }

return -1;
}

int main(){

    int n;
    cin>>n;

    int target;
    cin>>target;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    //approach 1 ; linear search ; TC---> o(n)  ; SC ---> O(1)

    //approach 2 ; binary search ; TC ---> O(logn)    ; SC ---> O(1)

    int ans = binary_search(arr,n,target);

    cout<<ans<<endl;

    ans = binary_search_rec(arr,0,n-1,target);

    cout<<ans<<endl;

return 0;
}
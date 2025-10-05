#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    
    //approach 1 ; using xor     TC ---> O(n)   ; SC ---> O(1)

    int xorr = 0;

    for(int i =0;i<n;i++){
        xorr = xorr ^ arr[i];
    }

    cout<<xorr<<endl;

    // approach 2;     TC ---> O(log2n)   ; SC---> O(1)
    // using binary search algo ; we can eliminate one of the array havles based on whether it is even or odd

    int low  = 0, high = n-1;
    int ans ;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if((((mid - 1) < low) || (arr[mid-1] != arr[mid]))  && (((mid + 1) > high) || (arr[mid + 1] != arr[mid]))){
            ans = arr[mid];
            break;
        }
        else if(((mid - 1) >= low) && (arr[mid] == arr[mid-1])){
            if((mid - low + 1)%2==1){
                high = mid - 2;
            }
            else{
                low = mid  + 1;
            }
        }
        else{
            if((mid - low)%2==1){
                high = mid - 1;
            }
            else{
                low = mid + 2;
            }
        }
    }

    cout<<ans<<endl;
    
return 0;
}
#include<iostream>
#include<algorithm>
#include<math.h>
#include<climits>
using namespace std;

//fun to check whether the speed mid is possible or not ; TC ---> O(n)       ; SC ---> O(1)
bool isTrue(int arr[],int n,int h,long long mid){

    int curr = 0 ;
    for(int i = 0;i<n;i++){
        long double y = mid;
        // on tycasting mid to float it is not working while for long double it is working due to precision thing
        // we can replace ceil(a / b) with (a + b -1) / b;
        //int x = ceil((float)arr[i] / (long double)y);       
        curr+= x;
        if(curr > h){
            return false;
        }
    }
return true;
}

int main(){

    int n;
    cin>>n;

    int h;
    cin>>h;

    int arr[n];

    for(int i = 0 ;i<n;i++){
        cin>>arr[i];
    }

    // approach 1;          TC ---> O(nlog2n) + O(nlog2max(arr[i]))  ; SC ---> O(1)
    // we are considering the speed in the range 1 to max(arr[i]) and checking if that speed is possible or not

    sort(arr, arr + n, greater<int>());     //O(nlog2n)   
    
    int ans  = arr[0];

    if(h!=n){
        
        long long low =1 , high = arr[0];

        while(low <= high){             //O(log2max(arr[i]) * n)   = O(nlog2n)        ; O(n) for calling isTrue()
            long long mid = low + (high - low)/2;
            if(isTrue(arr,n,h,mid)){
                ans = mid;
                high = mid -1 ;
            }
            else{
                low = mid + 1;
            }
        }

    }
    cout<<ans<<endl;

return 0 ;
}
#include<iostream>
#include<climits>
using namespace std;

//fun to check whether on the mid day whether it is possible to make m bouqets or not ; TC ---> O(n) ; SC ---> O(1)
bool isTrue(int arr[],int n,int m,int k, int mid){

    int cnt = 0 ;
    int curr = 0;
    for(int i =0;i<n;i++){
        if(arr[i] > mid){
            curr = 0;
        }
        else{
            curr++;
            if(curr == k){
                cnt++;
                curr = 0;
            }
           
        }
        if(cnt >= m){
            return true;
        }
    }
return false;
}

int main(){

    int n;
    cin>>n;

    int arr[n];

    int m;          
    cin>>m;

    int k;
    cin>>k;

    int maxi = -1;
    int mini = INT_MAX;

    for(int i = 0 ;i<n;i++){
        cin>>arr[i];
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    // approach 1;    TC ---> O(log2(maxi - mini + 1) * n)  ; SC --- > O(1)
    // the maximum or last possible ans can be the last day when any flower bloomed so we may need to wait 
    // till all the flower are not bloomed, and min days we need to wait is the first day when some flowers bloomed 
    // so if it is possible to make m bouqets then we may need to wait for the days in the range [mini_day, maxi_day]
    // on this range we can apply binary search and see whether on a day is it possible to make m bouquets or not

    int low = mini , high = maxi;

    int ans = -1;

    while(low<=high){
        int mid = low + (high - low)/2;
        if(isTrue(arr,n,m,k,mid)){
         
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
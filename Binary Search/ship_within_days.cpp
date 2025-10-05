#include<iostream>
using namespace std;

// fun to check whether is it possible to ship all the packages withing days if the ship cap is mid;
bool isTrue(int arr[],int n,int days,int mid){
    int cnt = 1 ;
    int curr = 0;

    for(int i =0;i<n;i++){
        curr+= arr[i];
        if(curr > mid){ 
            curr = arr[i];
            cnt++;
        }
        if(cnt > days){
            return false;
        }
    }
return true;
}

int main(){

    int n;
    cin>>n;

    int days;
    cin>>days;

    int arr[n];

    int total  = 0;
    int maxi = -1;

    for(int i = 0 ;i<n;i++){
        cin>>arr[i];
        total = total+= arr[i];
        maxi = max(maxi, arr[i]);
    }

    // approach 1; checking all the possibilities linearly in the range maxi to total ; TC ---> O((total - maxi + 1)*n) ; SC ---> O(1)

    // approach 2; using binary search checking all the possibilities in the range maxi to total ---> O(log2(total - maxi + 1) * n) ; SC ---> O(1)
    // mini wt cap of the ship should be the maxi wt of any package and to ship all the packages in one day cap of the ship can be total sum of 
    // the wts 

    int low= maxi , high = total ;
    int ans = total;

    while(low<=high){
        int mid = low + (high - low)/2;
        if(isTrue(arr,n,days,mid)){
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
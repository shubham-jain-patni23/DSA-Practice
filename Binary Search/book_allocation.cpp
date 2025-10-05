#include<iostream>
using namespace std;

//fun to check whether is it possible to allocate the books among k students if we allow max mid pages 
bool isTrue(int arr[],int n,int k,int mid){

    int cnt = 1;
    int curr = 0;

    for(int i = 0;i<n;i++){
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

    int maxi = 0, total = 0 ;

    for(int i = 0 ;i<n;i++){
        cin>>arr[i];
        maxi = max(maxi, arr[i]);
        total += arr[i];
    }

    // approach 1 ; TC ---> O(log2(total - maxi +1) * n)
    // the min possible ans can be the maxi page book and the maxi possible ans can be total or some less than total 
    // we can apply binary search in the range maxi to total and check if we want that only maximum mid pages can be assigned to any student
    // then are we able to allocate all the books among k students, if we are able then it is true otherwise if we need more than k students 
    // to assign all the books than we need to increase the maxi allowed pages mid.

    //considering n>=k
    int low = maxi , high = total;

    while(low<=high){
        int mid = low + (high - low)/2;
        if(isTrue(arr,n,k,mid)){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }

    cout<<low<<endl;

return 0 ;
}
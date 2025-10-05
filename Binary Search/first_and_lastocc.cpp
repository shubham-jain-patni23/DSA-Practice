#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//approach1 ; TC ---> O(log2n)    SC---> O(1)
int first(int arr[],int n,int x){

    int ans = -1;
    int low = 0, high = n-1;

    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid] < x){
            low = mid + 1;
        }
        else if(arr[mid]==x){
            ans = mid;
            high = mid - 1;
        }
        else{
            high = mid - 1;
        }
    }
return ans;
}

//approach2 ; using lower_bound ; TC ---> O(log2n)   ; SC---> O(1)

int first2(int arr[],int n,int x){
    int ans = lower_bound(arr, arr + n, x) - arr;
    if(ans==n || arr[ans]!=x) return -1;
return ans;
}

//approach1 ; TC ---> O(log2n) ; SC---> O(1)
int last(int arr[],int n,int x){
    int ans = -1;
    int low = 0 ,high = n-1;
    
    while(low<=high){
        int mid = low + (high - low)/2;

        if(arr[mid] < x){
            low = mid + 1;
        }
        else if(arr[mid]==x){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

return ans;
}

//approach2 ; using upper bound ; 

int last2(int arr[],int n,int target){
    int ans = upper_bound(arr, arr + n, target) - arr;
    ans--;
    if(arr[ans]==target){
        return ans;
    }
return -1;
}

//approach ; using first and last together 

vector<int> first_and_last(int arr[],int n,int x){
    int ans = lower_bound(arr, arr + n, x) - arr;
    if(ans==n || arr[ans]!=x) return {-1,-1};

return {ans, (upper_bound(arr,arr+n,x) - arr) -1 };
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
   
    int f = first(arr,n,target);
    int l = last(arr, n, target);

    cout<<f<<" "<<l<<endl;

    f = first2(arr,n,target);
    l = last2(arr, n, target);

    cout<<f<<" "<<l<<endl;

    vector<int> ans = first_and_last(arr, n, target);
    cout<<ans[0] <<" "<<ans[1]<<endl;

return 0;
}
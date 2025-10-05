#include<iostream>
using namespace std;


int lower_bound(int arr[],int n,int k){

    int low =0 , high = n-1;

    while(low <= high){
        int mid = low + (high - low)/2;
        int x  = arr[mid]- (mid + 1);
        if(x>=k){
            high = mid  - 1;
        }
        else{
            low = mid + 1;
        }
    }
return low;
}

//fun to check whether the mid is the kth missing no. or not
int isTrue(int arr[],int n,int k,int mid){

    // if mid is the kth miss then before it will be k-1 miss ele and it would be at x if present and if not present then 
    // greater no. then it will be first at x;
    int x = (mid - 1) - (k - 1);  

    if(x==0){
        if(arr[x] <= mid){
            return 2;
        }
        if(mid==k){
            return 1;
        }
        return 0;
    }

    if(arr[x-1] >= mid){
        return 0;
    }

    if((x < n) && arr[x] <= mid){
        return 2;
    }
    
    if(x==n){
        int y = arr[x -1] - n;
        y = y + (mid - arr[x - 1]);
        if(y==k){
            return 1;
        }
        else{
            return 0;
        }
    }

return 1;
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

    // appraoch 1;   TC ---> O(n) ; SC ---> O(1)
    // min ans can be k and if some lesser than it appears then it will be lesser than kth missing so we inc our ans 

    int ans  = k; 

    for(int i =0;i<n;i++){
        if(arr[i] > ans){
            break;
        }
        ans++;
    }

    cout<<ans<<endl;

    // approach 2;  TC ---> O(log2((n + k )- k  + 1)) = O(log2 (n + 1))
    // the min possible kth missing no can be k when the starting k no. are not present.
    // and the max possible kth missing no can be n + k , so the kth missing no. will be 'one' in the range k to (n + k)
    // using binary search we will check whether the mid is kth missing no. or not 
    // if kth missing no. then isTrue() will return 1 and we will break as ans will be unique
    // if not missing or greater than kth missing then isTrue() will return 0 then we will update high 
    // if not missing or lesser than kth missing then isTrue() will return 2 then we will update low

    int low  = k , high = n + k;
    ans;

    while(low <= high){
        int mid = low  + (high - low)/2;
        int x = isTrue(arr,n,k,mid);
        // mid is the kth missing no. if x ==1
        // mid is either not missing or more than kth missing if x == 0 
        // mid is either not missing or less than kth missing if x == 2
        if(x==1){           
            ans = mid;
            break;
        }
        else if(x==0){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }

    cout<<ans<<endl;


    // approach 3; TC ---> O(log2n) ; SC ---> O(1)
    // we are making observations like as we iterate through the array how many no. are missing till idx i
    // if at any time missing no increases k then it means our ans should be between those two idx 
    // e.g. if at idx i if the miss ele were 2 and at idx i+1 miss ele became 6 then it means there are 4 ele missed after arr[i]
    // so in that case our ans would be arr[i] + (5 - 2) i.e arr[i] + 3 ; if we want 5th miss ele.
    // to find the no where the miss no became greater than k we can apply binary search 

    int x = lower_bound(arr,n,k);
    x--;

    if(x==-1){
        ans = k;
    }
    else{
        ans = arr[x] + (k - (arr[x] - (x + 1)));
    }

    cout<<ans<<endl;

return 0 ;
}